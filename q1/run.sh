gcc -c main.c
gcc -c fun1.c
gcc -c fun2.c
gcc main.o fun1.o fun2.o -o out && ./out