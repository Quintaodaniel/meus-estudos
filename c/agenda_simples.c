#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTATOS 100

typedef struct {
    char nome[50];
    char telefone[20];
} Pessoa;

int validarTelefone(const char* telefone) {
    int tamanho = strlen(telefone);

    if (tamanho != 10 && tamanho != 11) return 0;

    for (int i = 0; i < tamanho; i++) {
        if (!isdigit(telefone[i])) return 0;
    }

    return 1;
}

Pessoa novaPessoa(const char* nome, const char* telefone) {
    Pessoa fulano;
    strcpy(fulano.nome, nome);
    strcpy(fulano.telefone, telefone);
    return fulano;
}

void exibirPessoa(Pessoa fulano) {
    printf("\nNome: %s\nTelefone: %s\n", fulano.nome, fulano.telefone);
}

void exibirContatos(Pessoa* agenda, size_t tamanho) {
    puts("\nSua agenda de contatos:");
    for (size_t i = 0; i < tamanho; i++) {
        exibirPessoa(agenda[i]);
    }
}

void buscarContato(const char* nome, Pessoa* agenda, size_t tamanho) {
    int achou = 0;

    for (size_t i = 0; i < tamanho; i++) {
        if (strstr(agenda[i].nome, nome) != NULL) {
            exibirPessoa(agenda[i]);
            achou = 1;
        }
    }

    if (!achou) {
        printf("Não há nenhum contato que contenha \"%s\" no nome.\n", nome);
    }
}

void editarNome(char* nome, Pessoa* agenda, size_t tamanho) {
    for (size_t i = 0; i < tamanho; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            printf("Novo nome: ");
            fgets(agenda[i].nome, sizeof(agenda[i].nome), stdin);
            agenda[i].nome[strcspn(agenda[i].nome, "\n")] = '\0';
            printf("Nome atualizado!\n");
            return;
        }
    }
    printf("Contato não encontrado.\n");
}

void editarTelefone(char* nome, Pessoa* agenda, size_t tamanho) {
    char novoTelefone[20];
    for (size_t i = 0; i < tamanho; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            do {
                printf("Novo telefone (10 ou 11 dígitos): ");
                fgets(novoTelefone, sizeof(novoTelefone), stdin);
                novoTelefone[strcspn(novoTelefone, "\n")] = '\0';
                if (!validarTelefone(novoTelefone))
                    printf("Telefone inválido, tenta de novo.\n");
            } while (!validarTelefone(novoTelefone));

            strcpy(agenda[i].telefone, novoTelefone);
            printf("Telefone atualizado!\n");
            return;
        }
    }
    printf("Contato não encontrado.\n");
}

int main() {
    Pessoa agenda[MAX_CONTATOS];
    size_t tamanho = 0;

    int opcao;
    char nome[50], telefone[20];

    do {
        printf("\n==== AGENDA ====\n");
        printf("[1] Adicionar contato\n");
        printf("[2] Exibir contatos\n");
        printf("[3] Buscar contato por nome\n");
        printf("[4] Editar nome de um contato\n");
        printf("[5] Editar telefone de um contato\n");
        printf("[0] Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1:
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; // remove \n

                do {
                    printf("Telefone (apenas números, 10 ou 11 dígitos): ");
                    fgets(telefone, sizeof(telefone), stdin);
                    telefone[strcspn(telefone, "\n")] = '\0';
                    if (!validarTelefone(telefone)) {
                        printf("Telefone inválido! Tente de novo.\n");
                    }
                } while (!validarTelefone(telefone));

                if (tamanho < MAX_CONTATOS) {
                    agenda[tamanho++] = novaPessoa(nome, telefone);
                    printf("Contato adicionado!\n");
                } else {
                    printf("Agenda cheia!\n");
                }
                break;

            case 2:
                exibirContatos(agenda, tamanho);
                break;

            case 3:
                printf("Entre com o nome (ou parte): ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                buscarContato(nome, agenda, tamanho);
                break;
            
            case 4:
                    printf("Digite o nome do contato que deseja editar: ");
                    fgets(nome, sizeof(nome), stdin);
                    nome[strcspn(nome, "\n")] = '\0';
                    editarNome(nome, agenda, tamanho);
                break;

            case 5:
                printf("Digite o nome do contato que deseja editar: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                editarTelefone(nome,agenda, tamanho);
                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
