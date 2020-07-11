#include <stdio.h>
#include <limits.h>
#include <stdlib.h>



typedef struct colaTDA{
 unsigned long tamano;
 struct nodo_cola *inicio;
 struct nodo_cola *fin;
} cola;


typedef struct nodo_colaTDA{
 void *elemento;
 struct nodo_cola *siguiente;
 struct nodo_cola *anterior;
} nodo_cola;

cola *crear_cola(){
    cola *q=malloc(sizeof(cola));
    q->inicio=q->fin=NULL;
    q->tamano=0;
    return q ;
   
}


unsigned long tamano_cola(cola *mi_cola) {							// else return 1
	return mi_cola->tamano;
}
/*
int *encolar(cola *micola,void *elemento){  

    nodo_cola *nuevo_nodo =malloc(sizeof(nodo_cola));
    nuevo_nodo->elemento=elemento;
    nuevo_nodo->siguiente=NULL;

    if(nuevo_nodo==NULL) return -1;
    if(micola->fin != NULL){

        micola->fin->siguiente= nuevo_nodo;
    }
    micola->fin=nuevo_nodo;
    if(micola->inicio==NULL){
        micola->inicio=nuevo_nodo;


}
    return 0;

}*/

int main(){
    cola *q1;
    q1=crear_cola();
    unsigned long  tamano=tamano_cola(q1);
    printf("tamaño %ld\n",tamano);







}