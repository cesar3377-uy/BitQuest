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

    for(i=5;i<25;i++)
    {
        nivel1[10][i]='#';
    }

    for(i=15;i<35;i++)
    {
        nivel1[20][i]='#';
    }

    nivel1[5][5]='M';
    nivel1[10][30]='M';
    nivel1[25][10]='M';

    nivel1[30][30]='K';

    nivel1[40][40]='D';

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

    for(i=5;i<50;i++)
    {
        nivel2[8][i]='#';
    }

    for(i=10;i<55;i++)
    {
        nivel2[20][i]='#';
    }

    for(i=5;i<40;i++)
    {
        nivel2[i][25]='#';
    }

    nivel2[8][20]='.';
    nivel2[20][40]='.';
    nivel2[30][25]='.';

    nivel2[5][50]='M';
    nivel2[15][10]='M';
    nivel2[30][45]='M';
    nivel2[45][15]='M';

    nivel2[50][50]='K';

    nivel2[40][40]='D';

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

    for(i=2;i<58;i++)
    {
        nivel3[5][i]='#';
        nivel3[15][i]='#';
        nivel3[25][i]='#';
        nivel3[35][i]='#';
        nivel3[45][i]='#';
    }

    nivel3[5][10]='.';
    nivel3[15][20]='.';
    nivel3[25][30]='.';
    nivel3[35][40]='.';
    nivel3[45][50]='.';

    for(i=5;i<50;i++)
    {
        nivel3[i][12]='#';
        nivel3[i][24]='#';
        nivel3[i][36]='#';
        nivel3[i][48]='#';
    }

    nivel3[10][12]='.';
    nivel3[20][24]='.';
    nivel3[30][36]='.';
    nivel3[40][48]='.';

    nivel3[8][8]='M';
    nivel3[18][18]='M';
    nivel3[28][28]='M';
    nivel3[38][38]='M';
    nivel3[48][48]='M';

    nivel3[52][10]='K';

    nivel3[54][40]='D';

    nivel3[58][58]='E';

    totalMonedasNivel3 = 5;
}

