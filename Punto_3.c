#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const int numNombres = 5;
    char** nombres = (char**)malloc(numNombres * sizeof(char*));

    for (int i = 0; i < numNombres; i++) {
        char buffer[100];
        printf("Ingrese el nombre %d: ", i+1);
        gets(buffer);

        nombres[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(nombres[i], buffer);
    }

    printf("Los nombres ingresados son:\n");
    for (int i = 0; i < numNombres; i++) {
        printf("%s\n", nombres[i]);
    }

    for (int i = 0; i < numNombres; i++) {
        free(nombres[i]);
    }
    free(nombres);

    return 0;
}