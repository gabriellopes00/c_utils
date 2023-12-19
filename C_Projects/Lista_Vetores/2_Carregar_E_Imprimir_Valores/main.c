#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int idades[10], i;

    for (i = 0; i < 10; i++) {
        printf("Digite a idade %d: ", i + 1);
        scanf("%d", &idades[i]);
    }

    printf("\nIdades carregadas:\n");
    for (i = 0; i < 10; i++) {
        printf("Posicao %d: %d\n", i + 1, idades[i]);
    }
	
	system("pause");
	return 0;
}
