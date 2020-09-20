#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Employee.h"
#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
int valorRetornado=1;
    FILE* f= fopen(path, "r");

    if(f==NULL)
    {

        valorRetornado= 0;
        return valorRetornado;

    }

    if(!parser_EmployeeFromText(f,pArrayListEmployee))
    {


       valorRetornado= 0;

    }

    fclose(f);
return valorRetornado;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f= fopen(path, "rb");

int valorRetornado=1;

    if(f==NULL)
    {
        valorRetornado=0;

        return valorRetornado;

    }

    if(!parser_EmployeeFromBinary(f,pArrayListEmployee))
    {



        valorRetornado=0;


    }

    fclose(f);



    return valorRetornado;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");

    printf("*********Alta Empleado**********\n\n");

    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    int id= getLastId(pArrayListEmployee);

    Employee* aux=employee_new();;
    int valorRetornado=0;



    getString(nombre,20,"\nIngrese nombre: ");

    convertirNombrePropio(nombre);
    horasTrabajadas=getEnteroPositivo("\nIngrese horas trabajadas: ");
    sueldo=getEnteroPositivo("\nIngrese sueldo: ");



    if(aux!=NULL)
    {

        employee_setNombre(aux, nombre);
        employee_setHorasTrabajadas(aux, horasTrabajadas);
        employee_setSueldo(aux,sueldo);
        employee_setId(aux,id+1);

    }



    if(aux!=NULL)
    {


        ll_add(pArrayListEmployee,aux);

        valorRetornado=1;

    }





    return valorRetornado;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int idIngresado;
    int tam= ll_len(pArrayListEmployee);
    char nombre[20];
    int sueldo;
    int horasTrabajadas;
    int valorRetornado=0;
    Employee* aux=NULL;

    system("cls");

    printf("*********Modificar Empleado**********\n\n");


    idIngresado = getEnteroPositivo("\nIngrese el id del empleado a modificar: ");

    if(idIngresado<=tam)
    {

        if(pArrayListEmployee!=NULL)
        {


            for(int i = 0; i < tam; i++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee, i);
                if(aux != NULL && aux->id == idIngresado)
                {
                    break;
                }
            }

            printf("Id          Nombre       Horas trabajadas           Sueldo\n");
            printf("%d   %10s               %d                  %d \n\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

            getString(nombre,20,"\nIngrese nuevo nombre: ");
            convertirNombrePropio(nombre);
            horasTrabajadas=getEnteroPositivo("\nIngrese nueva cantidad de horas trabajadas: ");
            sueldo=getEnteroPositivo("\nIngrese nuevo sueldo: ");


            employee_setNombre(aux, nombre);
            employee_setHorasTrabajadas(aux, horasTrabajadas);
            employee_setSueldo(aux,sueldo);

            valorRetornado=1;


        }


    }
    else
    {


        printf("\nEl id ingresado no existe\n");

    }



    return valorRetornado;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    int idIngresado;
    int tam= ll_len(pArrayListEmployee);
    int valorRetornado=0;
    Employee* aux=NULL;
    int id=0;
    char confirmacion='n';

    system("cls");

    printf("*********Baja Empleado**********\n\n");


    idIngresado = getEnteroPositivo("\n\nIngrese el id del empleado a dar de baja: ");

    if(idIngresado<=tam)
    {

        if(pArrayListEmployee!=NULL)
        {


            for(int i = 0; i < tam; i++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee, i);
                if(aux != NULL && aux->id == idIngresado)
                {
                    id=i;
                    break;
                }
            }

            printf("\n");

            printf("Id          Nombre       Horas trabajadas           Sueldo\n");
            printf("%d   %10s               %d                  %d \n\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);


            confirmacion = confirmar("\n\n¿Desea dar de baja al empleado?: ",20);

            if(confirmacion=='s')
            {

                employee_delete(aux);

                ll_remove(pArrayListEmployee,id);




                valorRetornado=1;

            }

        }
    }
    else
    {


        printf("\nEl id ingresado no existe\n");

    }



    return valorRetornado;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");

    printf("*********Listar empleados**********\n\n");

    int id;
    int valorRetornado=0;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    int tam = ll_len(pArrayListEmployee);
    Employee* aux=NULL;

    if(tam>0)
    {

        for(int i=0; i < tam; i++)
        {
            aux = ll_get(pArrayListEmployee, i);

            if(aux!=NULL)
            {
                if( employee_getId(aux, &id)  &&
                        employee_getNombre(aux, nombre) &&
                        employee_getHorasTrabajadas(aux, &horasTrabajadas) &&
                        employee_getSueldo(aux, &sueldo) )
                {
                    printf("Id          Nombre       Horas trabajadas           Sueldo\n");
                    printf("%d   %10s               %d                  %d \n\n", id, nombre, horasTrabajadas, sueldo);

                    valorRetornado=1;

                }

            }
        }
    }
    else
    {

        printf("No hay empleados cargados\n\n");

        valorRetornado=1;
    }

    return valorRetornado;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int valorRetornado = 0;
    int opcion;
    char cerrar='n';



    do
    {

        switch(menuInformation())
        {
        case 1:

            opcion=getOptionOrder();

            if (!ll_sort(pArrayListEmployee, ordenarPorId,opcion))
            {

                valorRetornado=1;

                printf("\nEmpleados ordenados exitosamente\n");
                system ("pause");
            }

            break;
        case 2:

            opcion=getOptionOrder();

            if(!ll_sort(pArrayListEmployee, ordenarPorNombre,opcion))
            {

                valorRetornado=1;
                printf("\nEmpleados ordenados exitosamente\n");
                 system ("pause");
            }

            break;

        case 3:

            opcion=getOptionOrder();

            if(!ll_sort(pArrayListEmployee, ordenarPorHorasTrabajadas,opcion))
            {

                valorRetornado=1;
                printf("\nEmpleados ordenados exitosamente\n");
                 system ("pause");
            }

            break;


        case 4:

            opcion=getOptionOrder();

            if( !ll_sort(pArrayListEmployee, ordenarPorSueldo,opcion))
            {

                valorRetornado=1;
                printf("\nEmpleados ordenados exitosamente\n");
                 system ("pause");
            }

            break;
        case 5:

            cerrar='s';
            break;

        default:

            printf("\nIngrese opcion valida\n");


        }

    }
    while(cerrar=='n');



    return valorRetornado;


}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    int valorRetornado = 0;
    int cant;
    int tam= ll_len(pArrayListEmployee);
    FILE* f=fopen(path, "w");
    Employee* aux=NULL;

    if(  f != NULL && path != NULL && tam > 0&& pArrayListEmployee!=NULL)
    {

        fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");
        for(int i=0; i < tam; i++)
        {
            aux = ll_get(pArrayListEmployee,i);
            cant= fprintf(f, "%d,%s,%d,%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
        }
        if (cant>0)
        {
            valorRetornado=1;
        }
    }

    fclose(f);
    return valorRetornado;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{

    int valorRetornado = 0;
    int cant;
    Employee* aux=NULL;
    FILE* f= fopen(path, "wb");
    int tam =ll_len(pArrayListEmployee);

    if( f != NULL && path != NULL && pArrayListEmployee != NULL && tam > 0)
    {


        for(int i=0; i < tam; i++)
        {
            aux = ll_get(pArrayListEmployee, i);
            cant = fwrite(aux, sizeof(Employee),1,f);

        }

         if(cant >0)
            {
                valorRetornado=1;
            }
        fclose(f);

    }
    return valorRetornado;
}


