
#include <iostream>
#include "entorno.h"

using namespace std;

void pruebas_basicas() {
	int tamano, maxValor, numInicial, prob2; // variables para almacenar la información obtenida a partir del fichero de configuración
	int i, j;  //índices para recorrer la rejilla
	int puntuacion, valor;    //variables auxiliares

	//cargamos la información del fichero de configuración en las variables locales
	//tamano, maxValor, numInicial y prob2, aunque las dos últimas no se utilizarán en este programa
	if (entornoCargarConfiguracion(tamano, maxValor, numInicial, prob2)) {
		entornoIniciar(tamano); //se inicia el modo gráfico y se dibuja la rejilla
		entornoPonerMarcadores(); //se muestra la casilla donde apareceran los marcadores del juego (valor máximo y puntuación)
		entornoPonerMaximo(maxValor); //se muestra el marcador: valor máximo
		valor = 1;
		puntuacion = 0;

		// se recorren las celdas de la rejilla colocando diferentes valores numéricos
		for (i = 0; i < tamano; i++)
			for (j = 0; j < tamano; j++) {
				entornoPonerNumero(i, j, valor); //se muestra un número en una posición de la rejilla
				puntuacion = puntuacion + valor;
				entornoPonerPuntuacion(puntuacion);   //se muestra el marcador: puntuación
				if (valor < 2048)
					valor = valor * 2;
				entornoPausa(500000);
			}

		// se recorren y borran las celdas de la rejilla
		for (i = tamano - 1; i >= 0; i--)
			for (j = tamano - 1; j >= 0; j--) {
				entornoEliminarCasilla(i, j);
				entornoPausa(500000);
			}
		entornoLeerTecla();

	} else
		cout << "Error al cargar la configuración del juego";

}

int main(){
	pruebas_basicas();

	return 0;
}
