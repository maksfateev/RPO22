#ifndef H_LINELIBER
#define H_LINELIBER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void  mutableToUpper(char* Line);
char* immutableToUpper(const char* Line);

void  mutableToLower(char* Line);
char* immutableToLower(const char* Line);

void  mutableLine(char* Line);
char* immutableLine(const char* Line);

void  mutableSpaces(char* Line);
char* immutableSpaces(const char* Line);

void  mutableFilter(char* Line);
char* immutableFilter(const char* Line);

bool checkNumber(const char* Line);
bool checkWord(const char* Line);

#endif