#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef struct Tarea{
	int TareaID; //Numerado en ciclo iterativo
	char *Descripcion; //
	int Duracion; // entre 10 – 100
}Tarea;

typedef struct Tnodo{
	Tarea tarea;
	Tnodo *sig;
}Tnodo;

void CargarListadeTareas(Tnodo **lista, int cant);
Tnodo * listaVacia();
Tnodo * CrearNodo();
void CargarNodoConTarea(Tnodo * tarea, int i);
void insertarNodo(Tnodo**lista, Tnodo *nodo);
void mostrar(Tnodo *lista);
Tnodo * QuitarNodo(Tnodo ** Lista);
bool ControlDeTarea(Tnodo * tarea);
Tnodo * busquedaPorId(Tnodo **lista, int cantidad);
	Tnodo *busquedaNombre(Tnodo **lista, int cantidad);



int main(){
	
	time_t t;
    srand((unsigned) time(&t));
    int cantidad = rand() % 4 +1;
    int id;
    
    printf("Ingrese la cantidad de tareas");    
    printf("\nLa cantidad ingresada es %d", cantidad);
    
    Tnodo * start;
    start = listaVacia();
	Tnodo * TareasRealizadas = listaVacia();
	Tnodo * TareasPendientes = listaVacia();
	Tnodo * busqueda = listaVacia();
//	mostrar(start); 
    
	CargarListadeTareas(&start, cantidad);
	
	printf("Busqueda de tarea por Id: \n");
	busqueda = busquedaPorId(&start, cantidad);
    mostrar(busqueda); 
	
	printf("Busqueda de tarea por nombre: \n");
	busqueda = busquedaNombre(&start, cantidad);
    mostrar(busqueda);	
	
		
	for (int i = 0; i < cantidad; i++)
    {
    	Tnodo * nodoAux = QuitarNodo(&start);
    	printf("\nDesea realizar la tarea(S/N): ");
    	mostrar(nodoAux);	
        if( ControlDeTarea(start) ){
        	insertarNodo(&TareasRealizadas, nodoAux);
        	
		}else{
        	insertarNodo(&TareasPendientes, nodoAux);
		}
		    
    }

	printf("\n##############Tareas realizadas#################");
	mostrar(TareasRealizadas);	
	
	printf("\n##############Tareas pendientes#################");
	mostrar(TareasPendientes);	
	
	//mostrar(start); 
	
	return 0;
}

Tnodo * listaVacia(){
	return NULL;
}



void CargarListadeTareas(Tnodo ** lista, int cant){
	
	int i;

	for(i=0; i < cant;i++){
		
		Tnodo * nuevoNodo = CrearNodo();
		
		CargarNodoConTarea(nuevoNodo,i);
		
		insertarNodo(lista, nuevoNodo);
	}
	
}

// funciona bien
void CargarNodoConTarea(Tnodo *tarea, int i){
	
	char aux[100];

	
	tarea->tarea.TareaID = i +1;
	printf("\ningrese el nombre de la tarea que debe realizar: ");
	gets(aux);
	
	tarea->tarea.Descripcion = (char*)malloc(strlen(aux));
	
	strcpy(tarea->tarea.Descripcion,aux);
	
	tarea->tarea.Duracion = rand() % 100 + 10;
	

}

Tnodo * CrearNodo(){
	
	return (Tnodo*)malloc(sizeof(Tnodo));
	
}


//problema
void insertarNodo(Tnodo ** lista, Tnodo *nodo){
	
	//Tnodo *aux = *lista;	
	nodo->sig = *lista;
	*lista = nodo;
		
}

Tnodo * QuitarNodo(Tnodo ** Lista){
	
	Tnodo *aux = *Lista;
	
	*Lista = (*Lista)->sig;
	aux->sig = NULL;
	return aux;
}



void mostrar(Tnodo *lista){ 
	
	while(lista !=NULL){
		printf("\nID: %d",lista->tarea.TareaID);
    	printf("\nDescripcion: %s",lista->tarea.Descripcion);
    	printf("\nDuracion: %d\n",lista->tarea.Duracion);
    	lista = lista->sig;
	}

}

bool ControlDeTarea(Tnodo * tarea){
	
	char aux;
	scanf(" %c",&aux);
	if(tolower(aux) == 's'){
		return true;
	}else{
		return false;
	}
	
}


Tnodo * busquedaPorId(Tnodo **lista, int cantidad){ 
	
	Tnodo *aux = *lista;
	int id;

    printf("Ingrese el ID de la tarea a buscar: ");
    scanf(" %d", &id);

    while ( aux->sig && aux->tarea.TareaID != id){
		aux =  aux->sig;
	}

	if (aux == NULL){
		printf("su tarea no existe");
		return NULL;
		 	
	}
	else{
		aux->sig = NULL;
		return aux;	
	}
	
}


Tnodo *busquedaNombre(Tnodo **lista, int cantidad){
	Tnodo *aux = *lista;
	char nombre[100];
	gets(nombre);
	
	while ( aux->sig && strcmp(aux->tarea.Descripcion,nombre) != 0){
		aux = aux->sig;
	}
	if (aux != NULL){
		aux->sig = NULL;
		return aux;		
	}
	else{
		printf("su tarea no existe");
		return NULL;
	}

}



