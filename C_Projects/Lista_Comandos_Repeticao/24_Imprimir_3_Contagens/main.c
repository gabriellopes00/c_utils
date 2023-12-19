#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int valor1, valor2, valor3, i;

    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &valor1);

    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &valor2);

    printf("Digite o terceiro valor inteiro: ");
    scanf("%d", &valor3);

    printf("Impressao contagem do valor %d:\n", valor1);
    for (i = 1; i <= valor1; i++) {
        printf("%d\n", i);
    }

    printf("Impressao contagem do valor %d:\n", valor2);
    for (i = 1; i <= valor2; i++) {
        printf("%d\n", i);
    }

    printf("Impressao contagem do valor %d:\n", valor3);
    for (i = 1; i <= valor3; i++) {
        printf("%d\n", i);
    }
	
	system("pause");
	return 0;
}
