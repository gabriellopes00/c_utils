#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int soma = 0;
	int valorI, valorF = 0;
	
	printf("Digite o valor inicial para soma: ");
	scanf("%d", &valorI);
	printf("Digite o valor final para soma: ");
	scanf("%d", &valorF);

    for (valorI; valorI <= valorF; valorI++) {
        if (valorI % 2 == 0) {
            soma += valorI;
            printf("%d\n", valorI);
        }
    }

    printf("A soma dos valores pares e: %d\n", soma);

	system("pause");
	return 0;
}
