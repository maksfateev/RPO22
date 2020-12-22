#include "cip.h"


void mutableXOR(char* Line, const char* key) {
	const int lengthLine = strlen(Line); 
	const int lengthKey = strlen(key);
	
	for(int i = 0; i < lengthLine; i++) {
		Line[i] ^= key[i % lengthKey];
	}
}

char* immutableXOR(const char* Line, const char* key) {
	int length = strlen(Line) + 1; 
	char* newLine = (char*) malloc(sizeof(char) * (length));
	strcpy(newLine,Line);
	mutableXOR(newLine,key);

	return newLine;
}


void mutableCaesar(char* Line, const int key) {
	const int length = strlen(Line); 
	const int newKey = key % 26;
	
	for(int i = 0; i < length; i++) {
		if(Line[i] >= 'a' && Line[i] <= 'z') {	
			if(Line[i] + newKey > 'z') {
				Line[i] -= ('z' - 'a') + 1;
			}
			if(Line[i] + newKey < 'a') {
				Line[i] += ('z' - 'a') + 1 ;
			}
			Line[i] += newKey;
		}
  		if(Line[i] >= 'A' && Line[i] <= 'Z') {	
			if(Line[i] + newKey > 'Z') {
				Line[i] -= ('Z' - 'A') + 1;
			}
			if(Line[i] + newKey < 'A') {
				Line[i] += ('Z' - 'A') + 1;
			}
			Line[i] += newKey;
		}
	}
}

char* immutableCaesar(const char* Line, const int  key) {
	int length = strlen(Line) + 1; 
	char* newLine = (char*) malloc(sizeof(char) * (length));
	strcpy(newLine,Line);
	mutableCaesar(newLine,key);

	return newLine;
}