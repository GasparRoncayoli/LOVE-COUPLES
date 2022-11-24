#define HIS "historia.dat"

/** STRUCTS**/

typedef struct{
      int id;
      char pregunta [100];//printf de la pregunta o situacion

      char opcion1[50];//las opciones
      char opcion2[50];
      char opcion3[50];
      char opcion4[50];

      char resp1[50];
      char resp2[50];
      char resp3[50];
      char resp4[50];

      int punto1;//los puntos no se printeam se usan para sumar o restar en el acumulador
      int punto2;
      int punto3;
      int punto4;
}stPregunta;


typedef struct _nodoPregunta{
      stPregunta dato;
      struct nodoPregunta*der;
      struct nodoPregunta*izq;
}nodoPregunta;

/** PROTOTIPADOS **/

void cargarHistoria();
stPregunta cargarStPregunta();
nodoPregunta * descargarHistoria(nodoPregunta * arbol);
nodoPregunta * insertar(nodoPregunta * arbol, nodoPregunta * nuevo);
