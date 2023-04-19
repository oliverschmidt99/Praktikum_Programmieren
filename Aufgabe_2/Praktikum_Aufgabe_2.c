//-------------------------------------------------------
//Praktikum Nr.2
//Aufgabe Nr.3
//Oliver Schmidt
// Datum: 15.03.2022
//-------------------------------------------------------


#include<stdio.h>
#include<stdlib.h>





struct rational {
    char vorzeichen;
    unsigned int nenner;
    unsigned int zaehler;
};



struct rational addion_rat(struct rational summand_1, struct rational summand_2);
struct rational subtrahtion_rat(struct rational minuend, struct rational subtrahend);
struct rational multiplikation_rat(struct rational faktor_1, struct rational faktor_2);
struct rational divison_rat(struct rational dividend, struct rational divisor);
struct rational number_drop(unsigned int zahl_was);


unsigned int ggT(struct rational r1);
void ausgabe_rat(struct rational zahl, char type, unsigned int zaehler);




int main(void) {

    printf("\nPraktikum Nr.2 // Aufgabe Nr.3\n\n");

    struct rational r1, r2, zahl_1, zahl_2, erg;
    unsigned int zaehler = 0;
    
        for(zaehler = 1;zaehler <= 4;zaehler++){

            struct rational zahl_1 = {0,0,0};
            struct rational zahl_2 = {0,0,0};
            zahl_1 =  number_drop(zaehler);
            ausgabe_rat(zahl_1, '0',zaehler);
            zaehler += 2;
            zahl_2 =  number_drop(zaehler);
            ausgabe_rat(zahl_2, '0',zaehler);
            
            

        zaehler -= 2;

            erg = multiplikation_rat(zahl_1, zahl_2);
            ausgabe_rat(erg, '*',zaehler+10);

            erg = divison_rat(zahl_1, zahl_2);
            ausgabe_rat(erg, '/',zaehler+10);

            erg = addion_rat(zahl_1, zahl_2);
            ausgabe_rat(erg, '+',zaehler+10);

            erg = subtrahtion_rat(zahl_1, zahl_2);
            ausgabe_rat(erg, '-',zaehler+10);


            printf("\n\n------Press the enter key for the calculation %d------\n\n", zaehler+10+1);
            getchar();
        }
return 0;
}



struct rational number_drop(unsigned int zahl_was)
{
    struct rational zahl_01;    
    struct rational zahl_02;
    struct rational zahl_03;
    struct rational zahl_04;
    struct rational zahl_05;
    struct rational zahl_06;
    struct rational zahl_07;
    struct rational zahl_08;
    struct rational zahl_09;
    struct rational zahl_10;
    struct rational zahl_11;
  
    switch (zahl_was)
    {
    case 1:           //nenner > zähler und vorzeichen -  / zahlen 10er
        zahl_01.zaehler      = 12;
        zahl_01.nenner       = 24;
        zahl_01.vorzeichen   = -1;
        return zahl_01;
        break;
    case 2:           // nenner > zähler und vorzeichen + / zahlen 10er
        zahl_02.zaehler      = 12;
        zahl_02.nenner       = 24;
        zahl_02.vorzeichen   = 1;
        return zahl_02;
        break;
    case 3:           //nenner < zähler und vorzeichen -  / zahlen 10er
        zahl_03.zaehler      = 15;
        zahl_03.nenner       = 12;
        zahl_03.vorzeichen   = -1;
        return zahl_03;
    case 4:           //nenner < zähler und vorzeichen +  / zahlen 10er
        zahl_04.zaehler      = 15;
        zahl_04.nenner       = 12;
        zahl_04.vorzeichen   = 1;
        return zahl_04;

    
    case 5:           //nenner > zähler und vorzeichen -  / zahlen 100000000er
        zahl_05.zaehler      = 69247166;
        zahl_05.nenner       = 98497687;
        zahl_05.vorzeichen   = -1;
        return zahl_05;
    case 6:          //nenner > zähler und vorzeichen +  / zahlen 100000000er
        zahl_06.zaehler      = 69247166;
        zahl_06.nenner       = 98497687;
        zahl_06.vorzeichen   = 1;
        return zahl_06;
    case 7:           //nenner < zähler und vorzeichen -  / zahlen 100000000er
        zahl_07.zaehler      = 70264713;
        zahl_07.nenner       = 41224210;
        zahl_07.vorzeichen   = -1;
        return zahl_07;
    case 8:           //nenner < zähler und vorzeichen +  / zahlen 100000000er
        zahl_08.zaehler      = 70264713;
        zahl_08.nenner       = 41224210;
        zahl_08.vorzeichen   = 1;
        return zahl_08;
    //-----------------------------------------------------------------Sonderfälle-----------------------------------------------------

    case 9:         //nenner = zähler und vorzeichen - 
        zahl_09.zaehler      = 15;
        zahl_09.nenner       = 15;
        zahl_09.vorzeichen   = -1;
        return zahl_09;
    case 10:        //zähler = 0
        zahl_10.zaehler      = 0;
        zahl_10.nenner       = 15;
        zahl_10.vorzeichen   = 1;
        return zahl_10;
    case 11:          //nenner = 0
        zahl_11.zaehler      = 15;
        zahl_11.nenner       = 0;
        zahl_11.vorzeichen   = 1;
        return zahl_11;
    default:
        break;
    }
    


}



//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------addion_rat-----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------




struct rational addion_rat(struct rational summand_1, struct rational summand_2)
{
    struct rational summe;


    int ggT_1, ggT_2;
    double zahl_1 = 0, zahl_2 = 0;

    zahl_1 = (double)summand_1.zaehler/(double)summand_1.nenner;
    zahl_2 = (double)summand_2.zaehler/(double)summand_2.nenner;



    summe.nenner = summand_1.nenner*summand_2.nenner;
    summand_1.zaehler = summand_1.zaehler*summand_2.nenner;
    summand_2.zaehler = summand_2.zaehler*summand_1.nenner;


    if(summand_1.vorzeichen == summand_2.vorzeichen){
        summe.zaehler = summand_1.zaehler + summand_2.zaehler;
        if(summand_1.vorzeichen == -1)
            summe.vorzeichen = -1;
        else if(summand_1.vorzeichen == 1)
            summe.vorzeichen = 1;
        }
    else{
        if(summand_1.vorzeichen == -1){
          if(zahl_1 > zahl_2){
                summe.zaehler =  summand_1.zaehler - summand_2.zaehler;
                summe.vorzeichen = -1;
            }
            else if(zahl_1 < zahl_2){
                summe.zaehler = summand_2.zaehler - summand_1.zaehler;
                summe.vorzeichen = 1;
            }
        }
        else if(summand_2.vorzeichen == -1){
             if(zahl_1 > zahl_2){
                summe.zaehler =  summand_1.zaehler - summand_2.zaehler;
                summe.vorzeichen = 1;
            }
            else if(zahl_1 < zahl_2){
                summe.zaehler = summand_2.zaehler - summand_1.zaehler;
                summe.vorzeichen = -1;
            }

        }
    }
    return summe;
}




//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------subtrahtion_rat------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------


struct rational subtrahtion_rat(struct rational minuend, struct rational subtrahend)
{
    struct rational differenz;





    int ggT_1, ggT_2;
    double zahl_1 = 0, zahl_2 = 0;

    zahl_1 = (double)minuend.zaehler/(double)minuend.nenner;
    zahl_2 = (double)subtrahend.zaehler/(double)subtrahend.nenner;



    differenz.nenner = minuend.nenner*subtrahend.nenner;
    minuend.zaehler = minuend.zaehler*subtrahend.nenner;
    subtrahend.zaehler = subtrahend.zaehler*minuend.nenner;


    if(minuend.vorzeichen == subtrahend.vorzeichen){
        if( minuend.vorzeichen == -1 && subtrahend.vorzeichen == -1){
            if(zahl_1 > zahl_2){
                differenz.zaehler = minuend.zaehler - subtrahend.zaehler;
                differenz.vorzeichen = -1;
            }
            else if(zahl_1 < zahl_2){
                differenz.zaehler = subtrahend.zaehler - minuend.zaehler;
                differenz.vorzeichen = 1;
            }
        }
        else if( minuend.vorzeichen == 1 && subtrahend.vorzeichen == 1){
            if(zahl_1 > zahl_2){
                differenz.zaehler = minuend.zaehler - subtrahend.zaehler;
                differenz.vorzeichen = 1;
            }
            else if(zahl_1 < zahl_2){
                differenz.zaehler = subtrahend.zaehler - minuend.zaehler;
                differenz.vorzeichen = -1;
            }
        }
    }
    else{
         if(minuend.vorzeichen == -1){   
                differenz.zaehler = minuend.zaehler + subtrahend.zaehler;
                differenz.vorzeichen = -1;    
        }
        else if(subtrahend.vorzeichen == -1){
            differenz.zaehler = minuend.zaehler + subtrahend.zaehler;
            differenz.vorzeichen = 1;
        }
    }
    return differenz;
}


//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------multiplikation_rat---------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------


struct rational multiplikation_rat(struct rational faktor_1, struct rational faktor_2)
{

    struct rational produkt;

    produkt.zaehler = faktor_1.zaehler * faktor_2.zaehler;
    produkt.nenner = faktor_1.nenner * faktor_2.nenner;
    produkt.vorzeichen = faktor_1.vorzeichen * faktor_2.vorzeichen;

    return produkt;
}

struct rational divison_rat(struct rational dividend, struct rational divisor)
{

    struct rational quotient;


    quotient.zaehler = dividend.zaehler * divisor.nenner;
    quotient.nenner = dividend.nenner * divisor.zaehler;
    quotient.vorzeichen = dividend.vorzeichen * divisor.vorzeichen;

    return quotient;
}



unsigned int ggT(struct rational r1)
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

//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------ausgabe_rat----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------

void ausgabe_rat(struct rational zahl, char type, unsigned int zaehler)
{

    double ieee;
    int teiler = 0;

    ieee = (double)zahl.zaehler / (double)zahl.nenner;

    teiler = ggT(zahl);

    


    if (zahl.vorzeichen == -1) {
        switch (type)
        {
        case '*':
            printf("\nMultiplikation: \n");
            printf("Zahl %d\t\t= -(%u / %u)\n", zaehler,zahl.zaehler, zahl.nenner);
            printf("Zahl %d ggT\t= -(%u / %u)\n", zaehler,zahl.zaehler/teiler, zahl.nenner/teiler);
            printf("Gleitkommazahl %d\t= -%.10f\n", zaehler, ieee);
            break;
        case '/':
            printf("\nDivison: \n");
            printf("Zahl %d\t\t= -(%u / %u)\n", zaehler, zahl.zaehler, zahl.nenner);
            printf("Zahl %d ggT\t= -(%u / %u)\n", zaehler,zahl.zaehler/teiler, zahl.nenner/teiler);
            printf("Gleitkommazahl %d\t= -%.10f\n", zaehler,ieee);
            break;
        case '+':
            printf("\nAddition: \n");
            printf("Zahl %d\t\t= -(%u / %u)\n", zaehler,zahl.zaehler, zahl.nenner);
            printf("Zahl %d ggT\t= -(%u / %u)\n", zaehler,zahl.zaehler/teiler, zahl.nenner/teiler);
            printf("Gleitkommazahl %d\t= -%.10f\n", zaehler,ieee);
            break;
        case '-':
            printf("\nSubtrahtion: \n");
            printf("Zahl %d\t\t= -(%u / %u)\n", zaehler,zahl.zaehler, zahl.nenner);
            printf("Zahl %d ggT\t= -(%u / %u)\n", zaehler,zahl.zaehler/teiler, zahl.nenner/teiler);
            printf("Gleitkommazahl %d\t= -%.10f\n",zaehler, ieee);
            break;
        case '0':
            printf("Zahl %d\t\t= -(%u / %u)\n", zaehler, zahl.zaehler, zahl.nenner);
            break;
        default:
            break;
        }
    }
    else {
        switch (type)
        {
        case '*':
            printf("\nMultiplikation: \n");
            printf("Zahl %d\t\t= (%u / %u)\n", zaehler,zahl.zaehler, zahl.nenner);
            printf("Zahl %d ggT\t= (%u / %u)\n", zaehler,zahl.zaehler/teiler, zahl.nenner/teiler);
            printf("Gleitkommazahl %d\t= %.10f\n",zaehler, ieee);
            break;
        case '/':
            printf("\nDivison: \n");
            printf("Zahl %d\t\t= (%u / %u)\n", zaehler, zahl.zaehler, zahl.nenner);
            printf("Zahl %d ggT\t= (%u / %u)\n", zaehler, zahl.zaehler/teiler, zahl.nenner/teiler);
            printf("Gleitkommazahl %d\t= %.10f\n",zaehler, ieee);
            break;
        case '+':
            printf("\nAddition: \n");
            printf("Zahl %d\t\t= (%u / %u)\n", zaehler, zahl.zaehler, zahl.nenner);
            printf("Zahl %d ggT\t= (%u / %u)\n",zaehler, zahl.zaehler/teiler, zahl.nenner/teiler);
            printf("Gleitkommazahl %d\t= %.10f\n", zaehler, ieee);
            break;
        case '-':
            printf("\nSubtrahtion: \n");
            printf("Zahl %d\t\t= (%u / %u)\n", zaehler,zahl.zaehler, zahl.nenner);
            printf("Zahl  %d ggT\t= (%u / %u)\n", zaehler,zahl.zaehler/teiler, zahl.nenner/teiler);
            printf("Gleitkommazahl %d\t= %.10f\n",zaehler, ieee);
            break;
        case '0':
            printf("Zahl %d\t\t=  (%u / %u)\n", zaehler,zahl.zaehler, zahl.nenner);
            break;
        default:
            break;
        }
    }
    return;
}
