#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


typedef struct{
    char vz;
    unsigned int za;
    unsigned int ne;
}rational;


int from_json(const uint8_t* buffer);
int findstring(char *sucher_string, char **pointer_adressen);


int main(){
printf("\n\n");

//int länge = 0;
//rational result;


uint8_t buffer[] =  "{\"vz\": 1, \"za\": 13, \"ne\": 7}";

from_json((uint8_t*)buffer);


printf("\n\n");
}



int from_json(const uint8_t* buffer){

 //   rational json;
    printf("buffer: %s\n\n", buffer);
    char* ptr;
    char* kopie_string_1;
    int länge_string_1;
    int zähler = 0;

    länge_string_1 = strlen(buffer+1);
    kopie_string_1 = malloc(länge_string_1);
    strcpy((char*)kopie_string_1, buffer);

    
    ptr = strstr(buffer, "{");
    if(ptr != &buffer[0]){
        printf("Falsch:\t { nicht vorhanden oder nicht am Anfang der Zeichenkette.\n");
        return 1;
    }
    else{
        zähler = 0;
        zähler = findstring("{", &buffer);
        if(zähler > 1){
        printf("Flasch:\t { %d mal vorhanden\n", zähler);
        return 1;
        }
        printf("Richtig: { vorhanden\n");
        
        
        
        ptr = strstr(&ptr[länge_string_1], "}");
            if(!ptr){
                printf("Falsch:\t } nicht vorhanden oder nicht am Anfang der Zeichenkette.\n");
                return 1;
            }
        printf("Richtig: } vorhanden\n");
        }






    ptr = strstr(buffer, "\"vz\":");
    if(!ptr){
        printf("Falsch: \"vz\": nicht vorhanden\n");
        return 1;
    }else{
     zähler = 0;
        zähler = findstring("\"vz\":", &buffer);
        if(zähler > 1){
        printf("Flasch:\t \"vz\": %d mal vorhanden\n", zähler);
        return 1;
        }
        printf("Richtig: \"vz\": vorhanden\n");
    }


    ptr = strstr(buffer, "\"za\":");
    if(!ptr){
        printf("Falsch: \"za\": nicht vorhanden\n");
        return 1;
    }else{
    zähler = 0;
        zähler = findstring("\"za\":", &buffer);
        if(zähler > 1){
        printf("Flasch:\t \"za\": %d mal vorhanden\n", zähler);
        return 1;
        }
        printf("Richtig: \"za\": vorhanden\n");
    }


    ptr = strstr(buffer, "\"ne\":");
    if(!ptr){
        printf("Falsch: \"ne\": nicht vorhanden\n");
        return 1;
    }else{
    zähler = 0;
        zähler = findstring("\"ne\":", &buffer);
        if(zähler > 1){
        printf("Flasch:\t \"ne\": %d mal vorhanden\n", zähler);
        return 1;
        }
        printf("Richtig: \"ne\": vorhanden\n");
    }

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
