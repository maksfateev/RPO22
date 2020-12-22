#include "lineliber.h"
#include "cip.h"

int main(int argc, char** argv) {
	char method[32];
	char text[128];	
	char key[128];
	
	if(argc == 1) {
		printf("input method(-xor or -ceaser), text(char[128]), key(char[128]) (Example:-xor AAA 11)\n");
		scanf("%s",method);
		scanf("%s",text);
		scanf("%s",key);	
	}
	else if(argc == 4 ) {
		strcpy(method,argv[1]);
		strcpy(text,argv[2]);
		strcpy(key,argv[3]);
	}
	else {
		printf("Invalid number of arguments\n");
		return 1;
	}
	
	mutableLine(text);
	mutableToLower(text);
	mutableToLower(method);
	
	if(strcmp(method, "-caesar") == 0) {
		if(!checkNumber(key)) {
			printf("Offset error: not a number\n");
			return 2;
		}
		if(!checkWord(text)) {
			printf("Text error: not a word\n");
			return 3;
		}
		mutableCaesar(text, atoi(key));
	}
	else if(strcmp(method, "-xor") == 0) {
		mutableXOR(text, key);
	}
	else {
		printf("Invalid method\n");
		return 4;
	}
	printf("Encoded string %s\n", text);
	return 0;
}
