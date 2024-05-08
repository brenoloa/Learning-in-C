/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
-=-= CAIXA ELETRONICO 1.0 -=-==
@saque
@deposito
@emprestimo com juros
@dev: breno.loandrade@aluno.educacao.pe.gov.br
@github.com/
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/
#include <stdio.h>
//#include <windows.h>  // para utilizar a função Sleep() no windows em mac ou linux é necessario alterar.

int main(void){

float saldo_atual = 1200;
float saque, deposito, emprestimo, parcela, pix;
int funcao, meses;
char chave_pix[100];
char nome[100];
float juros = 1.13; // 13%%  
// variaveis
puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
puts("-=-=-=-=-= CAIXA ELETRONICO -=-=-=-=-=");
puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
puts("-=-=-=-= DIGITE SEU USUARIO -=-=-=-=-=");
puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
printf("USER: ");
if (scanf("%99s", nome) != 1) {
    printf("Erro ao ler o nome.\n");
    return 1;
}
puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
puts("-=-=-=-=-= P R O C E S S A N D O . . . =-=-=-=-=");
puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
while(1){
    //Sleep(2000);
    puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("OLA, %s SALDO ATUAL: R$%.2f\n", nome, saldo_atual);
    //Sleep(2000);
    puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    puts("-=-=-=-= SELECIONE A FUNCAO -=-=-=-=-=");
    puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    puts("[1] SAQUE ==========");
    puts("[2] DEPOSITO =======");
    puts("[3] EMPRESTIMO =====");
    puts("[4] PIX= ===========");
    puts("[5] SAIR ===========");
    puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    scanf("%d", &funcao);
    if (funcao >= 1 && funcao <= 5) {
            if (funcao == 1){
                    puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
                    puts("DIGITE O QUANTO QUER SACAR");
                    printf("R$: ");
                    scanf("%f", &saque);
                    saldo_atual = saldo_atual - saque;
                    puts("-=-=-=-=-= P R O C E S S A N D O . . . =-=-=-=-=");
                    //Sleep(2000);
                    printf("SAQUE REALIZADO COM SUCESSO, SALDO ATUAL: R$%.2f\n", saldo_atual);
                    puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
                    continue;
                }
            //SAQUE
            else if (funcao == 2){
                    puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
                    puts("DIGITE O QUANTO QUER DEPOSITAR");
                    printf("R$: ");
                    scanf("%f", &deposito);
                    puts("-=-=-=-=-= P R O C E S S A N D O . . . =-=-=-=-=");
                    //Sleep(2000);
                    saldo_atual = saldo_atual + deposito;
                    printf("DEPOSITO REALIZADO COM SUCESSO, SALDO ATUAL: R$%.2f\n", saldo_atual);
                    puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
                    continue; 
            }
            //DEPOSITAR
            else if (funcao == 3) {
                puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
                puts("DIGITE O QUANTO QUER EMPRESTADO");
                printf("R$: ");
                scanf("%f", &emprestimo);
                printf("DESEJA PAGAR EM QUANTOS MESES? >");
                scanf("%d", &meses);
                saldo_atual = saldo_atual + emprestimo;
                emprestimo = emprestimo * juros;
                parcela = emprestimo / meses;
                puts("-=-=-=-=-= P R O C E S S A N D O . . . =-=-=-=-=");
                //Sleep(2000);
                printf("EMPRESTIMO REALIZADO!! %d PARCELAS de R$ %.2f TOTALIZANDO: R$ %.2f\n", meses, parcela, emprestimo);
                continue;
            }
            //EMPRESTIMO
            else if (funcao == 4){
            puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            puts("DIGITE A CHAVE PIX E O VALOR A SER ENVIADO");
            printf("CHAVE: ");
            scanf("%99s", chave_pix);
            printf("DIGITE O VALOR R$: ");
            scanf("%f", &pix);
            saldo_atual = saldo_atual - pix;
            puts("-=-=-=-=-= P R O C E S S A N D O . . . =-=-=-=-=");
            //Sleep(2000);
            printf("PIX EFETUADO ||  R$%.2f enviado para %s ", pix, chave_pix);
            puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            continue;
                }
            
            

            else if (funcao == 5){
                puts("FINALIZADO.");
                break;
            }
            //FIM
            }


    else{
    puts("FUNCAO INVALIDA . !!");
    break;
}
}
//Sleep(2000);
return 0;
}



