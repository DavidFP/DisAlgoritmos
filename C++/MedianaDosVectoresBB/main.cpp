/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 19 de marzo de 2015, 13:30
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int menor(int a, int b){
    if(a<=b) return a;
    else return b;
}


//Mediana de dos vectores
//Tenemos en cuenta que son pares, teniendo que k = 2n
//Los vectores están ordenados

int medianaDos(int x[], int y[],int inicioX, int finX, int inicioY,int  finY){
    int mitadX = (finX-inicioX)/2;
    int mitadY = (finY-inicioY)/2;
    int numElem =0;
    //Si tienen un sólo elemento cada uno de los vectores tiene que devolver el más pequeño
    if((inicioX>=finX) && (inicioY>=finY)){
        //Estamos en el caso base
        return menor(x[finX],y[finY]);
    }
    numElem=finX-inicioX+1;
    
    if(numElem==2){
        //Tenemos un vector de dos elementos cada uno
        if(x[finX]<= y[inicioY]){
            return x[finX];
        }else if(y[finY]<x[inicioX]){
            return y[finY];
        }else{
            return max(x[inicioX],y[inicioY]);
        }
    }
    numElem = (numElem-1)/ 2;//caso general
    mitadX = inicioX + numElem;
    mitadY = inicioY + numElem;
    if(x[mitadX]==y[mitadY]) return x[mitadX]; //Si coinciden por que lo hemos encontrado 1,3,4 - 0,3,7
    else if(x[mitadX]<y[mitadY])
        return medianaDos(x,y,finX-numElem,finX,inicioY,inicioY+numElem);
    else
        return medianaDos(x,y,inicioX,finY+numElem,finY-numElem,finY);
}


int main(int argc, char** argv) {
    int x[]={1,2,3,9};
    int y[]={0,6,7,8};
    int res = medianaDos(x,y,0,0,4,4);
    cout << "Mediana dos: " << res << endl;
    
    return 0;
}

