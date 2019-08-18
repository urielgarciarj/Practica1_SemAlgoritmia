#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;


struct Nodo {
	int id;
	string nombre;
	string apellido;
	string telefono;
	string celular;
	string direccion;
	Nodo* siguiente;
};
//hola a todos

//FUNCIONES A UTILIZAR
void insertarLista(Nodo*&, int, string, string, string, string, string);
void mostrarLista(Nodo*);
void buscarLista(Nodo* lista, int n);
void eliminarNodo(Nodo*& lista, int n);
void eliminarLista(Nodo*& lista, int n);
void menu();

void insertarLista(Nodo*& lista, int n, string nombre, string apellido, string telefono, string celular, string direccion) {
	Nodo* nuevo_nodo = new Nodo(); //Reservamos espacio en la memoria para el nuevo nodo
	nuevo_nodo->id = n; // Al nuevo nodo le insertamos el dato que se nos dio
	nuevo_nodo->nombre = nombre;
	nuevo_nodo->apellido = apellido;
	nuevo_nodo->telefono = telefono;
	nuevo_nodo->celular = celular;
	nuevo_nodo->direccion = direccion;

	Nodo* aux1 = lista; //Nodos auxiliares al momento de insertar los datos, siempre señala lom mismo que lista
	Nodo* aux2 = NULL; //Nodos auxiliares al momento de insertar los datos

	while ((aux1 != NULL) && (aux1->id < n)) { //En caso de que sea mayor el numero que queramos ingresar, en el caso de que ya tengamos un numero en la lista creado
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}

	if (lista == aux1) { //En caso de que vaya al inicio
		lista = nuevo_nodo; //lista ahora apuntara a donde apuntaba el nuevo nodo
	}
	else {
		aux2->siguiente = nuevo_nodo;
	}

	nuevo_nodo->siguiente = aux1; //Ahora siguiente apuntara a aux1, que es NULL
	cout << "Elemento " << n << " insertado a lista correctamente" << endl;
}

void mostrarLista(Nodo* lista) {
	Nodo* actual = new Nodo();
	actual = lista;
	while (actual != NULL) {
		cout << actual->id << ", ";
		cout << actual->nombre << ", ";
		cout << actual->apellido << ", ";
		cout << actual->telefono << ", ";
		cout << actual->celular << ", ";
		cout << actual->direccion << " -> " << endl;
		actual = actual->siguiente;
	}
}

void buscarLista(Nodo* lista, int n) {
	bool band = false;
	Nodo* actual = new Nodo();
	actual = lista;
	while ((actual != NULL) && (actual->id <= n)) { //Mientras la lista no apunte a NULL, el while seguira buscando el id que le fue proporcionado
		if (actual->id == n) { //En caso de que haya sido encontrado, se imprimiran todos los datos del nodo
			cout << actual->nombre << ", ";
			cout << actual->apellido << ", ";
			cout << actual->telefono << ", ";
			cout << actual->celular << ", ";
			cout << actual->direccion << " -> " << endl;
			band = true;
		}
		actual = actual->siguiente;
	}
	if (band == true) {
		cout << "Contacto con el id: " << n << "Si ha sido encontrado en la lista" << endl;
	}
	else {
		cout << "Contacto con el id: " << n << "No a sido encontrado en la lista" << endl;
	}
}

void eliminarNodo(Nodo*& lista, int n) {
	if (lista != NULL) {
		Nodo* aux_borrar;
		Nodo* anterior = NULL;

		aux_borrar = lista;
		//Ir recorriendo elementos de la lista para verificar si existe el elemento a buscar
		while ((aux_borrar != NULL) && (aux_borrar->id != n)) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		//Si no existe el elemento el siguiente IF se encargara de mostrarlo en pantalla
		if (aux_borrar == NULL) {
			cout << "El elemento no existe dentro de la lista" << endl;
		}
		//El elemento fue encontrado en la primera posicion de la lista
		else if (anterior == NULL) {
			lista = lista->siguiente;
			delete aux_borrar;
			cout << "Elemento " << n << "Ha sido borrado exitosamente de la lista" << endl;
		}
		//El elemento fue encontrado, despues de la primera posicion de la lista
		else {
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
			cout << "Elemento " << n << "Ha sido borrado exitosamente de la lista" << endl;
		}
	}
}

void eliminarLista(Nodo*& lista, int n) {
	//elimina todo alv
	Nodo* aux = lista;
	n = aux->id;
	lista = aux->siguiente;
	delete aux;
}


int main()
{
	menu();
	return 0;
}

void menu() {
	int op = 0;
	Nodo* lista = NULL;
	int Myid = 1;
	string nombre;
	string apellido;
	string telefono;
	string celular;
	string direccion;

	do {
		cout << "******************************************" << endl;
		cout << "************ ESCOGE UNA OPCION ***********" << endl;
		cout << "******************************************" << endl;
		cout << "*  (1): Agregar Contacto                 *" << endl;
		cout << "*  (2): Mostrar Contactos                *" << endl;
		cout << "*  (3): Buscar Contacto                  *" << endl;
		cout << "*  (4): Eliminar Contacto                *" << endl;
		cout << "*  (5): Eliminar todos los elementos     *" << endl;
		cout << "*  (0): Salir del menu                   *" << endl;
		cout << "******************************************" << endl;
		cin >> op;
		system("cls");

		switch (op)
		{
		case 1: cout << "Nombre Contacto: " << endl;
			cin >> nombre;
			cout << "Apellido de Contacto: " << endl;
			cin >> apellido;
			cout << "Telefono de contacto: " << endl;
			cin >> telefono;
			cout << "Celular de contacto: " << endl;
			cin >> celular;
			cout << "Direccion de contacto: " << endl;
			cin >> direccion;

			insertarLista(lista, Myid, nombre, apellido, telefono, celular, direccion);
			Myid += 1;
			system("pause");
			system("cls");
			break;

		case 2: mostrarLista(lista);
			cout << endl;
			system("pause");
			system("cls");
			break;

		case 3: cout << "Introduce valor a buscar: " << endl;
			cin >> Myid;
			buscarLista(lista, Myid);
			system("pause");
			system("cls");
			break;

		case 4: cout << "Introduce valor a eliminar: " << endl;
			cin >> Myid;
			eliminarNodo(lista, Myid);
			system("pause");
			system("cls");
			break;

		case 5: cout << "Todos los elementos de la lista fueron removidos " << endl;
			while (lista != NULL) {
				eliminarLista(lista, Myid);
			}
			system("pause");
			system("cls");

		default: cout << "Opcion no valida" << endl;
			system("pause");
			system("cls");
			break;
		}

	} while (op != 0);
}