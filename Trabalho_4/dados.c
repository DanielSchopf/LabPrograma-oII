#include "dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void fila_insere_ini (Fila* f, int id, int tempo_chegada, int tempo_execucao, int tipo){
    f->ini = insere_ini(f->ini,id, tempo_chegada, tempo_execucao, tipo);
    if (f->fim==NULL){
        f->fim = f->ini;
    }
}

Lista* insere_ini(Lista* ini, int id, int tempo_chegada, int tempo_execucao, int tipo) {
    Lista* p = (Lista*)malloc(sizeof(Lista));
    p->id = id;
    p->tempo_chegada = tempo_chegada;
    p->tempo_execucao = tempo_execucao;
    p->tipo = tipo;
    p->prox = ini;

    return p;
}

void ler_processos(Fila* f){
    int id, tempo_execucao, tipo, t=1, escolha;
    while(true){
        printf("ID do processo (Int): \n");
        scanf("%d", &id);
        printf("Tempo de chegada: %d \n", t);
        printf("Tempo de execucao: \n");
        scanf("%d", &tempo_execucao);
        while(true){
            printf("Tipo do processo (0-Sistema/1-Usuario): \n");
            scanf("%d", &tipo);
            if(tipo==0 || tipo==1){
                break;
            }
            printf("Valor invalido, digite novamente\n");
        }
        fila_insere(f, id, t, tempo_execucao, tipo);
        printf("Deseja continuar? (0-Não/1-Sim): \n");
        scanf("%d", &escolha);
        if(escolha==0){
            break;
        }
        t++;
    }

}

Pilha* pilha_cria (void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

void pilha_push (Pilha* p, int id, int tempo_chegada, int tempo_execucao, int tipo) {
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->id = id;
    n->tempo_chegada = tempo_chegada;
    n->tempo_execucao = tempo_execucao;
    n->tipo = tipo;
    n->prox = p->prim;
    p->prim = n;
}

int pilha_vazia (Pilha* p) {
    return (p->prim==NULL);
}

int pilha_pop (Pilha* p, Fila* f) {
    Lista* t;

    t = p->prim;
    fila_insere_ini(f, t->id, t->tempo_chegada, t->tempo_execucao, t->tipo);
    p->prim = t->prox;
    free(t);
    return 1;
}

void pilha_imprime(Pilha* p) {
    Lista* pt;

    printf("Pilha: ");
    for (pt = p->prim; pt != NULL; pt = pt->prox) {
        printf("%d, ", pt->id);
    }
    printf("\n");
}



void pilha_libera (Pilha* p) {
    Lista* q = p->prim;
    while (q!=NULL) {
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}



Fila* fila_cria (void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void fila_insere (Fila* f, int id, int tempo_chegada, int tempo_execucao, int tipo) {
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->id = id;
    n->tempo_chegada = tempo_chegada;
    n->tempo_execucao = tempo_execucao;
    n->tipo = tipo;
    n->prox = NULL;
    if (f->fim != NULL) {
        f->fim->prox = n;
    }
    else {
        f->ini = n;
    }
    f->fim = n;
}

void fila_retira (Fila* f, int tp, Pilha* p) {
    Lista* t;
    Lista* pt;
    Lista* l;
    Lista* aux;
    int tempo_execucao;
    if (fila_vazia(f)) {
        printf("Fila vazia.\n");
        exit(1);
    }

    int k = 0;
    for (pt = f->ini; pt != NULL; pt = pt->prox) {
        if (pt->tipo == 0) {
            l = f->ini;
            for (l = f->ini; l != pt; l = l->prox){
                aux = l;
                pilha_push(p, aux->id, aux->tempo_chegada, aux->tempo_execucao, aux->tipo);
                k++;
                free(aux);
                f->ini = l->prox;
            }
            break;
        }
    }


    t = f->ini;
    f->ini = t->prox;
    if (f->ini == NULL){
        f->fim = NULL;
    }



    pilha_imprime(p);

    if(t->tempo_execucao > tp){
        printf("\nProcesso: %d (%d) executado (Tipo: %d)\n\n", t->id, tp, t->tipo);
        tempo_execucao = t->tempo_execucao - tp;
        fila_insere(f, t->id, (f->fim->tempo_chegada)+1, tempo_execucao, t->tipo);
    }
    else{
        printf("\nProcesso: %d (%d) executado (Tipo: %d)\n\n", t->id, t->tempo_execucao, t->tipo);
    }

    for(int i=0;i<k;i++){
        pilha_pop(p, f);
    }




    free(t);


}

void fila_libera (Fila* f) {
    Lista* q = f->ini;
    while (q!=NULL) {
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

int fila_vazia (Fila* f) {
    return (f->ini==NULL);
}



