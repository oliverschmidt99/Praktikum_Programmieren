#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "rational.h"
#include "rational.c"
#include "json.c"

#define RD "\x1B[31m"
#define GN "\x1B[32m"
#define WH "\x1B[34m"
#define RS "\x1B[0m"

int main()
{

    rational *z1 = creat(0, 0, 0);
    rational *z2 = creat(0, 0, 0);
    rational *erg = creat(0, 0, 0);

    uint8_t buffer_to_json[10000];
    uint8_t buffer_z1_json[] = "{ \"za\": 42949 ,\"ne\": 96729, \"vz\": 1 }";
    uint8_t buffer_z2_json[] = "{ \"za\": 67295 ,\"ne\": 4967, \"vz\": -1 }";

    int error = 0;

    error = von_json((uint8_t *)buffer_z1_json, z1);
    if (error != 0)
    {
        printf(RD "1Es ist ein Eingabefehler aufgetreten. Bitte überprüfen Sie Ihre Angaben!\n\n" RS);
        return -1;
    }

    error = von_json((uint8_t *)buffer_z2_json, z2);
    if (error != 0)
    {
        printf(RD "2Es ist ein Eingabefehler aufgetreten. Bitte überprüfen Sie Ihre Angaben!\n\n" RS);
        return -1;
    }

    if (z1->ne != 0 && z2->ne != 0)
    {
        ggt_teiler(z1);
        ggt_teiler(z2);

        printf("Zahl 1\t\t = ->%i %10u/%-10u<-\n", z1->vz, z1->za, z1->ne);
        printf("Zahl 2\t\t = ->%i %10u/%-10u<-\n\n", z2->vz, z2->za, z2->ne);

        multiplikation_rat(z1, z2, erg);
        error = to_json(buffer_to_json, erg);
        if (error != 0)
        {
            printf(RD "3Es ist ein Eingabefehler aufgetreten. Bitte überprüfen Sie Ihre Angaben!\n\n" RS);
            return -1;
        }
        //printf("\nzu json\t %s\n", buffer_to_json);
        // printf("multiplikation\t = ->%i %10u/%-10u<-\n", erg->vz, erg->za, erg->ne);

        divison_rat(z1, z2, erg);
        error = to_json(buffer_to_json, erg);
        if (error != 0)
        {
            printf(RD "4Es ist ein Eingabefehler aufgetreten. Bitte überprüfen Sie Ihre Angaben!\n\n" RS);
            return -1;
        }
        // printf("\nzu json\t %s\n", buffer_to_json);
        // printf("division\t = ->%i %10u/%-10u<-\n", erg->vz, erg->za, erg->ne);

        addition_rat(z1, z2, erg);
        error = to_json(buffer_to_json, erg);
        if (error != 0)
        {
            printf(RD "5Es ist ein Eingabefehler aufgetreten. Bitte überprüfen Sie Ihre Angaben!\n\n" RS);
            return -1;
        }
        // printf("\nzu json\t %s\n", buffer_to_json);
        // printf("addition\t = ->%i %10u/%-10u<-\n", erg->vz, erg->za, erg->ne);

        subtrahtion_rat(z1, z2, erg);
        error = to_json(buffer_to_json, erg);
        if (error != 0)
        {
            printf(RD "6Es ist ein Eingabefehler aufgetreten. Bitte überprüfen Sie Ihre Angaben!\n\n" RS);
            return -1;
        }
        printf("\nzu json\t %s\n", buffer_to_json);
        //printf("subtrahtion\t = ->%i %10u/%-10u<-\n", erg->vz, erg->za, erg->ne);
    }
    else
    {
        printf("\nNenner darf nicht Null sein!\n");
    }

 

    destroy(z1);
    destroy(z2);
    destroy(erg);

    printf("\n\n\n\n");
    return 0;
}
