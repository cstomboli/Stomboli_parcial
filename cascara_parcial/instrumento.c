#ifndef INSTRUMENTO_C_INCLUDED
#define INSTRUMENTO_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fantasma.h"
#include "instrumento.h"
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
int ins_alta(Instrumento* instrumentos, char *msgError,int length, int *contador)
{
    char bufferName [30];
    int bufferTipo;
    int posLibre;
    int retorno=-1;
    contador=-1;
    if(!ins_lugarLibre(instrumentos,length,&posLibre))
    {
        if(!utn_getName("Ingrese Nombre del instrumento: \n","Invalido, reingrese:\n",2,30,2,bufferName))
        {
            if(!utn_getInt("Ingrese tipo de instrumento:\n","Invalido, reingrese:\n",1,21,2,&bufferTipo))
            {
                strncpy(instrumentos[posLibre].nombre ,bufferName,sizeof(bufferName));
                instrumentos[posLibre].tipo =bufferTipo;
                instrumentos[posLibre].IdInstrumento =generarId();
                instrumentos[posLibre].isEmpty =0;
                contador++;
                retorno=0;

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

/*
int ins_modificar (Instrumento* instrumentos, int length,int*id)
{
    int retorno=-1;
    char bufferName [51];
    char bufferLastName [51];
    int bufferId;

    char seguir='s';
    while(seguir=='s')
    {
        if(ins_buscarPorId(instrumentos,"\nIngrese Id a modificar\n", "Error id invalido\n",length,&bufferId)==0)
        {
            switch(utn_getInSimple("\nMENU DE MODIFICACION\nIngrese opcion a modificar \n1- Nombre - \n2- Apellido - \n3- Salir \n"))
            {
                case 1:
                    if(!utn_getName("Ingrese nombre:\n","Invalido, reingrese:\n",2,20,2,bufferName))
                    {
                        strncpy(instrumentos[bufferId].nombre,bufferName,sizeof(bufferName));
                        printf("Nombre modificado correctamente.\n");
                    }
                break;

                case 2:
                    if(!utn_getName("Ingrese Apellido:\n","Invalido, reingrese:\n",2,20,2,bufferLastName))
                        {
                        strncpy(instrumentos[bufferId].apellido,bufferLastName,sizeof(bufferLastName));
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
}   */

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
 * \param instrumentos Instrumento* Recibe la Estructura
 * \param length Tamaño de la misma
 * \return int 0 si pudo mostrar, -1 si no pudo.
 *
 */
 int ins_mostrarId(Instrumento* instrumentos, int length, int id)
{
    int retorno=0;

    printf("%d",instrumentos[id].IdInstrumento);
    return retorno;
}

int ins_mostrar(Instrumento* instrumentos, int length)
{
    int i;
    int retorno=-1;
    for (i=0; i<length; i++)
    {
        if(instrumentos[i].isEmpty==0)
        {
            printf("\n Id instrumento: %d",instrumentos[i].IdInstrumento);
            printf("\n Nombre: %s",instrumentos[i].nombre);
            printf("\n Tipo: %d",instrumentos[i].tipo);
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

 /*
int ins_ordenar (Instrumento* instrumentos,int length)
{
    int j;
    int flag;
    Instrumento buffer;
    int retorno=-1;

    if(instrumentos != NULL && length>0)
    {
        do
        {
            flag=0;
            for(j=0;j<length-1;j++)
            {
                if(strcmp(instrumentos[j].apellido,instrumentos[j+1].apellido)>0)
                {
                    buffer=instrumentos[j];
                    instrumentos[j]=instrumentos[j+1];
                    instrumentos[j+1]=buffer;
                    flag=1;
                    retorno=0;
                    break;

                    for(j=0;j<length-1;j++)
                    {

                        if(instrumentos[j].nombre>instrumentos[j+1].nombre)
                        {
                        buffer=instrumentos[j];
                        instrumentos[j]=instrumentos[j+1];
                        instrumentos[j+1]=buffer;
                        flag=1;
                        retorno=0;
                        break;
                        }
                    }

                }
            }
        }while(flag);
    }return retorno;
}   */

/** \brief La funcion muestra los datos hardcodeados.
 *
 * \param la estructura
 * \param el tamaño y el id para contar.
 * \return no retorna nada.
 *
 */

 /*
void ins_mock(Instrumento* instrumentos, int length,int *contadorId)
{
    instrumentos[0].codigoinsiado =0;
    instrumentos[0].isEmpty=0;
    strcpy(instrumentos[0].apellido,"Stomboli");
    strcpy(instrumentos[0].nombre,"Carolina");
    strcpy(instrumentos[0].sexo,"f");
    strcpy(instrumentos[0].telefono,"1521767920");
    strcpy(instrumentos[0].mail,"carostomboli@hotmail.com");
    strcpy(instrumentos[0].fechaAinsiado,"21-03-2018");

    instrumentos[1].codigoinsiado =1;
    instrumentos[1].isEmpty=0;
    strcpy(instrumentos[1].apellido,"Sarubbi");
    strcpy(instrumentos[1].nombre,"Maria del carmen");
    strcpy(instrumentos[1].sexo,"f");
    strcpy(instrumentos[1].telefono,"4243-3403");
    strcpy(instrumentos[1].mail,"marita.sarubbi@gmail.com");
    strcpy(instrumentos[1].fechaAinsiado,"05-02-2017");

    instrumentos[2].codigoinsiado =2;
    instrumentos[2].isEmpty=0;
    strcpy(instrumentos[2].apellido,"Faundo");
    strcpy(instrumentos[2].nombre,"El hagge");
    strcpy(instrumentos[2].sexo,"m");
    strcpy(instrumentos[2].telefono,"4245-8977");
    strcpy(instrumentos[2].mail,"f.elhagge@hotmail.com");
    strcpy(instrumentos[2].fechaAinsiado,"18-12-2018");

    instrumentos[3].codigoinsiado =3;
    instrumentos[3].isEmpty=0;
    strcpy(instrumentos[3].apellido,"Moreno");
    strcpy(instrumentos[3].nombre,"Catalina");
    strcpy(instrumentos[3].sexo,"f");
    strcpy(instrumentos[3].telefono,"1533524848");
    strcpy(instrumentos[3].mail,"catalinamoreno@gmail.com");
    strcpy(instrumentos[3].fechaAinsiado,"29-04-2019");

}
*/

#endif // INSTRUMENTO_C_INCLUDED
