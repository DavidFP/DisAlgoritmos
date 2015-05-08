/*
	Ejercicio que obtiene todas las posibles permutaciones
	de n elementos pasados por el usuario. 
	Para el caso de 2 se debería obtener
	0 1
	1 0 

*/
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

/*
	@brief Función de factibilidad
	@param v[], vector donde vamos almacenando el cálculo de las permutaciones
	@param paso, el paso de la ejecución por el que vamos
	@return 1 o 0 dependiendo de si es factible o no
*/

int factible(int v[], int paso){
	int i;
	for (int i = 0; i < paso; ++i)
		if(v[i]==v[paso]) return 0;
	return 1;
}

/*
@brief 	función que calcula  las permutaciones de N elementos haciendo uso de la
		técnica de vuelta atrás
@param v, vector donde se van a ir almacenando las permutaciones
@param N, número de elementos a los que queremos calcular las permutaciones
@param paso, el paso de la ejecución por el que vamos
@post Muestra por pantalla cada una de las permutaciones posibles
*/
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
	int N; // Cantidad de elementos de la permutación
	int paso=0; 
	int v[N]; //Vector con la permutación de los elementos del N pasado
	cout << "Cálculo de permutaciones con Vuelta Atrás" << endl;
	cout << "¿De cuantos elementos quiere la permutacion?"<<endl;
	cin>>N;
	permutaciones(v,N,paso); // Llamada a la función
	
	return EXIT_SUCCESS;
}