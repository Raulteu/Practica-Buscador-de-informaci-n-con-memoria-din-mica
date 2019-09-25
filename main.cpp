#include "CreadorIndices.h"

#include<iostream>
#include<string>


using namespace std;

int main()
{
	int N;
	tLista lista;
	tVisitados seen;
	tNoVisitados unseen;
	tTotal total;

	seen.cont = 0;
	unseen.cont = 0;
	total.cont = 0;

	tMatriz L;
	L = matrizConstante(0,1); //Inicializamos la matriz L
	lista.cont = 0;
	int opc, tamanio, pos;
	string clave, nueva, buscada, valor;
	bool encontrada;

	cout << "Buscador RJ-003" << endl << endl;
	cout << "Por favor, introduzca el nombre del fichero raiz a partir del que se creara el indice: ";
	cin >> valor;

	crearTabla(lista, valor, seen, unseen, total, L);

	tMatriz M, M´;
	tVector pageRank;

	N = total.cont;
	M = desdeEnlacesMatriz(L, N);
	pageRank = vectorPropio(M);
	ordenarPR(pageRank, total);
	pageRank = normaliza(pageRank);

	cout << "Introduzca una palabra para buscarla (''exit'' para terminar):";
	cin >> clave;
	transform(clave.begin(), clave.end(), clave.begin(), ::tolower);
	while (clave != "exit") {
	encontrada = buscar(lista, clave);
		if (encontrada)
		{
			cout << endl << "Se ha encontrado en: ";

			for (int i = 0; i < total.cont; i++)
			{
				for (int j = 0; j < total.cont; j++)
				{
					if (total.elementos[i] == lista.cv[posicion(lista, clave)].valor.palabra[j])
					{
						cout << total.elementos[i] << "(relevancia " << pageRank.vector[i] << ")" << endl;
					}
				}
			}
			cout << endl << endl;

		}
		else
		{
			cout << endl << "NO se ha encontrado" << endl << endl;
		}
		cout << "Introduzca una palabra para buscarla (''exit'' para terminar):";
		cin >> clave;
		transform(clave.begin(), clave.end(), clave.begin(), ::tolower);
	}
	if (clave == "exit") {
		cout << endl << "Gracias por usar nuestro buscador" << endl << "Hecho por Raul Vindel y Jose Marquez" << endl;
	}

	system("pause");
	

	
}
