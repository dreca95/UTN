
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "App.h"



App* app_new()
{

    App* aplicacion = (App*) malloc(sizeof (App));

    if(aplicacion!=NULL)
    {

        aplicacion->cantidadUsers=0;
        strcpy(aplicacion->nombre, " ");
        aplicacion->anio=0;

    }

    return aplicacion;

}


AppFavorita* appFav_new()
{

    AppFavorita* app = (AppFavorita*) malloc(sizeof (AppFavorita));


    if(app!=NULL)
    {

        app->aplicacion=app_new();
        app->estrellas=0;

    }

    return app;

}




int app_setCantidad(App* this,int cantidad)
{

    int todoOk=0;

    if(this!=NULL)
    {

        this->cantidadUsers=cantidad;
        todoOk=1;
    }

    return todoOk;
}


int app_getCantidad(App* this,int* cantidad)
{

    int todoOk=0;

    if(this !=NULL && cantidad!=NULL)
    {

        *cantidad= this->cantidadUsers;
        todoOk=1;
    }


    return todoOk;
}


int app_setNombre(App* this,char* nombre)
{

    int todoOk=0;

    if(this!=NULL && nombre!=NULL)
    {

        strcpy(this->nombre,nombre);
        todoOk=1;
    }

    return todoOk;
}

int app_getNombre(App* this,char* nombre)
{
    int todoOk=0;

    if(this!=NULL&&nombre!=NULL)
    {

        strcpy(nombre, this->nombre);
        todoOk=1;
    }

    return todoOk;

}

int app_setAnio(App* this,int anio)
{

    int todoOk=0;

    if( this!=NULL)
    {

        this->anio= anio;
        todoOk=1;
    }

    return todoOk;
}

int app_getAnio(App* this,int* anio)
{
    int todoOk=0;

    if(this!=NULL&& anio!=NULL)
    {

        *anio= this->anio;
        todoOk=1;
    }
    return todoOk;
}


int appFavorita_setEstrellas(AppFavorita* this,int estrellas)
{

    int todoOk=0;

    if( this!=NULL)
    {

        this->estrellas=estrellas;
        todoOk=1;
    }

    return todoOk;
}


int appFavorita_getEstrellas(AppFavorita* this,int* estrellas)
{
    int todoOk=0;

    if(this!=NULL&& estrellas!=NULL)
    {

        *estrellas= this->estrellas;
        todoOk=1;
    }
    return todoOk;
}


int appFavorita_setAplicacion(AppFavorita* this, App* aplicacion)
{


    int todoOk=0;

    if( this!=NULL&&aplicacion!=NULL)
    {

        this->aplicacion=aplicacion;
        todoOk=1;
    }

    return todoOk;


}



int appFavorita_getAplicacion(AppFavorita* this, App** aplicacion)
{
    int todoOk=0;

    if(this!=NULL&& aplicacion!=NULL)
    {

        *aplicacion= this->aplicacion;
        todoOk=1;
    }
    return todoOk;
}

App* app_newParametros(int cantidad, char* nombre, int anio)
{

    App* aplicacion = app_new();


    if(aplicacion==NULL||!app_setCantidad(aplicacion,cantidad)||
            !app_setNombre(aplicacion,nombre)||
            !app_setAnio(aplicacion,anio))
    {


        aplicacion=NULL;

    }

    return aplicacion;

}

AppFavorita* appFavorita_newParametros(App* aplicacion, int estrellas)
{

    AppFavorita* appFav = appFav_new();


    if(aplicacion==NULL||appFav==NULL||!appFavorita_setAplicacion(appFav,aplicacion)||!appFavorita_setEstrellas(appFav,estrellas))
    {


        appFav=NULL;

    }




    return appFav;

}




void app_delete(App* this)
{


    if(this != NULL)
    {
        free(this);

    }


}








int ordenarPorCantidad(void* aplicacionUno,void* aplicacionDos)
{

    int cantAppUno=0;
    int cantAppDos=0;
    int valorRetornado=0;

    app_getCantidad((App*)aplicacionUno,&cantAppUno);
    app_getCantidad((App*)aplicacionDos,&cantAppDos);

    if(cantAppUno>cantAppDos)
    {
        valorRetornado = 1;


    }
    else if(cantAppUno<cantAppDos)
    {
        valorRetornado = -1;
    }
    return valorRetornado;
}


int ordenarPorAntiguedad(void* aplicacionUno,void* aplicacionDos)
{

    int anioAppUno=0;
    int anioAppDos=0;
    int valorRetornado=0;

    app_getAnio((App*)aplicacionUno,&anioAppUno);
    app_getAnio((App*)aplicacionDos,&anioAppDos);

    if(anioAppUno>anioAppDos)
    {
        valorRetornado = 1;


    }
    else if(anioAppUno<anioAppDos)
    {
        valorRetornado = -1;
    }


    return valorRetornado;
}








int estaNombreEnListaApp (char* nombre, LinkedList* pApp)
{

    int retorno=-1;
    int tam;
    App* aplicacion=NULL;


    if(pApp!=NULL)
    {

        tam=ll_len(pApp);



        for(int i=0; i<tam; i++)
        {


            aplicacion=(App*)ll_get(pApp,i);

            if(strcmp(aplicacion->nombre,nombre)==0)
            {


                retorno=i;
                break;

            }
        }



    }

    return retorno;

}

int estaNombreEnListaAppFav (char* nombre, LinkedList* pApp)
{

    int retorno=-1;
    int tam;
    AppFavorita* aplicacion=NULL;
    App* aux=NULL;

    if(pApp!=NULL)
    {

        tam=ll_len(pApp);



        for(int i=0; i<tam; i++)
        {


            aplicacion=(AppFavorita*)ll_get(pApp,i);
            if(aplicacion!=NULL)
            {

                appFavorita_getAplicacion(aplicacion,&aux);
                {

                    if(aux!=NULL)
                    {

                        if(strcmp(aux->nombre,nombre)==0)
                        {


                            retorno=i;
                            break;
                        }
                    }
                }
            }
        }

    }

    return retorno;

}


LinkedList* aplicacionesCincoEstrellas(LinkedList* appFav)
{

    LinkedList* appCincoE=ll_newLinkedList();
    int tam;
    int contador=0;
    AppFavorita* aux=NULL;
    int estrellas;

    if(appFav!=NULL)
    {

        tam=ll_len(appFav);


        for(int i=0; i<tam; i++)
        {

            aux=(AppFavorita*)ll_get(appFav,i);

            if(aux!=NULL)
            {

                if(appFavorita_getEstrellas(aux,&estrellas))
                {

                    if(estrellas!=5)
                    {

                        contador++;

                    }

                }


            }

        }


appCincoE= ll_subList(appFav,contador,tam);

    }

    return appCincoE;

}


