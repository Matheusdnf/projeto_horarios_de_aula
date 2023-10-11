//struct diciplina
typedef struct diciplina {
    char nome[100]; //referente ao nome do professor
    char diciplina[3];
} Diciplina;
//funções do módulo diciplina
void menu_diciplina(void);
void cadastrar_diciplina(void);
void buscar_diciplina(void);
void atualizar_diciplina(void);
void excluir_diciplina(void);
void relatorio_diciplina(void);
//funções para validar as diciplinas
int valida_diciplina(char *diciplina);
void ler_diciplina(char *diciplina);
void diciplinas(void);