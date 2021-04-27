#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"
#include "fila.h"
#define N 5

 typedef struct fila{
	int n;
	int ini;
	int v[N];
 }Fila;

 struct arvb{
	int info;
	ArvB *esq;
	ArvB *dir;
 };
 
 
 
 
/* Função que cria uma Fila.*/ 
 Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->n = 0;
	f->ini = 0;
 return f;
 }

/* Testa se uma Fila é vazia.*/
 int fila_vazia(Fila *f){
	return f->n==0;
 }


/* Função que adiciona um elemento em uma Fila.*/
 void fila_insere(Fila *f, ArvB *a){
	int fim;
 	
	if(f->n==N){
		printf("Capacidade da Fila Estourou!!!\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N;
	f->v[fim]= a;
	f->n++;
 }

/* Função que remove um elemento de uma Fila.*/
 int fila_remove(Fila *f){
	int a;
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->v[f->ini];
	f->ini = (f->ini+1)%N;
	f->n--;
 return a;
 }

/* Função que imprime os elementos de uma Fila.*/
 void fila_imprime(Fila *f){
	int i; int k;
		for(i = 0; i<f->n;i++){
		k = (f->ini+i) % N;
		printf("%d\n",f->v[k]);
	}
 }

/* Libera o espaço alocado para uma Fila.*/
 void fila_libera(Fila *f){
	free(f);
 }


/* Retorne o valor armazenado no topo da fila recebida.*/
 int fila_topo(Fila* f){
	int a;
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->v[f->ini];
 return a;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 ArvB* arvb_cria_vazia(void){
	return NULL;
 }
 
 ArvB* arv_cria_no(int c, ArvB *sae, ArvB *sad){
	ArvB* a = (ArvB*)malloc(sizeof(ArvB));
	a->info = c;
	a->esq = sae;
	a->dir = sad;
 return a;
 }
 
 int arvb_vazia(ArvB *a){
	return a==NULL;
 }
 
 ArvB* arvb_busca(ArvB *a, int c){
	if(arvb_vazia(a))
		return NULL;
	else if(a->info < c)
		return arvb_busca(a->dir,c);
		else if(a->info > c)
		return arvb_busca(a->esq,c);
	else 
 return a;
 }
 
 int arvb_altura(ArvB *a){
	if(arvb_vazia(a)){
		return -1;
	}else{
		int hSAE = arvb_altura(a->esq);
		int hSAD = arvb_altura(a->dir);
		if(hSAE > hSAD)
			return 1+hSAE;
		else
		return 1+hSAD;
	}
 }

 
 void arvb_imprime(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		printf("%d ",a->info);
		arvb_imprime(a->dir);
	}
 }
 
 ArvB* arvb_insere(ArvB *a, int c){
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = c;
		a->esq = NULL;
		a->dir = NULL;
	}else if(a->info > c)
		a->esq = arvb_insere(a->esq,c);
	else if (a->info < c)
		a->dir = arvb_insere(a->dir,c);
	else
	printf("\nElemento Ja Pertence a Arvore");
 return a;
 }
 
 ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c)
			a->esq = arvb_remove(a->esq,c);
		else if (a->info < c)
		a->dir = arvb_remove(a->dir,c);
		else{
			ArvB* t;
				if (a->esq == NULL){
					t = a; a = a->dir;
					free(t);
				}else if (a->dir == NULL){
					t = a; a = a->esq;
					free(t);
				}else{
					t = a->esq;
					while(t->dir!=NULL)
						t = t->dir;
						a->info = t->info; t->info = c;
						a->esq = arvb_remove(a->esq,c);
				}
 		}
	}
 return a;
 }

 void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
 }
 
 /*Retorna a quantidade de folhas de uma árvore que possuem no campo info um número divisível por n.*/
 int folhas_div_n(ArvB* a, int n){
	static int cont = 0;
	if(!arvb_vazia(a)){ 
		folhas_div_n(a->esq, n); //Percorre a árvore pela esquerda
		if((a->info)%n == 0){ //Se o resto da divisão do elemento da posição atual da árvore pelo n for igual a zero o contador conta mais 1;
			cont++;
		}
		folhas_div_n(a->dir, n);
	}
 return cont;
 }
 
/*Função que decide se uma árvore é degenerada.*/
 int isdegenerada(ArvB* a){
 	if(a->esq != NULL) { //Verifica se a esquerda é diferente de NULL
        if(a->dir != NULL) { //Verifica se a direita é diferente de NULL
            return 0; 
        }else { //Se ambos forem igual a NULL envia esquerda para a função novamente
            return isdegenerada(a->esq);
        }
    }else{
        if(a->dir != NULL){ //Verifica se a direita é diferente de NULL, se sim envia direita para a função novamente
            return isdegenerada(a->dir); 
        }else{ //Se não retorna 1
            return 1; 
        }
    }
 }
 
/*Retorna a quantidade de nós que tenham fator de balanceamento igual a n.*/ 
 int nos_fb_n(ArvB* a, int n){
  int cont = 0;
	int fator(ArvB* a, int n){ //Cria nova função para executar os calculos necessarios sem inicializar o contador novamente a cada entrada.
		if(!arvb_vazia(a)){ 
		    int alturaEsq = arvb_altura(a->esq); //Pega a altura da árvore esquerda
		    int alturaDir = arvb_altura(a->dir); //Pega a altura da árvore direita
		
		    int dif = (alturaDir - alturaEsq);
		    if(dif == n){ // Se a diferença das alturas for igual a n o contador conta mais 1
		      cont++;
		    }
		return fator(a->esq, n), fator(a->dir, n), cont; //Retorna esquerda e direita para continuar percorrendo a árvore
		}else{
			return NULL;
		}
	}
  return fator(a,n); 
 }
 
/*Lê e imprime os elementos em comuns de duas árvores binárias de busca.*/ 
 void impressao_arv_elem_comuns(ArvB* a, ArvB* b){
	if(!arvb_vazia(a)){ 
		impressao_arv_elem_comuns(a->esq, b ); //Percorre a árvore A pela esquerda
		if(arvb_busca(b, a->info) != NULL){ //Se o elemento atual da arvore A existir igualmente na árvore B, printa elemneto verificado
			printf("%d ",a->info);
		}
		impressao_arv_elem_comuns(a->dir, b);
	}else{
		return NULL;
	}
 }
 
/*Imprime os elementos de uma árvore binária de busca por níveis.*/ 
 static int delimitador = NULL;
 void impressao_arv_niveis(ArvB* a){
	if(!arvb_vazia(a)){
		int nivel, altura;
		altura = arvb_altura(a); //Armazena a altura da árvore recebida
		//Cria uma fila inserido o primeiro nó da arvore e o delimitador para separar o níveis
		Fila* f = fila_cria();
    	fila_insere(f, a);
    	fila_insere(f, delimitador);
    
    	while(!fila_vazia(f)){
			ArvB* atual = fila_topo(f); //Cria um nó pra receber o elemento contido no topo da fila
			a = fila_remove(f); //Remove o elemento da fila
			if(atual != delimitador){ //Se o elemento for diferente de NULL printa o elemento
				printf("%d, ", atual->info);
				if(atual->esq != delimitador){ //Verifica se a esquerda é diferente de NULL, se sim envia opara a fila
					fila_insere(f, atual->esq);
				}
				if(atual->dir != delimitador){ //Verifica se a direita é diferente de NULL, se sim envia opara a fila
					fila_insere(f, atual->dir);
				}
				nivel = arvb_altura(a); //Recebe a altura atual da árvore
				nivel = abs(nivel - altura); //Calcula a diferença entre a altura total da árvore e a altura atual
			}else{
				if(fila_vazia(f)){ //Verifica se a fila está vazia
					printf("- nivel %d\n", altura);
					break;
				}else{ //Se a fila não estiver vazia insere NULL 
					fila_insere(f, delimitador);
					printf("- nivel %d\n",nivel);
				}
			}	 
		}
	}
 }
