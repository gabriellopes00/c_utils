#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float valorEmReais, cotacaoDolar, cotacaoEuro, valorEmDolares, valorEmEuros;

    printf("Digite o valor em reais: R$ ");
    scanf("%f", &valorEmReais);

    printf("Digite a cotacao do dolar: ");
    scanf("%f", &cotacaoDolar);

    printf("Digite a cotacao do euro: ");
    scanf("%f", &cotacaoEuro);

    valorEmDolares = valorEmReais / cotacaoDolar;
    valorEmEuros = valorEmReais / cotacaoEuro;

    printf("O valor em dolares e: %.2f USD\n", valorEmDolares);
    printf("O valor em euros e: %.2f EUR\n", valorEmEuros);	
	
	system("pause");
	return 0;
}
