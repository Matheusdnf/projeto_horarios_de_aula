//struct diciplina
typedef struct diciplina {
    int id;
    char cpf[15]; //referente ao nome do professor
    char diciplina[3];
    char status;           //A-Ativo I-Inexistente 
    //char status;
} Diciplina;
//tela do módulo diciplina
void menu_diciplina(void);
Diciplina* cadastrar_diciplina(void);
void buscar_diciplina(void);
void atualizar_diciplina(void);
void excluir_diciplina(void);
void relatorio_diciplina(void);
//funções para validar as diciplinas
int valida_diciplina(char *diciplina);
void ler_diciplina(char *diciplina);
void diciplinas(void);
//função de criar id
int criar_id_d(void);
//gravação e exibição de dados
void gravardiciplina(Diciplina* dic);
//funções do crud
void exibir_diciplinas(Diciplina* dic);
void listar_todas_diciplina(void);
void procura_diciplina(int id);
void remover_diciplina(int id);
void att_diciplina(int id);