#include <cstdio> 
#include <iostream>
#include <cstdlib>

using namespace std;


/*
	Método de la multiplicación rusa VA
	OJO que es recursivo
*/

int multiplicacionRusa(int x, int y){
	//Si multiplicamos por 0 devolvemos 0
	if(x==0) return 0;
	//Si multiplicamos por 1 devolvemos y, todo y por 1 es y
	if(x==1) return y;
	//Ahora si el módulo 2 es distinto de 0
	if((x%2)!=0) //Si es par le sumamos y dividimos x y multiplicamos y por 2
		return (y + multiplicacionRusa(x/2, y*2));
	else 
		return (multiplicacionRusa(x/2,y*2));

};


int main(void){
	int x = 7;
	int y = 3;
 	int valor = multiplicacionRusa(x,y);	

 	cout << "Resultado de " << x << " X " << y << " = " << valor <<endl;

 	cout << "Ahora vamos a calcular la tabla de multiplicacion:";
 	cin >> valor;

 	for(int i =0; i<=10; i++){
 		cout <<" "<<valor<< "x" << i <<" = "<<multiplicacionRusa(valor, i );
 		cout << endl;
 	}
}