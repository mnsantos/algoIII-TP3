#include "../include/problema.h"

using namespace std;

void mostrarVector(const vector<int>& a){
	cout<<"{";
	for (int i=0;i<a.size();++i){
		cout << a[i]+1 <<" ";
	}
	cout<<"} "<<endl;
}

bool sacar(vector<int>& a, int v){
	for (int i=0;i<a.size();++i){
		if (a[i]==v){
			a.erase(a.begin()+i);
			return true;
		}
	}
	return false;
}

void Ubis(vector<int>& a, int v){
	int i;
	for (i=0;i<a.size();++i){
		if (a[i]==v) break;
	}
	if (i==a.size()) a.push_back(v);
}

vector<int> U(const vector<int>& a, int v){
	vector<int> res = a;
	int i;
	for (i=0;i<a.size();++i){
		if (a[i]==v) break;
	}
	if (i==a.size()) res.push_back(v);	
	assert(res.size()>=a.size());
	return res;
}

vector<int> Problema::interseccion(vector<int>& a, int v){
	vector<int> res;
	for (int i=0;i<g.nodos[v].adyacentes.size();++i){
		for (int j=0;j<a.size();++j){
			if (g.nodos[v].adyacentes[i]==a[j]) res.push_back(a[j]);
		}
	}
	return res;
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

void Problema::resolver(){
	vector<int> P;
	vector<int> R;
	vector<int> X;
	maxFrontera=0;
	for (int i=0;i<g.cantNodos;++i){
		P.push_back(i);
	}
	findCliques(R,P,X);
}

int Problema::frontera(vector<int>& R){
	int res=0;
	int tam=R.size();
	for (int i=0;i<R.size();++i){
		res+=g.nodos[R[i]].adyacentes.size();
	}
	res = res - (tam*(tam-1));
	return res;
	
	/*
	int res=0;
	for (int i=0;i<R.size();++i){
		for (int j=0;j<g.nodos[R[i]].adyacentes.size();++j){
			int h=0;
			for (h;h<R.size();++h){
				if (g.nodos[R[i]].adyacentes[j]==R[h]) break;
			}
			if (h==R.size()) res++;
		}
	}
	return res;
	*/
}

void Problema::findCliques(vector<int> R, vector<int> P, vector<int> X){
	int front = frontera(R);		
	if (front>=maxFrontera){
		cliqueMaxFrontera = R;
		maxFrontera = front;
	}
	for (int i=0;i<P.size();++i){
		findCliques(U(R,P[i]),interseccion(P,P[i]),interseccion(X,P[i]));
		if (sacar(P,P[i])) i--;
		Ubis(X,P[i]);
	}
}
