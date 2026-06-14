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