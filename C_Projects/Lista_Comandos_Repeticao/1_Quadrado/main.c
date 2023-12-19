#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i;
	
	for (i = 15; i <= 50; i++) {
        int quadrado = i * i;
        printf("%d ao quadrado é igual a %d\n", i, quadrado);
    }
	
	system("pause");
	return 0;
}
