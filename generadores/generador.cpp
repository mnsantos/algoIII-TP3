#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */

using namespace std;

bool iguales(vector<int> a1, vector<int> a2){
	bool res= false;
	if((a1[0] == a2[0] && a1[1] == a2[1]) || (a1[0] == a2[1] && a1[1] == a2[0])){
		res= true;
	}
	return res;
}

bool esta(vector<vector<int> > & aristas, vector<int> a){
	bool res= false;
	for(int i=0; i< aristas.size(); i++){
		if(iguales(aristas[i], a)) res= true;
	}
	
	return res;
}

int main()
{
	
	int nodoMax;
	cin>> nodoMax;
		
	for(int n= 18; n< nodoMax; n++){
		srand (time(NULL));	
		int cant_max_aristas= (n*(n-1))/2;
		int m;
		
		m= (rand() % (cant_max_aristas / 3)) + ((cant_max_aristas/4) + 1); 
		//para q de randoms entre m/2 y m, y no toque tanto con 0 aristas
		
		cout<< n << " " << m << endl;
		
		vector<vector<int> > aristas;
		
		for(int i=0; i< m; i++){
			int nodo1= rand() % n +1;
			int nodo2= rand() % n +1;
			vector<int> a;
			a.push_back(nodo1);
			a.push_back(nodo2);
			
			if(nodo1 != nodo2 && !esta(aristas, a)){
				aristas.push_back(a);
				cout<< nodo1 << " " << nodo2 << endl;
			}
			else{
				i--;
			}
		}
	}
	
	cout <<"0";
	return 0;
}
