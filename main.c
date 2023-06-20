#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include <stdbool.h>
#include <string.h>

int main()
{
    int tp, escolha;
    Fila* f = fila_cria();
    Pilha* p = pilha_cria();
    ler_processos(f);
    printf("Insira o tempo de processo TP: \n");
    scanf("%d", &tp);
    while(true){
        printf("Digite 1 para executar um processo (0 para encerrar): \n");
        scanf("%d", &escolha);
        if(escolha==1){
            fila_retira(f, tp, p);
        }
    }

}


