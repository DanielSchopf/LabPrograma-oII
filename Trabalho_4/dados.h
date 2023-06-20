struct lista {
    int id;
    int tempo_chegada;
    int tempo_execucao;
    int tipo;
    struct lista* prox;
};
typedef struct lista Lista;

struct pilha {
    Lista* prim;
};
typedef struct pilha Pilha;


struct fila {
    Lista* ini;
    Lista* fim;
};
typedef struct fila Fila;



Pilha* pilha_cria (void);
void pilha_push (Pilha* p, int id, int tempo_chegada, int tempo_execucao, int tipo);
int pilha_pop (Pilha* p, Fila* f);
int pilha_vazia (Pilha* p);
void pilha_libera (Pilha* p);

Fila* fila_cria (void);
void fila_insere (Fila* f, int id, int tempo_chegada, int tempo_execucao, int tipo);
void fila_retira (Fila* f, int tp, Pilha* p);
void fila_libera (Fila* f);
int fila_vazia(Fila* f);

void fila_insere_ini (Fila* f, int id, int tempo_chegada, int tempo_execucao, int tipo);
Lista* insere_ini (Lista* ini, int id, int tempo_chegada, int tempo_execucao, int tipo);
