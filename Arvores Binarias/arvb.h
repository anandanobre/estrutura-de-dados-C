typedef struct arvb ArvB;

/*Função que cria uma Árvore Binária de Busca Vazia.*/
 ArvB* arvb_cria_vazia(void);
/*Testa se uma Árvore Binária é vazia.*/   
 int arvb_vazia(ArvB *a);
/*Função que busca a sub-árvore que contém um inteiro.*/
 ArvB* arvb_busca(ArvB *a,int c);
/*Função imprime a altura de uma árvore*/ 
 int arvb_altura(ArvB *a);
/*Função que imprime os elementos de uma Árvore.*/
 void arvb_imprime(ArvB *a);
/*Função que insere um inteiro em uma Árvore.*/
 ArvB* arvb_insere(ArvB *a, int c);
/*Função que remove um inteiro em uma Árvore.*/
 ArvB* arvb_remove(ArvB *a, int c);
/*Libera o espaço alocado para uma Árvore.*/
 void arvb_libera(ArvB *a);
 
/*Retorna a quantidade de folhas de uma árvore que possuem no campo info um número divisível por n.*/
 int folhas_div_n(ArvB* a, int n);
/*Função que decide se uma árvore é degenerada.*/
 int isdegenerada(ArvB* a);
/*Retorna a quantidade de nós que tenham fator de balanceamento igual a n.*/
 int nos_fb_n(ArvB* a, int n);
/*Lê e imprime os elementos em comuns de duas árvores binárias de busca.*/
 void impressao_arv_elem_comuns(ArvB* a, ArvB* b);
/*Imprime os elementos de uma árvore binária de busca por níveis.*/
 void impressao_arv_niveis(ArvB* a);
