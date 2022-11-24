#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "arbolesFinal.h"



int flecha (int teclaApretada, int posicion)
{
    if(teclaApretada == 80 && posicion != 5)
    {
        posicion++;
    }
    else if(teclaApretada == 72 && posicion != 1)
    {
        posicion--;
    }
    else if(teclaApretada == 27)
    {
       salir(posicion);
    }

    return posicion;
}

void salirMENU()
{
    goto menu;
    menu: main();
}

int salir(int posicion)
{
    int tecla;
    posicion = 1;
    while(tecla != 13)
    {
        system("cls");

        gotoxy(20,10);
        printf(BLANCO_T"JUEGO EN PAUSA"RESET_COLOR);
        apuntaFlecha(1,posicion);
        if(posicion == 1)
        {
        gotoxy(20,12);
        printf(ROJO_T"  Continuar."RESET_COLOR);
        }
        else
        {
        gotoxy(20,12);
        printf("Continuar.");
        }
        apuntaFlecha(2,posicion);
        if(posicion==2)
        {

        gotoxy(20,14);
        printf(ROJO_T"  Volver al menu. "RESET_COLOR);
        }
        else
        {
        gotoxy(20,14);
        printf("Volver al menu. ");
        }
        apuntaFlecha(3,posicion);
        if(posicion==3)
        {
        gotoxy(20,16);
        printf(ROJO_T"  Volver al escritorio. "RESET_COLOR);
        }
        else
        {
        gotoxy(20,16);
        printf("Volver al escritorio. ");
        }

        tecla = getch();

        if(tecla == 80 && posicion != 3)
        {
            posicion++;
        }
        else if(tecla == 72 && posicion != 1)
        {
            posicion--;
        }
    }
    if(tecla == 13 && posicion == 1)
    {
        return 0;
    }
    else if(tecla == 13 && posicion == 2)
    {
        goto menu;
        menu: main();
    }
    else if(tecla == 13 && posicion == 3)
    {

        exit(0);
    }
}

void seleccion (int teclaApretada, int posicion, stHistorial * historiali, nodoDobleUser * user)
{
    if(teclaApretada == 13 && posicion == 1) // JUGAR
    {
        system ("cls");

    nodoPregunta *arbol = inicArbol();
    system("cls");

    retornarMinita(historiali->pretendiente);

    system("cls");

    celdaEstilo arr[30]={};
    int validos = descargarEstilos(arr);
    elegirEstiloCelda(arr,validos,&historiali->estilo);
    system("cls");

    arbol = descargarHistoria(arbol);
    int desicion = decision2(arbol);
    int puntos=0;


        if(desicion == 1)
        {
            puntos = recorrer(arbol->der,puntos);
        }else{
            puntos = recorrer(arbol->izq, puntos);
        }

        historiali->puntajeObtenido = puntos;


        while(teclaApretada != 27)
        {
            mostrarGanado(historiali->puntajeObtenido);
        if(puntos>0)
        {
            user->logros.trofeo1 = 1;
        }
        else if (puntos < 0)
        {
            user->logros.trofeo2 = 1;
        }
        else
        {
            user->logros.trofeo3 = 1;
        }
            cargarLogros(user);

            user = altaLDF(user,user->user,historiali);
            cargarHistorial(user);


             teclaApretada = getch();
                salirMENU();


        }
    }
    else if(teclaApretada == 13 && posicion == 2) // INSTRUCCIONES
    {
        while(teclaApretada != 27)
        {
            system ("cls");
            gotoxy(10,0);
            printf(ROJO_T"INSTRUCCIONES");
            gotoxy(10,1);
            printf("Primero debera elegir la pretendiente a conquistar.");
            gotoxy(10,2);
            printf("Luego escoja la vestimenta para la ocasion.");
            gotoxy(10,3);
            printf("Y por ultimo diganos su personalidad.");
            gotoxy(10,4);
            printf("El simulador de citas sumara puntos en base a sus respuestas.");
            gotoxy(10,5);
            printf("Exitos!!");
            gotoxy(90,0);
            printf("--------------------------\n");
            gotoxy(90,1);
            printf("|Presione ESC, para salir |\n");
            gotoxy(90,2);
            printf("--------------------------\n"RESET_COLOR);
            teclaApretada = getch();

            if(teclaApretada == 27)
            {
             salirMENU();
            }
        }
    }
    else if(teclaApretada == 13 && posicion == 3) // LOGROS
    {
        posicion = 1;
        while(teclaApretada != 27) // MIENTRAS NO APRIETE ESC
        {
            system ("cls");
            stTrofeo a;
            a = buscarLogros(user);
            verTrofeo(a);


            teclaApretada = getch();

            if(teclaApretada == 27)
            {
                salirMENU();
            }

            posicion = flecha(teclaApretada, posicion);

            /*if(teclaApretada == 13)  // PARA QUE SOLO MUESTRE SI SELECCIONO UN FINAL CON ENTER
            {
                mostrarFinal(posicion);
            }*/
        }

    }
    else if(teclaApretada == 13 && posicion == 4)
    {
        system("cls");

        nodoDobleUser * nuevo = descargarHistorial();
        mostrarLista(nuevo);

        printf("Presione ESC, para salir.\n");

        teclaApretada = getch();

        if(teclaApretada == 27)
            {
                salirMENU();
            }

    }
    else // SALIR
    {
        system ("cls");
        exit(0);
    }

}

void apuntaFlecha (int posicionReal, int posicionFlecha)
{
    if(posicionReal == posicionFlecha)
    {
        printf("                                                                   ");
    }
    else
    {
        printf("                                                                  ");
    }
}

/*void mostrarFinal(int posicion)
{
    if(posicion == 1)
    {
        printf("\n-------------------------\n\n");
        printf("Mataste a la chica.\n");
        printf("\n-------------------------\n");

        system("pause");
        seleccion(13,3);
    }
    else if(posicion == 2)
    {
        printf("\n-------------------------\n\n");
        printf("La conquistaste.\n");
        printf("\n-------------------------\n");
        system("pause");
        seleccion(13,3);
    }
    else if(posicion == 3)
    {
        printf("\n-------------------------\n\n");
        printf("Ambos murienron.\n");
        printf("\n-------------------------\n");
        system("pause");
        seleccion(13,3);
    }
    else
    {
        printf("\n-------------------------\n\n");
        printf("No se wacho inventa otro final.\n");
        printf("\n-------------------------\n");
        system("pause");
        seleccion(13,3);
    }
}
*/
void imgPareja ()
{

    printf(ROJO_T"\n  ---------------------------------------------------------------------------------\n");
    printf("|         _,=**************,_                 _,**************=,_                 |\n");
    printf( "|       _,*********************,_           _,*********************,_             |\n");
    printf( "|      ,***************************,       ,***************************,          |\n");
    printf(  "|     ,*******************************,   ,*******************************,       |\n");
    printf(   "|    ,*********************************, ,*********************************,      |\n");
    printf(    "|   ,************************ ,;ssssssss;. *********************************,     |\n");
    printf(   "|   ******************** ____sSSSSSSSSSSSSs, ********************************     |\n");
    printf(    "|   ******************* / __()SSSSSSSSSSSSSSs            ********************     |\n");
    printf(    "|   ****************** / ___()SSSSSSSSSSSSSSS _-TTTTTT--_  ******************     |\n");
    printf(      "|   ***************** / ___()SSSSSSSSS'     |///|||\\\\\\\\     *****************     |\n");
    printf(       "|   **************** ( __()SSSSSS(@)S' ====/=_ '||||\\\\\\\\     ****************     |\n");
    printf(       "|   ***************** \SSSSSSSSSS()     ~=|_  ~  ||||\\\\\\\\      ***************     |\n");
    printf(     "|   **************** {SSSSSSSSSS'         |       ||||||||||| ***************     |\n");
    printf(      "|    *************** {SSSSSSS'         _/~'       ||||||||||| ***************     |\n");
    printf(      "|   `*************** {SSSSS'   \      (x)         |||||||||||  **************'     |\n");
    printf(       "|    `*************  /          ~-_   /~          ||||||||||| *************'      |\n");
    printf(       "|     `************ |            / ~~~\______--~  |||||||||||  ************'       |\n");
    printf(       "|      `*********** |           | \ ****** /      |||||||||||  ***********'        |\n");
    printf(      "|       `********* |   _-----__ |  \ **** /       |||||||||||  **********'         |\n");
    printf(      "|           ~***** |                ~~-_/ /       |||||||\\\\\       *****~          |\n");
    printf(     "|             ~** |                     ~~--__     \\\\\\\\\\\\        **~              |\n");
    printf(       "|               ~**                           ~~----\\\\\\\\\\**~                      |\n");
    printf(       "|                 ~**                                \\\\\\\**~                       |\n");
    printf(        "|                   ~** --__                          \\\\**~                       |\n");
    printf(        "|                     ~**,. ~~--__                    ||**~                       |\n");
    printf(        "|                       ~****;,.. ~~~---____         .**~                         |\n");
    printf(        "|                         ~************;,.. ~~~~~~~.**~                           |\n");
    printf(        "|                          ~***********************~                              |\n");
    printf(        "|                           ~*******************~                                 |\n");
    printf(        "|                            ~***************~                                    |\n");
    printf(        "|                               ~*******~                                         |\n");
    printf(       "|                                 ~***~                                           |\n");
    printf(       "|                                  `*'                                            |\n");
    printf(" ----------------------------------------------------------------------------------\n"RESET_COLOR);
}

void gotoxy(int x, int y)
{
// CONTROLADOR PARA NUESTRA VENTANA, Y MANIPULACION DE CONSOLA
    HANDLE ventana;
    ventana = GetStdHandle(STD_OUTPUT_HANDLE);

// CREAMOS OBJETO DE LAS CORDENADAS DENTRO DE UNA ESTRUCTURA
    COORD cordenadas;
// REDIRECCIONAMOS LAS VARIABLES DE LA ESTRUCTURA A NUESTRAS VARIABLES DE LA FUNCION
    cordenadas.X = x;
    cordenadas.Y = y;

// POSICIONAMOS EL MENSAJE DENTRO DE NUESTRA CONSOLA, A NUESTRA VENTANA CON LAS CORDENADAS DADAS.
    SetConsoleCursorPosition(ventana,cordenadas);



}

void animacionChauPareja()
{
    int i=10;
    while(i>1)
    {

        system("cls");
        gotoxy(0,i);

    printf("\n  ---------------------------------------------------------------------------------\n");
    printf("|         _,=**************,_                 _,**************=,_                 |\n");
    printf( "|       _,*********************,_           _,*********************,_             |\n");
    printf( "|      ,***************************,       ,***************************,          |\n");
    printf(  "|     ,*******************************,   ,*******************************,       |\n");
    printf(   "|    ,*********************************, ,*********************************,      |\n");
    printf(    "|   ,************************ ,;ssssssss;. *********************************,     |\n");
    printf(   "|   ******************** ____sSSSSSSSSSSSSs, ********************************     |\n");
    printf(    "|   ******************* / __()SSSSSSSSSSSSSSs            ********************     |\n");
    printf(    "|   ****************** / ___()SSSSSSSSSSSSSSS _-TTTTTT--_  ******************     |\n");
    printf(      "|   ***************** / ___()SSSSSSSSS'     |///|||\\\\\\\\     *****************     |\n");
    printf(       "|   **************** ( __()SSSSSS(@)S' ====/=_ '||||\\\\\\\\     ****************     |\n");
    printf(       "|   ***************** \SSSSSSSSSS()     ~=|_  ~  ||||\\\\\\\\      ***************     |\n");
    printf(     "|   **************** {SSSSSSSSSS'         |       ||||||||||| ***************     |\n");
    printf(      "|    *************** {SSSSSSS'         _/~'       ||||||||||| ***************     |\n");
    printf(      "|   `*************** {SSSSS'   \      (x)         |||||||||||  **************'     |\n");
    printf(       "|    `*************  /          ~-_   /~          ||||||||||| *************'      |\n");
    printf(       "|     `************ |            / ~~~\______--~  |||||||||||  ************'       |\n");
    printf(       "|      `*********** |           | \ ****** /      |||||||||||  ***********'        |\n");
    printf(      "|       `********* |   _-----__ |  \ **** /       |||||||||||  **********'         |\n");
    printf(      "|           ~***** |                ~~-_/ /       |||||||\\\\\       *****~          |\n");
    printf(     "|             ~** |                     ~~--__     \\\\\\\\\\\\        **~              |\n");
    printf(       "|               ~**                           ~~----\\\\\\\\\\**~                      |\n");
    printf(       "|                 ~**                                \\\\\\\**~                       |\n");
    printf(        "|                   ~** --__                          \\\\**~                       |\n");
    printf(        "|                     ~**,. ~~--__                    ||**~                       |\n");
    printf(        "|                       ~****;,.. ~~~---____         .**~                         |\n");
    printf(        "|                         ~************;,.. ~~~~~~~.**~                           |\n");
    printf(        "|                          ~***********************~                              |\n");
    printf(        "|                           ~*******************~                                 |\n");
    printf(        "|                            ~***************~                                    |\n");
    printf(        "|                               ~*******~                                         |\n");
    printf(       "|                                 ~***~                                           |\n");
    printf(       "|                                  `*'                                            |\n");
    printf(" ----------------------------------------------------------------------------------\n");


        i--;
        sleep(1);
    }
}

void mostrarGanado(int puntos)
{
    stTrofeo t;
    if(puntos>0)
    {
        t.trofeo1=1;
        animacionSaludo();
        system("CLS");
        printf(AMARILLO_T"OBTUVISTE EL TROFEO : LOVE COUPLES"RESET_COLOR);
        mostrarTrofeoTextoUno(t);
    }
    else if(puntos<0)
    {
        t.trofeo2=1;
        animaciondespedida();
        system("CLS");
        printf(AMARILLO_T"OBTUVISTE EL TROFEO : CAMBIO DE PLANES"RESET_COLOR);
        mostrarTrofeoTextoDos(t);
    }
    else if(puntos==0)
    {
        t.trofeo3=1;
        system("CLS");
        printf(AMARILLO_T"OBTUVISTE EL TROFEO : COMO LLEGASTE A ESTO?"RESET_COLOR);
        mostrarTrofeoTextoTres(t);
    }
}

void animacionSaludo()
{
      int i=22;
      int j=34;
    while(i<26)
    {

        system("cls");
        gotoxy(18,7);
        printf("-----------------------------\n");
        gotoxy(i,4);
        printf("    0 \n");
        gotoxy(i,5);
        printf("   /|\\ \n");
        gotoxy(i,6);
        printf("   / \\  \n");
        gotoxy(j,4);
        printf("    0 \n");
        gotoxy(j,5);
        printf("   /|\\ \n");
        gotoxy(j,6);
        printf("   / \\  \n");
        i++;
        j--;
        sleep(1);
    }
    gotoxy(29,0);
    printf(" __ __");
    gotoxy(29,1);
    printf("(  v  )");
    gotoxy(29,2);
    printf(" \\   /");
    gotoxy(29,3);
    printf("  \\_/");
    sleep(1);
    system("cls");
    gotoxy(29,3);
    printf("Love Couples\n");
    sleep(0,9);
    gotoxy(29,4);
    printf("Love Couples\n");
    sleep(1);
    gotoxy(29,5);
    printf("Love Couples\n");
    sleep(1);
    gotoxy(29,6);
    printf("Love Couples\n");
    sleep(1);
    gotoxy(29,7);
    printf("Love Couples\n");
    sleep(1);
    gotoxy(29,8);
    printf("Love Couples\n");
    sleep(1);
    gotoxy(29,3);
    printf("             \n");
    sleep(0,9);
    gotoxy(29,4);
    printf("             \n");
    sleep(1);
    gotoxy(29,5);
    printf("             \n");
    sleep(1);
    gotoxy(29,6);
    printf("             \n");
    sleep(1);
    gotoxy(29,7);
    printf("             \n");
    sleep(1);
    gotoxy(29,8);
    printf("             \n");
    sleep(1);
}

void animaciondespedida()
{
      int i=22;
      int j=34;
    while(i>15)
    {

        system("cls");
        gotoxy(10,7);
        printf("----------------------------------------\n");
        gotoxy(i,4);
        printf("    0 \n");
        gotoxy(i,5);
        printf("   /|\ \n");
        gotoxy(i,6);
        printf("   / \  \n");
        gotoxy(j,4);
        printf("    0 \n");
        gotoxy(j,5);
        printf("   /|\ \n");
        gotoxy(j,6);
        printf("   / \  \n");
        i--;
        j++;
        sleep(1);
    }
    sleep(1);
    system("cls");
    gotoxy(29,3);
    printf("No Love Couples\n");
    sleep(0,9);
    gotoxy(29,4);
    printf("No Love Couples\n");
    sleep(1);
    gotoxy(29,5);
    printf("No Love Couples\n");
    sleep(1);
    gotoxy(29,6);
    printf("No Love Couples\n");
    sleep(1);
    gotoxy(29,7);
    printf("No Love Couples\n");
    sleep(1);
    gotoxy(29,8);
    printf("No Love Couples\n");
    sleep(1);
    gotoxy(29,3);
    printf("             \n");
    sleep(0,9);
    gotoxy(29,4);
    printf("             \n");
    sleep(1);
    gotoxy(29,5);
    printf("             \n");
    sleep(1);
    gotoxy(29,6);
    printf("             \n");
    sleep(1);
    gotoxy(29,7);
    printf("             \n");
    sleep(1);
    gotoxy(29,8);
    printf("             \n");
    sleep(1);
}
