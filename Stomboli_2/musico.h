#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#include "instrumento.h"
#include "orquesta.h"

typedef struct
{
    int IdMusico;
    char nombre[31];
    char apellido[31];
    int edad;
    int IdOrquesta;
    int IdInstrumento;
    int isEmpty;

} Musico;

int mus_empty (Musico *list3, int length);
int mus_inicializar(Musico* list3, int length);
int mus_alta(Orquesta* listado, Instrumento* list2, Musico* list3, char *msgError,int length3, int length2,int length);
int mus_lugarLibre (Musico* list3, int length, int *posLibre);
int mus_modificar (Instrumento* instrumentos, Musico* list3, int length, int lengthInstru,int*id);
int mus_bajaPorOrquesta(Musico* list3, int length, int *id);
int mus_buscarPorIddeBaja (Musico* list3, int length, int *id);
int mus_buscarPorId (Musico* list3,char *msg,char *msgError, int length, int *id);
int mus_baja (Instrumento* instrumentos,Musico* list3, int length, int lengthIns);
int mus_mostrar(Instrumento*intrumentos, Musico* list3, int length, int lengthInstrume);
void mus_mock(Instrumento* instrumentos, Musico* list3, int length, int lengthInstrume);


#endif // MUSICO_H_INCLUDED
