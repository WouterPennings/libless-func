gcc -Wall -c print.c
gcc -Wall -c main.c

gcc -o main print.o main.o
./main