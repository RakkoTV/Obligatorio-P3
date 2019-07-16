#ifndef CIUDAD
#define CIUDAD

#include<String.h>


///Ver ifdefine

typedef struct{
                 int Codigo_C; ///se cambia el tipo de dato de codigo
                String Nombre_C;
}Ciudad;

void CargarCiudad(Ciudad &Ciu, int Autocincrementado);


//void CargarNombre(Ciudad &P);

void MostrarNombre(Ciudad P);
//es clave para el hash
 int DarCodigo(Ciudad p);
void DarNombre (String &Nombre,Ciudad C);

void MostrarCiudad (Ciudad C);



#endif // CIUDAD
