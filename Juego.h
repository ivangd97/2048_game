#ifndef JUEGO_H_
#define JUEGO_H_
#include "Tablero.h"

//PRE:Se espera como entrada un tipo tablero
//POST:Se muestra en el entorno gráfico los cambios visuales
//La complejidad del módulo pintar tablero es de O(n²)
void pintarTablero(tablero t);

//PRE:
//POST:Permite la inicialización del juego 2048

void juego_2048();

#endif
