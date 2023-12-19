#include <stdio.h>
#include <string.h>

#define NUM_AMIGOS 4

struct Amigo {
    char nome[50];
    double quantidade_reais;
    double quantidade_dolar;
    double quantidade_euro;
    double quantidade_libra;
};

int main() {
    int i, j;
    double cotacao_dolar, cotacao_euro, cotacao_libra;
    struct Amigo amigos[NUM_AMIGOS];
    double soma_total = 0;
    
    printf("Digite a cotação do Dólar: ");
    scanf("%lf", &cotacao_dolar);
    printf("Digite a cotação do Euro: ");
    scanf("%lf", &cotacao_euro);
    printf("Digite a cotação da Libra Esterlina: ");
    scanf("%lf", &cotacao_libra);
    
    for (i = 0; i < NUM_AMIGOS; i++) {
        printf("Digite o nome do amigo %d: ", i + 1);
        scanf("%s", amigos[i].nome);
        printf("Digite a quantidade de Reais que o %s deseja levar: ", amigos[i].nome);
        scanf("%lf", &amigos[i].quantidade_reais);
        
        amigos[i].quantidade_dolar = amigos[i].quantidade_reais / cotacao_dolar;
        amigos[i].quantidade_euro = amigos[i].quantidade_reais / cotacao_euro;
        amigos[i].quantidade_libra = amigos[i].quantidade_reais / cotacao_libra;
        
        soma_total += amigos[i].quantidade_reais;
    }
    
    int indice_maior = 0;
    int indice_menor = 0;
    
    for (i = 1; i < NUM_AMIGOS; i++) {
        if (amigos[i].quantidade_reais > amigos[indice_maior].quantidade_reais) {
            indice_maior = i;
        }
        if (amigos[i].quantidade_reais < amigos[indice_menor].quantidade_reais) {
            indice_menor = i;
        }
    }
    
    printf("\nResultados:\n");
    printf("Soma total em Reais: %.2lf\n", soma_total);
    printf("Amigo com mais dinheiro: %s (%.2lf Reais)\n", amigos[indice_maior].nome, amigos[indice_maior].quantidade_reais);
    printf("Amigo com menos dinheiro: %s (%.2lf Reais)\n", amigos[indice_menor].nome, amigos[indice_menor].quantidade_reais);
    
    printf("\nQuantidade de dinheiro convertido para cada amigo:\n");
    for (i = 0; i < NUM_AMIGOS; i++) {
        printf("%s tem %.2lf Reais, convertidos terá %.2lf dólares, %.2lf euros e %.2lf libras.\n", amigos[i].nome,
               amigos[i].quantidade_reais, amigos[i].quantidade_dolar, amigos[i].quantidade_euro, amigos[i].quantidade_libra);
    }
    
    for (i = 0; i < NUM_AMIGOS - 1; i++) {
        for (j = 0; j < NUM_AMIGOS - i - 1; j++) {
            if (amigos[j].quantidade_reais > amigos[j + 1].quantidade_reais) {
                struct Amigo temp = amigos[j];
                amigos[j] = amigos[j + 1];
                amigos[j + 1] = temp;
            }
        }
    }
    
    printf("\nAmigos ordenados por quantidade de Reais (do menor para o maior):\n");
    for (i = 0; i < NUM_AMIGOS; i++) {
        printf("%s: %.2lf Reais\n", amigos[i].nome, amigos[i].quantidade_reais);
    }
    
    return 0;
}
