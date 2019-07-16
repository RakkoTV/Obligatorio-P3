#include<ArregloConTope.h>
/*
const int Maximo=10;
typedef struct{
int InfoVertice[Maximo];
int tope;
}ArrayConTope;
*/

//Dado un arreglo devuelve su largo
int LargoArrayConTope(ArrayConTope ArrA)
{
return ArrA.tope;
}



/* Cargar Por  Pantalla Ndatos, lectura de un arreglo de enteros */
void CargarPorPantallaArrayConTope(ArrayConTope &Arr, int Ndatos)
{
    int Entero=0;
    for (int i=0;i < Ndatos;i++)
    {
    printf("Ingrese elemento :");
    scanf (" %d",&Entero);
    IncertarArrayConTope(Arr, Entero);
    printf("\n");
    }
}


/*  Inicializar el array con tope*/
void InicializarArrayConTope(ArrayConTope &Arr)
{
    Arr.tope=0;
}

/*  Incertar en el array con tope*/
void IncertarArrayConTope(ArrayConTope &Arr, int Valor)
{
    Arr.InfoVertice[Arr.tope]=Valor;
    Arr.tope++;
}
/* imprimo arreglo, impresion de un arreglo de enteros */
void DesplegarArrayConTope(ArrayConTope Arr)
{

    for(int i=0; i<Arr.tope; i++)
    {
        printf(" %d ",Arr.InfoVertice[i] );
    }
}



///  aca para bajo
/* buscar maximo: halla la posicion con el valor maximo del arreglo */
int BuscarmaximoArrayConTope(ArrayConTope Arr)
{
    int MaxPos= 0;
    for (int i = 1; i < Arr.tope; i++)
    {
        if ((Arr.InfoVertice[i]) > (Arr.InfoVertice[MaxPos]))
        {
        MaxPos=i;
        }
    }

    return MaxPos;
}
/* SumaraArrayConTope, devuelve la suma de un arreglo de enteros */
int SumaraArrayConTope(ArrayConTope Arr)
{
int suma=0;
for (int i=0;i<Arr.tope;i++)
{
    suma = suma + Arr.InfoVertice[i];
}

return suma;
}

/* PromedioArrayConTope: devuelve el promedio de un arreglo */
float PromedioArrayConTope(ArrayConTope Arr)
{
return (SumaraArrayConTope(Arr)/Arr.tope);
}

/*  invierte un arreglo */
void invierto(ArrayConTope Arr)
{
int temp;
for (int i=0;i < Arr.tope/2;i++)
{
temp = Arr.InfoVertice[i];
Arr.InfoVertice[i]=Arr.InfoVertice[Arr.tope-i-1];
Arr.InfoVertice[Arr.tope-i-1] = temp;
}
}

