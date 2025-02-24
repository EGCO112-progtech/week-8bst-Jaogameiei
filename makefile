compile: main.c
	 gcc main.c -o ll


run: ll
	 ./ll 4 1 6 2 11 9


clean: ll
	 rm ll