#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instrumento.h"
#include "orquesta.h"
#include "musico.h"
#include "utn.h"
#include "fantasma.h"
#include "informes.h"
#define FANTASMA 5      ///TAMAÑO DEL
#define INSTRUMENTOS 20 ///TAMAÑO DEL
#define ORQUESTA 50    ///TAMAÑO DEL
#define MUSICOS 5 ///TAMAÑO DEL

int main()
{
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
        switch(utn_getInSimple("\nIngrese una opcion\n1-Agregar Orquesta: \n2-Eliminar Orquesta: \n3-Listar Orquesta: \n4-Agregar Musico: \n5-Modificar Musico: \n6-Eliminar Musico: \n7-Imprimir Musicos: \n8-Agregar Instrumento: \n9-Agregar Instrumento: \n10-Salir\n"))
        {
            case 1:
                orq_alta(list2,"Error",ORQUESTA);
                break;
            case 2:
                if(!orq_baja(list2,ORQUESTA,&buffer))
                {
                    mus_bajaPorOrquesta(listado3,MUSICOS,&buffer);
                    printf("Orquesta y musicos eliminados correctamente.");
                }
                break;
            case 3:
                orq_mostrar(list2,ORQUESTA);
                break;
            case 4:
                mus_alta(list2,listado,listado3,"Error",ORQUESTA,INSTRUMENTOS,MUSICOS);
                break;
            case 5:
                mus_modificar(listado,listado3,MUSICOS,INSTRUMENTOS,&buffer);
                break;
            case 6:
                mus_ordenar(listado3,MUSICOS);
                ///mus_baja(listado,listado3,MUSICOS,INSTRUMENTOS);
                break;
            case 7:
                mus_mostrar(listado,listado3,MUSICOS,INSTRUMENTOS);
                break;
            case 8:
                ins_alta(listado,"Error",INSTRUMENTOS);
                break;
            case 9:
                ins_mostrar(listado,INSTRUMENTOS);
                break;
            case 10:
            seguir= 'n';
            break;

            default:
                printf("Opcion invalida");
                break;
        }
    }
    return 0;
}
