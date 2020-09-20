#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "App.h"



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_AppFromText(FILE* pFile, LinkedList* pApp)
{
    App* aux=NULL;
    char buffer[4][40];
    int cant;
    int valorRetornado=1;
    int cantidadUsers;
    char nombre[20];
    int anio;

    if(pFile==NULL)
    {



        valorRetornado=0;

    }
    fscanf(pFile, "%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);

    while(!feof(pFile))
    {

        cant = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);



        if( cant == 3)
        {

            cantidadUsers= atoi(buffer[0]);
            anio =atoi (buffer[2]);
            strcpy(nombre,buffer[1]);
            aux=app_newParametros(cantidadUsers,nombre,anio);

            if(aux !=NULL)
            {

                if(estaNombreEnListaApp(aux->nombre,pApp)==-1)
                {


                    ll_add(pApp, aux);

                }
                else
                {


                    if( app_getCantidad(aux, &cantidadUsers)  &&
                            app_getNombre(aux, nombre) &&
                            app_getAnio(aux, &anio) )
                    {

                        printf("El elemento Cantidad de users:%d  - Nombre de la app:%s  - Anio de registro:%d ya se encuentra cargado en la lista\n\n", cantidadUsers, nombre,anio);



                    }

                }


            }
            else
            {

                break;

            }

        }
    }
    return valorRetornado;
}



int parser_AppFavFromText(FILE* pFile, LinkedList* pApp)
{
    App* aux=NULL;
    AppFavorita* auxi=NULL;
    char buffer[4][40];
    int cant;
    int valorRetornado=0;
    int cantidadUsers;
    char nombre[20];
    int anio;
    int estrellas;

    if(pFile==NULL)
    {





    }
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3]);

    while(!feof(pFile))
    {

        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3]);



        if( cant == 4)
        {

            cantidadUsers= atoi(buffer[0]);
            anio =atoi (buffer[2]);
            strcpy(nombre,buffer[1]);
            estrellas= atoi(buffer[3]);

            aux=app_newParametros(cantidadUsers,nombre,anio);

            if(aux !=NULL)
            {

                auxi=appFavorita_newParametros(aux,estrellas);

                if(auxi!=NULL)
                {

                    if(estaNombreEnListaAppFav(aux->nombre,pApp)==-1)
                    {
                        ll_add(pApp, auxi);
valorRetornado=1;
                    }
                    else
                    {
                        if( app_getCantidad(aux, &cantidadUsers)  &&
                                app_getNombre(aux, nombre) &&
                                app_getAnio(aux, &anio) )
                        {

                            printf("El elemento Cantidad de users:%d  - Nombre de la app:%s  - Anio de registro:%d -Estrellas: %d ya se encuentra cargado en la lista\n\n", cantidadUsers, nombre,anio,estrellas);



                        }




                    }


                }
                else
                {


                    break;

                }

            }
        }
    }
    return valorRetornado;
}






