#include <stdio.h>
#include <math.h>

int main() {
    int num, divisores = 2;

    printf("Entre com um número: "); scanf("%d", &num);

    if (num == 1){
        printf("Não é primo!");
        return 0;
    }

    for (int i = 2; i < sqrt(num); i++) if (num % i == 0) divisores++;

    if (divisores == 2) printf("É primo!");
    else printf("Não é primo!");

    return 0;
}