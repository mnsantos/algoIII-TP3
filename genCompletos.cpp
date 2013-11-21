#include <iostream>
#include <stdlib.h>     /* srand, rand */

using namespace std;

int main()
{
	srand (time(NULL));
	
	int nodosMax;
	cin>> nodosMax;
	
	for(int nodos= 1; nodos<= nodosMax; nodos ++){
		
		cout<< nodos << " " << ((nodos*(nodos-1))/2) << endl;
		for(int i=1; i<= nodos; i++){
			for(int j=i+1; j<= nodos; j++){
				cout<< i <<" "<< j << endl;
			}
		}
		
	}
	cout <<"0";
	return 0;
}
