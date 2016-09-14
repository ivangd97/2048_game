/*
 * pruebasTablero.cpp
 *
 *  Created on: Jan 7, 2016
 *      Author: ivangd97
 */

#include "pruebasTablero.h"
#include "Tablero.h"
#include "entorno.h"
#include "Juego.h"
#include <iostream>

const int TAMANIOTABLERO=4;

void pruebasIniciar(){
	tablero t;//Declaramos una variable tipo tablero la cual iniciar
	iniciar(t,TAMANIOTABLERO);
	//Iniciamos el tablero t con el tamaño deseado,para esta prueba será un número entero
	entornoIniciar(TAMANIOTABLERO);
	entornoPausa(2000000);
	//Mostramos el tablero iniciado en el entorno gráfico durante unos segundos
	cout<<"Se mostrará el tablero con todas las casillas vacias"<<endl;
}

void pruebasPuntuacionMax(){
	tablero t;//Iniciamos un tablero t para la prueba
	//Declaramos la variable que nos servirá de referencia como valor máximo en la prueba
	int maxPrueba=64;
	iniciar(t,TAMANIOTABLERO);
	entornoIniciar(TAMANIOTABLERO);//Mostramos el tablero en el entorno gráfico
	t.m[0][0]=64;//Le damos a una de las casillas el valor máximo
	pintarTablero(t);//Pintamos el tablero para mostrar los cambios
	entornoPausa(5000000);
	if(puntuacionMax(t,maxPrueba)==true){
		//Si el módulo funciona tal y como se espera se mostrará un mensaje
		cout<<"EL modulo finalizará al haber encontrado el valor máximo que es 64"<<endl;
		cout<<" "<<endl;
		cout<<"El módulo funciona correctamente"<<endl;
	}
	else{
		//En caso contrario se mostraría un mensaje de error
		cout<<"El módulo no funciona de manera correcta"<<endl;
	}
}

void pruebasEstaLleno(){
	tablero t;
	int i,j;
	//Iniciamos un tablero y lo mostramos en el entorno
	iniciar(t,TAMANIOTABLERO);
	entornoIniciar(TAMANIOTABLERO);
	//Ahora recorreremos la matriz del tablero asignandole valores a las casillas
	//y luego comprobaremos si el módulo que se encarga de ver si está lleno funciona
	for(i=0;i<TAMANIOTABLERO;i++){
		for(j=0;j<TAMANIOTABLERO;j++){
			t.m[i][j]=2;
		}
	}
	pintarTablero(t);//Pintamos el tablero para mostrar los cambios en pantalla
	entornoPausa(5000000);
	if(EstaLleno(t)==true){
		cout<<"El modulo detecta que todas las casillas estan llenas y finaliza el juego"<<endl;
		cout<<" "<<endl;
		cout<<"El módulo da el resultado esperado"<<endl;
	}
	else{
		cout<<"Error en el módulo para comprobar si está lleno"<<endl;
	}

}

void pruebasGenerar_inicial(){
	tablero t;//Iniciamos un tablero t
	int numiniciar=2;

	iniciar(t,TAMANIOTABLERO);
	entornoIniciar(TAMANIOTABLERO);
	generar_inicial(t,numiniciar);//Generamos dos valores iniciales en un lugar aleatorio del tablero
	pintarTablero(t);//Mostramos los cambios en pantalla durante unos segundos
	entornoPausa(5000000);
	//Se podrá comprobar que el módulo es correcto de manera visual si se generan 2 valores
	//en algún lugar del tablero que sea 2 ó 4
	cout<<"Se generarán 2 números (2 o 4)aleatorios en cualquier casilla del tablero"<<endl;
}

void pruebasGenerar(){
	//La prueba de este módulo es similar a la del anterior
	tablero t;//Iniciamos un tablero t
	iniciar(t,TAMANIOTABLERO);
	entornoIniciar(TAMANIOTABLERO);
	generar(t);//Generamos un valor en el tablero
	pintarTablero(t);//Mostramos los cambios en pantalla durante unos segundos
	entornoPausa(5000000);
	cout<<"Se genrará 1 numero aleatorio (2 o 4) en una casilla aleatoria vacia del tablero"<<endl;
}

void pruebasQueTamanio(){
	//La prueba de este módulo es muy simple,iniciaremos un tablero de tamaño TAMANIOTABLERO
	//posteriormente haremos una llamada al módulo y esperaremos que devuelva el valor de la
	//constante TAMANIOTABLERO
	tablero t;
	iniciar(t,TAMANIOTABLERO);
	if(quetamanio(t)==TAMANIOTABLERO){
		//Mostraremos un mensaje en la consola con el resultado de la comprobación
		cout<<"El tamaño del tablero es: "<<TAMANIOTABLERO <<endl;
		cout<<""<<endl;
		cout<<"El módulo funciona como se espera"<<endl;
	}
	else{
		cout<<"Error en el módulo que comprueba el tamaño del tablero"<<endl;
	}

}

void pruebasVacia(){
	tablero t;
	iniciar(t,TAMANIOTABLERO);
	//Ahora vamos a asignarle un valor cualquiera a una casilla del tablero
	t.m[2][2]=4;
	//Para hacer la comprobación del módulo esperaremos que el resultado dado sea false al
	//checkear la casilla
	if(vacia(t,2,2)==false){
		cout<<"El módulo funciona de manera correcta"<<endl;
	}
	else{
		cout<<"El módulo para comprobar si la casilla está vacía no funciona"<<endl;
	}
}

void pruebasObtenerValor(){
	tablero t;
	iniciar(t,TAMANIOTABLERO);
	//Damos un valor a cualquier casilla
	t.m[0][0]=5;
	if(obtenerValor(t,0,0)==5){
		//Comprobamos si el módulo devuelve el valor que hemos asignado a la casilla
		cout<<"Asignamos el valor 5 a la casilla (0,0)"<<endl;
		cout<<"El valor obtenido de la casilla (0,0) es: "<<obtenerValor(t,0,0)<<endl;
		cout<<"EL módulo es correcto"<<endl;
	}
	else{
		cout<<"Error en el módulo de obtener valor"<<endl;
	}
}

void pruebasDesplazarIzd(){
	tablero t;
	long long int puntuacion=0;
	iniciar(t,TAMANIOTABLERO);
	entornoIniciar(TAMANIOTABLERO);
	//generamos unos valores iniciales en cualquier casilla
	t.m[1][1]=2;
	t.m[1][2]=2;
	pintarTablero(t);//mostramos los cambios en la pantalla
	entornoPausa(2000000);
	desplazarIzd(t,puntuacion);//Accedemos al módulo
	pintarTablero(t);
	entornoPausa(2000000);
	if(t.m[1][0]==4){
		//Como sabemos que si el módulo funcionase debería desplazar y sumar los numeros
		//que hemos puesto,comprobamos que la casilla en la que teóricamente queda el resultado
		//tiene el valor esperado
		cout<<"Veremos como los valores se desplazan a la izquierda"<<endl;

		cout<<"El modulo funciona"<<endl;
	}
	else{
		cout<<"Fallo en el módulo de desplazar izquierda"<<endl;
	}
}

//Haremos las pruebas de los 4 posibles movimientos solamente cambiando la casilla que se comprueba
//y las dos casillas que se rellenan

void pruebasDesplazarDcha(){
	tablero t;
	long long int puntuacion=0;
	iniciar(t,TAMANIOTABLERO);
	entornoIniciar(TAMANIOTABLERO);
	//generamos unos valores iniciales en cualquier casilla
	t.m[1][1]=2;
	t.m[1][2]=2;
	pintarTablero(t);//mostramos los cambios en la pantalla
	entornoPausa(2000000);
	desplazarDcha(t,puntuacion);//Accedemos al módulo
	pintarTablero(t);
	entornoPausa(2000000);
	if(t.m[1][TAMANIOTABLERO-1]==4){
		//Como sabemos que si el módulo funcionase debería desplazar y sumar los numeros
		//que hemos puesto,comprobamos que la casilla en la que teóricamente queda el resultado
		//tiene el valor esperado
		cout<<"Veremos como los valores se desplazan a la derecha"<<endl;
		cout<<"El modulo funciona"<<endl;
	}
	else{
		cout<<"Fallo en el módulo de desplazar a la derecha"<<endl;
	}
}

void pruebasDesplazarUp(){
	tablero t;
	long long int puntuacion=0;
	iniciar(t,TAMANIOTABLERO);
	entornoIniciar(TAMANIOTABLERO);
	//generamos unos valores iniciales en cualquier casilla
	t.m[2][2]=2;
	t.m[1][2]=2;
	pintarTablero(t);//mostramos los cambios en la pantalla
	entornoPausa(2000000);
	desplazarUp(t,puntuacion);//Accedemos al módulo
	pintarTablero(t);
	entornoPausa(2000000);
	if(t.m[0][2]==4){
		//Como sabemos que si el módulo funcionase debería desplazar y sumar los numeros
		//que hemos puesto,comprobamos que la casilla en la que teóricamente queda el resultado
		//tiene el valor esperado
		cout<<"Veremos como los valores se desplazan hacia arriba"<<endl;
		cout<<"El modulo funciona"<<endl;
	}
	else{
		cout<<"Fallo en el módulo de desplazar hacia arriba"<<endl;
	}
}

void pruebasDesplazarDown(){
	tablero t;
	long long int puntuacion=0;
	iniciar(t,TAMANIOTABLERO);
	entornoIniciar(TAMANIOTABLERO);
	//generamos unos valores iniciales en cualquier casilla
	t.m[2][2]=2;
	t.m[1][2]=2;
	pintarTablero(t);//mostramos los cambios en la pantalla
	entornoPausa(2000000);
	desplazarDown(t,puntuacion);//Accedemos al módulo
	pintarTablero(t);
	entornoPausa(2000000);
	if(t.m[TAMANIOTABLERO-1][2]==4){
		//Como sabemos que si el módulo funcionase debería desplazar y sumar los numeros
		//que hemos puesto,comprobamos que la casilla en la que teóricamente queda el resultado
		//tiene el valor esperado
		cout<<"Veremos como los valores se desplazan hacia abajo"<<endl;
		cout<<"El modulo funciona"<<endl;
	}
	else{
		cout<<"Fallo en el módulo de desplazar hacia abajo"<<endl;
	}
}

/*
 * Los módulos de desplazar filas/columnas y sumarlas quedan comprobados con la implementación
 * del módulo que los relaciona
 */
