sudoku: main.o sudoku.o
	g++ -g main.o sudoku.o -o sudoku

main.o: main.cpp sudoku.h
	g++ -Wall  -c main.cpp

sudoku.o: sudoku.cpp sudoku.h 
	g++ -Wall  -c sudoku.cpp


.PHONY: clean
clean:
	rm -f sudoku *.o
