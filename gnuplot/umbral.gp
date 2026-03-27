# ==========================================
# CONFIGURACIÓN GLOBAL
# ==========================================
set terminal pngcairo size 1000,700 font "Arial,11"
set grid
set key top left
set xlabel "Tamaño del problema (N)"
set ylabel "Tiempo de ejecución (segundos)"

# ==========================================
# EJERCICIO 2.2: O(N) vs O(N)
# ==========================================
set output "ejercicio2_2_ajuste.png"
set title "Ejercicio 2.2: Fuerza Bruta vs Divide y Vencerás"

# 1. Definimos las funciones teóricas (ambas lineales)
f_fb22(x) = a1*x + b1
f_dv22(x) = a2*x + b2

# 2. Hacemos el fit (ajuste por mínimos cuadrados)
fit f_fb22(x) "../data/ejercicio2.2_FB.dat" using 1:2 via a1, b1
fit f_dv22(x) "../data/ejercicio2.2_DV.dat" using 1:2 via a2, b2

# 3. Calculamos el umbral experimental usando 'paste' para unir las columnas
stats "< paste ../data/ejercicio2.2_FB.dat ../data/ejercicio2.2_DV.dat" using 1:(abs($2-$4)) name "UMBRAL22" nooutput
n0_22 = UMBRAL22_pos_min_y

# 4. Dibujamos las marcas
set label 1 sprintf("Umbral aprox: n0 = %d", n0_22) at graph 0.5, 0.9 tc rgb "red" front
set arrow 1 from n0_22, graph 0 to n0_22, graph 1 nohead dt 2 lc rgb "red" front

# 5. Pintamos los puntos reales y las curvas ajustadas
plot "../data/ejercicio2.2_FB.dat" using 1:2 title "FB (Datos)" pt 7 lc rgb "blue", \
     f_fb22(x) title "FB (Ajuste Lineal)" lw 2 lc rgb "dark-blue", \
     "../data/ejercicio2.2_DV.dat" using 1:2 title "DV (Datos)" pt 7 lc rgb "orange", \
     f_dv22(x) title "DV (Ajuste Lineal)" lw 2 lc rgb "dark-orange"

# Limpiamos etiquetas para la siguiente gráfica
unset label 1
unset arrow 1

# ==========================================
# EJERCICIO 2.4: O(N^2) vs O(N log N)
# ==========================================
set output "ejercicio2_4_ajuste.png"
set title "Ejercicio 2.4: Inversiones (FB vs DV)"

# 1. Definimos las funciones teóricas
# Fuerza Bruta es cuadrática, DV es logarítmica
g_fb24(x) = c1*x**2 + d1*x + e1
g_dv24(x) = c2*x*log(x) + d2

# 2. Hacemos el fit
fit g_fb24(x) "../data/ejercicio2.4_FB.dat" using 1:2 via c1, d1, e1
fit g_dv24(x) "../data/ejercicio2.4_DV.dat" using 1:2 via c2, d2

# 3. Calculamos el umbral experimental
stats "< paste ../data/ejercicio2.4_FB.dat ../data/ejercicio2.4_DV.dat" using 1:(abs($2-$4)) name "UMBRAL24" nooutput
n0_24 = UMBRAL24_pos_min_y

# 4. Dibujamos las marcas
set label 1 sprintf("Umbral aprox: n0 = %d", n0_24) at graph 0.3, 0.9 tc rgb "red" front
set arrow 1 from n0_24, graph 0 to n0_24, graph 1 nohead dt 2 lc rgb "red" front

# 5. Pintamos los puntos reales y las curvas ajustadas
plot "../data/ejercicio2.4_FB.dat" using 1:2 title "FB (Datos)" pt 7 lc rgb "cyan", \
     g_fb24(x) title "FB (Ajuste Cuadrático)" lw 2 lc rgb "blue", \
     "../data/ejercicio2.4_DV.dat" using 1:2 title "DV (Datos)" pt 7 lc rgb "green", \
     g_dv24(x) title "DV (Ajuste N log N)" lw 2 lc rgb "dark-green"

unset output
