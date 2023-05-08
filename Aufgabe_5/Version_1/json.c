#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "json.h"

#define RD "\x1B[31m"
#define GN "\x1B[32m"
#define WH "\x1B[34m"
#define RS "\x1B[0m"
#define NL "\n"

#define MAX_BUFFER_SIZE 500


short von_json(const uint8_t *buffer, rational *von_json){

 
    char* ptr = 0;
    char* start_adr_vz = 0;
    char* start_adr_za = 0;
    char* start_adr_ne = 0;
    char* kopie_buffer_string = 0;
    char* kopie_kleiner_string = 0;

    int laenge_string_buffer = 0;
    int laenge_string_short = 0;
    short zaehler = 0;
    short ist_error = 0;

    laenge_string_buffer = strlen((char*)buffer)+1; 
    kopie_buffer_string = malloc(laenge_string_buffer);
    kopie_kleiner_string = malloc(laenge_string_buffer);
    strcpy(kopie_buffer_string, (char*)buffer);

    laenge_string_short = zerlege_string(kopie_buffer_string, kopie_kleiner_string, " ");

    /*
    Prüft, ob das Zeichen '{' am Anfang des Strings vorhanden ist.
    Prüft, ob das Zeichen '}' am Ende des Strings vorhanden ist.
    Prüft, ob das Zeichen ',' im String vorhanden ist.
    Zählt die Anzahl der Vorkommen des Zeichens ',' im String und gibt eine Fehlermeldung aus, wenn es mehr als zweimal vorkommt.
    */
    ptr = strstr(kopie_kleiner_string, "{");
    if(*ptr != '{'){
    return -1;
    }

    zaehler = 0;
    zaehler = zähle_string("{", kopie_kleiner_string);
    if(zaehler != 1){
    return -1;
    }
    ptr = strstr(&kopie_kleiner_string[0], "}");
    if(!ptr){
    return -1;
    }
    ptr = strstr(&kopie_kleiner_string[0], ",");
    if(!ptr){
    return -1;
    }
    zaehler = 0;
    zaehler = zähle_string(",", ptr);
    if(zaehler != 2){
    return -1;
    }
 
    start_adr_vz = strstr(&kopie_kleiner_string[0], "\"vz\":");
    start_adr_za = strstr(&kopie_kleiner_string[0], "\"za\":");
    start_adr_ne = strstr(&kopie_kleiner_string[0], "\"ne\":");

    if(!start_adr_vz && !start_adr_za && !start_adr_ne){
    return -1;
    }

    zaehler = 0;
    zaehler = zähle_string("\"vz\":", start_adr_vz);
    if(zaehler > 1){
    return -1;
    }
    zaehler = 0;
    zaehler = zähle_string("\"za\":", start_adr_za);
    if(zaehler > 1){
    return -1;
    }
    zaehler = 0;
    zaehler = zähle_string("\"ne\":", start_adr_ne);
    if(zaehler > 1){
    return -1;
    }


    ist_error = extrahiere_zahl_aus_string(start_adr_vz, von_json, "\"vz\":");
    if(ist_error != 0){
        return -1;
    }
    ist_error = extrahiere_zahl_aus_string(start_adr_za, von_json, "\"za\":");
    if(ist_error != 0){
        return -1;
    }
    ist_error = extrahiere_zahl_aus_string(start_adr_ne, von_json, "\"ne\":");
    if(ist_error != 0){
        return -1;
    }

    free(kopie_buffer_string);
    free(kopie_kleiner_string);
return 0;
}


short to_json(uint8_t *buffer, const rational *zu_json){

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
if (total_length >= MAX_BUFFER_SIZE - strlen((char*)buffer))
{
  return -1;
}

// Hinzufügen des Gesamt-JSON-Strings zum Puffer
strcat((char*)buffer, string_vz);
strcat((char*)buffer,string_za);
strcat((char*)buffer,string_ne);

return 0;
}


short zähle_string(char *sucher_string, char *pointer_adresse){

/*Die Funktion initialisiert eine Zählvariable count mit 0 und einen Zeiger ptr auf die übergebene
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

short zerlege_string(char *buffer, char *kopie_buffer_string, const char *trennzeichen){

short laenge = 0;
char* token = 0;

    token = strtok(buffer, trennzeichen); // Trennzeichen ist hier ein Leerzeichen
    while (token != NULL) {
        strcat(kopie_buffer_string, token); // fügt jedes Token an den neuen String an
        token = strtok(NULL, trennzeichen);
    }
    laenge = strlen((char*)kopie_buffer_string);

return laenge;
}



short extrahiere_zahl_aus_string(char* start_adr, rational *extrahiere_zahl, const char *vgl){

char* end_adr = 0;
long pruef = 0;

// Sucht die Position der Zahl im String und speichert das Ende der Zahl in end_adr
start_adr += strlen(vgl);
end_adr = strtok(start_adr, ",");
if(end_adr != NULL){
    end_adr = strtok(start_adr, "}");
    if(end_adr == NULL){
    return -1;
    }
}

// Extrahiert die Zahl und überprüft ihre Grenzen.
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






uint8_t* open_json(char* filename){

char *kopie= NULL;
unsigned int laenge = 0;
int i;
FILE* file = fopen(filename, "r");

    if(file == NULL){
        printf("Fehler: Datei konnte nicht geoeffnet werden"NL);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    laenge = ftell(file);
    fseek(file, 0, SEEK_SET);
    kopie = malloc(laenge);
    
    for(i = 0; i <= laenge; i++){
        kopie[i] = fgetc(file); 
    }
    kopie[i-1]='\0';

fclose(file);
return kopie;
}









