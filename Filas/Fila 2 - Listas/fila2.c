#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"
#include "lista.h"

 struct lista{
	int info;
	Lista *prox;
 };
 
 struct fila{
	Lista *ini;
	Lista *fim;
 };

/*Função que cria uma Fila.*/ 
 Fila* fila_cria(void){
	Fila* f = (Fila*)malloc(sizeof(Fila));
	
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->ini = NULL;
	f->fim = NULL;
 return f;
 }
 
/*Testa se uma Fila é vazia.*/
 int fila_vazia(Fila *f){
	return f->ini==NULL;
}

/*Função que adiciona um elemento em uma Fila.*/
 void fila_insere(Fila *f, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = NULL;
	
	if(!fila_vazia(f)){
		f->fim->prox = l;
	}
	else{
		f->ini = l;
	}
		
	f->fim = l;
 }


/*Função que remove um elemento de uma Fila.*/
 int fila_remove(Fila *f){
	Lista *l; int a;
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
 	
	a = f->ini->info;
	l = f->ini;
	f->ini = f->ini->prox;
	free(l);
	
	if(fila_vazia(f)){
		f->fim = NULL;
	}
		
 return a;
 }
 
/*Função que imprime os elementos de uma Fila.*/
 void fila_imprime(Fila *f){
	Lista *lAux = f->ini;
	
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
 }

/*Libera o espaço alocado para uma Fila.*/
 void fila_libera(Fila *f){
	Lista* l = f->ini;
	Lista* lAux;
	
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(f);
 }

 /* Cria uma nova fila com os elementos da fila f na ordem inversa.*/
 Fila* inverte(Fila* f){
    Lista *lAux = f->ini;
    Fila* nova = fila_cria();
    Lista* list = lst_cria();
    Lista* c;
    int aux,aux2;

	while(lAux!=NULL){
		aux = lAux->info;
     	list = lst_insere(list,aux);
		lAux = lAux->prox;
	}

	c = list;

	while(c!=NULL){
		aux2 = c->info;
    	fila_insere(nova,aux2);
		c = c->prox;
	}
 return nova;
 }

/* Retorna o número de elementos da fila com valor maior que n.*/
 int qtd_maior(Fila* f, int n){
	Lista *lAux = f->ini;
	int aux, cont=0;
	
	while(lAux!=NULL){
		aux = lAux->info;
		if(aux > n){
			cont++;
		}
		lAux = lAux->prox;
	}
 return cont;
 }

/* Retorna o número de elementos da fila que possuem o campo info com valor par.*/
 int pares(Fila* f){
	Lista *lAux = f->ini;
	int aux, cont=0;
	
	while(lAux!=NULL){
		aux = lAux->info;
		if(aux%2 == 0){
			cont++;
		}
		lAux = lAux->prox;
	}
 return cont;
 }
