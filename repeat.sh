
max=200

for ((i=1; i<=max; i++)); do
    bash script.sh > cases/"case$i"
done