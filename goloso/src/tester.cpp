#include "../../tiempo.h"
#include <iostream>
#include "../include/problema.h"

void mostrarCiclos(ostream& os, int cantNodos, unsigned long long int result){
	os << cantNodos << " " << result <<endl;
}

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
	unsigned long long int start=0, end=0, result=0;
	for(int i=0;i<cantProblemas;i++){
		for (int j=0;j<10;++j){
			MEDIR_TIEMPO_START(start);
			problemas[i].resolver();
			MEDIR_TIEMPO_STOP(end);
			result+=end-start;
		}
		result=result/10;
		result=result/1000;
		mostrarCiclos(cout,problemas[i].g.cantNodos,result);
	}
    return 0;
}
