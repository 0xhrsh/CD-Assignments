gcc -c func1.c
gcc -c func2.c
gcc -c main.c
gcc main.o func1.o func2.o -o out && ./out