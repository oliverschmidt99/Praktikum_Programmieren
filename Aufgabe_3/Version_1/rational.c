
//#define number_drop(unsigned int)
#include "rational.h"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
#define RED   "\x1B[31m"
#define GREEN "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

static struct rational number_drop(unsigned int zahl_was);
static struct rational ggT_teiler(struct rational rat_zahl);
static unsigned int ggT(struct rational r1);


static struct rational number_drop(unsigned int zahl_was)
{
    struct rational zahl_00;
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
//-----------------------------------------------------------------10er------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------

    case 0:
        zahl_01.zaehler      = 12;
        zahl_01.nenner       = 24;
        zahl_01.vorzeichen   = -1;
        return zahl_01;
        break;
    case 1:           //nenner > zähler und vorzeichen -  / zahlen 10er
        zahl_01.zaehler      = 12;
        zahl_01.nenner       = 24;
        zahl_01.vorzeichen   = 1;
        return zahl_01;
        break;
    case 2:           // nenner > zähler und vorzeichen + / zahlen 10er
        zahl_02.zaehler      = 15;
        zahl_02.nenner       = 12;
        zahl_02.vorzeichen   = -1;
        return zahl_02;
        break;
    case 3:           //nenner < zähler und vorzeichen -  / zahlen 10er
        zahl_03.zaehler      = 15;
        zahl_03.nenner       = 12;
        zahl_03.vorzeichen   = 1;
        return zahl_03;
        
//-----------------------------------------------------------------100000000er-----------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------

  
    case 4:           //zähler < nanner und vorzeichen -  / zahlen 1000er
        zahl_04.zaehler      = 2495;
        zahl_04.nenner       = 8052;
        zahl_04.vorzeichen   = -1;
        return zahl_04;
    case 5:          //zähler < nanner und vorzeichen +  / zahlen 1000er
        zahl_05.zaehler      = 2495;
        zahl_05.nenner       = 8052;
        zahl_05.vorzeichen   = 1;
        return zahl_05;
    case 6:           //zähler > nanner und vorzeichen -  / zahlen 1000er
        zahl_06.zaehler      = 9688;
        zahl_06.nenner       = 5038;
        zahl_06.vorzeichen   = -1;
        return zahl_06;
    case 7:           //zähler > nanner und vorzeichen +  / zahlen 1000er
        zahl_07.zaehler      = 9688;
        zahl_07.nenner       = 5038;
        zahl_07.vorzeichen   = 1;
        return zahl_07;

//-----------------------------------------------------------------Sonderfälle-----------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------

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
        zahl_11.nenner       = 1;
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

    summe = ggT_teiler(summe);

    }
    return summe;
}




//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------subtrahtion_rat------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------


struct rational subtrahtion_rat(struct rational minuend, struct rational subtrahend)
{
    struct rational differenz;
    double zahl_1 = 0, zahl_2 = 0;


    zahl_1 = (double)minuend.zaehler/(double)minuend.nenner;
    zahl_2 = (double)subtrahend.zaehler/(double)subtrahend.nenner;



    differenz.nenner = minuend.nenner*subtrahend.nenner;            //Der nenner wird multipliziert.
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


        differenz = ggT_teiler(differenz);

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

    produkt = ggT_teiler(produkt);

    return produkt;
}





//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------divison_rat----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------




struct rational divison_rat(struct rational dividend, struct rational divisor){

    struct rational quotient;


    quotient.zaehler = dividend.zaehler * divisor.nenner;
    quotient.nenner = dividend.nenner * divisor.zaehler;
    quotient.vorzeichen = dividend.vorzeichen * divisor.vorzeichen;

    quotient = ggT_teiler(quotient);

    return quotient;
}

//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------ggT------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------


static unsigned int ggT(struct rational r1)
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


static struct rational ggT_teiler(struct rational rat_zahl){    

unsigned int teiler = 0;

    teiler = ggT(rat_zahl);
    rat_zahl.zaehler = rat_zahl.zaehler/teiler;
    rat_zahl.nenner = rat_zahl.nenner/teiler;

    return rat_zahl;
}



//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------ausgabe_rat----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------


void ausgabe_rat(struct rational zahl, char type, unsigned int zaehler)
{

    double ieee;

    ieee = (double)zahl.zaehler / (double)zahl.nenner;



    if(zahl.vorzeichen == 1){
        switch (type)
        {
        case '*':
            printf("\t-> \x1B[32m%10u/%-10u\x1B[0m<-", zahl.zaehler,zahl.nenner);
            break;
        case '/':
            printf("\t->\x1B[32m%10u/%-10u\x1B[0m<-", zahl.zaehler,zahl.nenner);
            break;
        case '+':
            printf("\t->\x1B[32m%10u/%-10u\x1B[0m<-", zahl.zaehler,zahl.nenner);
            break;
        case '-':
            printf("\t->\x1B[32m%10u/%-10u\x1B[0m<-", zahl.zaehler,zahl.nenner);
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
    else if(zahl.vorzeichen == -1){

        switch (type)
            {
            case '*':
                printf("\t->\x1B[31m%10d/%-10d\x1B[0m<-", zahl.zaehler,zahl.nenner);
                break;
            case '/':
                printf("\t->\x1B[31m%10d/%-10d\x1B[0m<-", zahl.zaehler,zahl.nenner);
                break;
            case '+':
                printf("\t->\x1B[31m%10d/%-10d\x1B[0m<-", zahl.zaehler,zahl.nenner);
                break;
            case '-':
                printf("\t->\x1B[31m%10d/%-10d\x1B[0m<-", zahl.zaehler,zahl.nenner);
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