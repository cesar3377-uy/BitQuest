#include <stdio.h>
#include "juego.h"
#include "mapas.h"

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
    printf("\nCargando nivel %d...\n", numeroNivel);
}

void mostrarResumenNivel(int nivel, int monedas, int pasos)
{
    printf("\n");
    printf("=====================================\n");
    printf("         NIVEL COMPLETADO\n");
    printf("=====================================\n");
    printf("Nivel: %d\n", nivel);
    printf("Monedas recolectadas: %d\n", monedas);
    printf("Pasos realizados: %d\n", pasos);
    printf("=====================================\n");
}
