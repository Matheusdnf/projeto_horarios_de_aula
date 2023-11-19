#ifndef diciplina_h
#define diciplina_h
//struct diciplina
typedef struct diciplina {
    int id;
    char cpf[15]; //referente ao nome do professor
    char diciplina[4];
    char status;           //A-Ativo I-Inexistente 
    //char status;
} Diciplina;
//tela do módulo diciplina
void menu_diciplinas(void);
Diciplina* cadastrar_diciplinas(void);
void buscar_diciplinas(void);
void atualizar_diciplinas(void);
void excluir_diciplinas(void);
void relatorio_diciplinas(void);
//funções para validar as diciplinas
int valida_diciplinas(char *diciplina);
void ler_diciplinas(char *diciplina);
void diciplinas(void);
//função de criar id
int criar_id_d(void);
//gravação e exibição de dados
void gravardiciplinas(Diciplina* dic);
//funções do crud
void exibir_diciplinas(Diciplina* dic);
void listar_todas_diciplinas(void);
void procura_diciplinas(int id);
void remover_diciplinas(int id);
void att_diciplinas(int id);
#endif