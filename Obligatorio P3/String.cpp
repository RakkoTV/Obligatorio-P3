#include<String.h>



//dada un Caracter devulve el numero o el signo  de - en tabla ascci
//PRECONDICION: que char sea numero
int ConvertirCaracter(char Caracter)
{
    switch(Caracter)
            {
            case '0':
                        return 0;
                        break;
            case '1':
                        return 1;
                        break;
            case '2':
                        return 2;
                        break;
            case '3':
                        return 3;
                        break;
            case '4':
                        return 4;
                        break;
            case '5':
                        return 5;
                        break;
            case '6':
                        return 6;
                        break;
            case '7':
                        return 7;
                        break;
            case '8':
                        return 8;
                        break;
            case '9':
                        return 9;
                        break;
            case '-':
                        return -1;	//retornamos -1 para multilpicar por las otras cosas
                        break;
            }
}







//se utiliza para que el - no interfiera al pasar de string a numero
int LargoTermino(String StrTermino)
{
int i=0, Largo=0;

while( StrTermino[i] != '\0' )
{
if ( (int(StrTermino[i]) >= 48) && (int(StrTermino[i]) <= 57) )
{
    Largo++;
}

i++;


}

return Largo;
}





//modulo termino, dado un String devuelve si el mismo es numero entero
//acepta el -
bool EsNumero(String nombre)
{
bool es=true;
int i=0, j= StrLar(nombre);

while(i< j && es==true)
	{
	    //printf("entro es un numero\n ");
	//comparar char por char contra


        if ((nombre[i]>=48 && nombre[i]<=57)||(nombre[i]=45))
        {
            i++;
        }
		else
		{
			es=false;
		}
    }
return es;
}



//revisar si es negativo va fuera de esto
//Devuelve si un numero es negativo
bool EsNegativo(String nombre)
{
bool es=true;
int i=0, j= StrLar(nombre);
        if(nombre[i]==45)
        {
            i=2;
            while((i<j) && (es==true))
            {
                //printf("entro es un numero\n ");
            //comparar char por char contra

                    if (nombre[i]>=48 && nombre[i]<=57)
                    {
                        i++;
                    }
                    else
                    {
                        es=false;
                    }
            }
        }
       else
        {
                    es=false;
        }


return es;
}

int Potencia(int n, int m)
{
    if(m==0)
        return 1;
    else
        return n* Potencia(n, m-1);
}


//Precondicion que sea un numero o señal de - el primer caracter
//pasa un string a numero
int ConvertirStringParaNumero(String Frase)
{

    int i=0, aux=0, Larg=(LargoTermino(Frase)-1),LargoAux=Larg;


    bool Negativo=EsNegativo(Frase);

    if(Negativo==true)// si es true
    {
        i=1;
    }

    while(LargoAux!=0)
    {


                aux =aux+(ConvertirCaracter(Frase[i]) * Potencia(10, LargoAux));
                i++;
                LargoAux--;
    }
    aux=aux+ConvertirCaracter(Frase[i]);

    if(Negativo==true)// si es true
    {
        aux=aux*-1;
    }


return aux;
}






//precondicion que antes del punto sea un nombre valido
bool TerminaenPuntotxt(String nombrearchivo)
{
    /// ademas de verificar los ultimos 4, asegurarse que todos los anteriores sean alfanumericos
    int largo, largototal=StrLar(nombrearchivo);
    largo=largototal-4;
    bool es=false;
if(largototal>4)//Para el caso que el usuario solo ingrese .txt sin nada antes
{
    if((nombrearchivo[largo]=='.')&&(nombrearchivo[largo+1]=='t')&&( nombrearchivo[largo+2]=='x') &&(nombrearchivo[largo+3]=='t' ) )
        {
            es=true;
        }
}
     return es;
    }


//Crea un string vacio

void StrCrear(String &s)
{
    s= new char[1];
    s[0]='\0';
}
//Librerar memoria y dejar el string vacio
void StrDestruir(String &s)
{///Librerar memoria y dejar el string vacio
    delete []s;
    s= NULL;
}
//devuelva el largo de un string. Se entiende por largo, la cantidad de caracteres antes del caracter nulo.
int StrLar(String s)
{
    int i=0;
    while (s[i]!='\0')
    {
        i++;
    }
    return i;
}


///strcop que reciba dos String y copia el segundo en el primero.
void StrCop(String &s2,String s1 )
{
    int i=0;
    int largo= StrLar(s1);
    delete []s2;
    s2= new char[largo+1];
    while(s1[i] !='\0')
    {
        s2[i]=s1[i];
        i++;
    }
    s2[i]='\0';
}

//Cargar
void CargarString(String &s)
 {
     fflush(stdin);
//printf("\nEntro a string");
    String aux= new char[MAX];
    int i=0;
    char c;
    scanf("%c",&c);
   // printf("\nAntes del while");
    while ((c!='\n') && (i<MAX))
    {
        aux[i]=c;
         i++;
        scanf("%c",&c);
       // printf("\nEntro al whuile dentro de  string");
    }
    aux[i]='\0';
    StrCop(s, aux);
    StrDestruir(aux);
  //  printf("\nsalio de  string");
}

//concatenar el segundo al final del primero
void StringCon(String &s1,String s2)
     {
     String aux;
     StrCrear(aux);
     StrCop(aux, s1);
    int largo = StrLar(s1) + StrLar(s2) + 1;
     if (largo > MAX)
     {
         largo = MAX;
     }
     delete [] s1;
     s1 = new char[largo];
     int i=0;
     while (aux[i] != '\0')
        {
            s1[i] = aux[i];
            i++;
      }
    int j=0;
        while (s2[j] != '\0' && i < MAX-1)
                {
                    s1[i] = s2[j];
                    i++;
                    j++;
                 }

                 s1[i] = '\0';
                 StrDestruir(aux);
                 }

//recibe 2 String y los cambia de posicion
void StrswpInvierte(String &s, String &s2)
{
    String aux;
    aux = s;
    s= s2;
    s2 = aux;
}

//despliegue un String por pantalla.
void MostrarString(String s)
{
    ///despliegue un String por pantalla.
    int i=0;
//printf("Entro al mostrar");
    while(s[i]!='\0')
    {
        //printf("Entro al while");
        printf("%c",s[i]);
        i++;
    }
}

//recibe dos strings y devuelve TRUE si el primero de ellos es
//menor (en orden alfab�tico) que el segundo
bool strmen(String s1,String s2)
{
    ///recibe dos strings y devuelve TRUE si el primero de ellos es
///menor (en orden alfab�tico) que el segundo
int i=0;
bool encontre = false;
bool menor = false;
while ((!encontre) && (s1[i]!='\0') && (s2[i]!='\0')) {
if (s1[i]!=s2[i]) {
encontre = true;
if (s1[i]<s2[i])
menor = true;
}
i++;
}
if ((!encontre) && (s2[i]!='\0'))
menor = true;
return menor;
}

//Devuelve true si el primer string es menor que el segundo caracter por caracter ascii
/// utilizar para arbol derecha menor y izquierda mayor
bool StrMenor(String s1, String s2 )
{
int i=0;
    bool encontre = false;
    bool menor = false;
   while ((!encontre) && (s1[i]!='\0') && (s2[i]!='\0'))
        {
            if (s1[i]!=s2[i])
                {
                    encontre = true;

                    if (s1[i]<s2[i])
                    {
                      menor = true;
                    }

                }
                i++;
        }

            if ((!encontre) && (s2[i]!='\0'))
                {
                    menor = true;
                }
            return menor;
}
//utilizar en hash para buscar en secuencia
///streq que reciba dos String y devuelva TRUE si ambos String son iguales o FALSE en caso contrario.
bool StringComparar(String s1,String s2)
{// si son iguales
    int i=0;
    bool iguales = true;
    while (iguales && (s1[i]!='\0') && (s2[i]!='\0'))
    {

        if (s1[i]!=s2[i])
        {
            iguales = false;
        }
        i++;

    }
    if ((s1[i]!='\0') || (s2[i]!='\0'))
    {
        iguales = false;
    }
    return iguales;
}



   //retorna TRUE si es alfanumerico o FALSE si no lo es.
bool EsAlfaNumerico(String nombre)
      {

// hay que comparar cada caracter del String
bool es=true;
int i=0;
while(i<= StrLar(nombre)&& es==true)
	{
if ( (nombre[i]>=1&&nombre[i]<=47)||(nombre[i]>=123&&nombre[i]<=255)||(nombre[i]>=58&&nombre[i]<=64)||(nombre[i]>=91&&nombre[i]<=96))
        	{
        	  es=false;
        	}
else
    i++;

    }

    return es;
}






