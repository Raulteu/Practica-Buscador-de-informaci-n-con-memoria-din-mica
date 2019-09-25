#include "TablaClaveValor.h"

int getTamanio(const tLista &lista)
{
	int tamanio = lista.cont;
	return tamanio;
}

tArraay getRegistro(const tLista &lista, int pos)
{
	return lista.cv[pos];
}

bool buscar(const tLista &lista, const string &clave)
{
	int pos = -1, ini = 0, fin = lista.cont - 1, mitad;
	bool encontrada = false;
	while ((ini <= fin) && (!encontrada))
	{
		mitad = (ini + fin) / 2;
		if (clave == lista.cv[mitad].clave)
		{
			encontrada = true;
		}
		else if (clave < lista.cv[mitad].clave)
		{
			fin = mitad - 1;
		}
		else
		{
			ini = mitad + 1;
		}
	}
	return encontrada;
}

int posicion(const tLista &lista, const string &clave)
{
	int pos = 0, ini = 0, fin = lista.cont - 1, mitad;
	bool encontrada = false;
	while ((ini <= fin) && (!encontrada))
	{
		mitad = (ini + fin) / 2;
		if (clave == lista.cv[mitad].clave)
		{
			encontrada = true;
			pos = mitad;
		}
		else if (clave < lista.cv[mitad].clave)
		{
			fin = mitad - 1;
			if (ini > fin + 1)
			{
				pos = fin;
			}
			if (pos == -1) { pos = 0; }
		}
		else
		{
			ini = mitad + 1;
		pos = ini;
		}
	}
		
	return pos;
}

void insertarClave(tLista &lista, const string &clave, const string &valor)
{
	if (lista.cont < maxCV) //Comprobamos que el array no esta lleno
	{
		int pos, pos2;
		bool encontrado = false;
		pos = posicion(lista, clave);
		if (buscar(lista, clave))
		{
			insertar(lista.cv[pos].valor, valor);
		}
		else
		{
			if (lista.cont == 0)
			{
				lista.cv[lista.cont].clave = clave;
				lista.cv[lista.cont].valor.cont = 0;
				insertar(lista.cv[pos].valor, valor);
				lista.cont++;
			}
			else
			{
				for (int i = lista.cont; i > pos; i--)
				{
					lista.cv[i] = lista.cv[i - 1];
				}
				for (int j = 0; j < lista.cv[pos].valor.cont; j++)
				{
					lista.cv[pos].valor.palabra[j] = " ";
				}
				lista.cv[pos].clave = clave;
				lista.cv[pos].valor.cont = 0;
				insertar(lista.cv[pos].valor, valor);
				lista.cont++;
			}
		}
	}
	cout << endl << endl << endl;
	for (int i = 0; i < lista.cont; i++)
	{
		cout << lista.cv[i].clave << " ";
		for (int j = 0; j < lista.cv[i].valor.cont; j++)
		{
			cout << lista.cv[i].valor.palabra[j];
		}
		cout << endl;
	}


		/*
		int pos, pos2;
		bool encontrado = false;
		pos = posicion(lista, clave);
		if (pos == -1)
		{
			if (lista.cont == 0)
			{
				lista.cv[lista.cont].clave = clave;
				lista.cv[lista.cont].valor.cont = 0;
				lista.cv[lista.cont].valor.palabra[lista.cv[lista.cont].valor.cont] = valor;
				lista.cv[lista.cont].valor.cont++;
				lista.cont++;
			}
			else
			{
				pos2 = 0;
				while ((pos2 < lista.cont) && !(lista.cv[pos2].clave > clave))
				{
					pos2++;
				}
				for (int j = lista.cont+1; j > pos2; j--)
				{
					lista.cv[j] = lista.cv[j - 1];
				}
				lista.cv[pos2].clave = clave;
				lista.cv[pos2].valor.cont = 0;
				lista.cv[pos2].valor.palabra[lista.cv[pos2].valor.cont] = valor;
				lista.cv[pos2].valor.cont++;
				lista.cont++;
			}
		}
		else
		{
			for (int i = 0; i < lista.cv[pos].valor.cont; i++){
				if (lista.cv[pos].valor.palabra[i] == valor){
					encontrado = true;
				}
			}
			if (!encontrado){
				lista.cv[pos].valor.palabra[lista.cv[pos].valor.cont] = valor; // falta comprobar qeu
				lista.cv[pos].valor.cont++;
			}
			encontrado = false;
		}
		*/
}

void imprimirLista(const tLista &lista)
{
	cout << setw(25) << left << "Clave" << setw(10) << left << "Valor" << endl<< endl;
	for (int i = 0; i < lista.cont; i++)
	{
		cout << setw(25) << left << lista.cv[i].clave;
		for (int j = 0; j < lista.cv[i].valor.cont; j++)
		{
			cout << lista.cv[i].valor.palabra[j] << "   ";
		}
		cout << endl;
	}
}