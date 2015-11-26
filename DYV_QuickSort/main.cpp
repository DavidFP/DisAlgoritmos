/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 20 de marzo de 2015, 13:16
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define UMBRAL 2
using namespace std;

//Encuentra Pivote
int encuentraPivote(int T[], int i, int j){
    for(int k = i; k<=j;k++){
        if(T[k]>T[i]) return k;
        else if (T[k]<T[i]) return i;
    }
    return -1;
}
//intercambia 
void intercambia(int a, int b){
    int aux = a;
    a=b;
    b=aux;
}
//Reordena 
int reordena (int T[], int i, int d, int pivote){
    do{
        //std::swap(T[i],T[d]);
        intercambia(T[i],T[d]);
       // while(T[i]<pivote){i++;};
       // while(T[d]>=pivote){d++;};
       if(T[i]<= pivote) i++;
       if(T[d]<= pivote) d++;
    }while(i<=d);
    return i;
}

//Mostrar vector 
void mostrar(int v[], int fin){
    for(int i=0;i<=fin;i++){
        cout << v[i];
    }
    cout<<endl;
}
//Quicksort
void quickSort(int T[], int i, int j){
    int k , pivote;
    int aux;
    if(j-i < UMBRAL){
        //Algoritmo de inserción
        for(int ind=i;ind<j;ind++){
            aux = T[ind];
            while((T[j]>aux)&&(j>=0)){
                T[j+1] = T[j];
                j--;
            } 
            T[j+1] = aux;
        }
    }else{
        pivote  = encuentraPivote(T,i,j);
        if(pivote!= -1){
            k=reordena(T,i,j,T[pivote]);
            quickSort(T,i,k-1);
            quickSort(T,k,j);
        }
    }

}
/*
 * 
 */
int main(int argc, char** argv) {
    
    int v[] ={6,5,4,3,2,1};
    mostrar(v,5);
    quickSort(v,0,5);
    mostrar(v,5);
    return 0;
}

