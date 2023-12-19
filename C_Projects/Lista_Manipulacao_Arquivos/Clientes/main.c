#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100
#define TAM_CPF 12
#define TAM_RG 10
#define TAM_NOME 50
#define SALARIO_MINIMO 1045.00
#define ARQUIVO "clientes.dat"

int i;

typedef struct {
    char cpf[TAM_CPF];
    char rg[TAM_RG];
    char nome[TAM_NOME];
    int idade;
    char sexo;
    float salario;
} Cliente;

void imprimirMenu() {
    printf("\nSISGESCLI - SISTEMA DE GESTAO DE CLIENTES\n");
    printf("1. Inserir\n");
    printf("2. Alterar\n");
    printf("3. Excluir\n");
    printf("4. Pesquisar CPF\n");
    printf("5. Pesquisar NOME\n");
    printf("6. Imprimir TODOS\n");
    printf("7. Relatorio por GENERO\n");
    printf("8. Relatorio por SALARIO\n");
    printf("9. Salvar em banco\n");
    printf("10. Ler do banco\n");
    printf("20. Sair\n");
    printf("Escolha uma opcao: ");
}

int buscarPosicaoVazia(Cliente clientes[]) {
    for (i = 0; i < MAX_CLIENTES; i++) {
        if (clientes[i].cpf[0] == '\0') {
            return i;
        }
    }
    return -1;  // Não há posição vazia
}

int buscarClientePorCPF(Cliente clientes[], char cpf[]) {
    for (i = 0; i < MAX_CLIENTES; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            return i;  // Retorna a posição se encontrar
        }
    }
    return -1;  // Não encontrado
}

void inserirCliente(Cliente clientes[]) {
    char novoCPF[TAM_CPF];
    printf("Digite o CPF do cliente a ser inserido: ");
    scanf("%s", novoCPF);

    // Verifica se o CPF já existe
    if (buscarClientePorCPF(clientes, novoCPF) != -1) {
        printf("CPF ja existe. Insercao cancelada.\n");
        return;
    }

    int posicaoVazia = buscarPosicaoVazia(clientes);

    if (posicaoVazia != -1) {
        strcpy(clientes[posicaoVazia].cpf, novoCPF);

        printf("Digite o RG: ");
        scanf("%s", clientes[posicaoVazia].rg);

        printf("Digite o nome: ");
        scanf(" %[^\n]s", clientes[posicaoVazia].nome);

        printf("Digite a idade: ");
        scanf("%d", &clientes[posicaoVazia].idade);

        printf("Digite o sexo (M/F): ");
        scanf(" %c", &clientes[posicaoVazia].sexo);

        printf("Digite o salario: ");
        scanf("%f", &clientes[posicaoVazia].salario);

        printf("Cliente inserido com sucesso.\n");
    } else {
        printf("Nao ha posicoes vazias para insercao.\n");
    }
}

void alterarCliente(Cliente clientes[]) {
    char cpfOrigem[TAM_CPF];
    printf("Digite o CPF de origem: ");
    scanf("%s", cpfOrigem);

    int posicaoOrigem = buscarClientePorCPF(clientes, cpfOrigem);

    if (posicaoOrigem != -1) {
        printf("Digite o novo CPF: ");
        scanf("%s", clientes[posicaoOrigem].cpf);

        // Verifica se o novo CPF já existe
        if (buscarClientePorCPF(clientes, clientes[posicaoOrigem].cpf) != -1) {
            printf("CPF ja existe. Alteracao cancelada.\n");
            return;
        }

        printf("Digite o novo RG: ");
        scanf("%s", clientes[posicaoOrigem].rg);

        printf("Digite o novo nome: ");
        scanf(" %[^\n]s", clientes[posicaoOrigem].nome);

        printf("Digite a nova idade: ");
        scanf("%d", &clientes[posicaoOrigem].idade);

        printf("Digite o novo sexo (M/F): ");
        scanf(" %c", &clientes[posicaoOrigem].sexo);

        printf("Digite o novo salario: ");
        scanf("%f", &clientes[posicaoOrigem].salario);

        printf("Cliente alterado com sucesso.\n");
    } else {
        printf("CPF de origem nao encontrado.\n");
    }
}

void excluirCliente(Cliente clientes[]) {
    char cpfExcluir[TAM_CPF];
    printf("Digite o CPF do cliente a ser excluido: ");
    scanf("%s", cpfExcluir);

    int posicaoExcluir = buscarClientePorCPF(clientes, cpfExcluir);

    if (posicaoExcluir != -1) {
        clientes[posicaoExcluir].cpf[0] = '\0';  // Marca como posição vazia
        printf("Cliente excluido com sucesso.\n");
    } else {
        printf("CPF nao encontrado.\n");
    }
}

void pesquisarPorCPF(Cliente clientes[]) {
    char cpfPesquisar[TAM_CPF];
    printf("Digite o CPF do cliente a ser pesquisado: ");
    scanf("%s", cpfPesquisar);

    int posicao = buscarClientePorCPF(clientes, cpfPesquisar);

    if (posicao != -1) {
        printf("Cliente encontrado na posicao %d.\n", posicao);
    } else {
        printf("CPF nao encontrado.\n");
    }
}

void pesquisarPorNome(Cliente clientes[]) {
    char nomePesquisar[TAM_NOME];
    printf("Digite o nome do cliente a ser pesquisado: ");
    scanf(" %[^\n]s", nomePesquisar);

    int encontrado = 0;

    for (i = 0; i < MAX_CLIENTES; i++) {
        if (strcmp(clientes[i].nome, nomePesquisar) == 0) {
            printf("Cliente encontrado na posicao %d.\n", i);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nome nao encontrado.\n");
    }
}

void imprimirTodosClientes(Cliente clientes[]) {
    printf("Imprimindo TODOS os clientes:\n");
    for (i = 0; i < MAX_CLIENTES; i++) {
        if (clientes[i].cpf[0] != '\0') {
            printf("Posicao %d: CPF: %s, RG: %s, Nome: %s, Idade: %d, Sexo: %c, Salario: %.2f\n", i,
                   clientes[i].cpf, clientes[i].rg, clientes[i].nome, clientes[i].idade, clientes[i].sexo,
                   clientes[i].salario);
        }
    }
}

void relatorioPorGenero(Cliente clientes[]) {
    int numClientesMasculino = 0;
    int numClientesFeminino = 0;
    int somaIdadeMasculino = 0;
    int somaIdadeFeminino = 0;
    float somaSalarioMasculino = 0.0;
    float somaSalarioFeminino = 0.0;

    for (i = 0; i < MAX_CLIENTES; i++) {
        if (clientes[i].cpf[0] != '\0') {
            if (clientes[i].sexo == 'M') {
                numClientesMasculino++;
                somaIdadeMasculino += clientes[i].idade;
                somaSalarioMasculino += clientes[i].salario;
            } else if (clientes[i].sexo == 'F') {
                numClientesFeminino++;
                somaIdadeFeminino += clientes[i].idade;
                somaSalarioFeminino += clientes[i].salario;
            }
        }
    }

    if (numClientesMasculino > 0) {
        printf("Relatorio por GENERO - MASCULINO\n");
        printf("a) Numero de clientes: %d\n", numClientesMasculino);
        printf("b) Idade media: %.2f\n", (float)somaIdadeMasculino / numClientesMasculino);
        printf("c) Salario medio: %.2f\n", somaSalarioMasculino / numClientesMasculino);
        printf("d) Soma salarios: %.2f\n", somaSalarioMasculino);
    }

    if (numClientesFeminino > 0) {
        printf("\nRelatorio por GENERO - FEMININO\n");
        printf("a) Numero de clientes: %d\n", numClientesFeminino);
        printf("b) Idade media: %.2f\n", (float)somaIdadeFeminino / numClientesFeminino);
        printf("c) Salario medio: %.2f\n", somaSalarioFeminino / numClientesFeminino);
        printf("d) Soma salarios: %.2f\n", somaSalarioFeminino);
    }
}

void relatorioPorSalario(Cliente clientes[]) {
    int posicaoMaiorSalario = 0;
    int posicaoMenorSalario = 0;
    float somaSalarios = 0.0;
    int numClientesMenorSalario = 0;

    for (i = 0; i < MAX_CLIENTES; i++) {
        if (clientes[i].cpf[0] != '\0') {
            somaSalarios += clientes[i].salario;

            if (clientes[i].salario > clientes[posicaoMaiorSalario].salario) {
                posicaoMaiorSalario = i;
            }

            if (clientes[i].salario < clientes[posicaoMenorSalario].salario) {
                posicaoMenorSalario = i;
            }

            if (clientes[i].salario < SALARIO_MINIMO) {
                numClientesMenorSalario++;
            }
        }
    }

    printf("Relatorio por SALARIO\n");
    printf("a) Cliente com maior salario: %s, %.2f\n", clientes[posicaoMaiorSalario].nome,
           clientes[posicaoMaiorSalario].salario);
    printf("b) Cliente com menor salario: %s, %.2f\n", clientes[posicaoMenorSalario].nome,
           clientes[posicaoMenorSalario].salario);
    printf("c) Salario medio geral: %.2f\n", somaSalarios / MAX_CLIENTES);
    printf("d) Soma dos salarios: %.2f\n", somaSalarios);
    printf("e) Numero de clientes com salario menor que 1 salario minimo: %d\n", numClientesMenorSalario);
}

void salvarEmBanco(Cliente clientes[]) {
    FILE *arquivo = fopen(ARQUIVO, "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(clientes, sizeof(Cliente), MAX_CLIENTES, arquivo);

    fclose(arquivo);

    printf("Dados salvos em banco com sucesso.\n");
}

void lerDoBanco(Cliente clientes[]) {
    FILE *arquivo = fopen(ARQUIVO, "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fread(clientes, sizeof(Cliente), MAX_CLIENTES, arquivo);

    fclose(arquivo);

    printf("Dados lidos do banco com sucesso.\n");
}

int main() {
    Cliente clientes[MAX_CLIENTES] = {0};  // Inicializa o vetor de clientes

    int opcao;

    do {
        imprimirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirCliente(clientes);
                break;
            case 2:
                alterarCliente(clientes);
                break;
            case 3:
                excluirCliente(clientes);
                break;
            case 4:
                pesquisarPorCPF(clientes);
                break;
            case 5:
                pesquisarPorNome(clientes);
                break;
            case 6:
                imprimirTodosClientes(clientes);
                break;
            case 7:
                relatorioPorGenero(clientes);
                break;
            case 8:
                relatorioPorSalario(clientes);
                break;
            case 9:
                salvarEmBanco(clientes);
                break;
            case 10:
                lerDoBanco(clientes);
                break;
            case 20:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 20);

    return 0;
}

