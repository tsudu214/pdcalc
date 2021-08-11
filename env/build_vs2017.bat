rem Change CMAKE for your environment.

set CMAKE=D:\Program Files\CMake\bin\cmake.exe


set ENV_DIR=%CD%
pushd .
%~d0
cd "%~dp0.."
set ROOT_DIR=%CD%
popd

rem call :MAKE_WIN32
call :MAKE_WIN64
rem pause
goto :EOF

:MAKE_WIN32
call :MAKE_1_ENV vs2017.x86 "Visual Studio 15" "Release"
goto :EOF

:MAKE_WIN64
call :MAKE_1_ENV vs2017.x64 "Visual Studio 15 2017 Win64" "Release"
goto :EOF

:MAKE_1_ENV
pushd .
setlocal
set WORK_DIR=%~1
set CMAKE_GENERATOR=%~2
set BUILD_CONFIG=%~3

mkdir "%WORK_DIR%"
cd "%WORK_DIR%"
"%CMAKE%" -G "%CMAKE_GENERATOR%" "%ROOT_DIR%"
if not "%BUILD_CONFIG%" == "" (
  "%CMAKE%" --build . --config "%BUILD_CONFIG%"
)

endlocal
popd
goto :EOF

