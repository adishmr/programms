#!/bin/bash
# File   : file_search.sh
# Author : Adish M R
# Brief  : Shell script to filter and show list of files/directories which
# exceeds specific size limit. Path and size limit need to be get from user
# at runtime.
echo -e "this script is to list files in a directory by size\n"
echo "Enter path: "
read -p ">>" USRPATH
if [ ${#USRPATH} -eq 0 ]; then
	USRPATH=". "
    echo -e "current directory is taken as path\n"
fi
cat << END
specify size by c for bytes, k for kilobytes, M for Megabytes and G for Gigabytes
eg: for 100 bytes -> 100c
    for 100 kB -> 100k
    for 100 MB -> 100M
    for 100 GB -> 100G
END
echo "Enter file size: "
read -p ">>" FSIZE
if [ ${#FSIZE} -eq 0 ]; then
	echo "please enter file size"
    exit
elif [[ $FSIZE != *[ckMG]* ]]; then
    echo "specify the size in bytes or kB or MB or GB"
    exit
fi
echo -e "\nto find files above $FSIZE type ABOVE
to find files below $FSIZE type BELOW"
read -p ">>" OPTION
OPTION=${OPTION,,}
if [[ $OPTION = "above" ]]
then
    find $USRPATH -size +$FSIZE
elif [[ $OPTION = "below" ]]
then
    find $USRPATH -size -$FSIZE
else
	echo "you must specify one option"
	exit
fi
