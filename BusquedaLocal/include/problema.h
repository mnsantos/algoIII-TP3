#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <cassert>
#include <algorithm>

using namespace std;

struct Nodo{
	vector<int> adyacentes;
	int id;
};

struct Grafo{
	vector<Nodo> nodos;
	int cantNodos;	
	
	void mostrarGrafo(ostream&);	
};

struct Problema{
	Problema (istream&);
	void mostrarResultado(ostream& os);
	void resolver();
	
	int frontera(vector<int> clique);
	vector<int> intersecar(vector<int> clique);
	vector<vector<int> > armar_vecindad (vector<int> clique);
	
	Grafo g;
	vector<int> cliqueMaxFrontera;
	int maxFrontera;
};

#endif
