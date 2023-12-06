#include "professor.h"
#include "valida.h"
#include "diciplina.h"
#include "checagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_professor(void){
    //opc -1 para ela poder ser atualiza pelo usuário quando vai navegando
    //impede que o programa entre em alguma opção que não deveria
    int opc=-1;
    do{
        opc=-1;
        Professor *prof;
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
        printf("\nDigite o que deseja fazer: ");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                prof = cadastrar_professor();
                //condição realizada para quando o cadastrado do aluno não quiser ser feito
                //ou por não atender alguma opção do usuário
                if(prof==NULL){
                    break;
                }
                gravar_professor(prof);
                break;
            case 2:
                buscar_professor();
                break;
            case 3:
                atualizar_professor();
                break;
            case 4:
                excluir_professor();
                break;
            case 5:
                relatorio_professor();
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

Professor *cadastrar_professor(void){
    system("clear||cls");
    Professor *prof;
    char nome[100];
    char email[225];
    char escolha;
    prof = (Professor*)malloc(sizeof(Professor));
    printf("\n");
    printf("========================================================\n\n");
    printf("   *************** Cadastrar Professor ***************  \n\n");
    do{
        ler_cpf(prof->cpf);
        if(!verifica_existe_prof(prof->cpf)){
            printf("Professor já cadastrado com esse cpf!\n");
            //caso já o usuário vai ter a chance de tentar novamente
            do {
                printf("Deseja tentar novamente (S/N)? ");
                scanf(" %c", &escolha); 
                letra_maiuscula(&escolha); 
                getchar();
                //validar a resposta 
                if (!valida_s_ou_n(escolha)) {
                    printf("Digite algo válido (S/N)!\n");
                }
                //enquanto o usário digitar "N" o laço continuará
            } while (escolha != 'S' && escolha != 'N'); 
            //Caso ele digite algo diferente de "S" no caso "N"
            //quer dizer que ele não quer mais digitar o cpf e irá retornar NULL
            if (escolha == 'N') {
                return NULL;  
            }
            //Caso o aluno com o cpf em questão não estiver cadastrado o loop se encerará
        } else {
            break;  
        }
    } while (1);
    ler_nome(nome);
    //utilzado essa função par na hora que armazenar o arquivo não inserir lixo de memória
    //com os caracteres que não foram usados será colocado \0 no lugar
    strncpy(prof->nome,nome,sizeof(prof->nome));
    ler_email(email);
    //utilzado essa função par na hora que armazenar o arquivo não inserir lixo de memória
    //com os caracteres que não foram usados será colocado \0 no lugar
    strncpy(prof->email,email,sizeof(prof->email));
    ler_telefone(prof->telefone);
    prof->status = 'A';
    printf("                                                        \n");
    printf("Dados do Professor cadastrados!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar(); // para aparecer o menu e ele não sair rapidamente
    return prof;
    free(prof);
}

void buscar_professor(void){
    system("clear||cls");
    char cpf[12];
    printf("========================================================\n");
    printf("    *************** Buscar Professor *************    \n\n");
    printf("                                                        \n");
    ler_cpf(cpf);
    procura_professor(cpf);
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void atualizar_professor(void){
    system("clear||cls");
    char cpf[12];
    printf("========================================================\n");
    printf("   *************** Atualizar Professor *************   \n\n");
    printf("                                                        \n");
    printf("      Informe o cpf do Professor que será atualizado        \n");
    printf("                                                        \n");
    ler_cpf(cpf);
    att_professor(cpf);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar();
    printf("Digite enter para continuar...");
    getchar();
}

void excluir_professor(void){
    system("clear||cls");
    char cpf[12];
    printf("========================================================\n");
    printf("    *************** Excluir Professor *************     \n\n");
    printf("                                                        \n");
    ler_cpf(cpf);
    procura_professor(cpf);
    if(decidir_excluir()){
        remover_Professor(cpf);
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

void relatorio_professor(void){
    system("clear||cls");
    printf("========================================================\n");
    printf("   *************** Relatório Professor *************  \n\n");
    printf("                                                        \n");
    printf("(Todos os Professores cadastrado)                       \n");
    listar_todos_professor();
    printf("========================================================\n");
    printf("\n");
    getchar();
    printf("Digite enter para continuar...");
    getchar();
}

void gravar_professor(Professor *prof){
    FILE *fp; // File Professor
    fp = fopen("Professor.dat", "ab");
    if (fp == NULL){
        printf("Erro na recuperação dos dados do Professor!\n");
        return;
    }
    fwrite(prof, sizeof(Professor), 1, fp);
    fclose(fp);
}

void exibicao_professor(Professor *prof){
    char estado[16];
    if ((prof == NULL) || (prof->status == 'I')){
        printf("\nEste Professor não existe no sistema!\n");
    }
    else{
        printf("\n ********Dados Do Professor********");
        printf("\nNome:%s\n", prof->nome);
        printf("CPF:%s\n", prof->cpf);
        printf("Email:%s\n", prof->email);
        printf("Telefone:%s\n", prof->telefone);
        if (prof->status == 'A'){
            strcpy(estado, "Professor Ativo");
        }
        else if (prof->status == 'I'){
            strcpy(estado, "Não Encontrado");
        }
    }
}

void listar_todos_professor(void){
    FILE *fp;
    Professor *prof;
    prof = (Professor *)malloc(sizeof(Professor));
    fp = fopen("Professor.dat", "rb");
    if (fp == NULL){
        printf("\nNenhum professor cadastrado!\n");
        return;
    }
    while (fread(prof, sizeof(Professor), 1, fp)){
        if (prof->status != 'I'){
            exibicao_professor(prof);
        }
    }
    fclose(fp);
    free(prof);
}

void procura_professor(char cpf[]){
    FILE *fp;
    Professor *prof;
    //serve para verificar se o cpf digitado está presente no sistema
    int cont=0;
    prof = (Professor *)malloc(sizeof(Professor));
    fp = fopen("Professor.dat", "rb");
    //verifica se existe o arquivo professores
    if (fp == NULL){
        printf("\nNenhum professor foi cadastrado!\n");
        //retornar para a tela anterior
        return;
    }
    while (fread(prof, sizeof(Professor), 1, fp)){
        if ((strcmp(prof->cpf, cpf) == 0) && (prof->status == 'A')){
            exibicao_professor(prof);
            cont++;
        }
    //caso o que foi digitado não for encontrado ele cairá nesse if 
    }if(!cont){
        printf("\nEsse professor não existe no sistema ou ainda não foi cadastrado!\n");
    }
    fclose(fp);
    free(prof);
}

// feito com a ajuda de marlison silva chat gpt e adapatada por matheus diniz
void remover_Professor(char cpf[]){
    FILE *fp;
    Professor *prof;
    //serve para verificar se o cpf digitado está presente no sistema
    int cont=0;
    prof = (Professor *)malloc(sizeof(Professor));
    fp = fopen("Professor.dat", "r+b");
    if (fp == NULL){
        printf("\nNenhum professor foi cadastrado!\n");
        //retornar para a tela anterior
        return;
    }
    while (fread(prof, sizeof(Professor), 1, fp)){
        //irá comparar o cpf digitado com os disponíveis no sistema
        if ((strcmp(prof->cpf, cpf) == 0) && (prof->status == 'A')){
            //encontrando irá contar 1
            cont++;
            //irá mudar o campo para I que significa inativo
            prof->status = 'I';
            fseek(fp, -1 * (long)sizeof(Professor), SEEK_CUR);
            //escrever o novo campo, no caso irá alterar
            fwrite(prof, sizeof(Professor), 1, fp);
            printf("\nProfessor excluído!\n");
            break; // Encerre o loop após a exclusão
        }
    }
    //caso o que foi digitado não for encontrado ele cairá nesse if 
    if (!cont){
        printf("\nEsse professor não existe no sistema ou ainda não foi cadastrado!\n");
    }
    fclose(fp);
    free(prof);
}

void att_professor(char cpf[]){
    FILE *fp;
    Professor *prof;
    int cont = 0;
    int esc=-1;
    prof = (Professor *)malloc(sizeof(Professor));
    fp = fopen("Professor.dat", "r+b");
    if (fp == NULL){
        printf("\nNenhum professor foi cadastrado!\n");
        return;
    }
    while (fread(prof, sizeof(Professor), 1, fp)){
        if ((strcmp(prof->cpf, cpf) == 0) && (prof->status == 'A')){
            cont++;
            //essa tela serve para dar a opção de atualizar o que desejas
            do{
                //valor sempre será atualizado para -1 quando voltar para essa tela
                esc=-1;
                system("clear||cls");
                printf("========================================================\n");
                printf("   *************** Atualizar Professor ***************      \n");
                printf("                                                        \n");
                printf("               o que deseja atualizar?                  \n");
                printf("          Telefone[\033[34m1\033[0m] - Email[\033[34m2\033[0m] - Voltar[\033[34m0\033[0m]\n");// feito com ajuda do chat openIA(Gpt)
                printf("                                                        \n");
                printf("Dados cadastrados no sistema:\n");
                printf("\nNome do Professor:%s", prof->nome);
                printf("CPF Do Professor:%s\n", prof->cpf);
                printf("Email:%s\n", prof->email);
                printf("Telefone:%s\n", prof->telefone);
                printf("========================================================\n");
                printf("\n");
                printf("Qual opção deseja atualizar:");
                fflush(stdin);
                scanf("%d", &esc);
                getchar();
                fflush(stdin);
                switch (esc){
                    case 1:
                        ler_telefone(prof->telefone);
                        printf("Alteração realizada!\n");
                        printf("Digite enter para continuar...");
                        getchar();
                        break;
                    case 2:
                        ler_email(prof->email);
                        printf("Alteração realizada!\n");
                        printf("Digite enter para continuar...");
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
                fseek(fp, -1 * (long)sizeof(Professor), SEEK_CUR);
                fwrite(prof, sizeof(Professor), 1, fp);
                fclose(fp);
            } while (esc != 0);
        }
    }
    if (!cont){
        printf("Professor não encontrado!\n");
    }
    fclose(fp);
    free(prof);
}