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
bool eh_caractere_especial(char c);
//funções referente a validação de email
void ler_email(char email[]);
int validate_email(char email[]);
char* str_to_lower(char* str);
int has_one_at_sign(char* str); 
int has_space(char* str);
//limpar o buffer de entrada para quando for utilizado o scanf
void limpar_buffer();
void letra_maiuscula(char* algo);
//validação de turma
void ler_turma(char *turma);
int valida_turma(char* turma);
int valida_s_ou_n(char escolha);
int decidir_excluir(void);
char obter_resposta(void);
char escolher_filtro(void);