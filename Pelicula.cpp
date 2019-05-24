#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula(string nombre,string genero,string director,int puntaje){
	this->nombre = nombre;
	this->genero = genero;
	this->director = director;
	this->puntaje = puntaje;
	this->actores = new Lista<string>();
}

string Pelicula::obtener_nombre(){
	return nombre;
}

string Pelicula::obtener_genero(){
	return genero;
}

string Pelicula::obtener_director(){
	return director;
}

int Pelicula::obtener_puntaje(){
	return puntaje;
}

void Pelicula::agregar_actor(string nuevo_actor){
	actores->agregar(nuevo_actor,actores->tamanio() + 1);
}

Lista<string>* Pelicula::obtener_lista_de_actores(){
	return actores;
}

/*void Pelicula::asignar_nombre(string nuevo_nombre){
	nombre = nuevo_nombre;
}

void Pelicula::asignar_genero(string nuevo_genero){
	genero = nuevo_genero;
}

void Pelicula::asignar_director(string nuevo_director){
	director = nuevo_director;
}

void Pelicula::asignar_puntaje(int nuevo_puntaje){
	puntaje = nuevo_puntaje;
}*/