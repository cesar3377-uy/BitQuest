#include <stdio.h>
#include "juego.h"
/*
 * mover_jugador
 * Procesa una tecla WASD y actualiza el estado del juego.
 * Retorna 1 si el jugador llego a la salida (E), 0 en cualquier otro caso.
 */
extern int validarMovimiento(char *mapa, int columnas, int fila, int col);
extern int detectarObjeto(char *mapa, int columnas, int fila, int col, char objeto);

int mover_jugador(
    char mapa[FILAS_MAPA][COLUMNAS_MAPA],
    EstadoJuego *estado,
    char tecla
)
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
void imprimir_ventana(char mapa[FILAS_MAPA][COLUMNAS_MAPA], EstadoJuego *estado)
{
    int inicioFila = estado->jugador_fila - VENTANA_FILS / 2;
    int inicioCol  = estado->jugador_col - VENTANA_COLS / 2;

    if(inicioFila < 0) inicioFila = 0;
    if(inicioCol < 0) inicioCol = 0;
    if(inicioFila + VENTANA_FILS > FILAS_MAPA) inicioFila = FILAS_MAPA - VENTANA_FILS;
    if(inicioCol + VENTANA_COLS > COLUMNAS_MAPA) inicioCol = COLUMNAS_MAPA - VENTANA_COLS;

    for(int i = 0; i < VENTANA_FILS; i++)
    {
        for(int j = 0; j < VENTANA_COLS; j++)
        {
            int filaMapa = inicioFila + i;
            int colMapa  = inicioCol + j;

            if(filaMapa == estado->jugador_fila && colMapa == estado->jugador_col)
                printf("P");
            else
                printf("%c", mapa[filaMapa][colMapa]);
        }
        printf("\n");
    }
}

void imprimir_stats(EstadoJuego *estado, int total_monedas)
{
    printf("Nivel: %d\n", estado->nivel);
    printf("Monedas: %d / %d\n", estado->monedas, total_monedas);
    printf("Pasos: %d\n", estado->pasos);
    printf("Llave: %s\n", estado->llave ? "Sí" : "No");
}

void buscar_jugador(char mapa[FILAS_MAPA][COLUMNAS_MAPA], int *fila, int *col)
{
    for(int i = 0; i < FILAS_MAPA; i++)
    {
        for(int j = 0; j < COLUMNAS_MAPA; j++)
        {
            if(mapa[i][j] == 'P')
            {
                *fila = i;
                *col  = j;
                return;
            }
        }
    }
}