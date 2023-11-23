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
