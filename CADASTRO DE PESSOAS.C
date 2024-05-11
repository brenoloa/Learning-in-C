#include <stdio.h>
int main(){
    int QUANTIDADE_PESSOAS;
        printf("Quantas pessoas deseja cadastrar?: ");
            scanf("%d", &QUANTIDADE_PESSOAS);
                int cont = 0;
                    char NOMES[QUANTIDADE_PESSOAS][100];
                        char CODIGO[QUANTIDADE_PESSOAS][100];
    
    while (cont < QUANTIDADE_PESSOAS){
        printf("Nome Completo: ");
            scanf("%s", NOMES[cont]);
                printf("Codigo: ");
                    scanf("%s", CODIGO[cont]);
                        cont ++;
    }
    for (char i = 0; i < cont; i++){
        printf("%s\t %s\n", NOMES[i], CODIGO[i]);
    }
            return 0;
    }