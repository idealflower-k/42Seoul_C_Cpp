cat /etc/passwd | grep -v '#' | sed -n 'n;p' | cut -d ':' -f1 | rev | sort -r | awk "$FT_LINE1 <= NR && NR <= $FT_LINE2" | xargs | sed  's/ /, /g' | sed 's/$/./' | tr -d '\n'
