#include <stdio.h>

int main() {
    int n;
    int a = 0, b = 1, proximo;

    printf("Digite um número limite para a sequência de Fibonacci: ");
    scanf("%d", &n);

    printf("Sequência de Fibonacci até %d:\n", n);

    while (a <= n) {
        printf("%d ", a);
        proximo = a + b;
        a = b;
        b = proximo;
    }

    printf("\n");
    return 0;
}
