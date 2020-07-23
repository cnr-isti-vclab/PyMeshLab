#saving location where script has been runned
$DIR = Get-Location

cd $PSScriptRoot #move to script directory

.\remove_unsuitable_plugins.ps1

cd ..\..\src\pymeshlabserver

qmake pymeshlabserver.pro
jom -j4

#going back to original location
cd $DIR
