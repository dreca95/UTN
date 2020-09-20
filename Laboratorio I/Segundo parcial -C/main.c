#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cachorros.h"
#include <string.h>
#include "funAux.h"

int main()
{
    char salir='n';


    LinkedList* cachorros= ll_newLinkedList();
    LinkedList* cachorrosMas44=ll_newLinkedList();
    LinkedList* cachorrosNoMachos=ll_newLinkedList();
    LinkedList* callejeros= ll_newLinkedList();

    do
    {
        switch( menu())
        {
        case 1:


            if(cargarElementos("cachorros.csv",cachorros))
            {


                printf("\ndatos cargados exitosamente.\n\n");




            }
            else
            {

                printf("\nNo se pudieron cargar los datos\n\n");

            }



            break;

        case 2:

            if(!ll_isEmpty(cachorros))
            {

                controller_List(cachorros);
            }

            else
            {


                printf("\nNo hay cachorros cargados\n\n");

            }


            break;

        case 3:

            if(!ll_isEmpty(cachorros))
            {
                cachorrosMas44= ll_filter(cachorros,esMayora44);

                if(!ll_isEmpty(cachorrosMas44))
                {

                    if(controller_saveAsText("cachorrosMas44.csv",cachorrosMas44))
                    {

                        printf("\nCachorros guardados en cachorrosMas44.csv\n");
                    }
                    else
                    {

                        printf("\nCachorros no guardados\n");
                    }
                }
                else
                {
                    printf("\nNo hay perros que no sean machos\n");
                }
            }
            else
            {


                printf("\nNo hay cachorros cargados\n\n");

            }

            break;
        case 4:

            if(!ll_isEmpty(cachorros))
            {
                cachorrosNoMachos= ll_filter(cachorros,noEsMacho);
                if(!ll_isEmpty(cachorrosNoMachos))
                {

                    if(controller_saveAsText("cachorrosNoMachos.csv",cachorrosNoMachos))
                    {

                        printf("\nCachorros guardados en cachorrosNoMachos.csv\n");
                    }
                    else
                    {

                        printf("\nCachorros no guardados\n");
                    }


                }
                else
                {

                    printf("\nNo hay perros que no sean machos\n");
                }

            }
            else
            {


                printf("\nNo hay cachorros cargados\n\n");

            }


            break;
        case 5:

            if(!ll_isEmpty(cachorros))
            {
                callejeros=ll_filter(cachorros,esCallejero);


                if(!ll_isEmpty(callejeros))
                {
                    controller_List(callejeros);
                }
                else
                {
                    printf("\nNo hay perros callejeros\n");
                }
            }

            else
            {


                printf("\nNo hay cachorros cargados\n\n");

            }



            break;

        case 6:
            ll_deleteLinkedList(cachorros);
             ll_deleteLinkedList(cachorrosNoMachos);
              ll_deleteLinkedList(cachorrosMas44);
               ll_deleteLinkedList(callejeros);
salir='s';
            break;
        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');
    return 0;
}
