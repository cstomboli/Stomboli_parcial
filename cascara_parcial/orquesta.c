#ifndef ORQUESTA_C_INCLUDED
#define ORQUESTA_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "orquesta.h"
#include "instrumento.h"
#include "utn.h"
#define TRUE 1
#define FALSE 0
#define SINFONICA 1
#define FILARMONICA 2
#define CAMARA 3

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
int orq_empty (Orquesta *orquestas, int length)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        if(orquestas[i].isEmpty==0)
        {
             retorno=0;
            break;
        }
        else
        {
            printf("No hay Orquesta cargados\n");
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
int orq_inicializar(Orquesta* orquestas, int length)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        orquestas[i].isEmpty=1;
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
int orq_alta(Orquesta* orquestas, char *msgError,int length)
{
    char bufferName [51];
    char bufferLugar [50];
    int bufferTipo;
    int posLibre;

    int retorno=-1;

    if(!orq_lugarLibre(orquestas,length,&posLibre))
    {
        if(!utn_getName("Nombre de la orquesta:\n","Invalido, reingrese:\n",4,20,2,bufferName))
        {
            if(!utn_getName("Lugar de la orquesta:\n","Invalido, reingrese:\n",4,20,2,bufferLugar))
            {
                if(!utn_getInt("Tipo de Orquesta:\n1- Sinfonica: \n2- Filarmonica: \n3- Camara: \n","Error",1,3,2,&bufferTipo))
                {
                    strncpy(orquestas[posLibre].nombre,bufferName,sizeof(bufferName));
                    strncpy(orquestas[posLibre].lugar,bufferLugar,sizeof(bufferLugar));
                    orquestas[posLibre].tipo=bufferTipo;
                    orquestas[posLibre].IdOrquesta=generarId();
                    orquestas[posLibre].isEmpty=0;
                    retorno=0;
                    printf("\nAlta correcta Id Orquesta: %d\n", orquestas[posLibre].IdOrquesta);
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
int orq_lugarLibre (Orquesta* orquestas, int length, int *posLibre)
{
    int retorno=-1;
    int i;
    for(i=0; i<length;i++)
    {
        if(orquestas[i].isEmpty==1)
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
int orq_buscarPorId (Orquesta* orquestas,char *msg,char *msgError, int length, int *id)
{
    int retorno=-1;
    int i;
    utn_getInt(msg,msgError,1,3,2,id);
    for(i=0; i<length; i++)
    {
        if (orquestas[i].IdOrquesta==*id)
        {
            retorno=0;
            *id=i;
            printf("\nEl id ingresado es de la orquesta %s\n",orquestas[i].nombre);
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
int orq_baja (Orquesta* orquestas, int length, int *id)
{
    int retorno=-1;
    orq_mostrar(orquestas,length);
    if(orq_buscarPorId(orquestas,"\nIngrese Id de la orquesta a dar de Baja:\n","Error",length,id)==0)
    {

        orquestas[*id].isEmpty=2;
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
 * \param orquestas Orquesta* Recibe la Estructura
 * \param length Tamaño de la misma
 * \return int 0 si pudo mostrar, -1 si no pudo.
 *
 */
int orq_mostrar(Orquesta* orquestas, int length)
{
    int i;
    int retorno=-1;
    for (i=0; i<length; i++)
    {
        if(orquestas[i].isEmpty==0)
        {
            printf("\n Id de la orquesta: %d",orquestas[i].IdOrquesta);
            printf("\n Nombre: %s",orquestas[i].nombre);
            printf("\n Lugar: %s",orquestas[i].lugar);

            switch(orquestas[i].tipo)
            {
                case 1:
                    printf("\n Tipo de Orquesta Sinfonica\n");
                    break;
                case 2:
                    printf("\n Tipo de Orquesta Viento de Filarmonica\n");
                    break;
                case 3:
                    printf("\n Tipo de Orquesta Viento de Camara\n");
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
void orq_mock(Orquesta* orquestas, int length)
{
    orquestas[0].IdOrquesta=1;
    orquestas[0].tipo =1;
    orquestas[0].isEmpty=0;
    strcpy(orquestas[0].nombre,"Orquesta1");
    strcpy(orquestas[0].lugar ,"Lugar1");

    orquestas[1].IdOrquesta=2;
    orquestas[1].tipo=2;
    orquestas[1].isEmpty=0;
    strcpy(orquestas[1].nombre,"Orquesta2");
    strcpy(orquestas[1].lugar,"Lugar2");

    orquestas[2].IdOrquesta=3;
    orquestas[2].tipo =3;
    orquestas[2].isEmpty=0;
    strcpy(orquestas[2].nombre,"Orquesta3");
    strcpy(orquestas[2].lugar ,"Lugar3");

    orquestas[3].IdOrquesta=4;
    orquestas[3].tipo=2;
    orquestas[3].isEmpty=0;
    strcpy(orquestas[3].nombre,"Orquesta4");
    strcpy(orquestas[3].lugar,"Lugar4");



}


#endif // ORQUESTA_C_INCLUDED
