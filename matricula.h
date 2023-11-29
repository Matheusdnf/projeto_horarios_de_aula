#ifndef matricula_h
#define matricula_h
//definição estrutura matrícula
typedef struct matricula{
    char cpf [15];
    char cod [7];
    char status;
}Matricula;
//telas do módulo matrícula
void menu_matricula(void);
 Matricula *cadastrar_matricula(void);
 void buscar_matricula(void);
 void atualizar_matricula(void);
 void excluir_matricula();
 void relatorio_matricula(void);
 //data base do módulo matricula
 void gravar_matricula(Matricula *matri);
 void exibicao_matricula(Matricula *matri);
 void listar_todas_matricula(void);
 void procura_matricula(char *cod);
 void remover_matricula(char *cod);
 void att_matricula(char *cod);
#endif