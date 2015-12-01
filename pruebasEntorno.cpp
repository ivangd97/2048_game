#include "pruebasEntorno.h"
#include "entorno.h"

void pruebaEntornoIniciar(){
	entornoIniciar(4);
	entornoPausa(1000000);
}

void pruebaPonerNumero(){
	entornoIniciar(4);
	entornoPausa(1000000);
	entornoPonerNumero(1,2,2);
	entornoPonerNumero(3,3,4);
	entornoPausa(1000000);
}

void pruebaEliminarCasilla(){
	int i,j;
	entornoIniciar(4);
	for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				entornoPonerNumero(i,j,1);
			}
	}
	entornoPausa(1000000);
	entornoEliminarCasilla(1,2);
	entornoEliminarCasilla(3,3);
	entornoPausa(1000000);
}

void pruebaMostrarMensaje(){
	entornoIniciar(4);
	entornoMostrarMensaje(Zona2,"Prueba mensaje");
	entornoPausa(1000000);
}

void pruebaMostrarMensajeFin(){
	entornoIniciar(4);
	entornoMostrarMensaje(Zona2,"Prueba mensaje");
	entornoPausa(1000000);
	entornoMostrarMensajeFin("Fin de la prueba");
	entornoPausa(500000);
}

void pruebaPonerMarcadores(){
	entornoIniciar(4);
	entornoPonerMarcadores();
	entornoPausa(1000000);
}

void pruebaPonerMaximo(){
	entornoIniciar(4);
	entornoPonerMaximo(2048);
	entornoPausa(1000000);
}

void pruebaPonerPuntuacion(){
	entornoIniciar(4);
	entornoPonerPuntuacion(100);
	entornoPausa(1000000);
}

void pruebaEntornoPausa(){
	int i,j;
	entornoIniciar(4);
	for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				entornoPausa(1000000);
				entornoPonerNumero(i,j,1);
			}
	}
	entornoPausa(1000000);
}

void pruebaTipoTecla(){
	entornoIniciar(4);
	entornoLeerTecla();
	entornoMostrarMensajeFin("Fin de la prueba");
}
