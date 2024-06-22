# plot des positions des boules sur le graph

plot "positions.txt" index (i) using 1:2:(0.2) with circles title "" lc rgb"white" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 3:4:(0.2) with circles title "" lc rgb"black" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 5:6:(0.2) with circles title "" lc rgb"orange" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 7:8:(0.2) with circles title "" lc rgb"orange" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 9:10:(0.2) with circles title "" lc rgb"yellow" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 11:12:(0.2) with circles title "" lc rgb"yellow" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 13:14:(0.2) with circles title "" lc rgb"dark-green" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 15:16:(0.2) with circles title "" lc rgb"dark-green" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 17:18:(0.2) with circles title "" lc rgb"dark-magenta" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 19:20:(0.2) with circles title "" lc rgb"dark-magenta" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 21:22:(0.2) with circles title "" lc rgb"red" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 23:24:(0.2) with circles title "" lc rgb"red" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 25:26:(0.2) with circles title "" lc rgb"blue" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 27:28:(0.2) with circles title "" lc rgb"blue" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 29:30:(0.2) with circles title "" lc rgb"dark-red" fs transparent solid 0.9 noborder,\
"positions.txt" index (i) using 31:32:(0.2) with circles title "" lc rgb"dark-red" fs transparent solid 0.9 noborder,\

i = i+1
if (i<=imax) reread