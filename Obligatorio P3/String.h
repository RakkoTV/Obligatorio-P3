#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <stdio.h>
#include<string.h>



const int MAX = 160;
typedef char *String;


/// mejor pasarla al modulo string
int LargoTermino(String StrTermino);

/// mejor pasarla al modulo string
//modulo termino, dado un String devuelve si el mismo es numero entero
bool EsNumero(String nombre);




/// mejor pasarla al modulo string
//Devuelve si un numero es negativo
bool EsNegativo(String nombre);

 //dada un Caracter devulve el numero o el signo  de - en tabla ascci
//PRECONDICION: que char sea numero
int ConvertirCaracter(char Caracter);


//Precondicion que sea un numero o señal de -
//pasa un string a numero
int ConvertirStringParaNumero(String Frase);




//recibe dos strings y devuelve TRUE si el primero de ellos es
//menor (en orden alfab�tico) que el segundo
bool strmen(String s1,String s2);

//precondicion que antes del punto sea un nombre valido
bool TerminaenPuntotxt(String nombrearchivo);

bool EsAlfaNumerico(String nombre);


//devulve el correspondiente i del comando
//int DarComando(String str,String comandos );


//Crea un string vacio
void StrCrear(String &s);

//Librerar memoria y dejar el string vacio
void StrDestruir (String &s);

//devuelve el largo de una cadena
int StrLar(String s);

//copia la cadena s1 sobre la cadena s2
void StrCop(String &s2,String s1 );


//permite el ingreso de una cadena desde teclado
void CargarString(String &s);

//concatenar el segundo al final del primero
void StringCon(String &s, String s2);

//recibe 2 string y los cambia de posicion
void StrswpInvierte (String &s, String &s2);

//imprime una cadena
void MostrarString(String s);

//Devuelve true si el primer string es menor que el segundo
bool StrMenor(String s1, String s2 );

//determina si las dos cadenzas son iguales o no
bool StringComparar(String s1,String s2);

//Almacena los datos cargado a archivo
void Bajar_String(String s, FILE * f);
//Carga datos del archivo a la memoria
void Levantar_String (String &s, FILE * f);

int Potencia(int n, int m);
#endif // STRING_H_INCLUDED
