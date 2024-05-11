#include <stdio.h>

#define lista_max 3

int main() {
    char produto[lista_max][100] = {""};
    float valor[lista_max] = {};
    int contador = 0;

    while (contador < lista_max) {
        printf("PRODUTO: ");
        scanf("%99s", produto[contador]);
        printf("VALOR: ");
        scanf("%f", &valor[contador]);
        contador++;
    }

    printf("PRODUTO\t\tVALOR\n");
    for (int x = 0; x < contador; x++) {
        printf("%s\t\tR$ %.2f\n", produto[x], valor[x]);
    }

    return 0;
}
