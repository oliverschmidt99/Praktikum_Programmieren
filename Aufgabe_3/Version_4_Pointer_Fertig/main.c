#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include "rational.c"
#include "rational.h"



int main(){

rational *z1 = creat(-1,8775,6343);
rational *z2 = creat(1,43453,8434);
rational *erg = creat(0,0,0);



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


destroy(z1);
destroy(z2);
destroy(erg);

printf("\n\n\n\n");
    return 0;
}
