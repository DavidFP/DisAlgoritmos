/* 
 * File:   utils.h
 * Author: david
 *
 * Created on 19 de marzo de 2015, 11:56
 */

#ifndef UTILS_H
#define	UTILS_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;


//variables globales
#define UMBRAL_MERGESORT 2
#define TAM_LATINO 4

//Función auxiliar para mostar un vector pasado y su tamaño
void mostrarVector(int v[], int tam);
//Función auxiliar para mostar un polinomio
void mostrarPolinomio(vector<int> &pol1);
//Función auxiliar para mostrar el cuadrado latino
void mostrarCuadradoLatino(int mat[][TAM_LATINO]);

//Cabeceras de las funciones definidas en el fichero cpp
int BBR(int v[], int inicio, int fin, int valor);
void mergesort(int inicio, int fin, int *vect);
int mayoritario(int v[],int inicio, int fin);
void TornillosTuercas(int tornillos[], int tuercas[], int inicio, int fin);
vector<int> multiplicaPolinomios( vector<int> &pol1, vector<int> &pol2);
void cuadradoLatino(int tam, int matriz[][TAM_LATINO]);
//Pruebas
//vector<int> sumaPolinomios(vector<int> &pol1, vector<int> &pol2);

//vector<int> multiplicaPoliminioClasico(vector<int> &pol1, vector<int> &pol2);
#endif	/* UTILS_H */

