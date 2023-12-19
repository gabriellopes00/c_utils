#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int valores[5], i = 0, j = 0;

    printf("Digite 5 valores inteiros separados por espaço: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &valores[i]);
    }

    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 4; j++) {
            if (valores[i] == valores[j]) {
                printf("Valores repetidos não são permitidos.\n");
                return 0;
            }
        }
    }

    if (valores[0] > valores[1]) {
        int temp = valores[0];
        valores[0] = valores[1];
        valores[1] = temp;
    }

    int intervalo1Min = valores[0];
    int intervalo1Max = valores[1];
    int intervalo2Min = valores[2];
    int intervalo2Max = valores[3];

    int valor5 = valores[4];
    if ((valor5 >= intervalo1Min && valor5 <= intervalo1Max) && (valor5 >= intervalo2Min && valor5 <= intervalo2Max)) {
        printf("O valor 5 está dentro de ambos os intervalos.\n");
    } else if (valor5 >= intervalo1Min && valor5 <= intervalo1Max) {
        printf("O valor 5 está dentro do primeiro intervalo.\n");
    } else if (valor5 >= intervalo2Min && valor5 <= intervalo2Max) {
        printf("O valor 5 está dentro do segundo intervalo.\n");
    } else {
        printf("O valor 5 não está dentro de nenhum dos intervalos.\n");
    }
	
	system("pause");
	return 0;
}
