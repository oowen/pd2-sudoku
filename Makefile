main: Sudoku.o main.o
	g++ -o Sudoku main.o Sudoku.o

Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp 

main.o: main.cpp Sudoku.h
	g++ -c main.cpp 

clean:
	rm *.o
