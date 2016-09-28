reset
set ylabel 'Time(sec)'
set xlabel 'N'
set style data lines
set title 'Wall-clock time - using clock()'
set datafile separator ","
set terminal png enhanced font 'Verdana,10'
set output 'clock.png'

plot [0:50000][0:0.006]'result_clock.csv' using 1:2 title 'Baseline', \
'' using 1:3 title 'OpenMP (2 threads)', \
'' using 1:4 title 'OpenMP (4 threads)', \
'' using 1:5 title 'AVX', \
'' using 1:6 title 'AVX + Unroll looping'
