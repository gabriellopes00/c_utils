#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float salario;
    float soma = 0;
    int continuar = 1;
    int contador = 0;

    while (continuar == 1 && contador < 5) {
        printf("Digite o valor do salario: ");
        scanf("%f", &salario);

        soma += salario;
        contador++;

        if (contador < 5) {
            printf("Deseja informar outro salario (0 = Nao, 1 = Sim)? ");
            scanf("%d", &continuar);
        } else {
            printf("Numero maximo de salarios atingido.\n");
        }
    }

    printf("A soma dos salarios informados e: %.2f\n", soma);
	
	system("pause");
	return 0;
}
