#include <stdio.h>

int main() {
    int i;
    int termos = 15;
    long long int anterior = 0, atual = 1, proximo;
    
    printf("Série de Fibonacci até o décimo quinto termo:\n");
    
    for (i = 1; i <= termos; i++) {
        printf("%lld, ", atual);
        
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    
    printf("\n");
    
    return 0;
}
