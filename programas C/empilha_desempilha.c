#include <stdio.h>

#define TAMANHO_MAX 10 // Define o tamanho máximo da pilha
typedef struct {
    int itens[TAMANHO_MAX]; // Array que armazena os elementos da pilha
    int topo; // Índice do topo da pilha
} Pilha;

void inicializa(Pilha *p) {
    p->topo = -1;           }

int empilha(Pilha *p, int valor) {
    if (p->topo < TAMANHO_MAX - 1) {
        p->topo++;
        p->itens[p->topo] = valor;
        return 1; // Sucesso (poderia ser true)
    }
    return 0; // Falha: Pilha Cheia (poderia ser false)
}

int desempilha(Pilha *p, int *valor) { //aqui estamos usando a função
			//desempilha que explicamos anteriormente
    if (p->topo >= 0) {
        *valor = p->itens[p->topo];
        p->topo--;
        return 1; // Sucesso
    }
    return 0; // Pilha Vazia
}

    int main(){
    Pilha p;
    int valor;
    // Inicializa a pilha
    inicializa(&p);
    printf("O topo da pilha no momento é: %d\n",p.topo);
    //printf("O valor armazenado no topo é: %d", p.itens[p.topo]);
    // Empilha alguns valores
    empilha(&p, 10);
    printf("O topo da pilha no momento é: %d\n",p.topo);
    printf("O valor armazenado no topo é: %d\n", p.itens[p.topo]);
    empilha(&p, 20);
    printf("O topo da pilha no momento é: %d\n",p.topo);
    printf("O valor armazenado no topo é: %d\n", p.itens[p.topo]);
    empilha(&p, 30);
    printf("O topo da pilha no momento é: %d\n",p.topo);
    printf("O valor armazenado no topo é: %d\n", p.itens[p.topo]);
    desempilha(&p, &valor);
    printf("O topo da pilha depois de desempilhar é no momento: %d\n",p.topo);
    printf("O valor armazenado no topo agora é: %d\n", p.itens[p.topo]);
    }