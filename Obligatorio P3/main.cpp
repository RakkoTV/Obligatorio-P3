#include<Grafo.h>

#include<Menu.h>


void CargarNodoAux(Arbol &ArboLineas, Diccionario_Ciudad Ciu_dades,GrafoMatriz Grafo, ArrayConTope ARRE, String NomAux12 )
{

    ///CargarArbolAuxiliar
//CargarNodoAux(ArboLineas, NomAux1);//Ciu_dades,Grafo,ARRE
                ///BORRAR DESPUES
                LPPF TramoAux;
                Crear(TramoAux);
                Parada Parada1;
                       String Origen, Destino;
                       StrCrear(Origen);
                       StrCrear(Destino);
                       printf("\n Ingrese el Nombre de la ciudad de Origen:  ");
                       CargarString(Origen);
                       fflush(stdin);
                       printf("\n Ingrese el Nombre de la ciudad de Destino: ");
                       CargarString(Destino);
                       fflush(stdin);
                                        if(!Member(Ciu_dades, Origen)&&(!Member(Ciu_dades, Destino)))
                                        {
                                            printf("\nLa o las ciudades ingresadas  no existen vuelva a ingresar o no existe un camino entre ambas");
                                            fflush(stdin);
                                        }
                                        else
                                            {
                                                Ciudad CidA, CidB;
                                                CidA=Find(Ciu_dades, Origen);
                                                CidB=Find(Ciu_dades, Destino);

                                                int CodOrigen=DarCodigo(CidA); // numero de parada 1
                                                int CodDestino=DarCodigo(CidB);// numero de parada tope+1

                                                if(!DFSHayCamino(Grafo,CodOrigen, CodDestino))
                                                {
                                                    printf("\n No existe un Tramo entre dichas ciudades");
                                                }
                                                else
                                                {
                                                ///Si hay camino

                                               DFSDarCaminoGrafoMatriz(Grafo,CodOrigen, CodDestino, ARRE );

                                               int NumParda=ARRE.tope-1; // vale 1 // ver otros casos

                                               Parada1=CargarParadaInicioFin(CidB,ARRE.tope);
                                               Insfront(TramoAux, Parada1);

                                               for(int i=NumParda;i>1; i--)
                                                   {
                                                    printf("\nIngresar Paradas intermedias: ");
                                                    Parada1=CargarParda(i, Ciu_dades, ARRE.InfoVertice[i]);
                                                    Insfront(TramoAux, Parada1);
                                                   }

                                                Parada1=CargarParadaInicioFin(CidA,1);
                                                Insfront(TramoAux, Parada1);
                                                Linea LineaNueva;
                                                CargarLinea( LineaNueva,NomAux12,TramoAux);

                                                fflush(stdin);
                                                InsertA(ArboLineas, LineaNueva);
                                                printf("\n Mostramos la linea cargada: ");
                                                Orden(ArboLineas);

                                               }


       StrDestruir(NomAux12);                                     }
StrDestruir(Origen);
StrCrear(Destino);



}






int main()
{
    int Op1, op3;
ArrayConTope ARRE;
InicializarArrayConTope(ARRE);

    Diccionario_Ciudad Ciu_dades;
    Ciudad Ci_d, CidAux;
    LPPF TramoDeParadas;
    Crear(TramoDeParadas);
    GrafoMatriz Grafo;
    CrearG(Grafo); //Lo puse aca y anda


   String ss1, ss2, ss3;

    //CrearG(Grafo);
 Make(Ciu_dades); ///Creamos las ciudades

 Arbol ArboLineas;
 //CrearArbol(ArboLineas);
 MakeA(ArboLineas);
 Linea LineaNueva;




StrCrear(ss1);StrCrear(ss2);StrCrear(ss3);
ss1="montevideo";
ss2="atlantida";
ss3="rocha";

    do
    {
        Menu1(Op1);
         switch (Op1)
        {

        case 1:
        {
            ///printf("1. Registrar los nombres de todas las ciudades que visita la empresa.\n");

            int Sal=0;
             int contado=0;//Inicia contador
            do /// Cargamos cada una de las  B=3.. ciudades
            {

                CargarCiudad(Ci_d, contado);
                String NomAux;
                StrCrear(NomAux);/// VER SI AL FINAL HAY QUE DESTRUIR
                DarNombre(NomAux, Ci_d);
                if(!Member(Ciu_dades,NomAux))
                {
                ///precondicion no member
                Insert(Ciu_dades,Ci_d );
                contado++;
                fflush(stdin);
                }
                else
                    {
                    printf("\n Error, El nombre ingresado ya existe");
                    }

                    StrDestruir(NomAux);///ver si lleva
                    fflush(stdin);

                printf("\n Desea ingresar otra ciudad? 1- SI, 2- NO\n");
                scanf("%d", &Sal);
            }while(Sal!=2);
        }
        break;

        case 2:///GRAFO Dados los nombres de dos ciudades, agregar un nuevo tramo entre ellas.

            {
                String s, s2;
                int Sal=0;
                 printf("\n Agregar un nuevo tramo: \n");
                do
                {

                printf("\n Ingrese dos ciudades para AGREGAR un tramo entre ellas:");


                        StrCrear(s);
                        StrCrear(s2);
                        printf("\n Ingrese el Nombre de la primer ciudad: ");

                      CargarString(s);
                       fflush(stdin);
                        printf("\n Ingrese el Nombre de la segunda ciudad: ");
                        CargarString(s2);
                        fflush(stdin);

                if(!Member(Ciu_dades, s)&&(!Member(Ciu_dades, s2)))
                {
                    printf("\nLa o las ciudades ingresadas  no existen vuelva a ingresar");
                    fflush(stdin);
                }
                else{
                        int CodCid1, CodCid2;

                CodCid1=DarCodigo(Find(Ciu_dades, s));
                CodCid2=DarCodigo(Find(Ciu_dades, s2));

                    IncertarAristaG(Grafo,CodCid1, CodCid2 );

                }

                DesplegarGrafoMatriz(Grafo);



                printf("\n Desea ingresar un nuevo tramo? 1- SI, 2- NO\n");
                scanf("%d", &Sal);
                }while(Sal!=2);
        }
            break;
        case 3:
{



        printf("\n Ingrese dos ciudades para saber si hay una sequencia que las una:");

        String s, s2;
        StrCrear(s);
        StrCrear(s2);
        printf("\n Ingrese el Nombre de la ciudad de Origen:  ");

      CargarString(s);
       fflush(stdin);
        printf("\n Ingrese el Nombre de la ciudad de Destino: ");
        CargarString(s2);
        fflush(stdin);

        if(!Member(Ciu_dades, s)&&(!Member(Ciu_dades, s2)))
        {
            printf("\nLa o las ciudades ingresadas  no existen vuelva a ingresar");
            fflush(stdin);
        }
        else
            {



                int CodCid3, CodCid4;


                CodCid3=DarCodigo(Find(Ciu_dades, s));
                CodCid4=DarCodigo(Find(Ciu_dades, s2));
                printf("\nCodigo 1: %d,Codigo 2: %d  ",CodCid3, CodCid4);
                if(DFSHayCamino(Grafo, CodCid3, CodCid4)==true)
                {

                    printf("\nhay una sequencia que las une ");
                }
                else{

                    printf("\n NO hay una sequencia que las une ");
                }

            }

}

            break;


        case 4:
            //printf("4. Ingresar una nueva l�nea a la empresa,
            //chequeando que no existiera previamente otra l�nea con el mismo c�digo alfanum�rico.\n");
{


int Salx=0;
                      String NomAux1;

            do
                {


                      //
            fflush(stdin);
               printf("\n Ingresar una nueva l�nea a la empresa\n");

               StrCrear(NomAux1);/// VER SI AL FINAL HAY QUE DESTRUIR
               printf("\nIngrese el nombre de la Linea: ");
               CargarString(NomAux1);


               if(EmptyA(ArboLineas)==true) // Si el arbol  es vacio
               {
                CargarNodoAux(ArboLineas, Ciu_dades,Grafo, ARRE, NomAux1 );
                MostrarString(NomAux1);
                StrDestruir(NomAux1);
                fflush(stdin);
               }
               else///Arbol vacio cargar todo
                {
                if(MemberABB(ArboLineas,NomAux1))// cuando este cargando
                    {
                    printf("\n Error, La linea que intenta ingresar ya existe");
                    }
                    else///Si no es miembro
                    {
                    printf("\n cuando este cargando");
                    fflush(stdin);
                   CargarNodoAux(ArboLineas, Ciu_dades,Grafo, ARRE, NomAux1 );

                    }
            }
                fflush(stdin);



                fflush(stdin);
                      //String NomAux1;




                printf("\n Desea ingresar otra Linea? 1- SI, 2- NO\n");
                scanf("%d", &Salx);



            }while(Salx!=2);
}


            break;
        case 5:

            {
                printf("\nDatos basicos de todas las lineas de la empresa: ");

                if(EmptyA2(ArboLineas)==false)
                {
                   orden2 (ArboLineas);
                }
                else
                    printf("\nNo hay ninguna linea\n");

            }

            break;
        case 6:
            {
                String NomLin;
                StrCrear(NomLin);
                printf("\nIngrese el nombre de la Linea a modificar: ");
                CargarString(NomLin);

               fflush(stdin);

               if(EmptyA2(ArboLineas)==true)/// SI EL ARBOL ESTA VACIO
               {
                   printf("\nNo hay lineas para modificar");
               }
               else
               {
                   if(MemberABB(ArboLineas,NomLin))//AGREGAR UN TRAMO
                   {
                        String NomCiudad;
                        StrCrear(NomCiudad);
                        printf("\nIngrese el nombre de Cuidad que desea agregar a la Linea: ");
                        CargarString(NomCiudad);

                        if(Member(Ciu_dades,NomCiudad)==true)// SI ESA CIUDAD EXISTE
                        {
                            Ciudad CiudDeLaNuevaParda;
                            CiudDeLaNuevaParda= Find(Ciu_dades,NomCiudad); // BUSCO ESA CIUDAD

                            Linea LinneAmodificar= FindABB(ArboLineas,NomLin);//Busco la linea a modiicar

                            LPPF TramoAmodificar =DarTramo(LinneAmodificar); //le saco el tramo
                            Parada UltimaParada = Ultimo(TramoAmodificar); //TOMO LA ULTIMA PARADA

                            int CodCiudNuevaAsta = DarCodigo(CiudDeLaNuevaParda); //tomo el codigo de la ciudad nueva

                           int CodDesde= DarCodigoCiudadParada(UltimaParada); // tomo el codigo de la ultima parada
                            //Dar codigo de la ciudad

                            if (DFSHayCamino(Grafo,CodDesde,CodCiudNuevaAsta))// si hay un camino de la la vieja a la nueva
                            {
                                printf("\n Hay un camino ver si esta ingresando el nuevo tramo al arbol");


                                Parada NuevaParada=  DevolverPardaAux(CiudDeLaNuevaParda, UltimaParada);//Va devolver la nueva parada
                                printf("\n ****La nueva parada a ingresar es:");
                                 MostrarParada(NuevaParada);
                                 printf("\n ****");
                                 ModificarLinea(LinneAmodificar, NuevaParada); ///Le agregamos al final de la linea una nueva parada
                                //Insback(TramoAmodificar,NuevaParada); // ingresamos esa nueva parada a la linea
                                //printf("\n Paradas modificadas****");
                               //ListarParadas(TramoAmodificar);
                               //printf("\n ****");
                                ModifyA(ArboLineas, LinneAmodificar); //le mandamos la nueva linea que esta modificada solamente los tramos
                                //esto va a eliminar y volver a cargar con la informacion que contiene que esta actualizada
                                    printf("\n La nueva linea modifica es****");
                                    MostrarLinea(LinneAmodificar);
                                    printf("\n ****");
                            }
                            else
                            {
                                printf("\nNo hay tramo que una la ultima parada con la cuidad ingresada");
                            }
                        }
                        else
                        {
                            printf("\nLa Cuidad ingresada no existe");
                        }

                   }
                   else
                   {
                       printf("\nLa linea ingresada no existe");
                   }
               }


                /*
Agregar una nueva parada a su recorrido.
Dado el codigo que identifica a una l�nea,
Se debe chequear que efectivamente exista un tramo entre la nueva parada y la ultima parada registrada
 hasta el momento en la linea.*/



     }

            break;
        case 7:

            {
                printf("\nDado el codigo que identifica a una linea, Listar todas las paradas,  : ");
                String Auxz;
                StrCrear(Auxz);/// VER SI AL FINAL HAY QUE DESTRUIR
               printf("\nIngrese el Codigo de la Linea: ");
               CargarString(Auxz);

               fflush(stdin);
               if(EmptyA2(ArboLineas))
                {

                printf("\nNo hay ciudades para mostrar");

               }
               else if(MemberABB(ArboLineas, Auxz))
                    {
                    Linea L1=FindABB(ArboLineas,Auxz );
                    MostrarLinea(L1);
                    }
                        else
                        {
                        printf("\nEl nombre ingresado no existe");
                        }

            }
            break;


        }
    }while(Op1 !=8);
    return 0;




}


