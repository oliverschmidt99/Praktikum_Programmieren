#include <stdio.h>
#include <stdlib.h>
#include "Übung_fuu.h"


int ggt_teiler(rational *rat_zahl);

int a(int);
int b(int);

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


int multiplikation_rat(const rational *faktor_1, const rational *faktor_2, rational *produkt){

    produkt->za = faktor_1->za * faktor_2->za;
    produkt->ne = faktor_1->ne* faktor_2->ne;
    produkt->vz = faktor_1->vz * faktor_2->vz;

    ggt_teiler(produkt);

return 0;
}


int divison_rat(const rational *dividend, const rational *divisor, rational *quotient){

    quotient->vz = dividend->vz*divisor->vz;
    quotient->za = dividend->za*divisor->ne;
    quotient->ne = dividend->ne*divisor->za;

    ggt_teiler(quotient);

    return 0;
}












int ggt_teiler(rational *rat_zahl){

    unsigned int teiler = 0;
    unsigned int a = rat_zahl->za;
    unsigned int b = rat_zahl->ne;
    unsigned int c = 0;


if(a == 0){
teiler = b;
}
else{
    while(b != 0){
        c= a%b;
        a=b;
        b=c;
    }
    teiler = a;
}
        rat_zahl->za = rat_zahl->za/teiler;
        rat_zahl->ne = rat_zahl->ne/teiler;
        rat_zahl->vz = rat_zahl->vz;
    return 0;
}






void ausgabe_rat(const rational *zahl, char type, unsigned int zaehler){

//printf("\nZahl = %u\n");


}

