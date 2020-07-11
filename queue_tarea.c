#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
 


typedef struct colaTDA{
 unsigned long tamano;
 struct nodo_colaTDA *inicio;
 struct nodo_colaTDA *fin;
} cola;


typedef struct nodo_colaTDA{
 void *elemento;
 struct nodo_colaTDA*siguiente;
 struct nodo_colaTDA *anterior;
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
int encolar(cola *micola, void *elemento){
    if(micola==NULL){ return -1;}
   
    nodo_cola *newnode = malloc(sizeof(nodo_cola));
    newnode->elemento=&elemento;
    newnode->siguiente=NULL;
    if(tamano_cola(micola)==0){
        newnode->anterior=NULL;
        micola->inicio=newnode;
        micola->fin=newnode;
        micola->tamano++;
    }else{
    if(micola->fin != NULL){

        micola->fin->siguiente=newnode;
    
    }
    newnode->anterior=micola->fin;
           
micola->tamano++;
}

return 0;
}
void *decolar(cola *mi_cola){
    


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
    int p=4;
    int *ptr=&p;
    q1=crear_cola();
    encolar(q1,ptr);
    encolar(q1,ptr);
    encolar(q1,ptr);
    encolar(q1,ptr);
    unsigned long  tamano=tamano_cola(q1);
    printf("tamaño %ld\n",tamano);





return 0;

}