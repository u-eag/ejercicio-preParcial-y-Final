int getString(char* pStr, char* msg, char*msgE);
int getInt (int *pNum, char* msg, char* msgE);
int getIntInRange (int *pNum,char *msg,char *msgE,int minimo,int maximo,int reintentos);
int getStringLetras (char* pStr, char* msg, char* msgE, int reintentos);
int getStringNumerosInt (char* pStr, char* msg, char* msgE,int reintentos);
int ordenarArrayMayorMenor (char* pArray, int len,int limit);
int showArrayInt(int* pArray,int len);
int showArrayChar(char* pArray,int len);
int isNumberInt (char* pStr);
int isLetter (char* pStr);

int getFloat (float *pNum, char* msg, char* msgE);
int getStringNumerosFloat (char* pStr, char* msg, char* msgE,int reintentos);
int isNumberFloat (char* pStr);

int isFecha(int dia,int mes,int anio);
int getFecha (int* dia,int* mes,int* anio,char* msgE,int reintentos);

int isCuit (char* pStr);
int getCuit (char* pStr, char* msg, char* msgE,int reintentos);
