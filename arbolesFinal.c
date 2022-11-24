#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "arbolesFinal.h"

nodoPregunta * inicArbol()
{
    return NULL;
}

nodoPregunta * crearNodoArbol(stPregunta nuevo)//funcion para cargar arbol
{

    nodoPregunta * aux = (nodoPregunta*) malloc (sizeof(nodoPregunta));
    aux->der= NULL;
    aux->izq = NULL;
    aux->dato = nuevo;
    return aux;
}
int accion_en_nodo (nodoPregunta* p)
{
    int puntaje=0;
    mostrar_pregunta(p->dato);
    puntaje=elegir_opcion(p->dato);//pasa pregunta por parametro
    return puntaje;
}

stPregunta cargar_pregunta()//habria que hacerlo para que lea el archivo esta es para probar como hacerlo
{
    //abre el archivo y las carga
    //esta funcion no va, el archivo lee directamente la estructura cuncion de prueba
    stPregunta aux;
    strcpy(aux.pregunta,"De que trabajas?");
    strcpy(aux.opcion1,"Uy que raro");
    strcpy(aux.opcion2,"Cuanto cobras?");
    strcpy(aux.opcion3,"Te gusta?");
    strcpy(aux.opcion4,"Estudiaste?");
    aux.punto1 = 1;
    aux.punto2 = -1;
    aux.punto3 = 3;
    aux.punto4 = -3;

    return aux;
}
void mostrar_pregunta(stPregunta aux)
{
    printf("\n%s",aux.pregunta);
    printf("\n%s",aux.opcion1);
    printf("\n%s",aux.opcion2);
    printf("\n%s",aux.opcion3);
    printf("\n%s",aux.opcion4);
}
int elegir_opcion(stPregunta p)
{
    int puntos=0;                //se puede hacer un acumulador en la struct personaje paraa que acumule
    puntos = contador_puntos(p); //sumey reste los puntos,la funcion se iguala al acumulador
    return puntos;
}

int contador_puntos (stPregunta p)
{
    int opcion;
    int puntos=0;
    char control='n';
    do
    {
    printf("\nElija opcion 1, 2, 3 o 4 ");
    scanf("\n%i",&opcion);

        switch(opcion)
        {
        case 1:
            puntos=p.punto1;
            break;
        case 2:
            puntos=p.punto2;
            break;
        case 3:
            puntos=p.punto3;
            break;
        case 4:
            puntos=p.punto4;
            break;
        default:
            printf("\nNo es opcion");
            control='s';
            system("pause");
            break;
        }
    }
    while(control=='s');
    return puntos;
}
