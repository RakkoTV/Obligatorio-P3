#ifndef ARREGLOCONTOPE_H_INCLUDED
#define ARREGLOCONTOPE_H_INCLUDED
#include <stdio.h>

const int Maximo=10;
typedef struct{
int InfoVertice[Maximo];
int tope;
}ArrayConTope;

//Dado un arreglo devuelve su largo
int LargoArrayConTope(ArrayConTope ArrA);

void InicializarArrayConTope(ArrayConTope &Arr);

void IncertarArrayConTope(ArrayConTope &Arr, int valor);

void DesplegarArrayConTope(ArrayConTope Arr);

/* Cargar Por  Pantalla Ndatos, lectura de un arreglo de enteros */
void CargarPorPantallaArrayConTope(ArrayConTope &Arr, int Ndatos);

/* buscar maximo: halla la posicion con el valor maximo del arreglo */
int BuscarmaximoArrayConTope(ArrayConTope Arr);

/* SumaraArrayConTope, devuelve la suma de un arreglo de enteros */
int SumaraArrayConTope(ArrayConTope Arr);

/* PromedioArrayConTope: devuelve el promedio de un arreglo */
float PromedioArrayConTope(ArrayConTope a);

/*  invierte un arreglo */
void invierto(ArrayConTope Arr);

#endif // ARREGLOCONTOPE_H_INCLUDED
