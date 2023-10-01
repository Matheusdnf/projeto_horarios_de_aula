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


