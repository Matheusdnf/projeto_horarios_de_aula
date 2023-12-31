#include "valida.h"
#include "relatorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_aluno(void){
    //opc -1 para ela poder ser atualiza pelo usuário quando vai navegando
    //impede que o programa entre em alguma opção que não deveria
    int opc=-1;
    do{
        opc=-1;
        system("clear||cls");
        Aluno *std;
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
        printf("\nDigite o que deseja fazer: ");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                std = cadastrar_aluno();
                //condição realizada para quando o cadastrado do aluno não quiser ser feito
                //ou por não atender alguma opção do usuário
                if(std==NULL){
                    break;
                }
                gravar_aluno(std);
                break;
            case 2:
                buscar_aluno();
                break;
            case 3:
                atualizar_aluno();
                break;
            case 4:
                excluir_aluno();
                break;
            case 5:
                relatorio_aluno();
                break;
            case 0:
                break;
            default:
                printf("\nOpção Inválida!\n");
                printf("Digite enter para continuar...");
                getchar();
                getchar();
                getchar();
                break;
        }
    } while (opc != 0);
}

Aluno *cadastrar_aluno(void){
    system("clear||cls");
    Aluno *std;
    char nome[100];
    char email[225];
    std = (Aluno *)malloc(sizeof(Aluno));
    printf("\n");
    printf("========================================================\n");
    printf("    ************* Cadastrar Aluno *************     \n\n");
    do {
        // Ler o CPF
        ler_cpf(std->cpf);
        // Verificar se o aluno já está cadastrado 
        if (!verifica_existe_aluno(std->cpf)) {
            printf("Aluno já cadastrado com esse CPF!\n");
            //caso já o usuário vai ter a chance de tentar novamente
            char resposta=obter_resposta();
            fflush(stdin);
            //Caso ele digite algo diferente de "S" no caso "N"
            //quer dizer que ele não quer mais digitar o cpf e irá retornar NULL
            if (resposta == 'N') {
                free(std);
                return NULL;  
            }
            //Caso o aluno com o cpf em questão não estiver cadastrado o loop se encerará
        } else {
            break;  
        }
        //retornar um tela,no caso ao menu 
    } while (1);
    ler_nome(nome);
    //função para deixar todo o nome minúsculo
    str_to_lower(nome);
    //utilzado essa função par na hora que armazenar o arquivo não inserir lixo de memória
    //com os caracteres que não foram usados será colocado \0 no lugar
    strncpy(std->nome,nome,sizeof(std->nome));
    ler_email(email);
    //utilzado essa função par na hora que armazenar o arquivo não inserir lixo de memória
    //com os caracteres que não foram usados será colocado \0 no lugar
    strncpy(std->email,email,sizeof(std->email));
    ler_telefone(std->telefone);
    std->status = 'A';
    printf("                                                        \n");
    printf("Dados do Aluno cadastrados!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar(); // para aparecer o menu e ele não sair rapidamente
    return std;
    free(std);
}

void buscar_aluno(void){
    system("clear||cls");
    char cpf[15];
    printf("========================================================\n");
    printf("    *************** Pesquisar Aluno *************     \n\n");
    printf("                                                        \n");
    ler_cpf(cpf);
    procura_aluno(cpf);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void atualizar_aluno(void){
    system("clear||cls");
    char cpf[15];
    printf("========================================================\n");
    printf("    *************** Atualizar Aluno *************     \n\n");
    printf("                                                        \n");
    printf("\033[34mInforme o cpf do aluno que será atualizado\033[0m\n");
    printf("                                                        \n");
    ler_cpf(cpf);
    printf("                                                        \n");
    att_aluno(cpf);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void excluir_aluno(){
    system("clear||cls");
    char cpf[15];
    printf("========================================================\n");
    printf("    *************** Excluir Aluno *************       \n\n");
    printf("                                                        \n");
    ler_cpf(cpf);
    procura_aluno(cpf);
    if(decidir_excluir()){
        remover_aluno(cpf);
        //quando o aluno for excluido a sua matrícula também será cancelada
        remover_matricula(cpf);
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

void relatorio_aluno(void){
    system("clear||cls");
    printf("========================================================\n");
    printf("    *************** Relatório Aluno *************       \n\n");
    printf("                                                        \n");
    printf("\x1B[34m(informar todos os alunos cadastrados)\x1B[0m \n");
    listar_todos_aluno();
    printf("========================================================\n");
    printf("\n");
    getchar();
    printf("Digite enter para continuar...");
    getchar();
}

void gravar_aluno(Aluno *std){
    FILE *fa; // File aluno
    fa = fopen("Alunos.dat", "ab");
    if (fa == NULL){
        printf("Erro na recuperação dos dados do Aluno!\n");
        return;
    }
    //escrever os dados digitados no arquivo
    fwrite(std, sizeof(Aluno), 1, fa);
    fclose(fa);
}

void exibicao_alunos(Aluno *std){
    if ((std == NULL) || (std->status == 'I')){
        printf("\nFalha na procura!\n");
    }
    else{
        printf("\n********Dados Do Aluno********");
        printf("\nNome:%s", std->nome);
        printf("\nCPF:%s\n", std->cpf);
        printf("Email:%s\n", std->email);
        printf("Telefone:%s\n", std->telefone);
    }
}

void listar_todos_aluno(void){
    FILE *fa;
    Aluno *std;
    std = (Aluno *)malloc(sizeof(Aluno));
    fa = fopen("Alunos.dat", "rb");
    //verifica se existe o arquivo alunos
    if (fa == NULL){
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }
    while (fread(std, sizeof(Aluno), 1, fa)){
        if (std->status != 'I'){
            exibicao_alunos(std);
        }
    }
    fclose(fa);
    free(std);
}

// feito com a ajuda de marlison silva
void procura_aluno(char cpf[]){
    FILE *fa;
    Aluno *std;
    //serve para verificar se o cpf digitado está presente no sistema
    int cont=0;
    std = (Aluno *)malloc(sizeof(Aluno));
    fa = fopen("Alunos.dat", "rb");
    if (fa == NULL){
        printf("\nNenhum aluno cadastrado!\n");
        //retornar para a tela anterior
        return;
    }
    while (fread(std, sizeof(Aluno), 1, fa)){
        if ((strcmp(std->cpf, cpf) == 0) && (std->status == 'A')){
            exibicao_alunos(std);
            cont++;
        }
    //caso o que foi digitado não for encontrado ele cairá nesse if 
    }if(!cont){
        printf("\nEsse aluno não existe no sistema ou ainda não foi cadastrado!\n");
    }
    fclose(fa);
    free(std);
}


// feito com a ajuda de marlison silva chat gpt e adapatada por matheus diniz

void remover_aluno(char cpf[]){
    FILE *fa;
    Aluno *std;
    //serve para verificar se o cpf digitado está presente no sistema
    int cont = 0;
    std = (Aluno *)malloc(sizeof(Aluno));
    fa = fopen("Alunos.dat", "r+b");
    //verificar se existe algum artigo existente
    if (fa == NULL){
        printf("\nNenhum aluno foi cadastrado!\n");
        return;
    }
    //irá ler o arquivdo 
    while (fread(std, sizeof(Aluno), 1, fa)){
        //irá comparar o cpf digitado com os disponíveis no sistema
        if ((strcmp(std->cpf, cpf) == 0) && (std->status == 'A')){
            //encontrando irá contar 1
            cont++;
            //irá mudar o campo para I que significa inativo
            std->status = 'I';
            fseek(fa, -1 * (long)sizeof(Aluno), SEEK_CUR);
            //escrever o novo campo, no caso irá alterar
            fwrite(std, sizeof(Aluno), 1, fa);
            printf("\nAluno excluído!\n");
            break; // Encerre o loop após a exclusão
        }
    }if (!cont){
        printf("\nAluno não encontrado!\n");
    }
    fclose(fa);
    free(std);
}

void att_aluno(char cpf[]){
    FILE *fa;
    Aluno *std;
    int cont = 0;
    int esc=-1;
    std = (Aluno *)malloc(sizeof(Aluno));
    fa = fopen("Alunos.dat", "r+b");
    if (fa == NULL){
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }
    while (fread(std, sizeof(Aluno), 1, fa)){
        //irá procurar o cpf do aluno procurado
        if ((strcmp(std->cpf, cpf) == 0) && (std->status == 'A')){
            cont++;
            //essa tela serve para dar a opção de atualizar o que desejas
            do{
                system("clear||cls");
                printf("========================================================\n");
                printf("   *************** Atualizar Aluno ***************      \n");
                printf("                                                        \n");
                printf("               o que deseja atualizar?                  \n");
                printf("         Telefone[\033[34m1\033[0m] - Email[\033[34m2\033[0m] - Voltar[\033[34m0\033[0m]\n");
                printf("                                                        \n");
                printf("Dados cadastrados no sistema:\n");
                printf("\nNome do aluno:%s\n", std->nome);
                printf("CPF Do Aluno:%s\n", std->cpf);
                printf("Email:%s\n", std->email);
                printf("Telefone:%s\n", std->telefone);
                printf("========================================================\n");
                printf("\n");
                printf("Qual opção deseja atualizar:");
                fflush(stdin);
                scanf("%d", &esc);
                limpar_buffer();
                switch (esc){
                    case 1:
                        ler_telefone(std->telefone);
                        printf("\nAlteração realizada!\n");
                        printf("\nDigite enter para continuar...");
                        getchar();
                        break;
                    case 2:
                        ler_email(std->email);
                        printf("\nAlteração realizada!\n");
                        printf("\nDigite enter para continuar...");
                        getchar();
                        break;
                    case 0:
                        break;
                    default:
                        printf("\nOpção inválida!\n");
                        printf("\nDigite enter para continuar...");
                        getchar();
                        break;
                }
                fseek(fa, -1 * (long)sizeof(Aluno), SEEK_CUR);
                fwrite(std, sizeof(Aluno), 1, fa);
            } while (esc != 0);
            break;
        }
    }
    if (!cont){
        printf("Aluno não encontrado!\n");
    }
    fclose(fa);
    free(std);
}