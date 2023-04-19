
#include <stdio.h>
#include <stdlib.h>
#include "rational.h"


int number_drop(unsigned int zahl_auswahl);
int ggT_teiler(rational *rat_zahl);





//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------addion_rat-----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------




int addion_rat(rational *summand_1,  rational *summand_2){
    
    rational *summe;


    double zahl_1 = 0, zahl_2 = 0;

    zahl_1 = (double)summand_1->zaehler/(double)summand_1->nenner;
    zahl_2 = (double)summand_2->zaehler/(double)summand_2->nenner;



    summe->nenner = (summand_1->nenner*summand_2->nenner);

    summand_1->zaehler = (summand_1->zaehler*summand_2->nenner);
    summand_2->zaehler = (summand_2->zaehler*summand_1->nenner);


    if(summand_1->vorzeichen == summand_2->vorzeichen){
        summe->zaehler = summand_1->zaehler + summand_2->zaehler;
        if(summand_1->vorzeichen == -1)
            summe->vorzeichen = -1;
        else if(summand_1->vorzeichen == 1)
            summe->vorzeichen = 1;
        }
    else{
        if(summand_1->vorzeichen == -1){
          if(zahl_1 > zahl_2){
                summe->zaehler =  summand_1->zaehler - summand_2->zaehler;
                summe->vorzeichen = -1;
            }
            else if(zahl_1 < zahl_2){
                summe->zaehler = summand_2->zaehler - summand_1->zaehler;
                summe->vorzeichen = 1;
            }
        }
        else if(summand_2->vorzeichen == -1){
             if(zahl_1 > zahl_2){
                summe->zaehler =  summand_1->zaehler - summand_2->zaehler;
                summe->vorzeichen = 1;
            }
            else if(zahl_1 < zahl_2){
                summe->zaehler = summand_2->zaehler - summand_1->zaehler;
                summe->vorzeichen = -1;
            }

        }

    ggT_teiler(summe);

    }
    return 0;
}




//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------subtrahtion_rat------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------


int subtrahtion_rat(rational *minuend, rational *subtrahend)
{
    rational *differenz;
    double zahl_1 = 0, zahl_2 = 0;


    zahl_1 = (double)minuend->zaehler/(double)minuend->nenner;
    zahl_2 = (double)subtrahend->zaehler/(double)subtrahend->nenner;



    differenz->nenner = minuend->nenner*subtrahend->nenner;            //Der nenner wird multipliziert.
    minuend->zaehler = minuend->zaehler*subtrahend->nenner;
    subtrahend->zaehler = subtrahend->zaehler*minuend->nenner;


    if(minuend->vorzeichen == subtrahend->vorzeichen){
        if( minuend->vorzeichen == -1 && subtrahend->vorzeichen == -1){
            if(zahl_1 > zahl_2){
                differenz->zaehler = minuend->zaehler - subtrahend->zaehler;
                differenz->vorzeichen = -1;
            }
            else if(zahl_1 < zahl_2){
                differenz->zaehler = subtrahend->zaehler - minuend->zaehler;
                differenz->vorzeichen = 1;
            }
        }
        else if( minuend->vorzeichen == 1 && subtrahend->vorzeichen == 1){
            if(zahl_1 > zahl_2){
                differenz->zaehler = minuend->zaehler - subtrahend->zaehler;
                differenz->vorzeichen = 1;
            }
            else if(zahl_1 < zahl_2){
                differenz->zaehler = subtrahend->zaehler - minuend->zaehler;
                differenz->vorzeichen = -1;
            }
        }
    }
    else{
         if(minuend->vorzeichen == -1){   
                differenz->zaehler = minuend->zaehler + subtrahend->zaehler;
                differenz->vorzeichen = -1;    
        }
        else if(subtrahend->vorzeichen == -1){
            differenz->zaehler = minuend->zaehler + subtrahend->zaehler;
            differenz->vorzeichen = 1;
        }

       ggT_teiler(differenz);
    }
    return 0;
}


//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------multiplikation_rat---------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------


int multiplikation_rat(const rational *faktor_1, const rational *faktor_2)
{

    rational *produkt;

    produkt->zaehler = faktor_1->zaehler * faktor_2->zaehler;
    produkt->nenner = faktor_1->nenner * faktor_2->nenner;
    produkt->vorzeichen = faktor_1->vorzeichen * faktor_2->vorzeichen;

    ggT_teiler(produkt);

    return 0;
}





//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------divison_rat----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------


int divison_rat(const rational *dividend, const rational *divisor){

    rational *quotient;

    quotient->zaehler = dividend->zaehler * divisor->nenner;
    quotient->nenner = dividend->nenner * divisor->zaehler;
    quotient->vorzeichen = dividend->vorzeichen * divisor->vorzeichen;

    ggT_teiler(quotient);

    return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------ggT------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------




int ggT_teiler(rational *rat_zahl){

    unsigned int teiler = 0;
    unsigned int a = rat_zahl->zaehler;
    unsigned int b = rat_zahl->nenner;
    unsigned int c = 0;

    do
    {
        c = a % b;
        a = b; b = c;
    } while (c != 0);

    teiler = a;

        rat_zahl->zaehler = rat_zahl->zaehler/teiler;
        rat_zahl->nenner = rat_zahl->nenner/teiler;
        rat_zahl->vorzeichen;
    return 0;
}


//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------Number drop------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------



int number_drop(unsigned int zahl_auswahl, rational *zahl)
{
  
    switch (zahl_auswahl)
    {
//-----------------------------------------------------------------10er------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------
    case 0:
        zahl = creat(-1,12,24);
        break;
    case 1:
       creat(1,12,24);
        break;
    case 2:
    creat(-1,15,12);
        break;
    case 3: 
    creat(1,15,12);
        break;
//-----------------------------------------------------------------100000000er-----------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------
    case 4:
    creat(-1,2495,8052);
        break;
    case 5:
    creat(1,2495,8052);
        break;
    case 6:
    creat(-1,9688,5038);
        break;
    case 7:
    creat(1,9688,5038);
        break;
    }

    return 0;
}


//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------ausgabe_rat----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------


void ausgabe_rat(const rational *zahl, char type, unsigned int zaehler)
{




    if(zahl->vorzeichen == 1){
        switch (type)
        {
        case '*':
            printf("\t-> \x1B[32m%10u/%-10u\x1B[0m<-", zahl->zaehler,zahl->nenner);
            break;
        case '/':
            printf("\t->\x1B[32m%10u/%-10u\x1B[0m<-", zahl->zaehler,zahl->nenner);
            break;
        case '+':
            printf("\t->\x1B[32m%10u/%-10u\x1B[0m<-", zahl->zaehler,zahl->nenner);
            break;
        case '-':
            printf("\t->\x1B[32m%10u/%-10u\x1B[0m<-", zahl->zaehler,zahl->nenner);
            break;
        case 'x':
           printf("\t->\033[35m\tError !=/0\t\033[0m<-");
            break;
        case 'p':
            printf("\nKalkulation  %X",zaehler);
            break;
        case 'z':
            printf("\n\n\t\t    \x1B[33mMultiplikation\t\t\t\x1B[34mDivision\t\t\t\x1B[35mAddition\t\t\t\x1B[36mSubtraktion\x1B[0m\n");
            break;
        case '0':
            printf("\t->\033[37m\t    0\t       \033[0m<-");
            break;
        default:
            break;
        }
    }
    else if(zahl->vorzeichen == -1){

        switch (type)
            {
            case '*':
                printf("\t->\x1B[31m%10d/%-10d\x1B[0m<-", zahl->zaehler,zahl->nenner);
                break;
            case '/':
                printf("\t->\x1B[31m%10d/%-10d\x1B[0m<-", zahl->zaehler,zahl->nenner);
                break;
            case '+':
                printf("\t->\x1B[31m%10d/%-10d\x1B[0m<-", zahl->zaehler,zahl->nenner);
                break;
            case '-':
                printf("\t->\x1B[31m%10d/%-10d\x1B[0m<-", zahl->zaehler,zahl->nenner);
                break;
            case '0':
                printf("\t->\033[37m\t    0\t       \033[0m<-");
                break;
            default:
                break;
            }
    }
    else
    printf("\t->\033[37m\t    0\t       \033[0m<-");
    
return;
}