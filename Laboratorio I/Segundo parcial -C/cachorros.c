#include "cachorros.h"



int cargarElementos(char* archivo, LinkedList* elementos)
{

    int valorRetornado=1;



    if(elementos!=NULL)
    {



        FILE* pFile= fopen(archivo, "r");


        if(pFile==NULL)
        {
            valorRetornado=0;

            printf("\nArchivo inexistente\n");
            return valorRetornado;

        }


        if(!parsearArchivoCSV(pFile,elementos))
        {

            valorRetornado=0;

        }


        fclose(pFile);


    }
    return valorRetornado;
}




int parsearArchivoCSV(FILE* pFile, LinkedList* elementos)
{
    eCachorro* aux=NULL;
    char buffer[5][40];

    int cant;
    int valorRetornado=0;
    int id_cachorro;
    char reservado[20];
    int dias;
    char raza[20];
    char nombre[20];
    char genero;

    if(pFile==NULL)
    {
        return valorRetornado;
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4],buffer[5] );

    while(!feof(pFile))
    {

        cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4],buffer[5] );



        if( cant == 6)
        {
            id_cachorro= atoi(buffer[0]);
            strcpy(nombre,buffer[1]);
            dias =atoi(buffer[2]);
            strcpy(raza,buffer[3]);
            strcpy(reservado,buffer[4]);
            genero=buffer[5][0];

            aux= nuevoelementoParametros(id_cachorro,nombre,dias,raza,reservado,genero);

            if(aux !=NULL)
            {


                ll_add(elementos, aux);

                valorRetornado=1;


            }
            else
            {



                valorRetornado=0;
                break;
            }


        }
        else
        {


            valorRetornado=0;

            break;

        }

    }

    return valorRetornado;
}


eCachorro* nuevoelemento()
{


    eCachorro* elemento = NULL;
    elemento= (eCachorro*) malloc(sizeof (eCachorro));

    if(elemento!=NULL)
    {


        elemento->ID_Cachorro=0;
        strcpy(elemento->nombre," ");
        elemento->dias=0;
        strcpy(elemento->raza," ");
        strcpy(elemento->reservado," ");
        elemento->genero=' ';


    }



    return elemento;
}



int setID_Cachorro(eCachorro* this,int id_cachorro)
{

    int todoOk=0;

    if(this!=NULL)
    {

        this->ID_Cachorro= id_cachorro;
        todoOk=1;
    }

    return todoOk;
}

int getId_Cachorro(eCachorro* this,int* id_cachorro)
{
    int todoOk=0;

    if(this!=NULL&&id_cachorro!=NULL)
    {

        *id_cachorro= this->ID_Cachorro;
        todoOk=1;
    }

    return todoOk;
}



int setNombre(eCachorro* this,char* nombre)
{

    int todoOk=0;

    if(this!=NULL)
    {

        strcpy(this->nombre, nombre);
        todoOk=1;
    }

    return todoOk;
}

int getNombre(eCachorro* this,char* nombre)
{
    int todoOk=0;

    if(this!=NULL&&nombre!=NULL)
    {

        strcpy(nombre,this->nombre);
        todoOk=1;
    }

    return todoOk;
}


int setDias(eCachorro* this,int edad)
{

    int todoOk=0;

    if(this!=NULL)
    {

        this->dias= edad;
        todoOk=1;
    }

    return todoOk;
}

int getDias(eCachorro* this,int* edad)
{
    int todoOk=0;

    if(this!=NULL&&edad!=NULL)
    {

        *edad= this->dias;
        todoOk=1;
    }

    return todoOk;
}

int setRaza(eCachorro* this,char* raza)
{

    int todoOk=0;

    if(this!=NULL)
    {

        strcpy(this->raza, raza);
        todoOk=1;
    }

    return todoOk;
}

int getRaza(eCachorro* this,char* raza)
{
    int todoOk=0;

    if(this!=NULL&&raza!=NULL)
    {

        strcpy(raza,this->raza);
        todoOk=1;
    }

    return todoOk;
}

int setReservado(eCachorro* this,char* reservado)
{

    int todoOk=0;

    if(this!=NULL)
    {

        strcpy(this->reservado, reservado);
        todoOk=1;
    }

    return todoOk;
}

int getReservado(eCachorro* this,char* reservado)
{
    int todoOk=0;

    if(this!=NULL&&reservado!=NULL)
    {

        strcpy(reservado,this->reservado);
        todoOk=1;
    }

    return todoOk;
}


int setGenero(eCachorro* this,char genero)
{

    int todoOk=0;

    if(this!=NULL)
    {

        this->genero= genero;
        todoOk=1;
    }

    return todoOk;
}

int getGenero(eCachorro* this,char* genero)
{
    int todoOk=0;

    if(this!=NULL&&genero!=NULL)
    {

        *genero= this->genero;
        todoOk=1;
    }

    return todoOk;
}

eCachorro* nuevoelementoParametros(int ID_Cachorro, char* nombre, int dias,char* raza, char* reservado, char genero)
{

    eCachorro* elemento = nuevoelemento();


    if(elemento==NULL||!setID_Cachorro(elemento,ID_Cachorro)||
            !setNombre(elemento,nombre)||!setDias(elemento,dias)
            ||!setRaza(elemento,raza)||!setReservado(elemento,reservado)||!setGenero(elemento,genero))
    {


        elemento=NULL;

    }

    return elemento;

}





int controller_saveAsText(char* path, LinkedList* pArrayList)
{

    int valorRetornado = 0;
    int cant;
    int tam= ll_len(pArrayList);
    FILE* f=fopen(path, "w");
    eCachorro* aux=NULL;

    int id;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[20];
    char genero;

    if(  f != NULL && path != NULL && tam > 0&& pArrayList!=NULL)
    {

        fprintf(f, "ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero\n");
        for(int i=0; i < tam; i++)
        {
            aux= ll_get(pArrayList,i);


            if(getId_Cachorro(aux,&id)&&getNombre(aux,nombre)&&getDias(aux,&dias)&&getRaza(aux,raza)&&
                    getReservado(aux,reservado)&&getGenero(aux,&genero))
            {

                cant=  fprintf(f,"%d,%s,%d,%s,%s,%c\n",id, nombre, dias,raza, reservado,genero);


            }
        }
        if (cant>0)
        {
            valorRetornado=1;
        }
    }

    fclose(f);
    return valorRetornado;
}

/*
eFecha* parsearFecha(char* fechaStr){

eFecha* fecha= (eFecha*)malloc(sizeof(fecha));
char buffer [3][5];
int dia;
int mes;
int anio;

  buffer[0][0]=fechaStr[0];
buffer[0][1]=fechaStr[1];
dia=atoi(buffer[0]);

 buffer[1][0]=fechaStr[3];
buffer[1][1]=fechaStr[4];
mes=atoi(buffer[1]);

 buffer[2][0]=fechaStr[6];
buffer[2][1]=fechaStr[7];
buffer[2][2]=fechaStr[8];
buffer[2][3]=fechaStr[9];
anio=atoi(buffer[2]);

fecha->dia=dia;
fecha->mes=mes;
fecha->anio=anio;


return fecha;
}

*/

int controller_List(LinkedList* elemento)
{
    system("cls");

    printf("*********Listar Cachorros**********\n\n");


    int valorRetornado=0;

    int id;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[3];
    char genero;
    eCachorro* aux=NULL;


    if(elemento!=NULL)
    {
        int tam = ll_len(elemento);

        for(int i=0; i < tam; i++)
        {
            aux = ll_get(elemento, i);

            if(aux!=NULL)
            {
                if(getId_Cachorro(aux,&id)&&getNombre(aux,nombre)&&getDias(aux,&dias)&&getRaza(aux,raza)&&
                        getReservado(aux,reservado)&&getGenero(aux,&genero))

                    printf("ID Cachorro:%d  Nombre:%s   Dias:%d  raza:%s  Reservado:%s  Genero:%c\n\n",id, nombre, dias,
                           raza, reservado,genero);
                // cachorros_toString(aux);

                valorRetornado=1;

            }

        }
    }

    else
    {

        printf("No hay llamados cargadas\n\n");

        valorRetornado=1;
    }

    return valorRetornado;
}


void cachorros_toString(eCachorro* elemento)
{

    printf("ID Cachorro:%d  Nombre:%s   Dias:%d  raza:%s  Reservado:%s  Genero:%c\n\n",elemento->ID_Cachorro, elemento->nombre, elemento->dias,
           elemento->raza, elemento->reservado,elemento->genero);

}

/*
void descProblema(int problema, char* desc){


switch (problema){

case 1:

    strcpy(desc,"No enciende la pc");

    break;

case 2:

    strcpy(desc,"No funciona mouse");

    break;
    case 3:

    strcpy(desc,"No funciona teclado");

    break;

    case 4:

    strcpy(desc,"No hay internet");

    break;
case 5:

    strcpy(desc,"No funciona telefono");

    break;
default:

    strcpy(desc,"ID de  problema incorrecto");

}



}



int esDeEsteTipo(eDominio* elemento, int id){

int retorno=0;

if(elemento->ID_Problema == id){

    retorno=1;

}

return retorno;
}


int solicitarTipoProblema(){

int numero;

printf("\n\n1.No enciende la pc\n");
printf("2.No funciona mouse\n");
printf("3.No funciona teclado\n");
printf("4.No hay internet\n");
printf("5.No funciona telefono\n");


printf("\nIngrese tipo de problema:");
scanf("%d",&numero);

while(numero<1||numero>5){

printf("\nError. Ingrese tipo de problema (1-5):");
scanf("%d",&numero);

}

return numero;

}



LinkedList* ll_map(LinkedList* this, int (*pFunc)(void*))
{


    eDominio* aux=NULL;
    LinkedList* nueva =ll_newLinkedList();


    if(pFunc!=NULL&& this!=NULL)
    {

        int tam=ll_len(this);

        for (int i=0; i<tam; i++)
        {

            aux= (eDominio*) ll_get(this,i);

            if(aux!=NULL&&pFunc(aux))
            {

                ll_add(nueva,aux);
            }
        }
    }

    return nueva;
}

*/



int esMayora44(eCachorro* elemento)
{

    int retorno=0;
    int dias;

    if(getDias(elemento,&dias))

{
    if( dias>44)
        {

            retorno=1;

        }
    }
    return retorno;



}


int noEsMacho(eCachorro* elemento)
{

    int retorno=0;
    char genero;

    if(getGenero(elemento,&genero))

{
    if( genero!='M')
        {

            retorno=1;

        }
    }
    return retorno;



}



int esCallejero(eCachorro* elemento){

int retorno=0;
    char* raza[20];

    if(getRaza(elemento,raza)){
    if( strcmp(raza,"Callejero")==0)
        {

            retorno=1;

        }
    }
    return retorno;


}

