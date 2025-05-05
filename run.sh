#!bin/sh

gcc -o main -Iinclude main.c lib/nbtree.c

if [ $? -eq 0 ]; then
    clear
    echo "Compilation successful. Running the program..."
    ./main
else
    echo "Compilation failed."
fi