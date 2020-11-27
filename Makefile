prog:capteur.o main.o
	gcc capteur.o main.o -o prog -g
main.o:main.c
	gcc -c main.c -g
capteur.o:capteur.c
	gcc -c capteur.c -g
