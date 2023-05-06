#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>


#define RD "\x1B[31m"
#define GN "\x1B[32m"
#define WH "\x1B[34m"
#define RS "\x1B[0m"
#define MAX_BUFFER_SIZE 500


typedef struct{
    char vz;
    unsigned int za;
    unsigned int ne;
}rational;
/**
 
@brief Erstellt und initialisiert eine neue rationale Zahl mit den übergebenen Parametern.
@param vz Vorzeichen der rationalen Zahl. Kann 1 oder -1 sein.
@param za Der Zähler der rationalen Zahl.
@param ne Der Nenner der rationalen Zahl.
@return Ein Zeiger auf die neu erstellte rationale Zahl oder NULL, falls die Speicherzuweisung fehlschlägt.
*/
rational *creat(char vz, unsigned int ne, unsigned int za);
/**

@brief Gibt den allokierten Speicher einer rationalen Zahl wieder frei.
@param zahl Der Zeiger auf die rationale Zahl, deren Speicher freigegeben werden soll.
*/
void destroy(rational *zahl);

//Neue Prototypen


/**
 * @brief Zerlegt einen String in Tokens anhand eines Trennzeichens und fügt sie zu einem neuen String zusammen.
 *
 * @param buffer Der zu zerlegende String.
 * @param kopie_buffer_string Der neue String, zu dem die Tokens hinzugefügt werden.
 * @param trennzeichen Das Trennzeichen, das die Tokens im ursprünglichen String voneinander trennt.
 * @return Die Länge des neuen Strings als unsigned short.
 */
short zerlege_string(char *buffer, char *kopie_buffer_string, const char *trennzeichen);
/**
 * @brief Extrahiert eine rationale Zahl aus einem JSON-String und gibt sie als short zurück.
 *
 * Diese Funktion sucht im JSON-String nach der rationalen Zahl, die mit dem Schlüssel "rational" versehen ist.
 * Die Zahl wird dann extrahiert und als short zurückgegeben. Wenn der JSON-String ungültig ist oder der Schlüssel nicht gefunden wurde,
 * wird 0 zurückgegeben.
 *
 * @param buffer Der JSON-String, der analysiert werden soll.
 * @param rational Ein Zeiger auf eine rational-Struktur, in der die extrahierte Zahl gespeichert wird.
 * @return Die extrahierte rationale Zahl als Short oder 0, wenn der JSON-String ungültig ist oder der Schlüssel nicht gefunden wurde.
 */
short von_json(const uint8_t *buffer, rational *von_json);
/**

@brief Erstellt einen JSON-String aus den Werten des übergebenen rationalen Datentyps und fügt ihn zum angegebenen Puffer hinzu.

@param buffer Ein Zeiger auf den Puffer, zu dem der JSON-String hinzugefügt wird.

@param zu_json Ein Zeiger auf den rationalen Datentyp, dessen Werte zum JSON-String konvertiert werden.

@return int Falls der JSON-String erfolgreich erstellt und zum Puffer hinzugefügt wurde, wird 0 zurückgegeben. Andernfalls wird -1 zurückgegeben.

@details Diese Funktion erstellt einen JSON-String aus den Werten des übergebenen rationalen Datentyps und fügt ihn zum angegebenen Puffer hinzu. Zunächst werden die Werte des rationalen Datentyps überprüft, ob sie den Einschränkungen für JSON entsprechen. Wenn einer der Werte ungültig ist, wird -1 zurückgegeben und der JSON-String wird nicht erstellt. Ansonsten werden die Strings für jeden Wert erstellt und zu einem Gesamt-JSON-String zusammengefügt. Vor dem Hinzufügen zum Puffer wird geprüft, ob der JSON-String zusammen mit dem Puffer den verfügbaren Puffer nicht überschreitet. Wenn der Gesamt-JSON-String größer ist als der verfügbare Puffer, wird -1 zurückgegeben und der JSON-String wird nicht zum Puffer hinzugefügt.
*/
short to_json(uint8_t *buffer, const rational *zu_json);
/**
 * @brief Zählt das Vorkommen eines Zeichens in einem String und gibt die Anzahl zurück.
 *
 * Diese Funktion sucht nach dem Vorkommen des angegebenen Zeichens im angegebenen String und gibt die Anzahl der Vorkommen zurück.
 *
 * @param sucher_string Der zu durchsuchende String.
 * @param pointer_adressen Ein Zeiger auf den ersten Charakter, der nach dem Suchvorgang gefunden wurde. Kann auf NULL gesetzt werden, wenn Sie die Adressen nicht benötigen.
 * @return Die Anzahl der Vorkommen des Zeichens im String.
 */
short zähle_string(char *sucher_string, char *pointer_adressen);
/**
@brief Extrahiert eine Zahl aus einem String und speichert sie in einer Datenstruktur.
Diese Funktion sucht nach einem bestimmten Muster in einem String und extrahiert daraus
eine Zahl, die in eine bestimmte Datenstruktur gespeichert wird. Sie wird verwendet,
um Zahlen aus einem JSON-String zu extrahieren.
@param kopie_buffer_string Ein Pointer auf einen Puffer, in dem der zu durchsuchende String kopiert wird.
@param start_adr_vz Ein Pointer auf den Start des Musters im zu durchsuchenden String.
@param von_json Ein Pointer auf die Datenstruktur, in der die extrahierte Zahl gespeichert wird.
@param vz_vgl Ein Pointer auf das Muster, nach dem gesucht wird.
@return Gibt 0 zurück, wenn die Zahl erfolgreich extrahiert und gespeichert wurde, oder -1 im Fehlerfall.
*/
short extrahiere_zahl_aus_string(char* start_adr, rational *von_json, const char* vgl);



//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------




int main(){
printf("\n\n");

rational *rückgabe_von_json = creat(0,0,0);


uint8_t buffer_form_json[] =  "{ \"za\": 4294967295 ,\"ne\": 4294967295, \"vz\": 1 }";
uint8_t buffer_to_json[10000];
int a = von_json((uint8_t*)buffer_form_json, rückgabe_von_json);


if(a != 0){
printf(RD"Es ist ein Eingabefehler aufgetreten. Bitte überprüfen Sie Ihre Angaben!\n\n"RS);
return -1;
}

if(rückgabe_von_json->vz == 1){
    printf("von json\t->"GN"%10u/%-10u"RS"<-\n", rückgabe_von_json->za,rückgabe_von_json->ne);
}
else{
    printf("\t->"RD"%10u/%-10u"RS"<-\n", rückgabe_von_json->za,rückgabe_von_json->ne);
}


a = to_json(buffer_to_json, rückgabe_von_json);
if(a != 0){
printf(RD"Es ist ein Eingabefehler aufgetreten. Bitte überprüfen Sie Ihre Angaben!\n\n"RS);
return -1;
}
printf("zu json\t %s", buffer_to_json);

destroy(rückgabe_von_json);
printf("\n\n");
return 0;
}



//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------



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

rational *creat(char vz, unsigned int za, unsigned int ne){
    rational *zahl =malloc(sizeof(rational));
    if (zahl != NULL){
        zahl->vz = vz;
        zahl->za = za;
        zahl->ne = ne;
    }
    return zahl;
}



void destroy(rational *zahl){
    free(zahl);
}
