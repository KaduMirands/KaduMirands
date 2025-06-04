#include <stdio.h>
#include <string.h>
struct Aluno {
    char nome[50];
    int matricula;
    float nota;
};
struct Professor {
   char nome[50];
   char disciplina[50];
   int sala;
};
int main() {
    struct Aluno aluno1; //definimos uma variável chamada aluno1 do tipo struct Aluno
    // Inicializando os membros
    aluno1.matricula = 101;
    aluno1.nota = 9.5;
    strcpy(aluno1.nome, "João"); // usando strcpy aqui
    printf("Nome: %s\nMatrícula: %d\nNota: %.2f\n", aluno1.nome, aluno1.matricula, aluno1.nota);
    struct Professor professor1;
    strcpy(professor1.nome, "Xavier");
    strcpy(professor1.disciplina, "Assuntos Aleatórios");
    professor1.sala = 120;
    printf("Nome: %s\nDisciplina: %s\nSala: %d\n", professor1.nome, professor1.disciplina, professor1.sala);
    return 0;
}

Criar uma struct Professor (Nome, Disciplina, Sala)
Depois, crie um professor usando essa estrutura
