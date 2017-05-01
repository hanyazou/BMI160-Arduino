#!/bin/bash

log=`date "+build-%Y%m%d-%H:%M.%S.log.txt"`
echo=/bin/echo

arduino="/Applications/Arduino-1.8.2.app/Contents/MacOS/Arduino"
boards=''
boards="$boards arduino:avr:uno"
boards="$boards Intel:arc32:arduino_101"
boards="$boards arduino:avr:leonardo"
boards="$boards arduino:samd:mzero_pro_bl_dbg"
#boards="$boards Arduino_STM32:STM32F1:genericSTM32F103C"

opts="--verbose --verify "

sketches="$*"
if [ ".$sketches" == . ]; then
    echo "Sketch file required."
    echo "USAGE: buildtest.sh <sketch.ino>..."
    exit 1
fi
   
msg()
{
    $echo $* >> $log
    $echo $*
}

filter()
{
    sed "s/$USER/johndoe/g"
}

buildtest()
{
    echo "##################################" >> $log
    echo "$arduino" --board "$board" $opts "$sketch" >> $log
    "$arduino" --board "$board" $opts "$sketch" 2>&1 | filter >> $log
    if [ ${PIPESTATUS[0]} == 0 ]; then
	msg "# ok board=$board"
    else
	msg "# ERROR board=$board"
	let err+=1
    fi
}

echo > $log
msg Arduino build test log started on `date`
msg
msg sketches=$sketches
msg boards=$boards
msg
err=0
for sketch in $sketches; do
    msg "## sketch=$sketch"
    for board in $boards; do
	buildtest $board $sketch
    done
done

msg
if [ $err == 0 ]; then
    msg All the build tests scceeded, CONGRATULATIONS!
else
    msg $err ERRORS
fi

msg
msg `date`
