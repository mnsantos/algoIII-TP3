#include "../include/problema.h"

using namespace std;

/*
//levanta problemas 
*/
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



/*
//muestra los resultados del problema
*/
void Problema::mostrarResultado(ostream& os){
	os << tamFrontera << " " << cliqueMaxFrontera.size() <<" ";
	for (int i = 0; i < cliqueMaxFrontera.size(); i++){
		if (i == cliqueMaxFrontera.size()-1){
			os << cliqueMaxFrontera[i] + 1 <<endl;
		}else{ 
			os << cliqueMaxFrontera[i] + 1 <<" ";
		}
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



/*
//obtiene el nodo de mayor grado de todo el grafo en O(n)
*/
int maxGrado(vector<Nodo>& vec){
	if(vec.size() == 0) {return -1;}
	Nodo aux = vec[1];
	for(int i = 0; i < vec.size(); i++){
		if(aux.adyacentes.size() < vec[i].adyacentes.size()){
			aux = vec[i];
		}
	}
	return aux.id;
}



/*
//obtiene nodo de mayor grado de una frontera en O(n)
*/
int Problema::mayorGrado(vector<int>& vec){
	if (vec.size() == 0) {return -1;}
	int aux = vec[1];
	for(int i = 0; i < vec.size(); i++){
		if(g.nodos[aux].adyacentes.size() < g.nodos[vec[i]].adyacentes.size()){
			aux = vec[i];
		}
	}
	return aux;
}



/*
//calcula el cardinal de la frontera de una clique en O(n)
*/
int Problema::cardinalFrontera(vector<int>& clique){
	int res = 0;
	int tam = clique.size();
	for (int i = 0; i < tam; i++){
		res = res + g.nodos[clique[i]].adyacentes.size();
	}
	res = res - (tam*(tam-1));	//quito las aristas de más
	return res;
}



/*
//funcion golosa que resuelve el problema 
*/
void Problema::resolver(){
	cliqueMaxFrontera.push_back(maxGrado(g.nodos));
	tamFrontera = cardinalFrontera(cliqueMaxFrontera);
	bool aumenta = true;
	vector<int> fronteraAux = g.nodos[cliqueMaxFrontera[0]].adyacentes;
	while (aumenta){
		int candidato = mayorGrado(fronteraAux);
		if(candidato == -1){ aumenta = false; break;}
		vector<int>cliqueAux = cliqueMaxFrontera;
		cliqueAux.push_back(candidato);
		if(tamFrontera < cardinalFrontera(cliqueAux)){
			cliqueMaxFrontera.push_back(candidato);
			tamFrontera = cardinalFrontera(cliqueMaxFrontera);
		}else{
			aumenta = false;
			
		}
	}
}

