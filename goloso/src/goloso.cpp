#include "../include/problema.h"

using namespace std;





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
//muestra cardinal de frontera y el tamaño y nodos de la clique
*/
void Problema::mostrarResultado(ostream& os){
	os << maxFrontera << " " << cliqueMaxFrontera.size() << " " ;
	for (int i = 0; i < cliqueMaxFrontera.size(); i++){
		if (i == cliqueMaxFrontera.size()-1){
			os << cliqueMaxFrontera[i].id + 1 <<endl;
		}else{ 
			os << cliqueMaxFrontera[i].id + 1 <<" ";
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
//calcula interseccion de vecinos en comun y el nodo a agregar a la clique
*/
vector<int> Problema::interseccion(vector<int>& a, int v){
	vector<int> res;
	for (int i=0;i<g.nodos[v].adyacentes.size();++i){
		for (int j=0;j<a.size();++j){
			if (g.nodos[v].adyacentes[i]==a[j]) res.push_back(a[j]);
		}
	}
	return res;
}





/*
//dados los adyacentes de un nodo (vec), obtiene el vecino de mayor grado
*/
Nodo mayorGrado(vector<Nodo> vec){
	Nodo aux = vec[1];
	for(int i = 0; i < vec.size(); i++){
		if(aux.adyacentes.size() < vec[i].adyacentes.size()){
			aux = vec[i];
		}
	}
	return aux;
}



/*
//calcula el cardinal de la frontera de una clique
*/
int Problema::frontera(vector<Nodo>& clique){
	int res = 0;
	int tam = clique.size();
	for (int i = 0; i < tam; i++){
		res = res + clique[i].adyacentes.size();
	}
	res = res - (tam*(tam-1));	//quito las aristas de más
	return res;
}



/*
//funcion golosa que resuelve el problema 
*/
void Problema::resolver(){

	cliqueMaxFrontera.push_back(mayorGrado(g.nodos));
	maxFrontera = cliqueMaxFrontera[1].adyacentes.size();
	bool aumenta = true;
	while (aumenta){
		
	
	
	}
}

