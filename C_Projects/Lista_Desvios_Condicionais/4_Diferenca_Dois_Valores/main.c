#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int valor1, valor2, maior, menor, diferenca;

    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &valor1);

    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &valor2);

    if (valor1 > valor2) {
        maior = valor1;
        menor = valor2;
    } else {
        maior = valor2;
        menor = valor1;
    }

    diferenca = maior - menor;

    printf("O maior valor e: %d\n", maior);
    printf("O menor valor e: %d\n", menor);
    printf("A diferenca entre os valores e: %d\n", diferenca);
	
	system("pause");
	return 0;
}
