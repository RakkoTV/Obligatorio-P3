#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <ABB.h>
#include<ArregloConTope.h>
///MATRIZ COMUN

//Declaraciones y cabezales
const int N=3;
typedef int GrafoMatriz[N][N];



//PRIMITIVAS

//CREAR LA MATRIZ
void CrearG (GrafoMatriz &Z);

//DEVUELVE SI PERTENECE O NO EL VERTICE
bool PerteneceVertice (GrafoMatriz Z,int v);

//DEVUELVE SI PERTENECE O NO LA ARISTA
bool PerteneceArista (GrafoMatriz Z,int CoordA, int CoordB);

//CREAR ARISTA POR MEDIO DE COORDENADAS
void IncertarAristaG(GrafoMatriz &F, int CoordA, int CoordB);

//CREAR VERTICE
void IncertarVerticeG(GrafoMatriz &F, int v);

//DADO UN VERTICE DEVUELVE LA CANTIDAD DE ARISTAS QUE LO TOCAM
//CASO SEA UN LAZO SE CUENTAN DOS
//PRECONDICION VERTICE VALIDO
int GradoVerticeGrafoMatriz(GrafoMatriz A, int x);



//AUXILIARES

//calcula la  Distacia  de un vertice a otro
int DistanciaGrafoMatriz (GrafoMatriz G, int u, int v);

///  dado un nodo imprime el  camino de ese nodo al 0
//void DFSLargo(GrafoMatriz G, int actual, bool visitado[N],ArrayConTope &Arr);


void DFS(GrafoMatriz G, int actual, bool visitado[N]);


//MOSTRAR POR PANTALLA LA MATRIZ
void DesplegarGrafoMatriz(GrafoMatriz F);

//DEVULVE UN NUEVO GRAFO CON LA MULTIPLICACION DE AXB
//PRECONDICION QUE SEA POSIBLE MULTIPLICARLAS
//MM indica, en cada posicion, el
//numero de trayectorias de longitud 2 entre los vertices correspondientes,
// es decir, si en la posici´on (i, j)
//hay un 3,
//tenemos tres trayectorias distintas desde el vertice Vi al vertice Vj.
void ProductoGrafoMatriz (GrafoMatriz A, GrafoMatriz B, GrafoMatriz &C);

//DADAS DOS MATRICES DEVULVE LA SUMA EN UNA NUEVA MATRIZ
void SumaDosGrafoMatriz (GrafoMatriz A, GrafoMatriz B, GrafoMatriz &SumC);



//DADO UN GRAFO Y DOS ARISTAS, DEVUELVE CUANTAS ARISTAS HAY ENTRE ELLAS.
//Precondicion x!=y
int CuantasAristasHayDeABMatriz(GrafoMatriz A, int x, int y);

//Matriz Cubica
void MatrizCubica(GrafoMatriz A1, GrafoMatriz &C2);

//Operación auxiliar para calcular la  Distacia  de un vertice a otro
void DFSDistancia (GrafoMatriz G, int actual, int v, bool visitado [N], int & dist);

void CopiarMatriz (GrafoMatriz A, GrafoMatriz &Cop);

void RecorrerGrafo (GrafoMatriz G);

void RecorrerGrafoDFSLargo (GrafoMatriz G);


//Devuelve un array con los vertices que componen el camino desde al
void DFSDarCaminoGrafoMatriz (GrafoMatriz G, int desde ,int al, ArrayConTope &Arr );
//Operación auxiliar para Cargar el camino
void DFSDarCamino (GrafoMatriz G, int desde,int actual, bool visitado [N], ArrayConTope &Arr);


///Devuelve un array con el mayor camino del grafo
///Criterio de desempate, dados dos caminos de mismo lago el primero es el mas largo
void DarCaaminoMasLargoGrafoMatriz (GrafoMatriz G, ArrayConTope  &Arr);

#endif // GRAFO_H_INCLUDED
