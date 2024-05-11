#include <stdio.h>
//#include <windows.h>  // para utilizar a função Sleep() no windows em mac ou linux é necessario alterar.

#define NUM_USUARIOS 3 // Definindo o número de usuários

int main(void) {
    // Credenciais pré-definidas e saldos para cada usuário
    char usuarios[NUM_USUARIOS][100] = {"brenoloa", "usuario2","usuario3"};
    char senhas[NUM_USUARIOS][100] = {"admin", "senha456","admin"};
    float saldos[NUM_USUARIOS] = {150000.0, 1500.0, 2200.0};

    // Variáveis para armazenar entrada do usuário
    char usuario_digitado[100];
    char senha_digitada[100];

    // Solicitar que o usuário insira suas credenciais
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-= CAIXA ELETRONICO -=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-= DIGITE SEU USUARIO -=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("USER: ");
    scanf("%99s", usuario_digitado);

    // Solicitar que o usuário insira sua senha
    printf("SENHA: ");
    scanf("%99s", senha_digitada);

    // Verificar se as credenciais correspondem a algum usuário
    int usuario_encontrado = -1; // Índice do usuário encontrado, inicialmente definido como -1 (não encontrado)
    for (int i = 0; i < NUM_USUARIOS; i++) {
        if (strcmp(usuario_digitado, usuarios[i]) == 0 && strcmp(senha_digitada, senhas[i]) == 0) {
            usuario_encontrado = i; // Atualiza o índice do usuário encontrado
            break; // Sai do loop assim que o usuário é encontrado
        }
    }

    // Se o usuário for encontrado
    if (usuario_encontrado != -1) {
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("-=-=-=-=-= AUTENTICACAO BEM-SUCEDIDA! -=-=-=-=-=\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        // Operações do caixa eletrônico para o usuário encontrado
        float saldo_atual = saldos[usuario_encontrado];
        // Restante do código do caixa eletrônico...

        // Operações do caixa eletrônico
        float saque, deposito, emprestimo, parcela, pix;
        int funcao, meses;
        char chave_pix[100];
        float juros = 1.13; // 13%%  

        // Loop principal do caixa eletrônico
        while (1) {
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("OLA, %s SALDO ATUAL: R$%.2f\n", usuario_digitado, saldo_atual);
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("-=-=-=-= SELECIONE A FUNCAO -=-=-=-=-=\n");
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("[1] SAQUE ==========\n");
            printf("[2] DEPOSITO =======\n");
            printf("[3] EMPRESTIMO =====\n");
            printf("[4] PIX= ===========\n");
            printf("[5] SAIR ===========\n");
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            scanf("%d", &funcao);

            if (funcao >= 1 && funcao <= 5) {
                if (funcao == 1) {
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                    printf("DIGITE O QUANTO QUER SACAR\n");
                    printf("R$: ");
                    scanf("%f", &saque);
                    saldo_atual -= saque;
                    printf("-=-=-=-=-= P R O C E S S A N D O . . . =-=-=-=-=\n");
                    printf("SAQUE REALIZADO COM SUCESSO, SALDO ATUAL: R$%.2f\n", saldo_atual);
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                } else if (funcao == 2) {
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                    printf("DIGITE O QUANTO QUER DEPOSITAR\n");
                    printf("R$: ");
                    scanf("%f", &deposito);
                    printf("-=-=-=-=-= P R O C E S S A N D O . . . =-=-=-=-=\n");
                    saldo_atual += deposito;
                    printf("DEPOSITO REALIZADO COM SUCESSO, SALDO ATUAL: R$%.2f\n", saldo_atual);
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                } else if (funcao == 3) {
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                    printf("DIGITE O QUANTO QUER EMPRESTADO\n");
                    printf("R$: ");
                    scanf("%f", &emprestimo);
                    printf("DESEJA PAGAR EM QUANTOS MESES? >");
                    scanf("%d", &meses);
                    saldo_atual += emprestimo;
                    emprestimo *= juros;
                    parcela = emprestimo / meses;
                    printf("-=-=-=-=-= P R O C E S S A N D O . . . =-=-=-=-=\n");
                    printf("EMPRESTIMO REALIZADO!! %d PARCELAS de R$ %.2f TOTALIZANDO: R$ %.2f\n", meses, parcela, emprestimo);
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                } else if (funcao == 4) {
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                    printf("DIGITE A CHAVE PIX E O VALOR A SER ENVIADO\n");
                    printf("CHAVE: ");
                    scanf("%99s", chave_pix);
                    printf("DIGITE O VALOR R$: ");
                    scanf("%f", &pix);
                    saldo_atual -= pix;
                    printf("-=-=-=-=-= P R O C E S S A N D O . . . =-=-=-=-=\n");
                    printf("PIX EFETUADO ||  R$%.2f enviado para %s ", pix, chave_pix);
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                } else if (funcao == 5) {
                    printf("FINALIZADO.\n");
                    break;
                }
            } else {
                printf("FUNCAO INVALIDA!\n");
                break;
            }
        }
    } else {
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n-=-=-=-=-= CREDENCIAIS INCORRETAS. ACESSO NEGADO.\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }

    return 0;
}
