compile: build game.o board.o command_processor.o menu.o src/main.c program.o
	gcc -o minesweeper-game src/main.c build/board/board.o build/game/game.o build/game/command_processor.o build/menu/menu.o build/program/program.o

board.o: build src/board/board.c inc/board/board.h
	gcc -c src/board/board.c
	mv board.o build/board/board.o

command_processor.o: build src/game/command_processor.c inc/game/command_processor.h
	gcc -c src/game/command_processor.c
	mv command_processor.o build/game/command_processor.o

game.o: build src/game/game.c inc/game/game.h
	gcc -c src/game/game.c
	mv game.o build/game/game.o

menu.o: build src/menu/menu.c inc/menu/menu.h
	gcc -c src/menu/menu.c
	mv menu.o build/menu/menu.o

program.o: build src/program/program.c inc/program/program.h
	gcc -c src/program/program.c
	mv program.o build/program/program.o

build: 
	mkdir build
	mkdir build/board
	mkdir build/game
	mkdir build/menu
	mkdir build/program

clean:
	rm -rf build minesweeper-game
