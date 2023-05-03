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



int main(){
printf("\n\n");

int länge = 0;
rational result;


uint8_t buffer[] =  "{ \"v\" : 1, \"z\": 13, \"n\": 7 }";

from_json((uint8_t*)buffer);


printf("\n\n");
}



int from_json(const uint8_t* buffer){

    rational json;
    printf("buffer: %s\n", buffer);
    char* ptr;

    
    ptr = strstr(buffer, "{");
    if(!ptr){
        printf("Falsch: { nicht vohrhanden\n");
        return 1;
    }
    printf("Richtig: { vohrhanden\n");


    ptr = strstr(&ptr[1], "}");
    if(!ptr){
        printf("Falsch: } nicht vohrhanden\n");
        return 1;
    }
    printf("Richtig: } vohrhanden\n");
    

return 0;
}



/*


int to_json(const rational_t *r, uint8_t *json, size_t json_size){


return 0;
}
*/
