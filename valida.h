#include <stdbool.h>
//assinatura de funções que validaão o número do telefone
void ler_telefone(char *telefone);
int valida_telefone(char *telefone);
//funções de valida nome
bool eh_letra_acentuada(char c);
void ler_nome(char *nome);
int valida_nome(char *nome);
//funções para validar cpf
void removerCaracteresNaoNumericos(char cpf[]);
int validarCPF(char cpf[]);
void ler_cpf(char cpf[]);
//funções referente a validação de email
void ler_email(char email[]);
int validate_email(char email[]);
char* str_to_lower(char* str);
int has_space(char* str);
//limpar o buffer de entrada para quando for utilizado o scanf
void limpar_buffer();
//funções para validar as diciplinas
int valida_diciplina(char *diciplina);
void ler_diciplina(char *diciplina);
void diciplinas(void);
//validação dos horários
void ler_periodo(char* periodo); 
void ler_tempo(char* tempo);
void ler_dia(char* dia);
int valida_periodo(char* periodo); 
int valida_tempo(char* tempo);
int valida_dia(char* dia);