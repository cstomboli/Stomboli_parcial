#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fantasma.h"
#include "instrumento.h"
#include "utn.h"
#define FANTASMA 51 ///TAMA�O DEL
#define INSTRUMENTOS 20 ///TAMA�O DEL

int main()
{
    ///char buffer[30];
    int buffer;
    char seguir='s';
    int contadorIdfantasma=0;

    Fantasma list3[FANTASMA];
    fan_inicializar(list3,FANTASMA);
    fan_mock(list3, FANTASMA, &contadorIdfantasma);

    Instrumento listado [INSTRUMENTOS];
    ins_inicializar(listado,INSTRUMENTOS);

    while(seguir=='s')
    {
        switch(utn_getInSimple("Ingrese una opcion\n1- Instrumento: \n2- Modificar: \n3- Baja \n4- Informar \n5- Salir\n"))
        {
        case 1:
                switch(utn_getInSimple("Ingrese una opcion:\n 1- Alta \n 2- Imprimir \n\n" ))
                {
                    case 1:
                            if(!ins_alta(listado,"Error",INSTRUMENTOS,&buffer))
                            {
                                printf("Alta correcta");
                               /// printf("%d", listado[buffer].IdInstrumento);
                               /// ins_mostrarId(listado,INSTRUMENTOS,buffer);
                            }

                        break;
                    case 2:

                        break;
                }
                break;

            case 2:
                switch(utn_getInSimple("Que desea Modificar 1-Autor o 2-Libro??\n\n" ))
                {
                    case 1:

                        break;

                    case 2:

                        break;
                }
                break;

                case 3:
                     break;


                case 4:
                    break;

                case 5:
                seguir= 'n';
                break;
        }
    }
    return 0;
}
