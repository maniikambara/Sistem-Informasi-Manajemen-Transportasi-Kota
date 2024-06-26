#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int inputInt(const char *prompt) {
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    return value;
}

void inputString(const char *prompt, char *str) {
    printf("%s", prompt);
    scanf("%s", str);
}

void MarqueeText(char *kalimat, int speed){
	int x; double y;
   	for(x=0; kalimat[x]!='\0'; x++){
	    printf("%c",kalimat[x]);
	    for(y=0; y<=speed; y++){
		}
   }
}
