#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

typedef struct
{
    int idInstrumento;
    int isEmpty;
    char nombre[31];
    int tipo;

}InstrumentoAuxiliar;

void informes (Orquesta* arrayOrquestas, int lengthOrq, Instrumento* arrayInstrumentos, int lengthIns, Musico* arrayMusicos, int lengthMus);

int inf_OrquestaPorLugar(Orquesta* orquestas, int length);
int inf_musicoMenor (Orquesta* orquestas, Instrumento* instrumentos, Musico* list3,int lengthOrq, int lengthIns, int lengthMus);
int inf_menosIntegrantesPorOrquesta (Musico* arrayMusicos, Orquesta* arrayOrquesta,int lengthMus, int lengthOrq);
int inf_InstrumentosOrq(Instrumento* arrayInstr, Orquesta* arrayOrq, Musico* arrayMus, int lengthIns, int lengthOrq, int lengthMus);
int inf_orquestaCompleta(Instrumento* arrayInstrumentos,Orquesta* arrayOrquestas,Musico* arrayMusicos,int lengthIns,int lengthOrq, int lengthMus);
int inf_menosMusicosPorOrquesta (Musico* arrayMusicos, Orquesta* arrayOrquesta,int lengthMus, int lengthOrq);
int inf_promedioPorInstrumento (Orquesta* orquestas, Musico* musicos, int lengthOrq, int lengthMus);
int inf_musNoViento (Musico* arrayMusicos, Instrumento* instrumentos,int lengthMus, int length);
int inf_ordenar (Musico* arrayMus,int lengthMus);


#endif // INFORMES_H_INCLUDED
