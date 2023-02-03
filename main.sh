#!/bin/bash

# définir les options possibles
while getopts "t1:t2:t3:p1:p2:p3:w:m:h::F:G:S:A:O:Q:Help" opt; do
  case $opt in
    t1) option_t1="$OPTARG"
    ;;
    t2) option_t1="$OPTARG"
    ;;
    t3) option_t1="$OPTARG"
    ;;
    p1) option_p="$OPTARG"
    ;;
    p2) option_p="$OPTARG"
    ;;
    p3) option_p="$OPTARG"
    ;;
    w) option_w="$OPTARG"
    ;;
    m) option_m="$OPTARG"
    ;;
    h) option_h="$OPTARG"
    ;;
    h) option_F="$OPTARG"
    ;;
    h) option_G="$OPTARG"
    ;;
    h) option_S="$OPTARG"
    ;;
    h) option_A="$OPTARG"
    ;;
    h) option_O="$OPTARG"
    ;;
    h) option_Q="$OPTARG"
    ;;
    Help) option_Help="$OPTARG"
        echo "-t<mode> : (t)emperatures."
        echo "-p<mode> : (p)ressions atmosphériques."
        echo "-w : vent ( (w)ind )"
        echo "-h : altitude ( (h)eight)"
        echo "-m : humidité ( (m)oisture )"
        echo "-F : (F)rance : France métropolitaine + Corse"
        echo "-G : (G)uyane française"
        echo "-S : (S)aint-Pierre et Miquelon : ile située à l’Est du Canada"
        echo "-A : (A)ntilles"
        echo "-O : (O)céan indien"
        echo "-Q : antarcti(Q)ue"
    ;;
    \?) echo "Option non valide : -$OPTARG" >&2
    exit 1
    ;;
  esac
done

if [ -n "$option_t1" ]; then
  
fi

if [ -n "$option_t2" ]; then
  
fi

if [ -n "$option_t3" ]; then
  
fi

if [ -n "$option_p1" ]; then
  
fi

if [ -n "$option_p2" ]; then
  
fi

if [ -n "$option_p3" ]; then
  
fi
