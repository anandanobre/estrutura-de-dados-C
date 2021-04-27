typedef struct lista Lista;
typedef struct fila Fila;

/*Função que cria uma Fila.*/
 Fila* fila_cria(void);
/*Testa se uma Fila é vazia.*/
 int fila_vazia(Fila *f);
/*Função que adiciona um elemento em uma Fila.*/
 void fila_insere(Fila *f, int info);
/*Função que remove um elemento de uma Fila.*/
 int fila_remove(Fila *f);
/*Função que imprime os elementos de uma Fila.*/
 void fila_imprime(Fila *f);
/*Libera o espaço alocado para uma Fila.*/
 void fila_libera(Fila *f);

/* Cria uma nova fila com os elementos da fila f na ordem inversa.*/
 Fila* inverte(Fila* f);
/* Retorna o número de elementos da fila que possuem valor maior que n.*/
 int qtd_maior(Fila* f, int n);
/* Retorna o número de elementos da fila que possuem o campo info com valor par.*/
 int pares(Fila* f);
