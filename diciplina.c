#include "diciplina.h"
#include "valida.h"
#include "professor.h"
#include "checagem.h"
#include "relatorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void menu_diciplinas(void){
    //opc -1 para ela poder ser atualiza pelo usuário quando vai navegando
    //impede que o programa entre em alguma opção que não deveria
    int opc=-1;
    do{
        opc=-1;
        system("clear||cls");
        Diciplina *dic;
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Diciplina ******************   \n");
        printf("          1 - Cadastrar Diciplina                          \n");
        printf("          2 - Pesquisar Diciplina                          \n");
        printf("          3 - Atualizar informações da Diciplina           \n");
        printf("          4 - Excluir Diciplina                            \n");
        printf("          5 - Relatório das Diciplinas                     \n");
        printf("          0 - Voltar                                       \n");
        printf("===========================================================\n");
        printf("\nDigite o que deseja fazer: ");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                dic = cadastrar_diciplinas();
                //condição realizada para quando o cadastrado do aluno não quiser ser feito
                //ou por não atender alguma opção do usuário
                if (dic == NULL){
                    break;
                }
                gravardiciplinas(dic);
                break;
            case 2:
                buscar_diciplinas();
                break;
            case 3:
                atualizar_diciplinas();
                break;
            case 4:
                excluir_diciplinas();
                break;
            case 5:
                relatorio_diciplinas();
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

Diciplina *cadastrar_diciplinas(void){
    system("clear||cls");
    char escolha;
    Diciplina *dic;
    dic = (Diciplina *)malloc(sizeof(Diciplina));
    // verificar se algum professor já foi cadastrado no sistema
    printf("========================================================\n");
    printf("    *************** Cadastrar Diciplina *************   \n\n");
    printf("                                                        \n");
    FILE *fp;
    fp = fopen("Professor.dat", "rb");
    if (fp == NULL){
        printf("Nenhum professor foi cadastrado!\n");
        printf("Digite enter para continuar...");
        getchar();
        getchar();
        fclose(fp);
        return NULL;
    }
    //fazer validação que verifica se já existe cpf no de diciplina
    listar_todos_professor_alt();
     do{
        ler_cpf(dic->cpf);
        if((!verifica_existe_prof(dic->cpf))){
            printf("Esse professor não foi cadastrado no sistema de professoures ou já foi atrelado alguma diciplina a ele!\n");
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
            //desenvolvido com o auxílio do chat gpt
            //permitir o usuário digitar novamente ou sair do loop
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
    printf("Pode ser 1 ou 2 diciplinas\n");
    diciplinas();
    ler_diciplinas(dic->diciplina);
    dic->status = 'A';
    dic->id = criar_id_d();
    printf("                                                        \n");
    printf("Diciplina cadastrada!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar(); // para aparecer o menu e ele não sair rapidamente
    fclose(fp);
    return dic;
    free(dic);
}

void buscar_diciplinas(void){
    system("clear||cls");
    int id = 0;
    printf("========================================================\n");
    printf("    *************** Pesquisar Diciplina *************     \n\n");
    printf("                                                        \n");
    printf("Informe o id da diciplina:");
    scanf("%d", &id);
    limpar_buffer();
    procura_diciplinas(id);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void atualizar_diciplinas(void){
    system("clear||cls");
    int id = 0;
    printf("========================================================\n");
    printf("    *************** Atualizar Diciplina *************   \n\n");
    printf("                                                        \n");
    printf("Informe o id da diciplina:");
    scanf("%d", &id);
    limpar_buffer();
    att_diciplinas(id);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar();
    printf("Digite enter para continuar...");
    getchar();
}

void excluir_diciplinas(void){
    system("clear||cls");
    int id = 0;
    printf("========================================================\n");
    printf("    *************** Excluir Diciplina *************     \n\n");
    printf("                                                        \n");
    printf("Informe o id da diciplina:");
    scanf("%d", &id);
    limpar_buffer();
    procura_diciplinas(id);
    if (decidir_excluir()){
        remover_diciplinas(id);
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

void relatorio_diciplinas(void){
    system("clear||cls");
    printf("========================================================\n");
    printf(" *************** Relatório Das Diciplinas ************* \n\n");
    printf("                                                        \n");
    printf("(informar todas as diciplinas cadastrado)               \n");
    printf("                                                        \n");
    listar_todas_diciplinas();
    printf("========================================================\n");
    printf("\n");
    getchar();
    printf("Digite enter para continuar...");
    getchar();
}

void diciplinas(void){
    printf("\n");
    printf("P-Português\n");
    printf("I-Inglês\n");
    printf("E-Espanhol\n");
    printf("A-Artes\n");
    printf("H-História\n");
    printf("G-Geografia\n");
    printf("L-Literatura\n");
    printf("L-Filosofia\n");
    printf("S-Sociologia\n");
    printf("M-Matemática\n");
    printf("B-Biologia\n");
    printf("Q-Química\n");
    printf("F-Física\n\n");
}

// funções para a validação da diciplina
void ler_diciplinas(char *diciplina){
    int t;
    do{
        fflush(stdin);
        printf("Digite a sigla da Matéria:");
        fgets(diciplina, 4, stdin);
        //remover o //n, função pega de @Lleusxam
        diciplina[strlen(diciplina)-1]=0;
        t = valida_diciplinas(diciplina);
        if (t == 0) {
            printf("Diciplina Invalida!\n");
        }
  } while (t != 1);
}

int valida_diciplinas(char *diciplina){
    // feito com ajuda de maria eloisa
    int tam = strlen(diciplina);
    // Só é permitidos 1 ou 2 matérias por vez
    // string que contem todas as iniciais referentes as diciplinas
    if ((tam != 2) && (tam != 1)){
        return 0;
    }
    // não permitir que o usuário digite duas letras iguais
    else if (tam == 2 && diciplina[0] == diciplina[1]){
        return 0;
    }
    letra_maiuscula(diciplina);
    int cont = 0;
    // permitir que o usuário digite a letra da maneira que preferir
    // apos isso chamara essa função que tratara os dados
    
    // um array com as iniciais das letras das matérias
    char materia[] = "PIEAHGLOSMBQF";
    // caso o usuário digitar só uma letra cairá nesse if
    if (tam == 1){
        // rodará 13 vezes que é referente a quantidade de diciplinas
        for (int i = 0; i < 13; i++){
            // diciplina [0] referindo ao primeiro índice
            if (diciplina[0] == materia[i]){
                return 1;
            }
        }
    }
    // caso o usuário digitar duas matérias
    else if (tam == 2){
        // esse for vai rodar 2 vezes para pegar ambas as posições
        for (int i = 0; i < 2; i++){
            // rodará 13 vezes que é referente a quantidade de diciplinas
            for (int j = 0; j < 13; j++){
                if (diciplina[i] == materia[j]){
                    cont++;
                }
            }
        }
        // para poder rodar duas vezes e conferir ambos os caracter
        if (cont != 2){
            return 0;
        }
        else{
            return 1;
        }
    }
    // verificar a questão dos espaços e a ocorrência de números
    for (int i = 0; i < tam; i++){
        if (!isalpha(diciplina[i]) && !isspace(diciplina[i])){
            return 0;
        }
    }
    return 0;
}

// Criar Id de forma nativa
// Feito com a ajuda do Chat Gpt e com Consultas no site StackOverflow
// Adapatado por Maria Eloisa e Matheus Diniz
int criar_id_d(void){
    // Abrir o arquivo
    FILE *arquivo = fopen("Diciplina.dat", "rb");
    if (arquivo == NULL){
        // caso o arquivo não exista começe com 1
        return 1;
        // Percorre o arquivo inteiro
        fseek(arquivo, 0, SEEK_END);
        // Para verificiar o tamanho do arquivo
        if ((long)ftell(arquivo) == 0){
            // caso o arquivo esteja vázio
            fclose(arquivo);
            return 1;
        }
    }
    else{
        // Posicione o ponteiro no início do último registro
        // Ver a última estrutura Adicionada

        // long adicionada para evitar problemas de conversão pelo sizeof, para um valor negativo, causando um estouro no fseek
        fseek(arquivo, -((long)sizeof(Diciplina)), SEEK_END);
        // Agora você pode ler o último registro usando fread

        Diciplina ultstruct;
        fread(&ultstruct, sizeof(Diciplina), 1, arquivo);

        // Obtenha o ID do último registro e incremente
        int id = ultstruct.id + 1;

        fclose(arquivo); // Feche o arquivo aqui
        return id;
    }
}

void gravardiciplinas(Diciplina *dic){
    FILE *fd; // File Diciplina
    fd = fopen("Diciplina.dat", "ab");
    if (fd == NULL){
        printf("Erro na recuperação dos dados da Diciplinas!\n");
        return;
    }
    fwrite(dic, sizeof(Diciplina), 1, fd);
    fclose(fd);
}

void exibir_diciplinas(Diciplina *dic,Professor* prof){
    char estado[16];
    if ((dic == NULL) || (dic->status == 'I')){
        printf("\nEsta Diciplinas não foi cadastrada no sistema!\n");
    }
    else{
        printf("\n ********Informações da diciplina********");
        printf("\nNome do professor:%s\n",prof->nome);
        printf("CPF do Professor:%s\n", dic->cpf);
        printf("Nome da diciplina:%s\n", dic->diciplina);
        printf("Id da diciplina:%d\n", dic->id);
        printf("\n");
        if (dic->status == 'A'){
            strcpy(estado, "Diciplina Ativa");
        }
        else if (dic->status == 'I'){
            strcpy(estado, "Fechada");
        }
    }
}

void listar_todas_diciplinas(void){
    FILE *fd;
    FILE *fp;
    Diciplina *dic;
    Professor *prof;
    prof=(Professor*)malloc(sizeof(Professor));
    dic = (Diciplina *)malloc(sizeof(Diciplina));
    fd = fopen("Diciplina.dat", "rb");
    fp=fopen("Professor.dat","rb");
    if ((fd == NULL) || (fp==NULL)){
        printf("Nenhuma diciplina ou professor cadastrado!\n");
        return;
    }
    while (fread(dic, sizeof(Diciplina), 1, fd)){
        if ((dic->status != 'I')){
            rewind(fp);
            while(fread(prof, sizeof(Professor), 1, fp)){
                if (((strcmp(prof->cpf,dic->cpf)==0))){
                    exibir_diciplinas(dic,prof);
                }
            }
        }
    }
    fclose(fd);
    free(dic);
    fclose(fp);
    free(prof);
}

//feito com a ajuda de marlison silva chat

void procura_diciplinas(int id){
    FILE *fd;
    FILE *fp;
    Diciplina *dic;
    Professor *prof;
    prof=(Professor*)malloc(sizeof(Professor));
    dic = (Diciplina *)malloc(sizeof(Diciplina));
    fd = fopen("Diciplina.dat", "rb");
    fp=fopen("Professor.dat","rb");
    int cont=0;
    if ((fd == NULL) || (fp==NULL)){
        printf("\nNenhuma diciplina cadastrada ou nenhum professor no sistema!\n");
        return;
    }
    //irá realizar a leitura de ambos os arquivos
    while (fread(dic, sizeof(Diciplina), 1, fd)){
        if ((dic->status != 'I') && (dic->id==id)){
            while(fread(prof, sizeof(Professor), 1, fp)){
                if (((strcmp(prof->cpf,dic->cpf)==0))){
                    exibir_diciplinas(dic,prof);
                    cont++;
                }
            }
        }
    }if(!cont){
        printf("\nEssa diciplina não existe no sistema ou ainda não foi cadastrado!\n");
    }
    fclose(fd);
    free(dic);
    free(prof);
    fclose(fp);
}

// feito com a ajuda de marlison silva chat gpt e adapatada por matheus diniz
void remover_diciplinas(int id){
    FILE *fd;
    Diciplina *dic;
    dic = (Diciplina *)malloc(sizeof(Diciplina));
    fd = fopen("Diciplina.dat", "r+b");
    int cont=0;
    if (fd == NULL){
        printf("\nNenhuma diciplina cadastrada!\n");
        return;
    }
    while (fread(dic, sizeof(Diciplina), 1, fd)){
        if ((dic->id == id) && (dic->status == 'A')){
            cont++;
            dic->status = 'I';
            fseek(fd, -1 * (long)sizeof(Diciplina), SEEK_CUR);
            fwrite(dic, sizeof(Diciplina), 1, fd);
            printf("\nDiciplina excluída!\n");
            break;
        }
    }
    if (!cont){
        printf("\nDiciplina não encontrada!\n");
    }
    fclose(fd);
    free(dic);
}
void att_diciplinas(int id){
    FILE *fd;
    FILE *fp;
    Diciplina *dic;
    Professor *prof;
    prof=(Professor*)malloc(sizeof(Professor));
    dic = (Diciplina *)malloc(sizeof(Diciplina));
    fd = fopen("Diciplina.dat", "rb");
    fp=fopen("Professor.dat","rb");
    int esc=-1;
    int cont=0;
    if ((fd == NULL) || (fp==NULL)){
        printf("\nNenhuma diciplina cadastrada ou nenhum professor cadastrado no sistema!\n");
        return;
    }
    while (fread(dic, sizeof(Diciplina), 1, fd)){
        if ((dic->id == id) && dic->status == 'A'){
            while(fread(prof, sizeof(Professor), 1, fp)){
                if (((strcmp(prof->cpf,dic->cpf)==0))){
                    cont++;
                    do{
                        esc=-1;
                        system("clear||cls");
                        printf("========================================================\n");
                        printf("   *************** Atualizar Diciplina ***************      \n");
                        printf("                                                        \n");
                        printf("               o que deseja atualizar?                  \n");
                        printf("              Diciplina[\033[31m1\033[0m] - Voltar[\033[31m0\033[0m]\n");
                        printf("                                                        \n");
                        printf("Dados cadastrados no sistema:\n");
                        printf("Nome do professor:%s",prof->nome);
                        printf("\nCPF do professor:%s", dic->cpf);
                        printf("\nNome da(s) Diciplina(s):%s\n", dic->diciplina);
                        printf("========================================================\n");
                        printf("\n");
                        printf("Qual opção deseja atualizar:");
                        fflush(stdin);
                        scanf("%d", &esc);
                        getchar();
                        fflush(stdin);
                        switch (esc){
                            case 1:
                                diciplinas();
                                ler_diciplinas(dic->diciplina);
                                printf("Alteração realizada!\n");
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
                        fseek(fd, -1 * (long)sizeof(Diciplina), SEEK_CUR);
                        fwrite(dic, sizeof(Diciplina), 1, fd);
                        fclose(fd);
                    } while (esc != 0);
                }
            }if (!cont){
                printf("Diciplina não encontrado!\n");
            }
        }
    }
    fclose(fd);
    free(dic);
    fclose(fp);
    free(prof);
}