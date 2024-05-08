#include <stdio.h>

int main (void){
    char c; int x;
    puts("=== BEM VINDO A LOCADORA DE FILMES ===");
    puts("=== SELECIONE O GENERO ===");
    puts("[1] COMEDIA");
    puts("[2] ACAO");
    puts("[3] ROMANCE");
    scanf("%c", &c);

    switch (c){
    
        case '1':
            puts("=== CATEGORIA: COMEDIA ===");
            puts("=== [1] GENTE GRANDE ===");
            puts("=== [2] TA DANDO ONDA ===");
            puts("Selecione o Filme: ");
            scanf("%d", &x);
            if(x == 1){
                puts("Filme: GENTE GRANDE. adcionado ao carrinho!...");
            }
            else if(x == 2){
                puts("Filme: TA DANDO ONDA. adcionado ao carrinho!...");
            }
            break;
        case '2':
            puts("=== CATEGORIA: ACAO ===");
            puts("=== [1] CIDADE DE DEUS ===");
            puts("=== [2] TROPA DE ELITE ===");
            puts("Selecione o Filme: ");
            scanf("%d", &x);
            if(x == 1){
                puts("Filme: CIDADE DE DEUS. adcionado ao carrinho!...");
            }
            else if(x == 2){
                puts("Filme: TROPA DE ELITE. adcionado ao carrinho!...");
            }
            break;
        case '3':
            puts("=== CATEGORIA: ROMANCE ===");
            puts("=== [1] CREPUSCULO ===");
            puts("=== [2] LINDA MULHER ===");
            puts("Selecione o Filme: ");
            scanf("%d", &x);
            if(x == 1){
                puts("Filme: CREPUSCULO. adcionado ao carrinho!...");
            }
            else if(x == 2){
                puts("Filme: LINDA MULHER. adcionado ao carrinho!...");
            }
            break;
        
        
        default:
            break;
    }
    
























}