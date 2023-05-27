#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include <stdbool.h>
#include <string.h>

int main() {
    Medico* m;
    Paciente* p;
    Consulta* c;
    Data* d;
    Hora* h;


    m= med_cria();
    p= pac_cria();
    c=consulta_cria();

    Data* d1 = (Data*)malloc(sizeof(Data));
    d1->dia = 01;
    d1->mes = 02;
    d1->ano = 2023;
    Hora* h1 = (Hora*)malloc(sizeof(Hora));
    h1->hora = 14;
    h1->minuto = 0;

    Data* d2 = (Data*)malloc(sizeof(Data));
    d2->dia = 01;
    d2->mes = 02;
    d2->ano = 2023;
    Hora* h2 = (Hora*)malloc(sizeof(Hora));
    h2->hora = 14;
    h2->minuto = 30;

    m= med_insere(m, 01, "Medico A", "Area A", "0001");
    p= pac_insere(p, 02, "Paciente A", "0002");
    c=consulta_insere(c, med_busca(m, 01), pac_busca(p, 02), d1, h1, "convenio 1", 0);
    c=consulta_insere(c, med_busca(m, 01), pac_busca(p, 02), d2, h2, "convenio 2", 0);
    while(true){
        int escolha;
        printf("Digite a ação desejada:\n1- Cadastrar\n2- Agendar consulta \n3- Realizar consulta \n4- Relatorios\n");
        scanf("%d", &escolha);
        switch(escolha) {
            case 1:
                cadastrar(m, p);
                break;
            case 2:
                c= ler_consulta(c,m,p);
                break;
            case 3:
                c= consultar(c);
                system("clear");
                break;
            case 4:
                relatorio(c, m, p);
                break;
            default:
                break;
        }


        int a;
        printf("Digite 0 para finalizar e 1 para continuar: ");
        scanf("%d", &a);
        if(a==0){
            break;
        }
    }
}
