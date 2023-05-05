#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define RED   "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

typedef struct{
    char vz;
    unsigned int za;
    unsigned int ne;
}rational;


int from_json(const uint8_t *buffer);
int findstring(char *sucher_string, char **pointer_adressen);


//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------




int main(){
printf("\n\n");

//int länge = 0;
//rational result;


uint8_t buffer[] =  "{\"vz\":                    1, \"za\": 33, \"ne\": 7}";

int a = from_json((uint8_t*)buffer);
if(a == 0){
printf("Die Eingabe ist Tip Top!\n");
}
printf("Fehler!\n");

printf("\n\n");
return 0;
}



//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------



int from_json(const uint8_t *buffer){


printf("buffer\t\t: %s\n", (char*)buffer);
 
    //rational json; 
    char* ptr;
    char* kopie_string_buffer;
    char vz_vg[] = "\"vz\":";
    char za_vg[] = "\"za\":";
    char ne_vg[] = "\"ne\":";
    char* start_adr_vz;
    char* start_adr_za;
    char* start_adr_ne;
    //char* end_adr_vz;
    //char* end_adr_za;
    //char* end_adr_ne;
    char *token;
    int länge_string_buffer;
    int zähler = 0;
    //char such_string_nummer[] = "-1234567890";

    länge_string_buffer = strlen((char*)buffer)+1; 
    kopie_string_buffer = malloc(länge_string_buffer);
    //strcpy((char*)kopie_string_buffer, buffer);


    //Leerzeichen sind erlaubt, somit werden siie entfernt, damit die berechnung einfacher ist. 
    token = strtok(buffer, " "); // Trennzeichen ist hier ein Leerzeichen

    while (token != NULL) {
        strcat(kopie_string_buffer, token); // fügt jedes Token an den neuen String an
        token = strtok(NULL, " ");
    }
    länge_string_buffer = strlen(kopie_string_buffer+1);
    printf("buffer Kopie\t: %s\n\n", kopie_string_buffer);



 

    ptr = strstr(kopie_string_buffer, "{");
    if(ptr != &kopie_string_buffer[0]){
        printf(RED"Falsch :"RESET"\t { nicht vorhanden oder nicht am Anfang der Zeichenkette.\n"RESET);
        return -1;
    }


    zähler = 0;
    zähler = findstring("{", &kopie_string_buffer);
    if(zähler > 1){
        printf(RED"Falsch :"RESET" { %d mal vorhanden\n"RESET, zähler);
    return -1;
    }
    
    ptr = strstr(&ptr[länge_string_buffer], "}");
    if(ptr != &kopie_string_buffer[länge_string_buffer]){
            printf(RED"Falsch :"RESET" } nicht vorhanden oder nicht am Anfang der Zeichenkette.\n"RESET);
    return -1;
    }
   

    ptr = strstr(kopie_string_buffer, ",");
    if(!ptr){
        printf(RED"Falsch :"RESET" , nicht vorhanden oder nicht am Anfang der Zeichenkette.\n"RESET);
    return -1;
    }
    
    zähler = 0;
    zähler = findstring(",", &kopie_string_buffer);
    if(zähler > 2){
        printf(RED"Falsch :"RESET" , %d mal zu viel vorhanden\n"RESET, zähler-2);
    return -1;
    }
    



/*
In dem String wird geprüft, ob die Zeichenbausteine, wie "vz": vorhanden sind.
*/

    start_adr_vz = strstr(kopie_string_buffer, vz_vg);
    start_adr_za = strstr(kopie_string_buffer, za_vg);
    start_adr_ne = strstr(kopie_string_buffer, ne_vg);



    if(start_adr_vz == NULL){
        printf(RED"Falsch :"RESET" \"vz\": nicht vorhanden\n"RESET);
       // return -1;
    }

    if(start_adr_za == NULL){
        printf(RED"Falsch :"RESET" \"za\": nicht vorhanden\n"RESET);
       // return -1;
    }
    
    if(start_adr_ne == NULL){
        printf(RED"Falsch :"RESET" \"ne\": nicht vorhanden\n"RESET);
        //return -1;
    }

    
    zähler = 0;
    zähler = findstring(vz_vg, (char**)start_adr_vz);
    printf("Hallo nach Findstring ende\n");
    if(zähler >= 1){
    printf(RED"Falsch :"RESET"\t \"vz\": %d mal vorhanden\n"RESET, zähler);
    return -1;
    }

    zähler = 0;
    zähler = findstring(za_vg, (char**)start_adr_ne);
    printf("Hallo nach Findstring ende\n");
    if(zähler >= 1){
    printf(RED"Falsch :"RESET"\t \"za\": %d mal vorhanden\n"RESET, zähler);
    return -1;
    }
    
    zähler = 0;
    zähler = findstring(ne_vg, (char**)kopie_string_buffer);
    if(zähler >= 1){
    printf(RED"Falsch :"RESET"\t \"ne\": %d mal vorhanden\n"RESET, zähler);
    return -1;
    }
    

printf("Die Eingabe ist Tip Top!\n");
free(kopie_string_buffer);
return 0;
}



/*


int to_json(const rational_t *r, uint8_t *json, size_t json_size){


return 0;
}
*/

/*
 * @param sucher_string ist das Suchkriterium, um die Elemente im String_1 zu finden.
 * @param pointer_adressen zeigt auf die Anfangsadresse der Strings.
 * @return int zähler zählt die Summe der gefundenen Elemente im String_1.
 */
int findstring(char *sucher_string, char **pointer_adresse){

int zähler = 0;
char *fundort_adresse = strstr(*pointer_adresse, sucher_string);
*pointer_adresse = fundort_adresse;

printf("Hallo findstring\n");
    while(fundort_adresse){
        zähler ++;
        fundort_adresse += strlen(sucher_string);
        fundort_adresse = strstr(fundort_adresse, sucher_string);
    }

return zähler;
}
