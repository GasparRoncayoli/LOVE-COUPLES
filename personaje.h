#define PER "personaje.dat"
#define EST "estilos.dat"

/** STRCUTS **/
typedef struct{
    char nombreUser[30];
    int puntaje;
    char cabello[30];
    char ojos[30];
    char piel[30];
    char nombreEstilo[30];
    int puntoEstilo;
}registroPersonaje;

typedef struct{
    char nombreEstilo[30];
    int puntoEstilo;
    char prenda[30];
}registroEstilos;

typedef struct _nodoPrendas{
    char prenda[60];
    struct _nodoPrendas * sig;
}nodoPrendas;

typedef struct{
    char nombreEstilo[30];
    int puntoEstilo;
    nodoPrendas * listaPrendas;
}celdaEstilo;


typedef struct{
    char cabello[30];
    char ojos[30];
    char piel[30];
}stAspecto;

typedef struct{
    int puntaje;
    celdaEstilo estilo[30];
    stAspecto aspecto[30];
}stPersonaje;

/** PROTOTIPADOS**/

/** FUNCIONES ARREGLO**/
int buscarPosEstilo(celdaEstilo arr[], char buscado[], int validos);
int agregarEstilo(celdaEstilo arr[], int puntajeEstilo, char nombreEstilo[], int validos);
int alta(celdaEstilo arr[], char nombreEstilo[], int puntaje, char prenda[], int validos);
int cargarEstilos(celdaEstilo arr[]);
int descargarEstilos(celdaEstilo arr[]); //de archivo a arre
/**MOSTRAR **/
void mostrarEstilos (celdaEstilo arr[],int validos);
void mostrarUnaCelda (celdaEstilo uno, int pos);
void mostrarPrendas(nodoPrendas*lista);
void elegirCelda (celdaEstilo arr[],int validos, char estilo[]);

/** FUNCIONES LISTA **/
nodoPrendas * inicListaPrenda();
nodoPrendas * crearNodoPrenda(char prenda[]);
nodoPrendas * agregarPrenda(nodoPrendas * lista, nodoPrendas * nuevo);
