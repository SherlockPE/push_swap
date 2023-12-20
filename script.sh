MAX_NUMBER=500
repetitions=10

ejecutable="./push_swap"

RANDOM_NUMBER=$(($RANDOM%$MAX_NUMBER))

for ((i=0; i < $repetitions; i++))
do
    $ejecutable
done