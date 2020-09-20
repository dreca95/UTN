#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funAux.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/
//validar negativos

int main()
{
    char salir='n';
    int flag=0;


    LinkedList* listaEmpleados = ll_newLinkedList();


    do
    {
        switch( menu())
        {
        case 1:

            if(!flag)
            {
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    ;

                    printf("\nEmpleados cargados desde data.csv exitosamente.\n\n");



                    flag=1;
                }
                else
                {

                    printf("\nNo se pudieron cargar los datos de los empleados desde data.csv\n\n");

                }

            }
            else
            {


                printf("\nNo puede cargarse porque ya se dio de alta previamente.\n\n");

            }


            break;

        case 2:

            if(!flag)
            {

                if(controller_loadFromBinary("data.bin",listaEmpleados))
                {

                    printf("\nEmpleados cargados desde data.bin exitosamente.\n\n");

                    flag=1;
                }
                else
                {

                    printf("\nNo puede cargarse porque no se encuentra el archivo data.bin\n\n");

                }

            }
            else
            {


                printf("\nNo puede cargarse porque ya se dio de alta previamente.\n\n");

            }


            break;

        case 3:

            if(controller_addEmployee(listaEmpleados))
            {
                flag=1;

                printf("\n\nEl empleado fue dado de alta.\n\n");

            }
            else
            {


                printf("\n\nEl empleado no pudo ser dado de alta.\n\n");
            }
            break;

        case 4:


            if(controller_editEmployee(listaEmpleados))
            {


                printf("\n\nEl empleado fue modificado.\n\n");

            }
            else
            {


                printf("\n\nNo se modificó ningun empleado\n\n");

            }

            break;

        case 5:

            if(controller_removeEmployee(listaEmpleados))
            {


                printf("\n\nEl empleado fue dado de baja.\n\n");

            }
            else
            {


                printf("\n\nNo se dio de baja a ningun empleado\n\n");

            }


            break;

        case 6:


            if(!controller_ListEmployee(listaEmpleados))
            {

                printf("\nLos empleados cargados no pueden mostrarse\n\n");

            }


            break;

        case 7:

            if(!controller_sortEmployee(listaEmpleados))

            {

                printf("\nLos empleados no fueron ordenados\n");

            }

            break;

        case 8:


            if(controller_saveAsText("data.csv",listaEmpleados))
            {

                printf("\nLos empleados fueron guardados en data.csv exitosamente\n");

            }
            else
            {

                printf("\nLos empleados no fueron guardados en data.csv\n");

            }

            break;

        case 9:

            if(controller_saveAsBinary("data.bin",listaEmpleados))
            {

                printf("\nLos empleados fueron guardados en data.bin exitosamente\n");

            }
            else
            {

                printf("\nLos empleados no fueron guardados en data.bin\n");

            }


            break;

        case 10:
            salir = confirmar("Confirma salir? s/n: ",25);

            if(salir=='s'){

               ll_deleteLinkedList(listaEmpleados);

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











