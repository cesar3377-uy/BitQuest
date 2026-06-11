#include <stdio.h>
#include "juego.h"
#include "mapas.h"

void mostrarMenu();
void iniciarJuego();

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
    printf("\nIniciando juego...\n");
}