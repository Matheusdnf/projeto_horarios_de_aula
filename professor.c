#include "global.h" //incluede para deixar opc global 
#include "professor.h"
#include "valida.h"
#include "diciplina.h"
#include "checagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_professor(void) {
    while (opc!=0){
        Professor* prof;
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
        printf("\nDigite o que deseja fazer: "); scanf("%c", &opc);
        switch (opc){
            case '1':
                prof=cadastrar_professor();
                gravar_professor(prof);
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
                break;
            default:
                printf("Opção Inválida!\n");
                printf("Digite enter para continuar...");getchar(); 
                break;
        }
    }
}

Professor* cadastrar_professor(void) {
    system("clear||cls");
    Professor* prof;
    bool v=true,f=false;
    char c;
    prof=(Professor*)malloc(sizeof(Professor));
    printf("\n");
    printf("========================================================\n\n");
    printf("   *************** Cadastrar Professor ***************  \n\n");
    while(v){
        ler_cpf(prof->cpf);
        c=verifica_existe_prof(prof->cpf);
        if (c == 1) {
                v = f;  
            } else {
                printf("Professor já cadastrado com esse cpf\n");
            }
        }
    ler_nome(prof->nome);
    ler_email(prof->email);
    ler_telefone(prof->telefone);
    prof->status='A';
    printf("                                                        \n");
    printf("Dados do Professor cadastrados!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");getchar(); //para aparecer o menu e ele não sair rapidamente
    return prof;
}

void buscar_professor(void) {
    system("clear||cls");
    char cpf[15];
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Buscar Professor *************    \n\n");
    printf("                                                        \n");
    ler_cpf(cpf);
    procura_professor(cpf);
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");getchar(); 
}


void atualizar_professor(void) {
    system("clear||cls");
    char cpf[15];
    printf("\n");
    printf("========================================================\n");
    printf("   *************** Atualizar Professor *************   \n\n");
    printf("                                                        \n");
    printf("      Informe o cpf do Professor que será atualizado        \n");
    printf("                                                        \n");
    ler_cpf(cpf);
    printf("                                                        \n");
    att_professor(cpf);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");getchar(); 
}


void excluir_professor(void) {
    system("clear||cls");
    char cpf[15];
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Professor *************     \n\n");
    printf("                                                        \n");
    ler_cpf(cpf);
    remover_Professor(cpf);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");getchar(); 
}

void relatorio_professor(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("   *************** Relatório Professor *************  \n\n");
    printf("                                                        \n");
    printf("(Todos os Professores cadastrado)                       \n");
    listar_todos_professor();
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}

void gravar_professor(Professor* prof){
    FILE* fp;  //File Professor
    fp=fopen("Professor.dat","ab");
    if (fp==NULL){
        printf("Erro na recuperação dos dados do Professor!\n");
    }
    fwrite(prof,sizeof(Professor),1,fp);
    fclose(fp);
}

void exibicao_professor(Professor* prof){
    char estado[16];
    if ((prof==NULL) || (prof->status=='I')){
        printf("\nEste Professor não existe no sistema!\n");
    }else{
        printf("\n ********Dados Do Professor********");
        printf("\nNome:%s",prof->nome);
        printf("CPF:%s\n",prof->cpf);
        printf("Email:%s\n",prof->email);
        printf("Telefone:%s\n",prof->telefone);
        if(prof->status=='A'){
            strcpy(estado,"Professor Ativo");
        }else if(prof->status=='I'){
            strcpy(estado,"Não Encontrado");
        }
    }
}

void listar_todos_professor(void){
    FILE* fp;
    Professor* prof;
    prof=(Professor*)malloc(sizeof(Professor));
    fp=fopen("Professor.dat","rb");
    if (fp==NULL){
        printf("\nNenhum professor cadastrado!\n");
    }
    while(fread(prof,sizeof(Professor),1,fp)){
        if (prof->status!='I'){
            exibicao_professor(prof);
        }
    }
    fclose(fp);
    free(prof);
}

void procura_professor(char cpf[]) {
    FILE* fp;
    Professor* prof;
    prof=(Professor*)malloc(sizeof(Professor));
    fp=fopen("Professor.dat","rb");
    if (prof == NULL) {
    printf("\tProfessor não encontrado!\n");
        return;
    }
    if (fp==NULL){
        printf("\nNenhum professor foi cadastrado!\n");
        return;
    }
    while(fread(prof, sizeof(Professor), 1, fp)) {
        if ((strcmp(prof->cpf, cpf) == 0) && (prof->status=='A')) {
            exibicao_professor(prof);
        }
    }
    fclose(fp);
    free(prof);
}

//feito com a ajuda de marlison silva chat gpt e adapatada por matheus diniz
void remover_Professor(char cpf[]) {
    FILE* fp;
    Professor *prof;
    int encontra = 0;
    prof = (Professor*) malloc(sizeof(Professor));
    fp = fopen("Professor.dat", "r+b");
    if (fp == NULL) {
        printf("Nenhum professor foi cadastrado!\n");
        return;
    }
    while (fread(prof, sizeof(Professor), 1, fp)) {
        if ((strcmp(prof->cpf, cpf) == 0) && (prof->status == 'A')) {
            encontra = 1;
            prof->status = 'I';
            fseek(fp, -1 * (long)sizeof(Professor), SEEK_CUR);
            fwrite(prof, sizeof(Professor), 1, fp);
            printf("\nProfessor excluído!\n");
            break; // Encerre o loop após a exclusão
        }
    }
    if (!encontra) {
        printf("\nProfessor não encontrado!\n");
    }
    fclose(fp);
}

void att_professor(char cpf[]){
    FILE* fp;
    Professor *prof;
    int encontra=0;
    int esc;
    prof=(Professor*)malloc(sizeof(Professor));
    fp=fopen("Professor.dat","r+b");
    if (prof == NULL) {
    printf("\tNão foi possível abrir o arquivo!\n");
        return;
    }
    if (fp==NULL){
        printf("\nNenhum professor foi cadastrado!\n");
        return;
    }
    while (fread(prof, sizeof(Professor), 1, fp)) {
        if ((strcmp(prof->cpf, cpf) == 0) && (prof->status == 'A')) {
        encontra=1;  
            while (esc!=0){
            system("clear||cls");
            printf("========================================================\n");
            printf("   *************** Atualizar Professor ***************      \n");
            printf("                                                        \n");
            printf("               o que deseja atualizar?                  \n");
            printf("          Telefone[\033[31m1\033[0m] - Email[\033[31m2\033[0m] - Voltar[\033[31m0\033[0m]\n");
            printf("                                                        \n");
            printf("Dados cadastrados no sistema:\n");
            printf("\nNome do Professor:%s",prof->nome);
            printf("CPF Do Professor:%s\n",prof->cpf);
            printf("Email:%s\n",prof->email);
            printf("Telefone:%s\n",prof->telefone);
            printf("========================================================\n");
            printf("\n");
            printf("Qual opção deseja atualizar:");
            scanf("%d",&esc);
            fflush(stdin);
            switch (esc) { 
                case 1:
                    ler_telefone(prof->telefone);
                    printf("Alteração realizada!\n");
                    printf("Digite enter para continuar...");getchar();
                    break;
                case 2:
                    ler_email(prof->email);
                    printf("Alteração realizada!\n");
                    printf("Digite enter para continuar...");getchar();
                    break;
                case 0:
                    esc=0;
                    break;
                default:
                    printf("\nOpção Inválida!\n");
                    printf("Digite enter para continuar...");getchar(); 
                    break;
            }
                fseek(fp, -1 * (long)sizeof(Professor), SEEK_CUR);
                fwrite(prof, sizeof(Professor), 1, fp);       
            }break;
        }
        }
        if (!encontra) {
            printf("Professor não encontrado!\n");
    } 
    fclose(fp);
    free(prof);
}