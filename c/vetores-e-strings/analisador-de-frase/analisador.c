#include <stdio.h>
#include <ctype.h>

int main() {
    char frase[1000];
    int i = 0;
    int vogais = 0, consoantes = 0, espacos = 0, digitos = 0, especiais = 0;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin); // Lê a frase com espaços

    while (frase[i] != '\0') {
        char c = frase[i];

        if (isalpha(c)) { // é letra?
            char minuscula = tolower(c);
            if (minuscula == 'a' || minuscula == 'e' || minuscula == 'i' ||
                minuscula == 'o' || minuscula == 'u') {
                vogais++;
            } else {
                consoantes++;
            }
        } else if (isdigit(c)) {
            digitos++;
        } else if (c == ' ') {
            espacos++;
        } else if (c != '\n') { // Vogais acentuadas contam como especiais
            especiais++;
        }

        i++;
    }

    printf("\nAnálise da frase:\n");
    printf("Vogais: %d\n", vogais);
    printf("Consoantes: %d\n", consoantes);
    printf("Dígitos: %d\n", digitos);
    printf("Espaços: %d\n", espacos);
    printf("Caracteres especiais: %d\n", especiais);

    return 0;
}
