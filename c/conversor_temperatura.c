#include <stdio.h>

void deCelsius(float temp) {
    printf("Em Fahrenheit: %.2f\n", (temp * 9.0/5.0) + 32);
    printf("Em Kelvin: %.2f\n", temp + 273.15);
}

void deFahrenheit(float temp) {
    printf("Em Celsius: %.2f\n", (temp - 32) * 5.0/9.0);
    printf("Em Kelvin: %.2f\n", ((temp - 32) * 5.0/9.0) + 273.15);
}

void deKelvin(float temp) {
    printf("Em Celsius: %.2f\n", temp - 273.15);
    printf("Em Fahrenheit: %.2f\n", (temp - 273.15) * 9.0/5.0 + 32);
}

int main() {
    float temperatura;
    int escolha;

    printf("Selecione a unidade da temperatura:\n");
    printf("[1] Celsius\n[2] Fahrenheit\n[3] Kelvin\n\n");
    printf("Escolha: ");
    
    if (scanf("%d", &escolha) != 1) {
        printf("Entrada inválida!\n");
        return 1;
    }

    printf("Digite a temperatura: ");
    if (scanf("%f", &temperatura) != 1) {
        printf("Entrada inválida!\n");
        return 1;
    }

    printf("\n");

    switch (escolha) {
        case 1:
            deCelsius(temperatura);
            break;
        case 2:
            deFahrenheit(temperatura);
            break;
        case 3:
            deKelvin(temperatura);
            break;
        default:
            printf("Escolha inválida!\n");
    }

    return 0;
}
