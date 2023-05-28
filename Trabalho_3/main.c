#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include <stdbool.h>
#include <string.h>

int main() {
    Medico* m;
    Paciente* p;
    Consulta* c;

    m= med_cria();
    p= pac_cria();
    c=consulta_cria();
    
    while(true){
        int escolha;
        printf("Digite a aчуo desejada:\n1- Cadastrar\n2- Agendar consulta \n3- Realizar consulta \n4- Desmarcar consulta \n5- Relatorios\n");
        scanf("%d", &escolha);
        switch(escolha) {
            case 1:
                printf("Escolha o tipo de cadastro(1- Medico 2- Paciente):\n");
                scanf("%d", &escolha);
                system("clear");
                switch(escolha) {
                    case 1: m= ler_medico(m);
                        break;
                    case 2: p= ler_paciente(p);
                        break;
                }
                break;
            case 2:
                c= ler_consulta(c,m,p);
                break;
            case 3:
                c= consultar(c);
                system("clear");
                break;
            case 4:
                c = consulta_remove(c);
                break;
            case 5:
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
