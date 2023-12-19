#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float valorParcelaReal, percentualAcrescimo, valorParcelaAtraso;

    printf("Digite o valor da parcela real: R$ ");
    scanf("%f", &valorParcelaReal);

    printf("Digite o percentual de acrescimo/juros (em porcentagem): ");
    scanf("%f", &percentualAcrescimo);

    valorParcelaAtraso = valorParcelaReal + ((valorParcelaReal * percentualAcrescimo) / 100);

    printf("O valor da parcela em atraso e: R$ %.2f\n", valorParcelaAtraso);
	
	system("pause");
	return 0;
}
