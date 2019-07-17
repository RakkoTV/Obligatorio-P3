#include<Grafo.h>


///GrafoMatriz[N][N];
/*
const int N = 6;
typedef int GrafoMatriz[N][N];
*/



//CREAR LA MATRIZ
void CrearG (GrafoMatriz &Z)
{
for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
        Z[i][j] = 0;
        }
    }
}

//CREAR VERTICE No se utiliza dado que las ciudades son predefinidas
void IncertarVerticeG(GrafoMatriz &F, int v)
{
//cometo
}

//CREAR ARISTA POR MEDIO DE CO
void IncertarAristaG(GrafoMatriz &F, int CoordA, int CoordB)
{
    if(CoordA!=CoordB)
    {
    F[CoordA][CoordB] = 1;
    F[CoordB][CoordA] = 1;
    }
    else
        {
        F[CoordA][CoordA] = 1;
        }
}

//MOSTRAR POR PANTALLA LA MATRIZ
void DesplegarGrafoMatriz(GrafoMatriz F)
{
for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("   %d  ", F[i][j]);
        }
        printf("\n");
    }
}


//Dados dos vertices, determinar si hay una arista que los une
bool HayArista (GrafoMatriz G, int u, int v)
{
    return (bool) (G[u][v] == 1);

}




///  dado un nodo imprime el  camino de ese nodo al 0
void DFSLargo(GrafoMatriz G, int actual, bool visitado[N],ArrayConTope &Arr)
{
        visitado[actual] = true;
bool parar=false;

IncertarArrayConTope(Arr, actual);

    for (int j=0; j<N; j++)
    {
        if ((G[actual][j] == 1)&&(parar==false))
        {
            if (!visitado[j])
            {
            DFSLargo(G, j, visitado, Arr);
            }
        parar=true;
        }
    }
}

//Hace una copia de A
void CopiarMatriz (GrafoMatriz A, GrafoMatriz &Cop)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
        Cop[i][j] = A[i][j];
          }
    }
}


void DFS(GrafoMatriz G, int actual, bool visitado[N])
{
        visitado[actual] = true;
printf ("\n ida:    %d", actual);

    for (int j=0; j<N; j++)
    {
        if (G[actual][j] == 1)
        {
            if (!visitado[j])
            {
            DFS(G, j, visitado);
            }
        }
    }
///printf ("\n vuelta: %d", actual);
}





void RecorrerGrafo (GrafoMatriz G)
{

bool visitado[N];
for (int i=0; i<N; i++)
visitado[i] = false;


for(int j=0; j<N; j++)///PARA QUE  VISITE LOS GRAFOS DISCONEXOS
    {
    if (!visitado[j])
            {
            DFS(G, j, visitado);

            }
    }
}


//Devuelve un array con los vertices que componen el camino desde al
void DFSDarCaminoGrafoMatriz (GrafoMatriz G, int desde ,int al, ArrayConTope &Arr )
{

    IncertarArrayConTope(Arr, desde);
   // int dist = 0;/// verificar esta variable
    bool visitado [N];
        for (int i = 0; i < N; i++)
        {
        visitado [i] = false;
        }

    DFSDarCamino(G, desde,al, visitado, Arr);
}
//Operación auxiliar para Cargar el camino
void DFSDarCamino (GrafoMatriz G, int desde,int actual, bool visitado [N], ArrayConTope &Arr)
{
    visitado [actual] = true;

    int j = 0;

        while (j < N && !visitado [desde])
        {
            if (G [actual][j] == 1)
            {
                if (!visitado [j])
                {
                   DFSDarCamino (G,desde, j, visitado, Arr);
                }
            }
            j++;
        }
    if ((actual != desde) && (visitado [desde]))/// no se que quise poner?pero anda
    {
        IncertarArrayConTope(Arr, actual);
    }

}






//Devuelve si hay camino desde al
bool DFSHayCamino (GrafoMatriz G, int desde ,int al)
{

    bool visitado [N];
        for (int i = 0; i < N; i++)
        {
        visitado [i] = false;
        }
    DFSCamino(G, desde,al, visitado);


    for (int i = 0; i < N; i++)
        {

        printf("\n VISITO AL %d ", (int) visitado[i]);
        }


    return visitado[al];
}
//Operación auxiliar para DFSHayCamino
void DFSCamino (GrafoMatriz G, int actual,int desde, bool visitado [N])
{
    visitado [actual] = true;

    int j = 0;

        while (j < N && !visitado [desde])
        {
            if (G [actual][j] == 1)
            {
                if (!visitado [j])
                {
                   DFSCamino (G,j, desde, visitado);
                }
            }
            j++;
        }


}















//cantidad de componentes conexas
/// devuelve uno si es conexo o el numero de componentes conexas
int CantidadComponentesConexas (GrafoMatriz G)
{
    int cant=0;
bool visitado[N];
for (int i=0; i<N; i++)
visitado[i] = false;


for(int j=0; j<N; j++)///PARA QUE  VISITE LOS GRAFOS DISCONEXOS
    {
    if (!visitado[j])
            {
            DFS(G, j, visitado);
            cant++;
            }
    }
   return cant;
}





//DEVULVE UN NUEVO GRAFO CON LA MULTIPLICACION DE AXB
//PRECONDICION QUE SEA POSIBLE MULTIPLICARLAS
//MM indica, en cada posicion, el
//numero de trayectorias de longitud 2 entre los vertices correspondientes,
// es decir, si en la posici´on (i, j)
//hay un 3,
//tenemos tres trayectorias distintas desde el vertice Vi al vertice Vj.
void ProductoGrafoMatriz (GrafoMatriz A, GrafoMatriz B, GrafoMatriz &C)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
        C[i][j] = 0;

            for (int k = 0; k < N; k++)
            {
            C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}


//DADAS DOS MATRICES DEVULVE LA SUMA EN UNA NUEVA MATRIZ
void SumaDosGrafoMatriz (GrafoMatriz A, GrafoMatriz B, GrafoMatriz &SumC)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
        SumC[i][j] = A[i][j] + B[i][j];
          }
    }
}

//DADO UN VERTICE DEVUELVE LA CANTIDAD DE ARISTAS QUE LO TOCAM
//CASO SEA UN LAZO SE CUENTAN DOS
//PRECONDICION VERTICE VALIDO
int GradoVerticeGrafoMatriz(GrafoMatriz A, int x)
{
 int   GradoVert=0;
     for (int i = 0; i < N; i++)
     {
         if(i!=x)
         {
             if(A[i][x]==1)
             {
                GradoVert++;
             }
         }
         else
             if(A[i][x]==1)
             {
                GradoVert=GradoVert+2;
             }
     }
return GradoVert;
}

bool PerteneceVertice (GrafoMatriz Z,int v)
{
 bool pertenece = false;
    int i=0;
    while((pertenece != true) && (i<N))
    {
        if(Z[i][v]==1)
            pertenece = true;
        else
            pertenece = false;
        i++;
    }

return pertenece;
}

bool PerteneceArista (GrafoMatriz Z,int CoordA, int CoordB)
{
 bool pertenece = false;

if ((Z[CoordA][CoordB]==1)||(Z[CoordB][CoordA]==1))
    pertenece = true;
else
    pertenece = false;

return pertenece;
}





//DADO UN GRAFO Y DOS ARISTAS, DEVUELVE CUANTAS ARISTAS HAY ENTRE ELLAS.
//Precondicion x!=y
int CuantasAristasHayDeABMatriZ(GrafoMatriz A, int x, int y)
{
    return A[x][y];
}

//Matriz Cubica
void MatrizCubica(GrafoMatriz A1, GrafoMatriz &C2)
{
    GrafoMatriz C3;
    CrearG(C3);
    ProductoGrafoMatriz(A1,A1,C3);// CUADRADA
    ProductoGrafoMatriz(C3,A1,C2);// CUBICA
}

///
//calcula la  Distacia  de un vertice a otro
int DistanciaGrafoMatriz (GrafoMatriz G, int u, int v)
{
    int dist = 0;
    bool visitado [N];
        for (int i = 0; i < N; i++)
        {
        visitado [i] = false;
        }
    DFSDistancia (G, u, v, visitado, dist);

    return dist;
}

//Operación auxiliar para calcular la  Distacia  de un vertice a otro
void DFSDistancia (GrafoMatriz G, int actual, int v, bool visitado [N], int & dist)
{
    visitado [actual] = true;

    int j = 0;

        while (j < N && !visitado [v])
        {
            if (G [actual][j] == 1)
            {
                if (!visitado [j])
                {
                   DFSDistancia (G, j, v, visitado, dist);
                }
            }
            j++;
        }
    if ((actual != v) && (visitado [v]))
    {
      dist++;
    }
}





///Devuelve un array con el mayor camino del grafo
///Criterio de desempate, dados dos caminos de mismo lago el primero es el mas largo
void DarCaaminoMasLargoGrafoMatriz (GrafoMatriz G, ArrayConTope  &Arr)
{
    ArrayConTope AuxArr;
    InicializarArrayConTope(AuxArr);

    int i=0;

    DFSDarCaminoGrafoMatriz(G,i,i,Arr);

   for(i=0; i<N; i++)
   {
       for(int j=0; j<N; j++)
           {
               if(i!=j)
              {
                  DFSDarCaminoGrafoMatriz(G,i,j,AuxArr);


                  if(LargoArrayConTope(AuxArr) >LargoArrayConTope(Arr))
                  {
                      Arr=AuxArr;
                     // CopiarArrayConTope(AuxArr,Arr) ;

                  }
                  InicializarArrayConTope(AuxArr);
              }
           }
   }
}
