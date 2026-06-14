#include <stdlib.h>
#include <stdio.h>
#include "juego.h"

extern int validarMovimiento(char *mapa, int columnas, int fila, int col);
extern int detectarObjeto(char *mapa, int columnas, int fila, int col, char objeto);

void buscar_jugador(char mapa[FILAS_MAPA][COLUMNAS_MAPA], int *fila, int *col)
{
    for (int i = 0; i < FILAS_MAPA; i++) {
        for (int j = 0; j < COLUMNAS_MAPA; j++) {
            if (mapa[i][j] == 'P') {
                *fila = i;
                *col  = j;
                return;
            }
        }
    }
    *fila = 1;
    *col  = 1;
}

void imprimir_ventana(char mapa[FILAS_MAPA][COLUMNAS_MAPA], EstadoJuego *estado)
{
    system("cls");
    int cam_fila = estado->jugador_fila - VENTANA_FILS / 2;
    int cam_col  = estado->jugador_col  - VENTANA_COLS / 2;
    if (cam_fila < 0) cam_fila = 0;
    if (cam_col  < 0) cam_col  = 0;
    if (cam_fila > FILAS_MAPA    - VENTANA_FILS) cam_fila = FILAS_MAPA    - VENTANA_FILS;
    if (cam_col  > COLUMNAS_MAPA - VENTANA_COLS) cam_col  = COLUMNAS_MAPA - VENTANA_COLS;
    for (int i = 0; i < VENTANA_FILS; i++) {
        for (int j = 0; j < VENTANA_COLS; j++) {
            int mf = cam_fila + i;
            int mc = cam_col  + j;
            if (mf == estado->jugador_fila && mc == estado->jugador_col)
                printf("P");
            else
                printf("%c", mapa[mf][mc]);
        }
        printf("\n");
    }
    int total = (estado->nivel == 1) ? totalMonedasNivel1 :
                (estado->nivel == 2) ? totalMonedasNivel2 :
                                       totalMonedasNivel3;
    imprimir_stats(estado, total);
}

void imprimir_stats(EstadoJuego *estado, int total_monedas)
{
    printf("-----------------------------\n");
    printf("Nivel  : %d\n",  estado->nivel);
    printf("Monedas: %d / %d\n", estado->monedas, total_monedas);
    printf("Pasos  : %d\n",  estado->pasos);
    printf("Llave  : %s\n",  estado->llave ? "Si" : "No");
    printf("-----------------------------\n");
    printf("Movimiento: W A S D  |  Salir: Q\n");
}

int mover_jugador(char mapa[FILAS_MAPA][COLUMNAS_MAPA], EstadoJuego *estado, char tecla)
{
    int nuevaFila = estado->jugador_fila;
    int nuevaCol  = estado->jugador_col;
    switch(tecla)
    {
        case 'W': case 'w': nuevaFila--; break;
        case 'S': case 's': nuevaFila++; break;
        case 'A': case 'a': nuevaCol--;  break;
        case 'D': case 'd': nuevaCol++;  break;
        default: return 0;
    }
    if(!validarMovimiento(&mapa[0][0], COLUMNAS_MAPA, nuevaFila, nuevaCol))
        return 0;
    if(detectarObjeto(&mapa[0][0], COLUMNAS_MAPA, nuevaFila, nuevaCol, 'M'))
    {
        estado->monedas++;
        mapa[nuevaFila][nuevaCol] = '.';
    }
    else if(detectarObjeto(&mapa[0][0], COLUMNAS_MAPA, nuevaFila, nuevaCol, 'K'))
    {
        estado->llave = 1;
        mapa[nuevaFila][nuevaCol] = '.';
    }
    else if(detectarObjeto(&mapa[0][0], COLUMNAS_MAPA, nuevaFila, nuevaCol, 'D'))
    {
        if(estado->llave == 0) return 0;
        mapa[nuevaFila][nuevaCol] = '.';
    }
    else if(detectarObjeto(&mapa[0][0], COLUMNAS_MAPA, nuevaFila, nuevaCol, 'E'))
    {
        mapa[estado->jugador_fila][estado->jugador_col] = '.';
        estado->jugador_fila = nuevaFila;
        estado->jugador_col  = nuevaCol;
        estado->pasos++;
        return 1;
    }
    mapa[estado->jugador_fila][estado->jugador_col] = '.';
    estado->jugador_fila = nuevaFila;
    estado->jugador_col  = nuevaCol;
    estado->pasos++;
    
    return 0;
}