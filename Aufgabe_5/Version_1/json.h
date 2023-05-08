#ifndef _JSON_H
#define _JSON_H

#include <stdint.h>


#define RD "\x1B[31m"
#define GN "\x1B[32m"
#define WH "\x1B[34m"
#define RS "\x1B[0m"
#define NL "\n"

typedef struct{
    char vz;
    unsigned int za;
    unsigned int ne;
}rational;



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



uint8_t* open_json(char* filename);


short wirt_json(rational * rat_zahl, const char* phad);

#endif