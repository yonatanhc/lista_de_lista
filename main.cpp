#include <iostream>
#include "menu.h"

int main(int argc, char const *argv[]){

	Menu* menu = new Menu();

	menu->crear_lista_de_peliculas(argv[1],argv[2]);

	menu->interfaz();

	delete menu;
	
	return 0;
}