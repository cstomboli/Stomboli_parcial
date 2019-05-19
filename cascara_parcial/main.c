#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instrumento.h"
#include "orquesta.h"
#include "musico.h"
#include "utn.h"
#include "fantasma.h"
#define FANTASMA 5      ///TAMAÑO DEL
#define INSTRUMENTOS 20 ///TAMAÑO DEL
#define ORQUESTA 50    ///TAMAÑO DEL
#define MUSICOS 1000 ///TAMAÑO DEL

int main()
{
    ///char buffer[30];
    int buffer;
    char seguir='s';

    Fantasma fan [FANTASMA];
    fan_inicializar(fan,FANTASMA);
    fan_mock(fan, FANTASMA,&buffer);

    Instrumento listado [INSTRUMENTOS];
    ins_inicializar(listado,INSTRUMENTOS);
    ins_mock(listado,INSTRUMENTOS);

    Orquesta list2 [ORQUESTA];
    orq_inicializar(list2,ORQUESTA);
    orq_mock(list2,ORQUESTA);

    Musico listado3 [MUSICOS];
    mus_inicializar(listado3,MUSICOS);
    mus_mock(listado,listado3,MUSICOS,INSTRUMENTOS);

    while(seguir=='s')
    {
        switch(utn_getInSimple("\n\nIngrese una opcion\n1- Instrumentos: \n2- Orquesta: \n3- Musico \n4- Salir\n"))
        {
            case 1:
                switch(utn_getInSimple("Ingrese una opcion:\n1- Alta \n2- Imprimir \n\n" ))
                {
                    case 1:
                        if(!ins_lugarLibre(listado,INSTRUMENTOS,&buffer))
                        {
                            if(!ins_alta(listado,"Error",INSTRUMENTOS))
                            {
                                    printf("\nAlta correcta Id Instrumento: %d\n", listado[buffer].IdInstrumento);
                            }
                        }
                        break;
                    case 2:
                        ins_mostrar(listado,INSTRUMENTOS);
                        break;
                }
                break;

            case 2:
                switch(utn_getInSimple("\nMENU ORQUESTA:\n 1- Alta \n 2- Eliminar \n 3- Mostrar \n 4- Volver\n\n" ))
                {
                    case 1:
                        if(!orq_lugarLibre(list2,ORQUESTA,&buffer))
                        {
                            if(!orq_alta(list2,"Error",ORQUESTA))
                            {
                                printf("\nAlta correcta Id Orquesta: %d\n", list2[buffer].IdOrquesta);
                            }
                        }
                        break;

                    case 2:
                        if(!orq_baja(list2,ORQUESTA,&buffer))
                        {
                            mus_bajaPorOrquesta(listado3,MUSICOS,&buffer);
                            printf("Orquesta y musicos eliminados correctamente.");
                        }
                        break;
                    case 3:
                        if(!orq_mostrar(list2,ORQUESTA))
                        {
                        }
                        else
                        {
                            printf("No hay ninguna orquesta cargada");
                            break;
                        }
                        break;

                }
                break;

            case 3:
                switch(utn_getInSimple("\nMENU MUSICO:\n 1- Alta\n 2- Modificar\n 3- Eliminar\n 4- Imprimir \n5- Ordenar\n" ))
                {
                    case 1:
                        if(!mus_lugarLibre(listado3,MUSICOS,&buffer))
                        {
                            if(!mus_alta(list2,listado,listado3,"Error",ORQUESTA,INSTRUMENTOS,MUSICOS))
                            {
                                printf("\nAlta correcta Id Musico: %d\n", listado3[buffer].IdMusico);
                            }
                        }
                        break;
                    case 2:
                        if(!mus_modificar(listado,listado3,MUSICOS,INSTRUMENTOS,&buffer))
                        {
                            printf("Modificado correctamente");
                        }
                        break;
                    case 3:
                        if(!mus_baja(listado,listado3,MUSICOS,INSTRUMENTOS))
                        {
                            printf("Eliminado correctamente");
                        }
                        else
                        {
                            printf("No hay musicos cargados.");
                        }
                        break;
                    case 4:
                        if(!mus_mostrar(listado,listado3,MUSICOS,INSTRUMENTOS))
                        {

                        }
                        else
                        {
                            printf("No hay musicos cargados");
                        }
                        break;
                    case 5:
                        if(!mus_ordenar(listado3,MUSICOS))
                        {

                        }

                        ///ins_cantidad(listado,INSTRUMENTOS);
                }
                break;

            case 4:
            seguir= 'n';
            break;

            default:
                printf("Opcion invalida");
                break;
        }
      }
    return 0;
}
