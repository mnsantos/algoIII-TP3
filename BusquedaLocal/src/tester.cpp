#include "../../tiempo.h"
#include <iostream>
#include "../include/problema.h"

using namespace std;

void mostrarCiclos(ostream& os, int cantTrabajos, unsigned long long int result){
	os << cantTrabajos << " " << result <<endl;
}

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
	
	int cantRepeticiones= 300;
	for(int i = 0;i<cantProblemas;i++){
		start=0; end=0; result=0;
		
		for(int j=0; j<cantRepeticiones; j++){
			MEDIR_TIEMPO_START(start);
			problemas[i].resolver();
			MEDIR_TIEMPO_STOP(end);
			result+= (end-start);
		}	
			result= result / cantRepeticiones;
			mostrarCiclos(cout, problemas[i].g.cantNodos, result);
	}
    
    return 0;
}
