#ifndef INFORMES_C_INCLUDED
#define INFORMES_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"
#include "utn.h"

////////////////////////////////////////// INFORMES INSTRUMENTOS ////////////////////////////////////


/** \brief  Cuenta la cantidad de Orquestas.
 *
 * \param   Recibe la Estructura Orquesta.
 * \param   El tamaño de la misma.
 * \return  -1 si no pudo contar, 0 Si pudo.
 *
 */
int orq_cantidad (Orquesta* orquestas, int length)
{
    int i;
    int retorno = -1;
    int contadorOrquestas=0;

    if(orquestas != NULL && length > 0)
    {
        for(i=0; i<=length; i++)
        {
            if(orquestas[i].isEmpty== 0)
            {
                contadorOrquestas++;
            }
        }
        printf("Las orquestas son: %d \n",contadorOrquestas);
        retorno = 0;
    }
    return retorno;
}



////////////////////////////////////////// INFORMES INSTRUMENTOS ////////////////////////////////////


/** \brief  Cuenta la cantidad de instrumentos.
 *
 * \param   Recibe la Estructura Instrumentos.
 * \param   El tamaño de la misma.
 * \return  -1 si no pudo contar, 0 Si pudo.
 *
 */
int ins_cantidad (Instrumento* instrumentos, int length)
{
    int i;
    int retorno = -1;
    int contadorInstrumentos=0;
    int contadorCuerdas=0;
    int contadorMadera=0;
    int contadorMetal=0;
    int contadorPercusion=0;

    if(instrumentos != NULL && length > 0)
    {
        for(i=0; i<=length; i++)
        {
            if(instrumentos[i].isEmpty == 0)
            {
                contadorInstrumentos++;
                if(instrumentos[i].tipo==1)
                {
                    contadorCuerdas++;
                }
                if(instrumentos[i].tipo==2)
                {
                    contadorMadera++;
                }
                if(instrumentos[i].tipo==3)
                {
                    contadorMetal++;
                }
                if(instrumentos[i].tipo==4)
                {
                    contadorPercusion++;
                }

            }
        }
        printf("Los Instrumentos cargados son: %d \n",contadorInstrumentos);
        printf("Los Instrumentos de tipo Cuerdas son: %d \n",contadorCuerdas);
        printf("Los Instrumentos cargados de tipo Viento Madera son: %d \n",contadorMadera);
        printf("Los Instrumentos cargados de tipo Viento Metal son: %d \n",contadorMetal);
        printf("Los Instrumentos cargados de tipo percusion son: %d \n",contadorPercusion);
        retorno = 0;
    }
    return retorno;
}













////////////////////////////////////////// INFORMES MUSICOS ////////////////////////////////////


/** \brief Cuenta la cantidad de musicos que hay.
 *
 * \param   Recibe la Estructura Musicos
 * \param   El tamaño de la misma.
 * \return  -1 si no pudo contar, 0 Si pudo.
 *
 */
int mus_cantidad (Musico* list3, int length)
{
    int i;
    int retorno = -1;
    int contadorMusicos=0;
    int acumuladorEdad=0;
    int contadorSuperan=0;
    int promedio;

    if(list3 != NULL && length > 0)
    {
        for(i=0; i<=length; i++)
        {
            if(list3[i].isEmpty == 0)
            {
                contadorMusicos++;
                acumuladorEdad += list3[i].edad;
                retorno=0;
            }
        }
        promedio=acumuladorEdad/contadorMusicos;
        for(i=0; i<=length; i++)
        {
            if(list3[i].edad >promedio)
            {

                contadorSuperan++;
            }
        }
        printf("Los musicos son: %d \n",contadorMusicos);
        printf("El promedio de edad de los musicos es: %d \n",promedio);
        printf("Supera el promedio de edad de los musicos : %d \n",contadorSuperan);
        retorno = 0;
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
    int i;
    int flag;
    Musico buffer;
    int retorno=-1;

    if(list3 != NULL && length>0)
    {
        retorno=0;
        do
        {
            flag=0;
            for(j=0;j<length-1;j++)
            {
                if(list3[j].isEmpty==1)
                {
                    continue;
                }
                if(strcmp(list3[j].apellido,list3[j+1].apellido)>0)
                {
                    buffer=list3[j];
                    list3[j]=list3[j+1];
                    list3[j+1]=buffer;
                    flag=1;
                }
                else if(strcmp(list3[j].apellido,list3[j+1].apellido)==0)
                {
                        for(i=0;i<length-1;i++)
                        {
                            if(list3[i].isEmpty==1)
                            {
                                continue;
                            }
                            if(strcmp(list3[i].nombre,list3[i+1].nombre)>0)
                            {
                                buffer=list3[i];
                                list3[i]=list3[i+1];
                                list3[i+1]=buffer;
                                flag=1;
                            }
                        }
                }

            }
        }while(flag);
    }return retorno;
}


#endif // INFORMES_C_INCLUDED
