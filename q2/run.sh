echo Here is the original file
cat temp.c
gcc -c main.c
gcc -c r_lc.c
gcc -c r_mc.c
gcc -c rs.c
gcc main.o r_lc.o r_mc.o rs.o -o out && ./out
echo here is the file after removing comments and spaces
cat temp.c
