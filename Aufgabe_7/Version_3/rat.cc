/**
 * @file rat.cc
 * @author Oliver Schmidt (oliverlucaschmidt@gmail.com)
 * @brief Implementierung der Funktionen und Methoden für die Rational-Klasse.
 * 
 * Diese Datei enthält die Implementierung der Funktionen und Methoden, die für die 
 * Arbeit mit Rationalzahlen in der Rational-Klasse benötigt werden. Sie enthält
 * die Definitionen der arithmetischen Operationen wie Multiplikation, Division,
 * Addition und Subtraktion für Rationalzahlen sowie weitere Hilfsfunktionen.
 * Die Implementierung basiert auf den in der Headerdatei "rat.hh" definierten Deklarationen. 
 * 
 * Die Rational-Klasse ermöglicht die Erstellung und Manipulation von Rationalzahlen
 * durch die Verwendung von Zählern (za) und Nennern (ne). Die Implementierung
 * berücksichtigt sowohl positive als auch negative Rationalzahlen und verwendet 
 * verschiedene Algorithmen wie den größten gemeinsamen Teiler (ggT) zur Vereinfachung 
 * der Rationalzahlen. Diese Datei stellt sicher, dass die Funktionen und Methoden 
 * der Rational-Klasse korrekt funktionieren und das erwartete Verhalten liefern.
 * 
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <cstdio>
#include <cmath>
#include "rat.hh"

using namespace std;


/**
 * @brief Konstruktor für ein Rational-Objekt.
 * @param num Der Zähler der rationalen Zahl.
 * @param denom Der Nenner der rationalen Zahl.
 * @param neg (optional) Gibt an, ob die Zahl negativ ist. Standardmäßig ist sie positiv.
 */
Rational::Rational(unsigned long num, unsigned long denom, bool neg)
  : negative(neg), za(num), ne(denom) {
}
/**
 * @brief Konstruktor für ein ggT_kgV-Objekt.
 * @param num1 Die erste Zahl.
 * @param num2 Die zweite Zahl.
 */
ggT_kgV::ggT_kgV(unsigned long num1, unsigned long num2)
  : zahl_1(num1), zahl_2(num2) {
}



Rational Rational::multiplikation(Rational multiplikand) {
  unsigned long new_za; ///< Neuer Zähler des Ergebnis-Bruchs
  unsigned long new_ne; ///< Neuer Nenner des Ergebnis-Bruchs
  bool new_negative; ///< Neues Vorzeichen des Ergebnis-Bruchs

  // Berechne den Zähler des Ergebnis-Bruchs
  new_za = za * multiplikand.za;
  // Berechne den Nenner des Ergebnis-Bruchs
  new_ne = ne * multiplikand.ne;
  // Berechne das neue Vorzeichen des Ergebnis-Bruchs
  new_negative = negative ^ multiplikand.negative;

  // Erzeuge ein neues Rational-Objekt mit dem berechneten Zähler, Nenner und Vorzeichen und gib es zurück
  return Rational(new_za, new_ne, new_negative);
}

Rational Rational::division(Rational divisor) {
  unsigned long new_za; ///< Neuer Zähler des Ergebnis-Bruchs
  unsigned long new_ne; ///< Neuer Nenner des Ergebnis-Bruchs
  bool new_negative; ///< Neues Vorzeichen des Ergebnis-Bruchs

  // Berechne den Zähler des Ergebnis-Bruchs
  new_za = za * divisor.ne;
  // Berechne den Nenner des Ergebnis-Bruchs
  new_ne = ne * divisor.za;
  // Berechne das neue Vorzeichen des Ergebnis-Bruchs
  new_negative = negative ^ divisor.negative;

  // Erzeuge ein neues Rational-Objekt mit dem berechneten Zähler, Nenner und Vorzeichen und gib es zurück
  return Rational(new_za, new_ne, new_negative);
}



Rational Rational::addition(Rational summand) {
  unsigned long new_za; ///< Neuer Zähler des Ergebnis-Bruchs
  unsigned long new_ne; ///< Neuer Nenner des Ergebnis-Bruchs
  bool new_negative; ///< Neues Vorzeichen des Ergebnis-Bruchs

  // Überprüfe, ob das Vorzeichen des aktuellen Bruchs mit dem Vorzeichen des Summanden übereinstimmt
  if (negative == summand.negative) {
    // Berechne den Zähler des Ergebnis-Bruchs, wenn die Vorzeichen übereinstimmen
    new_za = (za * summand.ne) + (summand.za * ne);
    new_negative = negative;
  } else {
    // Berechne den Zähler des Ergebnis-Bruchs, wenn die Vorzeichen nicht übereinstimmen
    if (za * summand.ne >= summand.za * ne) {
      new_za = (za * summand.ne) - (summand.za * ne);
      new_negative = negative;
    } else {
      new_za = (summand.za * ne) - (za * summand.ne);
      new_negative = summand.negative;
    }
  }
  
  // Berechne den Nenner des Ergebnis-Bruchs
  new_ne = ne * summand.ne;

  // Berechne den größten gemeinsamen Teiler (ggT) von Zähler und Nenner
  unsigned long teiler = ggT_kgV(new_ne, new_za).ggT(new_ne, new_za);

  // Kürze den Bruch, indem Zähler und Nenner durch den ggT geteilt werden
  new_za = new_za / teiler;
  new_ne = new_ne / teiler;

  // Erzeuge ein neues Rational-Objekt mit dem berechneten Zähler, Nenner und Vorzeichen und gib es zurück
  return Rational(new_za, new_ne, new_negative);
}




Rational Rational::subtraktion(Rational subtrahend) {
  unsigned long new_za; ///< Neuer Zähler des Ergebnis-Bruchs
  unsigned long new_ne; ///< Neuer Nenner des Ergebnis-Bruchs
  bool new_negative; ///< Neues Vorzeichen des Ergebnis-Bruchs

  // Überprüfe, ob das Vorzeichen des aktuellen Bruchs nicht mit dem Vorzeichen des Subtrahenden übereinstimmt
  if (negative != subtrahend.negative) {
    // Subtraktion von zwei Zahlen mit unterschiedlichen Vorzeichen
    new_za = (za * subtrahend.ne) + (subtrahend.za * ne);
    new_negative = negative;
  } else {
    // Subtraktion von zwei Zahlen mit dem gleichen Vorzeichen
    if (za >= subtrahend.za) {
      new_za = (za * subtrahend.ne) - (subtrahend.za * ne);
      new_negative = negative;
    } else {
      new_za = (subtrahend.za * ne) - (za * subtrahend.ne);
      new_negative = !negative;
    }
  }
  
  // Berechne den Nenner des Ergebnis-Bruchs
  new_ne = ne * subtrahend.ne;

  // Berechne den größten gemeinsamen Teiler (ggT) von Zähler und Nenner
  unsigned long teiler = ggT_kgV(new_ne, new_za).ggT(new_ne, new_za);

  // Kürze den Bruch, indem Zähler und Nenner durch den ggT geteilt werden
  new_za = new_za / teiler;
  new_ne = new_ne / teiler;

  // Erzeuge ein neues Rational-Objekt mit dem berechneten Zähler, Nenner und Vorzeichen und gib es zurück
  return Rational(new_za, new_ne, new_negative);
}



unsigned long ggT_kgV::ggT(unsigned long a, unsigned long b) {
  while (b != 0) {
    unsigned long temp = b; ///< Temporäre Variable zur Speicherung des aktuellen Wertes von b
    b = a % b; ///< Aktualisiere b mit dem Rest der Division von a durch b
    a = temp; ///< Aktualisiere a mit dem vorherigen Wert von b
  }
  return a; ///< Rückgabe des größten gemeinsamen Teilers (ggT)
}


unsigned long ggT_kgV::kgV(unsigned long a, unsigned long b) {
  return (a * b) / ggT(a, b);
}


/**
 * @brief Überladung des Operators '/' für die Division von zwei Rational-Objekten.
 * 
 * @param p Das linke Rational-Objekt (Dividend).
 * @param q Das rechte Rational-Objekt (Divisor).
 * @return Das Ergebnis der Division von p durch q.
 */
Rational operator/(Rational p, Rational q) {
  return p.division(q);
}
/**
 * @brief Überladung des Operators '*' für die Multiplikation von zwei Rational-Objekten.
 * 
 * @param p Das linke Rational-Objekt (Multiplikand).
 * @param q Das rechte Rational-Objekt (Multiplikator).
 * @return Das Ergebnis der Multiplikation von p mit q.
 */
Rational operator * (Rational p, Rational q) {
  return p.multiplikation(q);
}
/**
 * @brief Überladung des Operators '+' für die Addition von zwei Rational-Objekten.
 * 
 * @param p Das linke Rational-Objekt (Summand).
 * @param q Das rechte Rational-Objekt (Summand).
 * @return Das Ergebnis der Addition von p und q.
 */
Rational operator + (Rational p, Rational q) {
  return p.addition(q);
}

/**
 * @brief Überladung des Operators '-' für die Subtraktion von zwei Rational-Objekten.
 * 
 * @param p Das linke Rational-Objekt (Minuend).
 * @param q Das rechte Rational-Objekt (Subtrahend).
 * @return Das Ergebnis der Subtraktion von q von p.
 */
Rational operator - (Rational p, Rational q) {
  return p.subtraktion(q);
}


/**
*@brief Gibt das Rational-Objekt auf einem Ausgabestrom aus.
*
*@param os Der Ausgabestrom, auf dem das Rational-Objekt ausgegeben werden soll.
*@return Eine Referenz auf den übergebenen Ausgabestrom.
*/
std::ostream &Rational::print(std::ostream &os) {
  if (negative)
    os << '-';
  return os << za << '/' << ne;
}

/**
 * @brief Überladung des Operators '<<' für die Ausgabe eines Rational-Objekts auf einem Ausgabestrom.
 * 
 * @param os Der Ausgabestrom, auf dem das Rational-Objekt ausgegeben werden soll.
 * @param p Das Rational-Objekt, das ausgegeben werden soll.
 * @return Eine Referenz auf den übergebenen Ausgabestrom.
 */
std::ostream &operator<<(std::ostream &os, Rational p) {
  return p.print(os);
}
