#ifndef checagem_h
#define checagem_h
#include "professor.h"
void listar_todos_professor_alt(void);
void exibicao_professores_alt(Professor *prof);
int verifica_existe_prof(char cpf[]);
int verifica_existe_aluno(char cpf[]);
int verificar_turma_existente(char cod[]);
int verifica_aluno_matriculado(char cpf[]);
void listar_turma_cadastradas_alt(void);
void disciplina_por_professor(char cpf[]);
int valida_diciplina_professor(char *disciplina,char cpf[]);
#endif