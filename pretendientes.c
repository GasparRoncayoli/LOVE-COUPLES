#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "pretendientes.h"
#include "colores.h"

nodoPretendientes * crearNodoPrete(stPretendientes aux)
{
    nodoPretendientes * nuevo = (nodoPretendientes*)malloc(sizeof(nodoPretendientes));
    nuevo->dato = aux;
    nuevo->sig = NULL;
    return nuevo;
}

nodoPretendientes * agregarPrincipioPrete(nodoPretendientes *lista,nodoPretendientes *nuevo)
{
    if(lista!=NULL)
    {
    nuevo->sig = lista;
    }
    return nuevo;
}

nodoPretendientes * descargarMinitas()
{
    FILE * archi=fopen("minitas","rb");
        nodoPretendientes * lista = NULL;
    if(archi!=NULL)
    {

        stPretendientes aux;

        while(fread(&aux,sizeof(stPretendientes),1,archi)>0)
        {
         nodoPretendientes * nuevo = crearNodoPrete(aux);
         lista = agregarPrincipioPrete(lista,nuevo);
        }

      fclose(archi);
    }
   return lista;

}


void dibujoMina()
{

printf("               .::::::::.\n");
printf("              :::::::::::\n");
printf("             ..:::::::::::'\n");
printf("           .:::::::::::'\n");
printf("        '::::::::::::::.\n");
printf("            ..::::::::::.\n");
printf("          ``::::::::::::::\n");
printf("            ::::``::::::::'     .:::.\n");
printf("           ::::'   ':::::'    .::::::::.\n");
printf("         .::::'     :::::   .:::::::'::::.\n");
printf("        .:::'       ::::: .:::::::::' ':::::.\n");
printf("        .::'        :::::.:::::::::'   ':::::.\n");
printf("        .::'         ::::::::::::::'    ``::::.\n");
printf("      ...:::           ::::::::::::'       ``::.\n");
printf("     ````':.           ':::::::::'          ::::..\n");
}


void mostrarMinita(stPretendientes aux)
{
    printf("-----------------\n");
    printf("%s\n",aux.nombre);
    printf("-----------------\n");
}

void mostrarMinita2(stPretendientes aux)
{
    printf("-------------------------\n");
    printf(ROJO_T"%s\n"RESET_COLOR,aux.nombre);
    printf(ROJO_T"%s\n"RESET_COLOR,aux.descripcion);
    printf(ROJO_T"%s\n"RESET_COLOR,aux.genero);
    printf("-------------------------\n");
}


void elegirMinita(nodoPretendientes * uno,nodoPretendientes * dos, nodoPretendientes * tres, char * aux[])
{
    system ("cls");
    int posicion = 1;
    int teclaApretada = 0;


    while(teclaApretada != 13)
    {
    system ("cls");
    gotoxy(0,20);
    dibujoMina();


        apuntaFlecha(1,posicion);               /// MUESTRA COLOREADO LA SELECCION
        if(posicion == 1)
        {
            gotoxy(0,0);
            mostrarMinita2(uno->dato);
        }
        else
        {
            gotoxy(0,0);
            mostrarMinita(uno->dato);
        }

        apuntaFlecha(2,posicion);
        if(posicion == 2)
        {
            gotoxy(0,6);
            mostrarMinita2(dos->dato);
        }
        else
        {
            gotoxy(0,6);
            mostrarMinita(dos->dato);
        }

        apuntaFlecha(3,posicion);
        if(posicion == 3)
        {
            gotoxy(0,12);
            mostrarMinita2(tres->dato);
        }
        else
        {
           gotoxy(0,12);
            mostrarMinita(tres->dato);
        }

       /// FIN DE MOSTRAR COLOREADO LA SELECCION

        teclaApretada = getch();

        posicion = flecha(teclaApretada, posicion);
    }

   if(posicion == 1)
   {
       strcpy(aux,uno->dato.nombre);
   }
    else if(posicion == 2)
   {
       strcpy(aux,dos->dato.nombre);
   }
    else if(posicion == 3)
   {
       strcpy(aux,tres->dato.nombre);
   }

}


//stPretendientes seleccionarWacha()
//{
//nodoPretendientes * lista = NULL;
//
//lista = cargarMinitas();
//char c;
//printf("Elegir minita\n");
//system("pause");
//system("cls");
//
//stPretendientes elegida = elegirMinita(lista,lista->sig,lista->sig->sig);
//system("cls");
//mostrarMinita2(elegida);
//
//return elegida;
//}



