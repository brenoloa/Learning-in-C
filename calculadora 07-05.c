#include <stdio.h>

int main(){
    float n1, n2, x;
    char y;
    puts("DIGITE A OPERAÇÃO EXEMPLO: 34+34, 20*2, 23/2, 233-33");
    printf("______: ");
    scanf(" %f %c %f", &n1, &y, &n2);
    switch (y)
    {
    case '+':
        x = n1 + n2;
        printf("%.1f + %.1f = %.1f", n1, n2, x);
        break;
    case '-':
        x = n1 - n2;
        printf("%.1f - %.1f = %.1f", n1, n2, x);
        break;
    case '/':
        x = n1 / n2;
        printf("%.1f / %.1f = %.1f", n1, n2, x);
        break;
    case '*':
        x = n1 * n2;
        printf("%.1f * %.1f = %.1f", n1, n2, x);
        break;
    default:
        break;
    }
}







