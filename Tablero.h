#ifndef TABLERO_H_
#define TABLERO_H_
const int MAXTAMANIO=8;

typedef int Tmatriz[MAXTAMANIO][MAXTAMANIO];

struct tablero{
	Tmatriz m;
	int tamanio;
};


//Complejidad O(n²)
//Pre: Se introduce el tablero con el tamaño que le queremos dar a este ,3<=tam<=8
//Post: Altera el tablero dejando todas las casillas con valor 0
void iniciar(tablero &t,int tam);



//Complejidad O(n²)
//Pre: Se introduce el tablero y el número máximo que queremos comprobar( int max debe ser potencia de 2)
//Post: Devuelve true si el número está en alguna casilla del tablero y false si no lo está
bool puntuacionMax(tablero t,int max);




//Complejidad O(n)
//Pre: Se introduce el struct tablero en el que queremos saber si todas sus casillas tienen un valor distinto de 0 o no
//Post: Devuelve un booleano true si todos sus valores son distintos de 0
	//devuelve false si almenos un valor es igual a 0
bool EstaLleno(tablero &t);


void eliminarColumnas(tablero &t,int num);


//Complejidad O(n)
//Pre: Se introduce el struct tablero en el que queremos que generar un número
	//el tablero ha de tener todas sus casillas con valor 0
//Post: Genera una cantidad de casillas igual al entero numiniciar un  2 o un 4 con 50% de posibilidades
	//entre uno u otro en numiniciar casillas  aleatorias del tablero
void generar_inicial(tablero &t,int numiniciar);


//Complejidad O(n)
//Pre: Se introduce el struct tablero en el que queremos que generar un número
//Post: Si el tablero no esta lleno genera un 2 o un 4 con 50% de posibilidades
	//entre uno u otro en una casilla vacia aleatoria del tablero
void generar(tablero &t);


//Complejidad O(1)
//Pre: Se introduce el struct tablero del que queremos que nos diga el tamaño
//Post: Devuelve el valor  t.tamanio del struct tablero
int quetamanio(tablero t);

//Complejidad O(1)
//Pre: Se introduce el tablero y la fila y columna de la casilla de la que queremos saber si esta vacia
	// 0<=fila ^ col<t.tamanio
//Post: Devuelve un booleano que nos indica true si la casilla tiene el valor 0 y false si el valor es !=0
bool vacia(tablero t, int fila, int col);

//Complejidad O(1)
//Pre: Se introduce el tablero y la fila y columna de la casilla de la que queremos saber el valor
	// 0<=fila ^ col<t.tamanio
//Post: Devuelve el valor de la casilla el cual es un entero
int obtenerValor(tablero t,int fila,int col);


//Complejidad O(n³)
//Pre: Se introduce el tablero y utilizamos el parámetro de salida puntuación para que devuelva la puntuacion
	//de la suma en todo el tablero
//Post:Devuelve el tablero desplazado y  sumado a la izquierda y la puntuación de toda esa suma está almacenada en el parametro
	//de salida puntuacion
void desplazarIzd(tablero &t,long long int &puntuacion);

//Complejidad O(n²)
//Pre: Se introduce el tablero y la fila que queremos desplazar a la izquierda del tablero
	// 0<=fila<t.tamanio
//Post: Altera esa fila desplazandola a la izquierda de la matriz que es el tablero
void desplazar_fila_Izd(tablero &t,int fila);

//Complejidad O(n)
//Pre: Se introduce el tablero y la fila que queremos sumar desde la izquierda del tablero
	// 0<=fila<t.tamanio
//Post: Altera esa fila sumando los valores contiguos al que estamos comparando y devuelve la puntuación, que es el valor acumulado de las sumas
long long int sumar_Izd(tablero &t,int fila);


//Complejidad O(n³)
//Pre: Se introduce el tablero y utilizamos el parámetro de salida puntuación para que devuelva la puntuacion
	//de la suma en todo el tablero
//Post:Devuelve el tablero desplazado y  sumado  a la derecha y la puntuación de toda esa suma está almacenada en el parametro
	//de salida puntuacion
void desplazarDcha(tablero &t,long long int &puntuacion);


//Complejidad O(n²)
//Pre: Se introduce el tablero y la fila que queremos desplazar a la derecha del tablero
	// 0<=fila<t.tamanio
//Post: Altera esa fila desplazandola a la derecha de la matriz que es el tablero
void desplazar_fila_Dcha(tablero &t,int fila);



//Complejidad O(n)
//Pre: Se introduce el tablero y la fila que queremos sumar desde la derecha del tablero
	// 0<=fila<t.tamanio
//Post: Altera esa fila sumando los valores contiguos al que estamos comparando y devuelve la puntuación, que es el valor acumulado de las sumas
long long int sumar_Dcha(tablero &t,int fila);


//Complejidad O(n³)
//Pre: Se introduce el tablero y utilizamos el parámetro de salida puntuación para que devuelva la puntuacion
	//de la suma en todo el tablero
//Post:Devuelve el tablero desplazado y  sumado  hacia arriba y la puntuación de toda esa suma está almacenada en el parametro
	//de salida puntuacion
void desplazarUp(tablero &t,long long int &puntuacion);


//Complejidad O(n²)
//Pre: Se introduce el tablero y la columna que queremos desplazar arriba del tablero
	// 0<= col<t.tamanio
//Post: Altera esa columna desplazandola arriba de la matriz que es el tablero
void desplazar_col_Up(tablero &t,int col);


//Complejidad O(n)
//Pre: Se introduce el tablero y la columna que queremos sumar desde arriba del tablero
	// 0<=col<t.tamanio
//Post: Altera esa columna sumando los valores contiguos al que estamos comparando y devuelve la puntuación, que es el valor acumulado de las sumas
long long int sumar_Up(tablero &t,int col);


//Complejidad O(n³)
//Pre: Se introduce el tablero y utilizamos el parámetro de salida puntuación para que devuelva la puntuacion
	//de la suma en todo el tablero
//Post:Devuelve el tablero desplazado y  sumado  abajo y la puntuación de toda esa suma está almacenada en el parametro
	//de salida puntuacion
void desplazarDown(tablero &t,long long int &puntuacion);


//Complejidad O(n²)
//Pre: Se introduce el tablero y la columna que queremos desplazar abajo del tablero
	// 0<= col<t.tamanio
//Post: Altera esa columna desplazandola abajo de la matriz que es el tablero
void desplazar_col_Down(tablero &t,int col);



//Complejidad O(n)
//Pre: Se introduce el tablero y la columna que queremos sumar desde abajo del tablero
	// 0<=col<t.tamanio
//Post: Altera esa columna  sumando los valores contiguos al que estamos comparando y devuelve la puntuación, que es el valor acumulado de las sumas
long long int sumar_Down(tablero &t,int col);

#endif /* TABLERO_H_ */
