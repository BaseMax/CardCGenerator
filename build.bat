@echo off
setlocal

set MSYS2_PATH=C:\msys64
set MINGW_PATH=%MSYS2_PATH%\mingw64

set CC=%MINGW_PATH%\bin\gcc.exe
set CFLAGS=-I%MINGW_PATH%\include -Wall
set LDFLAGS=-L%MINGW_PATH%\lib -lcairo -lfontconfig -lgdi32

%CC% %CFLAGS% -o card_generator card_generator.c %LDFLAGS%

endlocal
