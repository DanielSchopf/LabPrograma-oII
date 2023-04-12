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

void ler_mun(int n, Municipio *m, int d) {
    for (int i = 0; i < n; i++) {
        m[i].nome = (char *)malloc(100 + 1);
        printf("Digite o nome da cidade:\n");
        fgets(m[i].nome, 100, stdin);
        m[i].nome[strcspn(m[i].nome, "\n")] = '\0'; // remove o caractere de nova linha
        printf("Digite a populacao de %s:\n", m[i].nome);
        scanf("%d", &m[i].populacao);
        m[i].dados = alocar_matriz(n, d);
        getchar();
    }
}


int main() {
    int n, d;
    printf("Digite o numero de municipios presentes na pesquisa:\n");
    scanf("%d", &n);

    printf("Digite o numero de dias para a tabela de dados");
    scanf("%d", &d);

    getchar();
    Municipio *m = (Municipio *)malloc(n * sizeof(Municipio));
    if (m == NULL) {
        printf("Memoria insuficiente.\n");
    }
    system("cls");

    ler_mun(n, m, d);


    return 0;
}
