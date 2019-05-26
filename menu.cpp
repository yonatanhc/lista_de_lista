#include "menu.h"

Menu::Menu(){

	peliculas_vistas = new Lista<Pelicula*>();
	peliculas_no_vistas = new Lista<Pelicula*>();
	peliculas_recomendadas = new Lista<Pelicula*>();
}

void Menu::guardar_actores_a_la_lista(string actor,Pelicula* pelicula){

	string act;

	ofstream file;
	file.open("actores.txt");
	file << actor;
	file.close();

	ifstream arch("actores.txt");
	while(arch >> act){
		pelicula->agregar_actor(act);
	}
	arch.close();
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

		getline(archivo,actor); // por alguna razon no alcanzo a leer la linea de los actores
		getline(archivo,actor); // con un solo getline necesito 3, falta revisar...
		getline(archivo,actor);

		
		guardar_actores_a_la_lista(actor,pelicula);

		

		lista_de_peliculas->agregar(pelicula,lista_de_peliculas->tamanio() + 1);
	}

	archivo.close();

}

void Menu::crear_lista_de_peliculas(char const* peliculas_vistas_txt,char const* peliculas_no_vistas_txt){

	leer_archivo(peliculas_vistas_txt,peliculas_vistas);

	leer_archivo(peliculas_no_vistas_txt,peliculas_no_vistas);
}

void Menu::mostrar_actores(Lista<string>* lista){
	cout << endl <<"ACTORES DE LA PELICULA:"<< endl;
	for (int i = 1; i <= lista->tamanio(); ++i){
		cout << lista->consultar(i) << endl;
	}
}

void Menu::mostrar_pelicula(Pelicula* pelicula){
	cout << "NOMBRE:  " << pelicula->obtener_nombre() << endl;
	cout << "GENERO:  " << pelicula->obtener_genero() << endl;
	cout << "DIRECTOR:  " << pelicula->obtener_director() << endl;
	cout << "PUNTAJE:  " << pelicula->obtener_puntaje() << endl;
	mostrar_actores(pelicula->obtener_lista_de_actores());
	cout << ".............................." << endl;
}

void Menu::mostrar_lista_de_peliculas(Lista<Pelicula*>* lista){
	for (int i = 1; i <= lista->tamanio(); ++i){
		Pelicula* pelicula = lista->consultar(i);
		mostrar_pelicula(pelicula);
	}
}


bool Menu::coinciden_actores(Pelicula* peli_v,Pelicula* peli_nv){
	Lista<string>* act_v = peli_v->obtener_lista_de_actores();
	Lista<string>* act_nv = peli_nv->obtener_lista_de_actores();

	for (int i = 1; i <= act_v->tamanio(); ++i){
		for (int j = 1; j <= act_nv->tamanio(); ++j){
			if(act_v->consultar(i) == act_nv->consultar(j)){
				return true;
			}
		}
	}
	return false;
}

bool Menu::coincidencia(Pelicula* peli_v,Pelicula* peli_nv){
	if(peli_nv->obtener_puntaje() >= 7) return true;
	else{

		if(peli_v->obtener_director() == peli_nv->obtener_director() || coinciden_actores(peli_v,peli_nv)){
			return true;
		}

	}
	return false;
}

bool Menu::comparar_lista_pelicula_vista(Pelicula* peli_nv){
	for (int i = 1; i <= peliculas_vistas->tamanio(); ++i){
		Pelicula* peli_v = peliculas_vistas->consultar(i);
		if(peli_v->obtener_genero() == peli_nv->obtener_genero() && coincidencia(peli_v,peli_nv)){
			return true;
		}
	}
	return false;
}

void Menu::crear_lista_de_peliculas_recomendadas(){
	for (int i = 1; i <= peliculas_no_vistas->tamanio(); ++i){

		Pelicula* peli_nv = peliculas_no_vistas->consultar(i);
		if(comparar_lista_pelicula_vista(peli_nv)){
			peliculas_recomendadas->agregar(peli_nv,peliculas_recomendadas->tamanio()+1);
		}
	}

}

void Menu::interfaz(){
	int opcion;

	do{
		cout <<"*" << "***************************************" <<"*"<< endl;
		cout <<"*" << "........MENU DE OPCIONES..............." <<"*"<< endl;
		cout <<"*" << "mostrar peliculas vistas............[1]" <<"*"<< endl;
		cout <<"*" << "mostrar peliculas NO vistas.........[2]" <<"*"<< endl;
		cout <<"*" << "generar peliculas recomendadaas.....[3]" <<"*"<< endl;
		cout <<"*" << "mostrar peliculas recomendadas......[4]" <<"*"<< endl;
		cout <<"*" << "salir...............................[5]" <<"*"<< endl;
		cout <<"*" << ".....elija una de las opciones........." <<"*"<< endl;
		cout <<"*" << "***************************************" <<"*"<< endl;
		cin >> opcion;

		switch(opcion){

			case 1:
				cout << "LISTA DE PELICULAS VISTAS:" << endl<< endl;
				mostrar_lista_de_peliculas(peliculas_vistas);
			break;

			case 2:
				cout << "LISTA DE PELICULAS NO VISTAS:" << endl<< endl;
				mostrar_lista_de_peliculas(peliculas_no_vistas);
			break;

			case 3:
				crear_lista_de_peliculas_recomendadas();
			break;

			case 4:
				cout << "LISTA DE PELICULAS RECOMENDADAS:" << endl<< endl;
				mostrar_lista_de_peliculas(peliculas_recomendadas);
			break;

		}



	}while(opcion != 5);
}