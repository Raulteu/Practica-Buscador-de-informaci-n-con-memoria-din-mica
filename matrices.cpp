#include "matrices.h"


tMatriz matrizConstante(double a, int b) //Crea una matriz de tamanio BxB rellena de todos a
{
	tMatriz matrizConstante;
	if (b < MAX_TAM)
	{
		matrizConstante.cont = b;
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < b; j++)
			{
				matrizConstante.array[i][j] = a;
			}
		}
	}
	return matrizConstante;
}

tVector operator* (const tMatriz &matriz, const tVector &vector) //Multiplica una matriz por un vector
{
	tVector v;
	v.cont = vector.cont;
	double num = 0;
	int x = 0, a = 0;
	for (int i = 0; i < matriz.cont; i++) //fila
	{
		num = 0;
		x = 0;
		for (int j = 0; j < matriz.cont; j++) //columna
		{
			if (x < vector.cont)
			{
				num = num + (matriz.array[i][j] * vector.vector[x]);
				x++;
			}
		}
		v.vector[a] = num;
		a++;
	}
	return v;
}

tMatriz operator* (double a, tMatriz &matriz) //Multiplica una constante a por una matriz
{
	for (int i = 0; i < matriz.cont; i++)
	{
		for (int j = 0; j < matriz.cont; j++)
		{
			matriz.array[i][j] = matriz.array[i][j] * a;
		}
	}
	return matriz;
}

tMatriz operator+ (const tMatriz &matriz1, const tMatriz &matriz2) //Suma dos matrices
{
	tMatriz matriz;
	matriz.cont = matriz1.cont;
	for (int i = 0; i < matriz1.cont; i++)
	{
		for (int j = 0; j < matriz2.cont; j++)
		{
			matriz.array[i][j] = matriz1.array[i][j] + matriz2.array[i][j];
		}
	}
	return matriz;
}
void mostrar(tMatriz L){ //Muestra una matriz. Aunque no se necesita para la practica, lo hicimos para comprobar lo que se ibamos haciendo
	for (int i = 0; i < L.cont; i++){
		for (int j = 0; j < L.cont; j++){
			cout << L.array[i][j] << " ";
		}
		cout << endl;
	}
}

void mostrarV(tVector v){ //Muestra un vector. Mismo caso que en el mostrar matriz que hay justo arriba
	for (int j = 0; j < v.cont; j++){
		cout << v.vector[j] << " ";
	}
}

tMatriz matrizM´(tMatriz L, int N) //Dada la patriz L, devuelve a mtriz M´
{
	tMatriz m;
	m.cont = L.cont;
	int enlaces = 0;

	for (int j = 0; j < L.cont; j++) //Para cada columna (cada txt)
	{
		enlaces = 0;
		for (int i = 0; i < L.cont; i++)
		{
			if (L.array[i][j] == 1)
			{
				enlaces++; //Calcula el numero de enlaces
			}
		}
		for (int ii = 0; ii < m.cont; ii++) //Y calcula M
		{
			if (enlaces > 0)
			{
				if (L.array[ii][j] == 1.0)
				{
					m.array[ii][j] = 1.0 / enlaces;
				}
				else
				{
					m.array[ii][j] = 0;
				}
			}
			else
			{
				m.array[ii][j] = 1.0 / N;
			}
		}

	}

	return m;
}


tMatriz desdeEnlacesMatriz(const tMatriz &L, int N) //Dada la matriz L, devuelve la matriz M
//M = (1-c)Cn + cM'         Cn matriz con todas las entradas iguales a 1/N
{
	double C = 1 - c;
	tMatriz m;
	tMatriz Cn;

	m = matrizM´(L, N); //Hacemos M´
	Cn.cont = m.cont;

	Cn = matrizConstante(1.0 / N, Cn.cont); //Creamos una matriz llena de 1/N (Cn)
	Cn = operator*(C, Cn); //Y hacemos (1-c)*Cn

	//Ahora hacemos c*M´
	m = operator*(c, m);

	//Sumamos (1-c)*Cn +c*M´
	tMatriz M;
	M.cont = m.cont;
	M = operator+ (Cn, m);

	return M;
}


tVector normaliza(const tVector &vector) //Dado un vector, lo devuelve con la primera componente igual a 1 y los demas proporcionales a como eran antes
{
	tVector vec;
	vec.cont = vector.cont;
	for (int i = 0; i < vec.cont; i++)
	{
		vec.vector[i] = vector.vector[i] / vector.vector[0];
	}
	
	return vec;
}


tVector vectorPropio(const tMatriz &matriz) //Dado una matriz devuelve su vector propio
{	
	tVector ini, aux;
	double coc, intAux;
	bool cerc = true;
	ini.cont = matriz.cont;
	

		for (int r = 0; r < ini.cont; r++){
			ini.vector[r] = 1.0;
		}
		do{
		aux = operator* (matriz, ini);
		for (int c = 0; c < ini.cont; c++){
			coc = aux.vector[c] / ini.vector[c];
			intAux = abs(coc - 1);
			if ((intAux > 0.00001)){
				cerc = false;
				break;
			}
			cerc = true;
		}
		if (cerc == false){
			ini = aux;
		}
	} while (cerc == false);
	return aux;
}



