
#include "arbolesFinal.h"


int recorrer(nodoPregunta *arbol, int puntos);
int decision(nodoPregunta *arbol);
void gotoxy(int x, int y);
void mostrarDialogo(char pregunta[]);
int seleccionPuntos(int teclaApretada, int posicion,stPregunta puntos);
void apuntaFlecha (int posicionReal, int posicionFlecha);
int menuIngame(stPregunta aux);
void retornarMinita(char  nombre[]);
void game(char user[]);
stHistorial startGame();

