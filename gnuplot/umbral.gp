set terminal pngcairo size 900,600
set output "umbral.png"
set title "Cálculo experimental del umbral"
set xlabel "Tamaño n"
set ylabel "Tiempo (ms)"
set grid
set key top right


stats data_file using 1:(abs($2-$3)) nooutput
umbral = STATS_pos_min_y
print sprintf("Umbral experminetal n0 = %.4f", umbral)

set arrow 1 from umbral, graph 0 to umbral, graph 1 nohead dt 2 lc rgb "red"
set label 1 sprintf("n0 = %.2f", uumbral) at umbral+2, graph 0.9 tc rgb "red"

plot
	data_file using 1:2 smooth sbezier title "Fuerza bruta",
	data_file using 1:3 smooth sbezier title "Divide y vencerás"
unset output
