#!/bin/bash
#File   : hangman.sh
#Author : Adish M R
#Brief  : Shell script to play hangman game.
STRING=`shuf -n1 /usr/share/dict/american-english`;
STRING=${STRING,,}
STRING=${STRING/"'s"}
BAKUP=$STRING
LIVES=${#STRING}
##########################
function gallows_base
{
clear
echo "                  "
echo "                  "
echo "                  "
echo "                  "
echo "                  "
echo "                  "
echo "                  "
echo "                  "
echo "                  "
echo "      ________________"
echo "                           "
}
function gallows_pole1
{
clear
echo "                  "
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "      ___________|_____"
echo "                           "
}
function gallows_pole2
{
clear
echo "          ________"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "      ___________|_____"
echo "                           "
}
function gallows
{
clear
echo "          ________"
echo "         |       |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "      ___________|_____"
echo "                           "
}
function gallows_head
{
clear
echo "          ________"
echo "         |       |"
echo "       _/_\_     |"
echo "        |_|      |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "      ___________|_____"
echo "                           "
}
function gallows_body
{
clear
echo "          ________"
echo "         |       |"
echo "       _/_\_     |"
echo "        |_|      |"
echo "         |       |"
echo "         |       |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "      ___________|_____"
echo "                           "
}
function gallows_arm1
{
clear
echo "          ________"
echo "         |       |"
echo "       _/_\_     |"
echo "        |_|      |"
echo "       --|       |"
echo "         |       |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "      ___________|_____"
echo "                           "
}
function gallows_arm2
{
clear
echo "          ________"
echo "         |       |"
echo "       _/_\_     |"
echo "        |_|      |"
echo "       --|--     |"
echo "         |       |"
echo "                 |"
echo "                 |"
echo "                 |"
echo "      ___________|_____"
echo "                           "
}
function gallows_leg1
{
clear
echo "          ________"
echo "         |       |"
echo "       _/_\_     |"
echo "        |_|      |"
echo "       --|--     |"
echo "         |       |"
echo "        /        |"
echo "       /         |"
echo "                 |"
echo "      ___________|_____"
echo "                           "
}
function gallows_leg2
{
clear
echo "          ________"
echo "         |       |"
echo "       _/_\_     |"
echo "        |_|      |"
echo "       --|--     |"
echo "         |       |"
echo "        / \      |"
echo "       /   \     |"
echo "                 |"
echo "      ___________|_____"
echo "                           "
}

function chek_fn
{
    if [ $LIVES == "9" ]; then
        gallows_base;
	elif [ $LIVES == "8" ]; then
	    gallows_pole1;
	elif [ $LIVES == "7" ]; then
		gallows_pole2;
	elif [ $LIVES == "6" ]; then
		gallows;
	elif [ $LIVES == "5" ]; then
		gallows_head;
	elif [ $LIVES == "4" ]; then
		gallows_body;
	elif [ $LIVES == "3" ]; then
		gallows_arm1;
	elif [ $LIVES == "2" ]; then
		gallows_arm2;
	elif [ $LIVES == "1" ]; then
		gallows_leg1;
	elif [ $LIVES == "0" ]; then
		gallows_leg2;
	fi
}
##########################
clear
echo -e "=====Welcome to HANGMAN=====\n"
echo -e "You have $LIVES lives"
echo -e " ${BAKUP//[^[:space:]$STORE]/_ }\n"
while [ $LIVES -ne 0 ]
do
	echo ">>$DISP"
	read -n1 -p "enter the letter: " LETTER
	DISP+=$LETTER
	LETTER=${LETTER,,}
	if [ ${#LETTER} -eq 0 ];
	then
    	LETTER="!"
    	echo $LETTER
	fi
	LETTER=${LETTER,,}
	if [[ $STRING == *$LETTER* ]]; then
		STRING=${STRING//$LETTER/}
		STORE+=$LETTER
	else
        LIVES=`expr $LIVES - 1`
		chek_fn
        echo -e "\n!! You Lost 1 Life, you have $LIVES lives remaining"
    fi
	
	echo -e "\n${BAKUP//[^[:space:]$STORE]/_ }\n"
    if [ -z "$STRING" ]; then
        echo "Congratulations... You Won the Game
        with $LIVES lives remaining"
        exit
    fi
done
echo "You lose... Try Next time..
      The word was $BAKUP"
