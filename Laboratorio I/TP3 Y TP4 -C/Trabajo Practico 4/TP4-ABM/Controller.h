#include "LinkedList.h"

int controller_loadFromText(char* path, LinkedList* pApp);
int controller_addApp(LinkedList* pApp);
int controller_removeApp(LinkedList* pApp);
int controller_ListApp(LinkedList* pApp);
int controller_sortAppCantidadDesc(LinkedList* pApp);
int controller_saveAsText(char* path, LinkedList* pApp);
int controller_loadFromTextAppFav(char* path, LinkedList* pApp);


int controller_addAppFav(LinkedList* pApp,LinkedList* favoritas);
int controller_ListAppFav(LinkedList* pApp);
int controller_saveAsTextAppFav(char* path, LinkedList* pApp);

