#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------
//Praktikum Nr.2
//Aufgabe Nr.1
//Oliver Schmidt
// Datum: 15.03.2022
//-------------------------------------------------------


#include<stdio.h>
#include<stdlib.h>


struct rationaleZahl {
	unsigned int nenner;
	unsigned int zaehler;
	char vorzeichen;
};


unsigned int ggT(struct rationaleZahl);
void ausgabe(struct rationaleZahl);





int main(void) {

	printf("\nPraktikum Nr.2 // Aufgabe Nr.1\n\n");

	struct rationaleZahl r1;

	do {
		r1.nenner = rand() % 10000;
		r1.zaehler = rand() % 1000;
		r1.vorzeichen = rand() % 2;

		ausgabe(r1);

	} while (getchar());
}






void ausgabe(struct rationaleZahl r1)
{
	double erg = 0;
	char vorzeichen;
	unsigned int ggT_zaehler = 0;
	unsigned int ggT_nenner = 0;



	if (r1.vorzeichen == 0) {
		vorzeichen = '-';
	}
	else if (r1.vorzeichen != 0) {
		vorzeichen = ' ';
	}


	ggT_zaehler = r1.zaehler / ggT(r1);
	ggT_nenner = r1.nenner / ggT(r1);
	
	erg=(double)(r1.zaehler)/(double)(r1.nenner);




	if (r1.nenner != 0) {

		printf("Zahl\t\t= %c%d/%d\n", vorzeichen, r1.zaehler, r1.nenner);
		printf("Zahl gekuertz\t= %c%d/%d\n", vorzeichen, ggT_zaehler, ggT_nenner);
		printf("Gleitkommazahl\t= %c%.24f\n",vorzeichen, erg);
		printf("\n----------------Press Enter----------------\n");

	}
	else {
		printf("Zahl\t\t= %c%d/%d = Error\n", vorzeichen, r1.zaehler, r1.nenner);
		printf("\n----------------Press Enter----------------\n");
	}


}








unsigned int ggT(struct rationaleZahl r1)
{
	unsigned int a = r1.zaehler;
	unsigned int b = r1.nenner;
	unsigned int c = 0;
	
	do
	{
		c = a % b;     
		a = b; b = c;           
	} while (c != 0);

	return a;
}


