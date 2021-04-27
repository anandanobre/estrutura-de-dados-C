#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

 void bubble_sort(int *v, int n){
	int i, j, temp;
	for(i=n-1; i>0; i--)
		for(j=0; j<i; j++)
			if(v[j]> v[j+1]){
				temp = v[j]; 
				v[j] = v[j+1];
				v[j+1] = temp;
			}
    
 }

 void insert_sort (int *v, int n){ 
	int i, j, temp;
	for (i = 1; i < n; ++i) {
		temp = v[i];
		for (j = i - 1; j >= 0 && temp < v[j]; j--)
			v[j+1] = v[j];
			v[j+1] = temp;
		} 
  
 }


 void quick_sort(int n, int *v){
	if(n>1){
		int x = v[0];
		int a =1; int b = n-1;
		while(1){
			while(a<n && v[a] <=x) a++;
				while(v[b]>x) b--;
					if(a<b){
						int temp = v[a];
						v[a] = v[b];
						v[b] = temp;
						a++;
						b--; 
					}else{
						break;
					}
		}
		v[0] = v[b];
		v[b] = x; 
		quick_sort(b,v);
		quick_sort(n-a,&v[a]);
	}
 }


 void merge_sort(int *v,int n){
	int meio, i, j, k;
	int* auxiliar;
	auxiliar =(int*) malloc(n * sizeof(int));
	if (auxiliar==NULL){
		return;
  	}
  	meio = n/2;
  	i = 0; k=0;
  	j = meio;
	while (i < meio && j < n) {
  		if (v[i] <= v[j]) {
    		auxiliar[k] = v[i++];
  		}else {
    		auxiliar[k] = v[j++];
   			++k;
  		}
   
		if (i == meio) {
 			while (j < n) {
 				auxiliar[k++] = v[j++]; 
 			}
		}else {
			while (i < meio) {
				auxiliar[k++] = v[i++]; 
 			} 
		}
	}
 }

 void heapify(int *v, int n, int i){
    int l, r, maior, aux;
    maior = i;
    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < n && v[l] > v[maior]){
    	maior = l;
	}
        
    if (r < n && v[r] > v[maior]){
    	l = r;
	}
        
    if (maior != i){
        aux = v[i];
    	v[i] = v[maior];
        v[maior] = aux;
        heapify(v, n, maior);
    }
 }

 void HeapSort(int n, int *v){
    int i, aux;
    for (i = (n / 2) - 1; i >= 0; i--)
        heapify(v, n, i);

    for (i = n - 1; i >= 0; i--) {
    	aux = v[0];
    	v[0] = v[i];
        v[i] = aux;
        heapify(v, i, 0);
    }
 }

//Calcula o tempo de execução de cada algoritmo e faz uma média
 int main() {
	int cont, round, round2, pot = 1, i = 1;
	int *v, *aux;
	
		for(round = 0; round <= 4; round++){ //Testa as funções 5 vezes 
			int n = pow(10,pot); //Define n como 10^n(n {1, 2, ..., 6}).
		
			float t1, t2, t3, t4, t5;
			time_t t_ini, t_fim;
					
			v = (int*)(malloc(n*sizeof(int)));
			aux = (int*)(malloc(n*sizeof(int)));
		
			for(cont = 0; cont!= n; cont++){ // Preenche o vetor de forma aleátoria
				v[cont] = rand()%10;
			}
			 
			for(cont = 0; cont!= n; cont++){ //Salva o vetor em uma variável auxiliar
				aux[cont] = v[cont];
			}
			 
			printf("Bubble: OK\n");
			        
			t_ini = clock(); //Conta tempo inicial
			bubble_sort(v, n); //Envia o vetor e o tamanho para a função
			t_fim = clock(); ////Conta tempo final
			
			t1= (t_fim - t_ini); //Calcula a diferença dos tempos
			 
			for(cont = 0; cont!= n; cont++){ //Faz o vetor v receber o vetor criado inicialmente
				v[cont] = aux[cont];
			}
		 
		
			printf("\nInsert: OK\n");
			
			t_ini = clock();
			insert_sort(v, n);
			t_fim = clock();
			
			t2 = (t_fim - t_ini);
			
			for(cont = 0; cont!= n; cont++){
				v[cont] = aux[cont];
			}
			
			
			printf("\nQuick: OK\n");
			
			t_ini = clock();
			quick_sort(n,v);
			t_fim = clock();
			
			t3 = (t_fim - t_ini);
			
			for(cont = 0; cont!= n; cont++){
				v[cont] = aux[cont];
			}
			
			
			printf("\nMerge: OK\n");
			
			t_ini = clock();
			merge_sort(v,n);
			t_fim = clock();
			
			t4 = (t_fim - t_ini);
			
			for(cont = 0; cont!= n; cont++){
				v[cont] = aux[cont];
			}
			
			
			printf("\nHeap: OK\n\n");
			
			t_ini = clock();
			HeapSort(n, v);
			t_fim = clock();
			  
			t5= (t_fim - t_ini);
		
		
			printf("Tempo BubbleSort: %f\n", t1/1000);
			printf("Tempo IsertSort: %f\n", t2/1000);
			printf("Tempo QuickSort: %f\n", t3/1000);
			printf("Tempo MergeSort: %f\n", t4/1000);
			printf("Tempo HeapSort: %f\n", t5/1000);
			printf("__________________________________\n\n");
			
			pot++;
			free(v);
	}

  return 0;
 }
