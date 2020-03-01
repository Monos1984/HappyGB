@echo off
rem *****************************************************
rem * Fichier de Compilation Game Boy avec SDCC *
rem *****************************************************
rem * Version : 1.2 du 30/6/2019                        *
rem *****************************************************
 

rem --------------------------------
rem - adresse du dossier de la lib -
rem --------------------------------
SET adrsdk=..\..\happylib_gb




rem ================================
rem ** Compilation des fichiers C **
rem ================================ 
echo -----------------
echo -- compilation --
echo -----------------





sdcc -c -mgbz80 -I%adrsdk%/include happylib_gb.c

if exist "*.sym" del *.sym
if exist "*.ihx" del *.ihx
if exist "*.lk"  del *.lk
if exist "*.noi" del *.noi

if exist "*.lst" del *.lst
if exist "*.asm" del *.asm
if exist "*.map" del *.map

pause
