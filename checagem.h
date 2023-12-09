#ifndef checagem_h
#define checagem_h
#include "professor.h"
int verifica_existe_prof(char cpf[]);
int verifica_existe_aluno(char cpf[]);
int verificar_turma_existente(char cod[]);
int verifica_aluno_matriculado(char cpf[]);
void disciplina_por_professor(char cpf[]);
int valida_diciplina_professor(char *disciplina,char cpf[]);
int verifica_professor_com_disciplina(char cpf[]);
#endif