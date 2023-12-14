#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "valida.h"
#include "relatorio.h"
//código turma  6A
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
                //condição realizada para quando o cadastrado do aluno não quiser ser feito
                //ou por não atender alguma opção do usuário
                if(t==NULL){
                    break;
                }
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

void tela_turma(void){
    printf("Com a lestras em MAÍSCULA!");
    printf("(I-infantil do 1° a 5° Série)\n(F-Fundamental do 6° ao 9° Ano )\n(M-Ensino Médio da 1° 3° Aérie)\n");
    printf("Digite primeiramente se é I-F-M e após essas letras digite o número conforme mostrado\n");
    printf("No fim digite se é da turma A,B ou C\n\n");
}
//testar se está ocorrendo tudo bem
Turma *cadastrar_turma(void){
    system("clear||cls");
    char nome[100];
    Turma* t; //t-turm
    t = (Turma *)malloc(sizeof(Turma));
    printf("\n");
    printf("========================================================\n");
    printf("    ************* Cadastrar Turma *************     \n\n");
    tela_turma();
    do{
        ler_turma(t->cod);
        if(!verificar_turma_existente(t->cod)){
            printf("Turma já cadastrada!\n");
            char resposta=obter_resposta();
            fflush(stdin);
            //Caso ele digite algo diferente de "S" no caso "N"
            //quer dizer que ele não quer mais digitar o cpf e irá retornar NULL
            if (resposta == 'N') {
                free(t);
                return NULL;  
            }
        //Caso a turma em questão não estiver cadastrado o loop se encerará
        }else{
            break;  
        }
    }while (1);
    printf("Escreva o nome da turma (Só escreva letras)\n");
    ler_nome(nome);
    //deixar todo o nome com letras minúsculas
    str_to_lower(nome);
    //utilzado essa função par na hora que armazenar o arquivo não inserir lixo de memória
    //com os caracteres que não foram usados será colocado \0 no lugar
    strncpy(t->nome,nome,sizeof(t->nome));
    t->status = 'A';
    printf("                                                        \n");
    printf("Dados da Turma cadastrada!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
    return t;
    free(t);
}

void buscar_turma(void){
    system("clear||cls");
    char cod[4];
    printf("\n");  
    printf("========================================================\n");
    printf("    *************** Pesquisar Turma *************     \n\n");
    printf("                                                        \n");
    tela_turma();
    ler_turma(cod);
    procura_turma(cod);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void atualizar_turma(void){
    system("clear||cls");
    char cod[4];
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Turma *************     \n\n");
    printf("                                                        \n");
    printf("\033[34mInforme o código da truma que será atualizada\033[0m\n");
    printf("                                                        \n");
    tela_turma();
    ler_turma(cod);
    att_turma(cod);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void excluir_turma(){
    system("clear||cls");
    char cod[4];
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Turma *************       \n\n");
    printf("                                                        \n");
    tela_turma();
    ler_turma(cod);
    procura_turma(cod);
    if(decidir_excluir()){
        remover_turma(cod);
    }
    else{
        return;
    }
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
    listar_todas_turma();
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
    if ((t == NULL) || (t->status == 'I')){
        printf("\nEsta Turma não existe no sistema!\n");
    }
    else{
        printf("\n********Dados Da Turma********");
        printf("\nSérie da Turma:%s", t->cod);
        printf("\nNome da Turma:%s\n", t->nome);
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
    int cont=0;
    t = (Turma *)malloc(sizeof(Turma));
    ft = fopen("Turma.dat", "rb");
    if (ft == NULL){
        printf("\nNenhuma Turma cadastrada!\n");
        return;
    }
    while (fread(t, sizeof(Turma), 1, ft)){
        if ((strcmp(t->cod, cod) == 0) && (t->status == 'A')){
            cont++;
            exibicao_turma(t);
        }
    }if(!cont){
        printf("\nEssa turma não existe no sistema ou ainda não foi cadastrado!\n");
    }
    fclose(ft);
    free(t);
}

// feito com a ajuda de marlison silva chat gpt e adapatada por matheus diniz
void remover_turma(char *cod){
    FILE *ft;
    Turma *t;
    int cont = 0;
    t = (Turma *)malloc(sizeof(Turma));
    ft = fopen("Turma.dat", "r+b");
    if (ft == NULL){
        printf("\nNenhuma Turma foi cadastrada!\n");
        return;
    }
    while (fread(t, sizeof(Turma), 1, ft)){
        if ((strcmp(t->cod, cod) == 0) && (t->status == 'A')){
            cont++;
            t->status = 'I';
            fseek(ft, -1 * (long)sizeof(Turma), SEEK_CUR);
            fwrite(t, sizeof(Turma), 1, ft);
            printf("\nTurma excluída!\n");
            break; // Encerre o loop após a exclusão
        }
    }
    if (!cont){
        printf("\nTurma não encontrada!\n");
    }
    fclose(ft);
    free(t);
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
                esc=-1;
                system("clear||cls");
                printf("========================================================\n");
                printf("   *************** Atualizar Turma ***************      \n");
                printf("                                                        \n");
                printf("               o que deseja atualizar?                  \n");
                printf("           Nome da turma[\033[34m1\033[0m] - Voltar[\033[34m0\033[0m]    \n");
                printf("                                                        \n");
                printf("Dados cadastrados no sistema:\n");
                printf("Código da Turma:%s\n", t->cod);
                printf("Nome da turuma:%s\n", t->nome);
                printf("========================================================\n");
                printf("\n");
                printf("Qual opção deseja atualizar:");
                fflush(stdin);
                scanf("%d", &esc);
                limpar_buffer();
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
                        printf("\nAlteração realizada!\n");
                        printf("\nDigite enter para continuar...");
                        getchar();
                        break;
                }
                fseek(ft, -1 * (long)sizeof(Turma), SEEK_CUR);
                fwrite(t, sizeof(Turma), 1, ft);
            } while (esc != 0);
            break;
        }
    }
    if (!encontra){
        printf("Turma não encontrada!\n");
    }
    fclose(ft);
    free(t);
}


