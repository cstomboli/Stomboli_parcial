#ifndef MUSICO_C_INCLUDED
#define MUSICO_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"
#include "utn.h"
#define TRUE 1
#define FALSE 0

static int generarId(void);

/** \brief  Genera Id.
 *
 * \param   No recibe nada
 * \param
 * \return  int, creciente.
 *
 */
static int generarId(void)
{
    static int id=1;
    return id++;
}

/** \brief  Busca si una estructura esta vacia o no.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si pudo dar de baja, -1 si no pudo.
 *
 */
int mus_empty (Musico *arrayMus, int lengthMus)
{
    int i;
    int retorno=-1;

    for(i=0;i<lengthMus;i++)
    {
        if(arrayMus[i].isEmpty==0)
        {
             retorno=0;
            break;
        }
        else
        {
            printf("No hay Musico cargados\n");
            break;
        }
    }
    return retorno;
}

/** \brief  Inicializa todos los campos en 1.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si pudo. -1 si no pudo.
 *
 */
int mus_inicializar(Musico* arrayMus, int lengthMus)
{
    int i;
    int retorno=-1;

    for(i=0;i<lengthMus;i++)
    {
        arrayMus[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

/** \brief  Da de Alta.
 *
 * \param   Recibe la Estructura
 * \param   Mensaje de Error
 * \param   Tamaño de la misma
 * \param   Posicion donde va a guardar.
 * \return  0 si pudo dar de alta, -1 si no pudo.
 *
 */
int mus_alta(Orquesta* arrayOrq, Instrumento* arrayIns, Musico* arrayMus, char *msgError,int lengthOrq, int lengthIns,int lengthMus)
{
    char bufferName [51];
    char bufferLastName [51];
    int bufferEdad;
    int bufferIdOrquesta;
    int bufferIndiceOrquesta;
    int bufferIdInstrumento;
    int posLibre;
    int retorno=-1;

    if(!mus_lugarLibre(arrayMus,lengthMus,&posLibre))
    {
        if(!utn_getName("Nombre:\n","Invalido, reingrese:\n",2,20,2,bufferName))
        {
            if(!utn_getName("Apellido:\n","Invalido, reingrese:\n",2,20,2,bufferLastName))
            {
                if(!utn_getInt("Ingrese Edad:\n","Invalido, reingrese:\n",1,100,2,&bufferEdad))
                {
                    if(!orq_buscarPorId(arrayOrq,"Ingrese id de la orquesta\n","Error",lengthOrq,&bufferIndiceOrquesta))
                    {
                        if(!ins_buscarPorId(arrayIns,"Ingrese instrumento:\n1- Cuerdas \n2- Viento Madera \n3- Viento Metal \n4- Percusion\n","Invalido, reingrese:\n",lengthIns,&bufferIdInstrumento))
                        {
                                ///if(buscar orquesta por id)
                                bufferIdOrquesta=arrayOrq[bufferIndiceOrquesta].IdOrquesta;
                                strncpy(arrayMus[posLibre].nombre,bufferName,sizeof(bufferName));
                                strncpy(arrayMus[posLibre].apellido,bufferLastName,sizeof(bufferLastName));
                                arrayMus[posLibre].edad=bufferEdad;
                                arrayMus[posLibre].IdOrquesta=bufferIdOrquesta;
                                arrayMus[posLibre].IdInstrumento=bufferIdInstrumento;
                                arrayMus[posLibre].IdMusico=generarId();
                                arrayMus[posLibre].isEmpty=0;
                                retorno=0;
                                printf("\nAlta correcta Id Musico: %d\n", arrayMus[posLibre].IdMusico);

                        }
                    }
                }
            }
        }
    }
    else
    {
        printf("\nNo hay lugar para realizar una nueva Alta.\n\n");
    }
    return retorno;
}

/** \brief  Buscar lugar libre.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \param   int donde guarda el indice de la posicion libre
 * \return  0 encontro lugar libre, -1 si no.
 *
 */
int mus_lugarLibre (Musico* arrayMus, int lengthMus, int *posLibre)
{
    int retorno=-1;
    int i;
    for(i=0; i<lengthMus;i++)
    {
        if(arrayMus[i].isEmpty==1)
        {
            *posLibre=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

/** \brief  Modifica el campo solicitado.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \param   El id a buscar
 * \return  0 si pudo modificar, -1 si no pudo.
 *
 */
int mus_modificar (Instrumento* arrayIns, Musico* arrayMus, int lengthMus, int lengthIns,int*id)
{
    int retorno=-1;
    int bufferEdad;
    int bufferIdOrquesta;
    int bufferId;
    mus_mostrar(arrayIns,arrayMus,lengthMus,lengthIns);

        if(mus_buscarPorId(arrayMus,"\nIngrese Id a modificar\n", "Error id invalido\n",lengthMus,&bufferId)==0)
        {
            switch(utn_getInSimple("\nMENU DE MODIFICACION\nIngrese opcion a modificar \n1- Edad - \n2- Id de la Orquesta - \n3- Salir \n"))
            {
                case 1:
                    if(!utn_getInt("Ingrese Edad:\n","Invalido, reingrese:\n",1,100,2,&bufferEdad))
                    {
                        arrayMus[bufferId].edad=bufferEdad;
                        printf("Edad modificado correctamente.\n");
                    }
                    break;

                case 2:
                    if(!utn_getInt("Ingrese Id de Orquesta:\n","Invalido, reingrese:\n",1,20,2,&bufferIdOrquesta))
                        {
                            arrayMus[bufferId].IdOrquesta =bufferIdOrquesta;
                            printf("Id de orquesta modificado correctamente.\n");
                        }
                    break;

                case 3:
                    retorno=0;
                    break;

                default:
                    printf("Opcion invalida");
                    break;
            }
        }
        else
        {
        printf("\nId no encontrado.\n\n");
        }




    return retorno;
}

/** \brief  Busca por Id el campo solicitado.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \param   Id a buscar
 * \return  0 si lo encontro, -1 si no.
 *
 */
int mus_buscarPorId (Musico* arrayMus,char *msg,char *msgError, int lengthMus, int *id)
{
    int retorno=-1;
    int i;
    utn_getInt(msg,msgError,1,3,2,id);
    for(i=0; i<lengthMus; i++)
    {
        if (arrayMus[i].IdMusico==*id)
        {
            retorno=0;
            *id=i;
             break;
        }
    }

    return retorno;
}

/** \brief  Da de baja el campo solicitado.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si pudo dar de baja, -1 si no pudo.
 *
 */
int mus_baja (Instrumento* arrayIns,Musico* arrayMus, int lengthMus, int lengthIns)
{
    int buffer;
    int retorno=-1;
    mus_mostrar(arrayIns,arrayMus,lengthMus,lengthIns);

    if(mus_buscarPorId(arrayMus,"\nIngrese Id a dar de baja\n","\nId incorrecto\n",lengthMus,&buffer)==0)
    {
        arrayMus[buffer].isEmpty=2;
        retorno=0;
        printf("Musico Eliminado correctamente");
    }
    else
    {
        printf("\nId no encontrado\n");
    }
    return retorno;
}

/** \brief  Busca por Id el campo solicitado.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \param   Id a buscar
 * \return  0 si lo encontro, -1 si no.
 *
 */
int mus_bajaPorOrquesta(Musico* arrayMus, int lengthMus, int *id)
{
    int retorno=-1;
    int i;


         if(mus_buscarPorIddeBaja(arrayMus,lengthMus,id)==0)
        {
            for(i=0;i<lengthMus;i++)
            {
                arrayMus[i].isEmpty=2;
                retorno=0;
            }
        }


    return retorno;
}
/** \brief  Busca por Id el campo solicitado.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \param   Id a buscar
 * \return  0 si lo encontro, -1 si no.
 *
 */
int mus_buscarPorIddeBaja (Musico* arrayMus, int lengthMus, int *id)
{
    int retorno=-1;
    int i;
    for(i=0; i<lengthMus; i++)
    {
        if (arrayMus[i].IdOrquesta==*id)
        {
            retorno=0;
            *id=i;
            break;

        }
    }

    return retorno;
}

/** \brief Muestra todos los campos indicados
 *
 * \param arrayMus Musico* Recibe la Estructura
 * \param lengthMus Tamaño de la misma
 * \return int 0 si pudo mostrar, -1 si no pudo.
 *
 */
int mus_mostrar(Instrumento* arrayIns, Musico* arrayMus,int lengthIns, int lengthMus)
{
    int i;
    int retorno=-1;

    for (i=0; i<lengthMus; i++)
    {
        if(arrayMus[i].isEmpty==0)
        {
            printf("\nCodigo de musico: %d",arrayMus[i].IdMusico);
            printf("\nNombre: %s",arrayMus[i].nombre);
            printf("\nApellido: %s",arrayMus[i].apellido);
            printf("\nEdad: %d",arrayMus[i].edad);
            printf("\nId Orquesta: %d",arrayMus[i].IdOrquesta);
            printf("\nNombre del Instrumento: %s", arrayIns[i].nombre);
            switch(arrayIns[i].tipo)
            {
                case 1:
                    printf("\nTipo de Instrumento: Cuerdas.\n");
                    break;
                case 2:
                    printf("\nTipo de Instrumento: Viento Madera.\n");
                    break;
                case 3:
                    printf("\nTipo de Instrumento: Viento Metal.\n");
                    break;
                case 4:
                    printf("\nTipo de Instrumento: Percusion.\n");
                    break;

            }

        }
    }
    return retorno;
}


/** \brief La funcion muestra los datos hardcodeados.
 *
 * \param la estructura
 * \param el tamaño y el id para contar.
 * \return no retorna nada.
 *
 */
void mus_mock(Instrumento* arrayIns, Musico* arrayMus, int lengthIns, int lengthMus)
{

    arrayMus[0].IdMusico =1;
    arrayMus[0].isEmpty=0;
    arrayMus[0].IdOrquesta=1;
    arrayMus[0].edad=30;
    strcpy(arrayMus[0].apellido,"Mus1");
    strcpy(arrayMus[0].nombre,"Mus1");
    strcpy(arrayIns[0].nombre,"Guitarra");
    arrayIns[0].tipo=3;
    arrayMus[0].IdInstrumento=2;

    arrayMus[1].IdMusico =2;
    arrayMus[1].isEmpty=0;
    arrayMus[1].IdOrquesta=2;
    arrayMus[1].edad=20;
    strcpy(arrayMus[1].apellido,"Mus2");
    strcpy(arrayMus[1].nombre,"Mus2");
    strcpy(arrayIns[1].nombre,"Bateria");
    arrayIns[1].tipo=3;
    arrayMus[1].IdInstrumento=5;

    arrayMus[2].IdMusico=3;
    arrayMus[2].isEmpty=0;
    arrayMus[2].IdOrquesta=4;
    arrayMus[2].edad=22;
    strcpy(arrayMus[2].apellido,"Mus3");
    strcpy(arrayMus[2].nombre,"Mus3");
    strcpy(arrayIns[2].nombre,"Flauta traversa");
    arrayIns[2].tipo=3;
    arrayMus[2].IdInstrumento=2;

    arrayMus[3].IdMusico=4;
    arrayMus[3].isEmpty=0;
    arrayMus[3].IdOrquesta=4;
    arrayMus[3].edad=27;
    strcpy(arrayMus[3].apellido,"Mus4");
    strcpy(arrayMus[3].nombre,"Mus4");
    strcpy(arrayIns[3].nombre,"Flauta");
    arrayIns[3].tipo=3;
    arrayMus[3].IdInstrumento=1;

    arrayMus[4].IdMusico=5;
    arrayMus[4].isEmpty=0;
    arrayMus[4].IdOrquesta=1;
    arrayMus[4].edad=22;
    strcpy(arrayMus[4].apellido,"Mus5");
    strcpy(arrayMus[4].nombre,"Mus5");
    strcpy(arrayIns[4].nombre,"Flauta");
    arrayIns[4].tipo=4;
    arrayMus[4].IdInstrumento=3;

    arrayMus[5].IdMusico=6;
    arrayMus[5].isEmpty=0;
    arrayMus[5].IdOrquesta=3;
    arrayMus[5].edad=30;
    strcpy(arrayMus[5].apellido,"Mus6");
    strcpy(arrayMus[5].nombre,"Mus6");
    strcpy(arrayIns[5].nombre,"Flauta");
    arrayIns[5].tipo=3;
    arrayMus[5].IdInstrumento=4;


    strcpy(arrayMus[6].nombre,"Mus7");
    strcpy(arrayMus[6].apellido,"Amus7");
    arrayMus[6].edad=31;
    arrayMus[6].IdInstrumento=2;
    arrayMus[6].IdOrquesta=1;
    arrayMus[6].isEmpty=0;
    arrayMus[6].IdMusico=7;

    strcpy(arrayMus[7].nombre,"Mus8");
    strcpy(arrayMus[7].apellido,"Amus8");
    arrayMus[7].edad=32;
    arrayMus[7].IdInstrumento=3;
    arrayMus[7].IdOrquesta=1;
    arrayMus[7].isEmpty=0;
    arrayMus[7].IdMusico=8;

    strcpy(arrayMus[8].nombre,"Mus9");
    strcpy(arrayMus[8].apellido,"Amus9");
    arrayMus[8].edad=33;
    arrayMus[8].IdInstrumento=5;
    arrayMus[8].IdOrquesta=1;
    arrayMus[8].isEmpty=0;
    arrayMus[8].IdMusico=9;

    strcpy(arrayMus[9].nombre,"Mus10");
    strcpy(arrayMus[9].apellido,"Amus10");
    arrayMus[9].edad=34;
    arrayMus[9].IdInstrumento=1;
    arrayMus[9].IdOrquesta=1;
    arrayMus[9].isEmpty=0;
    arrayMus[9].IdMusico=10;

    strcpy(arrayMus[10].nombre,"Mus11");
    strcpy(arrayMus[10].apellido,"Amus11");
    arrayMus[10].edad=35;
    arrayMus[10].IdInstrumento=5;
    arrayMus[10].IdOrquesta=1;
    arrayMus[10].isEmpty=0;
    arrayMus[10].IdMusico=11;

    strcpy(arrayMus[11].nombre,"Mus12");
    strcpy(arrayMus[11].apellido,"Amus12");
    arrayMus[11].edad=36;
    arrayMus[11].IdInstrumento=1;
    arrayMus[11].IdOrquesta=1;
    arrayMus[11].isEmpty=0;
    arrayMus[11].IdMusico=12;

    strcpy(arrayMus[12].nombre,"Mus13");
    strcpy(arrayMus[12].apellido,"Amus13");
    arrayMus[12].edad=37;
    arrayMus[12].IdInstrumento=5;
    arrayMus[12].IdOrquesta=1;
    arrayMus[12].isEmpty=0;
    arrayMus[12].IdMusico=13;


    strcpy(arrayMus[13].nombre,"Mus14");
    strcpy(arrayMus[13].apellido,"Amus14");
    arrayMus[13].edad=38;
    arrayMus[13].IdInstrumento=1;
    arrayMus[13].IdOrquesta=1;
    arrayMus[13].isEmpty=0;
    arrayMus[13].IdMusico=14;

    strcpy(arrayMus[14].nombre,"Mus15");
    strcpy(arrayMus[14].apellido,"Amus15");
    arrayMus[14].edad=39;
    arrayMus[14].IdInstrumento=5;
    arrayMus[14].IdOrquesta=1;
    arrayMus[14].isEmpty=0;
    arrayMus[14].IdMusico=15;

    strcpy(arrayMus[15].nombre,"Mus16");
    strcpy(arrayMus[15].apellido,"Amus16");
    arrayMus[15].edad=40;
    arrayMus[15].IdInstrumento=1;
    arrayMus[15].IdOrquesta=1;
    arrayMus[15].isEmpty=0;
    arrayMus[15].IdMusico=16;
}


#endif // MUSICO_C_INCLUDED
