#include "listacadenas.h"

int getTamano(const tListaCadenas &lista)
{
	int tamanio = 0;
	tamanio = lista.cont;
	return tamanio;
}

string getCadena(const tListaCadenas &lista, int pos)
{
	string cadena;
	if (pos <= lista.cont)
	{
		cadena = lista.palabra[pos];
	}
	else { cadena = "ERROR, NO SE HA ENCONTRADO LA PALABRA"; }
	return cadena;
}

void insertar(tListaCadenas &lista, const string &palabra)
{
	bool encontrado = false;
	for (int i = 0; i < lista.cont; i++)
	{
		if (lista.palabra[i] == palabra)
		{
			encontrado = true;
		}
	}
	if (lista.cont >= maxCad) //Comprobamos que no esta lleno el array
	{
		redimensionar(lista);
	}
	if (!encontrado)
	{
		inicializa(lista);
		lista.palabra[lista.cont] = palabra;
		lista.cont++;
	}
}

bool buscar(const tListaCadenas & lista, const string &palabra) 
{
	bool exito = false;
	int i = 0;
	while ((!exito) && (i < lista.cont))
	{
		if (lista.palabra[i] == palabra)
		{
			exito = true;
		}
		i++;
	}
	return exito;
}

void eliminar(tListaCadenas &lista, int pos)
{
	lista.palabra[pos] = " ";
	for (int i = pos; i < lista.cont; i++)
	{
		lista.palabra[i] = lista.palabra[i + 1];
	}
	if (lista.cont > 0)
	{
		lista.cont--;
	}
}


void imprimir(const tListaCadenas &lista)
{
	for (int i = 0; i < lista.cont; i++)
	{
		cout << lista.palabra[i] << endl;
	}
}

void inicializa(tListaCadenas &lista)
{
	lista.cap = maxCad;
	lista.palabra = new string[maxCad];
}

void redimensionar(tListaCadenas &lista)
{
	int tam;
	tam = (lista.cap * 3 / 2) + 1;
	string *palabra2 = new string[tam];

	for (int i = 0; i < lista.cap; i++)
	{
		palabra2[i] = lista.palabra[i];
	}
	lista.cap = tam;

	for (int j = lista.cap; j < tam; j++)
	{
		palabra2[j] = " ";
	}
 	delete[] lista.palabra;

	lista.palabra = palabra2;
}