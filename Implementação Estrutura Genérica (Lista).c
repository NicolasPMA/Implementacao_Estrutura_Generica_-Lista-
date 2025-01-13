#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROFESSOR 0
#define ALUNO     1

typedef struct {
    float salario;
} Professor;

typedef struct {
    char curso[50];
    int anoIngresso;
} Aluno;

typedef struct {
    int tipo;         // PROFESSOR ou ALUNO
    int matricula;
    char nome[50];
    void *info;       // Aponta para (Professor*) ou (Aluno*)
} Pessoa;

// Nó da lista encadeada
typedef struct No {
    Pessoa pessoa;
    struct No *prox;
} No;

// Cria um novo nó a partir de uma Pessoa
No* criarNo(Pessoa p) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo != NULL) {
        novo->pessoa = p;
        novo->prox = NULL;
    }

    return novo;
}

// Libera a memória alocada para a "info" dentro de uma Pessoa
void liberarInfoPessoa(Pessoa *p) {
    if (p->info != NULL) {
        free(p->info);
        p->info = NULL;
    }
}

// 1. Inserir uma pessoa na lista
No* inserirPessoa(No* lista, Pessoa p) {
    No* novo = criarNo(p);
    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        return lista;
    }

    novo->prox = lista;
    return novo;
}

// 2. Remover uma pessoa pela matrícula
No* removerPessoa(No* lista, int matricula) {
    No *atual = lista, *anterior = NULL;

    while (atual != NULL && atual->pessoa.matricula != matricula) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Matricula nao encontrada.\n");
        return lista;
    }

    if (anterior == NULL) {
        lista = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    liberarInfoPessoa(&(atual->pessoa));
    free(atual);

    printf("Pessoa com matricula %d removida.\n", matricula);
    return lista;
}

// 3. Buscar uma pessoa pela matrícula (imprimir dados se encontrada)
void buscarPessoa(No* lista, int matricula) {
    No *atual = lista;

    while (atual != NULL) {
        if (atual->pessoa.matricula == matricula) {
            printf("\n--- Pessoa encontrada ---\n");
            printf("Tipo: %s\n", (atual->pessoa.tipo == PROFESSOR) ? "Professor" : "Aluno");
            printf("Matricula: %d\n", atual->pessoa.matricula);
            printf("Nome: %s\n", atual->pessoa.nome);

            // Imprime dados específicos
            if (atual->pessoa.tipo == PROFESSOR) {
                Professor *prof = (Professor *) atual->pessoa.info;
                printf("Salario: %.2f\n", prof->salario);
            }
            else {
                Aluno *al = (Aluno *) atual->pessoa.info;
                printf("Curso: %s\n", al->curso);
                printf("Ano de Ingresso: %d\n", al->anoIngresso);
            }

            return;
        }

        atual = atual->prox;
    }

    printf("Matricula nao encontrada.\n");
}


// 4. Contar o número de alunos de um determinado curso
int contarAlunosCurso(No* lista, const char *cursoBusca) {
    int contador = 0;
    No *atual = lista;

    while (atual != NULL) {
        if (atual->pessoa.tipo == ALUNO) {
            Aluno *a = (Aluno *) atual->pessoa.info;

            if (strcmp(a->curso, cursoBusca) == 0) {
                contador++;
            }
        }

        atual = atual->prox;
    }

    return contador;
}

// 5. Imprimir os professores de maior salário
void imprimirProfessoresMaiorSalario(No* lista) {
    float maiorSalario = -1.0f;
    No *atual = lista;

    // 1) Encontrar o maior salário
    while (atual != NULL) {
        if (atual->pessoa.tipo == PROFESSOR) {
            Professor *prof = (Professor *) atual->pessoa.info;

            if (prof->salario > maiorSalario) {
                maiorSalario = prof->salario;
            }
        }

        atual = atual->prox;
    }

    if (maiorSalario < 0) {
        printf("Nao ha professores na lista.\n");
        return;
    }

    // 2) Imprimir todos os professores que têm esse salário
    printf("\nProfessores com salario = %.2f:\n", maiorSalario);
    atual = lista;

    while (atual != NULL) {
        if (atual->pessoa.tipo == PROFESSOR) {
            Professor *prof = (Professor *) atual->pessoa.info;

            if (prof->salario == maiorSalario) {
                printf("Matricula: %d, Nome: %s\n",
                       atual->pessoa.matricula,
                       atual->pessoa.nome);
            }
        }

        atual = atual->prox;
    }
}

Pessoa criarPessoa() {
    Pessoa p;
    p.info = NULL; // inicializa ponteiro

    printf("\n-- Qual o tipo de pessoa? --\n");
    printf("0 - Professor\n1 - Aluno\nEscolha: ");
    scanf("%d", &p.tipo);
    getchar();

    while (p.tipo != PROFESSOR && p.tipo != ALUNO) {
        printf("Valor invalido. Digite 0 ou 1: ");
        scanf("%d", &p.tipo);
        getchar();
    }

    printf("Digite a matricula: ");
    scanf("%d", &p.matricula);
    getchar();

    printf("Digite o nome: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';

    // Aloca e preenche a info de acordo com p.tipo
    if (p.tipo == PROFESSOR) {
        Professor *prof = (Professor *) malloc(sizeof(Professor));

        if (prof == NULL) {
            printf("Erro ao alocar memoria para Professor.\n");
            exit(1);
        }

        printf("Digite o salario: ");
        scanf("%f", &prof->salario);
        getchar();

        p.info = prof;
    }
    else {
        Aluno *al = (Aluno *) malloc(sizeof(Aluno));

        if (al == NULL) {
            printf("Erro ao alocar memoria para Aluno.\n");
            exit(1);
        }

        printf("Digite o curso: ");
        fgets(al->curso, 50, stdin);
        al->curso[strcspn(al->curso, "\n")] = '\0';

        printf("Digite o ano de ingresso: ");
        scanf("%d", &al->anoIngresso);
        getchar();

        p.info = al;
    }

    return p;
}

int main() {
    No *lista = NULL;  // lista vazia
    int opcao;
    int mat;
    char curso[50];

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir pessoa na lista\n");
        printf("2. Remover pessoa pela matricula\n");
        printf("3. Buscar pessoa pela matricula\n");
        printf("4. Contar numero de alunos de um curso\n");
        printf("5. Imprimir professores de maior salario\n");
        printf("6. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1: {
                Pessoa p = criarPessoa();
                lista = inserirPessoa(lista, p);
                printf("Pessoa inserida com sucesso!\n");
            } break;

            case 2: {
                printf("Digite a matricula a remover: ");
                scanf("%d", &mat);
                lista = removerPessoa(lista, mat);
            } break;

            case 3: {
                printf("Digite a matricula para buscar: ");
                scanf("%d", &mat);
                buscarPessoa(lista, mat);
            } break;

            case 4: {
                printf("Digite o curso: ");
                fgets(curso, 50, stdin);
                curso[strcspn(curso, "\n")] = '\0';

                int qtd = contarAlunosCurso(lista, curso);
                printf("Ha %d aluno(s) no curso \"%s\".\n", qtd, curso);
            } break;

            case 5:
                imprimirProfessoresMaiorSalario(lista);
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }
    while (opcao != 6);

    // Liberar a lista inteira ao sair
    while (lista != NULL) {
        No* temp = lista;
        lista = lista->prox;
        liberarInfoPessoa(&temp->pessoa);  // libera p->info
        free(temp);                        // libera o nó
    }

    return 0;
}
