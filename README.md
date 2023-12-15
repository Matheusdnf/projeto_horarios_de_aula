![projeto2](https://github.com/Matheusdnf/projeto_horarios_de_aula/assets/142422460/ad07d984-9941-4a9e-bc32-38a912675a1e)

# Projeto_horarios_de_aula
Trata-se de um sistema de gestão de horários de aula desenvolvido em linguagem C.
#
UFRN - Universidade Federal do Rio Grande do Norte.\
CERES - Centro de Ensino Superior do Seridó.\
BSI - Bacharelado em Sistemas de Informação.\
DCT1106 - Programação - Flavius Gorgônio.\
Desenvolvido por @matheusdnf\

**SE POSSÍVEL TESTE EM LINUX OU NO REPLIT**\
o projeto contem algumas validações que em sua maioria funciona apenas no linux ou que pode dar algum erro no Windows,podendo ocorrer do projeto ser encerrado,mas é só tentar novamente que ele será exectuado
   

### Como utilizar
O sistema é dividido em 6 módulos:
* **Aluno**
  - Irá dispor dos dados do aluno, como `Nome`, `CPF`, `Email` e `Telefone`.
* **Professor**
  - Irá dispor dos dados do professor, como `Nome`, `CPF`, `Email` e `Telefone`.
* **Turma**
  - Será criada uma turma escolhendo o nível entre:
    - (`I-infantil` do 1° ao 5° ano, `F-Fundamental` do 6° ao 9° ano e `M-Ensino médio` do 1° ao 3° ano).
    - No fim, coloque a sala entre (A, B ou C).
    - Após isso, será dado um `nome` à turma, criado a sua escolha, podendo apenas conter letras.
* **Matrícula**
  - Relacionará uma chave referente ao aluno e a uma turma cadastrada.
  - A chave em questão é o `CPF` do aluno que se conecta com uma das `turmas` já cadastradas.
  - Seria o nome da turma, exemplo: `F6A`.
* **Disciplina**
  - Atrelará uma `disciplina` a um professor já cadastrado, `professor`. Essa relação é realizada através do `CPF` do professor e uma das `disciplinas` disponíveis no programa.
* **Horário**
  - No horário, será colocado o `professor` que irá ministrar a aula, sendo o seu `CPF` a chave.
  - Será cadastrada a `disciplina` ministrada pelo `professor`, podendo ser apenas uma das `disciplinas` atreladas a ele.
  - Será colocada a `turma` que já foi cadastrada, como dado exemplo anteriormente.
  - Irá ser decido o `turno` que ocorrerá a aula entre (M-Manhã,T-Tarde,N-Noite)
  - Será colocado o `dia da semana` (2-segunda,3-terça...6-Sexta)
  - o `periodo` está relacionado aos horário se será (1°h,2°...6°)
## Relatórios
O projeto conta com alguns relatórios, entre eles informando as informações do que foram cadastrado no decorrer do programa\
e a filtragem de algumas informações específicas
## Para compilar o projeto
- Para rodar o projeto, você irá precisar do compilador para linguagem C instalado em sua máquina.

- Com isso sendo feito, irá criar alguma pasta pelo terminal e clonar o repositório abaixo:

```shell
https://github.com/Matheusdnf/projeto_horarios_de_aula.git
```
- Após isso você irá poder rodar o projeto!
  
O projeto irá dispor de um make file, essas são algumas alternativas para conseguir compilar o projeto\
```powershell
gcc *.c -o projeto -Wall
./projeto
```
```powershell
LINUX
make ou makefile
```
```powershell
WINDOWS
mingw32-make
