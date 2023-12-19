#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max_linhas 10
#define Max_colunas 10

int i, j, linhaMaiorSoma, colunaMaiorValoresPares, linhaMaiorValor;
int linha1 = 0, linha2 = 0, coluna1 = 0, coluna2 = 0;
int somaLinha1 = 0, somaLinha2 = 0, somaColuna1 = 0, somaColuna2 = 0;

void carregarMatriz(int matriz[Max_linhas][Max_colunas], int linhas, int colunas) {
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 40 + 1;
        }
    }
}

void imprimirMatriz(int matriz[Max_linhas][Max_colunas], int linhas, int colunas) {
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int encontrarLinhaMaiorSoma(int matriz[Max_linhas][Max_colunas], int linhas, int colunas) {
    int linhaMaiorSoma = 0;
    int maiorSoma = 0;

    for (i = 0; i < linhas; i++) {
        int somaLinha = 0;
        for (j = 0; j < colunas; j++) {
            somaLinha += matriz[i][j];
        }

        if (somaLinha > maiorSoma) {
            maiorSoma = somaLinha;
            linhaMaiorSoma = i;
        }
    }

    return linhaMaiorSoma;
}

int contarValoresParesNaColuna(int matriz[Max_linhas][Max_colunas], int linhas, int coluna) {
    int valoresPares = 0;

    for (i = 0; i < linhas; i++) {
        if (matriz[i][coluna] % 2 == 0) {
            valoresPares++;
        }
    }

    return valoresPares;
}

int encontrarColunaMaiorValoresPares(int matriz[Max_linhas][Max_colunas], int linhas, int colunas) {
    int colunaMaiorValoresPares = 0;
    int maiorNumeroValoresPares = 0;

    for (j = 0; j < colunas; j++) {
        int valoresPares = contarValoresParesNaColuna(matriz, linhas, j);
        if (valoresPares > maiorNumeroValoresPares) {
            maiorNumeroValoresPares = valoresPares;
            colunaMaiorValoresPares = j;
        }
    }

    return colunaMaiorValoresPares;
}

int encontrarLinhaMaiorValor(int matriz[Max_linhas][Max_colunas], int linhas, int colunas) {
    int linhaMaiorValor = 0;
    int maiorValor = matriz[0][0];

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (matriz[i][j] > maiorValor) {
                maiorValor = matriz[i][j];
                linhaMaiorValor = i;
            }
        }
    }

    return linhaMaiorValor;
}

int main() {
    srand(time(NULL));
    int matriz[Max_linhas][Max_colunas];
    int linhas, colunas;

    printf("\n===== MATRIZ =====\n");

    printf("Informe o numero de linhas (ate %d): ", Max_linhas);
    scanf("%d", &linhas);

    printf("Informe o numero de colunas (ate %d): ", Max_colunas);
    scanf("%d", &colunas);

    if (linhas > Max_linhas || colunas > Max_colunas || linhas <= 0 || colunas <= 0) {
        printf("Numero invalido de linhas ou colunas.\n");
        return 1;
    }

    int opcao;
    char opcao2;

    do {
        printf("1. Carregar matriz com valores aleatorios entre 1 e 40;\n");
        printf("2. Imprimir os valores da Matriz\n");
        printf("3. Mostrar a linha com maior soma\n");
        printf("4. Mostrar coluna com maior numero de pares\n");
        printf("5. Mostrar linha com maior valor\n");
        printf("6. Mostrar 2 linhas e 2 colunas\n");
        printf("7. Imprimir o valor das linhas inseridas\n");
        printf("8. Imprimir o valor da soma das linhas inseridas\n");
        printf("9. Imprimir o valor da maior soma das linhas inseridas\n");
        printf("0. Sair\n");
        printf("OBS: Para selecionar as opcoes 7, 8 e 9, antes sera necessario inserir os dados na opcao 6.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                carregarMatriz(matriz, linhas, colunas);
                break;
            case 2:
                printf("Matriz gerada:\n");
                imprimirMatriz(matriz, linhas, colunas);
                break;
            case 3:
                linhaMaiorSoma = encontrarLinhaMaiorSoma(matriz, linhas, colunas);
                printf("Linha com a maior soma: Linha %d\n", linhaMaiorSoma + 1);
                break;
            case 4:
                colunaMaiorValoresPares = encontrarColunaMaiorValoresPares(matriz, linhas, colunas);
                printf("Coluna com o maior numero de valores pares: Coluna %d\n", colunaMaiorValoresPares + 1);
                break;
            case 5:
                linhaMaiorValor = encontrarLinhaMaiorValor(matriz, linhas, colunas);
                printf("Linha com o maior valor: Linha %d\n", linhaMaiorValor + 1);
                break;
            case 6:
            	linha1, linha2, coluna1, coluna2;
    			printf("Informe duas linhas (1 a %d): ", linhas);
    			scanf("%d %d", &linha1, &linha2);
    			printf("Informe duas colunas (1 a %d): ", colunas);
    			scanf("%d %d", &coluna1, &coluna2);
    			break;
    		case 7:
    			if(linha1 == 0 || linha2 == 0 || coluna1 == 0 || coluna2 == 0){
    				printf("E necessario inserir os dados na opcao 6 antes de continuar.\n");
        			return 1;	
				} else{
					if (linha1 < 1 || linha2 < 1 || linha1 > linhas || linha2 > linhas ||
        				coluna1 < 1 || coluna2 < 1 || coluna1 > colunas || coluna2 > colunas) {
        				printf("Linhas ou colunas fora dos limites.\n");
        				return 1;
    				} else{
    					printf("Valores das linhas: Linha %d, Linha %d\n", linha1, linha2);
    					printf("Valores das colunas: Coluna %d, Coluna %d\n", coluna1, coluna2);	
					}
				}
				break;
			case 8:
				if(linha1 == 0 || linha2 ==0 || coluna1 == 0 || coluna2 == 0){
    				printf("E necessario inserir os dados na opcao 6 antes de continuar.\n");
        			return 1;	
				} else{
					somaLinha1 = 0, somaLinha2 = 0, somaColuna1 = 0, somaColuna2 = 0;
							
    				for (i = 0; i < colunas; i++) {
        				somaLinha1 += matriz[linha1 - 1][i];
        				somaLinha2 += matriz[linha2 - 1][i];
    				}

    				for (i = 0; i < linhas; i++) {
        				somaColuna1 += matriz[i][coluna1 - 1];
        				somaColuna2 += matriz[i][coluna2 - 1];
    				}
	
    				printf("Valores das linhas: Linha %d: %d, Linha %d: %d\n", linha1, somaLinha1, linha2, somaLinha2);
    				printf("Valores das colunas: Coluna %d: %d, Coluna %d: %d\n", coluna1, somaColuna1, coluna2, somaColuna2);
    			}
    			break;
    		case 9:
    			if(linha1 == 0 || linha2 ==0 || coluna1 == 0 || coluna2 == 0){
    				printf("E necessario inserir os dados na opcao 6 antes de continuar.\n");
        			return 1;	
				} else{
    				if (somaLinha1 + somaColuna1 > somaLinha2 + somaColuna2) {
        				printf("A primeira combinacao (Linha %d + Coluna %d) tem a maior soma.\n", linha1, coluna1);
    				} else {
        				printf("A segunda combinacao (Linha %d + Coluna %d) tem a maior soma.\n", linha2, coluna2);
    				}
    			}
    			break;
        	case 0:
            	printf("Encerrando o programa.\n");
            	break;
        	default:
            	printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    system("pause");
    return 0;
}

