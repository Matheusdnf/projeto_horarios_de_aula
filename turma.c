#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "valida.h"
#include "turma.h"

//código turms  6A
//nome da turma pequenas pragas

void menu_turma(void){
    int opc=-1;
    do{
        opc=-1;
        system("clear||cls");
        Turma* t; //t-turma
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Turma ******************       \n");
        printf("          1 - Cadastrar Turma                              \n");
        printf("          2 - Pesquisar Turma                              \n");
        printf("          3 - Atualizar informações da Turma               \n");
        printf("          4 - Excluir Turma                                \n");
        printf("          5 - Relatório da Turma                         \n");
        printf("          0 - Voltar                                       \n");
        printf("===========================================================\n");
        printf("\nDigite o que deseja fazer: ");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                t=cadastrar_turma();
                gravar_turma(t);
                break;
            case 2:
                buscar_turma();
                break;
            case 3:
                atualizar_turma();
                break;
            case 4:
                excluir_turma();
                break;
            case 5:
                relatorio_turma();
                break;
            case 0:
                break;
            default:
                printf("Opção Inválida!\n");
                printf("Digite enter para continuar...");
                getchar();
                break;
        }
    } while (opc != 0);
}

Turma *cadastrar_turma(void){
    system("clear||cls");
    Turma* t; //t-turm
    t = (Turma *)malloc(sizeof(Turma));
    printf("\n");
    printf("========================================================\n");
    printf("    ************* Cadastrar Turma *************     \n\n");
    ler_turma(t->cod);
    ler_nome(t->nome);
    t->status = 'A';
    printf("                                                        \n");
    printf("Dados da Turma cadastrada!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar(); // para aparecer o menu e ele não sair rapidamente
    return t;
    free(t);
}

void buscar_turma(void){
    system("clear||cls");
    char cpf[15];
    printf("\n");  
    printf("========================================================\n");
    printf("    *************** Pesquisar Turma *************     \n\n");
    printf("                                                        \n");
    ler_cpf(cpf);
    procura_turma(cpf);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void atualizar_turma(void){
    system("clear||cls");
    char cpf[15];
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Turma *************     \n\n");
    printf("                                                        \n");
    printf("      Informe o código da Turma que será atualizada     \n");
    printf("                                                        \n");
    ler_cpf(cpf);
    printf("                                                        \n");
    att_turma(cpf);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void excluir_turma(){
    system("clear||cls");
    char cpf[15];
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Turma *************       \n\n");
    printf("                                                        \n");
    ler_cpf(cpf);
    remover_turma(cpf);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void relatorio_turma(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Relatório Turma *************       \n\n");
    printf("                                                        \n");
    printf("(informar todas as Turmas cadastradas)                   \n");
    listar_todos_turma();
    printf("========================================================\n");
    printf("\n");
    getchar();
    printf("Digite enter para continuar...");
    getchar();
}
void gravar_turma(Turma *t){
    FILE *ft; // File Turma
    ft = fopen("Turma.dat", "ab");
    if (ft == NULL){
        printf("Erro na recuperação dos dados do Turma!\n");
        return;
    }
    fwrite(t, sizeof(Turma), 1, ft);
    fclose(ft);
    free(t);
}



void exibicao_turma(Turma *t){
    char estado[17];
    if ((t == NULL) || (t->status == 'I')){
        printf("\nEsta Turma não existe no sistema!\n");
    }
    else{
        printf("\n********Dados Da Turma********");
        printf("\nCódigo da Turma:%s", t->cod);
        printf("\nNome da Turma:%s\n", t->nome);
        if (t->status == 'A'){
            strcpy(estado, "Turma ativa");
        }
        else if (t->status == 'I'){
            strcpy(estado, "Turma Fechada");
        }
    }
}

void listar_todas_turma(void){
    FILE *ft;
    Turma *t;
    t = (Turma*)malloc(sizeof(Turma));
    ft = fopen("Turma.dat", "rb");
    if (ft == NULL){
        printf("\nNenhuma Turma cadastrada!\n");
        return;
    }
    while (fread(t, sizeof(Turma), 1, ft)){
        if (t->status != 'I'){
            exibicao_turma(t);
        }
    }
    fclose(ft);
    free(t);
}

// feito com a ajuda de marlison silva
void procura_turma(char *cod){
    FILE *ft;
    Turma *t;
    t = (Turma *)malloc(sizeof(Turma));
    ft = fopen("Turma.dat", "rb");
    if (t == NULL){
        printf("\tTurma não encontrada!\n");
        return;
    }
    if (ft == NULL){
        printf("\nNenhuma Turma cadastrada!\n");
        return;
    }
    while (fread(t, sizeof(Turma), 1, ft)){
        if ((strcmp(t->cod, cod) == 0) && (t->status == 'A')){
            exibicao_turma(t);
        }
    }
    fclose(ft);
    free(t);
}

// feito com a ajuda de marlison silva chat gpt e adapatada por matheus diniz

void remover_turma(char *cod){
    FILE *ft;
    Turma *t;
    int encontra = 0;
    t = (Turma *)malloc(sizeof(Turma));
    ft = fopen("Turma.dat", "r+b");
    if (ft == NULL){
        printf("\nNenhuma Turma foi cadastrada!\n");
        return;
    }
    while (fread(t, sizeof(Turma), 1, ft)){
        if ((strcmp(t->cod, cod) == 0) && (t->status == 'A')){
            encontra = 1;
            t->status = 'I';
            fseek(ft, -1 * (long)sizeof(Turma), SEEK_CUR);
            fwrite(t, sizeof(Turma), 1, ft);
            printf("\nTurma excluída!\n");
            break; // Encerre o loop após a exclusão
        }
    }
    if (!encontra){
        printf("\nTurma não encontrada!\n");
    }
    fclose(ft);
}

void att_turma(char *cod){
    FILE *ft;
    Turma *t;
    int encontra = 0;
    int esc=-1;
    t = (Turma *)malloc(sizeof(Turma));
    ft = fopen("Turma.dat", "r+b");
    if (ft == NULL){
        printf("\nNenhuma Turma cadastrada!\n");
        return;
    }
    while (fread(t, sizeof(Turma), 1, ft)){
        if ((strcmp(t->cod, cod) == 0) && (t->status == 'A')){
            encontra = 1;
            do{
                system("clear||cls");
                printf("========================================================\n");
                printf("   *************** Atualizar Turma ***************      \n");
                printf("                                                        \n");
                printf("               o que deseja atualizar?                  \n");
                printf(" Nome da turma[\033[31m2\033[0m] - Voltar[\033[31m0\033[0m]    \n");
                printf("                                                        \n");
                printf("Dados cadastrados no sistema:\n");
                printf("Código da Turma:%s\n", t->cod);
                printf("Nome da turuma:%s\n", t->nome);
                printf("========================================================\n");
                printf("\n");
                printf("Qual opção deseja atualizar:");
                fflush(stdin);
                scanf("%d", &esc);
                fflush(stdin);
                getchar();
                switch (esc){
                    case 1:
                        ler_nome(t->nome);
                        printf("\nAlteração realizada!\n");
                        printf("\nDigite enter para continuar...");
                        getchar();
                        break;
                    case 0:
                        break;
                    default:
                        printf("\nOpção Inválida!\n");
                        printf("Digite enter para continuar...");
                        getchar();
                        break;
                }
                fseek(ft, -1 * (long)sizeof(Turma), SEEK_CUR);
                fwrite(t, sizeof(Turma), 1, ft);
                fclose(ft);
            } while (esc != 0);
        }
    }
    if (!encontra){
        printf("Turma não encontrada!\n");
    }
    fclose(ft);
    free(t);
}


