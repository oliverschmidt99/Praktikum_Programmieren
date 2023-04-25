#ifndef JSON_H
#define JSON_H

#include <stdint.h>
#include "rational.h"

typedef struct {
    int v;    // Vorzeichen: 1 für positive Zahlen, -1 für negative Zahlen
    unsigned int z;    // Zähler
    unsigned int n;    // Nenner
} rational_t;

int to_json(const rational_t *r, uint8_t *json, size_t json_size);
int from_json(const uint8_t *json, size_t json_size, rational_t *r);

#endif