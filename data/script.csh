#!/bin/csh

# Directorios de trabajo
set dir_datos = "."
set dir_bin = "../bin"

echo "--- Ejercicio 2.2 ---"
# Tamaños seguros: de 1 a 10 millones de elementos (Max 40 MB de RAM)
foreach ejecutable (ejercicio2.2_FB ejercicio2.2_DV)
    set salida = "${dir_datos}/${ejecutable}.dat"
    echo "Generando archivo $salida ..."
    echo -n "" > $salida
    
    @ i = 1000
    while ($i <= 10000)
        $dir_bin/$ejecutable 42 1000 $i >> $salida
        @ i += 1000
    end
end

echo "--- Ejercicio 2.4 ---"
foreach ejecutable (ejercicio2.4_FB ejercicio2.4_DV)
    set salida = "${dir_datos}/${ejecutable}.dat"
    echo "Generando archivo $salida ..."
    echo -n "" > $salida
    
    @ i = 5000
    while ($i <= 100000)
        $dir_bin/$ejecutable 42 $i | awk '{print $2, $6}' >> $salida
        @ i += 5000
    end
end

echo "¡Proceso terminado sin errores! Tienes los 4 archivos .dat listos."
