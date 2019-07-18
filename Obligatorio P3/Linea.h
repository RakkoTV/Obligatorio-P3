#ifndef LINEA_H_INCLUDED
#define LINEA_H_INCLUDED

//#include<String.h>
#include<Lppf.h>

typedef struct
{
    String CodAlf;
    LPPF Tramo;
}Linea;

void DarCodigoLinea(Linea Lin, String &CodAl);

LPPF DarTramo(Linea Lin);

///Devuelve true si la uno es menor que la dos

bool LineaMenor(Linea Lin, Linea Linead);

//Dada una Linea y un codigo de linea devulve true si la primera es menor que la segunda
bool LineaMenorPorCodigo(Linea Lin, String CodLin);

//Dados una linea y un nombre de linea devulve true si son de igual nombre
bool LineaIgual (Linea Lin, String CodLin);

//Dado un String y un Tramo se crea Linea
void CargarLinea(Linea &Lin, String NombreLinea, LPPF Tramo );

void MostrarLinea(Linea Lin);
void MostrarLinea2(Linea Lin);

#endif // LINEA_H_INCLUDED
