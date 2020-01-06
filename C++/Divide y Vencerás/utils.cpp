#include "utils.h"

/**
 * @brief función auxiliar para mostrar el vector por pantalla
 * @param v
 * @param tam
 */
void mostrarVector(int v[], int tam) {
    for (int i = 0; i < tam; i++)
        cout << v[i] << "-";
    cout << endl;
};

/**
 * @brief función auxiliar para mostrar el vector por pantalla
 * @param v
 * @param tam
 */
void mostrarSeccionVector(int v[], int inicio, int tam) {
    for (int i = inicio; i < tam; i++)
        cout << v[i] << "-";
    cout << endl;
};

void mostrarCuadradoLatino(int matriz[][TAM_LATINO]) {
    for (int i = 0; i < TAM_LATINO; i++) {
        cout << "| ";
        for (int j = 0; j < TAM_LATINO - 1; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << i + 1 << endl;
    }
    cout << endl;
}

/////////BUSQUEDA BINARIA

/**
 * @brief   función que realiza busqueda binaria en un vector ordenado
 * @param v
 * @param inicio
 * @param fin
 * @param valor
 * @return -1 en caso de no estar el elemento, y el elemento en caso contrario
 */
int BBR(int v[], int inicio, int fin, int valor) {
    int res = 0;
    //Caso de que no encuentre el valor en el vector
    if (inicio > fin) {
        return res = -1;
    } else {
        if (inicio == fin) {
            if (valor == v[inicio]) return res = inicio;
            else return res = -1;
        } else {
            //int mitad = (fin - inicio) / 2;
            int mitad = (inicio + fin) / 2;
            cout << mitad << endl;
            if (valor == v[mitad]) return res = mitad;
            else {
                cout << mitad << endl;
                if (valor < mitad) return res = BBR(v, inicio, mitad - 1, valor);
                else return res = BBR(v, mitad + 1, fin, valor);

            }
        }
    }
    return res;
};

////////////MERGESORT//////////////

/**
 * @brief   Algoritmo de ordenación clasico del método de la burbuja ORDEN n^2
 * @param vect, vector a ordenar
 * @param inicio , posición inicial del vector
 * @param fin , posicion final del vector
 * @post vector ordenado    
 */
void bubbleSort(int *vect, int inicio, int fin) {
    int i, j;
    int aux;
    for (i = inicio; i < fin; i++)
        for (j = inicio; j <= i; j++)
            if (vect[j] > vect[j + 1]) {
                aux = vect[j];
                vect[j] = vect[j + 1];
                vect[j + 1] = aux;
            }
}

/////////ORDENACIÓN SELECCIÓN

/**
 * @brief función que ordena el vector pasado con un tamaño dado ORDEN n^2
 * @param vect
 * @param fin
 */
void OrdenacionSeleccion(int *vect, int fin) {
    int i, j, pos_min, min;

    for (i = 0; i < fin - 1; i++) {
        min = vect[i];
        pos_min = i;
        for (j = i + 1; j < fin; j++) {
            if (vect[j] < min) {
                min = vect[j];
                pos_min = j;
            }
        }
        vect[pos_min] = vect[i];
        vect[i] = min;
    }
};

/**
 * @brief  Función que fusiona y mezcla dos vectores
 * @param inicio , posición inicial del vector original
 * @param fin , posición final del vector original
 * @param mitad , posición central del vector original
 * @param vect , vector original
 */
void mezcla(int inicio, int fin, int mitad, int *vect) {
    int x, y, z;
    int *aux;
    x = inicio;
    y = mitad + 1;
    z = x;
    aux = new int[(fin + 1)*8];
    while ((x <= mitad) && (y <= fin)) {
        //Si el valor izquierda es menor que la derecha
        //lo ordena
        if (vect[x] <= vect[y]) {
            aux[z] = vect[x];
            x++;
        } else {
            aux[z] = vect[y];
            y++;
        }
        z++;
    }
    //Mientras que le x este por debajo de la mitad del vector, va insertando
    while (x <= mitad) {
        aux[z] = vect[x];
        x++;
        z++;
    }
    //Mientras que y esté por encima de la mitad, lo va insertando
    while (y <= fin) {
        aux[z] = vect[y];
        y++;
        z++;
    }
    //El resto de elementos los inserta ordenados
    for (x = inicio; x <= fin; x++) {
        vect[x] = aux[x];
    }
    //free ( aux );
    delete [] aux;
}

/**
 * @brief función que ordena un vector por el método de Mergesort
 * @param inicio, posición inicial del vector
 * @param fin , posición final del vector
 * @param vect , vector a ordenar
 */
void mergesort(int inicio, int fin, int *vect) {
    int mitad;
    //Si el tamaño de la partición está por debajo del umbral
    if (fin - inicio + 1 <= UMBRAL_MERGESORT) {
        //Aplicamos un algoritmo de ordenación clásico
        OrdenacionSeleccion(vect, fin);
    } else {
        //En caso contrario, calculamos la mitad y llamamos recursivamente
        //o bien por la izquierda o por la derecha de la mitad
        mitad = (inicio + fin) / 2;
        mergesort(inicio, mitad, vect);
        mergesort(mitad + 1, fin, vect);
        //Una vez que tenemos ordenadas las dos partes hacemos la mezcla del vector
        mezcla(inicio, fin, mitad, vect);
    }
}

/**
 * @brief función que calcula el elemento mayoritario de un vector
 * @param v
 * @param inicio
 * @param fin
 * @return el elemento mayoritario(en caso de existir)
 */
int mayoritario(int v[], int inicio, int fin) {
    //Variables
    int mitad = (fin + inicio) / 2;
    int mayori = 0;
    //int mayorIzq;
    //int mayorDer;
    int cont = 0;
    //Caso Base, si el indice de inicio es igual o mayor al de fin
    if (inicio >= fin) return v[inicio];
    else {
        int mIzq = mayoritario(v, inicio, mitad);
        int mDer = mayoritario(v, mitad + 1, fin);

        if (mIzq == mDer) return mIzq;
        else {
            if (mIzq == -1) {
                for (int i = inicio; i <= fin; i++) {
                    if (mDer == v[i]) cont++;
                }
                if (cont > mitad + 1) return mDer;
                else return -1;
            }
            if (mDer == -1) {
                for (int i = inicio; i < fin; i++) {
                    if (mIzq == -1) {
                        for (int i = inicio; i < fin; i++) {
                            if (mIzq == v[i]) cont++;
                        }
                    }
                    if (cont > mitad + 1) return mIzq;
                    else return -1;
                }
            }
            int a = 0;
            int b = 0;
            for (int i = inicio; i < fin; i++) {
                if (mIzq == v[i]) a++;
                else if (mDer == v[i]) b++;
                else return -1;
            }

        }

    }
    return mayori;
}

///////TORNILLOS Y TUERCAS

/**
 * @brief función que reordena respecto a un pivote dado
 * @param v
 * @param pivoteOrigen
 * @param inicio
 * @param fin
 */
int reordenaRespectoPivote(int v[], int pivoteOrigen, int inicio, int fin) {
    int min = inicio;
    int max = fin;
    int pivote = pivoteOrigen;
    int posicionPivote = -1;
    int aux = 0;

    while (min < max) {
        //Por la parte menor
        while (v[min] <= pivote && min < fin) {
            //Si coincide tuerca y tornillo almacenamos la posicion
            //para colocar
            if (v[min] == pivote)
                posicionPivote = min;
            min++;
        }
        //Por la parte mayor
        while (v[max] >= pivote && max > inicio) {
            if (v[max] == pivote)
                posicionPivote = max;
            max--;
        }

        //Ahora si los indices se han cruzado hay que cambiar
        //de posición los elementos
        if (max > min) {
            aux = v[min];
            v[min] = v[max];
            v[max] = aux;
            //Los motramos por pantalla para ir visualizando los cambios
            mostrarVector(v, fin);
        }
    }

    //Si la posición del pivote es mayor que 0 se queda
    if (posicionPivote - max < 0)
        aux = max;
        //Si estan en la misma posición o se cruzan 
    else if (posicionPivote - min > 0)
        aux = min;
    else aux = posicionPivote;

    //Si hay el mismo número de tuercas que de tornillos
    if (posicionPivote != -1) {
        //Se posiciona el pivote 
        v[posicionPivote] = v[aux];
        v[aux] = pivote;
        mostrarSeccionVector(v, inicio, fin);
    }
    return aux;
}

/**
 * @brief Función que soluciona el problema de los tornillos y las tuercas
 *        haciendo uso de la técnica de Divide y Vencerás, se basa en el 
 *        algoritmo de Quicksort
 * @param tornillos
 * @param tuercas
 * @param inicio
 * @param fin
 */
void TornillosTuercas(int tornillos[], int tuercas[], int inicio, int fin) {
    if (inicio <= fin) {
        int piv1, piv2;
        //Se toma la primera tuerca y se reordenan los tornillos respecto a esta
        cout << endl << "Tuerca: " << tuercas[inicio] << endl;
        cout << "ORDENAMOS RESPECTO A LA PRIMERA" << endl;

        piv1 = reordenaRespectoPivote(tornillos, tuercas[inicio], inicio, fin);
        cout << "Pos: " << piv1 << "tornillo: " << tornillos[piv1] << endl;

        //Se almacena en piv2 la posición de la tuerca anterior
        cout << "Tornillo -> Anterior: " << tornillos[piv1] << endl;
        cout << "Se ordenan las tuercas" << endl;
        piv2 = reordenaRespectoPivote(tuercas, tornillos[piv1], inicio, fin);
        cout << "Tuerca ->Posicion: " << piv2 << "Tornillo - Posición: " << tornillos[piv2] << endl;
        //Si han encajado todas las tuercas y tornillos respectivamente
        if (piv1 == piv2) cout << endl << "Pareja OK" << endl;
        //Llamada recursiva para el resto, por la izquierda del pivote y por la derecha
        TornillosTuercas(tornillos, tuercas, inicio, piv1 - 1);
        TornillosTuercas(tornillos, tuercas, piv1 + 1, fin);
    }
}

///////MULTIPLICACIÓN DE POLINOMIOS

//Lo voy a implementar haciendo uso de dos vectores de enteros
// en el que cada posición indica el grado del polinomio
//Para este caso voy a usar STL para simplificar

/**
 * @brief función que pasado dos tamaños de un vector calcula el mayor
 * @param a
 * @param b
 * @return el mayor entre a y b y si son iguales a
 */
int mayorGrado(int a, int b) {
    if (a >= b) return a;
    else return b;
}

/**
 * @brief función que muestra por pantalla un polinomio pasado como parámetro
 * @param pol1
 */
void mostrarPolinomio(vector<int> &pol1) {
    int gradoMayor = pol1.size();
    cout << endl;
    for (int i = 0; i < gradoMayor; i++) {
        if (i == 0) {
            cout << pol1[i];
        } else {
            cout << pol1[i] << "x^" << i;
        }
        if (pol1[i] > 0) {
            if (i < gradoMayor - 1) cout << " + ";
        } else {
            if (i < gradoMayor - 1) cout << " - ";
        }
    }
}

/**
 * @brief función que calcula la multiplicación de dos polinomios por el método clásico
 * @param pol1
 * @param pol2
 * @return resultado que es un vector de enteros, con el resultado de la operación
 */
vector<int> multiplicaPoliminioClasico(vector<int> &pol1, vector<int> &pol2) {
    vector<int> resultado;
    int gradoPol1 = pol1.size();
    int gradoPol2 = pol2.size();
    //redimensionamos el vector para que pueda tener todos los grados resultantes
    resultado.resize(gradoPol1 + gradoPol2 - 1, sizeof (int));

    //Recorremos los vectores y vamos multiplicando el polinomio 1 con el indice i
    //y el vector polinomio 2 con el índice j
    for (int i = 0; i < gradoPol1; i++)
        for (int j = 0; j < gradoPol2; j++)
            resultado[i + j] = pol1[i] * pol2[j];
    return resultado;
}

/**
 * @brief función hace la suma de dos polinomios pasados como parámetro
 * @param pol1
 * @param pol2
 * @return el polinomio resultado
 */
vector<int> sumaPolinomios(vector<int> &pol1, vector<int> &pol2) {
    int gradoMayor = 0;
    vector<int> resultado;
    if (pol1.size() < pol2.size()) {
        gradoMayor = pol2.size();
        pol1.resize(gradoMayor, 0);
    } else {
        gradoMayor = pol1.size();
        pol2.resize(gradoMayor, 0);
    }
    for (int i = 0; i < gradoMayor; i++)
        resultado.push_back(pol1[i] + pol2[i]);
    // mostrarPolinomio(resultado);
    return resultado;
};

/**
 * @brief función que calcula la resta de dos polinomios pasado por parámetro
 * @param pol1
 * @param pol2
 * @return 
 */
vector<int> restaPolinomios(vector<int> &pol1, vector<int> &pol2) {
    int gradoMayor = 0;
    vector<int> resultado;
    if (pol1.size() < pol2.size()) {
        gradoMayor = pol2.size();
        pol1.resize(gradoMayor, 0);
    } else {
        gradoMayor = pol1.size();
        pol2.resize(gradoMayor, 0);
    }
    for (int i = 0; i < gradoMayor; i++)
        resultado.push_back(pol1[i] - pol2[i]);
    mostrarPolinomio(resultado);
    return resultado;
};

/**
 * @brief función que calcula la multiplicación de dos polinomios pasados por 
 *        parámetro, usando la técnica de multiplicación de enteros grandes 
 *        de divide y vencerás
 * @param pol1
 * @param pol2
 * @return resultado, vector de enteros con el polinomio resultante
 */
vector<int> multiplicaPolinomios(vector<int> &pol1, vector<int> &pol2) {
    //1º tenemos que ver que polinomio tiene mayor grado
    int gradoMayor = mayorGrado(pol1.size(), pol2.size());
    vector<int> resultado;
    if (gradoMayor < 2) {
        //Tenemos que resolver de forma clásica
        multiplicaPoliminioClasico(pol1, pol2);
    } else {
        //Resolver con la técnica de DYV
        //Tenemos que ir reduciendo el tamaño a la mitad, por lo tanto
        //el grado mayor tiene que ser la mitad
        int gradoMitad = gradoMayor / 2;

        //Aplicamos el principio de la multiplicación de enteros grandes
        //  Pol1 [X|W]  y Pol2 [Z|Y]
        vector<int> x, y, w, z;
        //SUBDIVISIÓN EN POLINOMIOS MÁS PEQUEÑOS
        //Insertamos la parte izquierda de Pol 1 en el vector x
        x.insert(x.end(), pol1.begin(), pol1.begin() + gradoMitad);
        //Insertamos la parte derecha de Pol1 en el vector w
        w.insert(w.end(), pol1.begin() + gradoMitad, pol1.end());

        //Insertamos la parte izquierda de Pol2 en el vector z
        z.insert(z.end(), pol2.begin(), pol2.begin() + gradoMitad);
        //Insertamos la parte derecha de Pol2 en el vector y
        y.insert(y.end(), pol2.begin() + gradoMitad, pol2.end());

        //Aplicando la fórmula del segundo algoritmo de las diapositivas
        //wz + xy = (w + x)(y + z) - wy - xz
        vector<int> wx, yz;
        //Parte de los parentesis
        wx = sumaPolinomios(w, x);
        yz = sumaPolinomios(y, z);
        //Ahora hacemos la multiplicación
        vector<int> wx_yz;
        wx_yz = multiplicaPoliminioClasico(wx, yz);
        //ahora multiplicamos las segundas partes para luego restarlas
        vector<int> wy;
        wy = multiplicaPoliminioClasico(w, y);
        vector<int> xz;
        xz = multiplicaPoliminioClasico(x, z);

        //Ahora tenemos que restarlos, dos a dos
        //Resta parcial de wy-xz
        vector<int> wy_xz;
        wy_xz = restaPolinomios(wy, xz);
        resultado.clear();
        resultado = restaPolinomios(wx_yz, wy_xz);
        mostrarPolinomio(resultado);
    }
    return resultado;
}

/////////CUADRADO LATINO

/**
 * @brief función que calcula si es potencia de 2
 * @param val
 * @return booleano
 */
bool potencia2(int val) {
    return (~(~0U >> 1) | val)& val - 1;
}
/**
 * @brief función que resuelve el problema del cuadrado latino
 * @param tam
 * @param matriz
 */
void cuadradoLatino(int tam, int matriz[][TAM_LATINO]) {
    //Caso base, sería un cambio de 1-2 con 2-1
    if (tam == 2) {
        matriz[1][0] = 1;
        matriz[0][0] = 2;
    } else {
        //Comprobamos si es potencia de 2
        if (!potencia2(tam)) {
            //Podemos subdividir, llamada recursiva
            cuadradoLatino((tam / 2), matriz);
            //Al salir de la recursividad

            //Cuadrante Arriba derecha
            for (int i = 0; i < tam / 2; i++) {
                for (int j = (tam / 2) - 1; j < tam - 1; j++) {
                    matriz[i][j] = (i + 1)+(j + 1);
                    if (matriz[i][j] > tam) matriz[i][j] = matriz[i][j]-(tam / 2);
                }
            }
            mostrarCuadradoLatino(matriz);
            //Cuadrante Abajo izquierda
            for (int i = tam / 2; i < tam; i++)
                for (int j = 0; j < tam / 2; j++)
                    matriz[i][j] = matriz[i - tam / 2][j] +(tam / 2);
            mostrarCuadradoLatino(matriz);
            //Cuadrante Abajo derecho
            for (int i = tam / 2; i < tam; i++) {
                for (int j = (tam / 2) - 1; j < tam - 1; j++) {
                    matriz[i][j] = (i + 1) - (j + 1);
                    if (matriz[i][j] <= 0) matriz[i][j] = matriz[i][j] + (tam / 2);
                }
            }
            mostrarCuadradoLatino(matriz);
        }else{
            cout<< "No se ha contemplado el caso de que no sea potencia de 2"<<endl;
            return;
        }

    }
    mostrarCuadradoLatino(matriz);
}
