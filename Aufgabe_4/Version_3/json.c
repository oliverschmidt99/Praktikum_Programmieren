#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include "rational.h"



#define MAX_BUFFER_SIZE 500




short von_json(const uint8_t *buffer, rational *von_json){

 
    char* ptr;
    char* start_adr_vz;
    char* start_adr_za;
    char* start_adr_ne;
    char* kopie_buffer_string;
    char* kopie_kleiner_string;
    char vz_vgl[] = "\"vz\":";
    char za_vgl[] = "\"za\":";
    char ne_vgl[] = "\"ne\":";

    int länge_string_buffer;
    int länge_string_short;
    short zähler = 0;
    short ist_error = 0;

    länge_string_buffer = strlen((char*)buffer)+1; 
    kopie_buffer_string = malloc(länge_string_buffer);
    kopie_kleiner_string = malloc(länge_string_buffer);
    strcpy(kopie_buffer_string, buffer);

    länge_string_short = zerlege_string(kopie_buffer_string, kopie_kleiner_string, " ");

    /*
    Prüft, ob das Zeichen '{' am Anfang des Strings vorhanden ist.
    Prüft, ob das Zeichen '}' am Ende des Strings vorhanden ist.
    Prüft, ob das Zeichen ',' im String vorhanden ist.
    Zählt die Anzahl der Vorkommen des Zeichens ',' im String und gibt eine Fehlermeldung aus, wenn es mehr als zweimal vorkommt.
    */
    ptr = strstr(kopie_kleiner_string, "{");
    if(ptr != &kopie_kleiner_string[0]){
    return -1;
    }

    zähler = 0;
    zähler = zähle_string("{", kopie_kleiner_string);
    if(zähler > 1){
    return -1;
    }
    ptr = strstr(&kopie_kleiner_string[länge_string_short]-1, "}");
    if(!ptr){
    return -1;
    }
    ptr = strstr(&kopie_kleiner_string[0], ",");
    if(!ptr){
    return -1;
    }
    zähler = 0;
    zähler = zähle_string(",", ptr);
    if(zähler != 2){
    return -1;
    }
    

/*
    @brief Sucht in einem gegebenen String nach den Substrings "vz:", "za:" und "ne:" und speichert die Startadressen in den Variablen "start_adr_vz", "start_adr_za" und "start_adr_ne".
    @param kopie_buffer_string Der zu durchsuchende String.
    @param vz_vgl Der zu suchende Substring für das Vorzeichen.
    @param za_vgl Der zu suchende Substring für den Zähler.
    @param ne_vgl Der zu suchende Substring für den Nenner.
    @return int Gibt -1 zurück, wenn mindestens eines der Substrings nicht gefunden wurde, sonst 0.
    */

    start_adr_vz = strstr(&kopie_kleiner_string[0], vz_vgl);
    start_adr_za = strstr(&kopie_kleiner_string[0], za_vgl);
    start_adr_ne = strstr(&kopie_kleiner_string[0], ne_vgl);
    if(!start_adr_vz && !start_adr_za && !start_adr_ne){
    return -1;
    }

    zähler = 0;
    zähler = zähle_string("\"vz\":", start_adr_vz);
    if(zähler > 1){
    return -1;
    }
    zähler = 0;
    zähler = zähle_string("\"za\":", start_adr_za);
    if(zähler > 1){
    return -1;
    }
    zähler = 0;
    zähler = zähle_string("\"ne\":", start_adr_ne);
    if(zähler > 1){
    return -1;
    }

/**
@brief Extrahiert die Zahlenwerte für die Felder "vz", "za" und "ne" aus einem JSON-String und speichert sie im struct "von_json".
@param start_adr_vz Der Start-Pointer für das Feld "vz" im JSON-String.
@param start_adr_za Der Start-Pointer für das Feld "za" im JSON-String.
@param start_adr_ne Der Start-Pointer für das Feld "ne" im JSON-String.
@param von_json Ein Pointer auf das struct, in welchem die extrahierten Zahlenwerte gespeichert werden sollen.
@param vz_vgl Der String, welcher das Feld "vz" im JSON-String darstellt.
@param za_vgl Der String, welcher das Feld "za" im JSON-String darstellt.
@param ne_vgl Der String, welcher das Feld "ne" im JSON-String darstellt.
@return Gibt bei einem Fehler den Wert -1 zurück, sonst den Wert 0.
*/
    ist_error = extrahiere_zahl_aus_string(start_adr_vz, von_json, vz_vgl);
    if(ist_error != 0){
        return -1;
    }
    ist_error = extrahiere_zahl_aus_string(start_adr_za, von_json, za_vgl);
    if(ist_error != 0){
        return -1;
    }
    ist_error = extrahiere_zahl_aus_string(start_adr_ne, von_json, ne_vgl);
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
if(zu_json->za < 0 || zu_json->za > 4294967295){
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
if (total_length >= MAX_BUFFER_SIZE - strlen(buffer)){
  return -1;
}

// Hinzufügen des Gesamt-JSON-Strings zum Puffer
strcat(buffer, string_vz);
strcat(buffer,string_za);
strcat(buffer,string_ne);

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

short länge = 0;
char* token = 0;

    token = strtok(buffer, trennzeichen); // Trennzeichen ist hier ein Leerzeichen
    while (token != NULL) {
        strcat(kopie_buffer_string, token); // fügt jedes Token an den neuen String an
        token = strtok(NULL, trennzeichen);
    }
    länge = strlen((char*)kopie_buffer_string);

return länge;
}



short extrahiere_zahl_aus_string(char* start_adr, rational *extrahiere_zahl, const char *vgl){
char* end_adr = 0;

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
extrahiere_zahl->za = atoi(end_adr);
    if(extrahiere_zahl->za < 0 || extrahiere_zahl->za > 4294967296){
    return -1;
    }
}
if(strcmp(vgl, "\"ne\":") == 0){
extrahiere_zahl->ne = atoi(end_adr);
    if(extrahiere_zahl->ne < 0 || extrahiere_zahl->ne > 4294967296){
    return -1;
    }
}
return 0;
}
