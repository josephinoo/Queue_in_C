
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

cola *crear_cola();
unsigned long tamano_cola(cola *mi_cola);
int encolar(cola *micola, void *elemento);
void *decolar(cola *mi_cola);
unsigned long posicion_cola(cola *mi_cola, void *elemento) ;
int destruir_cola(cola *mi_cola);