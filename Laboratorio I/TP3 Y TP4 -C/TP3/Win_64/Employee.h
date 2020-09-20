#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "funAux.h"
#include "LinkedList.h"


typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);



int getLastId(LinkedList* this);

int ordenarPorNombre(void* empleadoUno,void* empleadoDos);
int ordenarPorSueldo(void* empleadoUno,void* empleadoDos);
int ordenarPorId(void* empleadoUno,void* empleadoDos);
int ordenarPorHorasTrabajadas(void* empleadoUno,void* empleadoDos);

#endif // employee_H_INCLUDED
