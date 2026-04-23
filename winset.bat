@echo off
setlocal

set "DPS=deps"
set "WLD=%DPS%\mingw64"
set "WLD32=%DPS%\mingw32"
set "PDD=%DPS%\pdcmod"
if not exist "%DPS%" mkdir "%DPS%"




if not exist "%DPS%\pdcurses.zip" (powershell -Command "Invoke-WebRequest 'https://github.com/Bill-Gray/PDCursesMod/archive/refs/tags/v4.5.4.zip' -OutFile '%DPS%\pdcurses.zip'")

if /i "%PROCESSOR_ARCHITECTURE%"=="AMD64" (if not exist "%DPS%\winlib.zip" (powershell -Command "Invoke-WebRequest 'https://github.com/brechtsanders/winlibs_mingw/releases/download/15.2.0posix-14.0.0-msvcrt-r7/winlibs-x86_64-posix-seh-gcc-15.2.0-mingw-w64msvcrt-14.0.0-r7.zip' -OutFile '%DPS%\winlib.zip'")
) else (if not exist "%DPS%\winlib.zip" (powershell -Command "Invoke-WebRequest 'https://github.com/brechtsanders/winlibs_mingw/releases/download/15.2.0posix-14.0.0-msvcrt-r7/winlibs-i686-posix-dwarf-gcc-15.2.0-mingw-w64msvcrt-14.0.0-r7.zip' -OutFile '%DPS%\winlib.zip'")
)


if not exist "%DPS%\pdcmod" (tar -xf "%DPS%\pdcurses.zip" -C "%DPS%" && ren "%DPS%\PDCursesMod-4.5.4" pdcmod)
if not exist "%DPS%\msvc" (tar -xf "%DPS%\winlib.zip" -C "%DPS%")

if /i "%PROCESSOR_ARCHITECTURE%"=="AMD64" (
    "%WLD%\bin\gcc.exe" main.c glob.c log.c pcs.c ren.c %PDD%\wincon\*.c %PDD%\pdcurses\*.c -I"%PDD%" -I"%PDD%"\wincon -lwinmm -lm -static -static-libgcc -o tettyris.exe -lwinmm
) else (
    "%WLD32%\bin\gcc.exe"   main.c glob.c log.c pcs.c ren.c %PDD%\wincon\*.c %PDD%\pdcurses\*.c -I"%PDD%" -I"%PDD%"\wincon -lwinmm -lm -static -static-libgcc -o tettyris.exe -lwinmm
)

if exist "%DPS%" rmdir /s /q "%DPS%"
endlocal
