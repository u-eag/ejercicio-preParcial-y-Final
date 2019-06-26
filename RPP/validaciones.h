
int getChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit, int caseSensitive, int tries); // para obtener el botón del menú seleccionado

int getStringLetras (char* pStr, char* msg, char* msgE, int reintentos); // para tomar apellido y nombre
int getString(char* pStr, char* msg, char*msgE);
int isLetter (char* pStr);

int getSexo(char* pStr,char* msg,char* msgE,int reintentos); // para tomar [F][M]
int isSexo (char* pStr);

int getTelephone (char* pStr, char* msg, char* msgE,int reintentos);
int isTelephone (char* pStr);

int getMail (char* pStr, char* msg, char* msgE,int reintentos);
int isMail(char* pStr);

int getFecha (int* dia,int* mes,int* anio,char* msgE,int reintentos);
int isFecha(int dia,int mes,int anio);



int getInt (int *pNum, char* msg, char* msgE);
int getFloat (float *pNum, char* msg, char* msgE);

int getIntInRange (int *pNum,char *msg,char *msgE,int minimo,int maximo,int reintentos);
int cargarArraySecuencialInt(int* pArray,int len,char* msg, char* msgE);
int cargarArraySecuencialFloat(float* pArray,int len,char* msg, char* msgE);

int getStringNumerosInt (char* pStr, char* msg, char* msgE,int reintentos);
int getStringNumerosFloat (char* pStr, char* msg, char* msgE,int reintentos);
int getStringAlphanumeric (char* pStr, char* msg, char* msgE,int reintentos);

int getDni (char* pStr, char* msg, char* msgE,int reintentos);
int getCuit (char* pStr, char* msg, char* msgE,int reintentos);

int searchFreeSpace(char pArray[][20],int* pIndex,int len);
int saerchName(char* name, char parray[][20], int len, int* pIndex);
int ordenarArrayMayorMenor (char* pArray, int len,int limit);

int showArrayInt(int* pArray,int len);
int showArrayChar(char* pArray,int len);

int isNumberInt (char* pStr);
int isNumberFloat (char* pStr);
int isAlphanumeric (char* pStr);
int isDni (char* pStr);
int isCuit (char* pStr);
