;rutinas.asm 
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
; RCX= monedas recolectadas
; RDX= pasos realizados
; R8= niveles completados
; puntaje total = monedas * 100 + niveles * 500 - pasos * 2
; puntaje negativo devuelve 0
calcularPuntaje:
    mov rax, rcx
    imul rax, 100 ; monedas * 100

    mov r10, r8
    imul r10, 500 ; niveles * 500
    add rax, r10 ; sumar a las monedas

    mov r11, rdx
    imul r11, 2 ; pasos * 2
    sub rax, r11 ; restar a las monedas y niveles

    cmp rax, 0
jge .fin_puntaje

    xor rax, rax ; puntaje negativo devuelve 0

    .fin_puntaje:
    ret

; int detectarObjeto
; RCX= direccion inicial del mapa
; RDX= numero de columnas del mapa
; R8= fila
; R9= columna
; [rsp+40]=  objeto buscado
; Devuelve 1 si se detecta un objeto, 0 si no se detecta

detectarObjeto:
    mov r10, r8   ; fila
    imul r10, rdx   ; fila*columnas
    add r10, r9   ; fila*columnas + columna

    mov al, [rcx + r10] ; obtener el caracter de la celda
    mov r11b, [rsp+40] ; cargar el objeto buscado en r11b
    cmp al, r11b ; comparar con el objeto buscado
    je .encontrado

    xor rax, rax ; objeto no detectado
    ret

.encontrado:
    mov rax, 1 ; objeto detectado
    ret

; int CeldasLibres
; RCX= direccion inicial del mapa
; RDX= total de celdas
; cuenta el numero de celdas libres ('.') en el mapa
; Devuelve en RAX el total
CeldasLibres:
    xor rax, rax ; contador de celdas libres
    xor r10, r10   ; índice del bucle

    .ciclo_libres:
    cmp r10, rdx
    jge .fin_libres
    mov bl, [rcx + r10]
    cmp bl, '.' ; comparar con el caracter de celda libre
    jne .siguiente_libre
    inc rax
.siguiente_libre:
    inc r10
    jmp .ciclo_libres

.fin_libres:
    ret