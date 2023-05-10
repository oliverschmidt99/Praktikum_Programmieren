#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "rational.h"
#include "json.h"

/**
 * @brief Berechnet den größten gemeinsamen Teiler (GGT) von Zähler und Nenner einer rationalen Zahl.
 * 
 * Diese Funktion berechnet den größten gemeinsamen Teiler (GGT) von Zähler und Nenner einer rationalen Zahl 
 * und gibt ihn als `int` zurück.
 * 
 * @param rat_zahl Ein Zeiger auf das `rational`-Objekt, dessen GGT berechnet werden soll.
 * @return Der größte gemeinsame Teiler von Zähler und Nenner der rationalen Zahl.
 */
int ggt_teiler(rational *rat_zahl);


rational *creat(char vz, unsigned int za, unsigned int ne){
    rational *zahl =malloc(sizeof(rational));
    if (zahl != NULL){
        zahl->vz = vz;
        zahl->za = za;
        zahl->ne = ne;
    }
    return zahl;
}

void destroy(rational *zahl){
    free(zahl);
}


int multiplikation_rat(const rational *faktor_1, const rational *faktor_2, rational *produkt){

    produkt->za = faktor_1->za * faktor_2->za;
    produkt->ne = faktor_1->ne* faktor_2->ne;
    produkt->vz = faktor_1->vz * faktor_2->vz;

    ggt_teiler(produkt);
return 0;
}


int divison_rat(const rational *dividend, const rational *divisor, rational *quotient){

    if(dividend->za != 0 && divisor->ne !=0){   
        quotient->vz = dividend->vz*divisor->vz;
        quotient->za = dividend->za*divisor->ne;
        quotient->ne = dividend->ne*divisor->za;
        ggt_teiler(quotient);
    }
return 0;
}



int addition_rat(const rational *summand_1, const rational *summand_2, rational *summe){


    /*Bei einer Null-Wertung des Zählers sollte die Funktion direkt die Zahl nehmen, die keine Null enthält.
    Wenn die beiden Zahlen im Zähler den Wert Null haben, wird eine Null in der Summe-Zähler hinzugefügt.*/


    
    if(summand_1->za != 0 && summand_2->za != 0){

        summe->ne = (summand_1->ne * summand_2->ne);

        if(summand_1->vz == summand_2->vz){
            summe->za = (summand_1->za * summand_2->ne) + (summand_2->za * summand_1->ne);
            summe->vz = summand_1->vz;
        }
        else{
          summe->za = abs((summand_1->za * summand_2->ne) - (summand_2->za * summand_1->ne));
            if((summand_1->za * summand_2->ne) > (summand_2->za * summand_1->ne)){
                summe->vz = summand_1->vz;
            }
            else if((summand_1->za * summand_1->ne) < (summand_2->za * summand_2->ne)){
                summe->vz = summand_2->vz;
            }
        }
        ggt_teiler(summe);
    }
    else{

        if(summand_1->za == 0){
            summe->za = summand_2->za;
            summe->ne = summand_2->ne;
            summe->vz = summand_2->vz;
        }
        else if(summand_2->za == 0){
            summe->za = summand_1->za;
            summe->ne = summand_1->ne;
            summe->vz = summand_1->vz;
        }
        else{
            summe->za = 0;
        }
    }
return 0;
}


int subtrahtion_rat(const rational *minuend, rational *subtrahend, rational *differenz){
subtrahend->vz = -1*subtrahend->vz ;
addition_rat(minuend, subtrahend, differenz);    
return 0;
}








int ggt_teiler(rational *rat_zahl){

    unsigned int teiler = 0;
    unsigned int a      = rat_zahl->za;
    unsigned int b      = rat_zahl->ne;
    unsigned int c      = 0;


	if(a == 0){
	teiler = b;
	}
	else{
 	   while(b != 0){
    		c = a%b;
   	 	    a = b;
    	    b = c;
    		}
    teiler = a;
	}
        rat_zahl->za = rat_zahl->za/teiler;
        rat_zahl->ne = rat_zahl->ne/teiler;
        rat_zahl->vz = rat_zahl->vz;
    return 0;
}






//void ausgabe_rat(const rational *zahl, char type, unsigned int zaehler){
//
////printf("\nZahl = %u\n");
//
//
//}

