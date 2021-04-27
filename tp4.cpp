#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Tarea{
	int TareaID; //Numerado en ciclo iterativo
	char *Descripcion; //
	int Duracion; // entre 10 – 100
}Tarea;

typedef struct Tnodo{
	Tarea tarea;
	Tnodo *sig;
}Tnodo;

void cargarTarea(Tnodo **lista, Tnodo** start, int cant);
Tnodo * listaVacia();
Tnodo ** cargarNodo(Tnodo** tarea, int i);
void insertarNodo(Tnodo**lista, Tnodo **start);
void mostrar(Tnodo **lista);

int main(){
	
	time_t t;
    srand((unsigned) time(&t));
    int cantidad = rand() % 4 +1;
    
    printf("Ingrese la cantidad de tareas");    
    printf("\nLa cantidad ingresada es %d", cantidad);
    
    Tnodo * start;
    start = listaVacia();   
//	mostrar(start); 
    
	Tnodo * tarea;
	cargarTarea(&tarea , &start, cantidad);
	mostrar(&tarea);	
	
	return 0;
}

Tnodo * listaVacia(){
	return NULL;
}



void cargarTarea(Tnodo ** lista, Tnodo ** start, int cant){
	
	int i;
	//printf("\n%d",cant);
	
	for(i=0; i < cant;i++){
		
		lista = (Tnodo**)malloc(sizeof(Tnodo*));
		lista = cargarNodo(lista,i);
		
		insertarNodo(lista, start);
		//printf("\n%d",cant);
	}
	
}

// funciona bien
Tnodo ** cargarNodo(Tnodo** tarea, int i){
	
	char aux[100];

	
	(*tarea)->tarea.TareaID = i +1;
	printf("\ningrese el nombre de la tarea que debe realizar: ");
	gets(aux);
	
	(*tarea)->tarea.Descripcion = (char*)malloc(sizeof(strlen(aux)));
	
	strcpy((*tarea)->tarea.Descripcion,aux);
	
	(*tarea)->tarea.Duracion = rand() % 100 + 10;
	
	return tarea;

}


//problema
void insertarNodo(Tnodo ** lista, Tnodo **start){
	
	(*lista)->sig = *start;
	start = lista;
		
	/*Tnodo *L= *lista;
	Tnodo *S = *start;
	//printf("adasdsad");
	L->sig = S;
	S = L;*/
}



void mostrar(Tnodo **lista){
	Tnodo *t = *lista;
	
	while(t !=NULL){
		printf("\nID: %d",t->tarea.TareaID);
    	printf("\nDescripcion: %s",t->tarea.Descripcion);
    	printf("\nDuracion: %d\n",t->tarea.Duracion);
    	t = t->sig;
	}

}
