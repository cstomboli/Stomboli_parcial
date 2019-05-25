#ifndef INSTRUMENTO_C_INCLUDED
#define INSTRUMENTO_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "instrumento.h"
#include "utn.h"
#define TRUE 1
#define FALSE 0
#define CUERDAS 1
#define VIENTO MADERA 2
#define VENTO METAL 3
#define PRECUSION 4

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
int ins_empty (Instrumento *instrumentos, int length)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        if(instrumentos[i].isEmpty==0)
        {
            retorno=0;
            break;
        }
        else
        {
            printf("No hay Instrumento cargados\n");
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
int ins_inicializar(Instrumento* instrumentos, int length)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        instrumentos[i].isEmpty=1;
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
int ins_alta(Instrumento* instrumentos, char *msgError,int length)
{
    char bufferName [30];
    int bufferTipo;
    int posLibre;
    int retorno=-1;

    if(!ins_lugarLibre(instrumentos,length,&posLibre))
    {
        if(!utn_getName("Ingrese Nombre del instrumento: \n","Invalido, reingrese:\n",2,30,2,bufferName))
        {
            if(!utn_getInt("Ingrese tipo de instrumento:\n","Invalido, reingrese:\n",1,4,2,&bufferTipo))
            {
                strncpy(instrumentos[posLibre].nombre ,bufferName,sizeof(bufferName));
                instrumentos[posLibre].tipo =bufferTipo;
                instrumentos[posLibre].IdInstrumento =generarId();
                instrumentos[posLibre].isEmpty =0;
                retorno=0;
                printf("\nAlta correcta Id Instrumento: %d\n", instrumentos[posLibre].IdInstrumento);

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
int ins_lugarLibre (Instrumento* instrumentos, int length, int *posLibre)
{
    int retorno=-1;
    int i;
    for(i=0; i<length;i++)
    {
        if(instrumentos[i].isEmpty==1)
        {
            *posLibre=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

/** \brief  Busca por Id el campo solicitado.
 *
 * \param   Recibe la Estructura
 * \param   Mensaje
 * \param   Mensaje de Error
 * \param   Tamaño de la misma
 * \param   Id a buscar
 * \return  0 si lo encontro, -1 si no.
 *
 */
int ins_buscarPorId (Instrumento* instrumentos,char *msg,char *msgError, int length, int *id)
{
    int retorno=-1;
    int i;
    utn_getInt(msg,msgError,1,3,2,id);
    for(i=0; i<length; i++)
    {
        if (instrumentos[i].IdInstrumento==*id)
        {
            retorno=0;
            *id=i;
             break;
        }
        else
        {
            printf("Id no encontrado.");
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

int ins_baja (Instrumento* instrumentos, int length)
{
    int buffer;
    int retorno=-1;

    ins_mostrar(instrumentos,length);

    if(ins_buscarPorId(instrumentos,"\nIngrese Id a dar de baja\n","\nId incorrecto\n",length,&buffer)==0)
    {
        instrumentos[buffer].isEmpty=2;
        retorno=0;
    }
    else
    {
        printf("\nId no encontrado\n");
    }
    return retorno;
}

/** \brief Muestra todos los campos indicados
 *
 * \param   Recibe la Estructura instrumentos
 * \param   Tamaño de la misma
 * \return  0 si pudo mostrar, -1 si no pudo.
 *
 */
int ins_mostrar(Instrumento* instrumentos, int length)
{
    int i;
    int retorno=-1;
    for (i=0; i<length; i++)
    {
        if(instrumentos[i].isEmpty==0)
        {
            printf("\nId instrumento: %d",instrumentos[i].IdInstrumento);
            printf("\nNombre: %s",instrumentos[i].nombre);

            switch(instrumentos[i].tipo)
            {
                case 1:
                    printf("\nTipo de instrumento: Cuerdas\n");
                    break;
                case 2:
                    printf("\nTipo de instrumento: Viento de Madera\n");
                    break;
                case 3:
                    printf("\nTipo de instrumento: Viento de Metal\n");
                    break;
                case 4:
                    printf("\nTipo de instrumento: Percusion\n");
                    break;
            }
            retorno=0;
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
void ins_mock(Instrumento* instrumentos, int length)
{
    instrumentos[0].IdInstrumento =1;
    strcpy(instrumentos[0].nombre,"Inst1");
    instrumentos[0].tipo=1;
    instrumentos[0].isEmpty=0;

    instrumentos[1].IdInstrumento =2;
    strcpy(instrumentos[1].nombre,"Inst2");
    instrumentos[1].tipo=2;
    instrumentos[1].isEmpty=0;

    instrumentos[2].IdInstrumento =3;
    strcpy(instrumentos[2].nombre,"Inst3");
    instrumentos[2].tipo=2;
    instrumentos[2].isEmpty=0;

    instrumentos[3].IdInstrumento=4;
    strcpy(instrumentos[3].nombre,"Inst4");
    instrumentos[3].tipo=3;
    instrumentos[3].isEmpty=0;

    instrumentos[3].IdInstrumento=5;
    strcpy(instrumentos[3].nombre,"Inst5");
    instrumentos[3].tipo=4;
    instrumentos[3].isEmpty=0;
}


#endif // INSTRUMENTO_C_INCLUDED
