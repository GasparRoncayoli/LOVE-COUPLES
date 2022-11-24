#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "trofeo.h"
#include "colores.h"
void mostrarTrofeoUno()
{
    printf(" ___________\n");
    printf("|  Trofeo 1 |\n");
    printf("|    ##     |\n");
    printf("|  # ##     |\n");
    printf("|    ##     |\n");
    printf("|    ##     |\n");
    printf("|   ####    |\n");
    printf("|___________|\n");
}

void mostrarTrofeoDos()
{
    printf(" ___________\n");
    printf("|  Trofeo 2 |\n");
    printf("|   #####   |\n");
    printf("|  #   ###  |\n");
    printf("|     ###   |\n");
    printf("|   ###     |\n");
    printf("|  ######## |\n");
    printf("|___________|\n");
}

void mostrarTrofeoTres()
{
    printf(" ___________\n");
    printf("|  Trofeo 3 |\n");
    printf("|  ######   |\n");
    printf("|       #   |\n");
    printf("|  ######   |\n");
    printf("|       #   |\n");
    printf("|  ######   |\n");
    printf("|___________|\n");
}

void mostrarTrofeoCuatro()
{
    printf(" \n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
}

void mostrarTrofeoTextoUno(stTrofeo P)
{
    if(P.trofeo1==1)
    {
    printf("\n");
    printf(AMARILLO_T "    Love    \n "RESET_COLOR);
    printf(AMARILLO_T "   Couples  \n"RESET_COLOR);
    printf(AMARILLO_T " ___________\n"RESET_COLOR);
    printf(AMARILLO_T "|  Trofeo 1 |\n"RESET_COLOR);
    printf(AMARILLO_T "|Conseguiste|\n"RESET_COLOR);
    printf(AMARILLO_T "|Enamorar   |\n"RESET_COLOR);
    printf(AMARILLO_T "|A  la      |\n"RESET_COLOR);
    printf(AMARILLO_T "|Chica      |\n"RESET_COLOR);
    printf(AMARILLO_T "|           |\n"RESET_COLOR);
    printf(AMARILLO_T "|___________|\n"RESET_COLOR);
    manosAmor();
    }
    else
    {
    printf(ROJO_T" ___________\n"RESET_COLOR);
    printf(ROJO_T"| x     x   |\n"RESET_COLOR);
    printf(ROJO_T"|  x   x    |\n"RESET_COLOR);
    printf(ROJO_T"|   x x     |\n"RESET_COLOR);
    printf(ROJO_T"|    x      |\n"RESET_COLOR);
    printf(ROJO_T"|   x  x    |\n"RESET_COLOR);
    printf(ROJO_T"|  x    x   |\n"RESET_COLOR);
    printf(ROJO_T"|_x______x__|\n"RESET_COLOR);
    }
}

void mostrarTrofeoTextoDos(stTrofeo P)
{
    if(P.trofeo2==1)
    {
    printf(AMARILLO_T"   Partner  \n"RESET_COLOR);
    printf(AMARILLO_T"    swap    \n"RESET_COLOR);
    printf(AMARILLO_T" ___________\n"RESET_COLOR);
    printf(AMARILLO_T"|  Trofeo 2 |\n"RESET_COLOR);
    printf(AMARILLO_T"|Conseguiste|\n"RESET_COLOR);
    printf(AMARILLO_T"|Ser Odiado |\n"RESET_COLOR);
    printf(AMARILLO_T"|Por la     |\n"RESET_COLOR);
    printf(AMARILLO_T"|Chica      |\n"RESET_COLOR);
    printf(AMARILLO_T"|           |\n"RESET_COLOR);
    printf(AMARILLO_T"|___________|\n"RESET_COLOR);
    brokenHeart();
    }
    else
    {
    printf(ROJO_T" ___________\n"RESET_COLOR);
    printf(ROJO_T"| x     x   |\n"RESET_COLOR);
    printf(ROJO_T"|  x   x    |\n"RESET_COLOR);
    printf(ROJO_T"|   x x     |\n"RESET_COLOR);
    printf(ROJO_T"|    x      |\n"RESET_COLOR);
    printf(ROJO_T"|   x  x    |\n"RESET_COLOR);
    printf(ROJO_T"|  x    x   |\n"RESET_COLOR);
    printf(ROJO_T"|_x______x__|\n"RESET_COLOR);
    }
}

void mostrarTrofeoTextoTres(stTrofeo P)
{
    if(P.trofeo3==1)
    {
    printf(AMARILLO_T"  Pacto de  \n "RESET_COLOR);
    printf(AMARILLO_T"   Muerte   \n"RESET_COLOR);
    printf(AMARILLO_T" ___________\n"RESET_COLOR);
    printf(AMARILLO_T"|  Trofeo 3 |\n"RESET_COLOR);
    printf(AMARILLO_T"|Conseguiste|\n"RESET_COLOR);
    printf(AMARILLO_T"|Que ambos  |\n"RESET_COLOR);
    printf(AMARILLO_T"|Fallecieran|\n"RESET_COLOR);
    printf(AMARILLO_T"|           |\n"RESET_COLOR);
    printf(AMARILLO_T"|           |\n"RESET_COLOR);
    printf(AMARILLO_T"|___________|\n"RESET_COLOR);
    //meme();
    }
    else
    {
    printf(ROJO_T" ___________\n"RESET_COLOR);
    printf(ROJO_T"| x     x   |\n"RESET_COLOR);
    printf(ROJO_T"|  x   x    |\n"RESET_COLOR);
    printf(ROJO_T"|   x x     |\n"RESET_COLOR);
    printf(ROJO_T"|    x      |\n"RESET_COLOR);
    printf(ROJO_T"|   x  x    |\n"RESET_COLOR);
    printf(ROJO_T"|  x    x   |\n"RESET_COLOR);
    printf(ROJO_T"|_x______x__|\n"RESET_COLOR);
    }
}

void mostrarTrofeoTextoCuatro(stTrofeo P)
{
    if((P.trofeo1==1) && (P.trofeo2==1) && (P.trofeo3==1))
    {

    printf(AMARILLO_T"   Maestro  \n "RESET_COLOR);
    printf(AMARILLO_T"   Gigolo   \n"RESET_COLOR);
    printf(AMARILLO_T" ___________\n"RESET_COLOR);
    printf(AMARILLO_T"|  Trofeo 4 |\n"RESET_COLOR);
    printf(AMARILLO_T"|Conseguiste|\n"RESET_COLOR);
    printf(AMARILLO_T"|Todos los  |\n"RESET_COLOR);
    printf(AMARILLO_T"|Logros     |\n"RESET_COLOR);
    printf(AMARILLO_T"|           |\n"RESET_COLOR);
    printf(AMARILLO_T"|           |\n"RESET_COLOR);
    printf(AMARILLO_T"|___________|\n"RESET_COLOR);
    gotoxy(0,0);
    mostrarTrofeoTextoUno(P);
    gotoxy(0,10);
    mostrarTrofeoTextoDos(P);
    gotoxy(0,20);
    mostrarTrofeoTextoTres(P);
    }
    else
    {
    printf("        \n");
    }
}

void brokenHeart()
{
    gotoxy(30,10);
    printf(AMARILLO_T"  0  0     0  0    \n"RESET_COLOR);
    gotoxy(30,11);
    printf(AMARILLO_T" 0     0 0     0 \n"RESET_COLOR);
    gotoxy(30,12);
    printf(AMARILLO_T" 0      0      0 \n"RESET_COLOR);
    gotoxy(30,13);;
    printf(AMARILLO_T"  0     /      0 \n"RESET_COLOR);
    gotoxy(30,14);
    printf(AMARILLO_T"   0    \\     0\n"RESET_COLOR);
    gotoxy(30,15);
    printf(AMARILLO_T"    0   /   0\n"RESET_COLOR);
    gotoxy(30,16);
    printf(AMARILLO_T"      0 \ 0 \n"RESET_COLOR);
    gotoxy(30,17);
    printf(AMARILLO_T"        0 \n"RESET_COLOR);
}

void manosAmor()
{
gotoxy(30,0);
printf(AMARILLO_T"____________36936936936936936\n"RESET_COLOR);
gotoxy(30,1);
printf(AMARILLO_T"____________36936936936936936\n"RESET_COLOR);
gotoxy(30,2);
printf(AMARILLO_T"____________369369369369369369\n"RESET_COLOR);
gotoxy(30,3);
printf(AMARILLO_T"___________36936936936936933693\n"RESET_COLOR);
gotoxy(30,4);
printf(AMARILLO_T"__________3693693693693693693693\n"RESET_COLOR);
gotoxy(30,5);
printf(AMARILLO_T"_________369369369369369369369369\n"RESET_COLOR);
gotoxy(30,6);
printf(AMARILLO_T"_________3693693693693693693693699\n"RESET_COLOR);
gotoxy(30,7);
printf(AMARILLO_T"________3693693693693693693693699369\n"RESET_COLOR);
gotoxy(30,8);
printf(AMARILLO_T"_______36936939693693693693693693693693\n"RESET_COLOR);
gotoxy(30,9);
printf(AMARILLO_T"_____3693693693693693693693693693693636936\n"RESET_COLOR);
gotoxy(30,10);
printf(AMARILLO_T"___36936936936936936936936936936___369369369\n"RESET_COLOR);
gotoxy(30,11);
printf(AMARILLO_T"__36936___369336936369369369369________36936\n"RESET_COLOR);
gotoxy(30,12);
printf(AMARILLO_T"_36936___36936_369369336936936__抖__抖\n"RESET_COLOR);
gotoxy(30,13);
printf(AMARILLO_T"36933___36936__36936___3693636_抖抖抖抖\n"RESET_COLOR);
gotoxy(30,14);
printf(AMARILLO_T"693____36936__36936_____369363_抖抖抖抖\n"RESET_COLOR);
gotoxy(30,15);
printf(AMARILLO_T"______36936__36936______369369__抖抖抖\n"RESET_COLOR);
gotoxy(30,16);
printf(AMARILLO_T"_____36936___36936_______36936___抖抖\n"RESET_COLOR);
gotoxy(30,17);
printf(AMARILLO_T"_____36936___36936________36936___抖\n"RESET_COLOR);
gotoxy(30,18);
printf(AMARILLO_T"_____36936___36936_________36936___11,\n"RESET_COLOR);
gotoxy(30,19);
printf(AMARILLO_T"______369____36936__________369___11,\n"RESET_COLOR);
gotoxy(30,20);
printf(AMARILLO_T"______________369________________11,\n"RESET_COLOR);
gotoxy(30,21);
printf(AMARILLO_T"_______________________________11,\n"RESET_COLOR);
gotoxy(30,22);
printf(AMARILLO_T"____________________________11,\n"RESET_COLOR);
gotoxy(30,23);
printf(AMARILLO_T"___________________________11,\n"RESET_COLOR);
gotoxy(30,24);
printf(AMARILLO_T"________________________抖禵抖禱n"RESET_COLOR);
gotoxy(30,25);
printf(AMARILLO_T"_______________________抖抖抖抖禱n"RESET_COLOR);
gotoxy(30,26);
printf(AMARILLO_T"_______________________抖抖抖抖禱n"RESET_COLOR);
gotoxy(30,27);
printf(AMARILLO_T"________________________抖抖抖禱n"RESET_COLOR);
gotoxy(30,28);
printf(AMARILLO_T"_________________________抖抖禱n"RESET_COLOR);
gotoxy(30,29);
printf(AMARILLO_T"__________________________抖禱n"RESET_COLOR);
gotoxy(30,30);
printf(AMARILLO_T"___________________________禱n"RESET_COLOR);
gotoxy(30,31);
printf(AMARILLO_T"______________________________11,\n"RESET_COLOR);
gotoxy(30,32);
printf(AMARILLO_T"________________________________11,\n"RESET_COLOR);
gotoxy(30,33);
printf(AMARILLO_T"__________________________________11,\n"RESET_COLOR);
gotoxy(30,34);
printf(AMARILLO_T"___________________________________11,\n"RESET_COLOR);
gotoxy(30,35);
printf(AMARILLO_T"___________________________________11,\n"RESET_COLOR);
gotoxy(30,36);
printf(AMARILLO_T"__________________________________11,\n"RESET_COLOR);
gotoxy(30,37);
printf(AMARILLO_T"_________________________________11,\n"RESET_COLOR);
gotoxy(30,38);
printf(AMARILLO_T"_______________________________11,\n"RESET_COLOR);
gotoxy(30,39);
printf(AMARILLO_T"___________________________抖__抖\n"RESET_COLOR);
gotoxy(30,40);
printf(AMARILLO_T"__________________________抖抖抖抖\n"RESET_COLOR);
gotoxy(30,41);
printf(AMARILLO_T"__________________________抖抖抖抖\n"RESET_COLOR);
gotoxy(30,42);
printf(AMARILLO_T"___________________________抖抖抖\n"RESET_COLOR);
gotoxy(30,43);
printf(AMARILLO_T"____________________________ 抖禱n"RESET_COLOR);
gotoxy(30,44);
printf(AMARILLO_T"_____________________________ 禱n"RESET_COLOR);
gotoxy(30,45);
printf(AMARILLO_T"____________________________11,\n"RESET_COLOR);
gotoxy(30,46);
printf(AMARILLO_T"__________________________11,\n"RESET_COLOR);
gotoxy(30,47);
printf(AMARILLO_T"_________________________11,\n"RESET_COLOR);
gotoxy(30,48);
printf(AMARILLO_T"___________________________11,\n"RESET_COLOR);
gotoxy(30,49);
printf(AMARILLO_T"_____________________________11,\n"RESET_COLOR);
gotoxy(30,50);
printf(AMARILLO_T"________________________________11,\n"RESET_COLOR);
gotoxy(30,51);
printf(AMARILLO_T"__________________________________11,\n"RESET_COLOR);
gotoxy(30,52);
printf(AMARILLO_T"______________369___________________11,\n"RESET_COLOR);
gotoxy(30,53);
printf(AMARILLO_T"______369____36936__________369_____11,\n"RESET_COLOR);
gotoxy(30,54);
printf(AMARILLO_T"_____36936___36936_________36936___11,\n"RESET_COLOR);
gotoxy(30,55);
printf(AMARILLO_T"_____36936___36936________36936___11,\n"RESET_COLOR);
gotoxy(30,56);
printf(AMARILLO_T"_____36936___36936_______36936___11,\n"RESET_COLOR);
gotoxy(30,57);
printf(AMARILLO_T"______36936__36936______369369 _抖_抖\n"RESET_COLOR);
gotoxy(30,58);
printf(AMARILLO_T"693____36936__36936_____369363 抖抖抖禱n"RESET_COLOR);
gotoxy(30,59);
printf(AMARILLO_T"36933___36936__36936___3693636 抖抖抖禱n"RESET_COLOR);
gotoxy(30,60);
printf(AMARILLO_T"_36936___36936_369369336936936 _抖抖禱n"RESET_COLOR);
}

//void meme()
//{
//gotoxy(30,0);
//printf(AMARILLO_T"创创创创创创创创抖抖抖创创创创创创创创创创\n");
//gotoxy(30,2);
//printf("创创创创创创炊抖创创创抖洞创创创创创创创创\n");
//gotoxy(30,3);
//printf("创创创创创创洞创创创创创炊创创创创创创创创\n");
//gotoxy(30,4);
//printf("创创创创创抖创创创创创创创抖创创创创创创创\n");
//gotoxy(30,5);
//printf("创创创创创洞创创创创创创创炊洞创创创创创创\n");
//gotoxy(30,6);
//printf("创创创创炊创创创创创创创创创洞创创创创创创\n");
//gotoxy(30,7);
//printf("创创创创洞创创创创创创创创创炊创创创创创创\n");
//gotoxy(30,8);
//printf("创创创创抖抖抖创炊抖抖洞创创创洞创创创创创\n");
//gotoxy(30,9);
//printf("创创创炊炊抖创创创抖抖创创创创洞创创创创创\n");
//gotoxy(30,10);
//printf("创创创炊炊抖创创创抖抖创创创创洞创创创创创\n");
//gotoxy(30,11);
//printf("创创创创炊抖创创创抖抖创创创创炊创创创创创\n");
//gotoxy(30,12);
//printf("创创创洞炊抖创创创抖洞创创创炊抖创创创创创\n");
//gotoxy(30,13);
//printf("创创创洞创创创创创创创创创创创抖创创创创创\n");
//gotoxy(30,14);
//printf("创创创洞创创创创创炊抖洞创创创炊创创创创创\n");
//gotoxy(30,15);
//printf("创创创洞创创创创炊抖抖抖创创创炊创创创创创\n");
//gotoxy(30,16);
//printf("创创创炊创创创炊抖抖抖抖洞创创创洞创创创创\n");
//gotoxy(30,17);
//printf("创创创炊创创创抖抖抖抖抖抖创创炊创创创创创\n");
//gotoxy(30,18);
//printf("创创创炊创创炊抖抖抖抖洞炊创创炊创创创创创\n");
//gotoxy(30,19);
//printf("创创创创洞创创创抖抖抖洞洞炊炊洞创创创创创\n");
//gotoxy(30,20);
//printf("创创创创洞创创创创创创创创创抖创创创创创创\n");
//gotoxy(30,21);
//printf("创创创创炊创创创创创创创创创洞创创创创创创\n");
//gotoxy(30,22);
//printf("创创创创创洞创创创创创创创炊创创创创创创创\n");
//gotoxy(30,23);
//printf("创创创创创炊创创创创创创创抖创创创创创创创\n");
//gotoxy(30,24);
//printf("炊洞创创创创抖创创创创创炊抖洞创炊抖抖抖洞\n");
//gotoxy(30,25);
//printf("炊抖抖创创创创抖创创创抖洞创抖抖抖抖抖抖抖\n");
//gotoxy(30,26);
//printf("创炊抖抖抖创创创创抖创创创炊抖抖创创创创创\n");
//gotoxy(30,27);
//printf("创创创抖抖抖抖洞创创创炊抖抖抖抖抖抖创创创\n");
//gotoxy(30,28);
//printf("创创创创创炊抖抖抖抖抖抖抖抖创炊洞炊抖抖洞\n");
//gotoxy(30,29);
//printf("创创创创创创创创创创创创创炊创创洞创创创抖\n");
//gotoxy(30,30);
//printf("创创创创创创创创创创创创创炊创创抖创创炊创\n");
//gotoxy(30,31);
//printf("创创创创创创创创创创创创创炊创创炊创创炊炊\n");
//gotoxy(30,32);
//printf("创创创创创创创创创创创创创炊创创炊洞创炊炊\n");
//gotoxy(30,33);
//printf("创创创创创创创创创创创抖抖抖炊创炊洞创炊炊\n");
//gotoxy(30,34);
//printf("创创创创创创创创创炊抖洞创炊抖抖炊洞创炊抖\n");
//gotoxy(30,35);
//printf("创创创创创炊抖抖抖抖创创创抖抖抖抖抖抖抖抖\n");
//gotoxy(30,36);
//printf("创抖抖抖抖抖抖抖抖抖抖抖抖抖抖抖抖洞创炊炊\n");
//gotoxy(30,37);
//printf("抖抖抖抖创创创创创洞炊抖抖洞炊抖抖抖创炊炊\n");
//gotoxy(30,38);
//printf("创创创创创创创创创炊创创创创洞创创抖抖炊炊\n");
//gotoxy(30,39);
//printf("创创创创创创创创创创洞创创炊创创创创抖抖炊\n");
//gotoxy(30,40);
//printf("创创创创创创创创创创炊抖抖洞创创创创创抖抖碶n"RESET_COLOR);
//
//}


void verTrofeo(stTrofeo P)
{
    system ("cls");
    int posicion = 1;
    int teclaApretada = 0;

    while(teclaApretada != 13)
    {
    system ("cls");
    gotoxy(0,20);


        apuntaFlecha(1,posicion);               /// MUESTRA COLOREADO LA SELECCION
        if(posicion == 1)
        {
            gotoxy(0,0);
        mostrarTrofeoTextoUno(P);
        }
        else
        {
            gotoxy(0,0);
        mostrarTrofeoUno();
        }

        apuntaFlecha(2,posicion);
        if(posicion == 2)
        {
            gotoxy(0,10);
           mostrarTrofeoTextoDos(P);

        }
        else
        {
            gotoxy(0,10);
        mostrarTrofeoDos();
        }

        apuntaFlecha(3,posicion);
        if(posicion == 3)
        {
            gotoxy(0,20);
            mostrarTrofeoTextoTres(P);

        }
        else
        {
           gotoxy(0,20);
         mostrarTrofeoTres();
        }
        apuntaFlecha(4,posicion);
        if(posicion == 4)
        {
            gotoxy(0,30);
            mostrarTrofeoTextoCuatro(P);
        }


       /// FIN DE MOSTRAR COLOREADO LA SELECCION

        teclaApretada = getch();

        posicion = flecha(teclaApretada, posicion);
    }

}
