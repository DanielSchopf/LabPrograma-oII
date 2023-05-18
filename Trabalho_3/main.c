#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "menu.h"
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

    m= med_insere(m, 01, "Medico A", "Area A", "0001");
    p= pac_insere(p, 02, "Paciente A", "0002");
    while(true){
        int escolha;
        printf("Digite a ação desejada:\n1- Cadastrar\n2- Agendar consulta \n3- Relatorios\n");
        scanf("%d", &escolha);
        switch(escolha) {
            case 1:
                cadastrar(m, p);
                break;
            case 2:
                c = ler_consulta(c,m,p);
                break;
            case 3:
                relatorio(c, m, p);
                break;
            default:
                break;
        }

        consulta_imprime(c);

        int a;
        printf("Digite 0 para finalizar e 1 para continuar: ");
        scanf("%d", &a);
        if(a==0){
            break;
        }
    }


}
