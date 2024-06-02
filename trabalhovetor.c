/**
 **MENU QUE POSSIBILITA ADCIONAR E REMOVER ITENS E NO FINAL MOSTRAR O RESULTADO.
**ALUNOS :
* BRENO LIMA OLIVEIRA DE ANDRADE || 01460017 ||
*
*
*
*
*
*
**/
#include <stdio.h>

int main()
{
    char ch; int editar, qntd, contador = 0;
    // VARIAVEIS de "ch" PARA O MENU, "editar" PARA A EDICAO, "qntd" PARA O TAMANHO DA LISTA e "contador" PARA O LOOPING WHILE DA LISTA
    printf("DEFINA O TAMANHO DA LISTA.\n >>:  ");
    scanf("%d", &qntd); // ESCOLHA DO TAMANHO DA LISTA
    char LISTA[qntd][99];
    printf("Adcione [%d] itens.\n", qntd);
        while(qntd > contador) // LOOPING WHILE QUE FAZ COM QUE OS ITENS SEJAM ADCIONADOS NA QUANTIDADE DECLARADA, UTILIZANDO O CONTADOR PARA CONTROLAR E TAMBEM PARA ADCIONAR NA POSICAO DO VETOR.
        {
            printf(">> ");
            scanf(" %s", &LISTA[contador]);
            contador++;
        }
    while(1) // CRIAÇAO DE UM LOOPING INFINITO while true, em C "1" ou qualquer valor inteiro é considerado true, então o while é sempre ativado pois a condição esta verdadeira o tempo inteiro
    {
        // MENU PRINCIPAL.
        printf
            (
                "====================\n"
                "[1] IMPRIMIR\n"
                "[2] EDITAR\n"
                "[3] LIMPAR\n"
                "[4] ALTERAR O TAMANHO\n"
                "[5] SAIR\n"
                "====================\n"
            );
        
        
        scanf(" %c", &ch);
        
        if (ch == '2') // NESSE IF É ONDE PODE SER FEITA A EDIÇÃO DE ALGUMA POSIÇÃO DO VETOR SELECIONADO, SE FOR INVALIDO VOLTA AO MENU INICIAL.
        {
            printf("EDICAO, selecione a posicao que deseja editar entre [0 - %d]\n>>: ", qntd - 1);
            scanf("%d", &editar);
            if (editar >= 0 && editar < qntd) // FORÇA QUE O USUARIO ESCOLHA ENTRE OS NUMEROS DE POSICAO POSSIVEIS, CASO ESCOLHA POSICAO ERRADA VOLTA AO MENU INICIAL.
            {
                printf("%d POSICAO SELECIONADA, ESCREVA O ITEM PARA SUBSTITUIR.\n>>: ", editar);
                scanf("%s", LISTA[editar]);
            } 
            else {
                printf("POSICAO ERRADA.\n");
            }
            
        }
        else if (ch == '1') // ESSE IF IMPRIME A LISTA COMO ESTÁ NO MOMENTO.
        {
            printf("====================\n");
            printf("RESULTADO DOS %d ITENS\n", qntd);
            printf("====================\n");
            for (int i = 0; i < qntd; i++) // UTILIZACAO DO FOR POIS COMO NÃO SABEMOS O TAMANHO DA LISTA DO USUARIO UTILIZAMOS A QUANTIDADE PRÉ DEFINIDA ANTERIOMENTE.
            {
                printf("%d.\t%s\n",i , LISTA[i]);
            }    
            continue;;
        }
        else if (ch == '3') // ESSE IF DELETA TODA LISTA EXISTENTE E EM SEGUIDA POSSIBILITA A CRIAÇÃO DE UMA NOVA COM A MESMA QUANTIDADE PRÉ DEFINIDA.
        {
            printf("====================\n");
            printf("DELETADO COM SUCESSO!.\n");
            contador = 0;
            printf("Adcione [%d] itens.\n", qntd);
            while(qntd > contador)
            {
                printf(">> ");
                scanf(" %s", &LISTA[contador]);
                contador++;
            }
            continue;
        }
        
        else if (ch == '4') // ESSE IF POSSIBILITA ALTERAR O TAMANHO DA LISTA QUE FOI DECLARADO NO INICIO DO CODIGO
        {
            printf("====================\n");
            printf("O TAMANHO DA LISTA ATUAL = %d, DEFINA O NOVO TAMANHO:\n >>:", qntd);
            scanf("%d", &qntd);
            printf("TAMANHO ATUALIZADO, AGORA = %d ITENS.\n", qntd);
            continue;
        }
        else if (ch == '5') // ESSE IF FAZ O PROGRAMA SER FINALIZADO COM A QUEBRA DO LOOPING WHILE.
        {
            printf("FINALIZADO.");
            break;
        }
        else // ESSE ELSE É PARA IMPEDIR QUE O USUARIO DIGITE QUALQUER OUTRA COISA ALÉM DE 1, 2, 3 e 4. IMPRIMINDO UM "ERRO" E VOLTANDO AO MENU.
        {
            printf("COMANDO INVALIDO.\n");
            continue;
        }
    }
    return 0;
}
