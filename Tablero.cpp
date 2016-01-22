#include "Tablero.h"
#include <cstdlib>
#include <iostream>

void iniciar(tablero &t,int tam){
	int i,j;
	t.tamanio=tam;
	for(i=0;i<t.tamanio;i++){
		for(j=0;j<t.tamanio;j++){
			t.m[i][j]=0;

		}
	}
}

bool puntuacionMax(tablero t,int max){
	bool puntuacionAlcanzada = false;
		int i, j;

		for(i=0;i<t.tamanio;i++){
				for(j=0;j<t.tamanio;j++){

					if(t.m[i][j]==max)
						puntuacionAlcanzada=true;
				}
			}
			return puntuacionAlcanzada;

}



bool EstaLleno(tablero &t){
    bool lleno=true;
	int i=0;
	int j;

	while(i<t.tamanio && lleno){
			for(j=0;j<t.tamanio;j++){

				if(t.m[i][j]==0)
					lleno=false;
			}
			i++;
	}
return lleno;
}

void eliminarColumnas(tablero &t,int num){
	int i=0;
	int j;
	int suma=0;
	while(i<t.tamanio){
		for(j=0;j<t.tamanio;j++){
			suma = suma + t.m[i][j];
		}
		if(suma==num){
			for(j=0;j<t.tamanio;j++){
				t.m[i][j]=0;
			}
			i++;
		}
		else{
			i++;
		}
	}
}


void generar_inicial(tablero &t,int numiniciar){
	int j;
	int i;
	i=rand()%t.tamanio;
	j=rand()%t.tamanio;
	bool parar=false;
	int contar = 0;



	int gen;

		while(!parar){

				//si esa casilla esta ocupada se busca otra casilla
				if(t.m[i][j] != 0){

					i=rand()%t.tamanio;
						j=rand()%t.tamanio;
				}
				else{
					contar=contar+1;
                //se inserta y se sale del bucle
					if(contar == numiniciar)
						parar=true;


					gen = rand()%2;//se busca un numero aleatorio si es par sale 2 si es impar sale 4

					if(gen%2 == 0){
						t.m[i][j]=2;
					}
					else{
						t.m[i][j]=4;
					}

					}
				}
			}




void generar(tablero &t){

	int j;
	int i;
	i=rand()%t.tamanio;
	j=rand()%t.tamanio;
	bool parar=false;
	bool lleno=false;
	lleno =  EstaLleno(t);//Booleando encargado de solucionar un error que habia cuando el módulo se quedaba en bucle infinito
	//debido a que todas las casillas estaban lleans y no se podian generar numeros nuevos




	int gen;

		while(!parar && !lleno){

				//si esa casilla esta ocupada se busca otra casilla
				if(t.m[i][j] != 0){

					i=rand()%t.tamanio;
						j=rand()%t.tamanio;
				}
				else{
                //se inserta y se sale del bucle
				parar=true;
				gen = rand()%2;//se busca un numero aleatorio si es par sale 2 si es impar sale 4

				if(gen%2 == 0){
					t.m[i][j]=2;
				}
				else{
					t.m[i][j]=4;
				}

				}
			}
		}





int quetamanio(tablero t){
	return t.tamanio;
}

bool vacia(tablero t, int fila, int col){
	bool vacio=false;
	if(t.m[fila][col]==0){
		vacio=true;
	}
	return vacio;
}

int obtenerValor(tablero t,int fila,int col){
	int valor;
	valor=t.m[fila][col];
	return valor;
}



void desplazarIzd(tablero &t,long long int &puntuacion){
    puntuacion=0;
	int i;
	for(i=0;i<t.tamanio;i++){//engloba todas las filas correnpondientes del tablero en un bucle
		desplazar_fila_Izd(t,i);//las desplaza a la izquierda
		puntuacion = puntuacion + sumar_Izd(t,i);//suma los valores continuos , devuelve la puntuacion y se mete en el acumulador puntuacion
		desplazar_fila_Izd(t,i);//vuelve a desplazar esa suma

	}
}




void desplazar_fila_Izd(tablero &t,int fila){
	//los modulos de desplazamieto se encargan de coger una casilla y compararla con sus siguientes, si la siguiente es cero se busca la
	//sucesora, y si no lo es otorga el valor de la segunda casilla a la primera y la segunda se pone a 0//
	int j;
	int k=0;
	bool parar = false;

	for(j=0;j<t.tamanio;j++){//en el caso de que la primera casilla no sea 0 simplemente se pasa a la siguiente j++
		parar=false;

		if(t.m[fila][j]==0){
			k=j+1;//las siguientes a j siempre van a ser >j
				while(k<t.tamanio && !parar){
					if(t.m[fila][k]==0)//si la casilla a comparar es 0 se compara con la siguiente
						k++;

					else{//si no es cero se copia elvalor y se borra, además de que para el bucle de comparación
						t.m[fila][j]=t.m[fila][k]; //se copia
						t.m[fila][k]=0;//se borra
						parar=true;//detiene el bucle de comparar

				}

			}
		}
	}
}

long long int sumar_Izd(tablero &t,int fila){
	long long int puntuacion = 0;
	bool parar = false;
	int j = 0;
    //El módulo sumar_izd coje una casilla y la compara con su casilla inmediatamente a la derecha
	while(j<t.tamanio-1 && !parar){
		if(t.m[fila][j]==0)
			parar=true;//si una sola casilla comprobada es 0 es que el resto de casillas son 0 puesto que ya esta desplazado previamente
		else{
			if(t.m[fila][j]==t.m[fila][j+1]){//si la anterior es igual a la siguiente se multiplica por 2 el contenido de la primera
				//y la segunda se pone a 0, para seguir avanzando como nos interesa sumamos +2 al indice j del bucle
				t.m[fila][j]=t.m[fila][j]*2;
				puntuacion=puntuacion+t.m[fila][j];//el entero puntuación es un acumulador que va guardando los puntos resultantes de la suma
				t.m[fila][j+1]=0;

				j=j+2;

			}
			else{//si no es ni 0 ni es igual a la siguiente el bucle avanza
				j=j+1;
			}

		}
	}
	return puntuacion;//al final se devuelve la puntuación resultante de la fila
}


//La explicacion de este módulo es practicamente igual a la del módulo desplazarIzda , pero desplazando y sumando a la izquierda
void desplazarDcha(tablero &t,long long int &puntuacion){
	 int i;
	 puntuacion=0;
	//este bucle se encarga de las filas no las columnas
		for(i=0;i<t.tamanio;i++){
			desplazar_fila_Dcha(t,i);
			puntuacion =puntuacion + sumar_Dcha(t,i);
			desplazar_fila_Dcha(t,i);
		}
	}


void desplazar_fila_Dcha(tablero &t,int fila){
	int j;
	int k=t.tamanio-1;
	bool parar =false;

	for(j=t.tamanio-1;j>=0;j--){
			parar=false;

		if(t.m[fila][j]==0){
			k=j-1;
				while(k>=0 && !parar){
					if(t.m[fila][k]==0)
						k--;

					else{
						t.m[fila][j]=t.m[fila][k];
						t.m[fila][k]=0;
						parar=true;
					}

				}
		}
	}
	}

long long int sumar_Dcha(tablero &t,int fila){
	long long int puntuacion = 0;
	bool parar = false;
	int j = t.tamanio-1;

	while(j>0 && !parar){
		if(t.m[fila][j]==0)
			parar=true;
		else{
			if(t.m[fila][j]==t.m[fila][j-1]){
				//se suma
				t.m[fila][j]=t.m[fila][j]*2;
				puntuacion= puntuacion + t.m[fila][j];
				t.m[fila][j-1]=0;
				j=j-2;

			}
			else{
				j=j-1;
			}

		}
	}
	return puntuacion;
}





void desplazarUp(tablero &t,long long int &puntuacion){
	int i;
	puntuacion = 0;
	//este bucle se encarga de las columnas, no las filas
		for(i=0;i<t.tamanio;i++){
			desplazar_col_Up(t,i);
			puntuacion = puntuacion + sumar_Up(t,i);
			desplazar_col_Up(t,i);
		}
	}


void desplazar_col_Up(tablero &t,int col){

	int j;
	int k=0;
	bool parar = false;

	for(j=0;j<t.tamanio;j++){
		parar=false;

		if(t.m[j][col]==0){
			k=j+1;
				while(k<t.tamanio && !parar){
					if(t.m[k][col]==0)
						k++;

					else{
						t.m[j][col]=t.m[k][col];
						t.m[k][col]=0;
						parar=true;

				}

			}
		}
	}
}

long long int sumar_Up(tablero &t,int col){
	long long int puntuacion = 0;
	bool parar = false;
	int j = 0;

	while(j<t.tamanio-1 && !parar){
		if(t.m[j][col]==0)
			parar=true;
		else{
			if(t.m[j][col]==t.m[j+1][col]){
				t.m[j][col]=t.m[j][col]*2;
				puntuacion=puntuacion+t.m[j][col];
				t.m[j+1][col]=0;
				j=j+2;

			}
			else{
				j=j+1;
			}

		}
	}
	return puntuacion;
}





void desplazarDown(tablero &t,long long int &puntuacion){
	int i;
	puntuacion=0;

		for(i=0;i<t.tamanio;i++){
			desplazar_col_Down(t,i);
			puntuacion = puntuacion + sumar_Down(t,i);
			desplazar_col_Down(t,i);
		}
	}

void desplazar_col_Down(tablero &t,int col){
	int j;
	int k=t.tamanio-1;
	bool parar =false;

	for(j=t.tamanio-1;j>=0;j--){
			parar=false;

		if(t.m[j][col]==0){
			k=j-1;
				while(k>=0 && !parar){
					if(t.m[k][col]==0)
						k--;

					else{
						t.m[j][col]=t.m[k][col];
						t.m[k][col]=0;
						parar=true;
					}

				}
		}
	}
	}

long long int sumar_Down(tablero &t,int col){
	long long int puntuacion = 0;
	bool parar = false;
	int j = t.tamanio-1;

	while(j>0 && !parar){
		if(t.m[j][col]==0)
			parar=true;
		else{
			if(t.m[j][col]==t.m[j-1][col]){
				//se suma
				t.m[j][col]=t.m[j][col]*2;
				puntuacion= puntuacion + t.m[j][col];
				t.m[j-1][col]=0;
				j=j-2;

			}
			else{
				j=j-1;
			}

		}
	}
	return puntuacion;
}
