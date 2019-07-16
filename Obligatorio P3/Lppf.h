#ifndef LPPF_H_INCLUDED
#define LPPF_H_INCLUDED

#include<Parada.h>
typedef struct NodoTL
{
     Parada info;
    NodoTL *sig;
} NodoT;

typedef struct
{
    NodoT * prim;/// origen
    NodoT * ult; ///destino
} LPPF; ///paradas

void Crear (LPPF &l);


void Insfront (LPPF &l, Parada e);

bool EsVacia (LPPF l);

//Precondición: !Vacia(l)
Parada Primero (LPPF l);

//Precondición: !Vacia(l)
void Resto (LPPF &l);


int Largo (LPPF l);

//Precondición: !Vacia(l)
Parada kesimo(LPPF l, int NumParada);


//Precondición: !Vacia(l)
Parada Ultimo (LPPF l);


void Insback (LPPF &l, Parada e);

void AgregarTramo(LPPF &L, String NombreCiudad1, String NombreCiudad2);

#endif // LPPF_H_INCLUDED
