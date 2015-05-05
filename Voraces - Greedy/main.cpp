/**
 * @brief       Ejercicios de prácticas Algoritmos Voraces
 * @author      David Fernández Puentes
 * @version     1.0
 **/


#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

/*-------------EJERCITOS ---------*/
/*-------------Funciones----------*/

/**
 * @brief Función que ordena un vector de tamaño pasado por parámetro
 * @param vect
 * @param tam
 */

void ordena(int vect[], int tam) {
    int aux = 0;
    int i, j;
    for (i = 0; i < tam; ++i) {
        aux = vect[i];
        for (j = i - 1; j >= 0 && vect[j] > aux; j--) {
            vect[j + 1] = vect[j];
        }
        vect[j + 1] = aux;
    }
}

/**
 * @brief Función voraz que calcula el número máximo de defensores que debe ir
 *        a cada una de las tropas enemigas en nCiudades
 * @param enemigos
 * @param defensores
 * @param nCiudades
 * @param solucion
 */
void ejercito(int enemigos[], int defensores[], int nCiudades, int solucion[]) {
    int i;
    int solu = nCiudades - 1;
    for (i = 0; i < nCiudades; i++) {
        //iniciamos el vector de la solución
        solucion[i] = 0;
    }
    i = 0;
    int j = 0;
    while (i != nCiudades) {
        if (defensores[i] >= enemigos[j]) {
            solucion[i] = j;
            i++;
            j++;
        } else {
            solucion[i] = solu;
            solu--;
            i++;
        }
    }
}

/**
 * @brief Función que da la solución voraz al problema de los ejercitos
 */
void SolucionEjercitos() {

    int tam;
    int nCiudades;

    //Introducción de datos
    cout << "Número de ciudades" << endl;
    cin >> nCiudades;
    tam = nCiudades;
    int solucion[tam], enemigos[tam], defensores[tam];
    for (int i = 0; i < nCiudades; i++) {

        cout << "Tropa Enemigos " << i << " : ";
        cin >> enemigos[i];
        cout << "Tropa Defensores " << i << " :";
        cin >> defensores[i];
    }
    for (int i = 0; i < nCiudades; i++) {
        solucion[i] = 0;
    }
    ordena(enemigos, nCiudades);
    ordena(defensores, nCiudades);
    ejercito(enemigos, defensores, nCiudades, solucion);

    for (int i = 0; i < nCiudades; i++) {
        cout << "Ciudad atacada " << i + 1 << ": " << enemigos[solucion[i]] << "defendida por:" << defensores[i] << "soldados" << endl;
    }

};

/*---------FIN----EJERCITOS ---------*/

/*----------Coloreado de grafo-------*/
#define nVert 5 //Número de vértices

void coloreado(int arist[][nVert + 1], int numVert) {
    //Variables del problema
    int i, j; // i recorre los vertices del grafo, j los vertices del 1 al i *)
    int color; // recorre los colores del 1 al n
    bool vertColoreado; // sirve para marcar el vertice i como coloreado

    int coloresSolucion[nVert + 1] = {0, 0, 0, 0, 0, 0}; // almacena la solucion del problema

    for (i = 1; i <= numVert; i++) { //Solo se recorren con los que se les ha puesto un color
        color = 0; //Si son adyacentes
        do {
            vertColoreado = true;
            color++;
            for (j = 1; j <= i; j++) {
                //Que son adyacentes (FUNCIÓN de FACTIBILIDAD)
                if (arist[i][j] == 1 && coloresSolucion[j] == color) {
                    vertColoreado = false; // cuando el color coincide se cambia para que vuelva a probar
                }
            }
        } while (vertColoreado != true);
        coloresSolucion[i] = color;
    }
    //Mostramos la solución 
    int nCromatico = 0;
    cout << "--- COLOREADO DE GRAFO --- (EJEMPLO PARA 5 NODOS)" << endl;

    for (int i = 1; i <= numVert; i++) { //Muestra los colores que le toca
        string color = "";

        if (coloresSolucion[i] == 1) color = " Rojo";
        if (coloresSolucion[i] == 2) color = " Verde";
        if (coloresSolucion[i] == 3) color = " Azul";
        if (coloresSolucion[i] == 4) color = " Naranja";
        if (coloresSolucion[i] == 5) color = " Morado";

        //Comprobamos el número más alto de coloresSolucion
        if (coloresSolucion[i] >= nCromatico)
            nCromatico = coloresSolucion[i];

        cout << "Nodo: " << i << " Color: " << color << endl;
    }

    //Mostrar el número cromático
    cout << "----------------------------------" << endl;
    cout << "Núm Cromático :" << nCromatico << endl;
    cout << endl;
}

void solucionColoreado() {
    int numVertices = nVert;

    int arist1[nVert + 1][nVert + 1] = {// 1 son adyacentes y 0 no adyacentes -1 hacer las columnas
        //0    1   2   3   4   5
        {-1, -1, -1, -1, -1, -1}, //0
        {-1, 0, 1, 1, 0, 0}, //1
        {-1, 1, 0, 0, 1, 0}, //2
        {-1, 1, 0, 0, 1, 0}, //3
        {-1, 0, 1, 1, 0, 1}, //4
        {-1, 0, 0, 0, 1, 0} //5
    };

    int arist2[nVert + 1][nVert + 1] = {// 1 son adyacentes y 0 no adyacentes -1 hacer las columnas
        //0    1   2   3   4   5
        {-1, -1, -1, -1, -1, -1}, //0
        {-1, 0, 1, 0, 0, 1}, //1
        {-1, 1, 0, 1, 1, 0}, //2
        {-1, 1, 1, 0, 0, 0}, //3
        {-1, 0, 1, 0, 0, 0}, //4
        {-1, 1, 0, 0, 0, 0} //5
    };

    int arist3[nVert + 1][nVert + 1] = {// 1 son adyacentes y 0 no adyacentes -1 hacer las columnas
        //0    1   2   3   4   5
        {-1, -1, -1, -1, -1, -1}, //0
        {-1, 0, 1, 1, 0, 1}, //1
        {-1, 1, 0, 0, 1, 1}, //2
        {-1, 1, 0, 0, 1, 1}, //3
        {-1, 0, 1, 1, 0, 1}, //4
        {-1, 1, 1, 1, 1, 0} //5
    };

    cout << "--EJEMPLO 1--" << endl;
    coloreado(arist1, numVertices);

    cout << "--EJEMPLO 2--" << endl;
    coloreado(arist2, numVertices);

    cout << "--EJEMPLO 3--" << endl;
    coloreado(arist3, numVertices);
}
/*----------Fin Coloreado de grafo----*/

/**-----Fontanero-----*/

void mostrarFontanero(int vect[], int tam) {
    for (int i = 0; i < tam; ++i) {
        cout << vect[i] << " ";
    }
    cout << endl;
}

void vorazFontanero(int vTrabajos[], int vEspera[], int tam) {
    int espera = 0;
    for (int i = 0; i < tam; i++) {
        vEspera[i] = espera;
        espera += vTrabajos[i];
        //vTrabajos[i] = -1;
    }
}

void solucionFontanero() {
    int tam = 0;

    cout << "Cuantos trabajos desea insertar: ";
    cin >> tam;
    int vtrabajos[tam];
    for (int i = 0; i < tam; i++) {

        cout << "Trabajo :" << i << "Duración: ";
        cin >> vtrabajos[i];
        cout << endl;
    }
    //Rellenamos el vector de esperas a 0
    int vespera[tam];
    for (int i = 0; i < tam; i++)
        vespera[i] = 0;

    ordena(vtrabajos, tam);

    vorazFontanero(vtrabajos, vespera, tam);
    cout << "TRABAJOS" << endl;
    mostrarFontanero(vtrabajos, tam);
    cout << "ESPERA" << endl;
    mostrarFontanero(vespera, tam);
    //Calculamos el tiempo de espera media
    int esperaMedia = 0;
    for (int i = 0; i < tam; i++) {
        esperaMedia += vespera[i];
    }
    esperaMedia = esperaMedia / tam;
    cout << "Espera media de los usuarios: " << esperaMedia << endl;
}
/**--FIN---Fontanero-----*/

/*--------ARCHIVOS----------*/
void maximizarNumArchivos(int espacioDisco, int archivos[], int tam) {
    //Para maximizar el número de archivos vamos a empezar por los más pequeños
    //hasta completar el tamaño del disco
    int disco[tam];
    for (int i = 0; i < tam; i++) //ponemos el disco a 0 para saber los ficheros que tiene
        disco[i] = 0;

    for (int i = 0; i < tam; ++i) {
        if (espacioDisco > 0 && (espacioDisco - archivos[i] >= 0)) {
            disco[i] = archivos[i];
            espacioDisco -= archivos[i];
        }
    }
    int contadorArchivos = 0;
    for (int i = 0; i < tam; i++) {
        if (disco[i] != 0) contadorArchivos++;
    }
    if (tam == contadorArchivos) {
        cout << "Se han podido insertar todos los ficheros con éxito" << endl;
        cout << "Ficheros: " << endl;
        for (int i = 0; i < tam; i++)
            cout << "Fich:" << i << "Tam: " << disco[i] << "\t";
        cout << endl;
    } else {
        cout << "Se han podido insertar " << contadorArchivos << "con un espacio libre: " << espacioDisco << endl;
        cout << "Ficheros: " << endl;
        for (int i = 0; i < tam; i++) {
            if (disco[i] != 0)
                cout << "Fich: " << i << "Tam: " << disco[i] << "\t";
        }
        cout << endl;
    }
};

void maximizarEspacioUsado(int espacioDisco, int archivos[], int tam) {
    //Para maximizar el espacio usado, una vez que tenemos el vector con los 
    //archivos ordenado, empezamos por el más grande ya que los pequeños son más fáciles
    //de acoplar por los hueco
    int disco[tam];
    for (int i = 0; i < tam; i++) //ponemos el disco a 0 para saber los ficheros que tiene
        disco[i] = 0;

    for (int i = 0; i < tam; ++i) {
        if (espacioDisco > 0 && (espacioDisco - archivos[i] >= 0)) {
            disco[tam - i] = archivos[i];
            espacioDisco -= archivos[i];
        }
    }
    int contadorArchivos = 0;
    for (int i = 0; i < tam; i++) {
        if (disco[i] != 0) contadorArchivos++;
    }
    if (tam == contadorArchivos) {
        cout << "Se han podido insertar todos los ficheros con éxito" << endl;
        cout << "Ficheros: " << endl;
        for (int i = 0; i < tam; i++)
            cout << "Fich:" << i << "Tam: " << disco[i] << "\t";
        cout << endl;
    } else {
        cout << "Se han podido insertar " << contadorArchivos << "con un espacio libre: " << espacioDisco << endl;
        cout << "Ficheros: " << endl;
        for (int i = 0; i < tam; i++) {
            if (disco[i] != 0)
                cout << "Fich: " << i << "Tam: " << disco[i] << "\t";
        }
        cout << endl;
    }


};

void solucionArchivos() {
    int tam = 0;
    int espacioDisco = 0;
    cout << "Cuanto espacion tiene su disco (Megas): ";
    cin >>espacioDisco;
    cout << "Cuantos archivos tiene: ";
    cin >> tam;
    int archivos[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Tamaño fichero: " << i << endl;
        cin >> archivos[i];
    }
    cout << "Ficheros insertados con éxito" << endl;
    //ordenamos primero los ficheros en orden creciente
    ordena(archivos, tam);
    cout << "--------------------------------------------" << endl;
    cout << "A) Maximizando en número de archivos-" << endl;
    // maximizarNumArchivos(espacioDisco,archivos,tam);
    cout << "--------------------------------------------" << endl;
    cout << "B) Maximizando el espacio en disco -" << endl;
    maximizarEspacioUsado(espacioDisco, archivos, tam);
    cout << "--------------------------------------------" << endl;
};

/*-------FIN Archivos-------*/

/*------TRABAJO ALUMNOS-----*/


void solucionAlumnos() {
    int n;
    cout << "Cuantos alumnos tiene?:" << endl;
    cin >> n;
    int T[n][n]; //Matriz de tiempos, T[i][j] tiempo que tarda el alumno i en hacer el trabajo j
    int E[n][n]; //Matriz de eficacia, E[i][j] Eficacia con la que hace el alumno i el trabajo j

    //Relleno las dos matrices con valores aleatorios de 0 a 100 la de eficacia porcentaje  y de 0 a 600 minutos la de tiempos
    srand(time(NULL));
    cout << "---------TIEMPOS---EN MINUTOS---------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[i][j] = rand() % 600;
            cout << T[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "---------EFICACIAS-----EN PORCENTAJE-------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            E[i][j] = rand() % 100;
            cout << E[i][j] << "\t";
        }
        cout << endl;
    }
    //Ahora una vez que tenemos generadas las dos tablas tenemos que calcular
    //Por un lado la suma tiempos mínima y por otro la suma eficiencia máxima

    //SUMA TIEMPOS MÍNIMA 
    //Para ello tengo que coger el menor de cada fila y sumarlos
    int sumaTiemposMin = 0;

    int aux[n];
    for (int i = 0; i < n; i++) {
        //En cada fila los meto en un vector los ordeno y sumo el primero que es
        //el más pequeño
        for (int j = 0; j < n; j++) {
            aux[j] = T[i][j];
        }
        ordena(aux, n);
        sumaTiemposMin += aux[0];
    }
    //Limpiamos aux
    for(int i=0; i<n;++i)
        aux[i]=0;
    
    //SUMA EFICACIAS MÁXIMA
    int sumaEficaciasMaxima = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aux[j] = E[i][j];

        }
        ordena(aux, n);
        sumaEficaciasMaxima += aux[n-1];
    }
    int celdas = n * n;
    cout << "Suma tiempos minima: " << sumaTiemposMin << endl;
    cout << "Suma eficacia máxima: " << sumaEficaciasMaxima << endl;
    cout << "Media tiempo Mínimo : " << sumaTiemposMin/celdas <<" minutos" <<endl;
    cout << "Media eficacia Máxima : " << sumaEficaciasMaxima/celdas <<" %"<<endl;
};

/*--FIN TRABAJO ALUMNOS ---*/


int menu(void) {
    int opc = 0;

    cout << "----------------------------------------------" << endl;
    cout << "Problemas Voraces" << endl;
    cout << "Problema 7  - Ejercitos(Terminado)" << endl;
    cout << "Problema 8  - Conferencias(Pendiente)" << endl;
    cout << "Problema 9  - Archivos(Terminado A y B)" << endl;
    cout << "Problema 10 - Trabajo alumnos(Terminado)" << endl;
    cout << "Problema 11 - Fontanero(Terminado)" << endl;
    cout << "Problema 12 - Coloreado de grafo(Terminado)" << endl;
    cout << " -1 para SALIR" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Introduce el número del problema [7 a 12] " << endl;

    cin >> opc;

    if (opc > 6 && opc < 13)
        return opc;
    else
        return -1;
}

/*
 * 
 */
int main(void) {

    int opcMenu = 0;
    opcMenu = menu();
    if (opcMenu == -1) {
        return EXIT_SUCCESS;
    } else {
        cout << " Opcion elegida::" << opcMenu << endl;
        switch (opcMenu) {
            case 7:
            {
                cout << "Problema 7 - Ejercitos" << endl;
                SolucionEjercitos();
                main();
            }
                break;
            case 8:
            {
                cout << "Problema 8 - Conferencias"<<endl;
                cout << "No terminado :-( "<<endl;
                main();
            }
                break;
            case 9:
            {
                //Archivos
                cout << "Problema 9 - Archivos" << endl;
                solucionArchivos();
                main();
            }
                break;
            case 10:
            {
                //Trabajo Alumnos
                cout << "Problema 10 - Trabajo alumnos" << endl;
                solucionAlumnos();
                main();
            }
                break;
            case 11:
            {
                //Fontanero
                cout << "Problema 11 - Fontanero" << endl;
                solucionFontanero();
                main();
            }
                break;
            case 12:
            {
                //Coloreado de Grafo
                cout << "Problema 12 - Coloreado de grafo" << endl;
                solucionColoreado();
                main();
            }
                break;
           
        }

    }
    return EXIT_SUCCESS;
}

