#include "menu.h"

Menu::Menu(){

	peliculas_vistas = new Lista<Pelicula*>();
	peliculas_no_vistas = new Lista<Pelicula*>();
}


void Menu::leer_archivo(char const* archivo_txt,Lista<Pelicula*>* lista_de_peliculas){
	string actor,nombre,genero,director;
	int puntaje;

	ifstream archivo(archivo_txt);

	while(archivo >> nombre){
		archivo >> genero;
		archivo >> puntaje;
		archivo >> director;

		Pelicula* pelicula = new Pelicula(nombre,genero,director,puntaje);

		while(archivo >> actor && actor != "/n"){
			pelicula->agregar_actor(actor);
		}
		

		lista_de_peliculas->agregar(pelicula,lista_de_peliculas->tamanio() + 1);
	}

	archivo.close();

}

void Menu::crear_lista_de_peliculas(char const* peliculas_vistas_txt,char const* peliculas_no_vistas_txt){

	leer_archivo(peliculas_vistas_txt,peliculas_vistas);

	leer_archivo(peliculas_no_vistas_txt,peliculas_no_vistas);
}

void Menu::mostrar_actores(Lista<string>* lista){
	for (int i = 1; i <= lista->tamanio(); ++i){
		cout << lista->consultar(i) << endl;
	}
}

void Menu::mostrar_pelicula(Pelicula* pelicula){
	cout << pelicula->obtener_nombre() << endl;
	cout << pelicula->obtener_genero() << endl;
	cout << pelicula->obtener_director() << endl;
	cout << pelicula->obtener_puntaje() << endl;
	mostrar_actores(pelicula->obtener_lista_de_actores());
	cout << ".............................." << endl;
}

void Menu::mostrar_lista_de_peliculas(Lista<Pelicula*>* lista){
	for (int i = 1; i <= lista->tamanio(); ++i){
		Pelicula* pelicula = lista->consultar(i);
		mostrar_pelicula(pelicula);
	}
}

Lista<Pelicula*>* Menu::obtener_peliculas_vistas(){
	return peliculas_vistas;
}

Lista<Pelicula*>* Menu::obtener_peliculas_no_vistas(){
	return peliculas_no_vistas;
}