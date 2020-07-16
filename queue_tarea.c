#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>



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
    newnode->elemento=elemento;
    newnode->siguiente=NULL;
    if(micola->inicio==NULL){
        newnode->anterior=NULL;
        micola->inicio=newnode;
        micola->fin=newnode;
        micola->tamano++;
        return 0;
    }
    micola->fin->siguiente=newnode;
    newnode->anterior=micola->fin;
    micola->fin=newnode;
    micola->tamano++;
    

    return 0;
}

void *decolar(cola *mi_cola){
    if(mi_cola->tamano==0){
        return NULL;
    }
    void *value=NULL;
    nodo_cola *tmp=NULL;
    value=mi_cola->inicio->elemento;
    tmp=mi_cola->inicio;
    mi_cola->inicio=mi_cola->inicio->siguiente;
     mi_cola->tamano--;
    free(tmp);
    return value;

}





unsigned long posicion_cola(cola *mi_cola, void *elemento) {
  
        int pos=0;
        nodo_cola *current =mi_cola->inicio;
        if(mi_cola->inicio==NULL){
    
            return -1;

        }
        while (current!=NULL&&mi_cola->tamano>=pos)
        {
            if(current->elemento==elemento){
                return pos;
                
                break;
            }
            
            current=current->siguiente;
            pos++;
        }
        return -1;



}

int destruir_cola(cola *mi_cola) {
	if(mi_cola->tamano==0){
		free(mi_cola);
		return 0;
	}else{
		return -1;
	}
}
  



int main() {
    int TAM=1000;
    char entrada[TAM];
 
 int c=-1;
 cola *miCola=crear_cola();
 while(c!=0){
 
  memset(entrada, 0, TAM);
  fgets(entrada, TAM, stdin);
  
  if(strcmp(entrada, "x\n") !=0){

   unsigned long numero=atoi(entrada);
   encolar(miCola,(void *)numero);

   
  }else{




   unsigned long tamanoCola=tamano_cola(miCola);
   printf("el tamano es: %ld\n", tamanoCola);
  
   
   
   unsigned long posicion;
   printf("Elemento a buscar: ");
      scanf("%ld", &posicion);

   unsigned long posicionElemento=posicion_cola(miCola, (void *)posicion);
   printf("El elemento esta en la posicion %ld de la cola\n", posicionElemento );


   for(int i=0; i<tamanoCola; i++){


    decolar(miCola);

   }
   int destruccion=destruir_cola(miCola);
   if(destruccion==0){
    printf("elementos decolados y cola destruida\n");
    
   }
   c=0;



  }
   
}
    return 0;
}