#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>




int main(){
printf("\n\n");

uint8_t buffer[] =  "{ \"v\": 1, \"z\": 13, \"n\": 7 }";
                    //"{ \"z\": 14, \"n\": 13, \"v\": -1 }"
                    //"{ \"v\": 0, \"z\": -8 }"
                    //"{ \"n\": 13, \"v\": 1, \"z\": 98 }";


    int value = 0;
    int count = 0;
    for (int i = 0; i < sizeof(buffer); i++) {
        if (buffer[i] >= '0' && buffer[i] <= '9') {
        
        }
        
    }




printf("buffer: %s\n", buffer);




printf("\n\n");
}


/*


int from_json(const uint8_t* buffer, const size_t length, rational_t* result){

    uint8_t *buffer[] ={
        { "v": 1, "z": 13, "n": 7 }
        { "z": 2, "n": 3, "v": -1 }
        { "v": 1 , "n" : 1, "z": 0 }
        {"z": 17, "v": -1,"n":1}
    };


memcpy()

return 0;
}



int to_json(const rational_t *r, uint8_t *json, size_t json_size){


return 0;
}
*/