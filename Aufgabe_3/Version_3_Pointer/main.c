#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include "rational.h"
#include "rational.c"

const char loop_end = 4;
const char start = 0;//Bereiche um die Schleife zu starten: 0 für 10er; 4 für 1000er.
const char schleifen_ende = 16;





int main(void) {

    rational *zahl_1, *zahl_2, *erg, *empty;

    unsigned int zaehler_dowhile = 0;
    unsigned int zaehler_kalkulation = 0;
    unsigned int zaehler_dowhile_end = 0;
    unsigned int zaehler_start = start;


    printf("\n// Aufgabe Nr.3\n\n");
    
    ausgabe_rat(empty,'z',zaehler_kalkulation);

        do{
            erg = creat(0,0,0);
            zahl_1 = creat(0,0,0);
            zahl_2 = creat(0,0,0);
            empty = creat(1,0,0);

            ausgabe_rat(empty,'p',zaehler_kalkulation);     //Ausgabe für die Anzahl der Kalkulationen

            number_drop(zaehler_start, zahl_1);
            number_drop(zaehler_dowhile+start, zahl_2);
            
            if(zahl_1->nenner != 0 && zahl_2->nenner != 0){

                if(zahl_1->zaehler != 0 && zahl_2->zaehler != 0){
                ggT_teiler(zahl_1);         
                ggT_teiler(zahl_2);
                                
                multiplikation_rat(zahl_1, zahl_2);
                ausgabe_rat(erg, '*',0);

                divison_rat(zahl_1, zahl_2);
                ausgabe_rat(erg, '/',0);

                addion_rat(zahl_1, zahl_2);
                ausgabe_rat(erg, '+',0);

                subtrahtion_rat(zahl_1, zahl_2);
                ausgabe_rat(erg, '-',0);
                }
                else{
                    if(zahl_1->zaehler == 0){
                        ggT_teiler(zahl_2);
                        ausgabe_rat(empty,'0',0);
                        ausgabe_rat(empty,'0',0);
                        ausgabe_rat(zahl_2,'+',0);
                        zahl_2->vorzeichen *= zahl_2->vorzeichen;
                        ausgabe_rat(zahl_2,'-',0);
                    }
                    else{
                        ggT_teiler(zahl_1);
                        ausgabe_rat(empty,'0',0);
                        ausgabe_rat(empty,'x',0);
                        ausgabe_rat(zahl_1,'+',0);
                        ausgabe_rat(zahl_1,'-',0);
                    }
                }
            }           
            else{
            ausgabe_rat(empty,'x',0);
            }
            
        zaehler_dowhile++;//Zählt für den loop, also vier durchgänge der Hauptschleife und dann Rest.

            if(zaehler_dowhile == loop_end){
                zaehler_dowhile = 0;
                zaehler_start++;
            }

        zaehler_kalkulation++;//Zählt für die Ausgabe der Kalkulation.
        zaehler_dowhile_end++;//Zählt von 0-F durch, dann wird die Schleife beendet.
       


    destroy(erg);
    destroy(zahl_1);
    destroy(zahl_2);
    destroy(empty);



        }while(zaehler_dowhile_end != schleifen_ende);


printf("\n\n------------------end-----------------\n\n");
return 0;
}
