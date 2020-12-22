#include "lineliber.h"


void mutableToUpper(char* Line) {
	const int length = strlen(Line);
	for(int i = 0; i < length; i++) {
		if(Line[i] >= 'a' && Line[i] <= 'z') {
			Line[i] -= 'a' - 'A';
		}
	}
}

char* immutableToUpper(const char* Line) {
	int length = strlen(Line) + 1; 
	char* newLine = (char*) malloc(sizeof(char) * (length));
	strcpy(newLine,Line);
	mutableToUpper(newLine);

	return newLine;
}

 
void mutableToLower(char* Line) {
	const int length = strlen(Line);
	for(int i = 0; i < length; i++) {
		if(Line[i] >= 'A' && Line[i] <= 'Z') {
			Line[i] += 'a' - 'A';
		}
	}
}

char* immutableToLower(const char *Line) {
	int length = strlen(Line) + 1; 
	char* newLine = (char*) malloc(sizeof(char) * (length));
	strcpy(newLine,Line);
	mutableToLower(newLine);

	return newLine;
}


void mutableLine(char* Line) {
	int length;
	int start = 0;  
	int finish = 0;
	if (strlen(Line) == 0) {
		length = 0;
	} 
	else {
		finish = strlen(Line) - 1;	
		while(Line[start] == ' ') {
			if(Line[start + 1] == '\0') {
				break;
			}
			start++;
		}	
		if (start == finish) {
			length = 0;
		}
		else {
			while (Line[finish] == ' ') {
				finish--;
			}
			length = finish - start + 1;
			for(int i = 0; i < length; i++) {
				Line[i] = Line[start + i];
			}
		}
	}
	Line[length] = '\0';
	
}

char* immutableLine(const char* Line) {
	int length = strlen(Line) + 1; 
	
	char* newLine = (char*) malloc(sizeof(char) * (length));
	strcpy(newLine,Line);
	mutableLine(newLine);
	return newLine;
}	


void mutableSpaces(char* Line) {
	int length = strlen(Line);
	int i = 0, j = 0;
    
	while(Line[i] != '\0') {
		if(Line[i] == ' ') {
			for(j = i; j < length - 1; j++) {
				Line[j] = Line[j+1];
			}
			Line[length-1] = '\0';
		    length--;
			continue;
		}
		i++;
	}
}

char* immutableSpaces(const char* Line) {
	int length = strlen(Line) + 1; 
	
	char* newLine = (char*) malloc(sizeof(char) * (length));
	strcpy(newLine,Line);
	mutableSpaces(newLine);

	return newLine;
}


void mutableFilter(char* Line) {
	int length = strlen(Line);
	int i = 0, j = 0;
    
	while(Line[i] != '\0') {
		if(!isalpha(Line[i]) && !isspace(Line[i]) && !isdigit(Line[i])) {
			for(j = i; j < length - 1; j++){
				Line[j] = Line[j+1];
			}
			Line[length-1] = '\0';
		    length--;
			continue;
		}
		i++;
	}
}

char* immutableFilter(const char* Line) {
	int length = strlen(Line) + 1; 
	char* newLine = (char*) malloc(sizeof(char) * (length));
	strcpy(newLine,Line);
	mutableFilter(newLine);

	return newLine;
}


bool checkNumber(const char* Line) {
	const int length = strlen(Line);
	for(int i = 0; i < length; i++) {
		if(!isdigit(Line[i])) {	
			return false;
		}
	}
	return true;
}

bool checkWord(const char* Line) {
	const int length = strlen(Line);
	for(int i = 0; i < length; i++) {
		if(!isalpha(Line[i])) {	
			return false;
		}
	}
	return true;
}