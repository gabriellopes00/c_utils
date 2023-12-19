#include <stdio.h>

// Função para calcular a Média 1 (Prova A, Prova B)
float calcularMedia1(float provaA, float provaB) {
    return (provaA + provaB) / 2;
}

// Função para calcular a Média 2 (Prova A, Prova B, Prova C)
float calcularMedia2(float provaA, float provaB, float provaC) {
    return (provaA + provaB + provaC) / 3;
}

// Função para calcular a Média 3 (Prova A = 40%, Prova B = 40%, Atividade C = 20%)
float calcularMedia3(float provaA, float provaB, float atividadeC) {
    return 0.4 * provaA + 0.4 * provaB + 0.2 * atividadeC;
}

// Função para calcular a Média 4 (Prova A = 30%, Prova B = 30%, Atividade C = 20%, Pluridisciplinar = 20%)
float calcularMedia4(float provaA, float provaB, float atividadeC, float pluridisciplinar) {
    return 0.3 * provaA + 0.3 * provaB + 0.2 * atividadeC + 0.2 * pluridisciplinar;
}

// Função para calcular a Média 5 (Prova A = 30%, Prova B = 30%, Atividades C = 20% (3 atividades), Pluridisciplinar = 20%)
float calcularMedia5(float provaA, float provaB, float atividadeC1, float atividadeC2, float atividadeC3, float pluridisciplinar) {
    return 0.3 * provaA + 0.3 * provaB + 0.2 * (atividadeC1 + atividadeC2 + atividadeC3) + 0.2 * pluridisciplinar;
}

// Função para calcular a Média 6 ((NP1 + NP2) / 2)
float calcularMedia6(float atividade1, float provaA, float atividade2, float pluridisciplinar, float provaB) {
    float np1 = 0.3 * atividade1 + 0.7 * provaA;
    float np2 = 0.2 * (atividade2 + pluridisciplinar) + 0.6 * provaB;
    return (np1 + np2) / 2;
}

// Procedimento para avaliar se o aluno foi aprovado ou não
void avaliarAprovacao(float media) {
    if (media >= 5.0) {
        printf("Aluno APROVADO com media %.2f\n", media);
    } else {
        printf("Aluno REPROVADO com media %.2f\n", media);
    }
}

int main() {
    int opcao;
    float provaA, provaB, provaC, atividadeC, pluridisciplinar, atividadeC1, atividadeC2, atividadeC3;

    do {
        // Exibe o menu
        printf("\nMEDIAS ESCOLARES\n");
        printf("1 - Media 1 (Prova A, Prova B)\n");
        printf("2 - Media 2 (Prova A, Prova B, Prova C)\n");
        printf("3 - Media 3 (Prova A = 40%%, Prova B = 40%%, Atividade C = 20%%)\n");
        printf("4 - Media 4 (Prova A = 30%%, Prova B = 30%%, Atividade C = 20%%, Pluridisciplinar = 20%%)\n");
        printf("5 - Media 5 (Prova A = 30%%, Prova B = 30%%, Atividades C = 20%% (3 atividades), Pluridisciplinar = 20%%)\n");
        printf("6 - Media 6 ((NP1 + NP2) / 2)\n");
        printf("9 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        // Realiza a operação de acordo com a opção escolhida
        switch (opcao) {
            case 1:
                printf("Digite as notas da Prova A e Prova B: ");
                scanf("%f %f", &provaA, &provaB);
                avaliarAprovacao(calcularMedia1(provaA, provaB));
                break;
            case 2:
                printf("Digite as notas da Prova A, Prova B e Prova C: ");
                scanf("%f %f %f", &provaA, &provaB, &provaC);
                avaliarAprovacao(calcularMedia2(provaA, provaB, provaC));
                break;
            case 3:
                printf("Digite as notas da Prova A, Prova B e Atividade C: ");
                scanf("%f %f %f", &provaA, &provaB, &atividadeC);
                avaliarAprovacao(calcularMedia3(provaA, provaB, atividadeC));
                break;
            case 4:
                printf("Digite as notas da Prova A, Prova B, Atividade C e Pluridisciplinar: ");
                scanf("%f %f %f %f", &provaA, &provaB, &atividadeC, &pluridisciplinar);
                avaliarAprovacao(calcularMedia4(provaA, provaB, atividadeC, pluridisciplinar));
                break;
            case 5:
                printf("Digite as notas da Prova A, Prova B, Atividades C (3 atividades) e Pluridisciplinar: ");
                scanf("%f %f %f %f %f", &provaA, &provaB, &atividadeC1, &atividadeC2, &atividadeC3, &pluridisciplinar);
                avaliarAprovacao(calcularMedia5(provaA, provaB, atividadeC1, atividadeC2, atividadeC3, pluridisciplinar));
                break;
            case 6:
                printf("Digite as notas da Atividade 1, Prova A, Atividade 2, Pluridisciplinar e Prova B: ");
                scanf("%f %f %f %f %f", &atividadeC1, &provaA, &atividadeC2, &pluridisciplinar, &provaB);
                avaliarAprovacao(calcularMedia6(atividadeC1, provaA, atividadeC2, pluridisciplinar, provaB));
                break;
            case 9:
                printf("Saindo do programa de medias escolares.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 9);

    return 0;
}

