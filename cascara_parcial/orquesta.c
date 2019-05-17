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
                if(!utn_getInt("Tipo de Orquesta:\n 1- Sinfonica: \n2- Filarmonica: \n3- Camara""Invalido, reingrese:\n","Error",1,3,2,&bufferTipo))
                {
                    strncpy(orquestas[posLibre].nombre,bufferName,sizeof(bufferName));
                    strncpy(orquestas[posLibre].lugar,bufferLugar,sizeof(bufferLugar));
                    orquestas[posLibre].tipo=bufferTipo;
                    orquestas[posLibre].IdOrquesta=generarId();
                    orquestas[posLibre].isEmpty=0;
                    retorno=0;
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

/** \brief  Modifica el campo solicitado.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \param   El id a buscar
 * \return  0 si pudo modificar, -1 si no pudo.
 *
 */

 /*
int orq_modificar (Orquesta* orquestas, int length,int*id)
{
    int retorno=-1;
    char bufferName [51];
    char bufferLastName [51];
    int bufferId;

    char seguir='s';
    while(seguir=='s')
    {
        if(orq_buscarPorId(orquestas,"\nIngrese Id a modificar\n", "Error id invalido\n",length,&bufferId)==0)
        {
            switch(utn_getInSimple("\nMENU DE MODIFICACION\nIngrese opcion a modificar \n1- Nombre - \n2- Apellido - \n3- Salir \n"))
            {
                case 1:
                    if(!utn_getName("Ingrese nombre:\n","Invalido, reingrese:\n",2,20,2,bufferName))
                    {
                        strncpy(orquestas[bufferId].nombre,bufferName,sizeof(bufferName));
                        printf("Nombre modificado correctamente.\n");
                    }
                break;

                case 2:
                    if(!utn_getName("Ingrese Apellido:\n","Invalido, reingrese:\n",2,20,2,bufferLastName))
                        {
                        strncpy(orquestas[bufferId].apellido,bufferLastName,sizeof(bufferLastName));
                        printf("Apellido modificado correctamente.\n");
                        }
                break;

                case 3:
                    retorno=0;
                    seguir= 'n';
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

    }


    return retorno;
} */

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
int orq_baja (Orquesta* orquestas, int length)
{
    int buffer;
    int retorno=-1;

    if(orq_buscarPorId(orquestas,"\nIngrese Id a dar de baja\n","\nId incorrecto\n",length,&buffer)==0)
    {

        orquestas[buffer].isEmpty=2;
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
    orquestas[0].IdOrquesta =0;
    orquestas[0].tipo =2;
    orquestas[0].isEmpty=0;
    strcpy(orquestas[0].nombre,"Guitarra");
    strcpy(orquestas[0].lugar ,"Lomas");

    /*    orquestas[1].IdOrquesta =1;
    orquestas[1].isEmpty=0;
    strcpy(orquestas[1].apellido,"Sarubbi");
    strcpy(orquestas[1].nombre,"Maria del carmen");
    strcpy(orquestas[1].sexo,"f");
    strcpy(orquestas[1].telefono,"4243-3403");
    strcpy(orquestas[1].mail,"marita.sarubbi@gmail.com");
    strcpy(orquestas[1].fechaAorqiado,"05-02-2017");

    orquestas[2].IdOrquesta =2;
    orquestas[2].isEmpty=0;
    strcpy(orquestas[2].apellido,"Faundo");
    strcpy(orquestas[2].nombre,"El hagge");
    strcpy(orquestas[2].sexo,"m");
    strcpy(orquestas[2].telefono,"4245-8977");
    strcpy(orquestas[2].mail,"f.elhagge@hotmail.com");
    strcpy(orquestas[2].fechaAorqiado,"18-12-2018");

    orquestas[3].codigoorqiado =3;
    orquestas[3].isEmpty=0;
    strcpy(orquestas[3].apellido,"Moreno");
    strcpy(orquestas[3].nombre,"Catalina");
    strcpy(orquestas[3].sexo,"f");
    strcpy(orquestas[3].telefono,"1533524848");
    strcpy(orquestas[3].mail,"catalinamoreno@gmail.com");
    strcpy(orquestas[3].fechaAorqiado,"29-04-2019");
    */
}


#endif // ORQUESTA_C_INCLUDED
