all: signal.c
	gcc signal.c

run: all
	./a.out
clean:
	rm *.out
	rm *~
