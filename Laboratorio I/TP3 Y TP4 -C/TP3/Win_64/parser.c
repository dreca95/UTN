#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "Employee.h"



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* aux=NULL;
    char buffer[4][40];
    int cant;
    int valorRetornado=1;

    if(pFile==NULL)
    {



     valorRetornado=0;

    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3] );


    while(!feof(pFile))
    {

        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);



        if( cant == 4)
        {
            aux=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

            if(aux !=NULL)
            {


                ll_add(pArrayListEmployee, aux);

            }


        }
        else
        {

            break;

        }

    }

    return valorRetornado;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
int valorRetornado=1;
    Employee* aux=NULL;
    int cant;


    if( pFile == NULL)
    {
        valorRetornado= 0;
    }

    while( !feof(pFile))
    {
        aux = employee_new();

        if( aux != NULL)
        {
            cant = fread( aux,  sizeof(Employee), 1, pFile);

            if( cant == 1)
            {

                ll_add(pArrayListEmployee, aux);
            }
        }
        else
        {
            valorRetornado=0;
        }
    }


    return valorRetornado;

}
