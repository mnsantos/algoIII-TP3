#include <iostream>
#include "../include/problema.h"

using namespace std;

int main()
{
    char c;
    bool termino = false;
    vector<Problema> problemas;
    int cantProblemas = 0;
	bool existeEntrada = cin.good();
	assert(existeEntrada);
	while(!termino){
        problemas.push_back(Problema(cin));
        cantProblemas++;
        cin >> c;
        if (c =='0'){
            termino = true;
        }else{
            cin.putback(c);
        }
	}
	for(int i = 0;i<cantProblemas;i++){
		problemas[i].resolver();
		problemas[i].mostrarResultado(cout);
	}
    return 0;
}
