#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fantasma.h"
#include "utn.h"
#define FANTASMA 51 ///TAMAÑO DEL

int main()
{
    ///char buffer[30];
    char seguir='s';
    int contadorIdfantasma=0;

    Fantasma list3[FANTASMA];
    fan_inicializar(list3,FANTASMA);
    fan_mock(list3, FANTASMA, &contadorIdfantasma);

    while(seguir=='s')
    {
        switch(utn_getInSimple("Ingrese una opcion\n1- Altas: \n2- Modificar: \n3- Baja \n4- Informar \n5- Salir\n"))
        {
        case 1:
                switch(utn_getInSimple("Que desea dar de alta 1-Autor o 2-Libro??\n\n" ))
                {
                    case 1:
                            if(!fan_alta(list3,"Error",FANTASMA))
                            {
                                fan_mostrar(list3,FANTASMA);
                                printf("%s", list3[1].telefono);
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
