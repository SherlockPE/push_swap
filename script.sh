# Número de argumentos aleatorios que se generarán
num_argumentos=5

# Ruta al ejeccutable
ejecutable="./push_swap"

for ((i=1; i<=$num_argumentos; i++)); do
    numeros_aleatorios+=($((RANDOM % 5)))
done

echo "Números aleatorios generados: ${numeros_aleatorios[@]}"

$ejecutable "${numeros_aleatorios[@]}"