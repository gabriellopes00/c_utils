#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i;
	
	printf("N�meros divis�veis por 4 no intervalo de 1 a 200:\n");

    for (i = 1; i <= 200; i++) {
        if (i % 4 == 0) {
            printf("%d\n", i);
        }
    }
	
	system("pause");
	return 0;
}
