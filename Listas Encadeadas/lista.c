#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

 struct lista {
	int info;
	Lista *prox;
 };	

/* Cria uma lista vazia.*/
 Lista* lst_cria(){
	return NULL;
 }

/* Testa se uma lista é vazia.*/
 int lst_vazia(Lista *l){
	return (l==NULL);
 }

/* Insere um elemento no início da lista.*/
 Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
 return ln;
 }
 
/* Busca um elemento em uma lista.*/
 Lista* lst_busca(Lista *l, int info){
	Lista* lAux = l;
	while(lAux!=NULL){
		if(lAux->info == info)
		return lAux;
		lAux = lAux->prox;
	}
 return NULL;
 }


/* Imprime uma lista.*/
 void lst_imprime(Lista *l){
	Lista* lAux = l;
	while(lAux!=NULL){
		printf("Info = %d\n",lAux->info);
		lAux = lAux->prox;
	}
 }

/* Remove um elemento de um lista.*/
 Lista* lst_remove(Lista *l, int info){
	if(l!=NULL){
		Lista* lAux = l->prox;
	if(l->info==info){
		free(l);
 	return lAux;
	}else{
		Lista* lAnt = l;
		while(lAux!=NULL ){
			if(lAux->info == info){
				lAnt->prox = lAux->prox;
				free(lAux);
				break;
			}else{
				lAnt = lAux;
				lAux = lAux->prox;
			}
		}
	}
	}
 return l;
 }

/* Libera o espaço alocado por uma lista.*/
 void lst_libera(Lista *l){
	Lista* lProx;
	while(l!=NULL){
		lProx = l->prox;
		free(l);
		l = lProx;
	}
 }

/* Insere elementos de forma ordenada.*/
 Lista* lst_insere_ordenado(Lista *l, int info){
	Lista *lNew = (Lista*)malloc(sizeof(Lista));
	lNew->info = info;
	if(l==NULL){
		lNew->prox = NULL;
		return lNew;
	}else if(l->info>=info){
		lNew->prox = l;
		return lNew;
	}else{
		Lista *lAnt = l;
		Lista *lProx = l->prox;
		while(lProx!=NULL&&lProx->info<info){
			lAnt = lProx;
			lProx = lProx->prox;
		}
	lAnt->prox = lNew;
	lNew->prox = lProx;
	return l;
 	}
 }


/* Imprime uma lista recursivamente.*/
 Lista* lst_imprime_invertida_rec(Lista* l){
	if(lst_vazia(l))
		return 0;
	else{
		lst_imprime_invertida_rec(l->prox);
		printf("info: %d\n",l->info);
	}
}

/* Remove um elemento de um lista recursivamente. */
 Lista* lst_remove_rec(Lista *l, int info){
	if(!lst_vazia(l)){
		if(l->info==info){
			Lista* lAux = l;
			l = l->prox;
			free(lAux);
 		}
	}else{
		l->prox = lst_remove_rec(l->prox,info);
	}
 return l;
 }

/* Calcula a quantidade de nós de uma lista.*/
 int comprimento (Lista* l) {
	int cont = 0;
	Lista* lAux = l;
	
	if(lst_vazia(l)){
		return 0;
	}
  
	while(lAux != NULL){
		cont++;
		lAux= lAux->prox;
	}
 return cont;
 }

/* Retornar o número de nós da lista que possuem o campo info com valor menor que n*/
 int menores(Lista *l, int n){
	Lista* lAux = l;
	
	if(lst_vazia(l)){
		return 0;
	}
	
	int cont = 0;
	while (lAux != NULL){
		if (lAux->info < n)
			cont++;          
			lAux = lAux->prox;
		
	} 
 return cont;
 }

/* Soma os valores do campo info de todos os nós*/
 int soma(Lista* l){
	Lista* lAux = l;
	
	if(lst_vazia(l)){
		return 0;
	}
	
	int temp = 0;
	while (lAux != NULL){
		temp +=  lAux->info; 
		lAux = lAux->prox;
		
	} 
 return temp;
 } 

/* Retornar o número de nós da lista que possuem o campo info com número primo*/
 int primos(Lista* l){
	Lista* lAux = l;
	int i, cr, cont = 0;
	
	if(lst_vazia(l)){
		return 0;
	}
 	
	while (lAux != NULL){
		for(i = 1; i <= (lAux->info) ; i++){
			if((lAux->info)%i == 0){
				cr++;
			}
		}
		if(cr == 2){
			cont++;
		}
		cr = 0;
		lAux = lAux->prox;
	  } 
 return cont;
 }

/* Retorna a concatenação de duas listas*/
 Lista* lst_conc(Lista* l1, Lista* l2){
	Lista* a = l1;
    Lista* b = l2;
    Lista* nova = lst_cria();
    int aux;
    
	if(lst_vazia(l1) || lst_vazia(l2)){
		return 0;
	}

	while(b!=NULL){
		aux = b->info;
		nova = lst_insere(nova, aux);
		b = b->prox;
 	}
    while(a!=NULL){
		aux = a->info;
		nova = lst_insere(nova, aux);
		a = a->prox;
 	}
 return nova;
 }

/* Retira os elementos de l2 contidos em L1 */
 Lista* lst_diferenca(Lista* l1, Lista* l2){
	Lista* b;
	Lista* list_aux = lst_cria();
	int aux;

	for(b=l2;b!=NULL;b=b->prox){
		aux = b->info;
		if(lst_busca(l1, aux) != NULL){
		list_aux = lst_remove(l1, aux);
		}
	}
 return list_aux;
 }
