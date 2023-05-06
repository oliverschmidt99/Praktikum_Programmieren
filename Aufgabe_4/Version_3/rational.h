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


/**
 * @brief Zerlegt einen String in Tokens anhand eines Trennzeichens und fügt sie zu einem neuen String zusammen.
 *
 * @param buffer Der zu zerlegende String.
 * @param kopie_buffer_string Der neue String, zu dem die Tokens hinzugefügt werden.
 * @param trennzeichen Das Trennzeichen, das die Tokens im ursprünglichen String voneinander trennt.
 * @return Die Länge des neuen Strings als unsigned short.
 */
short zerlege_string(char *buffer, char *kopie_buffer_string, const char *trennzeichen);
/**
 * @brief Extrahiert eine rationale Zahl aus einem JSON-String und gibt sie als short zurück.
 *
 * Diese Funktion sucht im JSON-String nach der rationalen Zahl, die mit dem Schlüssel "rational" versehen ist.
 * Die Zahl wird dann extrahiert und als short zurückgegeben. Wenn der JSON-String ungültig ist oder der Schlüssel nicht gefunden wurde,
 * wird 0 zurückgegeben.
 *
 * @param buffer Der JSON-String, der analysiert werden soll.
 * @param rational Ein Zeiger auf eine rational-Struktur, in der die extrahierte Zahl gespeichert wird.
 * @return Die extrahierte rationale Zahl als Short oder 0, wenn der JSON-String ungültig ist oder der Schlüssel nicht gefunden wurde.
 */
short von_json(const uint8_t *buffer, rational *von_json);
/**

@brief Erstellt einen JSON-String aus den Werten des übergebenen rationalen Datentyps und fügt ihn zum angegebenen Puffer hinzu.

@param buffer Ein Zeiger auf den Puffer, zu dem der JSON-String hinzugefügt wird.

@param zu_json Ein Zeiger auf den rationalen Datentyp, dessen Werte zum JSON-String konvertiert werden.

@return int Falls der JSON-String erfolgreich erstellt und zum Puffer hinzugefügt wurde, wird 0 zurückgegeben. Andernfalls wird -1 zurückgegeben.

@details Diese Funktion erstellt einen JSON-String aus den Werten des übergebenen rationalen Datentyps und fügt ihn zum angegebenen Puffer hinzu. Zunächst werden die Werte des rationalen Datentyps überprüft, ob sie den Einschränkungen für JSON entsprechen. Wenn einer der Werte ungültig ist, wird -1 zurückgegeben und der JSON-String wird nicht erstellt. Ansonsten werden die Strings für jeden Wert erstellt und zu einem Gesamt-JSON-String zusammengefügt. Vor dem Hinzufügen zum Puffer wird geprüft, ob der JSON-String zusammen mit dem Puffer den verfügbaren Puffer nicht überschreitet. Wenn der Gesamt-JSON-String größer ist als der verfügbare Puffer, wird -1 zurückgegeben und der JSON-String wird nicht zum Puffer hinzugefügt.
*/
short to_json(uint8_t *buffer, const rational *zu_json);
/**
 * @brief Zählt das Vorkommen eines Zeichens in einem String und gibt die Anzahl zurück.
 *
 * Diese Funktion sucht nach dem Vorkommen des angegebenen Zeichens im angegebenen String und gibt die Anzahl der Vorkommen zurück.
 *
 * @param sucher_string Der zu durchsuchende String.
 * @param pointer_adressen Ein Zeiger auf den ersten Charakter, der nach dem Suchvorgang gefunden wurde. Kann auf NULL gesetzt werden, wenn Sie die Adressen nicht benötigen.
 * @return Die Anzahl der Vorkommen des Zeichens im String.
 */
short zähle_string(char *sucher_string, char *pointer_adressen);
/**
@brief Extrahiert eine Zahl aus einem String und speichert sie in einer Datenstruktur.
Diese Funktion sucht nach einem bestimmten Muster in einem String und extrahiert daraus
eine Zahl, die in eine bestimmte Datenstruktur gespeichert wird. Sie wird verwendet,
um Zahlen aus einem JSON-String zu extrahieren.
@param kopie_buffer_string Ein Pointer auf einen Puffer, in dem der zu durchsuchende String kopiert wird.
@param start_adr_vz Ein Pointer auf den Start des Musters im zu durchsuchenden String.
@param von_json Ein Pointer auf die Datenstruktur, in der die extrahierte Zahl gespeichert wird.
@param vz_vgl Ein Pointer auf das Muster, nach dem gesucht wird.
@return Gibt 0 zurück, wenn die Zahl erfolgreich extrahiert und gespeichert wurde, oder -1 im Fehlerfall.
*/
short extrahiere_zahl_aus_string(char* start_adr, rational *von_json, const char* vgl);

#endif
