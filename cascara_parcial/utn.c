#ifndef UTN_C_INCLUDED
#define UTN_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#define TRUE 0
#define FALSE 1

/** \brief La funcion pide el ingreso de una  Fecha de Nacimiento.
 *
 * \param Recibe el mensaje a mostrar.
 * \param el mensaje de Error
 * \param minimos y maximos caracteres
 * \param Cantidad de Reintentos.
 * \param char Donde guarda el resultado.
 * \return int -1 si no logro guardar lo ingresado. 0 si puedo realizarlo con exito.
 *
 */
int utn_fechaNacimiento (char *msg, char *msgError, char minimo, char maximo, int reintentos, char *resultado)
{
    char buffer[20];
    int retorno=-1;

   if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(! utn_getString(msg, msgError, minimo, maximo, reintentos, buffer))
            {

                if(utn_isValidFecha(buffer)==TRUE)
                {
                    strncpy(resultado,buffer,sizeof(buffer));
                    retorno=0;
                    break;
                }
                else
                {
                    printf("Fecha de Nacimiento invalida");
                    reintentos --;
                }
            }
            else
            {
                printf("%s",msgError);
                break;
            }

        }while(reintentos>=0);
    }
    return retorno;
}

/** \brief Valida que lo ingresado sean numeros
 *
 * \param char la cadena ingresada
 * \param
 * \return TRUE si es valido lo ingresado, FALSE si no lo es.
 *
 */
int utn_isValidFecha(char *cadena)
{
    int retorno=TRUE;
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!= '-' ))
        {
            retorno=FALSE;
        }
    }
    return retorno;
}

/** \brief La funcion pide el ingreso de un Cuit.
 *
 * \param Recibe el mensaje a mostrar.
 * \param el mensaje de Error
 * \param minimos y maximos caracteres
 * \param Cantidad de Reintentos.
 * \param char Donde guarda el resultado.
 * \return int -1 si no logro guardar lo ingresado. 0 si puedo realizarlo con exito.
 *
 */
int utn_getCuit (char *msg, char *msgError, char minimo, char maximo, int reintentos, char *resultado)
{
     char buffer[30];
    int retorno=-1;

    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(! utn_getString(msg, msgError, minimo, maximo, reintentos, buffer))
            {
                if(utn_isValidCuit(buffer)==TRUE)
                {
                    strncpy(resultado,buffer,sizeof(buffer));
                    retorno=0;
                    break;
                }
                 else
                {
                    printf("Cuit invalido");
                    reintentos --;
                }
            }
            else
            {
                printf("%s",msgError);
                break;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

/** \brief Valida que lo ingresado sean numeros
 *
 * \param char la cadena ingresada
 * \param
 * \return TRUE si es valido lo ingresado, FALSE si no lo es.
 *
 */
int utn_isValidCuit (char *cadena)
{
    int retorno=TRUE;
    int i;
    for (i=0; cadena[i] != '\0'; i++)
    {
         if((cadena[i]<'0' || cadena[i]>'9') && ( cadena[i]!= '-'  ) )
        {
            retorno=FALSE;
        }
    }
    return retorno;
}

/** \brief La funcion pide el ingreso de un Dni.
 *
 * \param Recibe el mensaje a mostrar.
 * \param el mensaje de Error
 * \param minimos y maximos caracteres
 * \param Cantidad de Reintentos.
 * \param char Donde guarda el resultado.
 * \return int -1 si no logro guardar lo ingresado. 0 si puedo realizarlo con exito.
 *
 */
int utn_getDni (char *msg, char *msgError, char minimo, char maximo, int reintentos, char *resultado)
{
    char buffer[20];
    int retorno=-1;

    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(! utn_getString(msg, msgError, minimo, maximo, reintentos, buffer))
            {
                if(utn_isValidDni(buffer)==TRUE)
                {
                    strncpy(resultado,buffer,sizeof(buffer));
                    retorno=0;
                    break;
                }
                 else
                {
                    printf("Dni invalido");
                    reintentos --;
                }
            }
            else
            {
                printf("%s",msgError);
                break;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

/** \brief Valida que lo ingresado sean numeros
 *
 * \param char la cadena ingresada
 * \param
 * \return TRUE si es valido lo ingresado, FALSE si no lo es.
 *
 */
int utn_isValidDni (char *cadena)
{
    int retorno=TRUE;
    int i;

    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && ( cadena[i]!= '.'  ) )
        {
            retorno=FALSE;
        }
    }
    return retorno;
}

/** \brief La funcion pide el ingreso de un telefono.
 *
 * \param Recibe el mensaje a mostrar.
 * \param el mensaje de Error
 * \param minimos y maximos caracteres
 * \param Cantidad de Reintentos.
 * \param char Donde guarda el resultado.
 * \return int -1 si no logro guardar lo ingresado. 0 si puedo realizarlo con exito.
 *
 */
int utn_getTelefono (char *msg, char *msgError, char minimo, char maximo, int reintentos, char *resultado)
{
    char buffer[20];
    int retorno=-1;

   if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(! utn_getString(msg, msgError, minimo, maximo, reintentos, buffer))
            {

                if(utn_isValidTelephone(buffer)==TRUE)
                {
                    strncpy(resultado,buffer,sizeof(buffer));
                    retorno=0;
                    break;
                }
                else
                {
                    printf("Telefono invalido");
                    reintentos --;
                }
            }
            else
            {
                printf("%s",msgError);
                break;
            }

        }while(reintentos>=0);
    }
    return retorno;
}
/** \brief Valida que lo ingresado sean numeros
 *
 * \param char la cadena ingresada
 * \param
 * \return TRUE si es valido lo ingresado, FALSE si no lo es.
 *
 */
int utn_isValidTelephone(char *cadena)
{
    int retorno=TRUE;
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!= '-' ))
        {
            retorno=FALSE;
        }
    }
    return retorno;
}
/** \brief La funcion pide el ingreso de un numero.
 *
 * \param Recibe el mensaje a mostrar.
 * \param el mensaje de Error
 * \param minimos y maximos caracteres
 * \param Cantidad de Reintentos.
 * \param char Donde guarda el resultado.
 * \return int -1 si no logro guardar lo ingresado. 0 si puedo realizarlo con exito.
 *
 */
int utn_getInt (char *msg, char *msgError, char minimo, char maximo, int reintentos, int *resultado)
{
    char buffer[20];
    int retorno=-1;

   if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(! utn_getString(msg, msgError, minimo, maximo, reintentos, buffer))
            {

                if(utn_isValidInt(buffer)==TRUE)
                {
                    *resultado=atoi(buffer);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("Invalido");
                    reintentos --;
                }
            }
            else
            {
                printf("%s",msgError);
                break;
            }

        }while(reintentos>=0);
    }
    return retorno;
}
/** \brief Valida
 *
 * \param cadena
 * \param
 * \return TRUE FALSE
 *
 */
int utn_isValidInt (char *cadena)
{
    int retorno=TRUE;
    int i;
    for (i=0; cadena[i] != '\0'; i++)
    {
        if (cadena[i]<'0' || cadena[i]>'9')
        {
            retorno=FALSE;
        }
    }
    return retorno;

}


int utn_getFecha (char *msg, char *msgError, char minimo, char maximo, int reintentos, int *resultado)
{
    char buffer[20];
    int retorno=-1;
   if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(! utn_getString(msg, msgError, minimo, maximo, reintentos, buffer))
            {
                if(utn_isValidDia(buffer)==TRUE)
                {/*
                    if(utn_isValidMes(buffer)==TRUE)
                    {
                       if(utn_isValidAnio(buffer)==TRUE)
                       {
                        */
                           *resultado=atoi(buffer);
                            retorno=0;
                            break;


                }
                else
                {
                    printf("Fecha invalida");
                    reintentos --;
                }
            }
            else
            {
                printf("%s",msgError);
                break;
            }
        }while(reintentos>=0);
    }
    return retorno;
}
int utn_isValidDia (char *cadena)
{
    int retorno=TRUE;
    int i;
    for (i=0; cadena[i] == cadena[1]; i++)
    {
        if ( cadena[0]=='3' && cadena[1]>'1')
        {
            retorno=FALSE;

        }
    }printf("%d 1" ,retorno);
    return retorno;
}/*
int utn_isValidMes (char *cadena)
{
    int retorno=TRUE;
    int i;
    for (i=0; cadena[2] == cadena[3]; i++)
    {
        if ( cadena[2]!='0' || cadena[0]!='1')
        {
            if (( cadena[2]!='0') && (cadena[3]!='1' || cadena[3]!='2'))
            {
                retorno=FALSE;
            }
        }
    }printf("%d 2" ,retorno);
    return retorno;
}
int utn_isValidAnio (char *cadena)
{
    int retorno=TRUE;
    int i;
    for (i=0; cadena[4] == cadena[7]; i++)
    {
        if ( cadena[4] < '2' && cadena[5] < '0' && cadena[6] < '0' && cadena[7] < '0')
        {
            retorno=FALSE;
        }
    }printf("%d 3" ,retorno);
    return retorno;
}

*/

 /** \brief La funcion pide el ingreso de un Numero.
  *
  * \param A traves de un mensaje.
  * \param
  * \return Y retorna el mismo.
  *
  */

int utn_getInSimple (char msg[])
{
    int aux;

    printf("%s",msg);

    scanf("%d",&aux);

    return aux;
}
/** \brief La funcion pide el ingreso de un flotante.
 *
 * \param Recibe el mensaje a mostrar.
 * \param el mensaje de Error
 * \param minimos y maximos caracteres
 * \param Cantidad de Reintentos.
 * \param float Donde guarda el resultado.
 * \return int -1 si no logro guardar lo ingresado. 0 si puedo realizarlo con exito.
 *
 */
float utn_getFloat (char * msg, char * msgError, float minimo, float maximo, float reintentos, float * resultado)
{
    char buffer[20];
    float retorno= -1;

    if (msg != NULL && msgError != NULL && maximo> minimo && reintentos>= 0)
    {
        do
        {
            if(!utn_getString(msg,msgError,minimo,maximo,reintentos,buffer))
            {
                if (utn_isValidFloat(buffer))
                {
                    *resultado=atof(buffer);
                    retorno = 0;
                    break;
                }
                else
                {
                    printf ("Numero Invalido");
                    reintentos--;
                }
            }
            else
            {
                printf("%s",msgError);
                break;
            }
        }while (reintentos>=0);
    }
    return retorno;
}
/** \brief Valida que el numero este entre los maximos y minimos permitidos.
 *
 * \param float numero,
 * \param
 * \return 1 si es valido 0 si es invalido
 *
 */

float utn_isValidFloat (char *cadena)
{
    int retorno=TRUE;
    int i;
    for (i=0; cadena[i] != '\0'; i++)
    {
        if (( cadena[i]<'0' || cadena[i]>'9') && (cadena[i] !='.' || cadena[i] !=','))
        {
            retorno=FALSE;
        }
    }printf("%d",retorno);
    return retorno;

}

/** \brief La funcion pide el ingreso del Sexo.
 *
 * \param Recibe el mensaje a mostrar.
 * \param el mensaje de Error
 * \param minimos y maximos caracteres
 * \param Cantidad de Reintentos.
 * \param char Donde guarda el resultado.
 * \return int -1 si no logro guardar lo ingresado. 0 si puedo realizarlo con exito.
 *
 */
int utn_getSex(char *msg, char *msgError, char minimo, char maximo, int reintentos, char *resultado)
{
    char buffer[4096];
    int retorno = -1;

    if(msg != NULL && msgError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            if(!utn_getString(msg,msgError,1,3,reintentos,buffer))
            {
                if(utn_isValidSex(buffer[0])==TRUE)
                {
                    *resultado = buffer[0];
                    retorno = 0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos --;
                }
            }
        }while(reintentos>=0);

    } return retorno;
}
/** \brief Valida que lo que se ingrese este entre lo permitido.
 *
 * \param char letra
 * \param   maximo y minimo.
 * \return TRUE si lo que se ingresa no es invalido FALSE si es invalido
 *
 */

int  utn_isValidSex (char letra)
{
    int retorno = TRUE ;
    if ((letra != 'f' ) && (letra != 'F' ) && (letra != 'm' ) && (letra != 'M' ))
    {
        retorno = FALSE ;
    }
    return retorno;
}

/** \brief La funcion pide el ingreso de una letra.
 *
 * \param Recibe el mensaje a mostrar.
 * \param el mensaje de Error
 * \param minimos y maximos caracteres
 * \param Cantidad de Reintentos.
 * \param char Donde guarda el resultado.
 * \return int -1 si no logro guardar lo ingresado. 0 si puedo realizarlo con exito.
 *
 */
int utn_getChar (char * msg, char * msgError, char minimo, char maximo, int reintentos, char * resultado)
{
    int retorno=-1;
    char bufferChar[4096];

    if(msg!=NULL && msgError!=NULL && minimo<=maximo && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,1,3,reintentos,bufferChar))
            {
                if(utn_isValidChar(bufferChar[0])==TRUE)
                {
                    *resultado=bufferChar[0];
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }

        }while(reintentos>=0);
    }
    return retorno;
}

/** \brief Valida que lo que se ingresa sean letras.
 *
 * \param Recibe un char
 * \param
 * \return TRUE si lo que se ingresa no es invalido FALSE si es invalido
 *
 */
 int utn_isValidChar(char letra)
{
    int retorno=TRUE;

    if((letra > 'Z' || letra < 'A') && (letra > 'z' || letra < 'a'))
    {
        retorno=FALSE;
    }
    return retorno;
}
/** \brief La funcion valida que la cadena ingresada sea valida.
 *
 * \param Recibe el mensaje a mostrar.
 * \param el mensaje de Error
 * \param minimos y maximos caracteres
 * \param Cantidad de Reintentos.
 * \param char Donde guarda el resultado.
 * \return int -1 si no logro guardar lo ingresado. 0 si puedo realizarlo con exito.
 *
 */
int utn_getString ( char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            printf("%s",msg);
            fflush (stdin);
            /// __fopurgue(stdin)  PARA LINUX
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,31);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }
        while(reintentos>=0);
    }
    return retorno;
}
/** \brief La funcion pide el ingreso del Nombre.
 *
 * \param Recibe el mensaje a mostrar.
 * \param el mensaje de Error
 * \param minimos y maximos caracteres
 * \param Cantidad de Reintentos.
 * \param char Donde guarda el resultado.
 * \return int -1 si no logro guardar lo ingresado. 0 si puedo realizarlo con exito.
 *
 */
int utn_getName (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
            {
                if(utn_isValidName(bufferStr)==TRUE)
                {
                    strncpy(resultado, bufferStr,31);
                    retorno = 0;
                    break;

                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_isValidName (char *cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {

        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a') && cadena[i] != ' ' )
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}
/// ESTA FUNCION NO ESTA EN USO.
/*
int utn_tieneEspacio (char *cadena)
{
    int retorno=-1;
    int i;
    retorno=isspace(cadena);

    for (i=0; cadena[i] != '\0'; i++)
    {
        if (isspace(cadena)==1)
        {
            retorno=0;
            break;
        }
    }
    printf("%d3 ",retorno);
    return retorno;
}
*/

/** \brief La funcion pide el ingreso del Mail.
 *
 * \param Recibe el mensaje a mostrar.
 * \param el mensaje de Error
 * \param minimos y maximos caracteres
 * \param Cantidad de Reintentos.
 * \param Donde guarda el resultado.
 * \return int -1 si no logro guardar lo ingresado. 0 si puedo realizarlo con exito.
 *
 */
int utn_getMail (char *msg, char *msgError,int minimo, int maximo, int reintentos, char *resultado)
{
    int retorno=-1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
            {
                if(utn_isValidMail(bufferStr)==TRUE)
                {
                    strncpy(resultado, bufferStr,31);
                    retorno = 0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

/** \brief Valida @ y . para mail
 *
 * \param la cadena
 * \param
 * \return TRUE FALSE si entra o no al if.
 *
 */
int utn_isValidMail (char *cadena)
{
    int retorno=FALSE;
    int i;
    int contadorArroba=0;
    int contadorPuntos=0;

    for( i=0 ; cadena [i] != '\0'  ; i++)
    {
        if(cadena [i] =='@' )
        {
           contadorArroba++;
        }
        if(cadena [i] =='.' )
        {
            contadorPuntos++;
        }
    }
    if(contadorArroba==1 && contadorPuntos>0)
    {
        retorno=TRUE;
    }
    return retorno;

}
#endif // UTN_C_INCLUDED
