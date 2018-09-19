exec 2> /dev/null
echo "1" > ex2.txt
max=1000

for i in `seq 2 $max`
do
    if `ln ex2.txt ex2.txt.lock`; then

        read_line=$(tail -n 1 ex2.txt)
        read_line=$read_line+1
        echo "$((read_line))" >> ex2.txt

        rm ex2.txt.lock
    fi
done
