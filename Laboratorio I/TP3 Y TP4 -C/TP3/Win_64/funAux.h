#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


/** \brief Muesttra las opciones del menu principal
 * \return int option (opcion elegida por el usuario)
 */
int menu();


/** \brief Muestra un mensaje, solicita al usuario 's' o 'n', lo valida y lo retorna
 * \param char mensaje[]
 * \param int tam
 * \return char confirmacion
 */
char confirmar (char* mensaje, int tam);


/** \brief Muestra un mensaje, solicita al usuario una cadena de caracteres, lo valida y lo retorna
 * \param char string[]
 * \param int tam
 * \return char mensaje
 */
void getString(char* string, int tam, char* mensaje);


/** \brief Convierte en mayúscula la primer letra de la cadena y las letras subsiguientes a un espacio, y al resto en minusculas
 * \param char* string
 */
void convertirNombrePropio(char* string);



/** \brief Muestra las opciones del submenú informes
 * \return int opcion (opcion elegida por el usuario)
 */

int menuInformation();


/** \brief Solicita que el usuario elija 1 o 0
 * \return int opcion (opcion elegida por el usuario)
 */
int getOptionOrder();


/** \brief Solicita que el usuario ingrese un numero entero mayor a cero
 * \param char* string
 * \return int opcion (opcion elegida por el usuario)
 */
int getEnteroPositivo(char* mensaje);

/** \brief Encuentra caracteres que no sean letras en una cadena de caracteres
 * \param char* string
 * \return int noHaySoloLetras (1 si hay caracteres que no sean letras, 0 si no los hay)
 */
int encontrarCaracterNoLetra(char* string);



/** \brief Encuentra caracteres que no sean numeros enteros en una cadena de caracteres
 * \param char* string
 * \return int noHaySoloNumeros (1 si hay caracteres que no sean numeros enteros, 0 si no los hay)
 */
int encontrarCaracterNoNumero(char* string);
