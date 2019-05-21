#ifndef INFORMES_C_INCLUDED
#define INFORMES_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"
#include "utn.h"
#include "informes.h"

void informes (Orquesta* orquestas, int lengthOr, Instrumento* instrumentos, int lengthIns, Musico* list3, int lengthMus)
{
    char seguir='s';
    if(orquestas != NULL && lengthOr > 0)
    {
        if(instrumentos != NULL && lengthIns > 0)
        {
            if(list3 != NULL && lengthMus > 0)
            {
                while(seguir=='s')
                {
                    switch (utn_getInSimple("\nIngrese una opcion:\n1-Cantidad de Orquesta\n2-Cantidad de Orquesta por Tipo: \n3-Cantidad de Instrumentos: \n4-Cantidad de Musicos por Orquesta: \n5-Cantidad de Musicos por Tipo de Instrumento: \n6-Cantidad de Musicos y promedio de Edad: \n7-Ordenar: \n8-Salir: \n"))
                    {
                        case 1:
                            orq_cantidad (orquestas,  lengthOr);
                            break;
                        case 2:
                            orq_cantidadTipo (orquestas,  lengthOr);
                            break;
                        case 3:
                            ins_cantidad (instrumentos, lengthIns);
                            break;
                         case 4:
                            mus_cantidadPorOrquesta ( list3, lengthMus);
                            break;
                        case 5:
                            mus_cantidadPorTipoInstrumento ( list3, lengthMus); ///no anda
                            break;
                        case 6:
                            mus_cantidadYpromedio ( list3,  lengthMus); ///no anda
                            break;
                        case 7:
                            mus_ordenar (list3, lengthMus);
                            break;

                        case 8:
                            seguir= 'n';
                            break;
                    }
                }
            }
        }
    }
}

////////////////////////////////////////// INFORMES INSTRUMENTOS ////////////////////////////////////

/** \brief  Cantidad de orquestas por tipo.
 *
 * \param   Estructura Orquesta
 * \param   Tamaño de la misma
 * \return  -1 si no pudo ejecutarse, 0 si pudo.
 *
 */
int orq_cantidadTipo (Orquesta* orquestas, int length)
{
    int i;
    int retorno = -1;
    int contadorSinfonica=0;
    int contadorFiloarmonica=0;
    int contadorCamara=0;

    if(orquestas != NULL && length > 0)
    {
        for(i=0; i<=length; i++)
        {
            if(orquestas[i].isEmpty== 0)
            {
                switch(orquestas[i].tipo)
                {
                    case 1:
                        contadorSinfonica++;
                        break;
                    case 2:
                        contadorFiloarmonica++;
                        break;
                    case 3:
                        contadorCamara++;
                        break;
                }
            }
        }
        printf("Orquesta tipo Sinfonica: %d \n",contadorSinfonica);
        printf("Orquesta tipo Filoarmonica: %d \n",contadorFiloarmonica);
        printf("Orquesta tipo Camara: %d \n",contadorCamara);
        retorno = 0;
    }
    return retorno;
}

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

/** \brief  Cuenta la Cantidad de musicos por
 *          tipo de Orquesta.
 * \param   Estructura Musico
 * \param   Tamaño de la misma
 * \return  -1 si no pudo contar, 0 Si pudo.
 *
 */
int mus_cantidadPorOrquesta (Musico* list3, int length)
{
    int i;
    int retorno = -1;
    int contadorSinfonica=0;
    int contadorFiloarmonica=0;
    int contadorCamara=0;

    if(list3 != NULL && length > 0)
    {
        for(i=0; i<=length; i++)
        {
            if(list3[i].isEmpty== 0)
            {

                switch(list3[i].IdOrquesta)
                {
                    case 1:
                        contadorSinfonica++;
                        break;
                    case 2:
                        contadorFiloarmonica++;
                        break;
                    case 3:
                        contadorCamara++;
                        break;
                }

            }
        }
        printf("Los musicos de la Orquesta Sinfonica son: %d \n",contadorSinfonica);
        printf("Los musicos de la Orquesta Filoarmonica son: %d \n",contadorFiloarmonica);
        printf("Los musicos de la Orquesta Camara son: %d \n",contadorCamara);
        retorno = 0;
    }
    return retorno;
}

/** \brief  Cuenta la Cantidad de musicos por
 *          tipo de Instrumento.
 * \param   Estructura Musico
 * \param   Tamaño de la misma
 * \return  -1 si no pudo contar, 0 Si pudo.
 *
 */
int mus_cantidadPorTipoInstrumento (Musico* list3, int length)
{
    int i;
    int retorno = -1;
    int contadorCuerdas=0;
    int contadorMadera=0;
    int contadorMetal=0;
    int contadorPercusion=0;

    if(list3 != NULL && length > 0)
    {
        for(i=0; i<=length; i++)
        {
            if(list3[i].isEmpty== 0)
            {

                switch(list3[i].IdInstrumento)
                {
                    case 1:
                        contadorCuerdas++;
                        break;
                    case 2:
                        contadorMadera++;
                        break;
                    case 3:
                        contadorMetal++;
                        break;
                    case 4:
                        contadorPercusion++;
                        break;
                }

            }
        }
        printf("Los Instrumentos de tipo Cuerdas son: %d \n",contadorCuerdas);
        printf("Los Instrumentos cargados de tipo Viento Madera son: %d \n",contadorMadera);
        printf("Los Instrumentos cargados de tipo Viento Metal son: %d \n",contadorMetal);
        printf("Los Instrumentos cargados de tipo percusion son: %d \n",contadorPercusion);
        retorno = 0;
    }
    return retorno;
}


/** \brief Cuenta la cantidad de musicos que hay.
 *          y calcula el promedio de edades.
 * \param   Recibe la Estructura Musicos
 * \param   El tamaño de la misma.
 * \return  -1 si no pudo contar, 0 Si pudo.
 *
 */
int mus_cantidadYpromedio (Musico* list3, int length)
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
            if(list3[i].isEmpty == 0 && list3[i].edad >promedio)
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
    int flag;
    Musico buffer;
    int retorno=-1;

    if(list3 != NULL && length > 0)
    {

        do
        {
            flag=0;
            for(j=0;j<length-1;j++)
            {
                if(list3[j].isEmpty == 0)
                {
                    if(strncmp(list3[j].apellido,list3[j+1].apellido,length) > 0)
                    {
                        buffer=list3[j];
                        list3[j]=list3[j+1];
                        list3[j+1]=buffer;
                        flag=1;
                        break;
                    }

                    else if(strncmp(list3[j].apellido,list3[j+1].apellido,length) == 0)
                    {
                        if(strncmp(list3[j].nombre,list3[j+1].nombre,length) > 0)
                        {
                            buffer=list3[j];
                            list3[j]=list3[j+1];
                            list3[j+1]=buffer;
                            flag=1;
                            break;
                        }
                    }
                }
            }

        }while(flag);
        retorno=0;
    }
    return retorno;
}



#endif // INFORMES_C_INCLUDED
