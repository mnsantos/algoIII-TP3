#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <queue>
#include <set>

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
	int mayorGrado(vector<int>&);
	int cardinalFrontera(vector<int>&);
	void resolver();

	Grafo g;
	vector<int> cliqueMaxFrontera;
	int tamFrontera;
};

#endif
