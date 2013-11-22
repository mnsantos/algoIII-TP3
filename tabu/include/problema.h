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
	int cantAristas;
	
	void mostrarGrafo(ostream&);	
};

struct Clique{
	vector<int> nodos;
	bool es_tabu;
	int nodo_diferencia;
};

struct Problema{
	Problema (istream&);
	void mostrarResultado(ostream& os);
	void resolver();
	
	vector<int> lista_tabu;
	
	bool tabu(vector<int>);
	
	int frontera(vector<int> clique);
	vector<int> intersecar(vector<int> clique);
	vector<Clique > armar_vecindad (vector<int> clique);
	
	Grafo g;
	vector<int> cliqueMaxFrontera;
	int maxFrontera;
};

#endif
