#include<ABB.h>


//Operaciones Basicas

//Crear Arbol
//Apunta a null
void MakeA (Arbol &a)
{
    a=NULL;
}



//Devolver si es Vacio un arbol
bool EmptyA (Arbol a)
{
    bool Es=false;
    if(a==NULL);
    {
        Es = true;
    }
    return Es;
}


//Devolver La raiz
//Precondicion arbol no vacio
Linea DarRaiz(Arbol a)
{
    return a->Info;
}


//Obtener el subarbol izquierdo
//Precondicion arbol no vacio

Arbol HijoIzquierdo (Arbol a)
{
    return a->Izq;
}


//Obtener el subarbol Derecho
//Precondicion arbol no vacio

Arbol HijoDerecho (Arbol a)
{
    return a->Der;
}



//Operacion sobre ABB (Arboles Binarios de Busqueda)

//Verifica si un N pertenece al arbol
//Precondicion arbol no vacio

bool MemberABB (Arbol a, String NombreLinea)
{

    String s;
    StrCrear(s);
    DarCodigoLinea(a->Info,s);
    if (a==NULL)
    {
        return false;
    }
    else
        if(StringComparar(s,NombreLinea))
        {
            return true;
        }

        else
            if(strmen(NombreLinea,s))
            {
                return MemberABB(a->Izq, NombreLinea);
            }
            else
                return MemberABB(a->Der, NombreLinea);
}



//precondicion member
Linea FindABB (Arbol a, String NombreLinea)
{

    String s;
    StrCrear(s);
    DarCodigoLinea(a->Info,s);

        if(StringComparar(s,NombreLinea))
        {
            return a->Info;
        }

        else
            if(strmen(NombreLinea,s))
            {
                return FindABB(a->Izq, NombreLinea);
            }
            else
                return FindABB(a->Der, NombreLinea);
}



//Incertar Valor en el ABB
//Precondicion que no exista en el Arbol
void InsertA(Arbol &av, Linea lin)
{

    if(av==NULL)//Si el nodo esta vacio lo pone alli.
    {
       av = new Nodoabb; //Crea un nuevo nodo
       av->Info=lin;
       av->Izq=NULL;
       av->Der=NULL;
    }
    else
        {

      if(LineaMenor(lin,av->Info))//Pregunta si N es menor que el nodo actual
           InsertA(av->Izq, lin);//Avanza al siguiente y vuelve al primer if
           else
            InsertA(av->Der, lin);
        }
}


//Devolver el minimo elemento
//Precondicion arbol no vacio
Linea MinimoRecursivo (Arbol a)
{

    if(a->Izq== NULL)
    {
        return a->Info; //Devuelvo el aterior de null
    }
    else
    {
        return MinimoRecursivo(a->Izq);
    }


}



//Precondicion arbol no vacio
//Borrar el minimo
//Es recursivo

void BorrarMinimo(Arbol &a)
{
    Arbol Aux;
    Aux=a;
    if(a->Izq== NULL)// si llego al ultimo voy a agarrar el derecho
    {
        Aux= a->Der; //A aux le pongo el derecho que es mas el mas grande que mi izq
        delete a;    //Elimino al ultimo nodo
        a=Aux; // le pongo El nodo derecho que esta en aux a a
    }
    else
        BorrarMinimo(a->Izq); //en cuanto no sea nulo lo busca y cambia al aux

}
// precondicion member
//no se modifica el Codlinea solo se modifica la secuancia de paradas
void ModifyA(Arbol &a, Linea Nueva)
{
String StrAux;
StrCrear(StrAux);
DarCodigoLinea(Nueva, StrAux);

DeleteA(a,StrAux );

InsertA(a, Nueva);


}


//Borrar una linea dada por el usuario
//Precondicion MEMBER, Emppty
void DeleteA (Arbol &a, String  NLinea)
{
    Arbol Aux;  //Creo un arbol auxiliar

    if(LineaIgual(a->Info,NLinea )) //si es el numero que busco entra aca
    {
                    if (a->Der==NULL) // Si el hijo derecho es nulo
                        {
                            Aux= a->Izq;
                            delete a;  //Pongo el hijo izquierdo en su lugar
                            a=Aux;
                        }
                    else
                        if (a->Izq==NULL) // Si el hijo izquierdo es nulo
                        {
                            Aux= a->Der;
                            delete a; //Pongo el hijo derecho  en su lugar
                            a=Aux;
                        }
                        else //
                            {
                                a->Info= MinimoRecursivo(a->Der); //Ponele el minimo de la derecha en ese nodo
                                BorrarMinimo(a->Der);//Elimina el nodo y apontalo a null
                            }
    }
    //Fin if Parte recursiva
    else
    {
        if(LineaMenorPorCodigo( a->Info, NLinea)) // Si es menor busca a la izquierda
        {
            DeleteA(a->Izq, NLinea);
        }
        else
        {
            DeleteA(a->Der, NLinea); //Si es mayor busca a la derecha
        }
    }





}











/*  ___________Recorridas___________

PARA MOSTRAR LOS ARBOLES:

        ___________Preorden:___________


        Primero el padre,
  luego el hijo izquierdo y finalmente el hijo derecho. */

void PreOrden(Arbol a)
{
    if(a!=NULL)
    {
        //printf(" %d ->", a->Info);
        PreOrden(a->Izq);
        PreOrden(a->Der);
    }
}





/*       ___________Orden:___________


 Pprimero hijo izquierdo,
 luego el padre

 y finalmente el hijo derecho  */

void Orden(Arbol a)
{
    if(a!=NULL)
    {
        Orden(a->Izq);
        printf(" No olvidar programar llamar a mostrar Lista , a->Info");
        Orden(a->Der);
    }
}







/*      ___________PosOrden:___________


Primero hijo izquierdo,
luego el hijo derecho
y finalmente el padre

*/

void PosOrden(Arbol a)

{
    if(a!=NULL)
    {
        PosOrden(a->Izq);
        PosOrden(a->Der);
       // printf(" %d ->", a->Info);
    }
}



int ContarNodos (Arbol a)
{
    if(a == NULL)
        return 0;
    else
        return 1+ ContarNodos(a->Izq)+ ContarNodos(a->Der);

}





Linea MaximoRecursivo (Arbol a)
{

    if(a->Der ==NULL)
    {
        return (a->Info);
    }
    else
        return MaximoRecursivo(a->Der);
}






//
//bool EsHoja(Arbol a, int N)
//{
//
//    if(a == NULL) //Primer paso base si es vacio y no lo encontre
//    {
//        return false;
//    }
//    else
//
//        if(N == a->Info)
//            {
//                return (bool)( (a->Izq ==NULL) &&(a->Der==NULL) ); //Segundo paso base si encuentro al N y si este n no tiene hijos es una hoja
//            }
//        else //Pasos recursivos de busqueda
//                if(N < a->Info)
//                {
//                    return EsHoja(a->Izq, N);
//                }
//                else
//                    return EsHoja(a->Der, N);
//
//}
//int Profundidad(Arbol a, int N)
//{
//    if(a!=NULL)
//    {
//        if(N == a->Info)
//        {
//            return 1;
//        }
//            else
//                if(N< a->Info)
//                {
//                    return 1 +Profundidad(a->Izq, N);
//                }
//
//                else
//                    return 1+ Profundidad(a->Der, N);
//
//
//    }
//}
//Eliminar Todos los nodos
//En posOrden
void EliminarArbol(Arbol &a)
{
    if(a!= NULL)
    {
     PosOrden(a->Izq);
     PosOrden(a->Der);
     delete a;
     a=NULL;

    }


}



