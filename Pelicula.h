#ifndef _PELICULA_H_
#define _PELICULA_H_

#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

class Pelicula{

	private:

		string nombre;
		string genero;
		int puntaje;
		string director;
		Lista<string>* actores;

	public:

		Pelicula(string nombre,string genero,string director,int puntaje);

		string obtener_nombre();

		string obtener_genero();

		string obtener_director();

		int obtener_puntaje();

		void agregar_actor(string nuevo_actor);

		Lista<string>* obtener_lista_de_actores();

		/*void asignar_nombre(string nuevo_nombre);

		void asignar_director(string nuevo_director);

		void asignar_genero(string nuevo_genero);

		void asignar_puntaje(int nuevo_puntaje);*/

};


#endif 