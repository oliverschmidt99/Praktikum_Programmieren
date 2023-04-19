#ifndef _RATIONAL_H
#define _RATIONAL_H


typedef struct{
    char vorzeichen;
    unsigned int nenner;
    unsigned int zaehler;
}rational;

rational *creat(char vorzeichen, unsigned int nenner, unsigned int zeahler);
void destroy(rational *zahl);

int addion_rat(rational *summand_1, rational *summand_2);
int subtrahtion_rat(rational *minuend, rational *subtrahend);
int multiplikation_rat(const rational *faktor_1, const rational *faktor_2);
int divison_rat(const rational *dividend, const rational *divisor);
void ausgabe_rat(const rational *zahl, char type, unsigned int zaehler);

#endif