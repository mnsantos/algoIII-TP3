#include "../include/problema.h"

using namespace std;

void mostrarVector(const vector<int>& a){
	cout<<"{";
	for (int i=0;i<a.size();++i){
		cout << a[i]+1 <<" ";
	}
	cout<<"} "<<endl;
}

Problema::Problema(istream& is){
	int m;
	is >> g.cantNodos >> m;
	g.nodos.resize(g.cantNodos);
	int e1,e2;
	for (int i=0;i<m;++i){
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

vector<vector<int> > Problema::armar_vecindad (vector<int> clique){
	vector<vector<int> > vecindad;
	vector<int> aux;
	vector<int> interseccion;
	int nodo_sacado;
	
	if(clique.size()>1){
		for(int i=0; i< clique.size(); i++){ //sacar un nodo y ademas intercambiar un nodo
			aux= clique;
			nodo_sacado= aux[i];
			aux.erase(aux.begin()+i);
			vecindad.push_back(aux);
			
			interseccion= intersecar(aux); //interseccion entre los adyacentes de los nodos de aux
			if(interseccion.size()>0){
				for(int i=0; i< interseccion.size(); i++){ //poner un nodo
					if(interseccion[i] != nodo_sacado){
						aux.push_back(interseccion[i]);
						vecindad.push_back(aux);
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
			vecindad.push_back(clique);
			clique.pop_back();
		}
	}
	
	return vecindad;
}


void Problema::resolver(){
	cliqueMaxFrontera.push_back(0);
	maxFrontera= g.nodos[0].adyacentes.size();
	
	bool hay_cambio= true;
	vector<vector<int> > vecindad;
	
	while(hay_cambio){
		vecindad= armar_vecindad(cliqueMaxFrontera);
		hay_cambio= false;
		
		cout<< "el clique hasta ahora ";
		mostrarVector(cliqueMaxFrontera);
		
		cout<< "iteracion "<< endl;
		for(int i=0; i< vecindad.size(); i++){
			mostrarVector(vecindad[i]);
		}
		
		for(int i=0; i< vecindad.size(); i++){
			int frontera_vecino= frontera(vecindad[i]); //para no calcularlo dos veces
			if(frontera_vecino > maxFrontera){
				cliqueMaxFrontera= vecindad[i];
				maxFrontera= frontera_vecino;
				hay_cambio= true;
			}
		}
	}
}
