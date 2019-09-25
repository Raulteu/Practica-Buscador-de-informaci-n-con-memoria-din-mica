#include <iostream>

using namespace std;

const int MAX_TAM = 50.0;
const double c = 0.85;

typedef double tArray[MAX_TAM][MAX_TAM];
typedef double tVec[MAX_TAM];

typedef struct {
	tArray array;
	int cont;
} tMatriz;

typedef struct {
	int cont;
	tVec vector;
} tVector;

void mostrar(tMatriz L);
void mostrarV(tVector v);
tMatriz matrizConstante(double a, int b);
tVector operator* (const tMatriz &matriz, const tVector &vector);
tMatriz operator* (double a, tMatriz &matriz);
tMatriz operator+ (const tMatriz &matriz1, const tMatriz &matriz2);

tMatriz matrizM´(tMatriz L, int N); //Crea la matriz M´

tMatriz desdeEnlacesMatriz(const tMatriz &L, int M); //M = (1-c)Cn + cM'         Cn matriz con todas las entradas iguales a 1/N (CALCULA LA MATRIZ M)
tVector normaliza(const tVector &vector);
tVector vectorPropio(const tMatriz &matriz);