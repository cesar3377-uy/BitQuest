#include <stdio.h>
#include "juego.h"
#include "mapas.h"
#include <conio.h>

void mostrarMenu();
void iniciarJuego();
void jugarNivel(int numeroNivel);
void mostrarResumenNivel(int nivel, int monedas, int pasos);

int main()
{
    mostrarMenu();
    iniciarJuego();

    return 0;
}

void mostrarMenu()
{
    printf("_____________________________________\n");
    printf("           BITQUEST\n");
    printf("_____________________________________\n");
    printf("Recolecta monedas, consigue la llave\n");
    printf("abre la puerta y fuga\n");
    printf("_____________________________________\n");
}

void iniciarJuego()
{
    jugarNivel(1);
    jugarNivel(2);
    jugarNivel(3);

    printf("\nJuego terminado\n");
}

void jugarNivel(int numeroNivel)
{
    EstadoJuego estado;

    estado.monedas = 0;
    estado.pasos   = 0;
    estado.llave   = 0;
    estado.nivel   = numeroNivel;

    char (*mapa_actual)[COLUMNAS_MAPA];

    switch(numeroNivel)
    {
        case 1:
            cargarNivel1();
            mapa_actual = nivel1;
            break;

        case 2:
            cargarNivel2();
            mapa_actual = nivel2;
            break;

        case 3:
            cargarNivel3();
            mapa_actual = nivel3;
            break;

        default:
            return;
    }

    buscar_jugador(
        mapa_actual,
        &estado.jugador_fila,
        &estado.jugador_col
    );

    char tecla;
    int nivel_terminado = 0;

    while(!nivel_terminado)
    {
        imprimir_ventana(
            mapa_actual,
            &estado
        );

        tecla = _getch();

        if(tecla=='q' || tecla=='Q')
            break;

        nivel_terminado =
            mover_jugador(
                mapa_actual,
                &estado,
                tecla
            );
    }

    mostrarResumenNivel(
        estado.nivel,
        estado.monedas,
        estado.pasos
    );
}

void mostrarResumenNivel(int nivel, int monedas, int pasos)
{
    printf("\n");
    printf("_____________________________________\n");
    printf("         NIVEL COMPLETAO\n");
    printf("______________________________________\n");
    printf("Nivel: %d\n", nivel);
    printf("Monedas recolectadas: %d\n", monedas);
    printf("Pasos realizados: %d\n", pasos);
    printf("_______________________________________\n");
}
