#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a, b, c;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    printf("Digite o valor de C: ");
    scanf("%d", &c);

    if (a + b > c) {
        printf("A soma de A e B e maior do que C.\n");
    } else {
        printf("A soma de A e B nao e maior do que C.\n");
    }
	
	system("pause");
	return 0;
}
