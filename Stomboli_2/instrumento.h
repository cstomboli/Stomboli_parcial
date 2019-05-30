#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

typedef struct
{
    int IdInstrumento;
    char nombre[31];
    int tipo;
    int isEmpty;

} Instrumento;

int ins_empty (Instrumento *instrumentos, int length);
int ins_inicializar(Instrumento* instrumentos, int length);
int ins_alta(Instrumento* instrumentos, char *msgError,int lengthint);
int ins_lugarLibre (Instrumento* instrumentos, int length, int *posLibre);
int ins_buscarPorId (Instrumento* instrumentos,char *msg,char *msgError, int length, int *id);
int ins_baja (Instrumento* instrumentos, int length);
int ins_mostrarId(Instrumento* instrumentos, int length, int id);
int ins_mostrar(Instrumento* instrumentos, int length);
void ins_mock(Instrumento* instrumentos, int length);


#endif // INSTRUMENTO_H_INCLUDED
