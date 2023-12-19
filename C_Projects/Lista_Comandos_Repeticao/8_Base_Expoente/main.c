#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	double base, expoente, resultado;

    printf("Digite a base: ");
    scanf("%lf", &base);

    printf("Digite o expoente: ");
    scanf("%lf", &expoente);

    resultado = pow(base, expoente);

    printf("%.2lf elevado a %.2lf é igual a %.2lf\n", base, expoente, resultado);

	system("pause");
	return 0;
}
