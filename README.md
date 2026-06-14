# BitQuest
Proyecto final de Lenguaje Ensamblador

Integrantes
- César Emmanuel Hernández Aguilera
- Emiliano Rios Muñoz 
- Ketzary Mirely Miguel Esquivel
- Jorge Luis Flores Gomez

## Descripción

BitQuest es un videojuego de exploración desarrollado en lenguaje C y ensamblador x86-64.

El jugador debe recorrer distintos niveles, recolectar monedas, encontrar una llave, abrir una puerta y llegar a la salida para completar cada nivel.

El proyecto fue desarrollado como práctica de integración entre programación en C, programación en ensamblador, Git y GitHub.

---

## Características

- 3 niveles de juego.
- Mapas de 60x60 celdas.
- Sistema de monedas.
- Sistema de llave y puerta.
- Movimiento mediante teclado.
- Ventana de visualización dinámica.
- Integración de rutinas en ensamblador NASM.
- Uso de Git y GitHub para trabajo colaborativo.

---

## Controles

| Tecla | Acción |
|---------|---------|
| W | Mover arriba |
| A | Mover izquierda |
| S | Mover abajo |
| D | Mover derecha |
| Q | Salir del nivel |

---

## Elementos del mapa

| Símbolo | Significado |
|----------|-------------|
| P | Jugador |
| M | Moneda |
| K | Llave |
| D | Puerta |
| E | Salida |
| # | Muro |
| . | Espacio libre |

---

## Archivos del proyecto

- main.c → Lógica principal del juego.
- juego.c → Mecánicas de juego y visualización.
- juego.h → Definiciones y estructuras.
- mapas.c → Generación de niveles.
- mapas.h → Declaraciones de mapas.
- rutinas.asm → Funciones implementadas en ensamblador.
- build.bat → Script de compilación automática.

---

## Rutinas en ensamblador

Las siguientes funciones fueron implementadas en NASM:

- contarCaracteres
- validarMovimiento
- calcularPuntaje
- detectarObjeto
- CeldasLibres

---

## Compilación manual

Compilar archivos C:

```bash
gcc -c main.c
gcc -c juego.c
gcc -c mapas.c
