compile: minesweeper/board/board.o minesweeper/main.c
	gcc -o minesweeper-game minesweeper/main.c minesweeper/board/board.o

board.o: minesweeper/board/board.c minesweeper/board/board.h
	gcc -c minesweeper/board/board.c

clean:
	rm minesweeper/board/*.o minesweeper-game
