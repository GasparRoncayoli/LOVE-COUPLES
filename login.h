#define USER "usuarios.dat"
#define TAM 600


#include "historial.h"


/** PROTOTIPADOS DE LOGIN **/
void iniciarSesion(char * name[]);
void login (char name[]);
void registrarse(char name[]);
int buscarUser(char name[]);
void controlString(char x[]);
void passwordRegister(char password[], char password2[]);
int passwordCheck(char password[]);
