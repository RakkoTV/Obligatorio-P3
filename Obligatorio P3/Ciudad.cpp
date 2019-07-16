#include<Ciudad.h>
/*
typedef struct{
                 int Codigo_C; ///se cambia el tipo de dato de codigo
                String Nombre_C;
}Ciudad;
*/


void CargarCiudad(Ciudad &Ciu, int Autocincrementado)
{

    StrCrear(Ciu.Nombre_C);
    printf("\nIngrese el nombre de la Ciudad:** " );
    CargarString(Ciu.Nombre_C);

    fflush(stdin);

    Ciu.Codigo_C=Autocincrementado;


}




///Ingresar codigo a la ciudad recorrer todo y sumar
void MostrarNombre(Ciudad C)
{
   MostrarString(C.Nombre_C);

}
 int DarCodigo(Ciudad C)
{
    return (C.Codigo_C);
}

void DarNombre (String &Nombre, Ciudad C)
{
StrCop(Nombre, C.Nombre_C);
}




void MostrarCiudad (Ciudad C)
{
    MostrarNombre(C);
    DarCodigo(C);

}

