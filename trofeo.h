/** STRUCT**/

typedef struct{
        int trofeo1;
        int trofeo2;
        int trofeo3;
}stTrofeo;

typedef struct{
        int trofeo1;
        int trofeo2;
        int trofeo3;
        char user[30];
}registroLogros;

/** PROTOTIPADOS **/
void mostrarTrofeoUno();
void mostrarTrofeoDos();
void mostrarTrofeoTres();
void mostrarTrofeoCuatro();
void mostrarTrofeoTextoUno(stTrofeo P);
void mostrarTrofeoTextoDos(stTrofeo P);
void mostrarTrofeoTextoTres(stTrofeo P);
void mostrarTrofeoTextoCuatro(stTrofeo P);
void verTrofeo(stTrofeo P);
void brokenHeart();
void manosAmor();
void meme();

