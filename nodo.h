#ifndef NODO_H
#define NODO_H

#include <iostream>

template < typename Dato >
class Nodo{
	private:
		// Dato a almacenar
		Dato dato;
		
		// Puntero a otro nodo
		Nodo<Dato>* siguiente;
		
	public:
		/*  Constructor con parametro
		    PRE: Ninguna
			POST: Crea un nodo con el dato d
		 		 y el puntero a NULL */
		Nodo(Dato d);

		/* Destructor
		 	PRE: Nodo creado
		 	POST: No hace nada*/
		~Nodo();

		/* Setea el dato (lo cambia)
			PRE: el nodo tiene que estar creado
			 	 d tiene que ser un dato válido
			POST: el nodo queda con el dato d*/
		void cambiar_dato(Dato d);

		/* Setear el puntero al siguiente nodo
		 	PRE: nodo creado y ps válido
		    POST: el puntero al siguiente apuntará a ps */
		void cambiar_siguiente(Nodo<Dato>* ps);

		/* Obtener el dato
			PRE: nodo creado
			POST: devuelve el dato que contiene el nodo */
		Dato obtener_dato();

		/* Obtener el puntero al nodo siguiente
		 	PRE: nodo creado
			POST: Devuelve el puntero al siguiente nodo
				  si es el último devuelve NULL */
		Nodo* obtener_siguiente();

};

// Constructor con parametro
template < typename Dato >
Nodo<Dato>::Nodo(Dato d){
	this->dato = d;
	this->siguiente = NULL;
}

// Destructor
template < typename Dato >
Nodo<Dato>::~Nodo(){
	// No hace nada
}

// Setear el dato
template < typename Dato >
void Nodo<Dato>::cambiar_dato(Dato d){
 	this->dato = d;
}

// Setear el ptr al sig
template < typename Dato >
void Nodo<Dato>::cambiar_siguiente(Nodo<Dato>* ps){
	this->siguiente = ps;
}

// Devolver el dato
template < typename Dato >
Dato Nodo<Dato>::obtener_dato(){
	return this->dato;
}

// Devolver el siguiente
template < typename Dato >
Nodo<Dato>* Nodo<Dato>::obtener_siguiente(){
	return this->siguiente;
}

#endif
