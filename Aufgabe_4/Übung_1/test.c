#include <stdio.h>
#include <json-c/json.h>

typedef struct {
    char *v;
    unsigned int *n;
    unsigned int *z;
} rational_t;

int main(int argc, char **argv){
    printf("\n\n");

    FILE *fp;
    char buffer[1024];
    struct json_object *parsed_json;
    struct json_object *v;
    struct json_object *n;
    struct json_object *z;


/*Dann wird die Funktion fopen() verwendet, um die Datei "test.json" im Lesemodus ("r") zu 
öffnen. Die fopen()-Funktion öffnet eine Datei und gibt einen Zeiger auf den Dateistream zurück, 
der zum Lesen und Schreiben der Datei verwendet wird. Der Dateizeiger wird in diesem Fall in der
Variablen fp gespeichert.

Als nächstes wird die Funktion fread() verwendet, um Daten aus der geöffneten Datei zu lesen.
Die fread()-Funktion wird verwendet, um Daten aus einem Stream in einen Puffer zu lesen.

Schließlich wird die geöffnete Datei mit fclose() geschlossen. Die fclose()-Funktion wird verwendet,
um eine offene Datei zu schließen und den Dateizeiger freizugeben. In diesem Fall wird der Dateizeiger
verwendet, der in der Variable fp gespeichert ist.
*/
    fp = fopen("test.json", "r");
    fread(buffer, 1024, 1, fp);
    fclose(fp);

    printf("buffer: %s\n", buffer);

    parsed_json = json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json,"v", &v);
    json_object_object_get_ex(parsed_json,"z", &z);
    json_object_object_get_ex(parsed_json,"n", &n);

    printf("v = %s\n", json_object_get_string(v));
    printf("z = %u\n", json_object_get_int(z));
    printf("n = %u\n", json_object_get_int(n));

    json_object_put(parsed_json);

    printf("\n\n");
    return 0;
}