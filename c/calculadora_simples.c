#include <stdio.h>

int main() {
    float a, b;
    char op;

    printf("\nEntre com os números racionais e a operação desejada:\n(Por exemplo: 2.5 + 8.2)\n\n");
    scanf("%f %c %f", &a, &op, &b);

    switch (op) {
        case '+':
            printf("Soma: %f\n", a + b);
            break;
        case '-':
            printf("Subtração: %f\n", a - b);
            break;
        case '*':
        case '.':
            printf("Multiplicação: %f\n", a * b);
            break;
        case '/':
        case ':':
            if (b == 0)
                printf("ERRO! Divisão por Zero.\n");
            else
                printf("Divisão: %f\n", a / b);
            break;
        default:
            printf("Operação inválida!\n");
    }

    return 0;
}
