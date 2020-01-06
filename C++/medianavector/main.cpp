#include <iostream>

using namespace std;

void Cambiar(int i, int j, int *v) {

    int x;

    x = v[i];
    v[i] = v[j];
    v[j] = x;

}

/*-------------------------------------------*/

int encuentrapivote(int i, int j, int *v) {

    int primera_clave, k;

    primera_clave = v[i];
    k = i + 1;

    while ((v[k] == primera_clave) && (k <= j)) {
        k++;
    }

    if (k <= j) {

        if (v[k] <= primera_clave) {
            return i;
        } else {
            return k;
        }

    } else {
        return -1;
    }

}

/*--------------------------------------------*/

int reordena(int i, int j, int pivote, int *v) {

    int inf, sup;

    inf = i;
    sup = j;

    do {

        Cambiar(inf, sup, v);
        while (v[inf] < pivote) {
            inf++;
        }
        while (v[sup] >= pivote) {
            sup--;
        }

    } while (inf <= sup);

    return inf;

}

int Mediana(int *T, int i, int j, int k) {

    int pivote;

    if (i == j)
        return T[i];
    else {
        pivote = encuentrapivote(i, j, T);
        if (pivote == -1) //cuando todos son iguales
            return T[i];

        pivote = reordena(i, j, T[pivote], T); //lo coloca el elemento en el sitio justo y devuelve la posición
        if (k < pivote) //Se busca por la izquierda
            return Mediana(T, i, pivote - 1, k);
        else //se busca por la derecha
            return Mediana(T, pivote, j, k);
    }
}

int main() {

    int v[] = {2, 3, 5, 1, 7, 9, 8};
    int min, max;
    cout << "La mediana del vector es : " << Mediana(v, 0, 6, (6 - 0) / 2);
    return 0;
}

