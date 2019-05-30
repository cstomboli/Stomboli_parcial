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

/** \brief La funcion muestra el menu de informes
 *
 * \param   Recibe la estructura Instrumento y su tamaño.
 * \param   Recibe la estructura Orquesta y su tamaño.
 * \param   Recibe la estructura Musico y su tamaño.
 * \return
 *
 */
void informes (Orquesta* arrayOrquestas, int lengthOrq, Instrumento* arrayInstrumentos, int lengthIns, Musico* arrayMusicos, int lengthMus)
{
    char seguir='s';
    if(arrayOrquestas != NULL && lengthOrq > 0)
    {
        if(arrayInstrumentos != NULL && lengthIns > 0)
        {
            if(arrayMusicos != NULL && lengthMus > 0)
            {
                while(seguir=='s')
                {
                    switch (utn_getInSimple("\nIngrese una opcion:\n1-Listar Orquesta por lugar: \n2-Musicos menores de 25: \n3-Orquesta con menos de 6 musicos: \n4-Instrumentos de una orquesta determinada: \n5- Orquesta completa \n6- Orquesta con menos musicos: \n7-Promedio de Instrumentos por Orquesta: \n8-Musicos que no tocan instrumento de viento: \n9-Salir: \n"))
                    {
                        case 1:
                            inf_OrquestaPorLugar(arrayOrquestas,lengthOrq);
                            break;
                        case 2:
                            inf_musicoMenor(arrayOrquestas,arrayInstrumentos,arrayMusicos,lengthOrq,lengthIns,lengthMus);
                            break;
                        case 3:
                            inf_menosIntegrantesPorOrquesta(arrayMusicos,arrayOrquestas,lengthMus,lengthOrq);
                            break;
                         case 4:
                            inf_InstrumentosOrq(arrayInstrumentos,arrayOrquestas,arrayMusicos,lengthIns,lengthOrq,lengthMus);
                        case 5:
                             inf_orquestaCompleta(arrayInstrumentos, arrayOrquestas,arrayMusicos, lengthIns,lengthOrq,lengthMus);
                            break;
                        case 6:
                            inf_menosMusicosPorOrquesta(arrayMusicos,arrayOrquestas,lengthMus,lengthOrq);
                            break;
                          case 7:
                            inf_promedioPorInstrumento (arrayOrquestas,arrayMusicos,lengthOrq,lengthMus);
                            break;
                        case 8:
                            inf_ordenar(arrayMusicos,lengthMus);
                            inf_musNoViento(arrayMusicos,arrayInstrumentos,lengthMus,lengthIns);
                            break;
                        case 9:
                            seguir= 'n';
                            break;
                    }
                }
            }
        }
    }
}

/** \brief La funcion Pide y muestra Orquesta segun el Lugar ingresado.
 *
 * \param   Recibe la estructura Orquesta.
 * \param   El tamaño de la misma.
 * \return  Retorno 0, si pudo recorrer y listar. -1 si no pudo.
 *
 */
int inf_OrquestaPorLugar(Orquesta* arrayOrquestas, int length)
{
    int i;
    int retorno=-1;
    char buffer[30];

    utn_getName("\nIngrese lugar Orquesta","Error",2,30,2,buffer);
    for (i=0; i<length; i++)
    {
        if(arrayOrquestas[i].isEmpty==0)
        {
            if(strncmp(arrayOrquestas[i].lugar,buffer,length)==0)
            {
                printf("\n Id de la orquesta: %d",arrayOrquestas[i].IdOrquesta);
                printf("\n Nombre: %s",arrayOrquestas[i].nombre);
                printf("\n Nombre: %s",arrayOrquestas[i].lugar);

                switch(arrayOrquestas[i].tipo)
                {
                    case 1:
                        printf("\n Tipo: Sinfonica\n");
                        break;
                    case 2:
                        printf("\n Tipo: Viento de Filarmonica\n");
                        break;
                    case 3:
                        printf("\n Tipo Viento de Camara\n");
                        break;
                }
            }
            retorno=0;
        }
    }
    return retorno;
}

/** \brief  La funcion lista los musicos menores de 25 años.
 *
 * \param   Recibe la estructura Instrumento y su tamaño.
 * \param   Recibe la estructura Orquesta y su tamaño.
 * \param   Recibe la estructura Musico y su tamaño.
 * \return  o si puedo recorrer las estructuras y listar en caso de encontrarlo. -1 si no pudo.
 *
 */
int inf_musicoMenor (Orquesta* arrayOrquestas, Instrumento* arrayInstrumentos, Musico* musicos,int lengthOrq, int lengthIns, int lengthMus)
{
    int i;
    int retorno=-1;

    if((musicos != NULL && lengthMus > 0) && (arrayOrquestas != NULL && lengthOrq > 0) && (arrayInstrumentos != NULL && lengthIns> 0))
    {
        for(i=0; i<=lengthMus; i++)
        {
            if((musicos[i].isEmpty == 0) && (arrayInstrumentos[i].isEmpty == 0) && (arrayOrquestas[i].isEmpty == 0))
            {
                if(musicos[i].edad<25)
                {
                    ///fflush (stdin);
                    /// __fopurgue(stdin)  PARA LINUX
                    printf("\n\nId de musico: %d",musicos[i].IdMusico);
                    printf("\nNombre: %s",musicos[i].nombre);
                    printf("\nApellido: %s",musicos[i].apellido);
                    printf("\nEdad: %d",musicos[i].edad);
                    printf("\nNombre del Instrumento: %s", arrayInstrumentos[i].nombre);
                    printf("\nNombre de la Orquesta: %s \n", arrayOrquestas[i].nombre); ///tira basura
                }
            }
        }retorno=0;
    }
    return retorno;
}

/** \brief La funcion lista las orquestas que tienen menos de 6 musicos
 *
 * \param Recibe la estructura Instrumento y su tamaño.
 * \param Recibe la estructura Orquesta y su tamaño.
 * \return
 *
 */
int inf_menosIntegrantesPorOrquesta (Musico* arrayMusicos, Orquesta* arrayOrquestas,int lengthMus, int lengthOrq)
{
    int retorno=-1;
    int i;
    int j;
    int contadorMusicos=0;
    int buffer;
    ///int acumuladorMus=0;

    if((arrayMusicos != NULL && lengthMus>0) && (arrayOrquestas != NULL && lengthOrq>0 ))
    {
        for(i=0;i<lengthOrq;i++)
        {
            if(arrayOrquestas[i].isEmpty==0)
            {
                buffer=arrayOrquestas[i].IdOrquesta;
                for(j=0;j<lengthMus;j++)
                {
                    if(arrayMusicos[j].isEmpty==0)
                    {
                        if(arrayMusicos[j].IdOrquesta==buffer)
                        {
                            contadorMusicos++;
                        }
                        if(contadorMusicos>6)
                        {
                            printf("\nEl id de la orquesta que tiene mas de 6 integrantes es: %d",arrayMusicos[i].IdOrquesta);
                            printf("\nEl nombre de la orquesta que tiene mas de 6 integrantes es: %s",arrayOrquestas[i].nombre);
                            break;
                        }
                    }

                }retorno=0;
            }   contadorMusicos=0;
         }
    }
    return retorno;
}

/** \brief La funcion pide el Id de una orquesta y Lista el nombre del musico, el nombre y tipo del instrumento.
 *
 * \param Recibe la estructura Instrumento y su tamaño.
 * \param Recibe la estructura Orquesta y su tamaño.
 * \param Recibe la estructura Musico y su tamaño.
 * \return  Devuelve menos 1, si no puede encontrar el id y listar los datos. = si puede.
 *
 */
int inf_InstrumentosOrq (Instrumento* arrayInstr, Orquesta* arrayOrq, Musico* arrayMus, int lengthIns, int lengthOrq, int lengthMus)
{
    int i;
    int retorno=-1;
    int buffer;
    if((arrayInstr != NULL && lengthIns>0) && (arrayOrq != NULL && lengthOrq>0 ))
    {
        utn_getInt("ingrese id de la Orquesta","Error",1,100,2,&buffer);

        for (i=0; i<lengthIns; i++)
        {
            if(arrayInstr[i].isEmpty==0)
            {
                if(arrayOrq[i].IdOrquesta==buffer && arrayMus[i].IdOrquesta==buffer)
                {

                    printf("\nNombre: %s",arrayMus[i].nombre);
                    printf("\nNombre: %s",arrayInstr[i].nombre);
                    switch(arrayInstr[i].tipo)
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
                }
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief  La funcion lista la orquesta completa.
 *
 * \param   Estructura Musico y el tamaño de la misma
 * \param   Estructura Orquesta y el tamaño de la misma
 * \param   Estructura Instrumento y el tamaño de la misma
 * \return  0 si pudo recorrer y contar los tipo de instrumentos.-1 si no pudo
 *
 */
int inf_orquestaCompleta (Instrumento* arrayInstrumentos, Orquesta* arrayOrq, Musico* arrayMusicos,int lengthIns, int lengthOrq, int lengthMus)
{
    int i;
    int j;
    int k;
    int retorno = -1;
    int contadorCuerdas=0;
    int contadorViento=0;
    int contadorPercusion=0;

    if((arrayMusicos != NULL && lengthMus > 0) && (arrayOrq != NULL && lengthOrq > 0) && (arrayInstrumentos != NULL && lengthIns > 0))
    {
        for(i=0; i<=lengthOrq; i++)
        {
            if(arrayOrq[i].isEmpty== 0)
            {
                for(j=0;j<lengthMus;j++)
                {
                    if(arrayMusicos[j].isEmpty== 0)
                    {
                        for(k=0; k<=lengthIns; k++)
                        {
                            if(arrayInstrumentos[k].isEmpty== 0)
                            {
                                if((arrayMusicos[j].IdOrquesta==arrayOrq[i].IdOrquesta) && (arrayMusicos[j].IdInstrumento==arrayInstrumentos[k].IdInstrumento))
                                {
                                    switch(arrayInstrumentos[k].tipo)
                                    {
                                        case 1:
                                            contadorCuerdas++;
                                            break;
                                        case 2:
                                            contadorViento++;
                                            break;
                                        case 3:
                                            contadorViento++;
                                            break;
                                        case 4:
                                            contadorPercusion++;
                                            break;
                                    }
                                }
                            }
                        }
                    }
                }
                if(contadorCuerdas>=4 && contadorViento>=4 && contadorPercusion>=1)
                {
                    printf("Orquesta completa %d", arrayOrq[i].IdOrquesta);

                }
                retorno = 0;
                contadorCuerdas=0;
                contadorViento=0;
                contadorPercusion=0;
            }
        }
    }
    return retorno;
}


/** \brief La funcion informa el Id de la orquesta que tiene menos musicos.
 *
 * \param   Estructura Musico y el tamaño de la misma
 * \param   Estructura Orquesta y el tamaño de la misma
 * \return  o si encontro y pudo listarla o -1 si no pudo.
 *
 */
int inf_menosMusicosPorOrquesta (Musico* arrayMusicos, Orquesta* arrayOrquestas,int lengthMus, int lengthOrq)
{
    int retorno=-1;
    int i;
    int j;
    int contadorMusicos=0;
    int buffer;
    int bufferMin=1000;
    int bufferMax=0;

    if((arrayMusicos != NULL && lengthMus>0) && (arrayOrquestas != NULL && lengthOrq>0 ))
    {
        for(i=0;i<lengthOrq;i++)
        {
            if(arrayOrquestas[i].isEmpty==0)
            {
                buffer=arrayOrquestas[i].IdOrquesta;
                for(j=0;j<lengthMus;j++)
                {
                    if(arrayMusicos[j].isEmpty==0)
                    {
                        if(arrayMusicos[j].IdOrquesta==buffer)
                        {
                            contadorMusicos++;
                        }
                    }
                }
                if(contadorMusicos>bufferMax)
                {
                    bufferMax=contadorMusicos;
                }
                else if(contadorMusicos<=bufferMin)
                {
                    bufferMin=contadorMusicos;
                    printf("\nEl id de la orquesta que tiene menos integrantes es: %d",arrayOrquestas[i].IdOrquesta);
                    retorno=0;
                }
                contadorMusicos=0;
            }

         }
    }
    return retorno;
}

/** \brief  Cuenta la Cantidad de musicos y saca el promedio por Orquesta.
 *
 * \param   Estructura Musico y el tamaño de la misma
 * \param   Estructura Orquesta y el tamaño de la misma
 * \return  -1 si no pudo contar, 0 Si pudo.
 *
 */
int inf_promedioPorInstrumento (Orquesta* arrayOrquestas, Musico* musicos, int lengthOrq, int lengthMus)
{
    int i;
    int retorno = -1;
    float contadorInstrumentos=0;
    float contadorOrquestas=0;
    float promedio;

    if((musicos != NULL && lengthMus > 0) && (arrayOrquestas != NULL && lengthOrq > 0))
    {
        for(i=0; i<=lengthMus; i++)
        {
            if(musicos[i].isEmpty == 0)
            {
                contadorInstrumentos++;
            }
        }
        for(i=0; i<=lengthOrq; i++)
        {
            if(arrayOrquestas[i].isEmpty == 0)
            {
                contadorOrquestas++;
            }
        }
        retorno=0;
    }
    promedio=contadorInstrumentos/contadorOrquestas;
    printf("El promedio de musicos por Orquesta es: %.2f \n",promedio);
    return retorno;
}

/** \brief  La funcion busca los musicos que tocan Instrumentos de Viento.
 *
 * \param   Recibe la Estructura Musico y el tamaño de la misma.
 * \param   Recibe la Estructura Instrumento y el tamaño de la misma.
 * \return  -1 si no pudo contar, 0 Si pudo.
 *
 */
int inf_musNoViento (Musico* arrayMusicos, Instrumento* arrayInstrumentos,int lengthMus, int lengthIns)
{
    int i;
    int j;
    int retorno = -1;

    if((arrayInstrumentos != NULL && lengthIns > 0) && (arrayMusicos != NULL && lengthMus > 0))
    {
        for(i=0; i<=lengthMus; i++)
        {
            if(arrayMusicos[i].isEmpty == 0)
            {
                for(j=0;j<lengthIns;j++)
                {
                    if(arrayInstrumentos[j].isEmpty == 0)
                    {
                        if(arrayMusicos[i].IdInstrumento==arrayInstrumentos[j].IdInstrumento)
                        {
                            if(arrayInstrumentos[j].tipo!=2 &&arrayInstrumentos[j].tipo!=3)
                            {

                                printf("\nNombre: %s",arrayMusicos[i].nombre);
                                printf("\nApellido: %s",arrayMusicos[i].apellido);
                                printf("\nId Orquesta: %d",arrayMusicos[i].IdOrquesta);
                                printf("\nNombre del Instrumento: %s", arrayInstrumentos[j].nombre);
                                switch(arrayInstrumentos[j].tipo)
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

                    }

                }

            }
        }
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
int inf_ordenar (Musico* arrayMus,int lengthMus)
{
    int j;
    int flag;
    Musico buffer;
    int retorno=-1;

    if(arrayMus != NULL && lengthMus > 0)
    {
        do
        {
            flag=0;
            for(j=0;j<lengthMus-1;j++)
            {
                if(arrayMus[j].isEmpty == 0)
                {
                    if(strncmp(arrayMus[j].apellido,arrayMus[j+1].apellido,lengthMus) > 0)
                    {
                        buffer=arrayMus[j];
                        arrayMus[j]=arrayMus[j+1];
                        arrayMus[j+1]=buffer;
                        flag=1;
                        break;
                    }

                    else if(strncmp(arrayMus[j].apellido,arrayMus[j+1].apellido,lengthMus) == 0)
                    {
                        if(strncmp(arrayMus[j].nombre,arrayMus[j+1].nombre,lengthMus) > 0)
                        {
                            buffer=arrayMus[j];
                            arrayMus[j]=arrayMus[j+1];
                            arrayMus[j+1]=buffer;
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
