#include<algorithm>
#include<cctype>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

const int maxCad = 1;

typedef string *tCadena;

typedef struct tListaCadenas {
	tCadena palabra;
	int cont;
	int cap;
};


int getTamano(const tListaCadenas &lista); //Devuelvel el tamaño de a lista
string getCadena(const tListaCadenas &lista, int pos); //Devuelve una cadena en la posicion pos;
void insertar(tListaCadenas &lista, const string &palabra); //Inserta un elemento al final de la lista
bool buscar(const tListaCadenas &lista, const string &palabra); //Devuelve true si la palabra esta en la lista
void eliminar(tListaCadenas &lista, int pos); // Elimina el elemento de la posicion pos
void imprimir(const tListaCadenas &lista); //Muestra los elementos de la lista

void inicializa(tListaCadenas &lista);
void redimensionar(tListaCadenas &lista);
