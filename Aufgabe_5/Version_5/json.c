#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "rational.h"
#include "json.h"


#define RD "\x1B[31m"
#define GN "\x1B[32m"
#define WH "\x1B[34m"
#define RS "\x1B[0m"
#define NL "\n"

#define MAX_storage_SIZE 500





short get_json_objekt(const uint8_t *storage, rational *from_json, unsigned int len_objekt){

 
    char* ptr = 0;
    char* start_adr_vz = 0;
    char* start_adr_za = 0;
    char* start_adr_ne = 0;
    char* kopie_storage = 0;
    char* clear_storage = 0;

    int laenge_string_storage = 0;
    int laenge_string_short = 0;
    short zaehler = 0;
    short is_error = 0;
    int i = 0;

    kopie_storage = malloc(len_objekt);
    clear_storage = malloc(len_objekt);
    if(!clear_storage && !kopie_storage){
        free(kopie_storage);
        free(clear_storage);
        return -1;
    }

    /*
    Prüft, ob das Zeichen '{' am Anfang des Strings vorhanden ist.
    Prüft, ob das Zeichen '}' am Ende des Strings vorhanden ist.
    Prüft, ob das Zeichen ',' im String vorhanden ist.
    Zählt die Anzahl der Vorkommen des Zeichens ',' im String und gibt eine Fehlermeldung aus, wenn es mehr als zweimal vorkommt.
    */


   for(i = 0; i < len_objekt; i++){
    kopie_storage[i] = storage[i];
   }

  
    start_adr_vz = strstr(&kopie_storage[0], "\"vz\":");
    start_adr_za = strstr(&kopie_storage[0], "\"za\":");
    start_adr_ne = strstr(&kopie_storage[0], "\"ne\":");
    if(!start_adr_vz && !start_adr_za && !start_adr_ne){
        free(kopie_storage);
        free(clear_storage);
    return -1;
    }


    disassemble_string(kopie_storage, clear_storage);


    start_adr_vz = strstr(&clear_storage[0], "\"vz\":");
    start_adr_za = strstr(&clear_storage[0], "\"za\":");
    start_adr_ne = strstr(&clear_storage[0], "\"ne\":");
    if(!start_adr_vz && !start_adr_za && !start_adr_ne){
        free(kopie_storage);
        free(clear_storage);
    return -1;
    }


    zaehler = 0;
    zaehler = count_string("\"vz\":", start_adr_vz);
    if(zaehler > 1){
        free(kopie_storage);
        free(clear_storage);
    return -1;
    }
    zaehler = 0;
    zaehler = count_string("\"za\":", start_adr_za);
    if(zaehler > 1){
        free(kopie_storage);
        free(clear_storage);
    return -1;
    }
    zaehler = 0;
    zaehler = count_string("\"ne\":", start_adr_ne);
    if(zaehler > 1){
        free(kopie_storage);
        free(clear_storage);
    return -1;
    }


    is_error = extract_number(start_adr_vz, from_json, "\"vz\":");
    if(is_error != 0){
        free(kopie_storage);
        free(clear_storage);
    return -1;
    }
    is_error = extract_number(start_adr_za, from_json, "\"za\":");
    if(is_error != 0){
        free(kopie_storage);
        free(clear_storage);
    return -1;
    }
    is_error = extract_number(start_adr_ne, from_json, "\"ne\":");
    if(is_error != 0){
        free(kopie_storage);
        free(clear_storage);
    return -1;
    }


free(kopie_storage);
free(clear_storage);
return 0;
}


short to_json(uint8_t *storage, const rational *zu_json){

// Erstellen der Strings für jeden Wert und Zusammenfügen zu einem Gesamt-JSON-String
char string_vz[10];
char string_za[20];
char string_ne[20];


// Überprüfen, ob die Werte den Einschränkungen für JSON entsprechen
if(zu_json->vz != -1 && zu_json->vz != 1){
return -1;
}
if (zu_json->za < 0 || zu_json->za > 4294967295){
return -1;
}
if(zu_json->ne < 0 || zu_json->ne > 4294967295){
return -1;
}

sprintf(string_vz,"{\"vz\":%i,", zu_json->vz);
sprintf(string_za,"\"za\":%u,", zu_json->za);
sprintf(string_ne,"\"ne\":%u}", zu_json->ne);

// Überprüfen, ob der Gesamt-JSON-String größer ist als der verfügbare Puffer
size_t total_length = strlen(string_vz) + strlen(string_za) + strlen(string_ne);
if (total_length >= MAX_storage_SIZE - strlen((char*)storage)){
  return -1;
}

// Hinzufügen des Gesamt-JSON-Strings zum Puffer
strcat((char*)storage, string_vz);
strcat((char*)storage, string_za);
strcat((char*)storage, string_ne);

return 0;
}


short count_string(char *sucher_string, char *pointer_adresse){

/*
Die Funktion initialisiert eine Zählvariable count mit 0 und einen Zeiger ptr auf die übergebene
Adresse pointer_adresse. Dann wird eine Schleife gestartet, die so lange läuft, bis der Zeiger
auf NULL gesetzt wird.
Sobald alle Vorkommen von sucher_string im String gefunden wurden, gibt die 
Funktion die Gesamtzahl von Vorkommen zurück.
*/

int count = 0;
    char *ptr = pointer_adresse;
    while ((ptr = strstr(ptr, sucher_string)) != NULL) {
        count++;
        ptr += strlen(sucher_string);
    }
    return count;
}


short extract_number(char* start_adr, rational *extrahiere_zahl, const char *vgl){

char* end_adr = 0;
long pruef = 0;

//Sucht die Position der Zahl im String und speichert das Ende der Zahl in end_adr
start_adr += strlen(vgl);
end_adr = strtok(start_adr, ",");
if(end_adr != NULL){
    end_adr = strtok(start_adr, "}");
    if(end_adr == NULL){
    return -1;
    }
}

//Extrahiert die Zahl und überprüft ihre Grenzen.
if(strcmp(vgl, "\"vz\":") == 0){
    extrahiere_zahl->vz = atoi(end_adr);
    if(extrahiere_zahl->vz != 1 && extrahiere_zahl->vz !=-1){
    return -1;
    }
}
if(strcmp(vgl, "\"za\":") == 0){
    pruef = 0;
    pruef = atol(end_adr);
    if(pruef < 0 || pruef > 4294967296){
    return -1;
    }
    extrahiere_zahl->za = pruef;
    
}
if(strcmp(vgl, "\"ne\":") == 0){
    pruef = 0;
    pruef = atol(end_adr);
    if(pruef < 0 || pruef > 4294967296){
    return -1;
    }
    extrahiere_zahl->ne = pruef;
}
return 0;
}


short from_json(const uint8_t *storage, uint8_t *storage_form_json, rational *from_json_rat){
    
    size_t len = 0;
    unsigned int d = 0;
    char* temp_storage;
    char* copy_storage;
    char* check = 0;
    int i = 0, j=0;
    int counter1 = 0;
    short is_error = 0;
    uint8_t text[100][100];

    
    copy_storage = malloc(strlen(storage)+1);
    temp_storage = malloc(strlen(storage)+1);
    if(!copy_storage && !temp_storage){
        return -1;
    }

    strcpy(copy_storage, storage);
    
    char *start= copy_storage, *end = copy_storage;
    len = strlen(copy_storage);

    
    do{
        d = strnlen(copy_storage, end - copy_storage);
        start = strstr(copy_storage+d, "{");
        d = strnlen(copy_storage, start - copy_storage);
        end = strstr(copy_storage+d, "}");
                   

            d = (end - start)+1;
            i=0;
            do{
                text[j][i] = start[i];
                i++;
            }while(i != d);

            end++;
            if (!start || !end){ 
                free(temp_storage);           
                free(copy_storage);
            return -1;
            }


            is_error = get_json_objekt(text[j], from_json_rat, i);
            if(is_error == -1){
                free(temp_storage);
                free(copy_storage);
            return -1;
            }
            d++; 
            j++;
            counter1++;

            if(from_json_rat->vz == 1){
                sprintf((char *)temp_storage,"rat %d:  (%u/%u)"NL,j, from_json_rat->za, from_json_rat->ne);
            }
            else{
                sprintf((char *)temp_storage,"rat %d: -(%u/%u)"NL,j, from_json_rat->za, from_json_rat->ne);
            }

            strcat((char*)storage_form_json, temp_storage);

        }while ((check = strstr(end, ",")) != NULL);
    
    free(temp_storage);
    free(copy_storage);
return 0; 
}



uint8_t* read_json(char* filename){

char *kopie= NULL;
unsigned int laenge = 0;
int i;
FILE* file = fopen(filename, "r");

    if(file == NULL){
        printf(RD" Fehler: "RS"Datei konnte nicht geoeffnet werden"NL NL);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    laenge = ftell(file);
    fseek(file, 0, SEEK_SET);
    kopie = malloc(laenge);
    
    for(i = 0; i < laenge; i++){
        kopie[i] = fgetc(file); 
    }
    kopie[i-1]='\0';

fclose(file);
return kopie;
}





void disassemble_string(char *str, char *new_str) {
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\r' && str[i] != '\t') {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';
}





short write_json(const uint8_t *storage, const char *filename){


FILE* file = fopen(filename, "w");

    if(file == NULL){
        printf(RD" Fehler: "RS"Datei konnte nicht geoeffnet werden"NL NL);
        exit(1);
    }

    fprintf(file, "%s", storage);

    

    fflush(file);  // alle ausstehenden Schreibvorgänge durchführen

    if(fclose(file) != 0) {
        printf(RD" Fehler: "RS"Datei konnte nicht geschlossen werden"NL NL);
        exit(1);
    }

return 0;
}