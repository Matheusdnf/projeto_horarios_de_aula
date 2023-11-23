// //conectar o aluno a turma
// //cpf e código da turma
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <matricula.h>
// void menu_matricula(void){
//     int opc=-1;
//     do{
//         opc=-1;
//         system("clear||cls");
//         Matricula* matri;
//         printf("\n");
//         printf("===========================================================\n");
//         printf("     ****************  Menu Matricula ******************       \n");
//         printf("          1 - Cadastrar Matricula                              \n");
//         printf("          2 - Pesquisar Matricula                              \n");
//         printf("          3 - Atualizar informações da Matricula               \n");
//         printf("          4 - Excluir Matricula                                \n");
//         printf("          5 - Relatório da Matricula                         \n");
//         printf("          0 - Voltar                                       \n");
//         printf("===========================================================\n");
//         printf("\nDigite o que deseja fazer: ");
//         scanf("%d", &opc);
//         switch (opc){
//             case 1:
//                 matri=cadastrar_matricula();
//                 gravar_matricula(matri);
//                 break;
//             case 2:
//                 buscar_matricula();
//                 break;
//             case 3:
//                 atualizar_matricula();
//                 break;
//             case 4:
//                 excluir_matricula();
//                 break;
//             case 5:
//                 relatorio_matricula();
//                 break;
//             case 0:
//                 break;
//             default:
//                 printf("Opção Inválida!\n");
//                 printf("Digite enter para continuar...");
//                 getchar();
//                 break;
//         }
//     } while (opc != 0);
// }

// Matricula *cadastrar_matricula(void){
//     system("clear||cls");
//     Matricula* matri; //t-turm
//     matri = (Matricula *)malloc(sizeof(Matricula));
//     printf("\n");
//     printf("========================================================\n");
//     printf("    ************* Cadastrar matricula *************     \n\n");
//     //ler o cpf do aluno
//     //colocar  a matrícula do aluno
//     matri->status = 'A';
//     printf("                                                        \n");
//     printf("Dados da matricula cadastrada!\n");
//     printf("========================================================\n");
//     printf("\n");
//     printf("Digite enter para continuar...");
//     getchar(); // para aparecer o menu e ele não sair rapidamente
//     return matri;
//     free(matri);
// }

// void buscar_matricula(void){
//     system("clear||cls");
//     // char cpf[15]; ou utilizar a matrícula com busca
//     printf("\n");  
//     printf("========================================================\n");
//     printf("    *************** Pesquisar Matricula *************     \n\n");
//     printf("                                                        \n");
//     // ler_cpf(cpf);
//     // procura_matricula(cpf);
//     printf("                                                        \n");
//     printf("========================================================\n");
//     printf("\n");
//     printf("Digite enter para continuar...");
//     getchar();
// }

// void atualizar_matricula(void){
//     system("clear||cls");
//     // char cpf[15];
//     printf("\n");
//     printf("========================================================\n");
//     printf("    *************** Atualizar Matricula *************     \n\n");
//     printf("                                                        \n");
//     printf("      Informe o código da Matricula que será atualizada     \n");
//     printf("                                                        \n");
//     // ler_cpf(cpf);
//     printf("                                                        \n");
//     // att_matricula(cpf);
//     printf("                                                        \n");
//     printf("========================================================\n");
//     printf("\n");
//     printf("Digite enter para continuar...");
//     getchar();
// }

// void excluir_matricula(){
//     system("clear||cls");
//     // char cpf[15];
//     printf("\n");
//     printf("========================================================\n");
//     printf("    *************** Excluir Matricula *************       \n\n");
//     printf("                                                        \n");
//     // ler_cpf(cpf);
//     // remover_matricula(cpf);
//     printf("                                                        \n");
//     printf("========================================================\n");
//     printf("\n");
//     printf("Digite enter para continuar...");
//     getchar();
// }

// void relatorio_matricula(void){
//     system("clear||cls");
//     printf("\n");
//     printf("========================================================\n");
//     printf("    *************** Relatório Matricula *************       \n\n");
//     printf("                                                        \n");
//     printf("(informar todas as Matriculas realizadas)                   \n");
//     listar_todos_matricula();
//     printf("========================================================\n");
//     printf("\n");
//     getchar();
//     printf("Digite enter para continuar...");
//     getchar();
// }
// void gravar_matricula(Matricula *matri){
//     FILE *fm; // File Turma
//     fm = fopen("Matricula.dat", "ab");
//     if (fm == NULL){
//         printf("Erro na recuperação dos dados da Matrícula!\n");
//         return;
//     }
//     fwrite(matri, sizeof(Matricula), 1, fm);
//     fclose(fm);
//     free(matri);
// }



// void exibicao_Matricula(Matricula *matri){
//     char estado[17];
//     if ((matri == NULL) || (matri->status == 'I')){
//         printf("\nEsta Matricula não existe no sistema!\n");
//     }
//     else{
//         printf("\n********Dados Da Matricula********");
//         // printf("\nMatrícula:%s", matri->cod);
//         // printf("\nCpf do aluno:%s\n", matri->nome);
//         if (matri->status == 'A'){
//             strcpy(estado, "Matricula ativa");
//         }
//         else if (matri->status == 'I'){
//             strcpy(estado, "Matricula Fechada");
//         }
//     }
// }

// void listar_todas_matricula(void){
//     FILE *fm;
//     Matricula *matri;
//     matri = (Matricula*)malloc(sizeof(Matricula));
//     fm = fopen("Matricula.dat", "rb");
//     if (fm == NULL){
//         printf("\nNenhuma Matricula cadastrada!\n");
//         return;
//     }
//     while (fread(matri, sizeof(Matricula), 1, fm)){
//         if (matri->status != 'I'){
//             exibicao_matricula(matri);
//         }
//     }
//     fclose(fm);
//     free(matri);
// }

// // feito com a ajuda de marlison silva
// // void procura_matricula(char *cod){
// //     FILE *fm;                                     utilizar cpf ou a matrícula
// //     Matricula *t;
// //     t = (Matricula *)malloc(sizeof(Matricula));
// //     fm = fopen("Matricula.dat", "rb");
// //     if (t == NULL){
// //         printf("\tMatricula não encontrada!\n");
// //         return;
// //     }
// //     if (fm == NULL){
// //         printf("\nNenhuma Matricula cadastrada!\n");
// //         return;
// //     }
// //     while (fread(t, sizeof(Matricula), 1, fm)){
// //         if ((strcmp(t->cod, cod) == 0) && (t->status == 'A')){
// //             exibicao_matricula(t);
// //         }
// //     }
// //     fclose(fm);
// //     free(t);
// // }

// // feito com a ajuda de marlison silva chat gpt e adapatada por matheus diniz

// // void remover_matricula(char *cod){
// //     FILE *fm;                                      usar matrícula ou cpf
// //     Matricula *matri;
// //     int encontra = 0;
// //     t = (Matricula *)malloc(sizeof(Matricula));
// //     fm = fopen("Matricula.dat", "r+b");
// //     if (fm == NULL){
// //         printf("\nNenhuma Matricula foi cadastrada!\n");
// //         return;
// //     }
// //     while (fread(matri, sizeof(Matricula), 1, fm)){
// //         if ((strcmp(t->cod, cod) == 0) && (t->status == 'A')){
// //             encontra = 1;
// //             t->status = 'I';
// //             fseek(fm, -1 * (long)sizeof(Matricula), SEEK_CUR);
// //             fwrite(matri, sizeof(Matricula), 1, fm);
// //             printf("\nMatricula excluída!\n");
// //             break; // Encerre o loop após a exclusão
// //         }
// //     }
// //     if (!encontra){
// //         printf("\nMatricula não encontrada!\n");
// //     }
// //     fclose(fm);
// // }

// void att_matricula(char *cod){
//     FILE *fm;
//     Matricula *t;
//     int encontra = 0;
//     int esc=-1;
//     t = (Matricula *)malloc(sizeof(Matricula));
//     fm = fopen("Matricula.dat", "r+b");
//     if (fm == NULL){
//         printf("\nNenhuma Matricula cadastrada!\n");
//         return;
//     }
//     while (fread(t, sizeof(Matricula), 1, fm)){
//         if ((strcmp(t->cod, cod) == 0) && (t->status == 'A')){
//             encontra = 1;
//             do{
//                 system("clear||cls");
//                 printf("========================================================\n");
//                 printf("   *************** Atualizar Matricula ***************      \n");
//                 printf("                                                        \n");
//                 printf("               o que deseja atualizar?                  \n");
//                 printf(" Nome da turma[\033[31m2\033[0m] - Voltar[\033[31m0\033[0m]    \n");
//                 printf("                                                        \n");
//                 printf("Dados cadastrados no sistema:\n");
//                 printf("Código da Turma:%s\n", t->cod);
//                 printf("Nome da turuma:%s\n", t->nome);
//                 printf("========================================================\n");
//                 printf("\n");
//                 printf("Qual opção deseja atualizar:");
//                 fflush(stdin);
//                 scanf("%d", &esc);
//                 fflush(stdin);
//                 getchar();
//                 switch (esc){
//                     case 1:
//                         ler_nome(t->nome);
//                         printf("\nAlteração realizada!\n");
//                         printf("\nDigite enter para continuar...");
//                         getchar();
//                         break;
//                     case 0:
//                         break;
//                     default:
//                         printf("\nOpção Inválida!\n");
//                         printf("Digite enter para continuar...");
//                         getchar();
//                         break;
//                 }
//                 fseek(fm, -1 * (long)sizeof(Turma), SEEK_CUR);
//                 fwrite(t, sizeof(Turma), 1, fm);
//                 fclose(fm);
//             } while (esc != 0);
//         }
//     }
//     if (!encontra){
//         printf("Turma não encontrada!\n");
//     }
//     fclose(fm);
//     free(t);
// }

