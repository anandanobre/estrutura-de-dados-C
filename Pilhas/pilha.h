typedef struct lista Lista;
typedef struct pilha Pilha;

/*Fun��o que cria uma pilha.*/
Pilha* pilha_cria(void);
/*Testa se uma pilha � vazia.*/
int pilha_vazia(Pilha *p);
/*Fun��o que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info);
/*Fun��o que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p);
/*Fun��o que imprime os elementos de uma pilha;*/
void pilha_imprime(Pilha *p);
/*Libera o espa�o alocado para uma pilha.*/
void pilha_libera(Pilha *p);

/* Retorne o valor armazenado no topo da pilha recebida.*/
 int topo(Pilha* p);
/* Retorna os valores impares contidos em uma pilha.*/
 int impares(Pilha* p);
/* Verifica quais s�o os elementos em comum em duas listas l1 e l2 e empilha em ordem crescente em uma nova pilha.*/
 Pilha* empilha_elem_comuns(Lista* l1, Lista* l2);
