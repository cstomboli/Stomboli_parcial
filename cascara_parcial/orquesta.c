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

/*
int informar (Orquesta* orquestas,int length)
{
   int retorno=-1;
   char seguir='s';


    while(seguir=='s')
    {
        switch(utn_getInSimple("Ingrese una opcion a Informar\n1- Listado Ordenado por Apellido y Sector: \n2- Salario Total y Promedio: \n3- Salir\n"))
        {
            case 1:
                sortOrquesta(orquestas, length);
                printOrquesta(orquestas,length);
            break;

            case 2:
                emp_promedio(orquestas, length);
            break;

            case 3:
                retorno=0;
                seguir= 'n';
            break;
        }
    }

    return retorno;
}

int orq_promedio (Orquesta* orquestas, int length)
{
    int i;
    int retorno = -1;
    float acumuladorSalary=0;
    int contadorEmpleados=-1;
    int contadorEmpleadosQueSuperan=0;
    float promedio;

    if(orquestas != NULL && length > 0)
    {
        for(i=0; i<=length; i++)
        {
            if(orquestas[i].isEmpty == 0)
            {
                acumuladorSalary += orquestas[i].salary;
                contadorEmpleados++;
            }
        }
        promedio = acumuladorSalary / contadorEmpleados;
        for(i=0; i<=length; i++)
        {
            if(orquestas[i].salary >promedio)
            {

                contadorEmpleadosQueSuperan++;
            }
        }
        printf("El total de los salarios es: %.2f \n",acumuladorSalary);
        printf("El promedio de los Salarios es: %.2f \n",promedio);
        printf("Los empleados que superan el salario Promedio Son: %d \n",contadorEmpleadosQueSuperan);
        retorno = 0;
    }
    return retorno;
}
*/

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
                if(!utn_getInt("Tipo de Orquesta:\n 1- Sinfonica: \n2- Filarmonica: \n3- Camara","Invalido, reingrese:\n",1,1,2,&bufferTipo))
                {
                    if(!utn_getTelefono("Telefono:\n","Invalido, reingrese:\n",4,20,2,bufferTel))
                    {
                       if(!utn_getMail("Mail:\n","Invalido, reingrese:\n",8,30,2,bufferMail))
                       {
                            if(!utn_fechaNacimiento("Fecha de Nacimiento dd-mm-aaaa sin guiones por favor:\n","Invalido, reingrese:\n",8,15,2,bufferFecha))
                            {
                                strncpy(orquestas[posLibre].nombre,bufferName,sizeof(bufferName));
                                strncpy(orquestas[posLibre].apellido,bufferLastName,sizeof(bufferLastName));
                                strncpy(orquestas[posLibre].sexo,bufferSexo,sizeof(bufferSexo));
                                strncpy(orquestas[posLibre].telefono,bufferTel,sizeof(bufferTel));
                                strncpy(orquestas[posLibre].mail,bufferMail,sizeof(bufferMail));
                                strncpy(orquestas[posLibre].fechaAorqiado,bufferFecha,sizeof(bufferFecha));
                                orquestas[posLibre].codigoorqiado=generarId();
                                orquestas[posLibre].isEmpty=0;
                                retorno=0;
                            }
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
        if (orquestas[i].codigoorqiado==*id)
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

    orq_mostrar(orquestas,length);

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
            printf("\n Codigo de orqio: %d",orquestas[i].codigoorqiado);
            printf("\n Apellido: %s",orquestas[i].apellido);
            printf("\n Nombre: %s",orquestas[i].nombre);
            printf("\n Sexo: %s",orquestas[i].sexo);
            printf("\n Telefono: %s", orquestas[i].telefono);
            printf("\n Mail: %s",orquestas[i].mail);
            printf("\n Fecha aorqiado: %s\n\n",orquestas[i].fechaAorqiado);
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
int orq_ordenar (Orquesta* orquestas,int length)
{
    int j;
    int flag;
    Orquesta buffer;
    int retorno=-1;

    if(orquestas != NULL && length>0)
    {
        do
        {
            flag=0;
            for(j=0;j<length-1;j++)
            {
                if(strcmp(orquestas[j].apellido,orquestas[j+1].apellido)>0)
                {
                    buffer=orquestas[j];
                    orquestas[j]=orquestas[j+1];
                    orquestas[j+1]=buffer;
                    flag=1;
                    retorno=0;
                    break;

                    for(j=0;j<length-1;j++)
                    {

                        if(orquestas[j].nombre>orquestas[j+1].nombre)
                        {
                        buffer=orquestas[j];
                        orquestas[j]=orquestas[j+1];
                        orquestas[j+1]=buffer;
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
void orq_mock(Orquesta* orquestas, int length,int *contadorId)
{
    orquestas[0].codigoorqiado =0;
    orquestas[0].isEmpty=0;
    strcpy(orquestas[0].apellido,"Stomboli");
    strcpy(orquestas[0].nombre,"Carolina");
    strcpy(orquestas[0].sexo,"f");
    strcpy(orquestas[0].telefono,"1521767920");
    strcpy(orquestas[0].mail,"carostomboli@hotmail.com");
    strcpy(orquestas[0].fechaAorqiado,"21-03-2018");

    orquestas[1].codigoorqiado =1;
    orquestas[1].isEmpty=0;
    strcpy(orquestas[1].apellido,"Sarubbi");
    strcpy(orquestas[1].nombre,"Maria del carmen");
    strcpy(orquestas[1].sexo,"f");
    strcpy(orquestas[1].telefono,"4243-3403");
    strcpy(orquestas[1].mail,"marita.sarubbi@gmail.com");
    strcpy(orquestas[1].fechaAorqiado,"05-02-2017");

    orquestas[2].codigoorqiado =2;
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

}


#endif // ORQUESTA_C_INCLUDED
