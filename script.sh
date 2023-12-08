#!/bin/bash

# Número de argumentos aleatorios que se generarán
num_argumentos=5

# Ruta al ejecutable
ejecutable="./push_swap"

# Generar números aleatorios y almacenarlos en un array
for ((i=1; i<=$num_argumentos; i++)); do
    numeros_aleatorios+=($((RANDOM % 5)))
done

# Imprimir los números aleatorios generados
# echo "Total de números generados: ${num_argumentos}"
echo "Números aleatorios generados: ${numeros_aleatorios[@]}"

# Llamar al ejecutable con los números aleatorios como argumentos
$ejecutable "${numeros_aleatorios[@]}"