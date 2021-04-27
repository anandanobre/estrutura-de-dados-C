typedef struct arvb ArvB;

/*Fun��o que cria uma �rvore Bin�ria de Busca Vazia.*/
 ArvB* arvb_cria_vazia(void);
/*Testa se uma �rvore Bin�ria � vazia.*/   
 int arvb_vazia(ArvB *a);
/*Fun��o que busca a sub-�rvore que cont�m um inteiro.*/
 ArvB* arvb_busca(ArvB *a,int c);
/*Fun��o imprime a altura de uma �rvore*/ 
 int arvb_altura(ArvB *a);
/*Fun��o que imprime os elementos de uma �rvore.*/
 void arvb_imprime(ArvB *a);
/*Fun��o que insere um inteiro em uma �rvore.*/
 ArvB* arvb_insere(ArvB *a, int c);
/*Fun��o que remove um inteiro em uma �rvore.*/
 ArvB* arvb_remove(ArvB *a, int c);
/*Libera o espa�o alocado para uma �rvore.*/
 void arvb_libera(ArvB *a);
 
/*Retorna a quantidade de folhas de uma �rvore que possuem no campo info um n�mero divis�vel por n.*/
 int folhas_div_n(ArvB* a, int n);
/*Fun��o que decide se uma �rvore � degenerada.*/
 int isdegenerada(ArvB* a);
/*Retorna a quantidade de n�s que tenham fator de balanceamento igual a n.*/
 int nos_fb_n(ArvB* a, int n);
/*L� e imprime os elementos em comuns de duas �rvores bin�rias de busca.*/
 void impressao_arv_elem_comuns(ArvB* a, ArvB* b);
/*Imprime os elementos de uma �rvore bin�ria de busca por n�veis.*/
 void impressao_arv_niveis(ArvB* a);
