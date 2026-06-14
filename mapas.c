//Hice este archivo nomas pa poner unas funciones que faltaron en juegos.c
#include "mapas.h"

char nivel1[FILAS_MAPA][COLUMNAS_MAPA];
char nivel2[FILAS_MAPA][COLUMNAS_MAPA];
char nivel3[FILAS_MAPA][COLUMNAS_MAPA];

int filaInicioNivel1 = 1;
int columnaInicioNivel1 = 1;

int filaInicioNivel2 = 1;
int columnaInicioNivel2 = 1;

int filaInicioNivel3 = 1;
int columnaInicioNivel3 = 1;

int totalMonedasNivel1 = 0;
int totalMonedasNivel2 = 0;
int totalMonedasNivel3 = 0;

void cargarNivel1()
{
    int i,j;

    for(i=0;i<FILAS_MAPA;i++)
    {
        for(j=0;j<COLUMNAS_MAPA;j++)
        {
            nivel1[i][j]='.';
        }
    }

    for(i=0;i<FILAS_MAPA;i++)
    {
        nivel1[i][0]='#';
        nivel1[i][COLUMNAS_MAPA-1]='#';
    }

    for(j=0;j<COLUMNAS_MAPA;j++)
    {
        nivel1[0][j]='#';
        nivel1[FILAS_MAPA-1][j]='#';
    }

    nivel1[1][1]='P';

    nivel1[5][5]='M';
    nivel1[10][10]='M';
    nivel1[15][15]='M';

    nivel1[20][20]='K';

    nivel1[25][25]='D';

    nivel1[50][50]='E';

    totalMonedasNivel1 = 3;
}

void cargarNivel2()
{
    int i,j;

    for(i=0;i<FILAS_MAPA;i++)
    {
        for(j=0;j<COLUMNAS_MAPA;j++)
        {
            nivel2[i][j]='.';
        }
    }

    for(i=0;i<FILAS_MAPA;i++)
    {
        nivel2[i][0]='#';
        nivel2[i][COLUMNAS_MAPA-1]='#';
    }

    for(j=0;j<COLUMNAS_MAPA;j++)
    {
        nivel2[0][j]='#';
        nivel2[FILAS_MAPA-1][j]='#';
    }

    nivel2[1][1]='P';

    nivel2[8][8]='M';
    nivel2[16][16]='M';
    nivel2[24][24]='M';
    nivel2[32][32]='M';

    nivel2[40][20]='K';

    nivel2[45][30]='D';

    nivel2[55][55]='E';

    totalMonedasNivel2 = 4;
}

void cargarNivel3()
{
    int i,j;

    for(i=0;i<FILAS_MAPA;i++)
    {
        for(j=0;j<COLUMNAS_MAPA;j++)
        {
            nivel3[i][j]='.';
        }
    }

    for(i=0;i<FILAS_MAPA;i++)
    {
        nivel3[i][0]='#';
        nivel3[i][COLUMNAS_MAPA-1]='#';
    }

    for(j=0;j<COLUMNAS_MAPA;j++)
    {
        nivel3[0][j]='#';
        nivel3[FILAS_MAPA-1][j]='#';
    }

    nivel3[1][1]='P';

    nivel3[10][10]='M';
    nivel3[20][20]='M';
    nivel3[30][30]='M';
    nivel3[40][40]='M';
    nivel3[50][20]='M';

    nivel3[35][10]='K';

    nivel3[45][15]='D';

    nivel3[58][58]='E';

    totalMonedasNivel3 = 5;
}

