#include "../include/problema.h"
#include <stdlib.h>
using namespace std;

void mostrarVector(const vector<int>& a){
	cout<<"{";
	for (int i=0;i<a.size();++i){
		cout << a[i]+1 <<" ";
	}
	cout<<"} "<<endl;
}

Problema::Problema(istream& is){
	is >> g.cantNodos >> g.cantAristas;
	g.nodos.resize(g.cantNodos);
	int e1,e2;
	for (int i=0;i<g.cantAristas;++i){
		is >> e1 >> e2;
		g.nodos[e1-1].adyacentes.push_back(e2-1);
		g.nodos[e2-1].adyacentes.push_back(e1-1);
	}
}

void Problema::mostrarResultado(ostream& os){
	os<<maxFrontera<<" "<<cliqueMaxFrontera.size()<<" ";
	for (int i=0;i<cliqueMaxFrontera.size();++i){
		if (i==cliqueMaxFrontera.size()-1) os<<cliqueMaxFrontera[i]+1<<endl;
		else os<<cliqueMaxFrontera[i]+1<<" ";
	}
}

void Grafo::mostrarGrafo(ostream& os){
	for (int i=0;i<cantNodos;++i){
		for (int j=0;j<nodos[i].adyacentes.size();++j){
			os<<"("<<i+1<<","<<nodos[i].adyacentes[j]+1<<") ";
		}
	}
	cout<<endl;
}

int Problema::frontera(vector<int> clique){
	int frontera=0;
	
	for(int i=0; i< clique.size(); i++){
		frontera+= (g.nodos[clique[i]].adyacentes.size() - (clique.size()-1)); //adyacentes - tam_clique para no contar como frontera los ejes de la clique
	}
	
	return frontera;
}

bool Problema::tabu(vector<int> clique){
	for(int i=0; i< clique.size(); i++){
		for(int j=0; j< lista_tabu.size(); j++){
			if(clique[i]==lista_tabu[j]){
				return true;
			}
		}
	}
	
	return false;
}

vector<int> Problema::intersecar(vector<int> clique){
	vector<int> interseccion= g.nodos[clique[0]].adyacentes;
	
	for(int j=0; j< interseccion.size(); j++){ //sacamos los adyacentes q ya estan en la clique
		int elem= interseccion[j], k=0;
		bool esta= false;
			
		while(k< clique.size() && !esta){
			if(clique[k]==elem) esta=true;
			k++;
		}
			
		if(esta){
			interseccion.erase(interseccion.begin()+j);
			j--;
		}
	}
	
	for(int i=1; i< clique.size(); i++){ //recorro los nodos de la clique
		vector<int> aux= g.nodos[clique[i]].adyacentes;

		for(int j=0; j< interseccion.size(); j++){ //el size cambia en cada iteracion, si vuela todo a la mier mirar aca! xD
			int elem= interseccion[j], k=0;
			bool esta= false;
			
			while(k< aux.size() && !esta){
				if(aux[k]==elem) esta=true;
				k++;
			}
			
			if(!esta){
				interseccion.erase(interseccion.begin()+j);
				j--;
			}
		}
	}
	
	return interseccion;
}

vector<Clique> Problema::armar_vecindad (vector<int> clique){
	vector<Clique> vecindad;
	vector<int> aux;
	vector<int> interseccion;
	int nodo_sacado;
	Clique vecino;
	
	if(clique.size()>1){
		for(int i=0; i< clique.size(); i++){ //sacar un nodo y ademas intercambiar un nodo
			aux= clique;
			nodo_sacado= aux[i];
			aux.erase(aux.begin()+i);
			
			vecino.nodos= aux;
			vecino.nodo_diferencia= nodo_sacado;
			vecino.es_tabu= tabu(aux);
			
			vecindad.push_back(vecino);
			
			interseccion= intersecar(aux); //interseccion entre los adyacentes de los nodos de aux
			if(interseccion.size()>0){
				for(int i=0; i< interseccion.size(); i++){ //poner un nodo
					if(interseccion[i] != nodo_sacado){
						aux.push_back(interseccion[i]);
						
						vecino.nodos= aux;
						vecino.es_tabu= tabu(aux);
						vecindad.push_back(vecino);
						
						aux.pop_back();
					}
				}
			}
		}
	}
	
	interseccion= intersecar(clique);
	if(interseccion.size()>0){
		for(int i=0; i< interseccion.size(); i++){ //poner un nodo
			clique.push_back(interseccion[i]);
			
			vecino.nodos= clique;
			vecino.es_tabu= tabu(clique);
			vecino.nodo_diferencia= -1;
			
			vecindad.push_back(vecino);
			
			clique.pop_back();
		}
	}
	
	return vecindad;
}


void Problema::resolver(){
	srand (time(NULL)); //random seed
	int nodo= rand() % g.cantNodos;
	cliqueMaxFrontera.push_back(nodo);
	maxFrontera= g.nodos[nodo].adyacentes.size();
	
	vector<Clique> vecindad;
	Clique clique;
	
	int cond=0;
	while(cond<= g.cantAristas){
		vecindad= armar_vecindad(clique.nodos);
 		//~ cout<< "el clique hasta ahora ";
		//~ mostrarVector(cliqueMaxFrontera);
		//~ 
		//~ cout<< "iteracion "<< endl;
		//~ for(int i=0; i< vecindad.size(); i++){
			//~ mostrarVector(vecindad[i]);
		//~ }
		bool hay_cambio= false;
		
		Clique ultimo_no_tabu;
		
		for(int i=0; i< vecindad.size(); i++){
			int frontera_vecino= frontera(vecindad[i].nodos); //para no calcularlo dos veces
			if(frontera_vecino > maxFrontera){
				cliqueMaxFrontera= vecindad[i].nodos;
				if(clique.nodos.size() <= vecindad[i].nodos.size()){
					lista_tabu.push_back(vecindad[i].nodo_diferencia); ///ACTUALIZO LISTA TABU
				}
				clique= vecindad[i];
				maxFrontera= frontera_vecino;
				hay_cambio= true;
			}
			
			if(vecindad[i].es_tabu == false){ //si no es tabu
				ultimo_no_tabu= vecindad[i];
			}
		}
		
		if(!hay_cambio){ 	//si no hay cambio
			if(ultimo_no_tabu.nodos.size()>0){	//si hay un no tabu en los vecinos
				if(clique.nodos.size() <= ultimo_no_tabu.nodos.size()){
					lista_tabu.push_back(ultimo_no_tabu.nodo_diferencia); ///ACTUALIZO LISTA TABU
				}
				clique= ultimo_no_tabu;
			}
			else{
				srand (time(NULL));	
				int pos_rand= rand() % vecindad.size();
				if(clique.nodos.size() <= vecindad[pos_rand].nodos.size()){
					lista_tabu.push_back(vecindad[pos_rand].nodo_diferencia); ///ACTUALIZO LISTA TABU
				}
				clique= vecindad[pos_rand];
			}
		}
		
	}
}
