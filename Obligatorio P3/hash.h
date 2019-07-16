#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include<Ciudad.h>

const int B = 3;
typedef struct nodoL {
    Ciudad info;
    nodoL * sig;
} NodoH;
typedef NodoH * ListaH;
typedef ListaH Diccionario_Ciudad[B];
/*
typedef struct{
                 int Codigo_C; ///se cambia el tipo de dato de codigo
                String Nombre_C;
}Ciudad;
*/


void Make(Diccionario_Ciudad &D);

bool Member(Diccionario_Ciudad D, String Nombre);

void Insert(Diccionario_Ciudad &D, Ciudad C);

void Modify(Diccionario_Ciudad &D, Ciudad c);

Ciudad Find(Diccionario_Ciudad D, String Nombre);

void Delete (Diccionario_Ciudad &D, String Nombre);


void CrearLista(ListaH &L);

int resumen(String S);
int h (int codigo);
//Dada una clave devuelve la persona que  está allí
Ciudad ObtenerEnListaHash (ListaH L, int clave);
bool PerteneceListaHash(ListaH L, int clave);
void InsfrontListaHash (ListaH &L,Ciudad P);

void BorrarEnListaHash(ListaH &L,int codigo);
//int cubetaMasPobladaHash (Hash tabla);
int LargoListaHash (ListaH L);


#endif // HASH_H_INCLUDED
