#ifndef _RATIONAL_H
#define _RATIONAL_H


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
int subtrahtion_rat(const rational *minuend, rational *subtrahend, rational *differenz);
void ausgabe_rat(const rational *zahl, char type, unsigned int zaehler);

int to_json(const rational_t *r, uint8_t *json, size_t json_size);
int from_json(const uint8_t *json, size_t json_size, rational_t *r);

#endif
