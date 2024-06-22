#creation du gif
unset xtics
unset ytics

#set term pbm size 600, 400
set size square 1,1


# modification de la couleur du fond
set object 1 rectangle \
from screen 0,0 to screen 1,1 fillcolor rgb"forest-green" behind

#placement des trous du billard
set object 2 circle at 0,0 size 0.5 fillcolor "black" fs transparent solid 0.9 noborder
set object 3 circle at 10,0 size 0.5 fillcolor "black" fs transparent solid 0.9 noborder
set object 4 circle at 0,5 size 0.4 fillcolor "black" fs transparent solid 0.9 noborder
set object 5 circle at 10,5 size 0.4 fillcolor "black" fs transparent solid 0.9 noborder
set object 6 circle at 0,10 size 0.5 fillcolor "black" fs transparent solid 0.9 noborder
set object 7 circle at 10,10 size 0.5 fillcolor "black" fs transparent solid 0.9 noborder

set term gif size 500,500 animate delay 1 
set output "billard.gif"

set xrange [0:10]
set yrange [0:10]
imax = 999
i = 0
load "script_billard.gnu"