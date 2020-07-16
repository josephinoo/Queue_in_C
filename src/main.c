
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <../include/queueTDA.h>



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