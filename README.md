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

O código é feito a partir dos conceitos de tabela de dispersão (tabela hash). O objetivo do código é ver na prática a funcionalidade da tabela Hash. 
A tabela de dispersão funciona a partir de uma chave simples, e através dela fazer uma busca rápida e obter o valor desejado. 
Nesse código, a chave escolhida é a matrícula dos alunos.

Conceitos utilizados:
- Criação de um arquivo (escrita e leitura).
- Função Hash.
- Tabela de dispersão.
