typedef struct lista Lista;
 
/* Cria uma lista vazia.*/
 Lista* lst_cria();
/* Testa se uma lista � vazia.*/
 int lst_vazia(Lista *l);
/* Insere um elemento no in�cio da lista.*/
 Lista* lst_insere(Lista *l, int info);
/* Busca um elemento em uma lista.*/
 Lista* lst_busca(Lista *l, int info);
/* Imprime uma lista.*/
 void lst_imprime(Lista *l);
/* Remove um elemento de uma lista.*/
 Lista* lst_remove(Lista *l, int info);
/* Libera o espa�o alocado por uma lista.*/
 void lst_libera(Lista *l);
 
/* Calcula a quantidade de n�s de uma lista.*/
 int comprimento (Lista* l);
/* Retornar o n�mero de n�s da lista que possuem o campo info com valor menor que n*/
 int menores(Lista *l, int n);
/* Soma os valores do campo info de todos os n�s*/
 int soma(Lista* l);
/* Retornar o n�mero de n�s da lista que possuem o campo info com n�mero primo*/
 int primos(Lista* l);
/* Retorna a concatena��o de duas listas*/
 Lista* lst_conc(Lista* l1, Lista* l2);
/* Retira os elementos de l2 contidos em L1 */
 Lista* lst_diferenca(Lista* l1, Lista* l2);
