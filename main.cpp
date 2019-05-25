#include <iostream>
#include "menu.h"

int main(int argc, char const *argv[]){

	Menu* menu = new Menu();

	menu->crear_lista_de_peliculas(argv[1],argv[2]);

	menu->mostrar_lista_de_peliculas(menu->obtener_peliculas_vistas());

	menu->mostrar_lista_de_peliculas(menu->obtener_peliculas_no_vistas());
	
	return 0;
}