#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int segredo, tentativa, tentativas = 0;

    srand(time(NULL));  // semente aleatória

    segredo = (rand() % 100) + 1;  // número entre 1 e 100

    printf("=== Jogo: Adivinhe o número de 1 a 100 ===\n");

    do {
        printf("Digite sua tentativa: ");
        scanf("%d", &tentativa);
        tentativas++;

        if (tentativa < segredo) {
            printf("Muito baixo!\n");
        } else if (tentativa > segredo) {
            printf("Muito alto!\n");
        } else {
            printf("Parabéns! Você acertou em %d tentativas.\n", tentativas);
        }
    } while (tentativa != segredo);

    return 0;
}
