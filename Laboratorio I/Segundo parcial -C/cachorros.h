#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>



#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

int ID_Cachorro;
char nombre[20];
int dias;
char raza [20];
char reservado[3];
char genero;

}eCachorro;




#endif // FUNCIONES_H_INCLUDED

int parsearArchivoCSV(FILE* pFile, LinkedList* elementos);

eCachorro* nuevoelemento();

int setID_Cachorro(eCachorro* this,int id_cachorro);
int getId_Cachorro(eCachorro* this,int* id_cachorro);

int setNombre(eCachorro* this,char* nombre);
int getNombre(eCachorro* this,char* nombre);
int setDias(eCachorro* this,int edad);

int getDias(eCachorro* this,int* edad);
int setRaza(eCachorro* this,char* raza);

int getRaza(eCachorro* this,char* raza);
int setReservado(eCachorro* this,char* reservado);
int getReservado(eCachorro* this,char* reservado);
int setGenero(eCachorro* this,char genero);
int getGenero(eCachorro* this,char* genero);
eCachorro* nuevoelementoParametros(int ID_Cachorro, char* nombre, int dias,char* raza, char* reservado, char genero);
//int setearTipo(eDominio* elemento);
//int controller_saveAsText(char* path, LinkedList* pArrayList);

void cachorros_toString(eCachorro* elemento);

int cargarElementos(char* archivo,LinkedList* elementos);
int esMayora44(eCachorro* elemento);

int controller_saveAsText(char* path, LinkedList* pArrayList);
int noEsMacho(eCachorro* elemento);
int esCallejero(eCachorro* elemento);

//void llamados_toString(eDominio* elemento);
//void descProblema(int problema, char* desc);

//int esDeEsteTipo(eDominio* elemento, int tipo);
//int solicitarTipoProblema();

//LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*,char),char tipo);
//LinkedList* ll_map(LinkedList* this, int (*pFunc)(void*));
