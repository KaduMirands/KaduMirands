#include <stdio.h>

// Inclui o arquivo de cabeçalho para funções de alocação de memória
#include <stdlib.h>
//====================================================================================
// Define a estrutura para um nó da lista encadeada
typedef struct No {
    int data;               // Dados que o nó irá armazenar
    struct No* next;     /* Ponteiro para o próximo nó na lista. Ele deve ser do tipo struct porque aponta para outro nó da mesma estrutura (auto-referência).  Nesse caso, struct No indica o tipo de estrutura para a qual o ponteiro aponta. Assim, o uso de um ponteiro do tipo struct dentro da própria struct é o que permite a formação da lista encadeada: cada nó aponta o próximo nó, formando uma cadeia de nós até que o último nó aponte para NULL, indicando o fim da lista*/
} Node;

//====================================================================================
// Função para criar e inicializar um novo nó com um dado valor
Node* createNode(int value) {
    // Aloca memória para o novo nó e retorna um ponteiro para essa memória
    Node* newNode = (Node*) malloc(sizeof(Node));
    
    // Atribui o valor fornecido ao campo 'data' do novo nó
    newNode->data = value;
    
    // Inicializa o campo 'next' do novo nó como NULL (ainda não está conectado a outros nós)
    newNode->next = NULL;
    
    // Retorna o ponteiro para o novo nó
    return newNode;
}

//======================================================================================
// Função para adicionar um novo nó ao final da lista encadeada
//Declaramos a função append, que aceita um ponteiro para o ponteiro da cabeça da lista (head) e um valor inteiro (data) que representa o valor a ser inserido no novo nó.
void append(Node** head, int value) {
	
    // Cria um novo nó com o valor fornecido
    Node* newNode = createNode(value);
    
    // Se a lista estiver vazia (a cabeça é NULL), torna o novo nó a cabeça
    //Verificamos se a lista encadeada está vazia. Se a cabeça da lista (*head) é NULL, isso significa que a lista está vazia.
    if (*head == NULL) {
//Se a lista está vazia, tornamos o novo nó (newNode) a cabeça da lista.
        *head = newNode;
//Se a lista não estiver vazia
    } else { // Se a lista não estiver vazia criamos um ponteiro temporário temp e inicializamos com a cabeça da lista. Esse ponteiro será usado para percorrer a lista até o último nó
        Node* temp = *head;
// Percorre a lista até encontrar o último nó
//Iniciamos um loop while para percorrer a lista. O loop continuará 
//até que o campo next do nó atual seja NULL, o que indica que encontramos 
//o último nó da lista
        while (temp->next != NULL) {
//Dentro do loop, movemos o ponteiro temp para o próximo nó. Esse passo faz com 
//que temp avance pela lista
            temp = temp->next; //em lista encadeadas, nós não incrementamos ponteiros da mesma maneira que faríamos com um vetor ou array. Em vez disso, fazemos o ponteiro atual apontar para o próximo nó usando a referência que está armazenada no campo next do nó atual
        }
        
        // Conecta o último nó ao novo nó
//Após sair do loop, o ponteiro temp estará apontando para o 
//último nó da lista. Aqui, fazemos o campo next do último nó 
//apontar para o newNode, efetivamente anexando o newNode 
//ao final da lista
        temp->next = newNode;
    }
}
//==========================================================================================
/* Função para Inserir um novo nó no início da lista */
void inserirNoInicio(Node **head, int value)
{
    Node *newNode  = createNode(value); /* nó solitário nasce com next = NULL */
    newNode->next  = *head;             /* aponta p/ antigo primeiro  */
    *head          = newNode;           /* head passa a ser o novo nó */
}


//===========================================================================================
// Função para inserir um nó após um nó com um valor específico
void insertAfter(Node** head, int referenceValue, int value) {
	// argumentos: Um ponteiro para o ponteiro da cabeça da lista (head).
	//O valor de referência do nó após o qual desejamos inserir um novo nó (referenceValue).
	//O valor de dados que o novo nó deve armazenar (value).
    
// Criamos um novo nó
    //Invocamos a função createNode (que foi definida anteriormente) 
	//para criar um novo nó com o valor value. O novo nó é armazenado no ponteiro newNode.
    Node* newNode = createNode(value);
    
// Verifica se a lista está vazia, em caso afirmativo, apenas adiciona o nó
	if (*head == NULL) {
        		*head = newNode;
        return;
    }
// Cria um ponteiro temporário para percorrer a lista
    Node* temp = *head;

    // Procura o nó com o valor de referência
    //Usamos um loop while para percorrer a lista. 
	//O loop continua até encontrar um nó com o data igual ao referenceValue ou até chegar ao final da lista.
    while (temp != NULL && temp->data != referenceValue) {
        temp = temp->next;
    }
// Se o valor de referência não foi encontrado, simplesmente retorna
  //Ou seja, depois de sair do loop, verificamos se temp é NULL. 
	//Se for, significa que não encontramos o referenceValue na lista. 
	//Nesse caso, imprimimos uma mensagem de erro e liberamos a memória alocada para o newNode usando a função free
    if (temp == NULL) {
        printf("Valor de referência %d não encontrado. Nó não inserido.\n", referenceValue);
        free(newNode);  // Libera a memória alocada, pois não vamos usá-la
        return;
    }
//Se encontrarmos o nó com o referenceValue, inserimos o newNode após ele. 
//Primeiro, fazemos o newNode->next apontar para o nó que vem depois de temp. 
//Em seguida, atualizamos o next do nó temp para apontar para o newNode.
    newNode->next = temp->next;
    temp->next = newNode;
}

//====================================================================================
// Função para imprimir todos os elementos da lista encadeada
void printList(Node* head) {
    // Ponteiro temporário para percorrer a lista
    Node* temp = head;
    
    // Enquanto não chegar ao final da lista (temp != NULL)
    while (temp != NULL) {
        // Imprime o valor do nó atual
        printf("%d -> ", temp->data);
        
        // Move para o próximo nó
        temp = temp->next;
    }
    // Indica o final da lista com "NULL"
    printf("NULL\n");      
}


//=============================================================================   
// Função principal do programa
int main() {
    // Inicializamos a lista como vazia definindo a cabeça da lista (head) como NULL
    Node* head = NULL;
    // Adiciona três nós à lista encadeada
    append(&head, 40); //append: função para adicionar um novo nó ao final da lista encadeada
    append(&head, 90);
    append(&head, 10);
    append(&head, 80);
    // Imprime a lista encadeada
    printf("Lista encadeada: \n");
    printList(head);  // Saída esperada: 1 -> 2 -> 3 -> NULL
    
    // Insere um elemento no ínicio
    inserirNoInicio(&head, 5);   /* insere o 4 no início */
    // Imprime a lista encadeada
    printf("Lista encadeada apos inserir um elemento no inicio: \n");
    printList(head);  // Saída esperada: 4 -> 1 -> 2 -> 3 -> NULL

      //Chamamos a função insertAfter para inserir um novo nó com o valor 5 após o nó com o valor 2    
    insertAfter(&head, 10, 35);  // Isso insere o valor 5 após o nó com valor 2
    // Imprime a lista encadeada
    printf("Lista encadeada apos inserir um elemento dentro da lista apos um determinado valor: \n");
    printList(head);  // Saída esperada: 1 -> 2 -> 5 -> 3 -> NULL
    // Retorna 0 indicando execução bem-sucedida  e termina
    return 0; 
}
