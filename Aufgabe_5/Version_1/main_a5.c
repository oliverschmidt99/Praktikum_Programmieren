#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "json.h"
#include "json.c"



int main(int argc, char *argv[]){
printf(NL NL);

short error = 0;
uint8_t* objekte = NULL;
rational* json_rat;
    char *filename="von_json.json";
    if(argc == 2){
        printf("Bitte geben sie eine Datei an, die goeffnet werden soll!"NL);
    return -1;
    }
   
    objekte = open_json(filename);
    printf("%s"NL,objekte);

    error = von_json(objekte, json_rat);
    if(error != 0){
        printf("Fehler: Umformung von Json hat nicht funktioniert!"NL);
    return -1;
    }


printf(NL NL);
return 0;
}
