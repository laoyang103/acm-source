@echo off

set SOURCEDIR=D:\infiles

for /f "delims=" %%I in ('dir /B /ON %SOURCEDIR%') do call makeeach.bat %SOURCEDIR%\%%~nI %%~nI

pause



