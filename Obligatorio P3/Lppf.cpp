#include<Lppf.h>


void Crear (LPPF &l)
{
    l.prim = NULL;
    l.ult = NULL;
}

void Insfront (LPPF &l, Parada e)
{
NodoT * nuevo = new NodoT;
nuevo->info = e;
nuevo->sig = l.prim;
l.prim = nuevo;
if (l.ult == NULL)
l.ult = nuevo;

}

bool EsVacia (LPPF l)
{
return (bool) (l.prim==NULL && l.ult==NULL);
}

//Precondición: !Vacia(l)
Parada Primero (LPPF l)
{
return l.prim->info;
}


//Precondición : !Vacia(l)
void Resto (LPPF &l)
{
NodoT * aux = l.prim->sig;
delete (l.prim);
l.prim = aux;
if (l.prim == NULL)
l.ult = NULL;

}



/// largo
int Largo (LPPF l)
{
 NodoT * aux = l.prim;
 int largo = 0;
    while (aux != NULL)
    {
    largo++;
    aux = aux->sig;
    }

return largo;
}




/// k-esimo

Parada kesimo(LPPF l, int NumParada)
{
 NodoT * aux = l.prim;
int contador=1;
    while ((aux != NULL )&& (contador!=NumParada))
    {
    contador++;
    aux = aux->sig;
    }

return aux->info;

}


///lISTAR PARADAS DE LA LINEA

void ListarParadas (LPPF l)
{
    NodoT * aux = l.prim;

    while(aux!=NULL)
    {
        MostrarParada(aux->info);
       aux= aux->sig;
    }
}





//Precondición: !Vacia(l)
Parada Ultimo (LPPF l)
{
return l.ult->info;
}






void Insback (LPPF &l, Parada e)
{
NodoT * nuevo = new NodoT;
nuevo->info = e;
nuevo->sig = NULL;
if (l.ult == NULL)
{ l.ult = nuevo;
l.prim = nuevo;
}
else
{ l.ult->sig = nuevo;
l.ult = nuevo;
}
}


///hacer todo esto en LPPF
///precondicion las ciudades son member
void AgregarTramo(LPPF &L, String NombreCiudad1, String NombreCiudad2)
{
   // Parada x;

//CargarParda(x, 1, D);



 printf("\n*********Hacer esta parte**********\n");



}
