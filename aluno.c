#include "global.h" //incluede para deixar opc global 
#include "aluno.h"
#include "valida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Apelido Struct 
Aluno* std;    //Estudante  

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
                std = cadastrar_aluno();
                gravaraluno(std);
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
                break;
            default:
                printf("Opção Inválida!\n");
                getchar(); printf("Digite enter para continuar...");getchar();          
                break;
        }
    }
}

Aluno* cadastrar_aluno(void) {
    system("clear||cls"); 
    std=(Aluno*)malloc(sizeof(Aluno));
    printf("\n");
    printf("========================================================\n");
    printf("    ************* Cadastrar Aluno *************     \n\n");
    ler_cpf(std->cpf);
    ler_nome(std->nome);
    ler_email(std->email);
    ler_telefone(std->telefone);
    std->status='M';
    printf("                                                        \n");
    printf("Dados do Aluno cadastrados!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");getchar(); //para aparecer o menu e ele não sair rapidamente
    return std;

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
    getchar(); printf("Digite enter para continuar...");getchar(); 

}

void atualizar_aluno(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Aluno *************     \n\n");
    printf("                                                        \n");
    printf("            o que deseja atualizar?                     \n");
    printf("             Telefone(0) - Email(1)                     \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
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
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void relatorio_aluno(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Relatório Aluno *************       \n\n");
    printf("                                                        \n");
    printf("       (informar todos os alunos cadastrado)            \n");
    listaaluno();
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void gravaraluno(Aluno* std){
    FILE* fa;  //File aluno
    fa=fopen("Alunos.dat","ab");
    if (fa==NULL){
        printf("Erro na recuperação dos dados do Aluno!\n");
        exit(1);
    }
    fwrite(std,sizeof(Aluno),1,fa);
    fclose(fa);
}

void exibir_alunos(Aluno* std){
    char estado[16];
    if ((std==NULL) || (std->status=='I')){
        printf("\nEste Aluno não existe no sistema!\n");
    }else{
        printf("********Dados Do Aluno********");
        printf("\n\tNome:%s",std->nome);
        printf("\tCPF:%s\n",std->cpf);
        printf("\tEmail:%s\n",std->email);
        printf("\tTelefone:%s\n",std->telefone);
        if(std->status=='M'){
            strcpy(estado,"Matriculado");
        }else if(std->status=='N'){
            strcpy(estado,"Não Encontrado");
        }else{
            strcpy(estado,"Fechado");
        }
    }
}

void listaaluno(void){
    FILE* fa;
    std=(Aluno*)malloc(sizeof(Aluno));
    fa=fopen("Alunos.dat","rb");
    if (fa==NULL){
        printf("Erro na recuperação dos dados!\n");
    }
    while(fread(std,sizeof(Aluno),1,fa)){
        if (std->status!='I'){
            exibir_alunos(std);
        }
    }
    fclose(fa);
    free(std);
}