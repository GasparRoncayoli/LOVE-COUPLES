#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "aventura.h"

void cargarHistoria()
{
    FILE * arch = fopen(HIS, "ab");
    stPregunta a;
    if(arch!=NULL)
    {

        for(int i = 0; i<63 ; i++)
        {
            a = cargarStPregunta();
            fwrite(&a, sizeof(stPregunta), 1, arch);
        }
        fclose(arch);
    }
}

stPregunta cargarStPregunta()
{
    stPregunta aux;
    printf("\n id: \n");
    scanf("%i", &aux.id);
    printf("\n PREGUNTA\n");
    fflush(stdin);
    gets(aux.pregunta);

    printf("\n OPCION 1\n");
    fflush(stdin);
    gets(aux.opcion1);
    printf("\n PUNTAJE:\n");
    scanf("%i", &aux.punto1);

    printf("\n OPCION 2\n");
    fflush(stdin);
    gets(aux.opcion2);
    printf("\n PUNTAJE:\n");
    scanf("%i", &aux.punto2);

    printf("\n OPCION 3\n");
    fflush(stdin);
    gets(aux.opcion3);
    printf("\n PUNTAJE:\n");
    scanf("%i", &aux.punto3);

    printf("\n OPCION 4\n");
    fflush(stdin);
    gets(aux.opcion4);
    printf("\n PUNTAJE:\n");
    scanf("%i", &aux.punto4);

    return aux;
}

nodoPregunta * descargarHistoria(nodoPregunta * arbol)
{
    FILE * arch = fopen(HIS, "rb");
    stPregunta a;

    if(arch!=NULL)
    {
        while(fread(&a, sizeof(stPregunta), 1, arch)>0)
        {
            nodoPregunta * nuevo = inicArbol();
            nuevo = crearNodoArbol(a);
            arbol = insertar(arbol, nuevo);
        }

        fclose(arch);
    }
    return arbol;
}

nodoPregunta * insertar(nodoPregunta * arbol, nodoPregunta * nuevo)
{
    if(arbol==NULL)
    {
        arbol = nuevo;
    }
    else
    {
        if(arbol->dato.id > nuevo->dato.id)
        {
            arbol->izq = insertar(arbol->izq, nuevo);
        }
        else
        {
            arbol->der = insertar(arbol->der, nuevo);
        }
    }
    return arbol;
}

