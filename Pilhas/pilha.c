#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "lista.h"

 struct lista{
	int info;
	Lista *prox;
 };
 
 struct pilha{
	Lista *prim;
 };  

 Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	if(p==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	p->prim = NULL;
 return p;
 }

/*Função que adiciona um elemento no topo de uma pilha.*/
 void pilha_push(Pilha *p, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
		if(l==NULL){
			printf("Memoria insuficiente!!!\n");
			exit(1);
		}
		l->info = info;
		l->prox = p->prim;
		p->prim = l;
 }

/*Testa se uma pilha é vazia.*/
 int pilha_vazia(Pilha *p){
	return p->prim==NULL;
 }

/*Função que remove um elemento do topo de uma pilha.*/
 int pilha_pop(Pilha *p){
	int a;
	Lista *l;
	if(pilha_vazia(p)){
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	l = p->prim;
	a = l->info;
	p->prim = l->prox;
	free(l);
 return a;
 }

/*Função que imprime os elementos de uma pilha.*/
 void pilha_imprime(Pilha *p){
	Lista *lAux = p->prim;
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
 }

/*Libera o espaço alocado para uma pilha.*/
 void pilha_libera(Pilha *p){
	Lista* l = p->prim;
	Lista* lAux;
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(p);
 }

/* Retorne o valor armazenado no topo da pilha recebida.*/
 int topo(Pilha* p){
	int a;
	Lista *l;
	
	if(pilha_vazia(p)){
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	l = p->prim;
	a = l->info;
 return a;
}

/* Retorna os valores impares contidos em uma pilha.*/
 int impares(Pilha* p){
 	Lista *lAux = p->prim;
	int aux, i, cont = 0;
	
	if(pilha_vazia(p)){
		printf("Pilha Vazia!!!\n");
		exit(1);
   }
 
	while(lAux!=NULL){
		aux = lAux->info;
		if(aux%2 != 0){
			cont++;
		}
		lAux = lAux->prox;
	}
 return cont;
 }
 
/* Verifica quais são os elementos em comum em duas listas l1 e l2 e empilha em ordem crescente em uma nova pilha.*/
 Pilha* empilha_elem_comuns(Lista* l1, Lista* l2){
	Lista* a = l1;
	Lista* b = l2;
	Pilha* nova = pilha_cria();
	Lista* lista_comuns = lst_cria();
	Lista* lista_aux = lst_cria();
	int aux1, aux2;

	for(a=l1;a!=NULL;a=a->prox){
		aux1 = a->info;
			for(b=l2;b!=NULL;b=b->prox){
				aux2 = b->info;
				if(aux1 == aux2){
					lista_comuns = lst_insere_ordenado(lista_comuns, aux1);
				}
			}
	}
	
	for(a=lista_comuns;a!=NULL;a=a->prox){
		aux1 = a->info;
		pilha_push(nova,aux1);
	}
 return nova;
 }
