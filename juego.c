#include "juego.h"
/*
 * mover_jugador
 * Procesa una tecla WASD y actualiza el estado del juego.
 * Retorna 1 si el jugador llego a la salida (E), 0 en cualquier otro caso.
 */
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
    if(nuevaFila < 0 || nuevaFila >= FILAS_MAPA)  return 0;
    if(nuevaCol  < 0 || nuevaCol  >= COLUMNAS_MAPA) return 0;
    char celdaDestino = mapa[nuevaFila][nuevaCol];
    if(celdaDestino == '#')
        return 0;
    if(celdaDestino == 'D' && estado->llave == 0)
        return 0;
    if(celdaDestino == 'M')
    {
        estado->monedas++;
        mapa[nuevaFila][nuevaCol] = '.';
    }
    else if(celdaDestino == 'K')
    {
        estado->llave = 1;
        mapa[nuevaFila][nuevaCol] = '.';
    }
    else if(celdaDestino == 'D')
    {
        mapa[nuevaFila][nuevaCol] = '.';
    }
    else if(celdaDestino == 'E')
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