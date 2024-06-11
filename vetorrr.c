#include <stdio.h>

int main (){
    char escolha;
    int quantidade, editar, contador = 0;
    printf("DEFINIR O TAMANHO DA LISTA. \n >>");
    scanf("%d", &quantidade);
    char LISTA[quantidade][99];

    while (quantidade > contador) 
    {
        printf(">>: ");
        scanf(" %s", &LISTA[contador]);
        contador++;
    }
    
    while (1)
    {
        printf("MENU\n");
        printf("[1] - IMPRIMIR\n ");
        printf("[2] - EDITAR\n ");
        printf("[3] - LIMPAR\n");
        printf("[4] - ALTERAR O TAMANHO DA LISTA\n");
        printf("[5] - SAIR\n >>: ");
        
        scanf(" %c", &escolha);

        if (escolha == '1')
        {
            for (int i = 0; quantidade > i; i++)
            {
                printf(" %s\n", LISTA[i]);
            }
            continue;
        }
        else if (escolha == '2')
        {
            printf("ESCOLHA POSICAO [0] - [%d]\n >>:", quantidade - 1);
            scanf("%d", &editar);
            if (editar >= 0 && editar < quantidade)
            {
                printf("ok, escreva o item a ser substituido\n >>: ");
                scanf(" %s", &LISTA[editar]);
            }
            else
            {
                printf("POSIÇÃO ERRADA.\n");
            }
            continue;
        }
        else if (escolha == '3')
        {
            printf("DELETADO.\n");
            contador = 0;
            printf("adcione os itens\n");
            while (quantidade > contador) 
            {
                printf(">>: ");
                scanf(" %s", &LISTA[contador]);
                contador++;
            }
            continue;
        }
        else if (escolha == '4')
        {
            printf("O TAMANHO ATUAL É DE: %d DEFINA NOVO TAMANHO:\n >>:", quantidade);
            scanf("%d", &quantidade);
            printf("tamanho atualizado para %d", quantidade);
            continue;
        }
        else if (escolha == '5')
        {
            printf("finalizado!\n");
            break;
        }
        else
        {
            printf("ERRO, TENTE NOVAMENTE!\n");
            continue;
        }
    
    }
    





    return 0;
}