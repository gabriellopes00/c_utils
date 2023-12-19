#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int n, p, i;

    printf("Digite um numero inteiro n: ");
    scanf("%d", &n);

    printf("Digite o valor do passo (p): ");
    scanf("%d", &p);

    if (p <= 0) {
        printf("O valor do passo (p) deve ser maior que zero. Assumindo p = 1.\n");
        p = 1;
    }

    printf("Multiplos de %d ate %d:\n", p, n);
    for (i = 0; i <= n; i += p) {
        printf("%d ", i);
    }

	
	system("pause");
	return 0;
}
