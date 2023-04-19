


#ifndef _RATIONAL_H_
#define _RATIONAL_H_


struct rational {
    char vorzeichen;
    unsigned int nenner;
    unsigned int zaehler;
};



struct rational addion_rat(struct rational summand_1, struct rational summand_2);
struct rational subtrahtion_rat(struct rational minuend, struct rational subtrahend);
struct rational multiplikation_rat(struct rational faktor_1, struct rational faktor_2);
struct rational divison_rat(struct rational dividend, struct rational divisor);
void ausgabe_rat(struct rational zahl, char type, unsigned int zaehler);

#endif