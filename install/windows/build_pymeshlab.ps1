#saving location where script has been runned
$DIR = Get-Location

cd $PSScriptRoot #move to script directory
cd ..\..\src

qmake PyMeshLab.pro
jom -j4

#going back to original location
cd $DIR
