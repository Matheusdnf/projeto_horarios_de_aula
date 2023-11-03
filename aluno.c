#include "global.h" //incluede para deixar opc global 
#include "aluno.h"
#include "valida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_aluno(void) {
    while (opc!=0){
        system("clear||cls");  
        Aluno* std;
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
    Aluno* std;
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
    char cpf[15];
    printf("\n");   //quando o usuário informar o cpf do aluno irá mostrar os dados atrelados a aquelas pessoa,planejo implementar um menu que de outras opções de procura
    printf("========================================================\n");
    printf("    *************** Pesquisar Aluno *************     \n\n");
    printf("                                                        \n");
    ler_cpf(cpf);
    procura_aluno(cpf);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");getchar(); 

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

void excluir_aluno() {
    system("clear||cls");
    char cpf [15];
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Aluno *************       \n\n");
    printf("                                                        \n");
    ler_cpf(cpf);
    remover_aluno(cpf);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");getchar(); 
}


void relatorio_aluno(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Relatório Aluno *************       \n\n");
    printf("                                                        \n");
    printf("(informar todos os alunos cadastrado)                   \n");
    listar_todos_aluno();
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
    free(std);
}

void exibicao_alunos(Aluno* std){
    char estado[17];
    if ((std==NULL) || (std->status=='I')){
        printf("\nEste Aluno não existe no sistema!\n");
    }else{
        printf("\n********Dados Do Aluno********");
        printf("\nNome:%s",std->nome);
        printf("CPF:%s\n",std->cpf);
        printf("Email:%s\n",std->email);
        printf("Telefone:%s\n",std->telefone);
        printf("status:%d",std->status);
        if(std->status=='M'){
            strcpy(estado,"Matriculado");
        }else if(std->status=='I'){
            strcpy(estado,"Fechado");
        }
    }
}

void listar_todos_aluno(void){
    FILE* fa;
    Aluno* std;
    std=(Aluno*)malloc(sizeof(Aluno));
    fa=fopen("Alunos.dat","rb");
    if (fa==NULL){
        printf("\nNenhum aluno cadastrado!\n");
    }
    while(fread(std,sizeof(Aluno),1,fa)){
        if (std->status!='I'){
            exibicao_alunos(std);
        }
    }
    fclose(fa);
    free(std);
}

//feito com a ajuda de marlison silva
void procura_aluno(char cpf[]) {
    FILE* fa;
    Aluno* std;
    std=(Aluno*)malloc(sizeof(Aluno));
    fa=fopen("Alunos.dat","rb");
    if (std == NULL) {
    printf("\tAluno não encontrado!\n");
        return;
    }
    while(fread(std, sizeof(Aluno), 1, fa)) {
        if ((strcmp(std->cpf, cpf) == 0) && (std->status)) {
            exibicao_alunos(std);
        }
    }
    fclose(fa);
    free(std);
}

//feito com a ajuda de marlison silva chat gpt e adapatada por matheus diniz

void remover_aluno(char cpf[]) {
    FILE* fa;
    Aluno std;
    int encontra = 0;
    fa = fopen("Alunos.dat", "r+b");
    if (fa == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }
    while (fread(&std, sizeof(Aluno), 1, fa)) {
        if (strcmp(std.cpf, cpf) == 0 && std.status == 'M') {
            encontra = 1;
            std.status = 'I';
            fseek(fa, -1 * (long)sizeof(Aluno), SEEK_CUR);
            fwrite(&std, sizeof(Aluno), 1, fa);
            printf("\nAluno excluído!\n");
            break; // Encerre o loop após a exclusão
        }
    }
    if (!encontra) {
        printf("\nAluno não encontrado!\n");
    }
    fclose(fa);
}

// void att_aluno(char cpf[]){
//     FILE* fa;
//     Aluno* std;
//     int encontra=0;
//     std=(Aluno*)malloc(sizeof(Aluno));
//     fa=fopen("Alunos.dat","rb");
//     if (std == NULL) {
//     printf("\tAluno não encontrado!\n");
//         return;
//     }
//     while (fread(&std, sizeof(Aluno), 1, fa)) {
//         if (strcmp(std->cpf, cpf) == 0 && std->status == 'M') {
//             encontra = 1;
//         printf("========================================================\n");
//         printf("    *************** Atualizar Aluno *************     \n\n");
//         printf("                                                        \n");
//         printf("            o que deseja atualizar?                     \n");
//         printf("         Telefone(1) - Email(2) - Voltar(0)             \n");
//         printf("                                                        \n");
//         scanf("%d",opc);
//         getchar();
//         switch (opc) { 
//             case '1':
//                 relatorio_aluno();
//                 break;
//             case '2':
//                 relatorio_professor();
//                 break;
//             case '0':
//                 opc=0;
//                 break;
//             default:
//                 printf("\nOpção Inválida!\n");
//                 getchar();printf("Digite enter para continuar...");getchar(); 
//                 break;
        