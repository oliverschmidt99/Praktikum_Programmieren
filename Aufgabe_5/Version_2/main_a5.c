#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "json.h"
#include "rational.h"
#include "json1.c"




int main(int argc, char *argv[])
{
    printf(NL NL);

    short error = 0;
    uint8_t *objekte = NULL;
    rational *json_rat = creat(0,0,0);
    char *filename = "json_zahlen.json";


    
    if (argc == 2)
    {
        printf(RD"Fehler: "RS"Bitte geben sie eine Datei an, die goeffnet werden soll!"NL NL);
        return -1;
    }

    objekte = open_json(filename);
    printf("%s" NL, objekte);

    error = json_roulette(objekte, json_rat);
    if (error != 0)
    {
        printf(RD"Fehler: "RS"Umformung von Json hat nicht funktioniert!"NL NL);
        return -1;
    }

destroy(json_rat);
printf(NL NL);
return 0;
}
