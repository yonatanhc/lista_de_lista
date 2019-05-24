#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include "lista.h"
#include "pelicula.h"

class Menu{

	private:

			Lista<Pelicula*>* peliculas_vistas;
			Lista<Pelicula*>* peliculas_no_vistas;

	public:

		Menu();

		void crear_lista_de_peliculas(char const* peliculas_vistas_txt,char const* peliculas_no_vistas_txt);

		void mostrar_lista_de_peliculas(Lista<Pelicula*>* lista);

		Lista<Pelicula*>* obtener_peliculas_vistas();

		Lista<Pelicula*>* obtener_peliculas_no_vistas();

		~Menu();

	private:

		void guardar_actores_a_la_lista(string linea,Pelicula* pelicula);

		void leer_archivo(char const* archivo_txt,Lista<Pelicula*>* lista_de_peliculas);

		void mostrar_pelicula(Pelicula* pelicula);

		void mostrar_actores(Lista<string>* lista);
	
};