#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "funAux.h"
#include "LinkedList.h"


typedef struct
{
    int cantidadUsers;
    char nombre[128];
    int anio;
} App;


typedef struct
{

    App* aplicacion;
    int estrellas;

} AppFavorita;


App* app_new();

void app_delete(App* this);

App* app_newParametros(int cantidad, char* nombre, int anio);
int app_setCantidad(App* this,int id);
int app_getCantidad(App* this,int* id);

int app_setNombre(App* this,char* nombre);
int app_getNombre(App* this,char* nombre);

int app_setAnio(App* this,int anio);
int app_getAnio(App* this,int* anio);


int ordenarPorCantidad(void* aplicacionUno,void* aplicacionDos);



LinkedList* elegirFavoritos (LinkedList* pApp);

AppFavorita* appFav_new();
AppFavorita* appFavorita_newParametros(App* aplicacion, int estrellas);
int appFavorita_setAplicacion(AppFavorita* this, App* aplicacion);

int appFavorita_getEstrellas(AppFavorita* this,int* estrellas);
int appFavorita_setEstrellas(AppFavorita* this,int estrellas);


int appFavorita_getAplicacion(AppFavorita* this, App** aplicacion);

int estaNombreEnListaApp (char* nombre, LinkedList* pApp);
int estaNombreEnListaAppFav (char* nombre, LinkedList* pApp);


LinkedList* aplicacionesCincoEstrellas(LinkedList* appFav);

#endif // employee_H_INCLUDED
