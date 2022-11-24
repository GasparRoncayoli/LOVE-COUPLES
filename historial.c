#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "login.h"
#define LOG "logros.dat"
#include "colores.h"
/** FUNCIONES LISTA DE USUARIOS **/
nodoDobleUser * cargarListaUser(nodoDobleUser * listaUser)
{
    FILE * arch = fopen(USER, "rb");
    nodoDobleUser * aux;
    if(arch !=NULL)
    {
        while (fread(&aux, sizeof(nodoDobleUser), 1, arch)>0)
        {
            listaUser = agregarUser(listaUser, aux);
        }
    }
    return listaUser;
}

nodoDobleUser * inicListaUser()
{
    return NULL;
}


nodoDobleUser * crearNodoUser(char nombreUser[])
{
    nodoDobleUser * nuevo = (nodoDobleUser*) malloc(sizeof(nodoDobleUser));


    strcpy(nuevo->user, nombreUser);
    strcpy(nuevo->password, "0");
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    nuevo->historial = inicFila();

    return nuevo;
}

nodoDobleUser * agregarUser(nodoDobleUser * lista, nodoDobleUser * nuevo)
{
    if(lista==NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->sig = lista;
        lista->ant = nuevo;
        lista = nuevo;
    }
    return lista;
}

/** FUNCIONES fila DE PARTIDAS**/
nodoFila * inicNodoFila()
{
    return NULL;
}
fila inicFila()
{
    fila f;
    f.fin=inicNodoFila();
    f.inicio=inicNodoFila();
    return f;
}
nodoFila * crearNodoFila(stHistorial hi)
{

    nodoFila * nuevo = (nodoFila*) malloc(sizeof(nodoFila));
    nuevo->historial = hi;
    nuevo->sig = NULL;
    nuevo->ant = NULL;


    return nuevo;
}

fila agregarHistorial(fila f, stHistorial hi)//agrega la fila
{

    nodoFila * nuevo=crearNodoFila(hi);


    if(f.inicio==NULL)
    {
        f.inicio=nuevo;
        f.fin=nuevo;
    }
    else
    {
        f.fin->sig = nuevo;
        nuevo->ant = f.fin;
        f.fin = nuevo;
    }
    return f;
}

nodoFila* intercambioFinal(nodoFila* fin, nodoFila* nuevo)
{
    fin->sig=nuevo;
    nuevo->ant=fin;
    return nuevo;
}

stHistorial devolverUno (fila *f)//extraer
{

    stHistorial aux;
    if (f->inicio!=NULL)
    {
        aux=f->inicio->historial;
        f->inicio=f->inicio->sig;
        if (f->inicio==NULL)
        {
            f->fin=NULL;
        }
    }
    return aux;
}

void mostrarLista(nodoDobleUser * user)
{
    while(user!=NULL)
    {
        printf(ROJO_T"\n------------------------------------------\n"RESET_COLOR);
        printf(MAGENTA_F"\n%s\n"RESET_COLOR, user->user);
        motrarFila(user->historial);
        printf(ROJO_T"\n------------------------------------------\n"RESET_COLOR);
        user = user->sig;
    }
}
void motrarFila (fila f)
{
    stHistorial aux;
    fila auxFi=inicFila();
    while(f.inicio!=NULL)
    {
        aux=devolverUno(&f);
        mostrarHistorial(aux);
    }

}
void mostrarHistorial(stHistorial hi)
{
    printf("\n Estilo: %s", hi.estilo);
    printf("\n Pretendiente: %s", hi.pretendiente);
    printf("\n Puntaje: %i\n",hi.puntajeObtenido);


}

/** ALTA **/
nodoDobleUser* buscarUserEnLista(nodoDobleUser*lista, char nombre[])
{
    nodoDobleUser* aux;
    if((lista!=NULL) && (strcmp(lista->user,nombre)!=0))
    {
        aux=buscarUserEnLista(lista->sig,nombre);
    }
    else
    {
        aux=lista;
    }
    return aux;
}

nodoDobleUser * altaLDF (nodoDobleUser * listaUser, char nombreUser[], stHistorial hi)
{
    nodoDobleUser * seg = buscarUserEnLista(listaUser, nombreUser);

    if(seg==NULL)
    {
        nodoDobleUser * nuevo= crearNodoUser(nombreUser);
        listaUser = agregarUser(listaUser, nuevo);
        listaUser->historial = agregarHistorial(listaUser->historial, hi);
    }
    else
    {
        seg->historial = agregarHistorial(seg->historial, hi);


    }
    return listaUser;
}

/** CONVERTIR A REGISTRO **/
registroHistorial convertirRegistroHis(nodoDobleUser * user, stHistorial h)
{
    registroHistorial a;
    strcpy(a.user, user->user);
    strcpy(a.estilo, h.estilo);
    strcpy(a.pretendiente, h.pretendiente);
    a.puntajeObtenido = h.puntajeObtenido;

    return a;
}
/** CARGAR ARCHIVO HISTORIAL **/
void cargarHistorial(nodoDobleUser * lista)
{
    FILE * arch = fopen(REG, "ab");
    registroHistorial a;
    stHistorial aux;
    if (arch!=NULL)
    {

        while(lista!=NULL)
        {
            while((lista->historial.inicio)!=NULL)
            {
                aux = devolverUno(&lista->historial); //devolver uno elimina el primer dato
                a = convertirRegistroHis(lista, aux);

                fwrite(&a, sizeof(registroHistorial), 1, arch);
            }
            lista = lista->sig;
        }
        fclose(arch);
    }
}
stHistorial convertirSthistorial(registroHistorial aux)
{
    stHistorial nuevo;
    strcpy(nuevo.estilo,aux.estilo);
    strcpy(nuevo.pretendiente,aux.pretendiente);
    nuevo.puntajeObtenido = aux.puntajeObtenido;
    return nuevo;
}

nodoDobleUser * descargarHistorial()
{
    FILE * arch = fopen(REG, "rb");
    registroHistorial a;
    stHistorial aux;
    nodoDobleUser * nuevo = inicListaUser();
    if (arch!=NULL)
    {
        while(fread(&a,sizeof(registroHistorial),1,arch)>0)
        {

          nuevo = altaLDF(nuevo,a.user,convertirSthistorial(a));

        }
        fclose(arch);
    }
    return nuevo;
}


registroLogros convertirToRegistroLogros(nodoDobleUser * user, stTrofeo x)
{
    registroLogros aux;

    strcpy(aux.user, user);
    aux.trofeo1= x.trofeo1;
    aux.trofeo2= x.trofeo2;
    aux.trofeo3= x.trofeo3;

    return aux;
}
void cargarLogros(nodoDobleUser * user)
{
    FILE * arch = fopen(LOG, "ab");
    registroLogros x;

    if(arch!=NULL)
    {
        x = convertirToRegistroLogros(user, user->logros);
        fwrite(&x, sizeof(registroLogros), 1, arch);
    }
    fclose(arch);
}

stTrofeo buscarLogros(nodoDobleUser * user)
{
    FILE * arch = fopen(LOG, "rb");
    registroLogros x;
    stTrofeo a;
    if(arch!=NULL)
    {
        while(fread(&x, sizeof(registroLogros), 1, arch)>0)
        {
            if((strcmp(x.user, user->user)==0))
               {
                   a.trofeo1 = x.trofeo1;
                   a.trofeo2 = x.trofeo2;
                   a.trofeo3 = x.trofeo3;
               }
        }
    fclose(arch);
    }

    return a;
}
