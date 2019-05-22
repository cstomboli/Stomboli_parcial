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
                    switch (utn_getInSimple("\nIngrese una opcion:\n1-Listar Orquesta por lugar: \n2-Musicos menores de 25 años: \n3-Orquesta con menos de 6 musicos: \n4-Instrumentos de una orquesta determinada: \n5- \n6-Cantidad de Musicos y promedio de Edad: \n7-: \n8-Musicos que no tocan instrumento de viento: \n9-Salir: \n"))
                    {
                        case 1:
                            inf_mostrarOrquesta(orquestas,lengthOr);
                            break;
                        case 2:
                            inf_musicoMenor(orquestas,instrumentos,list3,lengthOr,lengthIns,lengthMus);
                            break;
                        case 3:
                            inf_menosIntegrantesPorOrquesta(list3,orquestas,lengthMus,lengthOr);
                            break;
                         case 4:
                            mus_cantidadPorOrquesta ( list3, lengthMus);
                            break;
                        case 5:
                            inf_InsOrq(instrumentos,orquestas,list3,lengthIns,lengthOr,lengthMus);
                            break;
                        case 6:
                            mus_cantidadYpromedio ( list3,  lengthMus);
                            break;
                          case 7:
                            mus_cantidadYpromedio ( list3,  lengthMus);
                            break;
                        case 8:
                            inf_musNoViento(list3,instrumentos,lengthMus,lengthIns);
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

int inf_mostrarOrquesta(Orquesta* orquestas, int length)
{
    int i;
    int retorno=-1;
    char buffer[30];

    utn_getName("Ingrese lugar Orquesta","Error",2,30,2,buffer);
    printf("%s",buffer);
    for (i=0; i<length; i++)
    {
        if(orquestas[i].isEmpty==0)
        {
            if(strncmp(orquestas[i].lugar,buffer,length)==0)
            {
                printf("\n Id de la orquesta: %d",orquestas[i].IdOrquesta);
                printf("\n Nombre: %s",orquestas[i].nombre);
                printf("\n Nombre: %s",orquestas[i].lugar);

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
            }

            retorno=0;
        }
    }
    return retorno;
}

int inf_musicoMenor (Orquesta* orquestas, Instrumento* instrumentos, Musico* list3,int lengthOrq, int lengthIns, int lengthMus)
{
    int i;
    int retorno=-1;

    if((list3 != NULL && lengthMus > 0) && (orquestas != NULL && lengthOrq > 0) && (instrumentos != NULL && lengthIns> 0))
    {
        for(i=0; i<=lengthMus; i++)
        {
            if(list3[i].isEmpty == 0)
            {
                if(list3[i].edad<25)
                {
                    printf("\n\nId de musico: %d",list3[i].IdMusico);
                    printf("\nNombre: %s",list3[i].nombre);
                    printf("\nApellido: %s",list3[i].apellido);
                    printf("\nEdad: %d",list3[i].edad);
                    printf("\nNombre del Instrumento: %s", instrumentos[i].nombre);
                    printf("\nNombre de la Orquesta: %s\n", orquestas[i].nombre);
                }
            }
        }retorno=0;
    }
    return retorno;
}

int inf_menosIntegrantesPorOrquesta (Musico* arrayMusicos, Orquesta* arrayOrquesta,int lengthMus, int lengthOrq)
{
    int retorno=-1;
    int i;
    int contadorMusicos=0;
    ///int acumuladorMus=0;

    if((arrayMusicos != NULL && lengthMus>0) && (arrayOrquesta != NULL && lengthOrq>0 ))
    {
        for(i=0;i<lengthMus;i++)
        {
            if(arrayMusicos[i].isEmpty==0)
            {
                contadorMusicos++;
                if(arrayMusicos[i].IdOrquesta==1 && contadorMusicos>2)
                {
                    printf("%d",arrayMusicos[i].IdOrquesta);
                    break;
                }
            }

        }retorno=0;
    }
    return retorno;
}

int inf_InsOrq (Instrumento* arrayInstr, Orquesta* arrayOrq, Musico* arrayMus, int lengthIns, int lengthOrq, int lengthMus)
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

/** \brief  Cuenta la cantidad de instrumentos.
 *
 * \param   Recibe la Estructura Instrumentos.
 * \param   El tamaño de la misma.
 * \return  -1 si no pudo contar, 0 Si pudo.
 *
 */
int inf_musNoViento (Musico* arrayMusicos, Instrumento* instrumentos,int lengthMus, int length)
{
    int i;
    int retorno = -1;

    if((instrumentos != NULL && length > 0) && (arrayMusicos != NULL && lengthMus > 0))
    {
        for(i=0; i<=length; i++)
        {
            if(instrumentos[i].isEmpty == 0 && arrayMusicos[i].isEmpty == 0)
            {
                if(arrayMusicos[i].IdInstrumento!=2 &&instrumentos[i].tipo!=3)
                {
                    mus_ordenar(arrayMusicos,length);
                    printf("\nNombre: %s",arrayMusicos[i].nombre);
                    printf("\nApellido: %s",arrayMusicos[i].apellido);
                    printf("\nId Orquesta: %d",arrayMusicos[i].edad);
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
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}





















////////////////////////////////////////// INFORMES ORQUESTAS ////////////////////////////////////

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

/** \brief Informa el instrumento mas solicitado
 *
 * \param arrayMusicos Musico*
 * \param arrayAux[] InstrumentoAuxiliar
 * \param arrayInstrumento Instrumento*
 * \param sizeArray int
 * \return int
 *
 */

 /*
int informes_instrumentoMasUsado(Musico* arrayMusicos, InstrumentoAuxiliar arrayAux[], Instrumento* arrayInstrumento, int sizeArray)
{
    int retorno=-1;
    int i,j;
    int posicionAuxiliar = 0;
    if(arrayMusicos!= NULL && sizeArray>=0 && arrayAux != NULL && arrayInstrumento != NULL)
    {
        informes_initInstrmentoAuxiliar(arrayAux, sizeArray);
        for(i=0;i<sizeArray;i++)
        {
            if(arrayMusicos[i].isEmpty==1)
                continue;
            else
            {
                arrayAux[posicionAuxiliar].idInstrumento = arrayMusicos[i].idInstrumento;
                arrayAux[posicionAuxiliar].isEmpty = 0;
                for(j=0;j<20;j++)
                {
                    if(arrayAux[posicionAuxiliar].idInstrumento == arrayInstrumento[j].idInstrumento)
                    {
                        strcpy (arrayAux[posicionAuxiliar].nombre, arrayInstrumento[j].nombre);
                        arrayAux[posicionAuxiliar].tipo = arrayInstrumento[j].tipo;
                        break;
                    }
                }
                posicionAuxiliar++;
            }
        }
        retorno =0;
    }
}

*/




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
        printf("Los musicos que tocan un instrumentos de tipo Cuerdas son: %d \n",contadorCuerdas);
        printf("Los musicos que tocan un instrumentos de tipo Viento Madera son: %d \n",contadorMadera);
        printf("Los musicos que tocan un instrumentos de tipo Viento Metal son: %d \n",contadorMetal);
        printf("Los musicos que tocan un instrumentos de tipo percusion son: %d \n",contadorPercusion);
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
    float contadorMusicos=0;
    float acumuladorEdad=0;
    int contadorSuperan=0;
    float promedio;

    if(list3 != NULL && length > 0)
    {

        for(i=0; i<=length; i++)
        {
            if(list3[i].isEmpty == 0)
            {
                contadorMusicos++;
                acumuladorEdad+= list3[i].edad;
                retorno=0;
            }
        }
        promedio=acumuladorEdad/contadorMusicos;
        for(i=0; i<=length; i++)
        {
            if(list3[i].isEmpty == 0 && list3[i].edad>promedio)
            {
                contadorSuperan++;
            }
        }
        printf("Los musicos son: %.2f \n",contadorMusicos);
        printf("El promedio de edad de los musicos es: %.2f \n",promedio);
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
