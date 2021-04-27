#include <stdio.h>
#include <stdlib.h>
#define N 10
 
 typedef struct fila{
	int t_heap;
	int v[N];
 }FilaP;
 
 int parent(int i){
    return (i - 1) / 2;
 }
 
 int leftChild(int i){
    return ((2 * i) + 1);
 }

 int rightChild(int i){ 
    return ((2 * i) + 2);
 } 

 Max_Heapify(FilaP* f, int i){
 	int maior, aux;
	int l = leftChild(i);
	int r = rightChild(i);
	
	if (l <= f->t_heap && f->v[l] > f->v[i]){
		maior = l;
	}else{
		maior = i;
	}
	
	if(r <= f->t_heap && f->v[r] > f->v[maior]){
		maior = r;
	}
	
	if(maior != i){
		aux = f->v[i];
		f->v[i] = f->v[maior];	
		f->v[maior] = aux;
    
    Max_Heapify(f,maior);
	}
  return 0;
 } 

 //cria uma fila de prioridade vazia;
 FilaP* filap_cria(){
	FilaP *f = (FilaP*)malloc(sizeof(FilaP));
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->t_heap = 0;
 return f;
 }
 
 //devolve o elemento de maior prioridade na fila
 int heap_maximum(FilaP* f){
	return f->v[0];
 }
 

 //devolve o elemento de maior prioridade e o retira da fila;
 int heap_extract_max(FilaP* f){
	int max;
	if(f->t_heap < 1){
		printf("Erro: heap underflow");
	}
	
	max = f->v[0]; 
	f->v[0] = f->v[f->t_heap-1];
	f->t_heap = (f->t_heap - 1);
	
	Max_Heapify(f,0);
 return max;
 }

 void heap_increase_key(FilaP* f, int ind, int chave){
		int aux;
			
		if (chave < f->v[ind]){ 
			printf("Erro: Nova chave eh menor que a chave atual!\n");
		}
	
		f->v[ind] = chave;
		while(ind > 0 && f->v[parent(ind)] < f->v[ind]){
	    	aux = f->v[ind];
	    	f->v[ind] = f->v[parent(ind)];
	    	f->v[parent(ind)] = aux; 
	    		
	    	ind = parent(ind);
			}
}

/*insere um novo elemento na fila com prioridade chave.*/
void max_heap_insert(FilaP* f, int chave){
	f->t_heap = (f->t_heap + 1);
	f->v[f->t_heap] = -1;
	heap_increase_key(f, f->t_heap, chave);
}
