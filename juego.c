#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <pthread.h>

#include "juego.h"

void retornarMinita(char  nombre[])
{
    nodoPretendientes * minitas = descargarMinitas();
    nodoPretendientes * uno = minitas;
    nodoPretendientes * dos = minitas->sig;
    minitas = minitas->sig;
    nodoPretendientes * tres = minitas->sig;

//    strcpy(c,elegirMinita(uno,dos,tres));
    elegirMinita(uno,dos,tres, nombre);


}

/*stHistorial startGame()
{
    system ("cls");

    stHistorial historial;
    nodoPregunta *arbol = inicArbol();
    system("cls");

    retornarMinita(&historial.pretendiente);

    system("cls");

    celdaEstilo arr[30]={};
    int validos = descargarEstilos(arr);
    elegirCelda(arr,validos, &historial.estilo);
    system("cls");

    arbol = descargarHistoria(arbol);
    int puntos = recorrer(arbol,puntos);
    historial.puntajeObtenido = puntos;
    system("cls");

    return historial;
}
*/


//void game(char user[])
//{
//
//
//    arbol = descargarHistoria(arbol);
//    int puntos = recorrer(arbol,puntos);
//    historial.puntajeObtenido = puntos;
//
//    nodoDobleUser * nuevo = descargarHistorial();
//    nuevo = altaLDF(nuevo,user,historial);
//    cargarHistorial(nuevo);
//}


int recorrer(nodoPregunta *arbol, int puntos)
{
    int des = 0;

    if(arbol != NULL)
    {
        puntos = puntos + menuIngame(arbol->dato);
        getch();
        system("cls");
        des = decision(arbol);

        if(des == 1)
        {
            puntos = recorrer(arbol->der, puntos);
        }else{

            puntos = recorrer(arbol->izq, puntos);
        }
    }

    return puntos;
}

int decision2(nodoPregunta *arbol)
{
    int rta = 0;


    int posicion = 1;
    int teclaApretada = 0;

    nodoPregunta * derecha = arbol->der;
    nodoPregunta * izquierda = arbol->izq;
    system ("cls");
    while(teclaApretada != 13)
    {
    mostrarDialogo(arbol->dato.pregunta);


        apuntaFlecha(1,posicion);               /// MUESTRA COLOREADO LA SELECCION
        if(posicion == 1)
        {
            gotoxy(60,0);
            printf(ROJO_F "%s \n" RESET_COLOR, arbol->dato.opcion2);
        }
        else
        {
            gotoxy(60,0);
            printf("%s \n", arbol->dato.opcion2);
        }

        apuntaFlecha(2,posicion);
        if(posicion == 2)
        {
            gotoxy(60,19);
            printf(ROJO_F "%s \n" RESET_COLOR, arbol->dato.opcion1);
        }
        else
        {
            gotoxy(60,19);
            printf("%s \n", arbol->dato.opcion1);
        }
      teclaApretada = getch();
      posicion = flecha(teclaApretada, posicion);
    }


    if(posicion == 1)
    {
        rta = 1; // der
    }else{
        rta = 2; // izq
    }

    return rta;
}

int decision(nodoPregunta *arbol)
{
    int rta = 0;

    if(arbol->der!=NULL || arbol->izq != NULL)
    {
        printf("Como desea continuar su conversacion?\n");

    int posicion = 1;
    int teclaApretada = 0;


        nodoPregunta * derecha = arbol->der;
        nodoPregunta * izquierda = arbol->izq;
        system ("cls");
        while(teclaApretada != 13)
        {
        mostrarDialogo(arbol->dato.pregunta);


            apuntaFlecha(1,posicion);               /// MUESTRA COLOREADO LA SELECCION
            if(posicion == 1)
            {
                gotoxy(60,0);
                printf(ROJO_F "%s \n" RESET_COLOR, derecha->dato.pregunta);
            }
            else
            {
                gotoxy(60,0);
                printf("%s \n", derecha->dato.pregunta);
            }

            apuntaFlecha(2,posicion);
            if(posicion == 2)
            {
                gotoxy(60,19);
                printf(ROJO_F "%s \n" RESET_COLOR, izquierda->dato.pregunta);
            }
            else
            {
                gotoxy(60,19);
                printf("%s \n", izquierda->dato.pregunta);
            }

          teclaApretada = getch();
          posicion = flecha(teclaApretada, posicion);
        }


        if(posicion == 1)
        {
            rta = 1; // der
        }else{
            rta = 2; // izq
        }
    }

    return rta;
}

int menuIngame(stPregunta aux)
{
    system ("cls");
    int posicion = 1;
    int teclaApretada = 0;

    while(teclaApretada != 13)
    {
        system ("cls");
        mostrarDialogo(aux.pregunta);


        apuntaFlecha(1,posicion);               /// MUESTRA COLOREADO LA SELECCION
        if(posicion == 1)
        {
            gotoxy(60,0);
            printf(ROJO_F "%s \n" RESET_COLOR, aux.opcion1);
        }
        else
        {
            gotoxy(60,0);
            printf("%s \n", aux.opcion1);
        }

        apuntaFlecha(2,posicion);
        if(posicion == 2)
        {
            gotoxy(0,7);
            printf(ROJO_F "%s \n" RESET_COLOR, aux.opcion2);
        }
        else
        {
            gotoxy(0,7);
            printf("%s \n", aux.opcion2);
        }

        apuntaFlecha(3,posicion);
        if(posicion == 3)
        {
            gotoxy(110,7);
            printf(ROJO_F "%s \n" RESET_COLOR, aux.opcion3);
        }
        else
        {
           gotoxy(110,7);
            printf("%s \n", aux.opcion3);
        }

        apuntaFlecha(4,posicion);
        if(posicion == 4)
        {
            gotoxy(60,20);
            printf(ROJO_F "%s \n" RESET_COLOR, aux.opcion4);
        }
        else
        {
            gotoxy(60,20);
            printf("%s \n", aux.opcion4);
        }                                           /// FIN DE MOSTRAR COLOREADO LA SELECCION

        teclaApretada = getch();

        posicion = flecha(teclaApretada, posicion);
    }

    mostrarDialogo2(aux,posicion);


    int puntos = 0;
    puntos = seleccionPuntos(teclaApretada,posicion,aux);
   return puntos;
}
int seleccionPuntos(int teclaApretada, int posicion,stPregunta puntos) //
{
    int num=0;
    if(teclaApretada == 13 && posicion == 1)
    {
     num=puntos.punto1;
    }
    else if(teclaApretada == 13 && posicion == 2)
    {
    num=puntos.punto2;
    }
    else if(teclaApretada == 13 && posicion == 3)
    {
     num=puntos.punto3;
    }
    else
    {
     num=puntos.punto4;
    }

    return num;
}

void mostrarDialogo(char pregunta[])
{

    gotoxy(20,3);
    printf("-------------------------------------------------------------------------------------\n");
    gotoxy(20,4);
    printf("|  %-82s|\n",pregunta);
    gotoxy(20,5);
    printf("|                                                                                    |\n");
    gotoxy(20,6);
    printf("|                                                                                    |\n");
    gotoxy(20,7);
    printf("|                                                                                    |\n");
    gotoxy(20,8);
    printf("|                                                                                    |\n");
    gotoxy(20,9);
    printf("|                                                                                    |\n");
    gotoxy(20,10);
    printf("|                                                                                    |\n");
    gotoxy(20,11);
    printf("|                                                                                    |\n");
    gotoxy(20,12);
    printf("|                                                                                    |\n");
    gotoxy(20,13);
    printf("|                                                                                    |\n");
    gotoxy(20,14);
    printf("|                                                                                    |\n");
    gotoxy(20,15);
    printf("|                                                                                    |\n");
    gotoxy(20,16);
    printf(" ------------------------------------------------------------------------------------\n");

}

void mostrarDialogo2(stPregunta aux, int pos)
{
    if(pos == 1)
    {
    gotoxy(20,3);
    printf("-------------------------------------------------------------------------------------\n");
    gotoxy(20,4);
    printf("|  %-82s|\n",aux.pregunta);
    gotoxy(20,5);
    printf("|                                                                                    |\n");
    gotoxy(20,6);
    printf("|                                                                                    |\n");
    gotoxy(20,7);
    printf("|                                                                                    |\n");
    gotoxy(20,8);
    printf("|  %-82s|\n",aux.opcion1);
    gotoxy(20,9);
    printf("|                                                                                    |\n");
    gotoxy(20,10);
    printf("|  %-82s|\n",aux.resp1);
    gotoxy(20,11);
    printf("|                                                                                    |\n");
    gotoxy(20,12);
    printf("|                                                                                    |\n");
    gotoxy(20,13);
    printf("|                                                                                    |\n");
    gotoxy(20,14);
    printf("|                                                                                    |\n");
    gotoxy(20,15);
    printf("|                                                                                    |\n");
    gotoxy(20,16);
    printf(" ------------------------------------------------------------------------------------\n");
    }
    else if(pos == 2)
    {
    gotoxy(20,3);
    printf("-------------------------------------------------------------------------------------\n");
    gotoxy(20,4);
    printf("|  %-82s|\n",aux.pregunta);
    gotoxy(20,5);
    printf("|                                                                                    |\n");
    gotoxy(20,6);
    printf("|                                                                                    |\n");
    gotoxy(20,7);
    printf("|                                                                                    |\n");
    gotoxy(20,8);
    printf("|  %-82s|\n",aux.opcion2);
    gotoxy(20,9);
    printf("|                                                                                    |\n");
    gotoxy(20,10);
    printf("|  %-82s|\n",aux.resp2);
    gotoxy(20,11);
    printf("|                                                                                    |\n");
    gotoxy(20,12);
    printf("|                                                                                    |\n");
    gotoxy(20,13);
    printf("|                                                                                    |\n");
    gotoxy(20,14);
    printf("|                                                                                    |\n");
    gotoxy(20,15);
    printf("|                                                                                    |\n");
    gotoxy(20,16);
    printf(" ------------------------------------------------------------------------------------\n");
    }
     else if(pos == 3)
    {
    gotoxy(20,3);
    printf("-------------------------------------------------------------------------------------\n");
    gotoxy(20,4);
    printf("|  %-82s|\n",aux.pregunta);
    gotoxy(20,5);
    printf("|                                                                                    |\n");
    gotoxy(20,6);
    printf("|                                                                                    |\n");
    gotoxy(20,7);
    printf("|                                                                                    |\n");
    gotoxy(20,8);
    printf("|  %-82s|\n",aux.opcion3);
    gotoxy(20,9);
    printf("|                                                                                    |\n");
    gotoxy(20,10);
    printf("|  %-82s|\n",aux.resp3);
    gotoxy(20,11);
    printf("|                                                                                    |\n");
    gotoxy(20,12);
    printf("|                                                                                    |\n");
    gotoxy(20,13);
    printf("|                                                                                    |\n");
    gotoxy(20,14);
    printf("|                                                                                    |\n");
    gotoxy(20,15);
    printf("|                                                                                    |\n");
    gotoxy(20,16);
    printf(" ------------------------------------------------------------------------------------\n");
    }
     else
    {
    gotoxy(20,3);
    printf("-------------------------------------------------------------------------------------\n");
    gotoxy(20,4);
    printf("|  %-82s|\n",aux.pregunta);
    gotoxy(20,5);
    printf("|                                                                                    |\n");
    gotoxy(20,6);
    printf("|                                                                                    |\n");
    gotoxy(20,7);
    printf("|                                                                                    |\n");
    gotoxy(20,8);
    printf("|  %-82s|\n",aux.opcion4);
    gotoxy(20,9);
    printf("|                                                                                    |\n");
    gotoxy(20,10);
    printf("|  %-82s|\n",aux.resp4);
    gotoxy(20,11);
    printf("|                                                                                    |\n");
    gotoxy(20,12);
    printf("|                                                                                    |\n");
    gotoxy(20,13);
    printf("|                                                                                    |\n");
    gotoxy(20,14);
    printf("|                                                                                    |\n");
    gotoxy(20,15);
    printf("|                                                                                    |\n");
    gotoxy(20,16);
    printf(" ------------------------------------------------------------------------------------\n");
    }
}
