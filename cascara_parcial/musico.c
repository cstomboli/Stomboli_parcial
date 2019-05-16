#ifndef MUSICO_C_INCLUDED
#define MUSICO_C_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mustasma.h"
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

/*
int informar (Musico* list3,int length)
{
   int retorno=-1;
   char seguir='s';


    while(seguir=='s')
    {
        switch(utn_getInSimple("Ingrese una opcion a Informar\n1- Listado Ordenado por Apellido y Sector: \n2- Salario Total y Promedio: \n3- Salir\n"))
        {
            case 1:
                sortMusico(list3, length);
                printMusico(list3,length);
            break;

            case 2:
                emp_promedio(list3, length);
            break;

            case 3:
                retorno=0;
                seguir= 'n';
            break;
        }
    }

    return retorno;
}

int mus_promedio (Musico* list3, int length)
{
    int i;
    int retorno = -1;
    float acumuladorSalary=0;
    int contadorEmpleados=-1;
    int contadorEmpleadosQueSuperan=0;
    float promedio;

    if(list3 != NULL && length > 0)
    {
        for(i=0; i<=length; i++)
        {
            if(list3[i].isEmpty == 0)
            {
                acumuladorSalary += list3[i].salary;
                contadorEmpleados++;
            }
        }
        promedio = acumuladorSalary / contadorEmpleados;
        for(i=0; i<=length; i++)
        {
            if(list3[i].salary >promedio)
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
 * \param   Tama�o de la misma
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
 * \param   Tama�o de la misma
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
 * \param   Tama�o de la misma
 * \param   Posicion donde va a guardar.
 * \return  0 si pudo dar de alta, -1 si no pudo.
 *
 */
int mus_alta(Musico* list3, char *msgError,int length)
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
                    if(!utn_getInt("A que Orquesta pertenece:\n1- Sinfonica: \n2- Filarmonica: \n3- Camara","Invalido, reingrese:\n",1,20,2,&bufferIdOrquesta))
                    {
                        if(!utn_getInt("Ingrese instrumento:\n","Invalido, reingrese:\n",1,20,2,&bufferIdInstrumento))

                       {
                                ///if(buscar orquesta por id)
                                strncpy(list3[posLibre].nombre,bufferName,sizeof(bufferName));
                                strncpy(list3[posLibre].apellido,bufferLastName,sizeof(bufferLastName));
                                strncpy(list3[posLibre].edad,bufferEdad,sizeof(bufferEdad));
                                list3[posLibre].IdOrquesta=bufferIdOrquesta;
                                list3[posLibre].IdInstrumento=bufferIdInstrumento();
                                list3[posLibre].IdMusico=generarId();
                                list3[posLibre].isEmpty=0;
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
 * \param   Tama�o de la misma
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
 * \param   Tama�o de la misma
 * \param   El id a buscar
 * \return  0 si pudo modificar, -1 si no pudo.
 *
 */
int mus_modificar (Musico* list3, int length,int*id)
{
    int retorno=-1;
    int bufferEdad;
    char bufferLastName [51];
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
                        list3[bufferId].
                        printf("Nombre modificado correctamente.\n");
                    }
                break;

                case 2:
                    if(!utn_getName("Ingrese Apellido:\n","Invalido, reingrese:\n",2,20,2,bufferLastName))
                        {
                        strncpy(list3[bufferId].apellido,bufferLastName,sizeof(bufferLastName));
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
 * \param   Tama�o de la misma
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
        if (list3[i].codigomusiado==*id)
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
 * \param   Tama�o de la misma
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
 * \param length Tama�o de la misma
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
            printf("\n Codigo de musio: %d",list3[i].codigomusiado);
            printf("\n Apellido: %s",list3[i].apellido);
            printf("\n Nombre: %s",list3[i].nombre);
            printf("\n Sexo: %s",list3[i].sexo);
            printf("\n Telefono: %s", list3[i].telefono);
            printf("\n Mail: %s",list3[i].mail);
            printf("\n Fecha amusiado: %s\n\n",list3[i].fechaAmusiado);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Ordena por 2 criterios
 *
 * \param  Recibe la Estructura
 * \param El tama�o de la misma
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
 * \param el tama�o y el id para contar.
 * \return no retorna nada.
 *
 */
void mus_mock(Musico* list3, int length,int *contadorId)
{
    list3[0].codigomusiado =0;
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


#endif // MUSICO_C_INCLUDED
