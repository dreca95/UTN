#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "App.h"
#include "parser.h"



int controller_loadFromText(char* path, LinkedList* pApp)
{
    int valorRetornado=1;
    FILE* f= fopen(path, "r");

    if(f==NULL)
    {

        valorRetornado= 0;
        return valorRetornado;

    }

    if(!parser_AppFromText(f,pApp))
    {


        valorRetornado= 0;

    }

    fclose(f);
    return valorRetornado;
}



int controller_addApp(LinkedList* pApp)
{
    system("cls");

    printf("*********Alta Aplicacion**********\n\n");

    char nombre[20];
    int anio;
    int cantidadUsers;
    App* aux=app_new();;
    int valorRetornado=0;
    int esta;



    getString(nombre,20,"\nIngrese nombre: ");

    convertirNombrePropio(nombre);

    esta=estaNombreEnListaApp(nombre,pApp);

    if(esta==-1)
    {




        cantidadUsers=getEnteroPositivo("\nIngrese cantidad de usuarios: ");
        anio=getEnteroPositivo("\nIngrese anio de creacion: ");
        anio=validarAnio(anio);


        if(aux!=NULL)
        {

            app_setNombre(aux, nombre);
            app_setAnio(aux, anio);
            app_setCantidad(aux,cantidadUsers);


        }






        if(aux!=NULL)
        {


            ll_add(pApp,aux);

            valorRetornado=1;

        }

    }
    else
    {

        printf("\n\nEse nombre se encuentra en la lista\n");


        aux=(App*)ll_get(pApp,esta);

        printf("\n");
        printf("Cantidad de Users:%d   -  Nombre de App:%s   -   Anio de registro:%d\n\n", aux->cantidadUsers, aux->nombre, aux->anio);


    }



    return valorRetornado;
}




int controller_removeApp(LinkedList* pApp)
{


    int valorRetornado=0;
    App* aux=NULL;

    char nombreIngresado[20];
    int indice=-1;


    system("cls");

    printf("*********Baja App**********\n\n");


    controller_ListApp(pApp);

    getString(nombreIngresado,20,"\n\nIngrese el nombre de la app a dar de baja: ");
    convertirNombrePropio(nombreIngresado);


    if(pApp!=NULL)
    {

        int tam= ll_len(pApp);

        for(int i = 0; i < tam; i++)
        {
            aux = (App*)ll_get(pApp, i);
            if(aux != NULL && strcmp(aux->nombre,nombreIngresado)==0)
            {
                indice=i;
                break;
            }
        }

        if(indice>-1)
        {



            aux=(App*)ll_pop(pApp,indice);

            printf("\nApp dada de baja:\n");
            printf("Cantidad de Users:%d   -  Nombre de App:%s   -   Anio de registro:%d\n\n", aux->cantidadUsers, aux->nombre, aux->anio);
            valorRetornado=1;



        }


        else
        {


            printf("\nEl nombre ingresado no existe en la lista\n");

        }

    }

    return valorRetornado;
}

int controller_ListApp(LinkedList* pApp)
{
    system("cls");

    printf("*********Listar Apps por popularidad**********\n\n");


    int valorRetornado=0;
    char nombre[20];
    int anio;
    int cantidadUsers;
    App* aux=NULL;

    if(pApp!=NULL)
    {
        int tam = ll_len(pApp);

        for(int i=0; i < tam; i++)
        {
            aux = ll_get(pApp, i);

            if(aux!=NULL)
            {
                if( app_getCantidad(aux, &cantidadUsers)  &&
                        app_getNombre(aux, nombre) &&
                        app_getAnio(aux, &anio) )
                {

                    printf("Cantidad de users:%d  - Nombre de la app:%s  - Anio de registro:%d\n\n", cantidadUsers, nombre,anio);

                    valorRetornado=1;

                }

            }
        }
    }
    else
    {

        printf("No hay apps cargadas\n\n");

        valorRetornado=1;
    }

    return valorRetornado;
}


int controller_sortAppCantidadDesc(LinkedList* pApp)
{
    int valorRetornado = 0;



    if (!ll_sort(pApp,ordenarPorCantidad,0))
    {

        valorRetornado=1;

    }




    return valorRetornado;


}


int controller_saveAsText(char* path, LinkedList* pApp)
{

    int valorRetornado = 0;
    int cant;
    FILE* f=fopen(path, "w");
    App* aux=NULL;

    if(  f != NULL && path != NULL&& pApp!=NULL)
    {
        int tam= ll_len(pApp);
        fprintf(f, "cantidadUsers,nombre,anio\n");
        for(int i=0; i < tam; i++)
        {
            aux = ll_get(pApp,i);
            cant= fprintf(f, "%d,%s,%d\n", aux->cantidadUsers, aux->nombre, aux->anio);
        }
        if (cant>0)
        {
            valorRetornado=1;
        }
    }

    fclose(f);
    return valorRetornado;
}



int controller_ListAppFav(LinkedList* pApp)
{
    system("cls");
    AppFavorita* aux=NULL;
    App* auxi=NULL;
    int valorRetornado=0;
    int estrellas;
    char nombre[20];
    int anio;
    int cantidadUsers;
    printf("*********Listar Apps Favoritas**********\n\n");






    if(pApp!=NULL)
    {
        int tam = ll_len(pApp);

        for(int i=0; i < tam; i++)
        {
            aux = (AppFavorita*) ll_get(pApp, i);



            if(aux!=NULL)
            {

                if( appFavorita_getAplicacion(aux,&auxi) &&appFavorita_getEstrellas(aux,&estrellas) )
                {

                    if(app_getAnio(auxi,&anio)&&app_getNombre(auxi,nombre)&&app_getCantidad(auxi,&cantidadUsers))
                    {

                        printf(" Nombre de la app:%s  -  Cantidad de users:%d  - Anio de registro:%d  - Estrellas:%d\n\n",nombre,cantidadUsers,anio,estrellas);

                        valorRetornado=1;
                    }

                }

            }
        }
    }
    else
    {

        printf("No hay apps favoritas cargadas\n\n");

        valorRetornado=1;
    }

    return valorRetornado;

    system("pause");
}




int controller_loadFromTextAppFav(char* path, LinkedList* pApp)
{
    int valorRetornado=0;
    FILE* f= fopen(path, "r");

    if(f==NULL)
    {

        return valorRetornado;

    }

    if(parser_AppFavFromText(f,pApp))
    {

        valorRetornado= 1;

    }

    fclose(f);
    return valorRetornado;
}




int controller_addAppFav(LinkedList* pApp,LinkedList* favoritas)
{
    int retorno=0;
    char confirmacion;
    int estrellas;
    char nombre[20];
    App* aux=NULL;//Buscar app en la lista para agregar a favoritas
    AppFavorita* auxi=NULL;//Buscar indice en donde insertarla
    AppFavorita* appFav= appFav_new();  //Nueva app fvaorita
    int tam;//Buscar app en la lista para agregar a favoritas
    int tam2;//Buscar indice en donde insertarla
    int indice=-1;//Buscar app en la lista para agregar a favoritas
    int index=-1;//Buscar indice en donde insertarla
    confirmacion=confirmar("\n¿Desea agregar una app a la lista de favoritos? s/n");
    int esta;

    if(confirmacion=='s')
    {


        controller_ListApp(pApp);

        getString(nombre,20,"\n\nIngrese el nombre de la aplicacion quiere agregar a favoritas: ");
        convertirNombrePropio(nombre);

        esta=estaNombreEnListaAppFav(nombre,favoritas);


        if(esta==-1)
        {

            if(pApp!=NULL&&favoritas!=NULL&&appFav!=NULL)
            {

                tam = ll_len(pApp);

                for(int i = 0; i < tam; i++)
                {
                    aux = (App*)ll_get(pApp, i);
                    if(aux != NULL && strcmp(aux->nombre,nombre)==0)
                    {
                        indice=i;
                        break;
                    }
                }

                if(indice>-1)
                {

                    printf("\n");
                    printf("Cantidad de Users:%d   -  Nombre de App:%s   -   Anio de registro:%d\n\n", aux->cantidadUsers, aux->nombre, aux->anio);



                    estrellas= getEnteroPositivo("\n\nIngrese cantidad de estrellas (1 a 5): ");


                    while(estrellas<1||estrellas>5)
                    {

                        estrellas= getEnteroPositivo("\n\nError.Ingrese cantidad de estrellas (1 a 5): ");

                    }






                    appFavorita_setAplicacion(appFav,aux);
                    appFavorita_setEstrellas(appFav,estrellas);




                    if(appFav!=NULL)
                    {



                        tam2=ll_len(favoritas);


                        for(int i=0; i<tam2; i++)
                        {


                            auxi= (AppFavorita*)ll_get(favoritas, i);
                            if(auxi != NULL && auxi->estrellas==estrellas)
                            {
                                index=i;
                                break;
                            }

                        }


                        if(!ll_push(favoritas,index,appFav))
                        {

                            retorno=1;
                            printf("\n\nApp agregada a favoritas exitosamente.\n");





                        }
                        else
                        {
                            printf("\n\nNo pudo agregarse a favoritas.\n");
                        }

                    }

                    else
                    {
                        printf("\n\nNo pudo agregarse a favoritas.\n");
                    }

                }


                else
                {


                    printf("\nEl nombre ingresado no existe en la lista\n");

                }


            }


        }
        else
        {
            printf("\n\nEsa aplicacion ya se encuentra en la lista de favoritos\n");
        }


    }

    return retorno;


}


int controller_saveAsTextAppFav(char* path, LinkedList* pApp)
{

    int valorRetornado = 0;
    int cant=0;
    FILE* f=fopen(path, "w");
    AppFavorita* aux=NULL;
    App* auxi=NULL;
    int anio;
    int estrellas;
    int cantidadUsers;
    char nombre[20];

    if(  f != NULL && path != NULL&& pApp!=NULL)
    {
        int tam= ll_len(pApp);
        fprintf(f, "nombre,cantidadUsers,anio,estrellas\n");
        for(int i=0; i < tam; i++)
        {
            aux =(AppFavorita*) ll_get(pApp,i);

            if( appFavorita_getAplicacion(aux,&auxi) &&appFavorita_getEstrellas(aux,&estrellas) )
            {

                if(app_getAnio(auxi,&anio)&&app_getNombre(auxi,nombre)&&app_getCantidad(auxi,&cantidadUsers))
                {
                    cant= fprintf(f, "%d,%s,%d,%d\n", auxi->cantidadUsers, auxi->nombre, auxi->anio,aux->estrellas);
                }
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
