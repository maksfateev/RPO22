#ifndef H_CIP
#define H_CIP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void  mutableXOR(char* Line, const char* key);
char* immutableXOR(const char* Line , const char* key);

void  mutableCaesar(char* Line, const int key);
char* immutableCaesar(const char* Line, const int key);

#endif