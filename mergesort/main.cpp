#include <iostream>
#define umbral 2

using namespace std;
//
//void burbuja(int *vect, int inicio, int fin) {
//    int i, j;
//    int aux;
//    for (i = inicio; i < fin; i++)
//        for (j = inicio; j <= i; j++)
//            if (vect[j] > vect[j + 1]) {
//                aux = vect[j];
//                vect[j] = vect[j + 1];
//                vect[j + 1] = aux;
//            }
//}
//
//void mezcla(int inicio, int fin, int mitad, int *vect) {
//    int x, y, z;
//    int *aux;
//    x = inicio;
//    y = mitad + 1;
//    z = x;
//   
//    aux = new int[(fin + 1)*8];
//    while ((x <= mitad) && (y <= fin)) {
//        //Si el valor izquierda es menor que la derecha
//        //lo ordena
//        if (vect[x] <= vect[y]) {
//            aux[z] = vect[x];
//            x++;
//        } else {
//            aux[z] = vect[y];
//            y++;
//        }
//        z++;
//    }
//    //Mientras que le x este por debajo de la mitad del vector, va insertando
//    while (x <= mitad) {
//        aux[z] = vect[x];
//        x++;
//        z++;
//    }
//    //Mientras que y esté por encima de la mitad, lo va insertando
//    while (y <= fin) {
//        aux[z] = vect[y];
//        y++;
//        z++;
//    }
//    //El resto de elementos los inserta ordenados
//    for (x = inicio; x <= fin; x++) {
//        vect[x] = aux[x];
//    }
//    //free ( aux );
//    delete [] aux;
//}
//
///*----------------------------------------------------------*/
//
//void mergesort(int inicio, int fin, int *vect) {
//    int mitad;
//    //Si el tamaño de la partición está por debajo del umbral
//    if (fin - inicio + 1 <= umbral) {
//        burbuja(vect, inicio, fin); //Aplicamos un algoritmo de ordenación clasico
//    } else {
//        //En caso contrario, calculamos la mitad y llamamos recursivamente
//        //o bien por la izquierda o por la derecha de la mitad
//        mitad = (inicio + fin) / 2;
//        mergesort(inicio, mitad, vect);
//        mergesort(mitad + 1, fin, vect);
//        //Una vez que tenemos ordenadas las dos partes hacemos la mezcla del vector
//        mezcla(inicio, fin, mitad, vect);
//    }
//}
//

bool potencia2(int a){
   return !((~(~0U>>1)|a)&a -1) ;
}

int main() {
//
//    int v[] = {3, 8, 1, 9, 5, 4, 3, 8, 10};
//    mergesort(0, 8, v);
//    for (int i = 0; i < 9; i++) {
//        cout << v[i] << ", ";
//    }
    int a = 3;
    cout << potencia2(a);
    
    
    return 0;

}