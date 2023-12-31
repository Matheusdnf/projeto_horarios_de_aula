#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "valida.h"

//função responsável pela leitura do telefone e validação
void ler_telefone(char *telefone) {
    int t;
    //função inpirada na de @Claudio-Arauj
    do {
        printf("Digite o telefone com DDD:");
        fgets(telefone, 15 , stdin);
        //remover o //n, função pega de @Lleusxam
        telefone[strlen(telefone)-1]=0;
        t = valida_telefone(telefone);
        if (t == 0) {
        printf("Telefone inválido,Certifiquisse de que tenha colocado DDD ou só números!\n");
    }
  } while (t != 1);
}

int valida_telefone(char *telefone) {
    //uma lista com os ddds existentes no brasil
    char *ddd[] = {
        "11", "12", "13", "14", "15", "16", "17", "18", "19",
        "21", "22", "24", "27", "28", "31", "32", "33", "34",
        "35", "37", "38", "41", "42", "43", "44", "45", "46",
        "47", "48", "49", "51", "53", "54", "55", "61", "62",
        "63", "64", "65", "66", "67", "68", "69", "71", "73",
        "74", "75", "77", "79", "81", "82", "83", "84", "85",
        "86", "87", "88", "89", "91", "92", "93", "94", "95",
        "96", "97", "98", "99"
    };
    int tam = strlen(telefone);
    // Deve ter no mínimo 12 caracteres (incluindo '\n') e o ddd
    if (tam != 11) {
        return 0;
    }

    // Verificar se os primeiros 2 caracteres são um DDD válido
    // rodou 81 vezes por causa da quantidade de ddd
    for (int i = 0; i < 81; i++) {  
        //o strncmp compara os dois primeiros caracter de ambos
        if (strncmp(telefone, ddd[i], 2) == 0) {
            // Encontrou um DDD válido, agora verifique se os outros caracteres são dígitos
            for (int j = 2; j < 11; j++) {
                if (!isdigit(telefone[j])) {
                    return 0; // Contém caracteres não numéricos
                }
            }
            return 1; // Telefone válido
        }
    }
    return 0; // DDD inválido
}

// Função personalizada para verificar se um caractere é uma letra (incluindo
// acentos) Desenvolvida com akuda do chat gpt
bool eh_letra_acentuada(char c) { // recebe uma letra por vez
  // um char com as palavras que possam vir a ser acentuadas
  char letras_acentuadas[] = "ÁÀÂÃÉÈÊÍÌÎÓÒÔÕÚÙÛÇáàâãéèêíìîóòôõúùûç";
  // ela roda um loop que termina até o caracter nulo do fgets
  for (int i = 0; letras_acentuadas[i] != '\0'; i++) {
    // aí se a letra em questão for igual ao char letras_acentuadas retornará
    // vdd
    // esse loop e esse if verificiarão toda as letras
    if (c == letras_acentuadas[i]) {
      return true;
    }
  }
  // verifica se a letra c é uma letra ou um espaço em branco
  return isalpha(c) || c == ' ';
}

// função de leitura e validação do nome
void ler_nome(char *nome) {
  int t;
  do {
    printf("Digite o nome:");
    fgets(nome, 100, stdin);
    // remover o \n
    nome[strlen(nome) - 1] = '\0'; // Alteração para '\0'
    t = valida_nome(nome);
    if (t == 0) {
      printf("Nome inválido. Certifique-se de que não colocou números ou "
             "espaços a mais!\n");
    }
  } while (t != 1);
}
int valida_nome(char *nome) {
  // Pega o tamanho da variável nome
  int tam = strlen(nome);
  // Só permite nome maiores que 2 letras e menores que 100
  if (tam < 3 || tam > 100) {
    return 0;
  }
  // Verifica se o usuário não digitou um espaço em branco no início ou no final
  if (isspace(nome[0]) || isspace(nome[tam - 1])) {
    return 0;
  }
  // Verifica se o nome contém letras acentuadas ou caracteres especiais
  for (int j = 0; j < tam; j++) {
    if (!isalpha(nome[j]) && !eh_letra_acentuada(nome[j])) {
      return 0;
    }
  }
  // Verifica se dois espaços em branco consecutivos
  for (int i = 0; i < tam - 2; i++) {
    if (isspace(nome[i]) && isspace(nome[i + 1])) {
      return 0;
    }
  }

  return 1;
}

// feito com a ajuda do chat gpt
bool eh_caractere_especial(char c) {
  // Caracteres especiais que você deseja verificar
  char caracteres_especiais[] = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~";
  // Loop para verificar se o caractere está na lista de caracteres especiais
  for (int i = 0; caracteres_especiais[i] != '\0'; i++) {
    if (c == caracteres_especiais[i]) {
      return true;
    }
  }
  // Verifica se o caractere é um espaço em branco ou não alfanumérico
  return !isalnum(c) && c != ' ';
}


void removerCaracteresNaoNumericos(char cpf[]) {
    //feita pelo chat gpt
    int len = strlen(cpf);
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9') {
            cpf[k] = cpf[i];
            k++;
        }
    }
    cpf[k] = '\0'; // Adicione o terminador nulo ao final
}

int validarCPF(char cpf[]) {
    //validação de cpf retirado do site http://wurthmann.blogspot.com/ e sofreu algumas adpatações por Matheus Diniz
    // Remova os caracteres de pontuação (.) e hífen (-) do CPF
    removerCaracteresNaoNumericos(cpf);

    int i, j, digito1 = 0, digito2 = 0;

    if (strlen(cpf) != 11)
        return 0;
    else if ( 
             (strcmp(cpf, "22222222222") == 0) || (strcmp(cpf, "33333333333") == 0) ||
             (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
             (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) ||
             (strcmp(cpf, "88888888888") == 0) || (strcmp(cpf, "99999999999") == 0))
        return 0;
    else {
        // Digito 1
        for (i = 0, j = 10; i < 9; i++, j--) {
            digito1 += (cpf[i] - '0') * j;
        }
        digito1 %= 11;
        if (digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if ((cpf[9] - '0') != digito1)
            return 0;

        // Digito 2
        for (i = 0, j = 11; i < 10; i++, j--) {
            digito2 += (cpf[i] - '0') * j;
        }
        digito2 %= 11;
        if (digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if ((cpf[10] - '0') != digito2)
            return 0;
    }

    return 1;
}

//função para a leitura e validação do cpf
void ler_cpf(char cpf[]) {
    //função reutilizável para realizar a leitura do cpf
    int c;
    do{
        printf("Digite o CPF: ");
        scanf("%s", cpf);
        //função utilizada para limpar o buffer
        limpar_buffer();
        c=validarCPF(cpf);
        if (c == 0) {
            printf("CPF inválido!\n");
        }
    }while(c!=1);
}

//feito com a ajuda do chat gpt
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Lê e descarta cada caractere até encontrar uma nova linha ('\n') ou o fim do arquivo (EOF)
    }
}


void ler_email(char email[]) {
    //função reutilizável para realizar a leitura do email
    int e;
    do{
        printf("Digite seu Email:");
        scanf("%[-._@A-Za-z0-9]", email);
        //função utilizada para limpar o buffer
        limpar_buffer();
        e = validate_email(email);
        if (e == 0) {
            printf("Email inválido!\n");
        }
    }while(e!=1);
}
//função pega de MarlisonSilva
int validate_email(char email[]) {
    email = str_to_lower(email);
    char aux [255];
    if (!has_one_at_sign(email))
    {
        return 0;
    }
    
    if (strlen(email) >= 7 && !has_space(email)) {
        aux[0] = '\0';
        // prefixo
        int pos = 0;
        do {
            aux[pos] = email[pos];
            pos++;
        } while ((email[pos] != '\0') && (email[pos] != '@'));
        aux[pos] = '\0';

        if (strlen(aux) >= 1 && strlen(aux) <= 64){
            // primeira letra não é alfa-numérica e a última é um ponto
            if(!isalnum(aux[0]) || aux[strlen(aux) - 1] == '.') {
                return 0;
            }
        } else {
            return 0;
        }
        
        // caso não haja mais 2 caracteres após o @
        if (strlen(email) < (pos + 2)) {
            return 0;
        }

        // domínio
        pos = pos + 1;
        int i = 0;
        aux[0] = '\0';

        do {
            aux[i] = email[pos];
            pos++;
            i++;
        } while ((email[pos] != '\0') && (email[pos] != '.'));
        aux[i] = '\0';

        // domínio de tamanho incorreto
        if (strlen(aux) >= 2 && strlen(aux) <= 253){
            // primeira e última letra não é alfa-numérica
            if(!isalnum(aux[0]) || !isalnum(aux[strlen(aux) - 1])) {
                return 0;
            }
        } else {
            return 0;
        }

        // caso não haja mais 2 caracteres após o .
        if (strlen(email) < (pos + 2)) {
            return 0;
        }
        pos = pos + 1;
        i = 0;
        aux[0] = '\0';
        do {
            aux[i] = email[pos];
            pos++;
            i++;
        } while (email[pos] != '\0');
        aux[i] = '\0';
        
        // tamanho do top level domain incorreto
        if (strlen(aux) >= 2 && strlen(aux) <= 253){
            // primeira e última letra não é alfa-numérica
            if(!isalnum(aux[0]) || !isalnum(aux[strlen(aux) - 1])) {
                return 0;
            }
            
        } else {
            return 0;
        }
        
        return 1;

    }
    return 0;
}
//função pega de MarlisonSilva
int has_one_at_sign(char* str) {
    int i = 0;
    int found = 0;
    do
    {
        if (str[i] == '@')
        {
            found++;
        }
        i++;
    } while (str[i] != '\0');
    
    if (found == 1)
    {
        return true;
    }
    return false;
}

//auxiliares
int has_space(char* str) {
    //função pega de marlison silva @MarlisonSilva
    int i = 0;
    do
    {
        if (isspace(str[i]))
        {
            return true;
        }
        i++;
    } while (str[i] != '\0');
    
   return false;
}
//auxiliares
char* str_to_lower(char* str){
    //função pega de marlison silva @MarlisonSilva
    char *aux = str;
    int i = 0;
    do
    {
        aux[i] = tolower(str[i]);
        i++;
    } while (aux[i] != '\0');
    return aux;
}

//passar todas as letras para ficaram maiusculas 
void letra_maiuscula(char* algo) {
    //pega o tamanho para saber até onde tera que rodar
    int tam = strlen(algo);
    //o i será menor que o tamanho de caracter para saber o final
    for (int i = 0; i < tam; i++) {
        //irá passar letra por letra na função toupper
        algo[i] = toupper(algo[i]);
    }
}
// não esquecer  scanf(" %[^\n]", palavra);

void ler_turma(char *turma){
    limpar_buffer();
    int t;
    do{
        printf("Digite sua turma:");
        fgets(turma,5,stdin);
        letra_maiuscula(turma);
        turma[strlen(turma)-1]=0;
        t = valida_turma(turma);
        if (t == 0){
            printf("Turma Inválida\n");
        }
    }while(t!=1);
}

int valida_turma(char* turma){
    int tam = strlen(turma);
    //não pode ser uma turma com mais de 3 caracter
    //ajustar na estruct
    if(tam!=3){
        return 0;
    }
    char subsequente[]={'A','B','C'};
    //verifica a posição da string desejada
    if(strchr(subsequente,turma[2])==NULL){
        return 0;
    }
    //verificar se na posição turma[0] é um desses caracter, para atender os números específicos
    if (turma[0] == 'I'){
        for (int i = 1; i < 6; i++){
            //atoi tranforma um int em char
            if ((atoi(&turma[1])== i)){
                return 1;

            }
        }
    }
    else if (turma[0] == 'F'){
        for (int i = 6; i < 10; i++){
            if ((atoi(&turma[1])== i)){
                return 1;
            }
        }
    }
    else if (turma[0] == 'A'){
        for (int i = 1; i < 4; i++){
            if ((atoi(&turma[1])== i)){
                return 1;
            }
        }
    }
    return 0;
}

int valida_s_ou_n(char escolha) {
    if (escolha!='S' && escolha!='N'){
        return 0;
    }
    return 1;
}

int decidir_excluir(void){
    char delete;
    do{
        printf("\nCerteza que deseja excluir? (S/N)");
        scanf("%c", &delete);
        letra_maiuscula(&delete);
        limpar_buffer();
        if (!valida_s_ou_n(delete)) {
            printf("Digite algo válido (S/N)!\n");
        }
    }while (delete != 'S' && delete != 'N'); 
    return (delete == 'S');
}

char obter_resposta(void) {
    char escolha;
    do {
        printf("Deseja tentar novamente (S/N)? ");
        scanf(" %c", &escolha);
        letra_maiuscula(&escolha);
        getchar();
        // validar a resposta
        if (!valida_s_ou_n(escolha)) {
            printf("Digite algo válido (S/N)!\n");
        }
        
    } while (escolha != 'S' && escolha != 'N');
    return escolha;
}

char escolher_filtro(void){
    char situ;
    do{
        printf("Digite qual situação deseja ver (A-Ativo|I-Inativos):");
        scanf(" %c",&situ);
        limpar_buffer();
        letra_maiuscula(&situ);
        if(situ!='A' && situ!='I'){
            printf("Digite algo válido\n");
        }
    }while (situ != 'A' && situ != 'I');
    return situ;
}

