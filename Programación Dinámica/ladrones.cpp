/*
El Maqui y el Popeye acaban de desvalijar la reserva de oro. Los lingotes están
empaquetados en n cajas de diferentes pesos (reales) y, como no tienen tiempo de
desempaquetarlos para dividir el botín, deciden basarse en los pesos de las cajas para
intentar distribuir el botín a medias. Al cabo de un buen rato todavía no han
conseguido repartirse el botín, por lo cual acuden al Teclas para saber si el botín se
puede dividir en dos partes iguales sin desempaquetar ninguna de las cajas.

*/

#include <cstdio> 
#include <cstdlib>
#include <iostream>

using namespace std;


//Devuelve un true en caso de que se pueda repartir el botín de 
//manera equitativa entre los dos ladrones
bool repartir(int P[], int n, int peso){
	bool sepuede[n+1][peso];
	for (int i = 0; i < peso; ++i)
	{
		sepuede[0][i] = false;
	}
	for (int i = 0; i < n; ++i)
	{
		sepuede[i][0] = true;
	}
	for (int i = 1; i <n; ++i)
	{
		for (int j = peso ; j >P[i] ; --j)
		{
			if (P[i]>j)
			{
			   	sepuede[i][j] = sepuede[i-1][j];
			}else{
				sepuede[i][j] = sepuede[i-1][j] || sepuede[i-1][j-P[i]];
			}
		}
	}
	return sepuede[n][peso];
};


int main(void){

	int P[] ={10,10,10,10};
	int n = 4;
	int peso=20; // mitad del total
	cout << "-> " << repartir(P,n,peso);

}
