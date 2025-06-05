#include <stdio.h>

int main() {
    float a, b;
    char op;

    printf("\nEntre com os números racionais e a operação desejada:\n(Por exemplo: 2.5 + 8.2)\n\n");
    scanf("%f %c %f", &a, &op, &b);

    if (op == '+') printf("Soma: %f", a + b);
    else if (op == '-') printf("Subtração: %f", a - b);
    else if (op == '*' || op == '.') printf("Multiplicação: %f", a * b);
    else if (op == '/' || op == ':') {
        if (b == 0) printf("ERRO! Divisão por Zero.");
        else printf("Divisão: %f", a / b);
    }
    printf("\n");

    return 0;
}