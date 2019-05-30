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
			Lista<Pelicula*>* peliculas_recomendadas;
	public:

		Menu();

		void crear_lista_de_peliculas(char const* peliculas_vistas_txt,char const* peliculas_no_vistas_txt);

		void interfaz();

		~Menu();

	private:

		void leer_archivo(char const* archivo_txt,Lista<Pelicula*>* lista_de_peliculas);

		void mostrar_pelicula(Pelicula* pelicula);

		void mostrar_actores(Lista<string>* lista);

		bool coinciden_actores(Pelicula* peli_v,Pelicula* peli_nv);

		bool coincidencia(Pelicula* peli_v,Pelicula* peli_nv);

		bool comparar_lista_pelicula_vista(Pelicula* peli_nv);

		//void guardar_actores_a_la_lista(string actor,Pelicula* pelicula);

		void mostrar_lista_de_peliculas(Lista<Pelicula*>* lista);

		void crear_lista_de_peliculas_recomendadas();
	
};