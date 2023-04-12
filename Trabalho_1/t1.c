#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>

struct pessoa {
    int codigo;
    char nome[81];
    char endereco[81];
    float peso;
    int altura;
    char sexo;
    float salario;
};
typedef struct pessoa Pessoa;

void relatorio_pessoas(int n, Pessoa pessoas[n]) {

    for(int i=0;i<n;i++) {
        printf("Codigo pessoa %d: %d\n", i+1, pessoas[i].codigo);
        printf("Nome pessoa %d: %s\n", i+1, pessoas[i].nome);
        printf("Endereço pessoa %d: %s\n", i+1, pessoas[i].endereco);
        printf("Peso pessoa %d: %f\n", i+1, pessoas[i].peso);
        printf("Altura pessoa %d: %d\n", i+1, pessoas[i].altura);
        printf("Sexo pessoa %d: %c\n", i+1, pessoas[i].sexo);
        printf("Salario pessoa %d: %f\n", i+1, pessoas[i].salario);
    }

}

void relatorio_mulheres_peso(int n, Pessoa pessoas[n]) {
    float contador=0;
    float soma=0, media;

    for(int i=0;i<n;i++) {
        if(toupper(pessoas[i].sexo) == 'F') {
            soma += pessoas[i].peso;
            contador++;
        }
    }
    media = soma/contador;

    printf("A media de peso das mulheres é: %.1fkg", media);
}


void relatorio_homens_salario(int n, Pessoa pessoas[n]) {
    int contador=0;
    float soma=0, media;
    for(int i=0;i<n;i++) {
        if(toupper(pessoas[i].sexo) == 'M') {
            soma += pessoas[i].salario;
            contador++;
        }
    }
    media = soma/contador;

    printf("A media salarial dos homens é: %.2f", media);
}


void relatorio_imc(int n, Pessoa pessoas[n]) {
    float imc;
    float altura;
    for(int i=0;i<n;i++) {
        altura= (float)pessoas[i].altura/100;
        imc = (pessoas[i].peso/(altura*altura));
        printf("IMC %s: %.2f\n", pessoas[i].nome, imc);
    }
}

void relatorio_mais_alto(int n, Pessoa pessoas[n]) {
    int mais_alto=0;
    for(int i=0;i<n;i++) {
        if(pessoas[i].altura >= mais_alto) {
            mais_alto = pessoas[i].altura;
        }
    }
    for(int i=0;i<n;i++) {
        if(pessoas[i].altura == mais_alto) {
            printf("A pessoa mais alta é: %s - %.2f metros\n", pessoas[i].nome, (float)pessoas[i].altura/100);
        }
    }

}

void relatorio_mais_baixo(int n, Pessoa pessoas[n]) {
    int mais_baixo=pessoas[0].altura;
    for(int i=0;i<n;i++) {
        if(pessoas[i].altura <= mais_baixo) {
            mais_baixo = pessoas[i].altura;
        }
    }
    for(int i=0;i<n;i++) {
        if(pessoas[i].altura == mais_baixo) {
            printf("O código da pessoa mais baixa é: %d - %.2f metros\n", pessoas[i].codigo, (float)pessoas[i].altura/100);
        }
    }

}

void relatorio_salario_acima(int n, Pessoa pessoas[n]) {
    float media, soma=0;
    int contador=0;
    for(int i=0;i<n;i++) {
        soma+=pessoas[i].salario;
    }
    media = soma/n;
    for(int i=0;i<n;i++) {
        if(pessoas[i].salario > media) {
            contador++;
        }
    }

    printf("%d pessoas recebem o salário acima da média", contador);

}

void relatorio_peso_abaixoF(int n, Pessoa pessoas[n]) {
    float media, soma=0;
    int contador=0, contador2=0;
    for(int i=0;i<n;i++) {
        if(toupper(pessoas[i].sexo) == 'F') {
            soma+=pessoas[i].peso;
            contador++;
        }
    }
    media = soma/contador;
    for(int i=0;i<n;i++) {
        if(toupper(pessoas[i].sexo) == 'F') {
            if(pessoas[i].peso < media){
                contador2++;
            }
        }
    }

    printf("%d mulheres com peso abaixo da média", contador2);

}

void relatorio_menos1000(int n, Pessoa pessoas[n]) {
    for(int i=0;i<n;i++) {
        if(pessoas[i].salario < 1000){
            printf("Nome: %s\nEndereço: %s\n\n", pessoas[i].nome, pessoas[i].endereco);
        }
    }

}


void preencher_vetor(int n, Pessoa pessoas[n]) {
    for(int i=0;i<n;i++) {
        printf("Insira o código da pessoa %d: ", i+1);
        scanf("%d", &pessoas[i].codigo);
        fflush(stdin);
        printf("Insira o nome da pessoa %d: ", i+1);
        scanf("%s", pessoas[i].nome);
        fflush(stdin);
        printf("Insira o endereço da pessoa %d: ", i+1);
        scanf("%s", pessoas[i].endereco);
        fflush(stdin);
        printf("Insira o peso da pessoa %d: ", i+1);
        scanf("%f", &pessoas[i].peso);
        fflush(stdin);
        printf("Insira a altura da pessoa %d: ", i+1);
        scanf("%d", &pessoas[i].altura);
        fflush(stdin);
        printf("Insira o sexo da pessoa %d: ", i+1);
        scanf(" %c", &pessoas[i].sexo);
        while(toupper(pessoas[i].sexo) != 'F' && toupper(pessoas[i].sexo) != 'M' && toupper(pessoas[i].sexo) != 'O') {
            printf("Valor inválido, insira novamente (M, F ou O): ");
            scanf(" %c", &pessoas[i].sexo);
        }
        fflush(stdin);
        printf("Insira o salario da pessoa %d: ", i+1);
        scanf("%f", &pessoas[i].salario);
        fflush(stdin);
        printf("\n");

    }
}

int main() {

    setlocale(LC_ALL, "portuguese");

    int n, c=0;

    printf("Insira o número de pessoas: ");
    scanf("%d", &n);



    Pessoa pessoas[n];

    preencher_vetor(n, pessoas);
    system("clear");

    while(c==0) {
        int relatorio;
        printf("Insira o número do relatório desejado:\n1 - Relatório Geral\n2 - A média de peso das mulheres\n3 - A média de salário dos homens\n4 - O IMC de todas as pessoas\n5 - O nome da pessoa mais alta\n6 - O código da pessoa mais baixa\n7 - A quantidade de pessoas que ganham salário acima da media\n8 - A quantidade de pessoas do sexo feminino abaixo da media de peso das pessoas do sexo feminino\n9 - Nome e endereço das pessoas que ganham menos que R$1000,00\n");
        scanf("%d", &relatorio);
        system("clear");
        switch(relatorio) {
            case 1:
                relatorio_pessoas(n,pessoas);
                break;
            case 2:
                relatorio_mulheres_peso(n,pessoas);
                break;
            case 3:
                relatorio_homens_salario(n,pessoas);
                break;
            case 4:
                relatorio_imc(n,pessoas);
                break;
            case 5:
                relatorio_mais_alto(n,pessoas);
                break;
            case 6:
                relatorio_mais_baixo(n,pessoas);
                break;
            case 7:
                relatorio_salario_acima(n,pessoas);
                break;
            case 8:
                relatorio_peso_abaixoF(n,pessoas);
                break;
            case 9:
                relatorio_menos1000(n, pessoas);
                break;
            default:
                printf("Código inválido");
        }
        printf("\n\nDeseja continuar? (0 para continuar | 1 para encerrar)\n");
        scanf("%d", &c);
        system("clear");

    }

    return 0;
}
