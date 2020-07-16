#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count=0;
int j=0;

        
 typedef struct nodo{
	int dato;
	struct nodo* proximo;
}nodo_t;

typedef struct cola {
    nodo_t* primero;
	nodo_t* ultimo;

} cola_t;

nodo_t* crear_nodo(int valor){
  nodo_t* nodo = malloc(sizeof(nodo_t));
  nodo->dato = valor;
  nodo->proximo = NULL;
  return nodo;
}


cola_t* cola_crear(void){
	cola_t* cola=malloc(sizeof(cola_t)); 
	if(cola==NULL)return NULL;
	cola->primero=NULL;
	cola->ultimo=NULL;
	return cola;
}

int cola_encolar(cola_t *cola, int valor){
  nodo_t* nodo_nuevo = crear_nodo(valor);

  if(cola->primero==NULL){
    cola->primero = nodo_nuevo;
    cola->ultimo = nodo_nuevo;
  }
  else{
    cola->ultimo->proximo = nodo_nuevo;
    cola->ultimo = nodo_nuevo;
  }
  count=count+1;
}

void buscarDato( cola_t *q, int val )
{
     struct nodo *aux;
     aux = q->primero;
     int num= aux->dato;
     
     for(int i=0; i<=count;i++){
        if(num==val){
            break;
        }else{
            aux = aux->proximo;
            num= aux->dato;
            j+=1;
        }
     }

}

void cola_desencolar(cola_t *cola){

  nodo_t* nodo_aux;
  int dato;
  nodo_aux = cola->primero;
  dato = nodo_aux->dato; 
  cola->primero = nodo_aux->proximo;
  free(nodo_aux);
}
        
int main(int argc, char** argv) {
    printf("hola\n");
    char entrada[10];
    char a[10];
    int TAM=10;
    cola_t* cola_nuevo=cola_crear();
    while(1){        
        fgets(entrada, TAM, stdin);
        if(strcmp(entrada,"x\n")==0){
            count=count-1;
            break;
        }
        else{
            int numero= atoi(entrada);
            cola_encolar(cola_nuevo,numero);
        }
    }
    printf("la cola tiene %d elementos",count+1);
    printf("\n\n\n%d \n",cola_nuevo->primero->dato);
    printf("ingrese el valor a buscar: ");
    fgets(a, TAM, stdin);
    int b=atoi(a);
    buscarDato(cola_nuevo,b);
    printf("\nsu numero se encuenta en la posicion: %d", j);
    int num=count;
    for(int i=0;i<=num;i++){
        cola_desencolar(cola_nuevo);
        count=count-1;
    }
    printf("\nelementos decolados");
    free(cola_nuevo);
}