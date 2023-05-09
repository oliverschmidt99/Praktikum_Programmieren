#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "rational.h"
#include "json.h"
#include "rational.c"
#include "json.c"




int main(int argc, char *argv[])
{
    printf(NL NL);

    short error = 0;
    uint8_t *objekte = NULL;
    uint8_t *storage_form_json;
    rational *json_rat = creat(0,0,0);
    char *filename_read = "formjson_zahlen.json";
    char *filename_wirte = "to_txt_zahlen.txt";

    storage_form_json = malloc(sizeof(1000000000000));
    
    if (argc == 2)    {
        printf(RD"Fehler: "RS"Bitte geben sie eine Datei an, die goeffnet werden soll!"NL NL);
        free(storage_form_json);
        destroy(json_rat);
    return -1;
    }

    
    objekte = read_json(filename_read);
    printf(GN"Richtig:"RS" Datei wurde ausgelesen!" NL);



    error = from_json(objekte, storage_form_json, json_rat);
    if (error != 0){
        printf(RD"Fehler: "RS"Umformung von Json hat nicht funktioniert!"NL NL);
        free(storage_form_json);
        destroy(json_rat);
    return -1;
    }
    printf(GN"Richtig:"RS" Zahlen wurden ausgelsen!"NL);


    error = write_json(storage_form_json, filename_wirte);
    if (error != 0){
        printf(RD"Fehler: "RS"Schreiben in einer Datei, hat nicht funktioniert!"NL NL);
        free(storage_form_json);
        destroy(json_rat);
    return -1;
    }
    printf(GN"Richtig:"RS" Zahlen wurden in einer .txt gespeichert" NL);







free(storage_form_json);
destroy(json_rat);
printf(NL NL);
return 0;
}
