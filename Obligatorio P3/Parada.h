#ifndef PARADA_H_INCLUDED
#define PARADA_H_INCLUDED

#include<hash.h>
typedef struct
{
Ciudad Ciud;
int NumPar;
}Parada;


//void CargarParda (Parada &Par, int NParda, Diccionario_Ciudad D);
Parada CargarParda(int NParda, Diccionario_Ciudad D, int ValidarCodigoCiudad );

void MostrarParada(Parada P);


Parada CargarParadaInicioFin(Ciudad C, int N);

#endif // PARADA_H_INCLUDED
