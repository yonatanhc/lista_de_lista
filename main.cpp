#include <iostream>
#include "menu.h"

int main(int argc, char const *argv[]){

	Menu* menu = new Menu();

	menu->crear_lista_de_peliculas(argv[2],argv[3]);

	menu->mostrar_lista_de_peliculas(menu->obtener_peliculas_vistas());

	menu->mostrar_lista_de_peliculas(menu->obtener_peliculas_no_vistas());
	
	return 0;
}