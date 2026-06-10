#ifndef JUEGO_H
#define JUEGO_H

#include "mapas.h"

#define VENTANA_FILS 20
#define VENTANA_COLS 20

typedef struct {
    int jugador_fila;
    int jugador_col;
    int monedas;
    int pasos;
    int llave;
    int nivel;
} EstadoJuego;

void imprimir_ventana(char mapa[FILAS_MAPA][COLUMNAS_MAPA], EstadoJuego *estado);
void imprimir_stats(EstadoJuego *estado, int total_monedas);
void buscar_jugador(char mapa[FILAS_MAPA][COLUMNAS_MAPA], int *fila, int *col);
void mover_jugador(
    char mapa[FILAS_MAPA][COLUMNAS_MAPA],
    EstadoJuego *estado,
    char tecla
);
#endif