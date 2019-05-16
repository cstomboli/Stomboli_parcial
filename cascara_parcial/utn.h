#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_fechaNacimiento (char *msg, char *msgError, char minimo, char maximo, int reintentos, char *resultado);
int utn_isValidFecha(char *cadena);

int utn_getCuit (char *msg, char *msgError, char minimo, char maximo, int reintentos, char *resultado);
int utn_isValidCuit (char *cadena);

int utn_getDni (char *msg, char *msgError, char minimo, char maximo, int reintentos, char *resultado);
int utn_isValidDni (char *cadena);

int utn_getTelefono (char *msg, char *msgError, char minimo, char maximo, int reintentos, char *resultado);
int utn_isValidTelephone(char* cadena);

int utn_getInt (char *msg, char *msgError, char minimo, char maximo, int reintentos, int *resultado);
int utn_isValidInt (char *cadena);

int utn_getFecha (char *msg, char *msgError, char minimo, char maximo, int reintentos, int *resultado);
int utn_isValidMes (char *cadena);
int utn_isValidAnio (char *cadena);
int utn_isValidDia (char *cadena);

int utn_getInSimple (char msg[]);

float utn_getFloat (char * mensaje, char * mensajeError, float minimo, float maximo, float intentos, float * resultado);
float utn_isValidFloat (char *cadena);

int utn_getSex(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado);
int  utn_isValidSex (char letra);

int utn_getChar (char * msg, char * msgError, char minimo, char maximo, int reintentos, char * resultado);
int utn_isValidChar(char letra);

int utn_getString ( char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);

int utn_getName (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int utn_isValidName (char *cadena);

int utn_getMail (char *msg, char *msgError,int minimo, int maximo, int reintentos, char *resultado);
int utn_isValidMail (char *cadena);





#endif // UTN_H_INCLUDED
