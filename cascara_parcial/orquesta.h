#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct
{
    int IdOrquesta;
    char nombre[31];
    char lugar[31];
    int tipo;
    int isEmpty;

} Orquesta;

///int informar (Orquesta* orquestas,int length);
int orq_promedio (Orquesta* orquestas, int length);
int orq_empty (Orquesta *orquestas, int length);
int orq_inicializar(Orquesta* orquestas, int length);
int orq_alta(Orquesta* orquestas, char *msgError,int length);
int orq_lugarLibre (Orquesta* orquestas, int length, int *posLibre);
int orq_modificar (Orquesta* orquestas, int length,int*id);
int orq_buscarPorId (Orquesta* orquestas,char *msg,char *msgError, int length, int *id);
int orq_baja (Orquesta* orquestas, int length);
int orq_mostrar(Orquesta* orquestas, int length);
int orq_ordenar (Orquesta* orquestas,int length);
void orq_mock(Orquesta* orquestas, int length,int *contadorId);



#endif // ORQUESTA_H_INCLUDED
