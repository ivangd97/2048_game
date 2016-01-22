#include <iostream>
#include "entorno.h"
#include "Juego.h"
#include <cstdlib>
#include "Tablero.h"
#include "pruebasEntorno.h"

void pintarTablero(tablero t){
	int i,j;
	for(i=0;i<quetamanio(t);i++){
		for(j=0;j<quetamanio(t);j++){
			if(vacia(t,i,j)==true){
				entornoEliminarCasilla(i,j);
			}
			else{
				entornoPonerNumero(i,j,obtenerValor(t,i,j));
			}

		}
	}

}

void juego_2048(){


    //Se declaran y se inicializan las variables

	TipoTecla tecla= TNada;
	bool salir=false;//booleano que utililizaremos para salir del juego
	tablero tab;//declaramos un struct tablero
	int tamanioTablero;//creamos una variable que utilizaremos para el tamaño
	long long int puntuacion=0;//variable entero que utilizaremos para obtener la puntuaciónde un solo desplazamiento
	long long int puntuacionTotal = 0;//acumulador que utilizaremos para almacenar las sumas de los sucesivos desplazamientos
	int maxvalor;//entero que utilizaremos como meta en el juego
	int numiniciar ;//variable que utilizaremos para designar la cantidad de casillas iniciales en el tablero
	int y; //variable que no utilizaremos pues en esta version básica no son necesarias


	//cargamos la configuración del archivo uex2048.cnf
	entornoCargarConfiguracion ( tamanioTablero,maxvalor,numiniciar,y);


	srand (time(NULL));//generamos una semilla


	//Ahora inicializaremos nuestro tablero y nuestro entorno, para ello ponemos todas las casillas del tablero a 0
		//después inicializamos el entorno del tablero, generamos 2 números aleatorios entre 2 y 4 en cualquier casilla
		//y pintamos el tablero para mostrar los cambios en pantalla
	iniciar(tab,tamanioTablero);
		entornoIniciar(tamanioTablero);
		generar_inicial(tab,numiniciar);
		pintarTablero(tab);

		//Inicializamos los marcadores y dejamos el juego listo para empezar a jugar
		//entornoMostrarMensaje (Zona1, "¡ MUCHA SUERTE !");
		entornoPonerMarcadores( );
		entornoPonerMaximo(maxvalor);
		entornoPonerPuntuacion(0);



	while(!salir){

		tecla=entornoLeerTecla();

		switch(tecla){

		case TIzquierda:

			//-----------------------------------------------------------------------
				//EXPLICACIÓN DEL FUNCIONAMIENTO DEL JUEGO
			//-----------------------------------------------------------------------


			//En el caso de que desplacemos a la izquierda los números del tablero se moverán y sumarán hacia esta misma dirección
				//la puntuación resultante se almacenará junto con el acarreo que ya llevamos de esta en el acumulador puntuación total
			desplazarIzd(tab,puntuacion);
			puntuacionTotal = puntuacionTotal + puntuacion;//va almacenando la puntuacion total
			entornoPonerPuntuacion(puntuacionTotal);//mostramos la puntuación hasta el momento


			//se genera un 2 o un 4 en una casilla aleatoria vacia
			generar(tab);

			//se muestra el resultado del desplazamiento y el número generado por pantalla
			pintarTablero(tab);

			//en el caso de que hallamos llegado al valor meta o el tablero este lleno finalizará el programa
			if(puntuacionMax(tab,maxvalor)==true || EstaLleno(tab)==true)
					salir=true;

			break;
		case TArriba:
			//el  resto de casos es basicamente igual que el explicado arriba salvando la dirección
			desplazarUp(tab,puntuacion);
			puntuacionTotal = puntuacionTotal + puntuacion;
			entornoPonerPuntuacion(puntuacionTotal);

			generar(tab);
			pintarTablero(tab);

			if(puntuacionMax(tab,maxvalor)==true || EstaLleno(tab) ==true)
					salir=true;


			break;
		case TDerecha:
			desplazarDcha(tab,puntuacion);
			puntuacionTotal = puntuacionTotal + puntuacion;
			entornoPonerPuntuacion(puntuacionTotal);


			generar(tab);
			pintarTablero(tab);

			if(puntuacionMax(tab,maxvalor)==true || EstaLleno(tab) ==true)
					salir=true;



			break;
		case TAbajo:
			desplazarDown(tab,puntuacion);
			puntuacionTotal = puntuacionTotal + puntuacion;
			entornoPonerPuntuacion(puntuacionTotal);


			generar(tab);
			pintarTablero(tab);

			if(puntuacionMax(tab,maxvalor)==true || EstaLleno(tab) ==true)
					salir=true;

				break;

		case TSalir:

			salir=true;
			break;
		default:
			break;
			//fin switch
		}
	}

	//Esperamos 2 msegundos para que el mensaje no sea muy repentino y resulte más agradable
	entornoPausa(200000);
	//entornoMostrarMensajeFin("Hasta Pronto");
	//Esperamos 3 msegundos para que de tiempo a leer esta simpatica despedida
	entornoPausa(300000);

}

