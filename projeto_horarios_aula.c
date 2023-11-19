#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "horario.h"
#include "professor.h"
#include "diciplina.h"
#include "relatorio.h"
// Assinatura das funções
void menu_principal(void);
void menu_sobre(void);
void menu_equipe(void);

// Programa principal
int main(void)
{
    char opc;
    do{
        menu_principal();
        printf("\nDigite o que deseja fazer: ");
        fflush(stdin);
        scanf("%c", &opc);
        getchar();
        fflush(stdin);
        switch (opc){
            case '1':
                menu_aluno();
                break;
            case '2':
                menu_professor();
                break;
            case '3':
                menu_horario();
                break;
            case '4':
                menu_diciplinas();
                break;
            case '5':
                escolha_relatorio();
                break;
            case '6':
                menu_equipe();
                break;
            case '7':
                menu_sobre();
                break;
            case '0':
                printf("\nPrograma Finalizado!\n");
                break;
            default:
                printf("\nOpção Inválida!\n");
                printf("Digite enter para continuar...");
                fflush(stdin);
                getchar();
                break;
        }
    } while (opc != '0');
    return 0;
}

void menu_principal(){
    printf("\n");
    system("clear||cls");
    printf("\033[34m             ####\033[0m     \033[31m####\033[0m    \033[37m######\033[0m               \n"); // feito com a ajuda do chat gpt
    printf("\033[34m            ##  ##\033[0m   \033[31m##  ##\033[0m     \033[37m##\033[0m                 \n");
    printf("\033[34m            ##\033[0m       \033[31m##\033[0m         \033[37m##\033[0m                 \n");
    printf("\033[34m            ##\033[0m        \033[31m####\033[0m      \033[37m##\033[0m                 \n");
    printf("\033[34m            ##\033[0m           \033[31m##\033[0m     \033[37m##\033[0m                 \n");
    printf("\033[34m            ##  ##\033[0m   \033[31m##  ##\033[0m     \033[37m##\033[0m                 \n");
    printf("\033[34m             ####\033[0m     \033[31m####\033[0m      \033[37m##\033[0m                 \n\n");
    printf("           COLÉGIO SABER E TALENTO                \n\n");
    printf(" Preocupados em ensinar da melhor forma possível! \n\n");
    printf("===================================================\n");
    printf("   ************* Menu principal ***************    \n");
    printf("            1 - Gestão de alunos                   \n");
    printf("            2 - Gestão de professores              \n");
    printf("            3 - Gestão de Horários                 \n");
    printf("            4 - Gestão de Diciplinas              \n");
    printf("            5 - Menu Relatório                    \n");
    printf("            6 - Sobre a Equipe                    \n");
    printf("            7 - Sobre o Projeto                   \n");
    printf("            0 - Finalizar programa                \n");
    printf("                                                  \n");
}

void menu_sobre(void){
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("              Universidade Federal do Rio Grande do Norte (UFRN)                 \n");
    printf("                   Centro de Ensino Superior do Seridó                           \n");
    printf("                Departamento de Computação e Tecnologia                          \n");
    printf("                    Disciplina DCT1106 -- Programação                            \n");
    printf("                    Projeto controle de horários de aula                         \n");
    printf("                Desenvolvido por Matheus Diniz Fernandes                         \n");
    printf("=================================================================================\n");
    printf("                                                                                 \n");
    printf("            ********* Gestão de Horário de aula *********                        \n");
    printf("                                                                                 \n");
    printf("  Projeto realizado para a diciplina de programação a qual buscar incoporar      \n");
    printf("  os principais módulos para uma gestão de horário de aula, sendo eles alunos,   \n");
    printf("  professores e horários de aula.                                                \n");
    printf("                                                                                 \n");
    printf("=================================================================================\n");
    printf("Digite enter para continuar...");
    getchar();
}



void menu_equipe(void){
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("                                                                         \n");
    printf("            ********* Sistema de Gestão Escolar **********               \n");
    printf("                                                                         \n");
    printf("            Este projeto foi desenvolvido por;                           \n");
    printf("                                                                         \n");
    printf("            Aluno:Matheus Diniz Fernandes                                \n");
    printf("            E-mail:matheusdiniz870@gmail.com                             \n");
    printf("            Redes sociais: @matheus_dnz                                  \n");
    printf("            Git: Matheusdnf                                              \n");
    printf("                                                                         \n");
    printf("===========================================================================\n");
    printf("Digite enter para continuar...");
    getchar();
}

