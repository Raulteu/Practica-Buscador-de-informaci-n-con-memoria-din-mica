#include "listacadenas.h"
#include <iostream>
#include <iomanip>

const int maxCV = 200;

typedef struct {
	string clave;
	tListaCadenas valor;
} tArraay;

typedef tArraay tCV[maxCV]; //tRegistroIndicePalabras en las diapositivas segun ManuGod

typedef struct {
	int cont;
	tCV cv;
} tLista;

int getTamanio(const tLista &lista); //Devuelve el tamanio de la tabla
tArraay getRegistro(const tLista &lista, int pos); //Devuelve el registro (clave-valor) en la posicion pos
bool buscar(const tLista &lista, const string &clave); // Devuelve true si encuentra la clave "clave" 
int posicion(const tLista &lista, const string &clave); //Devuelve la posicion en la que esta la clave "clave" (-1 si no esta)
void insertarClave(tLista &lista, const string &clave, const string &valor); //Si palabra es ya una clave de la tabla, añade "valor" a la lista de archivos correspondiente.Si no, crea un registro nuevo con esa información.
void imprimirLista(const tLista &lista); //Imprime a tabla
