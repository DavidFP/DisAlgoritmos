/* 
 * File:   main.cpp
 * Author: David Fernández Puentes
 *
 * Created on 19 de marzo de 2015, 11:52
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "utils.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int opc = 0;

    do {
        cout << "\n Menú DYV " << endl;
        cout << "Introduzca ejercicio" << endl;
        cout << "1- Tornillos y tuercas" << endl;
        cout << "2- Multiplicacion Polinomios" << endl;
        cout << "3- Mayoritario" << endl;
        cout << "4- Cuadrado Latino de 8" << endl;
        cout << "5- Busqueda binaria" << endl;
        cout << "6- Mergesort" << endl;
        cout << "-1 para salir" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
            {
                //Problema 1 -Tornillos y las tuercas
                cout << "Para este ejercicio los datos van a ser fijos" << endl;
                int tuercas[] = {5, 3, 4, 2, 1};
                cout << "TUERCAS: ";
                mostrarVector(tuercas, 5);
                cout << endl;
                int tornillos[] = {1, 2, 4, 3, 5};
                cout << "TORNILLOS :";
                mostrarVector(tornillos, 5);
                TornillosTuercas(tornillos, tuercas, 0, 4);

                //ORDENADOS
                cout << "ORDENADOS" << endl;
                cout << "TUERCAS: ";
                mostrarVector(tuercas, 5);
                cout << endl;
                cout << "TORNILLOS :";
                mostrarVector(tornillos, 5);
            }
                break;

            case 2:
            {
                //Problema 2 - Multiplicación de polinomios
                //Funciona regular :-(
                vector<int> pol1, pol2;
                int indicePol1 = 0;
                cout << "Grado Polinomio 1:";
                cin>>indicePol1;
                int aux;
                for (int i = 0; i < indicePol1; i++) {
                    cout << "Grado:" << i << ":";
                    cin>>aux;
                    pol1.push_back(aux);
                }
                int indicePol2 = 0;
                cout << "Grado Polinomio 2:";
                cin>>indicePol2;
                for (int i = 0; i < indicePol2; i++) {
                    cout << "Grado: " << i << ":";
                    cin>>aux;
                    pol2.push_back(aux);
                }
                cout << "ORIGINALES \n POL1:";
                mostrarPolinomio(pol1);
                cout << "\nPOL 2:";
                mostrarPolinomio(pol2);
                cout << "RESULTADO" << endl;
                // sumaPolinomios(pol1,pol2);
                //multiplicaPolinomios(pol1,pol2);
                vector<int> res;
                //res = multiplicaPoliminioClasico(pol1,pol2);
                res = multiplicaPolinomios(pol1, pol2);
                mostrarPolinomio(res);
            }
                break;



            case 3:
            {
                //Problema 3 - Elemento mayoritario
                cout << "Introduzca el tamaño del vector" << endl;
                int tam = 0;
                cin >> tam;
                int vMayoritario[tam];
                for (int i = 0; i < tam; i++) {
                    cout << "Elemento" << i << ": ";
                    cin >> vMayoritario[i];
                }
                cout << "Vector rellenado" << endl;
                mostrarVector(vMayoritario, tam);

                cout << "Elemento mayoritario: " << mayoritario(vMayoritario, 0, tam);
                //
            }
                break;

            case 4:{
                //TAM_LATINO definido como global en utils.h
                int matriz[TAM_LATINO][TAM_LATINO];
                for(int i =0 ;i < TAM_LATINO;i++)
                    for(int j=0 ; j<TAM_LATINO;j++)
                       matriz[i][j] =0;
                
                cuadradoLatino(TAM_LATINO,matriz);
            }
            break;

            case 5: //Problema 5 - Busqueda Binaria
            {
                cout << "Introduzca el tamaño del vector" << endl;
                int tam = 0;
                cin >> tam;
                int vbbr[tam];
                for (int i = 0; i < tam; i++) {
                    vbbr[i] = i + 1;
                }
                mostrarVector(vbbr, tam);
                int valor;
                cout << "En un vector ordenado creciente de 0 a 10 \n Introduzca valor a buscar:" << endl;
                cin >>valor;
                int pos = BBR(vbbr, 0, tam, valor);
                cout << "OJO: La posición empieza en 0, al ser un vector" << endl;
                cout << "La posicion del valor" << valor << " es: " << pos << endl;
            }
                break;

            case 6: //Problema 6 - Ordenación Mergesort 
            {

                cout << "Tamaño del vector" << endl;
                int tam = 0;
                cin >> tam;
                int vMerge[tam];
                for (int i = tam - 1; i >= 0; i--) {
                    vMerge[i] = tam - i;
                }
                //Mostramos el vector original
                cout << "Vector Original :";
                mostrarVector(vMerge, tam);
                //Llamada al algorimo
                mergesort(0, tam, vMerge);
                //Mostramos el vector ordenado
                cout << "Vector Ordenado :";
                mostrarVector(vMerge, tam);
            }
                break;
        }
    } while (opc != -1);

    return 0;
}

