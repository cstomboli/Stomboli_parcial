#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED


typedef struct
{
    int codigofaniado;
    char nombre[31];
    char apellido[31];
    char sexo[2];
    char telefono[30];
    char mail[31];
    char fechaAfaniado[20];
    int isEmpty;

} Fantasma;

///int informar (Fantasma* list3,int length);
int fan_promedio (Fantasma* list3, int length);
int fan_empty (Fantasma *list3, int length);
int fan_inicializar(Fantasma* list3, int length);
int fan_alta(Fantasma* list3, char *msgError,int length);
int fan_lugarLibre (Fantasma* list3, int length, int *posLibre);
int fan_modificar (Fantasma* list3, int length,int*id);
int fan_buscarPorId (Fantasma* list3,char *msg,char *msgError, int length, int *id);
int fan_baja (Fantasma* list3, int length);
int fan_mostrar(Fantasma* list3, int length);
int fan_ordenar (Fantasma* list3,int length);

///int promedioMusicoPorOrquesta (Musico* arrayMusicos, Orquesta* arrayOrquesta,int lengthMus, int lengthOrq);


void fan_mock(Fantasma* list3, int length,int *contadorId);




#endif // FANTASMA_H_INCLUDED
