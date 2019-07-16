#include<Parada.h>


/*

typedef struct
{
Ciudad Ciud;
int NumPar;
}Parada;
*/

//
Parada CargarParda (int NParda, Diccionario_Ciudad D)
{

Parada Par;
String s;

    do
    {


         //s2;
        StrCrear(s);
        //StrCrear(s2);
        printf("\n Ingrese el Nombre de la ciudad:");

      CargarString(s);
       fflush(stdin);
//        printf("\n Ingrese el Nombre de la ciudad de Destino:");
//
//        CargarString(s2);
//        fflush(stdin);

        if(!Member(D, s))
        {
            printf("\nLa ciudad ingresada  no existen vuelva a ingresar");
            fflush(stdin);
        }
    }while(!Member(D, s));


    ///Ciudad origen
    Par.Ciud=Find(D,s);
    Par.NumPar=NParda;// auto incrementado arranca en 2

    //Insfront(L, Par);
    ///Ciudad Destino
    return Par;



}

void MostrarParada(Parada P)
{
    printf("\n ENombre ciudad: ");
    MostrarNombre(P.Ciud);
    printf("\n El  numero de Parada es: %d", P.NumPar);
}


