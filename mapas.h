#ifndef MAPAS_H
#define MAPAS_H

#define FILAS_MAPA 60
#define COLUMNAS_MAPA 60

extern char nivel1[FILAS_MAPA][COLUMNAS_MAPA];
extern char nivel2[FILAS_MAPA][COLUMNAS_MAPA];
extern char nivel3[FILAS_MAPA][COLUMNAS_MAPA];

extern int filaInicioNivel1;
extern int columnaInicioNivel1;

extern int filaInicioNivel2;
extern int columnaInicioNivel2;

extern int filaInicioNivel3;
extern int columnaInicioNivel3;

extern int totalMonedasNivel1;
extern int totalMonedasNivel2;
extern int totalMonedasNivel3;

void cargarNivel1();
void cargarNivel2();
void cargarNivel3();

#endif