#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int valor1, valor2, valor3, valor4;

    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &valor1);

    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &valor2);

    printf("Digite o terceiro valor inteiro: ");
    scanf("%d", &valor3);

    printf("Digite o quarto valor inteiro: ");
    scanf("%d", &valor4);

    printf("Valores divisiveis por 2 e 3:\n");

    if (valor1 % 2 == 0 && valor1 % 3 == 0) {
        printf("%d\n", valor1);
    }

    if (valor2 % 2 == 0 && valor2 % 3 == 0) {
        printf("%d\n", valor2);
    }

    if (valor3 % 2 == 0 && valor3 % 3 == 0) {
        printf("%d\n", valor3);
    }

    if (valor4 % 2 == 0 && valor4 % 3 == 0) {
        printf("%d\n", valor4);
    }
	
	system("pause");
	return 0;
}
