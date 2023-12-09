all:
	gcc -c -Wall *.h
	gcc -c -Wall *.c
	gcc -o projeto *.o
	./projeto
clean:
	rm -rf projeto *.h.gch
	rm -rf projeto *.o
run:
	./projeto