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


int from_json(const uint8_t* buffer);
int findstring(char *sucher_string, char **pointer_adressen);


//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------




int main(){
printf("\n\n");

//int länge = 0;
//rational result;


uint8_t buffer[] =  "{\"vz\": 23,\"za\": 33, \"ne\": 7}";

from_json((uint8_t*)buffer);


printf("\n\n");
}



//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------------



int from_json(const uint8_t* buffer){

 //   rational json;
    printf("buffer: %s\n\n", buffer);
    char* ptr;
    char* kopie_string_1;
    char* kopie_string_vz;
    char* kopie_string_ne;
    char* kopie_string_za;
    char* start_adr_vz;
    char* start_adr_za;
    char* start_adr_ne;
    char* end_adr_vz;
    char* end_adr_za;
    char* end_adr_ne;
    
    int länge_string_1;
    int zähler = 0;
    char such_string_nummer[] = "-1234567890";

    länge_string_1 = strlen(buffer+1);
    kopie_string_1 = malloc(länge_string_1);
    kopie_string_vz = malloc(länge_string_1);
    kopie_string_za = malloc(länge_string_1);
    kopie_string_ne = malloc(länge_string_1);
    strcpy((char*)kopie_string_1, buffer);

    
    ptr = strstr(buffer, "{");
    if(ptr != &buffer[0]){
        printf(RED"Falsch :"RESET"\t { nicht vorhanden oder nicht am Anfang der Zeichenkette.\n"RESET);
        return -1;
    }
    else{
        zähler = 0;
        zähler = findstring("{", &buffer);
        if(zähler > 1){
        printf(RED"Falsch :"RESET"\t { %d mal vorhanden\n"RESET, zähler);
        return -1;
        }
        printf(GREEN"Richtig:"RESET" { vorhanden\n"RESET);
        
        
        
        ptr = strstr(&ptr[länge_string_1], "}");
            if(!ptr){
                printf(RED"Falsch :"RESET"\t } nicht vorhanden oder nicht am Anfang der Zeichenkette.\n"RESET);
                return -1;
            }
        printf(GREEN"Richtig:"RESET" } vorhanden\n"RESET);
        }




    ptr = strstr(buffer, ",");
    if(!ptr){
        printf(RED"Falsch :"RESET" , nicht vorhanden oder nicht am Anfang der Zeichenkette.\n"RESET);
        return -1;
    }
    else{
        zähler = 0;
        zähler = findstring(",", &buffer);
        if(zähler > 2){
        printf(RED"Falsch :"RESET" , %d mal zu viel vorhanden\n"RESET, zähler-2);
        return -1;
        }
        printf(GREEN"Richtig:"RESET" , %d mal vorhanden\n"RESET, zähler);
    }


/*
In dem String wird geprüft, ob die Zeichenbausteine, wie "vz": vorhanden sind.
*/

    start_adr_vz = strstr(buffer, "\"vz\":");
    if(!start_adr_vz){
        printf(RED"Falsch :"RESET" \"vz\": nicht vorhanden\n"RESET);
        return -1;
    }
    else{
        printf(GREEN"Richtig:"RESET" \"vz\": vorhanden\n"RESET);
    }


    start_adr_za = strstr(buffer, "\"za\":");
    if(!start_adr_za){
        printf(RED"Falsch :"RESET" \"za\": nicht vorhanden\n"RESET);
        return -1;
    }else{
    zähler = 0;
        zähler = findstring("\"za\":", &buffer);
        if(zähler > 1){
        printf(RED"Falsch :"RESET"\t \"za\": %d mal vorhanden\n"RESET, zähler);
        return -1;
        }
        printf(GREEN"Richtig:"RESET" \"za\": vorhanden\n"RESET);
    }


    start_adr_ne = strstr(buffer, "\"ne\":");
    if(!ptr){
        printf(RED"Falsch :"RESET" \"ne\": nicht vorhanden\n"RESET);
        return -1;
    }else{
    zähler = 0;
        zähler = findstring("\"ne\":", &buffer);
        if(zähler > 1){
        printf(RED"Falsch :"RESET"\t \"ne\": %d mal vorhanden\n"RESET, zähler);
        return -1;
        }
        printf(GREEN"Richtig:"RESET" \"ne\": vorhanden\n"RESET);
    }



    














free(kopie_string_vz);
free(kopie_string_za);
free(kopie_string_ne);
free(kopie_string_1);
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


    while(fundort_adresse){
        zähler ++;
        fundort_adresse += strlen(sucher_string);
        fundort_adresse = strstr(fundort_adresse, sucher_string);
    }

return zähler;
}
