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
    
    /*
    else{
    if(micola->fin != NULL){
        
        micola->fin->siguiente=newnode;

    }
    newnode->anterior=micola->fin;  
  
        

}
*/

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
    //mi_cola->inicio->anterior=NULL;
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
        printf("Se elimino");
		return 0;
	}else{
		return -1;
	}
}
  



int main(){
	int val=0;
	char dato= 0;

    cola* colaTEST=crear_cola();
	while(1){
		
		scanf("%c",&dato);
        char * valor=&dato;
		
		if(strcmp(valor,"x\n")==0){
			break;
		}
		else{
			int numero= atoi(valor);
            int *ptr=&numero;
            //printf("Testing %ld\n",ptr);
			
			encolar(colaTEST,ptr);
			val++;
		}
	}

			
			
	
    printf("Elemento a buscar: ");
    int buscar;
    scanf("%d",&buscar);
    int * buscador =&buscar;
    unsigned long position =posicion_cola(colaTEST,buscador);
    printf("El elemento está en la posición %ld de la cola \n",position);
    for(int i=0;i<val;i++){
       decolar(colaTEST);
    }
    destruir_cola(colaTEST);

    /*

    cola* colaTEST=crear_cola();
    int pa =1;
     int pb =2;
      int pc =3;
       int pd =4;
        int pe =5;
    int* a=&pa;
    int* b=&pb;
    int* c=&pc;
    int* d=&pd;
    int* e=&pe;
    encolar(colaTEST,a);
        encolar(colaTEST,b);
            encolar(colaTEST,c);
                encolar(colaTEST,d);
                    encolar(colaTEST,e);


    unsigned long position =posicion_cola(colaTEST,e);
    printf("El elemento está en la posición %ld de la cola \n",position);
*/

    
    



return 0;

}
