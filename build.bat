@echo off

echo _____________________________________
echo        COMPILANDO BITQUEST
echo _____________________________________

gcc -c main.c
if errorlevel 1 goto error

gcc -c juego.c
if errorlevel 1 goto error

gcc -c mapas.c
if errorlevel 1 goto error

nasm -f win64 rutinas.asm -o rutinas.obj
if errorlevel 1 goto error

gcc main.o juego.o mapas.o rutinas.obj -o BitQuest.exe
if errorlevel 1 goto error

echo.
echo _____________________________________
echo      COMPILACION EXITOSA
echo _____________________________________
echo.

pause
exit

:error
echo.
echo _____________________________________
echo      ERROR DE COMPILACION
echo _____________________________________
echo.

pause