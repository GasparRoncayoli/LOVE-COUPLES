
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "personaje.h"
#include "colores.h"

/** FUNCIONES ARREGLO **/
/*int ingresarEstilo (celdaEstilo arr [], int dimension)
{

    char nombreEstilo[30];
    char prenda[30];
    int puntoEstilo = 0;
    char salir = 's';
    int validos = 0;


    for (int i = 0; i<25 ; i++)
    {
        printf("\n NOMBRE ESTILO\n");
        fflush(stdin);
        gets(nombreEstilo);

        printf("\n PUNTAJE DEL ESTILO:\n");
        scanf("%i", &puntoEstilo);

        printf("\n PRENDA\n");
        fflush(stdin);
        gets(prenda);

        validos = alta(arr, nombreEstilo, puntoEstilo, prenda, validos);
        printf("\n Desea cargar otro estilo? s/n\n");
        fflush(stdin);
        salir = getch(salir);
    }

    return validos;
}*/

int alta(celdaEstilo arr[], char nombreEstilo[], int puntaje, char prenda[], int validos)
{
    nodoPrendas * aux = crearNodoPrenda(prenda);

    int pos = buscarPosEstilo(arr, nombreEstilo , validos);
    if (pos == -1)
    {
        validos = agregarEstilo(arr, puntaje, nombreEstilo, validos);
        pos = validos - 1;
    }

    arr[pos].listaPrendas = agregarPrenda(arr[pos].listaPrendas, aux);

    return validos;
}
/** FUNCIONES ARREGLO**/
int buscarPosEstilo(celdaEstilo arr[], char buscado[], int validos)
{
    int rta = -1, i = 0;
    while((i < validos) && (rta == -1))
    {
        if(strcmpi(arr[i].nombreEstilo, buscado) == 0)
        {
            rta = i;
        }
        i++;
    }

    return rta;
}

int agregarEstilo(celdaEstilo arr[], int puntajeEstilo, char nombreEstilo[], int validos)
{
    arr[validos].puntoEstilo = puntajeEstilo;
    strcpy(arr[validos].nombreEstilo, nombreEstilo);
    validos ++;
    arr[validos].listaPrendas = inicListaPrenda();
    return validos;
}

/** FUNCIONES LISTA **/
nodoPrendas * inicListaPrenda()
{
    return NULL;
}


nodoPrendas * crearNodoPrenda(char prenda[])
{
    nodoPrendas * aux = (nodoPrendas*)malloc(sizeof(nodoPrendas));


    strcpy(aux->prenda, prenda);
    aux->sig = NULL;

    return aux;
}

nodoPrendas * agregarPrenda(nodoPrendas * lista, nodoPrendas * nuevo)
{
    if(lista==NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->sig = lista;
        lista = nuevo;
    }
    return lista;
}

/** FUNCION CARGARLO EN UN ARCHIVO**/
registroPersonaje convertirRegistroPer(stPersonaje pe)
{
    registroPersonaje a;
    a.puntaje = pe.puntaje;
    a.puntoEstilo = pe.estilo->puntoEstilo;
    strcpy(a.cabello, pe.aspecto->cabello);
    strcpy(a.ojos, pe.aspecto->ojos);
    strcpy(a.piel, pe.aspecto->piel);
    strcpy(a.nombreEstilo, pe.estilo->nombreEstilo);

    return a;
}

registroEstilos convertirRegistroEst(celdaEstilo arr)
{
    registroEstilos a;
    strcpy(a.nombreEstilo, arr.nombreEstilo);
    strcpy(a.nombreEstilo, arr.listaPrendas->prenda);
    a.puntoEstilo = arr.puntoEstilo;

    return a;
}

/*void cargarEstilos()
{
    FILE * arch = fopen(EST, "ab");
    celdaEstilo arr[5]={};
    registroEstilos a;
    int validos = 0;
    int i = 0;
    if (arch!=NULL)
    {
        validos = ingresarEstilo(arr, 5);
        while(i<validos)
        {
            while(arr[i].listaPrendas != NULL)
            {
                a = convertirRegistroEst(arr[i]);
                fwrite(&a, sizeof(registroEstilos), 1, arch);
                arr[i].listaPrendas = arr[i].listaPrendas->sig;
            }
            i++;
        }
        fclose(arch);
    }
}*/
/** DE ARCHIVO A ADL **/

int descargarEstilos(celdaEstilo arr[]) //de archivo a arre
{
    FILE * archi = fopen(EST,"rb");
    registroEstilos aux;
    int validos=0;
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(registroEstilos),1,archi)>0)
        {
            validos=alta(arr,aux.nombreEstilo,aux.puntoEstilo,aux.prenda,validos);
        }
        fclose(archi);
    }
    mostrarEstilos(arr, validos);
return validos;
}

/**MOSTRAR **/
void mostrarEstilos (celdaEstilo arr[],int validos) //muestra todos los estilos completos
{
    int i=0;
    while(i<validos)
    {
        mostrarUnaCelda(arr[i], i);
        i++;
    printf("\n");
    }
}
void mostrarUnaCelda (celdaEstilo uno, int pos)
{
        printf("\n\n******************************");
        printf("\n     | %s", uno.nombreEstilo);
        printf("\n******************************");
        mostrarPrendas(uno.listaPrendas);
}
void mostrarPrendas(nodoPrendas*lista)//muestra lista prenda
{
    if(lista!=NULL)
    {
        printf("\n%s ", lista->prenda);
        mostrarPrendas(lista->sig);
    }
}
void elegirCelda (celdaEstilo arr[],int validos, char estilo[]) //muestra y le da a elegir al usuario el estilo
{
    int pos;
    mostrarEstilos(arr, validos);
    printf("\nIgrese numero del estilos a seleccionar: ");
    scanf("%i", &pos);
    strcpy(estilo, arr[pos].nombreEstilo);
}

void elegirEstiloCelda (celdaEstilo arr[],int validos, char *estilo[])
{
    system ("cls");
    int posicion = 1;
    int teclaApretada = 0;


    while(teclaApretada != 13)
    {
    system ("cls");
    gotoxy(00,43);
    dibujoMina();


        apuntaFlecha(1,posicion);               /// MUESTRA COLOREADO LA SELECCION
        if(posicion == 1)
        {
            gotoxy(0,0);
            printf(ROJO_T"");
            mostrarUnaCelda(arr[0],0);
            printf(""RESET_COLOR);
        }
        else
        {
            gotoxy(0,0);
            mostrarUnaCelda(arr[0],0);
        }

        apuntaFlecha(2,posicion);
        if(posicion == 2)
        {
            gotoxy(0,8);
            printf(ROJO_T"");
            mostrarUnaCelda(arr[1],1);
            printf(""RESET_COLOR);
        }
        else
        {
            gotoxy(0,8);
            mostrarUnaCelda(arr[1],1);
        }

        apuntaFlecha(3,posicion);
        if(posicion == 3)
        {
            gotoxy(0,16);
            printf(ROJO_T"");
            mostrarUnaCelda(arr[2],2);
            printf(""RESET_COLOR);
        }
        else
        {
           gotoxy(0,16);
            mostrarUnaCelda(arr[2],2);
        }
        if(posicion == 4)
        {
            gotoxy(0,24);
            printf(ROJO_T"");
            mostrarUnaCelda(arr[3],3);
            printf(""RESET_COLOR);
        }
        else
        {
            gotoxy(0,24);
            mostrarUnaCelda(arr[3],3);
        }
        if(posicion == 5)
        {
            gotoxy(0,32);
            printf(ROJO_T"");
            mostrarUnaCelda(arr[4],4);
            printf(""RESET_COLOR);
        }
        else
        {
             gotoxy(0,32);
            mostrarUnaCelda(arr[4],4);
        }

       /// FIN DE MOSTRAR COLOREADO LA SELECCION

        teclaApretada = getch();

        posicion = flecha(teclaApretada, posicion);
    }

   if(posicion == 1)
   {
       strcpy(estilo,arr[0].nombreEstilo);
   }
    else if(posicion == 2)
   {
       strcpy(estilo,arr[1].nombreEstilo);
   }
    else if(posicion == 3)
   {
       strcpy(estilo,arr[3].nombreEstilo);
   }
    else if(posicion == 4)
   {
       strcpy(estilo,arr[4].nombreEstilo);
   }
   else if(posicion == 5)
   {
       strcpy(estilo,arr[5].nombreEstilo);
   }
}
