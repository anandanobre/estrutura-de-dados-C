#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"
 
 main(void){
 int a;
 
 Pilha* p1 = pilha_cria();
 pilha_push(p1,10);
 pilha_push(p1,20);
 pilha_push(p1,25);
 pilha_push(p1,30);
 a = pilha_pop(p1);
 printf("PILHA 1:\n\n");
 pilha_imprime(p1);
 
 printf("_____________________\n\n");
 printf("Elemento removido da pilha p1: %d\n",a);
 printf("Elemento no topo da pilha p1: %d\n",topo(p1));
 printf("Quantidade de elementos impares na pilha p1: %d\n",impares(p1));
 printf("_____________________\n\n");

 Lista* l1 = lst_cria();
 l1 = lst_insere(l1,4);
 l1 = lst_insere(l1,5);
 l1 = lst_insere(l1,6);
 l1 = lst_insere(l1,7);
 printf("LISTA 1:\n\n");
 lst_imprime(l1);

 Lista* l2=lst_cria();
 l2 = lst_insere(l2,5);
 l2 = lst_insere(l2,6);
 l2 = lst_insere(l2,7);
 l2 = lst_insere(l2,8);
 printf("\nLISTA 2:\n\n");
 lst_imprime(l2);
 printf("_____________________\n\n");
 
 Pilha* p2= empilha_elem_comuns(l1,l2);
 printf("PILHA 2 COM ELEMENTOS COMUNS DAS LISTAS 1 E 2, EM ORDEM CESCENTE:\n\n");
 pilha_imprime(p2);
 
 lst_libera(l1);
 lst_libera(l2);
 pilha_libera(p1);
 pilha_libera(p2);
 
 system("PAUSE");
 return 0;
}
