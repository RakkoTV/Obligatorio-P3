#include<Linea.h>
/*
typedef struct
{
    String CodAlf;
    LPPF Tramo;
}Linea;
*/


//Dado un String y un Tramo se crea Linea

void CargarLinea(Linea &Lin, String NombreLinea, LPPF Tramo )
{

StrCop(Lin.CodAlf, NombreLinea);
Lin.Tramo=Tramo;

}


void DarCodigoLinea(Linea Lin, String &CodAl)
{
    StrCop(CodAl, Lin.CodAlf);

}

LPPF DarTramo(Linea Lin)
{
    return Lin.Tramo;
}
///Devuelve true si la uno es menor que la dos
bool LineaMenor(Linea Lin, Linea Linead)
{
          String s,s1;
            StrCrear(s);
            StrCrear(s1);
            DarCodigoLinea(Lin,s1);
            DarCodigoLinea(Linead,s);

           return strmen(s1,s);
}
//Dada una Linea y un codigo de linea devulve true si el codlinea es menor que la lin
bool LineaMenorPorCodigo(Linea Lin, String CodLin)
{
             String s1;
            StrCrear(s1);
            DarCodigoLinea(Lin,s1);
           return strmen(CodLin, s1);
}

//Dados una linea y un nombre de linea devulve true si son de igual nombre
bool LineaIgual (Linea Lin, String CodLin)
{
            String s1;
            StrCrear(s1);
            DarCodigoLinea(Lin,s1);
          return  StringComparar(s1, CodLin);
}




