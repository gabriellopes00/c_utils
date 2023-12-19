#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int numero, i;
    long long int fatorial = 1; 
    
    printf("Digite um valor inteiro: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("O fatorial de números negativos não é definido.\n");
    } else {
        for (i = 1; i <= numero; i++) {
            fatorial *= i;
        }

        printf("%d! = %lld\n", numero, fatorial);
    }
	
	system("pause");
	return 0;
}
