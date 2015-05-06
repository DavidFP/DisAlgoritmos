#include <cstdio>
#include <iostream>
#include <cstdlib>


using namespace std;

int factible(int v[], int paso){
	int i;
	for (int i = 0; i < paso; ++i)
		if(v[i]==v[paso]) return 0;
	return 1;
}

void permutaciones(int *v, int N, int paso){
	int i; 	
	//Comprobamos si es solucion
	if(paso==N){
		for (int i = 0; i < N; ++i)
		{
			cout << " " << v[i] ;
		}
		
		cout << endl;
	}else{
		for (int i = 0; i < N; ++i)
		{
			v[paso] = i;
			if (factible(v,paso))
			{
				permutaciones(v,N,paso+1);
			}
		}

	}
}



int main(void){
	int N;
	int paso=0;
	int v[N];
	cout << "Cálculo de permutaciones con Vuelta Atrás" << endl;
	cout << "¿De cuantos elementos quiere la permutacion?"<<endl;
	cin>>N;
	permutaciones(v,N,paso);
	
	return EXIT_SUCCESS;
}