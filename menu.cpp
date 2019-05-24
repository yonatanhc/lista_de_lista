#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Menu::Menu(){

	peliculas_vistas = new Lista<Pelicula*>();
	peliculas_no_vistas = new Lista<Pelicula*>();
}

void Menu::guardar_actores_a_la_lista(string linea,Pelicula* pelicula){
	std::stringstream str(linea); //¿............?
	string actor;
	while(str >> actor){
		pelicula->agregar_actor(actor);
	}

}

void Menu::leer_archivo(char const* archivo_txt,Lista<Pelicula*>* lista_de_peliculas){
	string linea,nombre,genero,director;
	int puntaje;

	ifstream archivo(archivo_txt);

	while(archivo >> nombre){
		archivo >> genero;
		archivo >> director;
		archivo >> puntaje;

		Pelicula* pelicula = new Pelicula(nombre,genero,director,puntaje);

		getline(archivo,linea);
		guardar_actores_a_la_lista(linea,Pelicula* pelicula);

		lista_de_peliculas->agregar(pelicula,lista_de_peliculas->tamanio() + 1);
	}

	archivo.close();

}

void Menu::crear_lista_de_peliculas(char const* peliculas_vistas_txt,char const* peliculas_no_vistas_txt){

	leer_archivo(peliculas_vistas_txt,peliculas_vistas);

	leer_archivo(peliculas_no_vistas_txt,peliculas_no_vistas);
}