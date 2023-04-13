#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct municipio {
    char *nome;
    int populacao;
    int **dados;
};
typedef struct municipio Municipio;


int** alocar_matriz(int n, int d) {
    int** mat;
    mat = (int**)malloc(d*sizeof(int*));
    for(int i=0;i<d;i++) {
        mat[i] = (int*)malloc(3*sizeof(int));
    }
    return mat;
}

void palavra_maiuscula(char c){
    for(int i=0; i<strlen(c);i++){
        c[i] = toupper(c[i]);
    }
}

void ler_mun(int n, Municipio *m, int d) {
    for (int i = 0; i < n; i++) {
        m[i].nome = (char *)malloc(100 + 1);
        printf("Digite o nome da cidade:\n");
        fgets(m[i].nome, 100, stdin);
        m[i].nome[strcspn(m[i].nome, "\n")] = '\0'; // remove o caractere de nova linha
        printf("Digite a populacao de %s:\n", m[i].nome);
        scanf("%d", &m[i].populacao);
        m[i].dados = alocar_matriz(n, 3);
        for (int j = 0; j < d; j++) {
            printf("Digite o dia:\n");
            scanf("%d", &m[i].dados[j][0]);
            printf("Digite a quantidade de casos confirmados no dia:\n");
            scanf("%d", &m[i].dados[j][1]);
            printf("Digite a quantidade de óbitos no dia:\n");
            scanf("%d", &m[i].dados[j][2]);
            system("clear");
        }
        getchar();
    }
}

void imprime_mun(Municipio* m, int i, int d){
        printf("Nome do município: %s\n", m[i].nome);
        printf("População: %d\n", m[i].populacao);
        printf("Dados:\n");
        printf("DIAS\tCASOS CONFIRMADOS\tOBITOS\n");
        for (int j = 0; j < d; j++) {
            printf("%d\t\t%d\t\t%d\n", m[i].dados[j][0], m[i].dados[j][1], m[i].dados[j][2]);
        }
        return;

}

void busca_mun(int n, Municipio *m, int d) {
    char c[100 + 1];
    printf("Digite o nome do município:\n");
    fgets(c, 100, stdin);
    c[strcspn(c, "\n")] = '\0';
    system("clear");
    for (int i = 0; i < n; i++) {
        if (strcmp(c, m[i].nome) == 0) {
            imprime_mun(m,i,d);
        } else {
        printf("Município não encontrado.\n");
        }
    }

}

int main() {
    int n, d;
    printf("Digite o numero de municipios presentes na pesquisa:\n");
    scanf("%d", &n);

    printf("Digite o numero de dias para a tabela de dados:\n");
    scanf("%d", &d);

    getchar();
    Municipio *m = (Municipio *)malloc(n * sizeof(Municipio));
    if (m == NULL) {
        printf("Memoria insuficiente.\n");
    }
    system("cls");

    ler_mun(n, m, d);
    busca_mun(n, m, d);

    return 0;
}
