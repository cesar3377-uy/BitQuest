; Rutinas Jorgee

section .text
global contarCaracteres
global validarMovimiento
global calcularPuntaje
global detectarObjeto
global CeldasLibres

; int contarCaracteres
; RCX= direccion inicial del mapa
; RDX= total de celdas
; R8= caracter a contar
contarCaracteres:
    xor rax, rax ; contador de caracteres
    xor r10, r10   ; índice del bucle
    mov r11b, r8b   ; caracter a contar

.ciclo_contar:
    cmp r10, rdx
    jge .fin_contar
    mov bl, [rcx + r10]
    cmp bl, r11b
    jne .siguiente_contar
    inc rax
.siguiente_contar:
    inc r10
    jmp .ciclo_contar

.fin_contar:
    ret

; int validarMovimiento
; RCX= direccion inicial del mapa
; RDX= numero de columnas del mapa
; R8= fila 
; R9= columna
; Devuelve 1 si el movimiento es válido, 0 si no lo es
; Un movimiento es válido si la celda a la que se quiere mover no es un muro ('#') y está dentro de los límites del mapa
validarMovimiento:
    mov r10, r8   ; fila
    imul r10, rdx   ; fila*colum
    add r10, r9   ; fila*columnas + columna

    mov al, [rcx + r10] ; obtener el caracter de la celda
    cmp al, '#' ; comparar con el caracter de muro
    je .bloqueado

    mov rax, 1 ; movimiento válido
    ret
.bloqueado:
    xor rax, rax ; movimiento no válido
    ret

; int calcularPuntaje
