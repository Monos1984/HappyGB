@echo off
rem *****************************************************
rem * Fichier de Compilation Game Boy avec SDCC *
rem *****************************************************
rem * Version : 1.2 du 30/6/2019                        *
rem *****************************************************
 
rem ===================
rem ** Configuration **
rem =================== 
rem --------------
rem - Nom du jeu -
rem --------------
set nom=template

rem ------------------------------
rem - Nom du repertoir de sortie -
rem ------------------------------
set sortie=bin
rem -----------------------------------
rem - Nom du repertoir du code source -
rem -----------------------------------
SET dsource=source
rem --------------------------------
rem - adresse du dossier de la lib -
rem --------------------------------
SET adrsdk=..\..\happylib_gb

rem ----------------
rem - adresse sdcc -
rem ----------------
SET adrsdcc=..\..\SDCC\bin

rem ---------------------
rem - adresse emulateur -
rem ---------------------
SET adremul=..\..\bgb\bgb


rem ===============================================================
rem ** Test si le repertoir de sortie existe sinon il est genere **
rem ===============================================================
:suite
if not exist %sortie% goto :newrep

echo ----------------------------------------------
echo -- compilation du projet %nom%
echo ----------------------------------------------
rem ===========================
rem ** Effacement du fichier **
rem ===========================
if exist "%sortie%\%nom%.gb" del %sortie%\%nom%.gb


echo -------------------------------------------
echo -- Creation de la ROM pour Master System --
echo -------------------------------------------


rem ================================
rem ** Compilation des fichiers C **
rem ================================ 

echo ------------------
echo -- version sdcc --
echo ------------------
%adrsdcc%\sdcc -v

echo -----------------
echo -- compilation --
echo -----------------



for %%i in (%dsource%\*.*) do ( 
echo %%~nxi

%adrsdcc%\sdcc  -c -mgbz80 -I%adrsdk%/include %dsource%/%%~nxi
 )

rem =================================
rem ** linkage des fichiers objets **
rem =================================
%adrsdcc%\sdcc  -mgbz80 -o gb.ihx  --no-std-crt0  --data-loc 0xc0a0 %adrsdk%\lib\crt0.rel %adrsdk%\lib\happylib_gb.rel *.rel


echo -----------------------------
echo -- Creation du fichier gb --
echo -----------------------------

%adrsdcc%\makebin -Z -yn dt gb.ihx %sortie%/%nom%.gb 
echo.
if exist "%sortie%/%nom%.gb" echo --- Le fichier %nom%.gb vient d'etre genere dans le repertoir %sortie% ---
echo.
echo ----------------------------------------------------------------
echo - Debut effacement des fichiers sym,ihx,lk,noi,rel,lst,asm,map -
echo ----------------------------------------------------------------
pause


if exist "*.sym" del *.sym
if exist "*.ihx" del *.ihx
if exist "*.lk"  del *.lk
if exist "*.noi" del *.noi
if exist "*.rel" del *.rel
if exist "*.lst" del *.lst
if exist "*.asm" del *.asm
if exist "*.map" del *.map
echo -----------------------
echo - effacement effectue -
echo -----------------------
pause


if exist "%sortie%/%nom%.gb" %adremul% %sortie%/%nom%.gb


exit

rem ===================================
rem ** Creation du dossier de sortie **
rem ===================================
:newrep
mkdir %sortie%
goto :suite
