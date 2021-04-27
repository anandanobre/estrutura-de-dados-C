#include <stdio.h>
#include <stdlib.h>
#include "fila2.h" 

int main(void){
 int a, qtd;
 
 Fila* f1 = fila_cria();
 fila_insere(f1,10);
 fila_insere(f1,20);
 fila_insere(f1,30);
 fila_insere(f1,40);
 fila_insere(f1,50);
 a = fila_remove(f1);
 
 printf("Valor removido da fila f1: %d\n\n",a);
 printf("FILA 1:\n\n",a);
 fila_imprime(f1);

 printf("_______________\n\n");
 Fila* f2 = inverte(f1);
 printf("FILA 2 COM OS VALORES INVERTIDOS DE FILA 1: \n\n");
 fila_imprime(f2);
 qtd = qtd_maior(f1,20);
 printf("_______________\n");
 printf("\nNumero de elementos maiores que 20 em f1: %d\n",qtd);
 printf("Quantidade de elementos pares na fila f1: %d\n\n",pares(f1));

 fila_libera(f1);
 fila_libera(f2);

 system("PAUSE");
 
 return 0;
}
