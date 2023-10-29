#include "global.h" //incluede para deixar opc global 
#include "professor.h"
#include "valida.h"
#include "diciplina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Apelido struct Global
Professor* prof; //Professor


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
                prof=cadastrar_professor();
                gravarprofessor(prof);
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
                getchar(); printf("Digite enter para continuar...");getchar(); 
                break;
        }
    }
}

Professor* cadastrar_professor(void) {
    system("clear||cls");
    prof=(Professor*)malloc(sizeof(Professor));
    printf("\n");
    printf("========================================================\n\n");
    printf("   *************** Cadastrar Professor ***************  \n\n");
    ler_cpf(prof->cpf);
    ler_nome(prof->nome);
    ler_email(prof->email);
    ler_telefone(prof->telefone);
    prof->status='A';
    printf("                                                        \n");
    printf("Dados cadastrados!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");getchar(); //para aparecer o menu e ele não sair rapidamente
    return prof;
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
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void atualizar_professor(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Professor *************   \n\n");
    printf("                                                        \n");
    printf("             O que deseja atualizar?                    \n");
    printf("             Telefone(0) - Email(1)                     \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
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
    getchar(); printf("Digite enter para continuar...");getchar(); 
}

void relatorio_professor(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("   *************** Relatório Professor *************  \n\n");
    printf("                                                        \n");
    printf("       (Todos os Professores cadastrado)                \n");
    listarprofessor();
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}

void gravarprofessor(Professor* prof){
    FILE* fp;  //File Professor
    fp=fopen("Professor.dat","ab");
    if (fp==NULL){
        printf("Erro na recuperação dos dados do Aluno!\n");
        exit(1);
    }
    fwrite(prof,sizeof(Professor),1,fp);
    fclose(fp);
}

void exibir_professores(Professor* prof){
    char estado[16];
    if ((prof==NULL) || (prof->status=='I')){
        printf("\nEste Professor não existe no sistema!\n");
    }else{
        printf(" ********Dados Do Professor********");
        printf("\n\tNome:%s",prof->nome);
        printf("\tCPF:%s\n",prof->cpf);
        printf("\tEmail:%s\n",prof->email);
        printf("\tTelefone:%s\n",prof->telefone);
        if(prof->status=='A'){
            strcpy(estado,"Professor Ativo");
        }else if(prof->status=='N'){
            strcpy(estado,"Não Encontrado");
        }else{
            strcpy(estado,"Fechado");
        }
    }
}

void listarprofessor(void){
    FILE* fp;
    prof=(Professor*)malloc(sizeof(Professor));
    fp=fopen("Professor.dat","rb");
    if (fp==NULL){
        printf("Erro na recuperação dos dados!\n");
        exit(1);
    }
    while(fread(prof,sizeof(Professor),1,fp)){
        if (prof->status!='I'){
            exibir_professores(prof);
        }
    }
    fclose(fp);
    free(prof);
}