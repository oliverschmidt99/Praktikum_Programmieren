/**
 * @file main.cc
 * @autor: Oliver Schmidt (oliverlucaschmidt@gmail.com)
 * @brief Demonstration der Verwendung der Rational-Klasse für arithmetische Operationen mit rationalen Zahlen.
 * 
 * Dieses Programm zeigt die Verwendung der Rational-Klasse zur Durchführung von 
 * arithmetischen Operationen mit rationalen Zahlen. Es erzeugt zwei rationale 
 * Zahlen und führt dann Multiplikation, Division, Addition und Subtraktion mit
 * ihnen durch. Die Ergebnisse werden auf der Standardausgabe ausgegeben.
 * Das Programm dient dazu, die Funktionalität der Rational-Klasse zu testen
 * und zu demonstrieren.
 * 
 *
 * @version: 0.1
 * @date 2023-05-19
 * @copyright (c) 2023
 */

#include <cstdio>
#include "rat.hh"
#include "rat.cc"

/**
 * @brief Hauptfunktion des Programms.
 * @return Rückgabewert 0 bei erfolgreichem Programmabschluss.
 */
int main() {
  printf("Aufgabe 7\n\n");

  // Erzeuge zwei rationale Zahlen p und q
  Rational p(1, 2, true);
  Rational q(7, 6, true);

  // Führe verschiedene Operationen mit den rationalen Zahlen aus und gib die Ergebnisse aus
  std::cout << (p * q) << std::endl; // Multiplikation
  std::cout << (p / q) << std::endl; // Division
  std::cout << (p + q) << std::endl; // Addition
  std::cout << (p - q) << std::endl; // Subtraktion

  printf("\n");

  return 0;
}
