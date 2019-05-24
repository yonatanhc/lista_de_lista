#include "lista.h"
#include "pelicula.h"

class Menu{

	private:

			Lista<Pelicula*> peliculas_vistas;
			Lista<Pelicula*> peliculas_no_vistas;

	public:

		Menu();

		void crear_lista_de_peliculas(char const* peliculas_vistas_txt,char const* peliculas_no_vistas_txt);

		~Menu();

	private:

		void guardar_actores_a_la_lista(string linea,Pelicula* pelicula);

		void leer_archivo(char const* archivo_txt,Lista<Pelicula*>* lista_de_peliculas);
	
};