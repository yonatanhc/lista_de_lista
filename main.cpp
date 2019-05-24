#include <iostream>
#include "menu.h"

int main(int argc, char const *argv[]){

	Menu* menu = new Menu();

	menu->crear_lista_de_peliculas(argv[2],argv[3]);
	
	return 0;
}