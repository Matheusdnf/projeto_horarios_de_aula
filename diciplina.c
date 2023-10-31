#include "global.h" //incluede para deixar opc global 
#include "diciplina.h"
#include "valida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//Apelido struct Global
Diciplina* dic; //diciplina

void menu_diciplina(void) {
    while (opc!=0){
        system("clear||cls");   
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Diciplina ******************       \n");
        printf("          1 - Cadastrar Diciplina                          \n");
        printf("          2 - Pesquisar Diciplina                          \n");
        printf("          3 - Atualizar informações da Diciplina           \n");
        printf("          4 - Excluir Diciplina                            \n");
        printf("          5 - Relatório das Diciplinas                     \n");
        printf("          0 - Voltar                                       \n");
        printf("===========================================================\n");
        printf("\n");
        printf("Escolha uma das opções:");
        scanf("%s",&opc);
        switch (opc){
            case '1':
                dic=cadastrar_diciplina();
                gravardiciplina(dic);
                break;
            case '2':
                buscar_diciplina();
                break;
            case '3':
                atualizar_diciplina();
                break;
            case '4':
                excluir_diciplina();
                break;
            case '5':
                relatorio_diciplina();
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


Diciplina* cadastrar_diciplina(void) {
    system("clear||cls");   
    dic=(Diciplina*)malloc(sizeof(Diciplina));
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Cadastrar Diciplina *************   \n\n");
    printf("                                                        \n");
    printf("Pode ser 1 ou 2 diciplinas\n"); 
    diciplinas();
    ler_diciplina(dic->diciplina);
    printf("Digite o nome do professor\n");
    ler_nome(dic->nome);
    dic->id=criar_id_d();
    dic->status='A';
    printf("                                                        \n");
    printf("Dados cadastrados!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");getchar(); //para aparecer o menu e ele não sair rapidamente
    return dic;
}

void buscar_diciplina(void) {
    system("clear||cls");
    printf("\n");  
    printf("========================================================\n");
    printf("    *************** Pesquisar Aluno *************     \n\n");
    printf("                                                        \n");
    printf("            Informe a diciplina:                        \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 

}

void atualizar_diciplina(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Diciplina *************   \n\n");
    printf("                                                        \n");
    printf("            Informe a diciplina:                        \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}

void excluir_diciplina(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Diciplina *************     \n\n");
    printf("                                                        \n");
    printf("            Informe a diciplina:                        \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void relatorio_diciplina(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf(" *************** Relatório Das Diciplinas ************* \n\n");
    printf("                                                        \n");
    printf("       (informar todos as diciplinas cadastrado)        \n");
    printf("                                                        \n");
    listardiciplina();
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void diciplinas(void) {
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

//funções para a validação da diciplina
void ler_diciplina(char *diciplina) {
    int t;
    bool v=true,f=false;
    while (v) {
        fflush(stdin);
        printf("Digite a disciplina (somente maiúsculas):");
        fgets(diciplina, 3 , stdin);
        fflush(stdin);
        t = valida_diciplina(diciplina);
        if (t == 1) {
            printf("válido\n");
            v = f; // Saia do loop quando a disciplina for válida
        } else if (t == 0) {
            printf("inválido\n");
        }
    }
}

int valida_diciplina(char *diciplina) {
    int tam = strlen(diciplina);
    //Só é permitidos 1 ou 2 matérias por vez
    //string que contem todas as iniciais referentes as diciplinas
    if (tam != 2){
        return 0;
    }
    char *materia[]={
    "P","I","E","A","H",
    "G","L","O","S",
    "M","B","Q","F",};
    for (int i=0 ; i<13;i++){
        //compara se ambos os caracteres digitados estão presente no que foi digitado
        if (strncmp(diciplina, materia[i], 2) == 0 || strncmp(diciplina, materia[i], 1) == 0) {  
            return 1;
        }
    }
    //verificar a questão dos espaços e a ocorrência de números
    for (int i = 0; i < tam; i++) {
        if (!isalpha(diciplina[i]) && !isspace(diciplina[i])) {
            return 0;
        }
    }
    return 1;
}

//Criar Id de forma nativa 
//Feito com a ajuda do Chat Gpt e com Consultas no site StackOverflow 
//Adapatado por Maria Eloisa e Matheus Diniz 
int criar_id_d(void) { 
  //Abrir o arquivo 
  FILE *arquivo = fopen("Diciplina.dat", "rb"); 
  if (arquivo == NULL){
    //caso o arquivo não exista começe com 1
    return 1;
  // Percorre o arquivo inteiro  
  fseek(arquivo, 0, SEEK_END);  
  //Para verificiar o tamanho do arquivo 
  if ((long)ftell(arquivo)==0){
    //caso o arquivo esteja vázio
    fclose(arquivo);
    return 1;
  }
  } else { 
    // Posicione o ponteiro no início do último registro 
    //Ver a última estrutura Adicionada 

    //long adicionada para evitar problemas de conversão pelo sizeof, para um valor negativo, causando um estouro no fseek
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
