#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//
// Assinatura das fun  es
void menu_principal(void);
void menu_sobre(void);
void menu_equipe(void);
void menu_aluno(void);
void cadastrar_aluno(void);
void buscar_aluno(void);
void atualizar_aluno(void);
void excluir_aluno(void);
void relatorio_aluno(void);
void menu_horario(void);
void cadastrar_horario(void);
void buscar_horario(void);
void atualizar_horario(void);
void excluir_horario(void);
void relatorio_horario(void);
void menu_professor(void);
void cadastrar_professor(void);
void buscar_professor(void);
void atualizar_professor(void);
void excluir_professor(void);
void relatorio_professor(void);

//variáveis 
char opc;
int iniciar = 1;
// Programa principal
int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    while ( iniciar == 1){
        menu_principal();
        printf("\nDigite o que deseja fazer: "); scanf("%1s", &opc); getchar();
        switch (opc) { 
            case '1':
                menu_aluno();
                break;
            case '2':
                menu_horario();
                break;
            case '3':
                menu_professor();
                break;
            case '4':
                menu_equipe();
                break;
            case '5':
                menu_sobre();
                break;
            case '0':
                printf("\nPrograma Finalizado");
                iniciar = 0;
                break;
            default:
                printf("\nOpção Inválida!");
                printf("\n");
                system("pause");
                break;
        }
    }
    return 0;
}

// Funções


void menu_principal() {
    system("clear||cls");
    printf("\n");
    printf("===================================================\n");
    printf("             ####     ####    ######               \n");
    printf("            ##  ##   ##  ##     ##                 \n");
    printf("            ##       ##         ##                 \n");
    printf("            ##        ####      ##                 \n");
    printf("            ##           ##     ##                 \n");
    printf("            ##  ##   ##  ##     ##                 \n");
    printf("             ####     ####      ##                 \n\n");
    printf("           COLÉGIO SABER É DIVERSÃO               \n\n");
    printf(" Preocupados em ensinar da melhor forma possível! \n\n");
    printf("===================================================\n");
    printf("   ************* Menu principal ***************    \n");
    printf("            1 - Gestão de alunos                   \n");
    printf("            2 - Gestão de Horários                 \n");
    printf("            3 - Gestão de professores              \n");
    printf("            4 - Sobre a Equipe                      \n");
    printf("            5 - Sobre o Projeto                    \n");
    printf("            0 - Finalizar programa                 \n");
    printf("                                                   \n");
}


void menu_sobre(void) {
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
    printf("=================================================================================\n");
    system("pause");
}


void menu_equipe(void) {
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
    system("pause");
} 


void menu_aluno(void) {
    while (opc!=0){
        system("clear||cls");   
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Aluno ******************       \n");
        printf("          1 - Cadastrar aluno                              \n");
        printf("          2 - Pesquisar aluno                              \n");
        printf("          3 - Atualizar informações do aluno               \n");
        printf("          4 - Excluir aluno                                \n");
        printf("          5 - Relatório dos alunos                         \n");
        printf("          0 - Voltar                                       \n");
        printf("===========================================================\n");
        printf("\n");
        printf("Escolha uma das opções:");
        scanf("%s",&opc);
        switch (opc){
        case '1':
            cadastrar_aluno();
            break;
        case '2':
            buscar_aluno();
            break;
        case '3':
            atualizar_aluno();
            break;
        case '4':
            excluir_aluno();
            break;
        case '5':
            relatorio_aluno();
            break;
        case '0':
            opc=0;
        default:
            break;
            printf("Opção Inválida!\n");
            system("pause");
            break;
        }
    }
}

void cadastrar_aluno(void) {
    system("clear||cls");   //aqui será onde irá cadastrar um aluno que estuda na escola
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Cadastrar Aluno *************     \n\n");
    printf("         CPF (apenas números):                          \n");
    printf("         Nome completo:                                 \n");
    printf("         E-mail:                                        \n");
    printf("         Celular (apenas números):                      \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    system("pause");
}


void buscar_aluno(void) {
    system("clear||cls");
    printf("\n");   //quando o usuário informar o cpf do aluno irá mostrar os dados atrelados a aquelas pessoa,planejo implementar um menu que de outras opções de procura
    printf("========================================================\n");
    printf("    *************** Pesquisar Aluno *************     \n\n");
    printf("                                                        \n");
    printf("            Informe o CPF(apenas números):              \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    system("pause");
}

void atualizar_aluno(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Aluno *************     \n\n");
    printf("                                                        \n");
    printf("            Informe o CPF(apenas números):              \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    system("pause");
}


void excluir_aluno(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Aluno *************       \n\n");
    printf("                                                        \n");
    printf("            Informe o CPF(apenas números):              \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    system("pause");
}

void relatorio_aluno(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Relatório Aluno *************       \n\n");
    printf("                                                        \n");
    printf("       (informar todos os alunos cadastrado)            \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    system("pause");
}

void menu_horario(void) {
    while (opc!=0){
        system("clear||cls");   
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Horários ******************   \n");
        printf("          1 - Cadastrar Horário                          \n");
        printf("          2 - Pesquisar Horário                          \n");
        printf("          3 - Atualizar Horário                          \n");
        printf("          4 - Excluir Horário                            \n");
        printf("          5 - Relatório dos Horários                     \n");
        printf("          0 - Voltar                                     \n");
        printf("===========================================================\n");
        printf("\n");
        printf("Escolha uma das opções:");
        scanf("%s",&opc);
        switch (opc){
            case '1':
                cadastrar_horario();
                break;
            case '2':
                buscar_horario();
                break;
            case '3':
                atualizar_horario();
                break;
            case '4':
                excluir_horario();
                break;
            case '5':
                relatorio_horario();
                break;
            case '0':
                opc=0;
            default:
                break;
                printf("Opção Inválida!\n");
                system("pause");
                break;
        }
    }
}

void cadastrar_horario(void) {
    system("clear||cls");
    printf("========================================================\n");
    printf(" **************** Cadastrar Horário ******************  \n\n");
    printf("     Digite os dias da semana:                          \n");
    printf("     Digite o Período do Dia:                           \n");
    printf("     Digite o horário:                                  \n");
    printf("     Nome da diciplina:                                 \n\n");
    printf("========================================================\n");
    system("pause");
}

void buscar_horario(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Pesquisar Horário *************   \n\n");
    printf("                                                        \n");
    printf("          Informe a matéria:                            \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    system("pause");
}


void atualizar_horario(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Horário *************   \n\n");
    printf("                                                        \n");
    printf("          Informe a matéria:                            \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    system("pause");
}


void excluir_horario(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Horário *************     \n\n");
    printf("                                                        \n");
    printf("          Informe a matéria:                            \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    system("pause");
}

void relatorio_horario(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("   *************** Relatório dos Horários ************* \n\n");
    printf("                                                        \n");
    printf("       (informar todos os Professores cadastrado)       \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    system("pause");
}


void menu_professor(void) {
    while (opc!=0){
        system("clear||cls");   
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Professor ******************   \n");
        printf("          1 - Cadastrar Professor                          \n");
        printf("          2 - Pesquisar Professor                          \n");
        printf("          3 - Atualizar informações do Professor           \n");
        printf("          4 - Excluir Professor                            \n");
        printf("          5 - Relatório dos Professores                    \n");
        printf("          0 - Voltar                                       \n");
        printf("===========================================================\n");
        printf("\n");
        printf("Escolha uma das opções:");
        scanf("%s",&opc);
        switch (opc){
            case '1':
                cadastrar_professor();
                break;
            case '2':
                buscar_professor();
                break;
            case '3':
                atualizar_professor();
                break;
            case '4':
                excluir_professor();
                break;
            case '5':
                relatorio_professor();
                break;
            case '0':
                opc=0;
            default:
                break;
                printf("Opção Inválida!\n");
                system("pause");
                break;
        }
    }
}

void cadastrar_professor(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n\n");
    printf("   *************** Cadastrar Professor ***************  \n\n");
    printf("         CPF (apenas números):                            \n");
    printf("         Nome completo:                                   \n");
    printf("         E-mail:                                          \n");
    printf("         Celular (apenas números):                        \n");
    printf("         Matéria Lecionada:                              \n\n");
    printf("=========================================================\n");
    printf("\n");
    system("pause");
}

void buscar_professor(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Buscar Professor *************    \n\n");
    printf("                                                        \n");
    printf("            Informe o CPF(apenas números):              \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    system("pause");
}


void atualizar_professor(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Professor *************   \n\n");
    printf("                                                        \n");
    printf("            Informe o CPF(apenas números):              \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    system("pause");
}


void excluir_professor(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Professor *************     \n\n");
    printf("                                                        \n");
    printf("            Informe o CPF(apenas números):              \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    system("pause");
}

void relatorio_professor(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("   *************** Relatório Professor *************  \n\n");
    printf("                                                        \n");
    printf("       (informar todos os Professores cadastrado)       \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    system("pause");
}