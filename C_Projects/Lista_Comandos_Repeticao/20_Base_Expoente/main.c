#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int n = 15, i; 
    int primeiro = 1, segundo = 1, proximo;

    printf("%d, %d, ", primeiro, segundo);

    for (i = 3; i <= n; i++) {
        proximo = primeiro + segundo;
        printf("%d", proximo);
        if (i < n) {
            printf(", ");
        }
        primeiro = segundo;
        segundo = proximo;
    }

    printf("\n");

    system("pause");
	return 0;
}
