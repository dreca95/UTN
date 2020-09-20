
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"



Employee* employee_new()
{

    Employee* empleado = (Employee*) malloc(sizeof (Employee));

    if(empleado!=NULL)
    {

        empleado->id=0;
        strcpy(empleado->nombre, " ");
        empleado->horasTrabajadas=0;
        empleado->sueldo=0;
    }

    return empleado;

}


int employee_setId(Employee* this,int id)
{

    int todoOk=0;

    if(this!=NULL)
    {

        this->id=id;
        todoOk=1;
    }

    return todoOk;
}


int employee_getId(Employee* this,int* id)
{

    int todoOk=0;

    if(this !=NULL && id!=NULL)
    {

        *id= this->id;
        todoOk=1;
    }


    return todoOk;
}


int employee_setNombre(Employee* this,char* nombre)
{

    int todoOk=0;

    if(this!=NULL && nombre!=NULL)
    {

        strcpy(this->nombre,nombre);
        todoOk=1;
    }

    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk=0;

    if(this!=NULL&&nombre!=NULL)
    {

        strcpy(nombre, this->nombre);
        todoOk=1;
    }

    return todoOk;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int todoOk=0;

    if( this!=NULL)
    {

        this->horasTrabajadas= horasTrabajadas;
        todoOk=1;
    }

    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;

    if(this!=NULL&& horasTrabajadas!=NULL)
    {

        *horasTrabajadas= this->horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=0;

    if(this!=NULL)
    {

        this->sueldo=sueldo;
        todoOk=1;

    }

    return todoOk;

}



int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk=0;

    if(this!=NULL&&sueldo!=NULL)
    {

        *sueldo=this->sueldo;
        todoOk=1;

    }

    return todoOk;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* empleado = employee_new();
    int id;
    int horasTrabajadas;
    int sueldo;

    id= atoi(idStr);
    horasTrabajadas= atoi(horasTrabajadasStr);
    sueldo= atoi(sueldoStr);

    if(empleado==NULL||!employee_setId(empleado,id)||
            !employee_setNombre(empleado,nombreStr)||
            !employee_setHorasTrabajadas(empleado,horasTrabajadas)||
            !employee_setSueldo(empleado,sueldo))
    {


        empleado=NULL;

    }

    return empleado;

}

void employee_delete(Employee* this)
{


    if(this != NULL)
    {
        free(this);

    }


}


int getLastId(LinkedList* this)
{
    Employee* aux=NULL;
    int id=0;;

    int tam = ll_len(this);

    if(tam>0)
    {

        aux= (Employee*)ll_get(this,tam-1);

        if(aux!=NULL)
        {

            employee_getId(aux, &id);
        }
    }
    return id;

}




int ordenarPorNombre(void* empleadoUno,void* empleadoDos)
{

    char nombreEmpUno[20];
    char nombreEmpDos[20];
    int valorRetornado=0;

    employee_getNombre((Employee*)empleadoUno,nombreEmpUno);
    employee_getNombre((Employee*)empleadoDos,nombreEmpDos);

    if(strcmp(nombreEmpUno,nombreEmpDos) > 0)
    {
        valorRetornado = 1;


    }
    else if(strcmp(nombreEmpDos,nombreEmpUno) > 0)
    {
        valorRetornado = -1;
    }


    return valorRetornado;
}


int ordenarPorSueldo(void* empleadoUno,void* empleadoDos)
{

    int sueldoEmpUno=0;
    int sueldoEmpDos=0;
    int valorRetornado=0;

    employee_getSueldo((Employee*)empleadoUno,&sueldoEmpUno);
    employee_getSueldo((Employee*)empleadoDos,&sueldoEmpDos);

    if(sueldoEmpUno>sueldoEmpDos)
    {
        valorRetornado = 1;


    }
    else if(sueldoEmpUno<sueldoEmpDos)
    {
        valorRetornado = -1;
    }


    return valorRetornado;
}



int ordenarPorId(void* empleadoUno,void* empleadoDos)
{

    int idEmpUno=0;
    int idEmpDos=0;
    int valorRetornado=0;

    employee_getId((Employee*)empleadoUno,&idEmpUno);
    employee_getId((Employee*)empleadoDos,&idEmpDos);

    if(idEmpUno>idEmpDos)
    {
        valorRetornado = 1;


    }
    else if(idEmpUno<idEmpDos)
    {
        valorRetornado = -1;
    }


    return valorRetornado;
}



int ordenarPorHorasTrabajadas(void* empleadoUno,void* empleadoDos)
{

    int hTEmpUno=0;
    int hTEmpDos=0;
    int valorRetornado=0;

    employee_getHorasTrabajadas((Employee*)empleadoUno,&hTEmpUno);
    employee_getHorasTrabajadas((Employee*)empleadoDos,&hTEmpDos);

    if(hTEmpUno>hTEmpDos)
    {
        valorRetornado = 1;


    }
    else if(hTEmpUno<hTEmpDos)
    {
        valorRetornado = -1;
    }


    return valorRetornado;
}


