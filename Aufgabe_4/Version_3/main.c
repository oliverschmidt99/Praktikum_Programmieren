#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "rational.h"


#define RD "\x1B[31m"
#define GN "\x1B[32m"
#define WH "\x1B[34m"
#define RS "\x1B[0m"


int main(){

rational *z1 = creat(-1,8775,6343);
rational *z2 = creat(1,43453,8434);
rational *erg = creat(0,0,0);
rational *rückgabe_von_json = creat(0,0,0);

uint8_t buffer_form_json[] =  "{ \"za\": 4294967295 ,\"ne\": 4294967295, \"vz\": 1 }";
uint8_t buffer_to_json[10000];

int error = 0;


if(z1->ne != 0 && z2->ne != 0){
ggt_teiler(z1);
ggt_teiler(z2);

    printf("Zahl 1\t\t = ->%i %10u/%-10u<-\n", z1->vz, z1->za, z1->ne);
    printf("Zahl 2\t\t = ->%i %10u/%-10u<-\n\n", z2->vz, z2->za, z2->ne);

    multiplikation_rat(z1, z2, erg);
    printf("multiplikation\t = ->%i %10u/%-10u<-\n", erg->vz, erg->za, erg->ne);

    divison_rat(z1, z2, erg);
    printf("division\t = ->%i %10u/%-10u<-\n", erg->vz, erg->za, erg->ne);

    addition_rat(z1, z2, erg);
    printf("addition\t = ->%i %10u/%-10u<-\n", erg->vz, erg->za, erg->ne);

    subtrahtion_rat(z1, z2, erg);
    printf("subtrahtion\t = ->%i %10u/%-10u<-\n", erg->vz, erg->za, erg->ne);
}
else{
printf("\nNenner darf nicht Null sein!\n");    
}

error = von_json((uint8_t*)buffer_form_json, rückgabe_von_json);
if(error != 0){
printf(RD"Es ist ein Eingabefehler aufgetreten. Bitte überprüfen Sie Ihre Angaben!\n\n"RS);
return -1;
}
error = to_json(buffer_to_json, rückgabe_von_json);
if(error != 0){
printf(RD"Es ist ein Eingabefehler aufgetreten. Bitte überprüfen Sie Ihre Angaben!\n\n"RS);
return -1;
}
printf("zu json\t %s", buffer_to_json);

destroy(rückgabe_von_json);
destroy(z1);
destroy(z2);
destroy(erg);

printf("\n\n\n\n");
    return 0;
}
