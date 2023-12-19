#include <stdio.h>

struct Aluno {
    char RA[10];
    double NOTA1;
    double NOTA2;
    double NOTAPLURI;
    double media;
};

int main() {
    int i, j;
    struct Aluno alunos[3];
    double mediaGeral = 0.0;
    int aprovados = 0;
    int reprovados = 0;
    
    for (i = 0; i < 3; i++) {
        printf("Digite o RA do aluno %d: ", i + 1);
        scanf("%s", alunos[i].RA);
        printf("Digite a NOTA1 do aluno %d: ", i + 1);
        scanf("%lf", &alunos[i].NOTA1);
        printf("Digite a NOTA2 do aluno %d: ", i + 1);
        scanf("%lf", &alunos[i].NOTA2);
        printf("Digite a NOTAPLURI do aluno %d: ", i + 1);
        scanf("%lf", &alunos[i].NOTAPLURI);
        
        alunos[i].media = (0.3 * alunos[i].NOTA1) + (0.4 * alunos[i].NOTA2) + (0.3 * alunos[i].NOTAPLURI);
        
        mediaGeral += alunos[i].media;
        
        if (alunos[i].media >= 7.0) {
            printf("Aluno %s: APROVADO\n", alunos[i].RA);
            aprovados++;
        } else {
            printf("Aluno %s: REPROVADO\n", alunos[i].RA);
            reprovados++;
        }
    }
    
    mediaGeral /= 3.0;
    
    printf("\nMédia geral das notas dos alunos: %.2lf\n", mediaGeral);
    printf("Quantidade de alunos aprovados: %d\n", aprovados);
    printf("Quantidade de alunos reprovados: %d\n", reprovados);
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2 - i; j++) {
            if (alunos[j].media > alunos[j + 1].media) {
                struct Aluno temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
    
    printf("\nAlunos ordenados por média (do menor para o maior):\n");
    for (i = 0; i < 3; i++) {
        printf("RA: %s, Média: %.2lf\n", alunos[i].RA, alunos[i].media);
    }
    
    return 0;
}
