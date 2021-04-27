#include <stdio.h>
#include <stdlib.h>
#include "fila1.h"
#define N 5

 typedef struct fila{
	int n;
	int ini;
	int v[N];
 }Fila;
 
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
 void fila_insere(Fila *f, int info){
	int fim;
 	
	if(f->n==N){
		printf("Capacidade da Fila Estourou!!!\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N;
	f->v[fim]= info;
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

/* Retorna o número de elementos da fila que possuem valor maior que n.*/
 int qtd_maior(Fila* f, int n){
	int i; int k; int cont = 0;
	
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	
	for(i = 0; i<f->n;i++){
		k = (f->ini+i) % N;
		if(f->v[k] > n){
			cont++;
		}
 	}
 	return cont;
 }

/* Cria uma nova fila com os elementos da fila f na ordem inversa.*/
 Fila* inverte(Fila* f){
	Fila* nova = fila_cria();
	int i, k, aux;
  
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}

	for(i = 0; i<f->n;i++){
		k = (f->n-i) % N;
		aux = f->v[k];
		fila_insere(nova,aux);
	}
 return nova;
 }
 
 /* Retorna o número de elementos da fila que possuem o campo info com valor par.*/
 int pares(Fila* f){
	int aux, i, cont = 0;
	
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}

	for(i = f->n-1; i>=0;i--){
		aux = f->v[f->n-1];
		f->n--;
		
		if(aux%2 == 0){
		cont++;
		}
	}
 return cont;
}
