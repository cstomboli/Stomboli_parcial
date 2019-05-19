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
int mus_empty (Musico *list3, int length)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        if(list3[i].isEmpty==0)
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
int mus_inicializar(Musico* list3, int length)
{
    int i;
    int retorno=-1;

    for(i=0;i<length;i++)
    {
        list3[i].isEmpty=1;
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
int mus_alta(Orquesta* listado, Instrumento* list2, Musico* list3, char *msgError,int length3, int length2,int length)
{
    char bufferName [51];
    char bufferLastName [51];
    int bufferEdad;
    int bufferIdOrquesta;
    int bufferIndiceOrquesta;
    int bufferIdInstrumento;
    int posLibre;
    int retorno=-1;

    if(!mus_lugarLibre(list3,length,&posLibre))
    {
        if(!utn_getName("Nombre:\n","Invalido, reingrese:\n",2,20,2,bufferName))
        {
            if(!utn_getName("Apellido:\n","Invalido, reingrese:\n",2,20,2,bufferLastName))
            {
                if(!utn_getInt("Ingrese Edad:\n","Invalido, reingrese:\n",1,100,2,&bufferEdad))
                {
                    if(!orq_buscarPorId(listado,"Ingrese id de la orquesta\n","Error",length3,&bufferIndiceOrquesta))
                    {
                        if(!ins_buscarPorId(list2,"Ingrese instrumento:\n1- Cuerdas \n2- Viento Madera \n3- Viento Metal \n4- Percusion\n","Invalido, reingrese:\n",length2,&bufferIdInstrumento))
                        {
                                ///if(buscar orquesta por id)
                                bufferIdOrquesta=listado[bufferIndiceOrquesta].IdOrquesta;
                                strncpy(list3[posLibre].nombre,bufferName,sizeof(bufferName));
                                strncpy(list3[posLibre].apellido,bufferLastName,sizeof(bufferLastName));
                                list3[posLibre].edad=bufferEdad;
                                list3[posLibre].IdOrquesta=bufferIdOrquesta;
                                list3[posLibre].IdInstrumento=bufferIdInstrumento;
                                list3[posLibre].IdMusico=generarId();
                                list3[posLibre].isEmpty=0;
                                retorno=0;
                                printf("\nAlta correcta Id Musico: %d\n", list3[posLibre].IdMusico);

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
int mus_lugarLibre (Musico* list3, int length, int *posLibre)
{
    int retorno=-1;
    int i;
    for(i=0; i<length;i++)
    {
        if(list3[i].isEmpty==1)
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
int mus_modificar (Instrumento* instrumentos, Musico* list3, int length, int lengthInstru,int*id)
{
    int retorno=-1;
    int bufferEdad;
    int bufferIdOrquesta;
    int bufferId;
    mus_mostrar(instrumentos,list3,length,lengthInstru);

        if(mus_buscarPorId(list3,"\nIngrese Id a modificar\n", "Error id invalido\n",length,&bufferId)==0)
        {
            switch(utn_getInSimple("\nMENU DE MODIFICACION\nIngrese opcion a modificar \n1- Edad - \n2- Id de la Orquesta - \n3- Salir \n"))
            {
                case 1:
                    if(!utn_getInt("Ingrese Edad:\n","Invalido, reingrese:\n",1,100,2,&bufferEdad))
                    {
                        list3[bufferId].edad=bufferEdad;
                        printf("Edad modificado correctamente.\n");
                    }
                    break;

                case 2:
                    if(!utn_getInt("Ingrese Id de Orquesta:\n","Invalido, reingrese:\n",1,20,2,&bufferIdOrquesta))
                        {
                            list3[bufferId].IdOrquesta =bufferIdOrquesta;
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
int mus_buscarPorId (Musico* list3,char *msg,char *msgError, int length, int *id)
{
    int retorno=-1;
    int i;
    utn_getInt(msg,msgError,1,3,2,id);
    for(i=0; i<length; i++)
    {
        if (list3[i].IdMusico==*id)
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
int mus_baja (Instrumento* instrumentos,Musico* list3, int length, int lengthIns)
{
    int buffer;
    int retorno=-1;
    mus_mostrar(instrumentos,list3,length,lengthIns);

    if(mus_buscarPorId(list3,"\nIngrese Id a dar de baja\n","\nId incorrecto\n",length,&buffer)==0)
    {
        list3[buffer].isEmpty=2;
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
int mus_bajaPorOrquesta(Musico* list3, int length, int *id)
{
    int retorno=-1;
    int i;


         if(mus_buscarPorIddeBaja(list3,length,id)==0)
        {
            for(i=0;i<length;i++)
            {
                list3[i].isEmpty=2;
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
int mus_buscarPorIddeBaja (Musico* list3, int length, int *id)
{
    int retorno=-1;
    int i;
    for(i=0; i<length; i++)
    {
        if (list3[i].IdOrquesta==*id)
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
 * \param list3 Musico* Recibe la Estructura
 * \param length Tamaño de la misma
 * \return int 0 si pudo mostrar, -1 si no pudo.
 *
 */
int mus_mostrar(Instrumento* instrumentos, Musico* list3, int length, int lengthInstrume)
{
    int i;
    int retorno=-1;

    for (i=0; i<length; i++)
    {
        if(list3[i].isEmpty==0)
        {
            printf("\nCodigo de musico: %d",list3[i].IdMusico);
            printf("\nNombre: %s",list3[i].nombre);
            printf("\nApellido: %s",list3[i].apellido);
            printf("\nId Orquesta: %d",list3[i].IdOrquesta);
            printf("\nNombre del Instrumento: %s", instrumentos[i].nombre);
            switch(instrumentos[i].tipo)
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
void mus_mock(Instrumento* instrumentos, Musico* list3, int length, int lengthInstrume)
{
    list3[0].IdMusico =1;
    list3[0].isEmpty=0;
    list3[0].IdOrquesta=1;
    strcpy(list3[0].apellido,"Stomboli");
    strcpy(list3[0].nombre,"Carolina");
    strcpy(instrumentos[0].nombre,"Guitarra");
    instrumentos[0].tipo=1;

    list3[1].IdMusico =2;
    list3[1].isEmpty=0;
    list3[1].IdOrquesta=1;
    strcpy(list3[1].apellido,"Del Vilano");
    strcpy(list3[1].nombre,"Alberto");
    strcpy(instrumentos[1].nombre,"Bateria");
    instrumentos[1].tipo=4;

    list3[2].IdMusico=3;
    list3[2].isEmpty=0;
    list3[2].IdOrquesta=1;
    strcpy(list3[2].apellido,"Stomboli");
    strcpy(list3[2].nombre,"Soledad");
    strcpy(instrumentos[2].nombre,"Flauta traversa");
    instrumentos[2].tipo=2;

    list3[3].IdMusico=4;
    list3[3].isEmpty=0;
    list3[3].IdOrquesta=3;
    strcpy(list3[3].apellido,"Sarubbi");
    strcpy(list3[3].nombre,"Marita");
    strcpy(instrumentos[3].nombre,"Flauta");
    instrumentos[3].tipo=2;

}


#endif // MUSICO_C_INCLUDED
