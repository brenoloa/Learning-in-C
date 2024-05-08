/**
 * == CONVERSOR DE TEMPO
 * == @ MINUTOS, SEGUNDOS E HORAS.
 * == @brenoloa
 * == github.com/brenoloa
 * == breno.loandrade@aluno.educacao.pe.gov.br 
 *  **/
#include <stdio.h>
#include <ctype.h>

int main(){
    char escolha;float tempo, resultado;int escolha2;
    puts("== SELECIONE O TIPO A SER DIGITADO ==");
    printf("[1] HORAS\n[2] MINUTOS\n[3] SEGUNDOS\n==> ");
    scanf(" %c", &escolha);
    switch (escolha)
    {
    case '1':
        printf("== Categoria: HORAS, selecionada.\nInsira o numero de HORAS: ");
        scanf(" %f", &tempo);
        printf("== SELECIONE O METODO DE CONVERSAO\n[1] MINUTOS\n[2] SEGUNDOS.");
        scanf(" %d", &escolha2);

        if (escolha2 == 1){
           resultado = tempo * 60;
           printf("%.0f Horas eh igual a -> %.0f Minutos :)! ", tempo, resultado);
        }
        else if (escolha2 == 2){
            resultado = (tempo * 60) * 60;
           printf("%.0f Horas eh igual a -> %.0f Segundos :)! ", tempo, resultado);

        }
        break;
    case '2':
        printf("== Categoria: MINUTOS, selecionada.\nInsira o numero de MINUTOS: ");
        scanf(" %f", &tempo);
        printf("== SELECIONE O METODO DE CONVERSAO\n[1] HORAS\n[2] SEGUNDOS.");
        scanf(" %d", &escolha2);

        if (escolha2 == 1){
           resultado = tempo / 60;
           printf("%.0f Minutos eh igual a -> %.0f Horas :)! ", tempo, resultado);
        }
        else if (escolha2 == 2){
            resultado = tempo * 60;
           printf("%.0f Minutos eh igual a -> %.0f Segundos :)! ", tempo, resultado);
        }
        break;
    case '3':
        printf("== Categoria: SEGUNDOS, selecionada.\nInsira o numero de SEGUNDOS: ");
        scanf(" %f", &tempo);
        printf("== SELECIONE O METODO DE CONVERSAO\n[1] MINUTOS\n[2] HORAS.");
        scanf(" %d", &escolha2);
        if (escolha2 == 1){
           resultado = tempo / 60;
           printf("%.0f Segundos eh igual a -> %.0f Minutos :)! ", tempo, resultado);
        }
        else if (escolha2 == 2){
            resultado = (tempo / 60) / 60;
           printf("%.0f Segundos eh igual a -> %.0f Horas :)! ", tempo, resultado);
        } 
        break;
    default:
        puts("ERRO! REINICIE O SISTEMA.");
        break;
    }
}