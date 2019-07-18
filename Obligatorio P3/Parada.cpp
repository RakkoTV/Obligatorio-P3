#include<Parada.h>


/*

typedef struct
{
Ciudad Ciud;
int NumPar;
}Parada;
*/



int DarCodigoCiudadParada(Parada Par)
{

    return DarCodigo(Par.Ciud);
}

Parada CargarParadaInicioFin(Ciudad C, int N)
{
    Parada Para;
    Para.Ciud=C;
    Para.NumPar=N;
    return Para;
}



//
Parada CargarParda (int NParda, Diccionario_Ciudad D, int ValidarCodigoCiudad )
{

Parada Par;
String s;
Ciudad CidAux;
    do
    {
         //s2;
        StrCrear(s);
        //StrCrear(s2);
        printf("\n Ingrese el Nombre de la ciudad:");
      CargarString(s);
       fflush(stdin);




        if(!Member(D, s))
        {
            printf("\nLa ciudad ingresada  no existen vuelva a ingresar");
            fflush(stdin);
        }
        else
        {

            CidAux=Find(D,s );
        }
    }while(!Member(D, s)&&(DarCodigo(CidAux)!=ValidarCodigoCiudad));


    ///Ciudad origen
    Par.Ciud=CidAux;
    Par.NumPar=ValidarCodigoCiudad;// auto incrementado arranca en 2

    //Insfront(L, Par);
    ///Ciudad Destino
    return Par;



}

Parada DevolverPardaAux(Ciudad Origen, Parada Destino)
{
    Parada nueva;
    nueva.NumPar =  Destino.NumPar +1;///sumamos 1 y se lo ponemos a la nueva parada
    nueva.Ciud = Origen;
    return nueva;
}

void MostrarParada(Parada P)
{
    printf("\n ENombre ciudad: ");
    MostrarNombre(P.Ciud);
    printf("\n El  numero de Parada es: %d", P.NumPar);
}

int DarNumeroDeParda(Parada P)
{
    return P.NumPar;
}
