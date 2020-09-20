#include "funAux.h"


int menu()
{

    int option;
    system("cls");
    printf("************Menu de Opciones************\n\n");
    printf("1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).  \n");
    printf("2-Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3-Alta de empleado\n");
    printf("4-Modificar datos de empleado\n");
    printf("5-Baja de empleado\n");
    printf("6-Listar empleados\n");
    printf("7-Ordenar empleados\n");
    printf("8-Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9-Guardar los datos de los empleados en el archivo data.bin (modo binario).\n\n");
    printf("10-Salir\n\n");


    option = getEnteroPositivo("Ingrese opcion: ");

    return option;
}

char confirmar (char* mensaje, int tam)
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

    int noEsSoloLetra;


    printf("%s", mensaje);
    fflush(stdin);
    gets(auxString);

    noEsSoloLetra = encontrarCaracterNoLetra(auxString);

    while (noEsSoloLetra|| strlen(auxString)>tam)
    {

        printf("\nError, este campo solo admite letras sin acentuar y un maximo de %d caracteres. Reingrese: ", tam-1);
        fflush(stdin);
        gets(auxString);
        noEsSoloLetra= encontrarCaracterNoLetra(auxString);
    }




    strcpy(string, auxString);


}


int encontrarCaracterNoLetra(char* string)
{

    int tam= strlen(string);

    int noHaySoloLetras=0;

    for (int i= 0; i<tam; i++)
    {

        if( !(string[i]>=65&&string[i]<=90) && !(string[i]>=97&&string[i]<=122) && !(string[i]==' ') )
        {

            noHaySoloLetras=1;
        }

    }
    return noHaySoloLetras;

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


int menuInformation()
{



    int option;

    system("cls");

    printf("*********Ordenar empleados**********\n\n");

    printf(" 1-Ordenar por id.\n");
    printf(" 2-Ordenar por nombre.\n");
    printf(" 3-Ordenar por horas trabajadas.\n");
    printf(" 4-Ordenar por salario.\n");
    printf(" 5-Salir.\n");
    option=getEnteroPositivo("Ingrese opcion: ");



    return option;
}


int getOptionOrder()
{

    int order;

    system("cls");

    printf("***Criterios de ordenamiento***\n\n");


    order=getEnteroPositivo("Elija 1 para ordenar ascendentemente o 0 para ordenar descendentemente (esta operacion puede tomar unos segundos): ");

    while(!(order==1||order==0))
    {
        printf("\nOpcion invalida. ");
        order=getEnteroPositivo("Elija 1 para ordenar ascendentemente o 0 para ordenar descendentemente (esta operacion puede tomar unos segundos): ");

    }
    return order;
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

