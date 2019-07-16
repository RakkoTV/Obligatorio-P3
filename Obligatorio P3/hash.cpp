#include<hash.h>


/*
const int B = 20;
typedef struct nodoL { Persona info;
nodoL * sig;
} NodoH;
typedef NodoH * ListaH;
typedef ListaH Hash[B];

*/


void Make(Diccionario_Ciudad &D)
{


int i;
for(i=0;i<B;i++)
{
   CrearLista(D[i]);
}

}
/// Auxiliar de MAKE
void CrearLista (ListaH &L) //Create
{
    L=NULL; //Apuntamos L a null
}



bool Member(Diccionario_Ciudad D,String Nombre)
{

int cubeta, clave;
clave=resumen(Nombre);
cubeta = h(clave);
return PerteneceListaHash(D[cubeta],clave);
}




//Precondición: !Pertenece(H,DarClave(P))
void Insert(Diccionario_Ciudad &D, Ciudad cid)
{
int clave,cubeta;
String S;
StrCrear(S);
DarNombre(S, cid);
 clave = resumen(S);
 cubeta = h(clave);
InsfrontListaHash(D[cubeta],cid);
}





//Precondición: !Pertenece(H,DarClave(P))
Ciudad Find (Diccionario_Ciudad D, String Nombre)
{
int cubeta,clave;
clave=resumen(Nombre);
cubeta = h(clave);
return ObtenerEnListaHash (D[cubeta],clave);
}

//Precondición: !Pertenece(H,DarClave(e))
void Delete(Diccionario_Ciudad &D,  String Nombre)
{
int cubeta,clave;
clave=resumen(Nombre);
cubeta=h(clave);
BorrarEnListaHash(D[cubeta],clave); //
}

int h (int clave)
{
	return (clave%B);
}

//Dada una clave devuelve la persona que  está allí
Ciudad ObtenerEnListaHash (ListaH L,int clave)
{

         String S;
         StrCrear(S);
         DarNombre(S,L->info);
        if(clave == resumen(S))
        {
            return L->info; //Si pide el primer elemento
        }
        else
        {
            return ObtenerEnListaHash(L->sig, clave); // si pide el segundo, entra a este y pasa al siguiente nodo
        }
}
void BorrarEnListaHash(ListaH &L,int codigo)
{
    ListaH AuxEliminar=L; //Apunto al inicio de la Lista
    ListaH AuxAnterior=NULL; //Apunto a null
    String S;
    StrCrear(S);
    DarNombre(S,AuxEliminar->info);

 while((resumen(S)!=codigo )&&(AuxEliminar != NULL)) //Sino lo busco.
      {
      AuxAnterior=AuxEliminar; //Le asigno el valor del Anterior
      AuxEliminar= AuxEliminar->sig;
      StrCrear(S);
      DarNombre(S,AuxEliminar->info);
      }

    if(AuxAnterior==NULL)//Si es el primer elemento lo elimino
    {
       L=L->sig;
       delete AuxEliminar;
    }
    else
    {
     AuxAnterior->sig=AuxEliminar->sig; //Al anterior lo hago apuntar aL sucesor de TER
     delete AuxEliminar; //Elimino a N.
    }
}

bool PerteneceListaHash(ListaH L, int clave)
{
  bool Existe=false;
  String S;
  StrCrear(S);


    while((L!=NULL)&&(Existe==false))
  {
      DarNombre(S,L->info);
      if(resumen(S) == clave)
      {
          Existe=true;
      }
      else
      {
          L= L->sig;
      }
  }
  return Existe;
}

void InsfrontListaHash (ListaH &L,Ciudad C)
{
        ListaH Nuevo= new NodoH;
        Nuevo->info=C;
        Nuevo->sig=L;
        L=Nuevo;
}

//int cubetaMasPobladaHash (Hash tabla)
//{
//int maxs = LargoListaHash (tabla[0]);
//int ind = 0;
//    for (int i = 0; i < B; i++)
//    {
//    int largo = LargoListaHash (tabla[i]);
//        if (largo > maxs)
//        {
//        maxs = largo;
//        ind = i;
//        }
//    }
//return ind;
//}

int LargoListaHash (ListaH L)
{
int cant = 0;
    while (L != NULL)
    {
    cant++;
    L = L -> sig;
    }
return cant;
}

int resumen(String S)
{
     int i=0,c=0;

    while(S[i]!='\0')
    {

       c= S[i];
       i++;
      }
return c;
}

///member Consultar
//void Modify (Diccionario_Ciudad &D, Ciudad c)
//{
//    int cubeta,clave,clave2,cubeta2;
//    clave=resumen(c.Nombre_C);
//    cubeta=h(clave);
//    BorrarEnListaHash (D[cubeta],clave);
//
//    CargarCiudad(c);
//
//    clave2 = resumen(S);
//    cubeta2 = h(clave);
//    InsfrontListaHash (D[cubeta],c);
//}
/*
void HashHaciaMapeo (Hash H, Mapeo &M)
{
for (int i = 0; i < B; i++)
{
Lista aux = H[i];
while (aux != NULL)
{
InsertarMapeo (M, aux->info);
aux = aux -> sig;
}
}
}




*/
