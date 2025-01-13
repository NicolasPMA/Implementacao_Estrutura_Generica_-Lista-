# Implementacao_Estrutura_Generica_(Lista)
Aplicando os conceitos estudados de Hashing.

## 🚀 Funcionalidade
- Inserir pessoa na lista.
- Remover pessoa pela matricula.
- Buscar pessoa pela matricula.
- Contar numero de alunos de um curso.
- Imprimir professores de maior salario.

## 💻 Tecnologia utilizada
- C: Linguagem de programação principal.

## 💡 Como funciona
Quando o rodar o código, um menu de opções será apresentado.
1. Inserir pessoa na lista.
- O usuário deve digitar o tipo desejado (Professor ou Aluno).
- Caso escolha Professor, o usuário deve fornecer a matrícula, nome e salário.
- Caso escolha Aluno, o usuário deve fornecer a matrícula, nome, curso e ano de ingresso.

2. Remover pessoa pela matricula.
- Para remover uma pessoa da lista, o usuário deve informar a matrícula da pessoa a ser removida.
 
3. Buscar pessoa pela matricula.
- O usuário deve informar a matrícula da pessoa que deseja buscar.

4. Contar numero de alunos de um curso.
- O usuário deve fornecer o nome do curso que deseja consultar a quantidade de alunos.
  
5. Imprimir professores de maior salario.
- Imprime os professores que possuem o maior salário da lista.

6. Sair.

## ⚙ Como o código funciona

O código é feito a partir dos conceitos de estrutura genérica. No código, fiz uma lista genérica que armazena Alunos e Professores, cada um com suas características específicas.
A estrutura engloba informações iguais das structs Aluno e Professor em uma única estrutura Pessoa. Além disso, o código é estruturado em uma lista encadeada.

Conceitos utilizados:
- Estrutura genérica.
- Lista encadeada.
