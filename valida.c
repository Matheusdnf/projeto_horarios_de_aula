#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "valida.h"

bool v = true;
bool f = false;

void ler_telefone(char *telefone) {
    int t;
    while (v) {
        printf("Digite seu telefone:");
        fgets(telefone, 15, stdin);
        t = valida_telefone(telefone);
        if (t == 1) {
            printf("Telefone válido\n");
            v = f;  // Saia do loop quando o telefone for válido
        } else if (t == 0) {
            printf("Telefone inválido\n");
        }
    }
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
    if (tam != 12) {
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

// Função personalizada para verificar se um caractere é uma letra (incluindo acentos)
// Desenvolvida com akuda do chat gpt
bool eh_letra_acentuada(char c) {   //recebe uma letra por vez
    //um char com as palavras que possam vir a ser acentuadas
    char letras_acentuadas[] = "ÁÀÂÃÉÈÊÍÌÎÓÒÔÕÚÙÛÇáàâãéèêíìîóòôõúùûç"; 
    //ela roda um loop que termina até o caracter nulo do fgets
    for (int i = 0; letras_acentuadas[i] != '\0'; i++) {  
        // aí se a letra em questão for igual ao char letras_acentuadas retornará vdd
        //esse loop e esse if verificiarão toda as letras
        if (c == letras_acentuadas[i]) {
            return true;
        }
    }
    //verifica se a letra c é uma letra ou um espaço em branco 
    return isalpha(c) || c == ' ';
}

void ler_nome(char *nome) {
    int n;
    while (v) {
        printf("Digite seu nome:");
        fgets(nome, 100, stdin);
        n = valida_nome(nome);
        if (n == 1) {
            printf("válido\n");
            v=f;
        } else if (n == 0) {
            printf("inválido\n");
        }
    }
}

int valida_nome(char *nome) {
    // Pega o tamanho da variável nome
    int tam = strlen(nome);
    //só permite nome maiores que 2 letras 
    // é utilizado 3 para contar com o \n do teclado
    if (tam<3){
        return 0;
    }
    // Verificar se o usuário não digitou um espaço em branco,tanto no ínicio como no final
    if ((isspace(nome[0])) || (isspace(nome[tam - 2]))) {
        return 0;
    }
    //esse loop serve para procurar a questão de números
    for (int j = 0; j < tam - 1; j++) {
        if (!eh_letra_acentuada(nome[j])) {
            return 0;
        }
    }
    // Verifica se dois espaços em branco consecutivos
    for (int i = 0; i < tam - 2; i++) {
        if ((isspace(nome[i])) && (isspace(nome[i + 1]))) {
            return 0;
        }
    }
    return 1;
}
