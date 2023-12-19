#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float a, b, c, delta, raiz1, raiz2;

    printf("Digite o valor de a: ");
    scanf("%f", &a);

    printf("Digite o valor de b: ");
    scanf("%f", &b);

    printf("Digite o valor de c: ");
    scanf("%f", &c);

    delta = (b * b) - (4 * a * c);

    if (delta > 0) {
        raiz1 = (-b + sqrt(delta)) / (2 * a);
        raiz2 = (-b - sqrt(delta)) / (2 * a);
        printf("Duas raizes reais distintas:\n");
        printf("Raiz 1 = %.2f\n", raiz1);
        printf("Raiz 2 = %.2f\n", raiz2);
    } else if (delta == 0) {
        raiz1 = -b / (2 * a);
        printf("Uma raiz real:\n");
        printf("Raiz 1 = %.2f\n", raiz1);
    } else {
        printf("Nao ha raizes reais.\n");
    }
	
	system("pause");
	return 0;
}
