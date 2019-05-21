#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

void informes (Orquesta* orquestas, int lengthOr, Instrumento* instrumentos, int lengthIns, Musico* list3, int lengthMus);


int orq_cantidadTipo (Orquesta* orquestas, int length);
int orq_cantidad (Orquesta* orquestas, int length);

int ins_cantidad (Instrumento* instrumentos, int length);


int mus_cantidadPorOrquesta (Musico* list3, int length);
int mus_cantidadPorTipoInstrumento (Musico* list3, int length);

int mus_cantidadYpromedio (Musico* list3, int length);
int mus_ordenar (Musico* list3,int length);

#endif // INFORMES_H_INCLUDED
