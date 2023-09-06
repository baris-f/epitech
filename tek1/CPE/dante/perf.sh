if ! [ $# -eq 1 ] ; then
    echo "usage : ./pef.sh file.maz"
    exit 1
elif ! [ -r $1 ] ; then
    echo "file" $1 "isn't valid"
    exit 1
fi

echo "labyrinth choosen :" $1
#printf '\33]50;%s\007' "xft:pango:pixelsize=9"

printf "\nprofondeur test :"
time ./profondeur/solver $1 > /dev/null

printf "\nlargeur test :"
time ./largeur/solver $1 > /dev/null

printf "\nastar test :"
time ./astar/solver $1 > /dev/null
