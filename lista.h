#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"

template < typename Dato >
class Lista{
	private:
		// Primer elemento de la lista
		Nodo<Dato>* primero;
		// Tamaño de la lista
		int tam;
	public:
		/* Constructor
 		PRE: Ninguna
 		POST: construye una lista vacía
			- primero apunta a nulo
			- tam = 0 */
		Lista();

		// Destructor
		// PRE: Lista creada
		// POST: Libera todos los recursos de la lista
		~Lista();

		/*  Agregar un elemento a la lista
			PRE: lista creada y d válido
		 	POST: agrega un dato dentro de un nodo al principio
				- modifica el primero
				- tam se incrementa en 1 */
		void agregar(Dato d,int pos);

		/* Obtener el tamaño de la lista
		 	PRE: Lista creada
		 	POST: devuelve el tamaño de la lista (cantidad de nodos) */
		int tamanio();

		/* Obtener el dato que está en la posición pos
 			PRE: - lista creada y no vacía
				 - 0 < pos <= tam
			POST: devuelve el dato que está en la posición pos
				  se toma 1 como el primero */
		Dato consultar(int pos);

		// ¿Lista vacia?
		// PRE: Lista creada
		// POST: T si es vacia, F sino
		bool lista_vacia();

		// Borrado del nodo que está en la posición pos
		// PRE: - lista creada y no vacía
		//- 0 < pos <= tam
		// POST: libera el nodo que está en la posición pos
		// se toma 1 como el primero
		void eliminar(int pos);

	private:

		Nodo<Dato>* obtener_nodo(int pos);
};

template < typename Dato >
Lista<Dato>::Lista(){
	this->primero = NULL;
	this->tam = 0;
}

template < typename Dato >
Nodo<Dato>* Lista<Dato>::obtener_nodo(int pos){

	Nodo<Dato>* aux = this->primero;
	for (int i = 0 ; i < pos; ++i) aux = aux->obtener_siguiente();
	return aux;

}

template < typename Dato >
void Lista<Dato>::agregar(Dato d,int pos){

	Nodo<Dato>* nuevo_nodo = new Nodo<Dato>(d);
	if(pos == 1){
		nuevo_nodo->cambiar_siguiente(primero);
		primero = nuevo_nodo;
	}
	else{
		Nodo<Dato>* aux = obtener_nodo(pos-1);
		nuevo_nodo->cambiar_siguiente(aux->obtener_siguiente());
		aux->cambiar_siguiente(nuevo_nodo);
	}
	tam++;
}

template < typename Dato >
int Lista<Dato>::tamanio(){
	return this->tam;
}

template < typename Dato >
Dato Lista<Dato>::consultar(int pos){
	Nodo<Dato>* aux = obtener_nodo(pos);
	return aux->obtener_dato();
}

template < typename Dato >
bool Lista<Dato>::lista_vacia(){
	return this->tamanio == 0;
}

template < typename Dato >
void Lista<Dato>::eliminar(int pos) {
	Nodo<Dato>* aux;
	if(pos == 1){
		aux = this->primero;
		primero = aux->obtener_siguiente();
	}
	else{
		Nodo<Dato>* anterior = obtener_nodo(pos-1);
		aux = anterior ->obtener_siguiente();
		anterior ->cambiar_siguiente(aux->obtener_siguiente());
	}
	this->tam--;
	delete aux;
}

template < typename Dato >
Lista<Dato>::~Lista(){
	while(!lista_vacia()){
		eliminar(1);
	}
}

#endif