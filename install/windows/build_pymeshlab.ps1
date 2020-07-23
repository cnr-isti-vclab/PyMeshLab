#saving location where script has been runned
$DIR = Get-Location

.\remove_unsuitable_plugins.ps1

cd $PSScriptRoot #move to script directory
cd ..\..\src\pymeshlabserver

qmake pymeshlabserver.pro
jom -j4

#going back to original location
cd $DIR
