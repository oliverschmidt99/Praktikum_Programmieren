#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include "Übung_fuu.c"
#include "Übung_fuu.h"





int main(){
rational *z1 = creat(1,3,6);
rational *z2 = creat(-1,12,5);
rational *erg = creat(0,0,0);

printf("%i %u %u\n", z1->vz, z1->za, z1->ne);
printf("%i %u %u\n", z2->vz, z2->za, z2->ne);

multiplikation_rat(z1, z2, erg);
printf("multiplikation = %i %u / %u\n", erg->vz, erg->za, erg->ne);

division_rat(z1, z2, erg);
printf("division = %i %u / %u\n", erg->vz, erg->za, erg->ne);

addition_rat(z1, z2, erg);
printf("addition = %i %u / %u\n", erg->vz, erg->za, erg->ne);



    destroy(z1);
    destroy(z2);
    destroy(erg);

    return 0;
}