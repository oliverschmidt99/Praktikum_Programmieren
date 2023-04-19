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
int addition_rat(const rational *summand_1, const rational *summand_2, rational *summe);
int subtrahtion_rat(const rational *subtrahend, const rational *minuend, rational *differenz);
void ausgabe_rat(const rational *zahl, char type, unsigned int zaehler);


#endif