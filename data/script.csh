#!/bin/csh

# Directorios de trabajo
set dir_datos = "."
set dir_bin = "../bin"

# =========================================================================
# COMPARATIVA EJERCICIO 2.2: O(N)
# Matriz: Fuerza Bruta vs Divide y Vencerás
# =========================================================================
echo "--- Iniciando comparativa del Ejercicio 2.2 ---"
# Aumentamos drásticamente el tamaño para evitar los tiempos negativos.
# Filas fijas en 5000. Columnas de 5000 a 50000 (saltos de 5000).
# Esto probará matrices de hasta 250 millones de elementos.

foreach ejecutable (ejercicio2.2_FB ejercicio2.2_DV)
    set salida = "${dir_datos}/${ejecutable}.dat"
    echo "Ejecutando $ejecutable con tamaños extremos..."
    
    # Limpiamos el archivo .dat anterior
    echo -n "" > $salida
    
    @ i = 5000
    while ($i <= 50000)
        # Los argumentos son: semilla filas columnas
        $dir_bin/$ejecutable 42 5000 $i >> $salida
        @ i += 5000
    end
end

echo ""

# =========================================================================
# COMPARATIVA EJERCICIO 2.4: O(N^2) vs O(N log N)
# Inversiones: Fuerza Bruta vs Divide y Vencerás
# =========================================================================
echo "--- Iniciando comparativa del Ejercicio 2.4 ---"
# Dejamos este exactamente igual porque la gráfica salió impecable.

foreach ejecutable (ejercicio2.4_FB ejercicio2.4_DV)
    set salida = "${dir_datos}/${ejecutable}.dat"
    echo "Ejecutando $ejecutable..."
    
    # Limpiamos el archivo .dat anterior
    echo -n "" > $salida
    
    @ i = 5000
    while ($i <= 100000)
        # Filtramos la salida con awk para extraer solo Tamaño y Tiempo
        $dir_bin/$ejecutable 42 $i | awk '{print $2, $6}' >> $salida
        @ i += 5000
    end
end

echo ""
echo "Proceso finalizado. Los archivos .dat estan listos."
