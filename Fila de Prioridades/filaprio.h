typedef struct fila FilaP;

int parent(int i);
int leftChild(int i);
int rightChild(int i);
Max_Heapify(FilaP* f, int i);

//cria uma fila de prioridade vazia;
 FilaP* filap_cria();
//Retorna o elemento de maior prioridade na fila;
 int heap_maximum(FilaP* f);
//Retorna o elemento de maior prioridade e o retira da fila;
 int heap_extract_max(FilaP* f);
//Modifica a prioridade de determinado elemento no índice ind na fila (apenas se chave for maior);
 void heap_increase_key(FilaP* f, int ind, int chave);
//insere um novo elemento na fila com prioridade chave.
 void max_heap_insert(FilaP* f, int chave);
