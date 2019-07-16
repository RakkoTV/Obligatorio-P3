#ifndef PARADA_H_INCLUDED
#define PARADA_H_INCLUDED

#include<hash.h>
typedef struct
{
Ciudad Ciud;
int NumPar;
}Parada;


//void CargarParda (Parada &Par, int NParda, Diccionario_Ciudad D);
Parada CargarParda (int NParda, Diccionario_Ciudad D);

void MostrarParada(Parada P);




#endif // PARADA_H_INCLUDED
