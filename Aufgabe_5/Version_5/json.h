#ifndef _JSON_H
#define _JSON_H

#include <stdint.h>


#define RD "\x1B[31m"
#define GN "\x1B[32m"
#define WH "\x1B[34m"
#define RS "\x1B[0m"
#define NL "\n"



/**
 * @brief Extrahiert eine rationale Zahl aus einem JSON-String und gibt sie als short zurück.
 *
 * Diese Funktion sucht im JSON-String nach der rationalen Zahl, die mit dem Schlüssel "rational" versehen ist.
 * Die Zahl wird dann extrahiert und als short zurückgegeben. Wenn der JSON-String ungültig ist oder der Schlüssel nicht gefunden wurde,
 * wird 0 zurückgegeben.
 *
 * @param storage Der JSON-String, der analysiert werden soll.
 * @param rational Ein Zeiger auf eine rational-Struktur, in der die extrahierte Zahl gespeichert wird.
 * @return Die extrahierte rationale Zahl als Short oder 0, wenn der JSON-String ungültig ist oder der Schlüssel nicht gefunden wurde.
 */
short get_json_objekt(const uint8_t *storage, rational *from_json, unsigned int len_objekt);
/**

@brief Erstellt einen JSON-String aus den Werten des übergebenen rationalen Datentyps und fügt ihn zum angegebenen Puffer hinzu.

@param storage Ein Zeiger auf den Puffer, zu dem der JSON-String hinzugefügt wird.

@param zu_json Ein Zeiger auf den rationalen Datentyp, dessen Werte zum JSON-String konvertiert werden.

@return int Falls der JSON-String erfolgreich erstellt und zum Puffer hinzugefügt wurde, wird 0 zurückgegeben. Andernfalls wird -1 zurückgegeben.

@details Diese Funktion erstellt einen JSON-String aus den Werten des übergebenen rationalen Datentyps und fügt ihn zum angegebenen Puffer hinzu. Zunächst werden die Werte des rationalen Datentyps überprüft, ob sie den Einschränkungen für JSON entsprechen. Wenn einer der Werte ungültig ist, wird -1 zurückgegeben und der JSON-String wird nicht erstellt. Ansonsten werden die Strings für jeden Wert erstellt und zu einem Gesamt-JSON-String zusammengefügt. Vor dem Hinzufügen zum Puffer wird geprüft, ob der JSON-String zusammen mit dem Puffer den verfügbaren Puffer nicht überschreitet. Wenn der Gesamt-JSON-String größer ist als der verfügbare Puffer, wird -1 zurückgegeben und der JSON-String wird nicht zum Puffer hinzugefügt.
*/
short to_json(uint8_t *storage, const rational *zu_json);
/**
 * @brief Zählt das Vorkommen eines Zeichens in einem String und gibt die Anzahl zurück.
 *
 * Diese Funktion sucht nach dem Vorkommen des angegebenen Zeichens im angegebenen String und gibt die Anzahl der Vorkommen zurück.
 *
 * @param sucher_string Der zu durchsuchende String.
 * @param pointer_adressen Ein Zeiger auf den ersten Charakter, der nach dem Suchvorgang gefunden wurde. Kann auf NULL gesetzt werden, wenn Sie die Adressen nicht benötigen.
 * @return Die Anzahl der Vorkommen des Zeichens im String.
 */
short count_string(char *sucher_string, char *pointer_adressen);
/**
 * @brief Liest einen JSON-Dateiinhalt aus einer Datei und gibt ihn als uint8_t-Zeiger zurück.
 * 
 * Die Funktion liest den Inhalt einer JSON-Datei aus einer angegebenen Datei und gibt diesen Inhalt
 * als Zeiger auf einen uint8_t-Array zurück. Der Rückgabezeiger kann dann verwendet werden, um 
 * den Inhalt weiterzuverarbeiten.
 * 
 * @param filename Der Name der JSON-Datei, die gelesen werden soll.
 * @return Ein Zeiger auf den Inhalt der gelesenen JSON-Datei als uint8_t-Array.
 */
uint8_t* read_json(char *filename);
/**
 * @brief Entfernt Leerzeichen und Zeilenumbrüche aus einem String.
 *
 * Extrahiert eine Zahl aus einem String und speichert sie in einer Datenstruktur.
 * Diese Funktion sucht nach einem bestimmten Muster in einem String und extrahiert daraus
 * eine Zahl, die in eine bestimmte Datenstruktur gespeichert wird. Sie wird verwendet,
 * um Zahlen aus einem JSON-String zu extrahieren. 
 *
 * @param str Ein Zeiger auf den Eingabe-String, der verarbeitet werden soll.
 * @param new_str Ein Zeiger auf ein char-Array, in das der bereinigte String geschrieben werden soll.
 */
void disassemble_string(char *str, char *new_str);
/**
 * @brief Konvertiert einen JSON-String in ein `rational`-Objekt und gibt die Anzahl der konvertierten Bytes zurück.
 * 
 * Diese Funktion nimmt einen JSON-String als uint8_t-Array und konvertiert ihn in ein `rational`-Objekt.
 * Der konvertierte `rational`-Objekt wird im Funktionsparameter `from_json` zurückgegeben.
 * Der bereinigte JSON-String wird in `storage_form_json` zurückgegeben.
 * Die Funktion gibt die Anzahl der Bytes zurück, die für die Konvertierung verwendet wurden.
 * 
 * @param storage Ein Zeiger auf den JSON-String, der konvertiert werden soll.
 * @param storage_form_json Ein Zeiger auf ein uint8_t-Array, in das der bereinigte JSON-String geschrieben werden soll.
 * @param from_json Ein Zeiger auf das `rational`-Objekt, in das der JSON-String konvertiert werden soll.
 * @return Die Anzahl der Bytes, die für die Konvertierung des JSON-Strings verwendet wurden.
 */
short from_json(const uint8_t *storage, uint8_t *storage_form_json, rational *from_json);

short extract_number(char *start_adr, rational *from_json, const char *vgl);
/**
 * @brief Extrahiert eine Zahl aus einem String und konvertiert sie in ein `rational`-Objekt.
 * 
 * Diese Funktion extrahiert eine Zahl aus einem String, der an der Stelle `start_adr` beginnt,
 * und konvertiert sie in ein `rational`-Objekt. Der konvertierte `rational`-Objekt wird im 
 * Funktionsparameter `from_json` zurückgegeben.
 * Der String wird mit dem angegebenen Vergleichsstring `vgl` verglichen, um sicherzustellen, dass
 * der extrahierte Wert der erwartete Wert ist.
 * Die Funktion gibt die Anzahl der Bytes zurück, die für die Konvertierung verwendet wurden.
 * 
 * @param start_adr Ein Zeiger auf den Anfang des Strings, aus dem die Zahl extrahiert werden soll.
 * @param from_json Ein Zeiger auf das `rational`-Objekt, in das die extrahierte Zahl konvertiert werden soll.
 * @param vgl Ein Zeiger auf den Vergleichsstring, um sicherzustellen, dass der extrahierte Wert der erwartete Wert ist.
 * @return Die Anzahl der Bytes, die für die Konvertierung der Zahl verwendet wurden.
 */
short write_json(const uint8_t *storage, const char *filename);



#endif