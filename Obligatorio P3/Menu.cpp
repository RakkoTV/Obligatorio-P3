#include<Menu.h>

void Menu1 (int &opcion)

{
printf("\n");
printf("**********************************************************************************\n");
printf("\n");
printf("1. Registrar los nombres de todas las ciudades que visita la empresa.\n");
printf("2. (Grafo ver si eso,) Dados los nombres de dos ciudades, agregar un nuevo tramo entre ellas. Dicho tramo podrá luego ser incluido en alguna de las líneas que la empresa posee. \n");
printf("3. (Grafo dfs)Dados los nombres de dos ciudades, saber si existe alguna secuencia de tramos que las una. Esta operación le servirá a la directiva de la empresa a la hora de idear recorridos para nuevas líneas. \n");
printf("4. abb Ingresar una nueva línea a la empresa, chequeando que no existiera previamente otra línea con el mismo código alfanumérico.\n");
printf("5. Listar los datos básicos de todas las líneas de la empresa (código, origen, destino y cantidad de paradas), ordenados por código alfanumérico de menor a mayor. \n");
printf("6. Agregar una nueva parada a su recorrido. Dado el codigo que identifica a una línea, Se debe chequear que efectivamente exista un tramo entre la nueva parada y la ultima parada registrada hasta el momento en la linea. \n");
printf("7. Listar todas las paradas, Dado el codigo que identifica a una linea, (número de parada y nombre de ciudad) de su recorrido.\n");
printf("8. Salir\n");
fflush(stdin);
printf("**********************************************************************************\n");
printf("Ingresen la opcion deseada:   ");
scanf("%d", &opcion);
}


void Menu2 (int &opcion2)
{
fflush(stdin);
printf("\n");
printf("**********************************************************************************\n");
printf("**********************************************************************************\n");
printf("\n");
printf("1.............\n");
printf("2. ........\n");
printf("3. ........\n");
printf("4. ........\n");
printf("5. ........\n");
printf("6. ........\n");
printf("7. ........\n");
printf("8. ........\n");
fflush(stdin);
printf("**********************************************************************************\n");
printf("Ingresen la opcion deseada:   ");
scanf("%d", &opcion2);
printf("\n\n");
fflush(stdin);
}
void Menu3 (int &opcion3)
{
fflush(stdin);
printf("\n");
printf("**********************************************************************************\n");
printf("**********************************************************************************\n");
printf("\n");
printf("1. .......\n");
printf("2. ........\n");
printf("3. ........\n");
printf("4. ........\n");
printf("5. ........\n");
printf("6. ........\n");
printf("7. ........\n");
printf("8. ........\n");
fflush(stdin);
printf("**********************************************************************************\n");
printf("Ingresen la opcion deseada:   ");
scanf("%d", &opcion3);
printf("\n\n");
fflush(stdin);
}
