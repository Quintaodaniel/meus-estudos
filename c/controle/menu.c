#include <stdio.h>

int main() {
    int escolha;

    printf("Esse é um menu interativo, escolha qual opção deseja:\n\n");
    printf("[1] Opção 1\n");
    printf("[2] Opção 2\n");
    printf("[3] Opção 3\n");

    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            printf("Você escolheu a opção 1.");
            break;
    
        case 2:
            printf("Você escolheu a opção 2.");
            break;

        case 3:
            printf("Você escolheu a opção 3.");
            break;
    
        default:
            printf("Escolha inválida!");
            break;
    }

    return 0;
}