#include <stdio.h>
#include <windows.h>
int main(void){
    int rept = 0, mult = 1, som, num;
    printf("TABUADA, DIGITE UM NUMERO: ");
    scanf("%d", &num);
    while (rept < 10){
        som = num * mult;
        printf("%d x %d = %d\n", num, mult, som);
        rept++, mult++;
    }
 Sleep(10000);
 return 0;
}
