#include "personaje.h"
#include "trofeo.h"
#define REG "historial.dat"



typedef struct{
    char user[30];
    int puntajeObtenido;
    char pretendiente[30];
    char estilo[30];
}registroHistorial;

typedef struct{
    int puntajeObtenido;
    char pretendiente[30];
    char estilo[30];
}stHistorial;

typedef struct{ //nodo partida
    stHistorial historial;
    struct nodoFila* sig;
    struct nodoFila* ant;
}nodoFila;

typedef struct{
    nodoFila*inicio;
    nodoFila*fin;
}fila;

typedef struct _nodoDobleUser{
    char user[30];
    char password[30];
    stTrofeo logros;
    fila historial;

    struct _nodoDobleUser * sig;
    struct _nodoDobleUser * ant;
}nodoDobleUser;

/** FUNCIONES LISTA DE USUARIOS **/
nodoDobleUser * crearNodoUser(char nombreUser[]);
nodoDobleUser * cargarListaUser(nodoDobleUser * listaUser);
nodoDobleUser * inicListaUser();
nodoDobleUser * agregarUser(nodoDobleUser * lista, nodoDobleUser * nuevo);
/** FUNCIONES fila DE PARTIDAS**/
nodoFila * inicNodoFila();
fila inicFila();
nodoFila * crearNodoFila(stHistorial hi);
fila agregarHistorial(fila f, stHistorial hi);
nodoFila* intercambioFinal(nodoFila* fin, nodoFila* nuevo);
stHistorial devolverUno (fila *f);//extraer
void motrarFila (fila f); //muestra todo el historial
void mostrarHistorial(stHistorial hi);
void mostrarLista(nodoDobleUser * user);
/** ALTA **/
nodoDobleUser* buscarUserEnLista(nodoDobleUser*lista, char nombre[]);
nodoDobleUser * altaLDL (nodoDobleUser * listaUser, char nombreUser[], stHistorial hi);
/** CONVERTIR A REGISTRO **/
registroHistorial convertirRegistroHis(nodoDobleUser * user, stHistorial h);
/** CARGAR ARCHIVO HISTORIAL **/
void cargarHistorial(nodoDobleUser * lista);

stHistorial convertirSthistorial(registroHistorial aux);


void cargarLogros(nodoDobleUser * user);
registroLogros convertirToRegistroLogros(nodoDobleUser * user, stTrofeo x);
stTrofeo buscarLogros(nodoDobleUser * user);

