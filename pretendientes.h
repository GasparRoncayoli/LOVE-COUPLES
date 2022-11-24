#define PRE "minitas"

/** STRUCTS**/
typedef struct{
    char nombre[30];
    char descripcion[1000];
    char genero[30];
}stPretendientes;

typedef struct _nodoPretendientes{
    stPretendientes dato;
    struct _nodoPretendientes * sig;
}nodoPretendientes;


/** PROTOTIPADOS **/

nodoPretendientes * crearNodoPrete(stPretendientes aux);
nodoPretendientes * agregarPrincipioPrete(nodoPretendientes *lista,nodoPretendientes *nuevo);
nodoPretendientes * descargarMinitas();
void dibujoMina();
void mostrarMinita(stPretendientes aux);
void mostrarMinita2(stPretendientes aux);
void elegirMinita(nodoPretendientes * uno,nodoPretendientes * dos, nodoPretendientes * tres, char * aux[]);
stPretendientes seleccionarWacha();

