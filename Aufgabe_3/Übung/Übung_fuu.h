#ifndef _FUU_H
#define _FUU_H


typedef struct{
    char vz;
    unsigned int za;
    unsigned int ne;
}rational;


rational *creat(char vz, unsigned int ne, unsigned int za);
void destroy(rational *zahl);


int multiplikation_rat(const rational *faktor_1, const rational *faktor_2, rational *produkt);
int divison_rat(const rational *dividend, const rational *divisor, rational *quotient);
void ausgabe_rat(const rational *zahl, char type, unsigned int zaehler);


#endif