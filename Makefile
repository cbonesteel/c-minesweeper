compile: build game.o board.o command_processor.o src/main.c
	gcc -o minesweeper-game src/main.c build/board/board.o build/game/game.o build/game/command_processor.o

board.o: build src/board/board.c inc/board/board.h
	gcc -c src/board/board.c
	mv board.o build/board/board.o

command_processor.o: build src/game/command_processor.c inc/game/command_processor.h
	gcc -c src/game/command_processor.c
	mv command_processor.o build/game/command_processor.o

game.o: build src/game/game.c inc/game/game.h
	gcc -c src/game/game.c
	mv game.o build/game/game.o

build: 
	mkdir build
	mkdir build/board
	mkdir build/game

clean:
	rm -rf build minesweeper-game
