#!/bin/sh

#per poter funzionare bisogna installare espeak tramite comando sudo apt install espeak
#per farlo "parlare in italiano" bisogna installare espeak tramite il comando  sudo apt-get install mbrola-it3 mbrola-it4  dove -it3 è la voce maschile, -it4 è la voce femminile

g++ persona.cpp -o persona && ./persona
espeak -v mb-it3 -s 150 -f output.txt
