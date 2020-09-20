#include "funAux.h"


int menu()
{

    int option;
    system("cls");
    printf("************Menu de Opciones************\n\n");
    printf("1-Cargar archivo de apps (datos.csv) \n");
    printf("2-Alta de app\n");
    printf("3-Baja de app\n");
    printf("4-Resetear lista de apps\n");
    printf("5-Listar apps\n");
    printf("6-Cargar archivo de favoritas (favoritas.csv)\n");
    printf("7-Listar y agregar favoritas\n");
    printf("8-Guardar lista de apps en lista.csv\n");
    printf("9-Guardar favoritas en favoritos.csv\n");
    printf("10-Guardar favoritas con cinco estrellas en cincoEstrellas.csv\n\n");
    printf("11-Salir\n\n");


    option = getEnteroPositivo("Ingrese opcion: ");

    return option;
}

char confirmar (char* mensaje)
{
    printf("%s",mensaje);
    char confirmacion;
    fflush(stdin);
    confirmacion = getchar();
    confirmacion= tolower(confirmacion);


    while(!(confirmacion=='s'||confirmacion=='n'))
    {

        printf("Ingrese opcion valida. %s\n",mensaje);
        fflush(stdin);

        confirmacion = getchar();
        confirmacion= tolower(confirmacion);
    }

    return confirmacion;
}


void getString(char* string, int tam, char* mensaje)
{

    char auxString[100];




    printf("%s", mensaje);
    fflush(stdin);
    gets(auxString);


    while (strlen(auxString)>tam)
    {

        printf("\nError, este campo solo admite  un maximo de %d caracteres. Reingrese: ", tam-1);
        fflush(stdin);
        gets(auxString);

    }




    strcpy(string, auxString);


}





void convertirNombrePropio(char* string)
{

    char aux[100];
    int i=0;

    strcpy(aux,string);

    strlwr(aux);

    aux[0]=toupper(aux[0]);

    while(aux[i] != '\0')
    {

        if(aux[i]== ' ')
        {
            aux[i+1]= toupper(aux[i+1]);
        }
        i++;
    }

    strcpy(string, aux);
}







int getEnteroPositivo(char* mensaje)
{
    char numeroS [100];
    int numero;
    int noEsSoloNumero;

    printf("%s", mensaje);
    fflush(stdin);
    gets(numeroS);

    noEsSoloNumero=encontrarCaracterNoNumero(numeroS);

    while (noEsSoloNumero)
    {

        printf("\nError, este campo solo admite numeros positivos. Reingrese: ");
        fflush(stdin);
        gets(numeroS);
        noEsSoloNumero= encontrarCaracterNoNumero(numeroS);
    }

    numero = atoi(numeroS);

    return numero;
}


int encontrarCaracterNoNumero(char* string)
{

    int noHaySoloNumeros=0;

    int tam= strlen(string);


    for (int i= 0; i<tam; i++)
    {

        if( !(string[i]>=48&&string[i]<=57))
        {

            noHaySoloNumeros=1;
        }

    }
    return noHaySoloNumeros;

}

int validarAnio (int anio)
{


    while (anio<2000||anio>2019)
    {

        anio= getEnteroPositivo("\n\nError. Ingrese un anio entre 2000 y 2019: ");
    }

    return anio;
}


