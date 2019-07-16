#include<Grafo.h>

#include<Menu.h>


int main()
{
    int Op1, op3;

    Diccionario_Ciudad Ciu_dades;
    Ciudad Ci_d, CidAux;
    LPPF TramoDeParadas;
    Crear(TramoDeParadas);
    GrafoMatriz Grafo;
        CrearG(Grafo); //Lo puse aca y anda


   String ss1, ss2, ss3;

    //CrearG(Grafo);



StrCrear(ss1);StrCrear(ss2);StrCrear(ss3);
ss1="montevideo";
ss1="atlantida";
ss1="rocha";

    do
    {
        Menu1(Op1);
         switch (Op1)
        {

        case 1:
        {
            ///printf("1. Registrar los nombres de todas las ciudades que visita la empresa.\n");
            Make(Ciu_dades); ///Creamos las ciudades
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
                 printf("\n Agregar un nuevo tramo? \n");
                do
                {

                printf("\n Ingrese dos ciudades para saber si hay un tramo entre ellas:");


                        StrCrear(s);
                        StrCrear(s2);
                        printf("\n Ingrese el Nombre de la primer ciudad:");

                      CargarString(s);
                       fflush(stdin);
                        printf("\n Ingrese el Nombre de la segunda ciudad:");
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



        printf("\n Ingrese dos ciudades para saber si hay un tramo entre ellas:");

        String s, s2;
        StrCrear(s);
        StrCrear(s2);
        printf("\n Ingrese el Nombre de la ciudad:");

      CargarString(s);
       fflush(stdin);
        printf("\n Ingrese el Nombre de la ciudad de Destino:");
        CargarString(s2);
        fflush(stdin);

        if(!Member(Ciu_dades, s)&&(!Member(Ciu_dades, s2)))
        {
            printf("\nLa o las ciudades ingresadas  no existen vuelva a ingresar");
            fflush(stdin);
        }
}






            break;
        case 4:
{


int Salx=0;
            do
                {



               printf("\n Agregar un nuevo tramo\n");
               Parada x;
               int Contador=1;

               //CargarParda(x,Contador,Ciu_dades );
               Contador ++;


               MostrarParada(x);
//                String NomAux1;
//                StrCrear(NomAux1);/// VER SI AL FINAL HAY QUE DESTRUIR
//                String NomAux2;
//                StrCrear(NomAux2);/// VER SI AL FINAL HAY QUE DESTRUIR
//                printf("\nIngrese el nombre de la ciudad de partida");
//                CargarString(NomAux1);
//                fflush(stdin);
//
//
//                printf("\nIngrese el nombre de la ciudad destino");
//                CargarString(NomAux2);
//                fflush(stdin);
//                if((Member(Ciu_dades,NomAux1))&&(Member(Ciu_dades,NomAux2)))
//                {
//                    AgregarTramo(TramoDeParadas,NomAux1,NomAux2 );
//                }
//                else
//                {
//                    printf("\n Error, uno o los dos nombre ingresados no son ciudades");
//                }

                fflush(stdin);
                printf("\n Desea ingresar otro Tramo? 1- SI, 2- NO\n");
                scanf("%d", &Salx);



            }while(Salx!=2);
            }


            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;


        }
    }while(Op1 !=8);
    return 0;

}
