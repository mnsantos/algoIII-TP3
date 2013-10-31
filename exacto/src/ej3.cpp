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

void Grafo::mostrarGrafo(ostream& os){
	for (int i=0;i<cantNodos;++i){
		for (int j=0;j<nodos[i].adyacentes.size();++j){
			os<<"("<<i+1<<","<<nodos[i].adyacentes[j]+1<<") ";
		}
	}
	cout<<endl;
}

void Problema::resolver(){
	vector<int> P;
	vector<int> R;
	vector<int> X;
	for (int i=0;i<g.cantNodos;++i){
		P.push_back(i);
	}
}

void Problema::findCliques(vector<int>& P, vector<int>& R, vector<int>& X){
	vector<int> Paux = P;
	vector<int> Raux = R;
	vector<int> Xaux = X;	
	
	if (P.empty() && X.empty()){
		cout<<"{";
		for (int i=0;i<R.size();++i){
			cout << R[i] <<" ";
		}
		cout<<"}";
	}
	for (int i=0;i<P.size();++i){
		Raux.push_back(P[i]);
		sort( P.begin(), P.end() );
		sort( X.begin(), X.end() );
		sort( g.nodos[P[i]].adyacentes.begin(), g.nodos[P[i]].adyacentes.end() );
	}
}
