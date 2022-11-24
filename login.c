#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "login.h"
#include "colores.h"

/** INICIO SESION **/
void iniciarSesion(char * name[])
{

    int num = 0;
    FILE * archi = fopen(USER, "a+b");
    nodoDobleUser user;
    if (archi != NULL)
    {

        printf("\n"
               "\n"
               "\n"
               "\n"
               "\n");
        printf("                                                      __________________________________________________________ \n"
               "                                                     |                                                          |\n"
               "                                                     |                                                          |\n"
               "                                                     |                                                          |\n"
               "                                                     |             Ingrese 1 si ya tiene cuenta                 |\n"
               "                                                     |             ------------------------------               |\n"
               "                                                     |             Ingrese 2 si desea registrarse               |\n"
               "                                                     |                                                          |\n"
               "                                                     |                                                          |\n"
               "                                                                                 ");

        scanf("%i", &num);
        while(!((num==1) || (num==2)))
        {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        Beep(100,50);
        printf("                                                                   NO TE HAGAS EL VIVO Y PONE 1 O 2\n"
               "                                                                                 ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
        scanf("%i", &num);
        }

        if (num == 1)
        {
            login(name);
        }


        if (num == 2)

        {
            registrarse(name);
        }

        fclose(archi);
    }
}

/** LOGIN **/

void login (char name[])
{
   system("cls");

   FILE * archi = fopen(USER, "a+b");
   nodoDobleUser user;
   int flag = 0, flag2=0, num =0;
    char password[TAM];
   if (archi != NULL)
   {

      while (flag == 0 || flag2 == 0)
      {
    system("cls");
    printf("\n"
           "\n"
           "\n"
           "\n"
           "\n");
    printf("                                                      __________________________________________________________ \n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                     |             Ingrese el nombre de usuario                 |\n"
           "                                                     |             ------------------------------               |\n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                                    ");
        fflush(stdin);
        gets(name);

        system("cls");

         printf("\n"
           "\n"
           "\n"
           "\n"
           "\n");
    printf("                                                      __________________________________________________________ \n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                     |                Ingrese la contraseña                     |\n"
           "                                                     |             ------------------------------               |\n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                                    ");
        fflush(stdin);
        gets(password);

        flag = buscarUser(name);
        flag2 = passwordCheck(password);

        if (flag == 1 && flag2 == 1)
        {
            break;
        }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    system("cls");
    Beep(100,50);
    printf("\n"
           "\n"
           "\n"
           "\n"
           "\n");
    printf("                                                      __________________________________________________________ \n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                     |             Usuario y/o contraseña incorrectos           |\n"
           "                                                     |                                                          |\n"
           "                                                     |             ------------------------------               |\n"
           "                                                     |             Ingrese 1 para intentar de nuevo             |\n"
           "                                                     |             Ingrese 2 para registrarse                   |\n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                                                ");

        scanf("%i",&num);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
        if (num == 2)
            {
                goto registrarse;
                registrarse: registrarse(name);

            }
        }
    fclose(archi);
   }
}

/** REGISTRARSE **/

void registrarse(char name[])
{
    system("cls");

    char password[TAM];
    char password2[TAM];
    nodoDobleUser user;



    FILE * archi = fopen(USER, "ab");

    if (archi!= NULL)
    {
    printf("\n"
           "\n"
           "\n"
           "\n"
           "\n");
    printf("                                                      __________________________________________________________ \n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                     |           Ingrese un nombre de usuario valido            |\n"
           "                                                     |             ------------------------------               |\n"
           "                                                     |                 [maximo 41 caracteres]                   |\n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                                    ");
        fflush(stdin);
        gets(name);
        controlString(name);

        while (buscarUser(name))
        {
    system("cls");
    printf("\n"
           "\n"
           "\n"
           "\n"
           "\n");
    printf("                                                      __________________________________________________________ \n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                     |           Ingrese un nombre de usuario valido            |\n"
           "                                                     |             ------------------------------               |\n"
           "                                                     |                 [maximo 41 caracteres]                   |\n"
           "                                                     |                                                          |\n"
           "                                                     |             EL NOMBRE DE USUARIO YA EXISTE               |\n"
           "                                                     |             PORFAVOR INGRESE OTRO NOMBRE                 |\n"
           "                                                     |                                                          |\n"
           "                                                                    ");
           fflush(stdin);
            gets(name);
            controlString(name);
        }

    system("cls");
    printf("\n"
           "\n"
           "\n"
           "\n"
           "\n");
    printf("                                                      __________________________________________________________ \n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                     |                 Ingrese una contraseña                   |\n"
           "                                                     |             ------------------------------               |\n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                                       ");
        fflush(stdin);
        gets(password);
        controlString(password);

        system("cls");

        printf("\n"
           "\n"
           "\n"
           "\n"
           "\n");
    printf("                                                      __________________________________________________________ \n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                     |                 Ingrese una contraseña                   |\n"
           "                                                     |             ------------------------------               |\n"
           "                                                     |                                                          |\n"
           "                                                     |                 Confirme la contraseña                   |\n"
           "                                                     |                                                          |\n"
           "                                                     |                                                          |\n"
           "                                                                       ");
        fflush(stdin);
        gets(password2);
        passwordRegister(password, password2);
        strcpy(user.user, name);
        strcpy(user.password, password);

        fwrite(&user, sizeof(nodoDobleUser), 1, archi);
        fclose(archi);
    }

}

/** FUNCIONES PARA VALIDAR**/
int buscarUser(char name[])
{
    FILE * archi = fopen(USER, "rb");
    int flag = 0;
    nodoDobleUser  user;

    if (archi != NULL)
    {
        while (fread(&user, sizeof(nodoDobleUser), 1, archi) > 0 && flag == 0)
            {
                if (strcmpi(name, user.user) == 0)
                {
                    flag = 1;
                }

            }
    fclose(archi);
    }

    return flag;
}

void controlString(char x[])
{

    while (strlen(x) > TAM)
    {
        printf("\n\t\t\t\t\t\t\t\t\t\t\t MAXIMO DE CARACTERES SUPERADO, VUELVE A INTENTARLO.\n");
        fflush(stdin);
        gets(x);
    }
}

void passwordRegister(char password[], char password2[])
{
    while(strcmp(password, password2)!=0)
    {
        printf("                                                     |    Las contraseñas no coinciden, vuelve a intentarlo:    |\n");

        printf("                                                     |                 Ingrese una contraseña:                  |\n");
        fflush(stdin);
        gets(password);
        controlString(password);

        printf("                                                     |                 Confirme la contraseña:                  |\n");
        fflush(stdin);
        gets(password2);
        controlString(password2);

    }
}

int passwordCheck(char password[])
{
    FILE * archi = fopen(USER, "rb");
    nodoDobleUser  user;
    int flag = 0;

    if (archi!= NULL)
    {
        while (fread(&user, sizeof(nodoDobleUser), 1, archi) > 0 && flag == 0)
        {
            if (strcmp(password, user.password) == 0 )
            {
                flag = 1;
            }

        }
    fclose(archi);
    }


    return flag;
}
