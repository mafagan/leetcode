awk '
{
    for(i=1;i<=NF;i++) {
        a[i, NR]=$i
    }
}
NF>p{p=NF}
END{

for(i=1;i<=p;i++) {
    str=a[i, 1]
    for(j=2;j<=NR;j++) {
        str=str" "a[i, j]
    }

    print str
}
}
' file.txt
