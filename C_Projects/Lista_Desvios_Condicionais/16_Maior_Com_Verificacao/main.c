#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int valor1, valor2;

    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &valor1);

    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &valor2);

    if (valor1 == valor2) {
        printf("Valores iguais nao sao permitidos.\n");
    } else {
        int maior;
        if (valor1 > valor2) {
            maior = valor1;
        } else {
            maior = valor2;
        }

        printf("O maior valor informado e: %d\n", maior);
    }	
	
	system("pause");
	return 0;
}
