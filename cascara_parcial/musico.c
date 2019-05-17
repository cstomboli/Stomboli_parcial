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
                    if(!orq_buscarPorId(listado,"Ingrese id de la orquesta","Error",length3,&bufferIdOrquesta))
                    {
                        if(!ins_buscarPorId(list2,"Ingrese instrumento:\n 1 - \n2 -\n3 -\n4\n","Invalido, reingrese:\n",length2,&bufferIdInstrumento))

                       {
                                ///if(buscar orquesta por id)
                                strncpy(list3[posLibre].nombre,bufferName,sizeof(bufferName));
                                strncpy(list3[posLibre].apellido,bufferLastName,sizeof(bufferLastName));
                                list3[posLibre].edad=bufferEdad;
                                list3[posLibre].IdOrquesta=bufferIdOrquesta;
                                list3[posLibre].IdInstrumento=bufferIdInstrumento;
                                list3[posLibre].IdMusico=generarId();
                                list3[posLibre].isEmpty=0;
                                retorno=0;

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
int mus_modificar (Musico* list3, int length,int*id)
{
    int retorno=-1;
    int bufferEdad;
    int bufferIdOrquesta;
    int bufferId;

    char seguir='s';
    while(seguir=='s')
    {
        if(mus_buscarPorId(list3,"\nIngrese Id a modificar\n", "Error id invalido\n",length,&bufferId)==0)
        {
            switch(utn_getInSimple("\nMENU DE MODIFICACION\nIngrese opcion a modificar \n1- Edad - \n2- Id - \n3- Salir \n"))
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
int mus_baja (Musico* list3, int length)
{
    int buffer;
    int retorno=-1;

    mus_mostrar(list3,length);

    if(mus_buscarPorId(list3,"\nIngrese Id a dar de baja\n","\nId incorrecto\n",length,&buffer)==0)
    {
        list3[buffer].isEmpty=2;
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
 * \param list3 Musico* Recibe la Estructura
 * \param length Tamaño de la misma
 * \return int 0 si pudo mostrar, -1 si no pudo.
 *
 */
int mus_mostrar(Musico* list3, int length)
{
    int i;
    int retorno=-1;
    for (i=0; i<length; i++)
    {
        if(list3[i].isEmpty==0)
        {
            printf("\n Codigo de musico: %d",list3[i].IdMusico);
            printf("\n Apellido: %s",list3[i].apellido);
            printf("\n Nombre: %s",list3[i].nombre);
            printf("\n Edad: %d",list3[i].edad);
            printf("\n Id Orquesta: %d",list3[i].IdOrquesta);
            printf("\n Id Instrumento: %d",list3[i].IdInstrumento);

            retorno=0;
        }
    }
    return retorno;
}

/** \brief Ordena por 2 criterios
 *
 * \param  Recibe la Estructura
 * \param El tamaño de la misma
 * \return  -1 si no pudo Ordenar, 0 Si pudo.
 *
 */
int mus_ordenar (Musico* list3,int length)
{
    int j;
    int flag;
    Musico buffer;
    int retorno=-1;

    if(list3 != NULL && length>0)
    {
        do
        {
            flag=0;
            for(j=0;j<length-1;j++)
            {
                if(strcmp(list3[j].apellido,list3[j+1].apellido)>0)
                {
                    buffer=list3[j];
                    list3[j]=list3[j+1];
                    list3[j+1]=buffer;
                    flag=1;
                    retorno=0;
                    break;

                    for(j=0;j<length-1;j++)
                    {

                        if(list3[j].nombre>list3[j+1].nombre)
                        {
                        buffer=list3[j];
                        list3[j]=list3[j+1];
                        list3[j+1]=buffer;
                        flag=1;
                        retorno=0;
                        break;
                        }
                    }

                }
            }
        }while(flag);
    }return retorno;
}

/** \brief La funcion muestra los datos hardcodeados.
 *
 * \param la estructura
 * \param el tamaño y el id para contar.
 * \return no retorna nada.
 *
 */

 /*
void mus_mock(Musico* list3, int length,int *contadorId)
{
    list3[0].IdMusico =0;
    list3[0].isEmpty=0;
    strcpy(list3[0].apellido,"Stomboli");
    strcpy(list3[0].nombre,"Carolina");
    strcpy(list3[0].sexo,"f");
    strcpy(list3[0].telefono,"1521767920");
    strcpy(list3[0].mail,"carostomboli@hotmail.com");
    strcpy(list3[0].fechaAmusiado,"21-03-2018");

    list3[1].codigomusiado =1;
    list3[1].isEmpty=0;
    strcpy(list3[1].apellido,"Sarubbi");
    strcpy(list3[1].nombre,"Maria del carmen");
    strcpy(list3[1].sexo,"f");
    strcpy(list3[1].telefono,"4243-3403");
    strcpy(list3[1].mail,"marita.sarubbi@gmail.com");
    strcpy(list3[1].fechaAmusiado,"05-02-2017");

    list3[2].codigomusiado =2;
    list3[2].isEmpty=0;
    strcpy(list3[2].apellido,"Faundo");
    strcpy(list3[2].nombre,"El hagge");
    strcpy(list3[2].sexo,"m");
    strcpy(list3[2].telefono,"4245-8977");
    strcpy(list3[2].mail,"f.elhagge@hotmail.com");
    strcpy(list3[2].fechaAmusiado,"18-12-2018");

    list3[3].codigomusiado =3;
    list3[3].isEmpty=0;
    strcpy(list3[3].apellido,"Moreno");
    strcpy(list3[3].nombre,"Catalina");
    strcpy(list3[3].sexo,"f");
    strcpy(list3[3].telefono,"1533524848");
    strcpy(list3[3].mail,"catalinamoreno@gmail.com");
    strcpy(list3[3].fechaAmusiado,"29-04-2019");

}
*/

#endif // MUSICO_C_INCLUDED
