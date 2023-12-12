#ifndef relatorio_h
#define relatorio_h
#include "aluno.h"
#include "horario.h"
#include "professor.h"
#include "disciplina.h"
#include "checagem.h"
#include "matricula.h"
#include "turma.h"
//telas do relatório
void tela_relatorio(void);
void relatorio_tudo(void);
void relatorio_filtro(void);
void tela_filtro_relatorio(void);
void escolha_relatorio(void);
void tela_relatorio_ordenado(void);
void relatorio_ordenado(void);
//relatório tabela com filtro de situação
void relatorio_tabela_aluno(char situ);
void relatorio_tabela_professor(char situ);
void relatorio_tabela_disciplinas(char situ);
void relatorio_tabela_h(char situ);
void relatorio_tabela_matricula(char situ);
void relatorio_tabela_turmas(char situ);
//relatório com filtro 
void filtro_disciplina_atrelada_professor(void);
void listar_professor_por_disciplina(char *diciplina);
void filtro_turno_horario(void);
void listar_h_por_turno(char *turno);
void filtro_diasemana_horario(void);
void listar_h_pelo_diasemana(char *dia);
void filtro_turno_horario(void);
void filtro_alunos_turma(void);
void relatorio_tabela_aluno_por_turma(char *turma);
void filtro_horario_turmas(void);
void listar_h_turma(char *turma);
void filtro_professores_turmas(void);
void professores_por_turma(char *turma);
//relatórios/listagens personalizadas
void listar_todos_professor_alt(void);
void listar_turma_cadastradas_alt(void);
void listar_alunos_cadastrados_alt(void);
void filtro_periodo_horario(void);
void listar_h_pelo_periodo(char *periodo);
void filtro_aulas_professor(void);
void listar_h_professor(char cpf[]);
//ordenação
void list_alf_aluno(void);
void list_alf_professor(void);
void list_alf_turma(void);
void list_alf_disciplina(void);
void list_alf_matricula(void);
void list_alf_h(void);
void gerar_lista_aluno(Aluno **list);
void gerar_lista_professor(Professor **list);
void gerar_lista_turma(Turma **list);
void gerar_lista_disciplina(Disciplina **list);
void gerar_lista_matricula(Matricula **list);
void gerar_lista_h(Horario **list);
void apagar_lista_aluno(Aluno **list);
void apagar_lista_professor(Professor **list);
void apagar_lista_turma(Turma **list);
void apagar_lista_disciplina(Disciplina **list);
void apagar_lista_matricula(Matricula **list);
void apagar_lista_h(Horario **list);
void exibir_lista_aluno(Aluno *aux);
void exibir_lista_professor(Professor *aux);
void exibir_lista_turma(Turma *aux);
void exibir_lista_disciplina(Disciplina *aux);
void exibir_lista_matricula(Matricula *aux);
void exibir_lista_h(Horario *aux);

#endif  