#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float valorAmigo1, valorAmigo2, valorAmigo3;
    char adicionarServicos;
    float valorTotal, valorServicos, valorTotalCompra;

    printf("Digite o valor gasto pelo amigo 1: R$ ");
    scanf("%f", &valorAmigo1);

    printf("Digite o valor gasto pelo amigo 2: R$ ");
    scanf("%f", &valorAmigo2);

    printf("Digite o valor gasto pelo amigo 3: R$ ");
    scanf("%f", &valorAmigo3);

    printf("Deseja adicionar os servicos de atendimento (10%%)? (S/N): ");
    scanf(" %c", &adicionarServicos);

    valorTotal = valorAmigo1 + valorAmigo2 + valorAmigo3;

    valorServicos = adicionarServicos == 'S' || adicionarServicos == 's' ? valorTotal * 0.10 : 0.00;

    valorTotalCompra = valorTotal + valorServicos;

    printf("Valor total dos gastos: R$ %.2f\n", valorTotal);
    printf("Valor dos servicos de atendimento: R$ %.2f\n", valorServicos);
    printf("Valor total da compra: R$ %.2f\n", valorTotalCompra);
	
	system("pause");
	return 0;
}
