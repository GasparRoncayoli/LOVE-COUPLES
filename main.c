#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "juego.h"
 int INIC = 0;
char usuario[30]={};
stHistorial his;

int main()
{   /**INICIAR SESION**/

    nodoDobleUser * user= inicListaUser();
    while(INIC==0)
    {
        iniciarSesion(usuario);

        INIC=1;
    }
    user = crearNodoUser(usuario);

   /**MENU**/
    system ("cls");
    int posicion = 1;
    int teclaApretada = 0;

    while(teclaApretada != 13)
    {
    system ("cls");
    imgPareja();

        apuntaFlecha(1,posicion);               /// MUESTRA COLOREADO LA SELECCION
        if(posicion == 1)
        {
            gotoxy(90,3);
            printf(ROJO_F "START \n" RESET_COLOR); // ingresar al juego
        }
        else
        {
            gotoxy(90,3);
            printf("Start \n");
        }

        apuntaFlecha(2,posicion);
        if(posicion == 2)
        {
            gotoxy(90,6);
            printf(ROJO_F "I N S T R U C C I O N E S \n" RESET_COLOR); // instrucciones
        }
        else
        {
            gotoxy(90,6);
            printf("Instrucciones \n");
        }

        apuntaFlecha(3,posicion);
        if(posicion == 3)
        {
;            gotoxy(90,9);
            printf(ROJO_F "L O G R O S \n" RESET_COLOR); // logros
        }
        else
        {
           gotoxy(90,9);
            printf("Logros \n");
        }

        apuntaFlecha(4,posicion);
        if(posicion == 4)
        {
            gotoxy(90,12);
            printf(ROJO_F "H I S T O R I A L \n" RESET_COLOR); // historial
        }
        else
        {
            gotoxy(90,12);
            printf("Historial \n");
        }
         apuntaFlecha(5,posicion);
         if(posicion == 5)
        {
            gotoxy(90,15);
            printf(ROJO_F "S A L I R \n" RESET_COLOR); // salir
        }
        else
        {
            gotoxy(90,15);
            printf("Salir \n");
        }                                           /// FIN DE MOSTRAR COLOREADO LA SELECCION

        teclaApretada = getch();

        posicion = flecha(teclaApretada, posicion);
    }

    seleccion(teclaApretada, posicion, &his, user);

   return 0;
}
