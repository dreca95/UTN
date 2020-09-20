#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "App.h"
#include "funAux.h"

int main()
{
    char salir='n';



    LinkedList* apps = ll_newLinkedList();
    LinkedList* favoritas=ll_newLinkedList();
    LinkedList* cincoE=ll_newLinkedList();




    do
    {
        switch( menu())
        {
        case 1:


            if(controller_loadFromText("datos.csv",apps))
            {


                printf("\nProceso de carga de datos finalizado\n\n");



            }
            else
            {

                printf("\nNo se pudieron cargar las apps desde datos.csv\n\n");

            }



            break;


        case 2:

            if(controller_addApp(apps))
            {


                printf("\n\nLa app fue dada de alta.\n\n");

            }
            else
            {


                printf("\n\nLa app no pudo ser dada de alta.\n\n");
            }
            break;



        case 3:

            if(!ll_isEmpty(apps))
            {
                if(controller_removeApp(apps))
                {


                    printf("\n\nLa app fue dada de baja.\n\n");

                }
                else
                {


                    printf("\n\nNo se dio de baja a ninguna app\n\n");

                }

            }
            else
            {
                printf("\nNo hay apps cargadas\n\n");
            }
            break;

        case 4:

            if(!ll_clear(apps))
            {

                printf("\nLista vaciada\n\n");

            }
            else
            {

                printf("\nNo hay eleemntos para borrar\n\n");

            }



            break;

        case 5:
            if(!ll_isEmpty(apps))
            {

                controller_sortAppCantidadDesc(apps);
                if(!controller_ListApp(apps))
                {

                    printf("\nLas apps cargadas no pueden mostrarse\n\n");

                }


            }
            else
            {
                printf("\nNo hay apps cargadas\n\n");
            }

            break;

        case 6:
            if(!ll_isEmpty(apps))
            {


                if( controller_loadFromTextAppFav("favoritas.csv",favoritas))
                {

                    printf("\n\nApps favoritas cargadas\n");

                }
                else
                {
                    printf("\n\nApps favoritas no pudieron cargarse\n");
                }

            }
            else
            {
                printf("\nDebe cargar las apps del archivo datos.csv antes de interactuar con favoritos.\n");
            }

            break;

        case 7:



            if(!ll_isEmpty(apps)&&!ll_isEmpty(favoritas))
            {
                controller_ListAppFav(favoritas);

                controller_addAppFav(apps,favoritas);
            }
            else
            {
                printf("\nNo hay apps cargadas.Debe cargar algun archivo o dar de alta alguna app, y cargar el archivo favoritas.csv antes de ingresar a favoritos.\n\n");
            }

            break;
        case 8:
            if(!ll_isEmpty(apps))
            {

                if(controller_saveAsText("lista.csv",apps))
                {

                    printf("\nLas apps fueron guardadas en lista.csv exitosamente\n");

                }
                else
                {

                    printf("\nLas apps no fueron guardadas en lista.csv\n");

                }
            }
            else
            {
                printf("\nNo hay apps cargadas\n");
            }
            break;
        case 9:
            if(!ll_isEmpty(apps))
            {
                if(controller_saveAsTextAppFav("favoritos.csv",favoritas))
                {



                    printf("\nLas apps fueron guardadas en favoritos.csv exitosamente\n");

                }
                else
                {

                    printf("\nLas apps no fueron guardadas en favoritos.csv\n");

                }

            }
            else
            {
                printf("\nNo hay apps cargadas\n");
            }
            break;

        case 10:


            if(!ll_isEmpty(apps)&&!ll_isEmpty(favoritas))
            {
                cincoE=aplicacionesCincoEstrellas(favoritas);


                if(controller_saveAsTextAppFav("cincoEstrellas.csv",cincoE))
                {

                    printf("\nLas apps fueron guardadas en cincoEstrellas.csv exitosamente\n");

                }
                else
                {

                    printf("\nLas apps no fueron guardadas en cincoEstrellas.csv\n");

                }

            }
            else
            {
                printf("\nNo hay apps cargadas. Deebe cargar apps y favoritas.\n");
            }
            break;




        case 11:
            salir = confirmar("Confirma salir? s/n: ");

            if(salir=='s')
            {

                ll_deleteLinkedList(apps);

            }

            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');
    return 0;
}
