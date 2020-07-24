#saving location where script has been runned
$DIR = Get-Location

cd $PSScriptRoot #move to script directory

$FILENAME='..\unsuitable_plugins.txt'
$PLUGINS_DIR='..\..\pymeshlab\lib\meshlab\plugins'

foreach($line in Get-Content $FILENAME) {
    if($line -NotLike "`#*"){
        Remove-Item $PLUGINS_DIR\*$line*
    }
}

#going back to original location
cd $DIR
