#ifndef _RATIONAL_H
#define _RATIONAL_H

#include <stdint.h>


typedef struct{
    char vz;
    unsigned int za;
    unsigned int ne;
}rational;



/**
 * Erstellt eine neue rationale Zahl.
 *
 * @param vz Das Vorzeichen der Zahl (+ oder -).
 * @param ne Der Nenner der Zahl.
 * @param za Der Zähler der Zahl.
 *
 * @return Ein Zeiger auf die neu erstellte rationale Zahl.
 */
rational *creat(char vz, unsigned int ne, unsigned int za);

/**
 * Zerstört eine vorhandene rationale Zahl.
 *
 * @param zahl Ein Zeiger auf die zu zerstörende Zahl.
 */
void destroy(rational *zahl);

/**
 * Multipliziert zwei rationale Zahlen.
 *
 * @param faktor_1 Ein Zeiger auf den ersten Faktor.
 * @param faktor_2 Ein Zeiger auf den zweiten Faktor.
 * @param produkt Ein Zeiger auf die zu speichernde Produktzahl.
 *
 * @return 0 bei Erfolg, -1 bei einem Fehler.
 */
int multiplikation_rat(const rational *faktor_1, const rational *faktor_2, rational *produkt);

/**
 * Dividiert eine rationale Zahl durch eine andere.
 *
 * @param dividend Ein Zeiger auf die zu dividierende Zahl.
 * @param divisor Ein Zeiger auf die Zahl, durch die dividiert wird.
 * @param quotient Ein Zeiger auf die zu speichernde Quotientzahl.
 *
 * @return 0 bei Erfolg, -1 bei einem Fehler.
 */
int divison_rat(const rational *dividend, const rational *divisor, rational *quotient);

/**
 * Addiert zwei rationale Zahlen.
 *
 * @param summand_1 Ein Zeiger auf den ersten Summanden.
 * @param summand_2 Ein Zeiger auf den zweiten Summanden.
 * @param summe Ein Zeiger auf die zu speichernde Summenzahl.
 *
 * @return 0 bei Erfolg, -1 bei einem Fehler.
 */
int addition_rat(const rational *summand_1, const rational *summand_2, rational *summe);

/**
 * Subtrahiert eine rationale Zahl von einer anderen.
 *
 * @param minuend Ein Zeiger auf die zu subtrahierende Zahl.
 * @param subtrahend Ein Zeiger auf die Zahl, die subtrahiert wird.
 * @param differenz Ein Zeiger auf die zu speichernde Differenzzahl.
 *
 * @return 0 bei Erfolg, -1 bei einem Fehler.
 */
int subtrahtion_rat(const rational *minuend, rational *subtrahend, rational *differenz);

/**
 * Gibt eine rationale Zahl aus.
 *
 * @param zahl Ein Zeiger auf die auszugebende Zahl.
 * @param type Der Typ der Ausgabe ('z' für den Zähler, 'n' für den Nenner).
 * @param zaehler Der Zähler der Ausgabe (0 für keine Einschränkung).
 */
void ausgabe_rat(const rational *zahl, char type, unsigned int zaehler);


#endif