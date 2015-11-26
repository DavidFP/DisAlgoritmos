/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 24 de marzo de 2015, 18:03
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#define MAX 100
using namespace std;

bool solucion(int c[], int total, int tam){
    int res = 0;
    for(int i=0; i<tam;i++)
        res += c[i];
    if(res==total) return true;
    else return false;
};
/*
int seleccion(int c[]){
    return max(c);
};
*/
int seleccion(int c[], int p){
    return(c[p]);
};


bool factible(int c[], int total, int tam){
    int res =0;
    for(int i=0; i<tam; i++)
        res +=c[i];
    if(res==total) return true;
    else return false;
};


bool greedyCambio(int monedas[], int tam, int total, int cambio[], int t){
    int i,x,m =0;
    for(int i=0; i<tam;i++) cambio[i] =0;
    while(!solucion(monedas,total,t)&&(cambio!=NULL)){
        x=seleccion(monedas,m);
        m++;
        if(factible(cambio,total,tam)) cambio[t]=x;
        t++;
    }
    return solucion(cambio,total,tam);
}




/*
 * 
 */
int main(int argc, char** argv) {
    int cambio[4];
    int monedas[] ={50,25,5,1};
    int n =4; // tamaño de las monedas
    int total=81;
    int t =0;
    
    bool res = greedyCambio(monedas,n,total,cambio,t);
    if(res){ cout << "Cambio Justo"<<endl;
    for(int i=0; i<n; i++) cout << "Monedas: " << monedas[i] << "Cambio: "<<cambio[i]<<endl;
    }else{
        for(int i=0; i<n; i++) cout << "Monedas: " << monedas[i] << "Cambio: "<<cambio[i]<<endl;
    } 
    
    return 0;
}

