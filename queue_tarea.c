#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>


#define QUEUE_EMPTY INT_MIN

typedef struct colaTDA{
 unsigned long tamano;
 struct nodo_cola *inicio;
 struct nodo_cola *fin
} cola;
typedef struct nodo_colaTDA{
 void *elemento;
 struct nodo_cola *siguiente;
 struct nodo_cola *anterior;
} nodo_cola;

cola *crear_cola();

int main(){




}