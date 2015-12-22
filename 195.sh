lines=`cat file.txt | wc -l`
if [ $lines -gt 9 ]
then
    cat file.txt | head -n 10 | tail -n 1
fi
