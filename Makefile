compile: build board.o src/main.c
	gcc -o minesweeper-game src/main.c build/board/board.o

board.o: build src/board/board.c inc/board/board.h
	gcc -c src/board/board.c
	mv board.o build/board/board.o

build: 
	mkdir build
	mkdir build/board
	mkdir build/game

clean:
	rm -rf build minesweeper-game
