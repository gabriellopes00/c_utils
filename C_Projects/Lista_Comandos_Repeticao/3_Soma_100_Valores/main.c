#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int soma = 0, i;

    for (i = 1; i <= 100; i++) {
        soma += i;
    }

    printf("A soma de todos os valores entre 1 e 100 é: %d\n", soma);
	
	system("pause");
	return 0;
}
