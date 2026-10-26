cd "graphs"
set loadpath "../data"
set terminal pngcairo size 1000,700 font "Arial,12"
set grid
set key top left
set xlabel "Nombre d'elements (n)"
set ylabel "Temps (ms)"
set format x "%.0s%c"
set xrange [0:*]
set yrange [0:*]

set output "graph_bubble_sort.png"
set title "Tri a bulles : temps en fonction de n"
plot "bubble_sort.dat" using 1:2 with lines lw 1 lc rgb "gray" notitle, \
     "bubble_sort.dat" using 1:2 with points pt 7 ps 1.3 lc rgb "red" title "mesures", \
     "bubble_sort.dat" using 1:2 smooth acsplines with lines lw 3 lc rgb "red" title "courbe lissee"

set output "graph_insertion_sort.png"
set title "Tri par insertion : temps en fonction de n"
plot "insertion_sort.dat" using 1:2 with lines lw 1 lc rgb "gray" notitle, \
     "insertion_sort.dat" using 1:2 with points pt 7 ps 1.3 lc rgb "green" title "mesures", \
     "insertion_sort.dat" using 1:2 smooth acsplines with lines lw 3 lc rgb "green" title "courbe lissee"

set output "graph_selection_sort.png"
set title "Tri par selection : temps en fonction de n"
plot "selection_sort.dat" using 1:2 with lines lw 1 lc rgb "gray" notitle, \
     "selection_sort.dat" using 1:2 with points pt 7 ps 1.3 lc rgb "blue" title "mesures", \
     "selection_sort.dat" using 1:2 smooth acsplines with lines lw 3 lc rgb "blue" title "courbe lissee"

set output "graph_quick_sort.png"
set title "Tri rapide : temps en fonction de n"
plot "quick_sort.dat" using 1:2 with lines lw 1 lc rgb "gray" notitle, \
     "quick_sort.dat" using 1:2 with points pt 7 ps 1.3 lc rgb "orange" title "mesures", \
     "quick_sort.dat" using 1:2 smooth acsplines with lines lw 3 lc rgb "orange" title "courbe lissee"

set output "graph_merge_sort.png"
set title "Tri fusion : temps en fonction de n"
plot "merge_sort.dat" using 1:2 with lines lw 1 lc rgb "gray" notitle, \
     "merge_sort.dat" using 1:2 with points pt 7 ps 1.3 lc rgb "purple" title "mesures", \
     "merge_sort.dat" using 1:2 smooth acsplines with lines lw 3 lc rgb "purple" title "courbe lissee"

set output "graph_heap_sort.png"
set title "Tri par tas : temps en fonction de n"
plot "heap_sort.dat" using 1:2 with lines lw 1 lc rgb "gray" notitle, \
     "heap_sort.dat" using 1:2 with points pt 7 ps 1.3 lc rgb "brown" title "mesures", \
     "heap_sort.dat" using 1:2 smooth acsplines with lines lw 3 lc rgb "brown" title "courbe lissee"

set output "graph_slow_sorts.png"
set title "Les 3 tris lents : O(n^2)"
plot "bubble_sort.dat"    using 1:2 with points pt 7 ps 1.3 lc rgb "red"   notitle, \
     "bubble_sort.dat"    using 1:2 smooth acsplines with lines lw 2 lc rgb "red"   title "tri a bulles", \
     "insertion_sort.dat" using 1:2 with points pt 7 ps 1.3 lc rgb "green" notitle, \
     "insertion_sort.dat" using 1:2 smooth acsplines with lines lw 2 lc rgb "green" title "tri par insertion", \
     "selection_sort.dat" using 1:2 with points pt 7 ps 1.3 lc rgb "blue"  notitle, \
     "selection_sort.dat" using 1:2 smooth acsplines with lines lw 2 lc rgb "blue"  title "tri par selection"

set output "graph_fast_sorts.png"
set title "Les 3 tris rapides : O(n log n)"
plot "quick_sort.dat" using 1:2 with points pt 7 ps 1.3 lc rgb "orange" notitle, \
     "quick_sort.dat" using 1:2 smooth acsplines with lines lw 2 lc rgb "orange" title "tri rapide", \
     "merge_sort.dat" using 1:2 with points pt 7 ps 1.3 lc rgb "purple" notitle, \
     "merge_sort.dat" using 1:2 smooth acsplines with lines lw 2 lc rgb "purple" title "tri fusion", \
     "heap_sort.dat"  using 1:2 with points pt 7 ps 1.3 lc rgb "brown"  notitle, \
     "heap_sort.dat"  using 1:2 smooth acsplines with lines lw 2 lc rgb "brown"  title "tri par tas"

unset xrange
unset yrange
set logscale xy
set format y "%g"
set datafile missing "0.000"

set output "graph_all_sorts.png"
set title "Comparaison des 6 tris (echelle logarithmique)"
plot "bubble_sort.dat"    using 1:2 with linespoints lw 2 pt 7 ps 1.2 lc rgb "red"    title "tri a bulles", \
     "insertion_sort.dat" using 1:2 with linespoints lw 2 pt 7 ps 1.2 lc rgb "green"  title "tri par insertion", \
     "selection_sort.dat" using 1:2 with linespoints lw 2 pt 7 ps 1.2 lc rgb "blue"   title "tri par selection", \
     "quick_sort.dat"     using 1:2 with linespoints lw 2 pt 7 ps 1.2 lc rgb "orange" title "tri rapide", \
     "merge_sort.dat"     using 1:2 with linespoints lw 2 pt 7 ps 1.2 lc rgb "purple" title "tri fusion", \
     "heap_sort.dat"      using 1:2 with linespoints lw 2 pt 7 ps 1.2 lc rgb "brown"  title "tri par tas"
