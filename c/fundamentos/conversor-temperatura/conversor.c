#include <stdio.h>

int main() {
    float temperatura;
    int escolha;

    printf("Selecione qual unidade de temperatura está registrando: \n");
    printf("\n[1] Celsius\n");
    printf("[2] Fahrenheit\n");
    printf("[3] Kelvin\n\n");

    scanf("%d", &escolha);

    if (escolha == 1) { // Celsius
        printf("Entre com a temperatura: ");
        scanf("%f", &temperatura);
        printf("\n");
        printf("Em Fahrenheit: %.2f\n", (temperatura * 9.0/5.0) + 32);
        printf("Em Kelvin: %.2f\n", temperatura + 273.15);
    } else if (escolha == 2) { // Fahrenheit
        printf("Entre com a temperatura: ");
        scanf("%f", &temperatura);
        printf("\n");
        printf("Em Celsius: %.2f\n", (temperatura - 32) * 5.0 / 9.0);
        printf("Em Kelvin: %.2f\n", ((temperatura - 32) * 5.0 / 9.0) + 273.15);
    } else if (escolha == 3) { // Kelvin
        printf("Entre com a temperatura: ");
        scanf("%f", &temperatura);
        printf("\n");
        printf("Em Celsius: %.2f\n", temperatura - 273.15);
        printf("Em Fahrenheit: %.2f\n", (temperatura - 273.15) * 9.0 / 5.0 + 32);
    } else {
        printf("Escolha inválida!\n");
    }

    return 0;
}
