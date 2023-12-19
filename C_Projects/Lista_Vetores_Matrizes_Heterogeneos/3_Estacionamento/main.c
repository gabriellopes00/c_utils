#include <stdio.h>
#include <string.h>

#define MAX_VEICULOS 5
#define TAM_PLACA 8
#define TAM_MARCA 20
#define TAM_MODELO 20
#define TAM_TELEFONE 15

int i;

struct Veiculo {
    char placa[TAM_PLACA];
    char marca[TAM_MARCA];
    char modelo[TAM_MODELO];
    float valorEstacionamento;
    char telefoneProprietario[TAM_TELEFONE];
};

void inicializarEstacionamento(struct Veiculo estacionamento[], int *numVeiculos) {
    for (i = 0; i < MAX_VEICULOS; i++) {
        estacionamento[i].placa[0] = '\0'; // Inicializa as placas como vazias
    }
    *numVeiculos = 0; // Inicializa o número de veículos como zero
}

int localizarPosicaoVazia(struct Veiculo estacionamento[]) {
    for (i = 0; i < MAX_VEICULOS; i++) {
        if (estacionamento[i].placa[0] == '\0') {
            return i; // Retorna o índice da primeira posição vazia encontrada
        }
    }
    return -1; // Retorna -1 se não encontrar posição vazia
}

int localizarVeiculo(struct Veiculo estacionamento[], int numVeiculos, const char *placa) {
    for (i = 0; i < numVeiculos; i++) {
        if (strcmp(estacionamento[i].placa, placa) == 0) {
            return i; // Retorna o índice do veículo se encontrado
        }
    }
    return -1; // Retorna -1 se o veículo não for encontrado
}

void registrarEntrada(struct Veiculo estacionamento[], int *numVeiculos) {
    if (*numVeiculos < MAX_VEICULOS) {
        int posicao = localizarPosicaoVazia(estacionamento);
        if (posicao != -1) {
            printf("Digite a placa do veiculo: ");
            scanf("%s", estacionamento[posicao].placa);
            printf("Digite a marca do veiculo: ");
            scanf("%s", estacionamento[posicao].marca);
            printf("Digite o modelo do veiculo: ");
            scanf("%s", estacionamento[posicao].modelo);
            printf("Digite o valor do estacionamento: ");
            scanf("%f", &estacionamento[posicao].valorEstacionamento);
            printf("Digite o telefone do proprietario: ");
            scanf("%s", estacionamento[posicao].telefoneProprietario);
            (*numVeiculos)++;
            printf("Entrada registrada com sucesso.\n");
        } else {
            printf("Estacionamento lotado. Nao e possivel registrar entrada.\n");
        }
    } else {
        printf("Estacionamento lotado. Nao e possivel registrar entrada.\n");
    }
}

void registrarSaida(struct Veiculo estacionamento[], int *numVeiculos) {
    char placa[TAM_PLACA];
    printf("Digite a placa do veiculo que deseja registrar saida: ");
    scanf("%s", placa);

    int posicao = localizarVeiculo(estacionamento, *numVeiculos, placa);
    if (posicao != -1) {
        // Libera a posição do veículo
        estacionamento[posicao].placa[0] = '\0';
        (*numVeiculos)--;
        printf("Saida registrada com sucesso.\n");
    } else {
        printf("Veiculo nao encontrado. Nao e possivel registrar saida.\n");
    }
}

void localizarVeiculoMenu(struct Veiculo estacionamento[], int numVeiculos) {
    char placa[TAM_PLACA];
    printf("Digite a placa do veiculo que deseja localizar: ");
    scanf("%s", placa);

    int posicao = localizarVeiculo(estacionamento, numVeiculos, placa);
    if (posicao != -1) {
        printf("Veiculo encontrado na posicao %d.\n", posicao + 1);
    } else {
        printf("Veiculo nao encontrado.\n");
    }
}

void relatorioVeiculos(struct Veiculo estacionamento[], int numVeiculos) {
    printf("\nRelatorio de veiculos no estacionamento:\n");
    for (i = 0; i < MAX_VEICULOS; i++) {
        if (estacionamento[i].placa[0] != '\0') {
            printf("Posicao %d: Placa: %s, Marca: %s, Modelo: %s, Valor Estacionamento: %.2f, Telefone: %s\n",
                   i + 1, estacionamento[i].placa, estacionamento[i].marca,
                   estacionamento[i].modelo, estacionamento[i].valorEstacionamento,
                   estacionamento[i].telefoneProprietario);
        }
    }
}

float saldoCaixa(struct Veiculo estacionamento[], int numVeiculos) {
    float total = 0;
    for (i = 0; i < MAX_VEICULOS; i++) {
        if (estacionamento[i].placa[0] != '\0') {
            total += estacionamento[i].valorEstacionamento;
        }
    }
    return total;
}

int main() {
    struct Veiculo estacionamento[MAX_VEICULOS];
    int numVeiculos;

    inicializarEstacionamento(estacionamento, &numVeiculos);

    int opcao;
    do {
        printf("\nSYSCAR\n");
        printf("1. Registrar entrada\n");
        printf("2. Registrar saida\n");
        printf("3. Localizar veiculo\n");
        printf("4. Relatorio de veiculos\n");
        printf("5. Saldo caixa\n");
        printf("6. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarEntrada(estacionamento, &numVeiculos);
                break;
            case 2:
                registrarSaida(estacionamento, &numVeiculos);
                break;
            case 3:
                localizarVeiculoMenu(estacionamento, numVeiculos);
                break;
            case 4:
                relatorioVeiculos(estacionamento, numVeiculos);
                break;
            case 5:
                printf("Saldo total no caixa: %.2f\n", saldoCaixa(estacionamento, numVeiculos));
                break;
            case 6:
                printf("Saindo do sistema SYSCAR.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

