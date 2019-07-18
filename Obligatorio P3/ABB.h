#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

#include<Linea.h>

//#include<stdio.h>




typedef struct NodoAb
{
    Linea Info;
    NodoAb *Izq;
    NodoAb *Der;
}Nodoabb;

typedef Nodoabb * Arbol;





//Operaciones Basicas

//Crear Arbol
//Apunta a null
//void CrearArbol (Arbol &a);
void MakeA (Arbol &a);

bool MemberABB (Arbol a, String NombreLinea);
bool EmptyA (Arbol a);
void DeleteA (Arbol &a, String  NLinea);

///precondicion member
Linea FindABB (Arbol a, String NombreLinea);

//Dado un valor y 2 arboles. Poner el valor como padre
 // y los arboles como hijos
//CREA EL NODO


Arbol Constructor (int Raiz, Arbol A, Arbol B);



//Devolver La raiz
//Precondicion arbol no vacio
Linea DarRaiz(Arbol a);

//Devolver si es Vacio un arbol
bool EsVacio (Arbol a);

//Obtener el subarbol izquierdo
//Precondicion arbol no vacio

Arbol HijoIzquierdo (Arbol a);


//Obtener el subarbol Derecho
//Precondicion arbol no vacio

Arbol HijoDerecho (Arbol a);




//Operacion sobre ABB (Arboles Binarios de Busqueda)

//Verifica si un N pertenece al arbol
//Precondicion arbol no vacio
bool PerteneceRecursivoABB(Arbol a, int n);

//Verifica si un N pertenece al arbol
//Precondicion arbol no vacio
bool PerteneceInteractivo (Arbol a, int n);

//Incertar Valor en el ABB
//Precondicion que no exista en el Arbol
void InsertA(Arbol &a, Linea lin);


//Devolver el minimo elemento
//Precondicion arbol no vacio
Linea MinimoRecursivo (Arbol a);

//Devolver el minimo elemento
//Precondicion arbol no vacio
int MinimoInteractivo (Arbol a);

//Crea nodo de arbol NO BORRAR
//void CargarNodoAux(Arbol &ArboLineas, String NomAux1);



//Precondicion arbol no vacio
//Borrar el minimo

void BorrarMinimo(Arbol &a);

//Borrar un N dado por el usuario
//Precondicion existe N y arbol no vacio
void BorrarNodo (Arbol &a, int N);

// precondicion member
//no se modifica el Codlinea solo se modifica la secuancia de paradas
void ModifyA(Arbol &a, Linea Nueva);

/*  ___________Recorridas___________

PARA MOSTRAR LOS ARBOLES:

        ___________Preorden:___________


        Primero el padre,
  luego el hijo izquierdo y finalmente el hijo derecho. */

void PreOrden(Arbol a);

/*       ___________Orden:___________


 Pprimero hijo izquierdo,
 luego el padre

 y finalmente el hijo derecho  */

void Orden(Arbol a);



/*      ___________PosOrden:___________


Primero hijo izquierdo,
luego el hijo derecho
y finalmente el padre

*/

void PosOrden(Arbol a);




int ContarNodos (Arbol a);




Linea MaximoRecursivo (Arbol a);


void orden2 (Arbol a);

bool EsHoja(Arbol a, int N);

int Profundidad(Arbol a, int N);

//Eliminar Todos los nodos
void EliminarArbol(Arbol &a);

#endif // ABB_H_INCLUDED
