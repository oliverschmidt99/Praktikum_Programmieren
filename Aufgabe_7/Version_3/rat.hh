/**
 * @file rat.hh
 * @author Oliver Schmidt (oliverlucaschmidt@gmail.com)
 * @brief Enthält die Deklarationen für die Rational-Klasse und zugehörige Funktionen.
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */



#ifndef RAT_HH_
#define RAT_HH_ 1

#include <iostream>

/**
 * @class Rational
 * @brief Stellt eine rationale Zahl dar.
 *
 * Die Klasse Rational bietet Methoden zum Durchführen von arithmetischen Operationen
 * auf rationalen Zahlen.
 */
class Rational {
protected:
  bool negative; ///< Flag, das angibt, ob die rationale Zahl negativ ist
  unsigned long za; ///< Zähler der rationalen Zahl
  unsigned long ne; ///< Nenner der rationalen Zahl
public:
  /**
   * @brief Konstruiert ein Rational-Objekt.
   * @param za Der Zähler der rationalen Zahl.
   * @param ne Der Nenner der rationalen Zahl.
   * @param negative (optional) Gibt an, ob die Zahl negativ ist. Standardmäßig ist sie positiv.
   */
  Rational(unsigned long za, unsigned long ne, bool negative = false);

  /**
   * @brief Multipliziert das aktuelle Rational-Objekt mit dem übergebenen Multiplikanden.
   * @param multiplikand Der Multiplikand.
   * @return Das Ergebnis der Multiplikation als neues Rational-Objekt.
   */
  Rational multiplikation(Rational multiplikand);

  /**
   * @brief Dividiert das aktuelle Rational-Objekt durch den übergebenen Divisor.
   * @param divisor Der Divisor.
   * @return Das Ergebnis der Division als neues Rational-Objekt.
   */
  Rational division(Rational divisor);

  /**
   * @brief Addiert das aktuelle Rational-Objekt mit dem übergebenen Summanden.
   * @param summand Der Summand.
   * @return Das Ergebnis der Addition als neues Rational-Objekt.
   */
  Rational addition(Rational summand);

  /**
   * @brief Subtrahiert den übergebenen Subtrahenden vom aktuellen Rational-Objekt.
   * @param subtrahend Der Subtrahend.
   * @return Das Ergebnis der Subtraktion als neues Rational-Objekt.
   */
  Rational subtraktion(Rational subtrahend);

  /**
   * @brief Berechnet den größten gemeinsamen Teiler (ggT) des aktuellen Rational-Objekts.
   * @param zahl Eine rationale Zahl.
   * @return Das Ergebnis des ggT als neues Rational-Objekt.
   */
  Rational ggT(Rational zahl);

  /**
   * @brief Gibt das aktuelle Rational-Objekt auf dem übergebenen Ausgabestrom aus.
   * @param outstream Der Ausgabestrom.
   * @return Der Ausgabestrom nach der Ausgabe des Rational-Objekts.
   */
  std::ostream &print(std::ostream &outstream);
};


/**
 * @class ggT_kgV
 * @brief Stellt Methoden zur Berechnung des ggT und kgV von zwei Zahlen zur Verfügung.
 */
class ggT_kgV{
protected:
  unsigned long zahl_1; ///< Erste Zahl
  unsigned long zahl_2; ///< Zweite Zahl
public:
  /**
   * @brief Konstruiert ein ggT_kgV-Objekt.
   * @param zahl_1 Die erste Zahl.
   * @param zahl_2 Die zweite Zahl.
   */
  ggT_kgV(unsigned long zahl_1, unsigned long zahl_2);

  /**
   * @brief Berechnet den größten gemeinsamen Teiler (ggT) von zwei Zahlen.
   * @param za Die erste Zahl.
   * @param ne Die zweite Zahl.
   * @return Der ggT der beiden Zahlen.
   */
  unsigned long ggT(unsigned long za, unsigned long ne);

  /**
   * @brief Berechnet das kleinste gemeinsame Vielfache (kgV) von zwei Zahlen.
   * @param ne_1 Die erste Zahl.
   * @param ne_2 Die zweite Zahl.
   * @return Das kgV der beiden Zahlen.
   */
  unsigned long kgV(unsigned long ne_1, unsigned long ne_2);
};

#endif /* RAT_HH_ */

