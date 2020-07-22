#saving location where script has been runned
$DIR = Get-Location

$DISTRIB_PATH = Join-Path $PSScriptRoot ..\..\pymeshlab

$BUILD_PATH = Join-Path $PSScriptRoot ..\..\build

cd $PSScriptRoot #move to script directory

New-Item -ItemType Directory -Force -Path $BUILD_PATH

..\..\meshlab\install\windows\windows_build.ps1 $BUILD_PATH
..\..\meshlab\install\windows\windows_deploy.ps1 $BUILD_PATH\distrib

New-Item -ItemType Directory -Force -Path $DISTRIB_PATH\lib\meshlab\plugins
Copy-Item -Path $BUILD_PATH\distrib\*.dll -Destination $DISTRIB_PATH\lib\
Copy-Item -Path $BUILD_PATH\distrib\*.exp -Destination $DISTRIB_PATH\lib\
Copy-Item -Path $BUILD_PATH\distrib\*.lib -Destination $DISTRIB_PATH\lib\
Copy-Item -Path $BUILD_PATH\distrib\*.lib -Destination $DISTRIB_PATH\lib\
Copy-Item -Path $BUILD_PATH\distrib\lib\win32-msvc\*.lib -Destination $DISTRIB_PATH\lib\meshlab\
Copy-Item -Path $BUILD_PATH\distrib\lib\meshlab-common.lib -Destination $DISTRIB_PATH\lib\
Copy-Item -Path $BUILD_PATH\distrib\plugins\* -Destination $DISTRIB_PATH\lib\meshlab\plugins\
Copy-Item -Path $DISTRIB_PATH\lib\Qt*.dll -Destination $DISTRIB_PATH\
Remove-Item $DISTRIB_PATH\lib\Qt*.dll

rm -r $BUILD_PATH

#going back to original location
cd $DIR
