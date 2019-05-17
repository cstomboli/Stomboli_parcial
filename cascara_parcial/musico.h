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

///int informar (Musico* list3,int length);
int mus_promedio (Musico* list3, int length);
int mus_empty (Musico *list3, int length);
int mus_inicializar(Musico* list3, int length);
int mus_alta(Orquesta* listado, Instrumento* list2, Musico* list3, char *msgError,int length3, int length2,int length);
int mus_lugarLibre (Musico* list3, int length, int *posLibre);
int mus_modificar (Musico* list3, int length,int*id);
int mus_buscarPorId (Musico* list3,char *msg,char *msgError, int length, int *id);
int mus_baja (Musico* list3, int length);
int mus_mostrar(Musico* list3, int length);
int mus_ordenar (Musico* list3,int length);
void mus_mock(Musico* list3, int length,int *contadorId);


#endif // MUSICO_H_INCLUDED
