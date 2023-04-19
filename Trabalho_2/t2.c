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

void maiusculo(char* c){
    for (int j = 0; c[j] !='\0'; j++) {
        c[j] = toupper(c[j]);
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
        system("clear");
        m[i].dados = alocar_matriz(d, 3);
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
    int achou;
    for (int i = 0; i < n; i++) {
        if (strcmp(c, m[i].nome) == 0) {
            imprime_mun(m,i,d);
            achou=1;
        } 
    }
    if(achou==0) {
        printf("Município não encontrado.\n");
}

void busca_geral(int n, Municipio *m, int d) {
    for(int i=0;i<n;i++){
        int confirmado=0, obito=0, novo_confirmado=0, novo_obito=0;
        for(int j=0;j<d;j++){
            confirmado += m[i].dados[j][1];
            obito += m[i].dados[j][2];
            if(j==(d-1)) {
                novo_confirmado = m[i].dados[j][1];
                novo_obito = m[i].dados[j][2];
            }
        }
        float incidencia= ((confirmado*100000.0)/m[i].populacao);
        float mortalidade= ((obito*100000.0)/m[i].populacao);
        printf("Nome do municipio: %s\n", m[i].nome);
        printf("Casos confirmados: %d\nNovos confirmados: %d\n", confirmado, novo_confirmado);
        printf("Incidencia/100mil hab: %.2f\n", incidencia);
        printf("Obitos: %d\nNovos obitos: %d\n", obito, novo_obito);
        printf("Mortalidade: %.2f\n\n\n", mortalidade);
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
    int escolha;
    printf("Digite a opção desejada(1- Busca de municipio\t2- Dados Epidemiológicos):\n");
    scanf("%d", &escolha);
    system("clear");
    switch(escolha) {
        case 1:
            getchar();
            busca_mun(n, m, d);
            break;
        case 2:
            getchar();
            busca_geral(n, m, d);
            break;
        default: printf("Comando inválido!\n");
    }

    return 0;
}
