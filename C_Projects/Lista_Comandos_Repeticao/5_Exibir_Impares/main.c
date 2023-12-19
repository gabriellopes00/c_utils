#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i;
	
	printf("Valores ímpares de 1 a 20:\n");

    for (i = 1; i <= 20; i++) {
        if (i % 2 != 0) {
            printf("%d\n", i);
        }
    }
	
	system("pause");
	return 0;
}
