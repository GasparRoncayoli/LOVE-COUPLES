
#include "login.h"
#include "pretendientes.h"
#include "aventura.h"
#include "menu.h"
#include "colores.h"






//funciones
nodoPregunta * inicArbol();
nodoPregunta* cargarNodoArbol(stPregunta nuevo);
int accion_en_nodo (nodoPregunta* p);
stPregunta cargar_pregunta();
void mostrar_pregunta(stPregunta aux);
int elegir_opcion(stPregunta p);
int contador_puntos (stPregunta p);


//#endif // ARBOLESFINAL_H_INCLUDED
