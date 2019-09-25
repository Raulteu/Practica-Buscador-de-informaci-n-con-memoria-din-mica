#include "TablaClaveValor.h"
#include "matrices.h"

#include <iostream>
#include <string>

using namespace std;

const int MaxElementos = 100;

typedef string tElementos[MaxElementos];

typedef struct tVisitados
{
	tElementos elementos;
	int cont;
};

typedef struct tNoVisitados
{
	tElementos elementos;
	int cont;
};

typedef struct tTotal
{
	tElementos elementos;
	int cont;
};


void crearTabla(tLista &tabla, const string &archivoInicial, tVisitados &seen, tNoVisitados &unseen, tTotal &total, tMatriz &L);
void leerArc(tLista &lista, string valor, tVisitados &seen, tNoVisitados &unseen, tTotal &total, tMatriz &L);


void ordenarPR(tVector &vector, tTotal &total); //Ordena un vector, dejando la componente mayor la primera, y la menor la ultima
