#include <stdbool.h>

struct data {
    int dia;
    int mes;
    int ano;
};
typedef struct data Data;

struct hora {
    int hora;
    int minuto;
};
typedef struct hora Hora;

Data* ler_data();
Hora* ler_hora();

struct medico {
    int crm;
    char nome[80];
    char area[100];
    char telefone[20];
    struct medico* prox;
};
typedef struct medico Medico;

Medico *med_cria(void);
Medico *med_insere(Medico* m, int crm, char nome[80], char area[100], char telefone[20]);
Medico *med_busca(Medico* m, int crm);
void med_imprime(Medico* m);
int med_vazio(Medico* m);
Medico* ler_medico(Medico* m);


struct paciente {
    int cpf;
    char nome[80];
    char telefone[20];
    struct paciente* prox;
};
typedef struct paciente Paciente;


Paciente *pac_cria(void);
Paciente *pac_insere(Paciente* p, int cpf, char nome[80], char telefone[20]);
Paciente *pac_busca(Paciente* p, int cpf);
void pac_imprime(Paciente* p);
int pac_vazio(Paciente* p);
Paciente* ler_paciente(Paciente* p);

struct consulta {
    Medico* m;
    Paciente* p;
    Data* d;
    Hora* h;
    char convenio[80];
    int flag;
    struct consulta* prox;

};
typedef struct consulta Consulta;

Consulta *consulta_cria(void);
Consulta *consulta_insere(Consulta* c, Medico* m, Paciente* p, Data* d, Hora* h, char convenio[80], int flag);
void consulta_imprime(Consulta* c);
int consulta_vazio(Consulta* c);
Consulta* ler_consulta(Consulta* c, Medico* m, Paciente* p);
bool consulta_busca(Consulta* c, Medico* m, Paciente* p, Data* d, Hora* h);


void cadastrar(Medico* m, Paciente* p);
void relatorio(Consulta* c, Medico* m, Paciente* p);

