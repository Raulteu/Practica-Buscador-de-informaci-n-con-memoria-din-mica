#include "CreadorIndices.h"

void crearTabla(tLista &tabla, const string &archivoInicial, tVisitados &seen, tNoVisitados &unseen, tTotal &total, tMatriz &L)
{
	cout << endl << "Cargando...[CORRECTO]" << endl;
	for (int x = 0; x < tabla.cont; x++) //Inicializa a "Vacio"
	{
		tabla.cv[x].clave = " ";
		for (int i = 0; i < tabla.cv[x].valor.cont; i++)
		{
			tabla.cv[x].valor.palabra[i] = " ";
		}
	}
	
	unseen.elementos[unseen.cont] = archivoInicial;
	unseen.cont++;
	total.elementos[total.cont] = unseen.elementos[0];
	total.cont++;
	
	leerArc(tabla, archivoInicial, seen, unseen, total, L);
	while (unseen.cont > 0){
		leerArc(tabla, unseen.elementos[0], seen, unseen, total, L);
	}
	cout << endl << "Creando tablas...[CORRECTO]" << endl << endl;
}

void leerArc(tLista &lista, string valor, tVisitados &seen, tNoVisitados &unseen, tTotal &total, tMatriz &L){
	ifstream palabra;
	string word;
	int i = 0, j = seen.cont, ii = 0, longitud, numArc,comprobar = 0;
	bool found = false, encontrado = false;
	palabra.open(valor);
	if (!palabra.is_open()){
		cout << endl << "Error" << endl << endl;
		cout << "Fichero no encontrado, por favor intruduzca un correcto: ";
		cin >> valor;
		unseen.elementos[0] = valor;
		total.elementos[0] = valor;
		exit;
	}
	else{
		seen.elementos[seen.cont] = unseen.elementos[0];
		seen.cont++;


		for (int i = 0; i < unseen.cont; i++){
			unseen.elementos[i] = unseen.elementos[i + 1];
		}
		unseen.cont--;
		while (!palabra.eof()){
			palabra >> word;
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			longitud = word.length();
			if (!ispunct(word[longitud - 1])){
				insertarClave(lista, word, valor); // valor es el txt
			}
			else{
				word.erase(longitud - 1);
				if (word[0] == '<'){
					word.erase(word.begin());
					longitud = word.length();
					if (word[longitud - 1] == '>'){
						word.erase(longitud - 1);
					}
					ii = 0;
					//Si esta en totales en la posicion i ponemos Lij = 1
					while (!encontrado && ii < total.cont)
					{
						if (total.elementos[ii] == word)
						{
							encontrado = true;
						}
						ii++;
					}
					if (encontrado)
					{
						L.array[ii-1][j] = 1.0; //ii-1 porque hace un ii++ antes de salir
					}
					//Si no, aniadirlo a totales y no visitados y ampliar el tamanio de L en 1
					else
					{
						L.cont++;
						//Ampliamos el tamanio y lo inicializamos a 0
						for (int j = 0; j < L.cont; j++)
						{
							L.array[L.cont - 1][j] = 0;
						}
						for (int i = 0; i < L.cont; i++)
						{
							L.array[i][L.cont - 1] = 0;
						}
						//Aniadimos
						L.array[L.cont - 1][j] = 1.0;
					}
					encontrado = false;
					found = false;
					comprobar = 0;
					while ((word != seen.elementos[comprobar]) && (!found) && (comprobar <= seen.cont)) { //Comprueba que el txt no esta en la lista Visitados
						comprobar++;
					} 
					if (word == seen.elementos[comprobar]){
						found = true;
					}
					comprobar = 0;
					if (!found){// Si no esta ...
						while ((word != total.elementos[comprobar]) && (!found) && (comprobar <= total.cont)) {//...Comprueba que el txt no esta en la lista NoVisitados para que no se repita
								comprobar++;
								
							}
						if (word == total.elementos[comprobar]){
							found = true;
						}
							if (!found){ // Si no se encuentra en ninguna de las dos la guarda
								unseen.elementos[unseen.cont] = word;
								unseen.cont++;
								total.elementos[total.cont] = word;
								total.cont++;
							}

						found = false;
					}
				}
				else {
					insertarClave(lista, word, valor);
				}
				numArc = total.cont;
			}
		}
	}
}


void ordenarPR(tVector &vector, tTotal &total)
{
	for (int i = 0; i < vector.cont - 1; i++)
	{
		// Desde el primer elemento hasta el penúltimo
		for (int j = i + 1; j < vector.cont; j++)
		{
			// Desde i+1 hasta el final
			if (vector.vector[j] > vector.vector[i])
			{
				double tmp;
				string aux;
				tmp = vector.vector[i];
				vector.vector[i] = vector.vector[j];
				vector.vector[j] = tmp;

				aux = total.elementos[i];
				total.elementos[i] = total.elementos[j];
				total.elementos[j] = aux;

			}
		}
	}
}
