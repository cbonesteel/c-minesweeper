# c-minesweeper

![Project Status: In Development](https://img.shields.io/badge/Project%20Status-In%20Development-brightgreen)
![Version: 0.1](https://img.shields.io/badge/Version-0.1-brightgreen)
![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-brightgreen)

## Project Description
This project is a personal programming project with a focus on learning how to use C. The
program is a basic command line game of minesweeper with user input being text inputs.

The minesweeper game will allow for custom board sizes and difficulty, difficulty being
defined by mine density. All user inputs will be used in the form [letter] [x] [y]. The letter
will define the specific game command, flag, reveal, help, etc., with x and y being the
coordinate to be executed on if the command requires it.

## Installing this Repository

### Dependencies
This project relies on running it from the command line. This repository relies
on the newest version of Gnu's gcc compiler and Gnu's make. Ensure you have recent
copies of both of these programs installed. Download links and instructions can be
found here:

* [gcc](https://gcc.gnu.org/install/)
* [make](https://www.gnu.org/software/make/)

### Installation and Running
**NOTE:** This repository has only been run on macOS. The Makefile relies on Unix based commands
such as mv, mkdir, etc. This repository may not work on Windows using these instructions. Windows
instructions will be written after the project is finished.
1. In ~/your/path clone this repository
2. To compile, run the following command. The output should look similar to below.
``` console
system:c-minesweeper user$ make
mkdir build
mkdir build/board
mkdir build/game
gcc -c src/game/game.c
mv game.o build/game/game.o
gcc -c src/board/board.c
mv board.o build/board/board.o
gcc -o minesweeper-game src/main.c build/board/board.o build/game/game.o
```
3. To run, simply execute the generated executable minesweeper-game as follows.
``` console
system:c-minesweeper user$ ./minesweeper-game
```
4. To clean the directory, run the following command. The output should look simialr to below.
``` console
system:c-minesweeper user$ make clean
rm -rf build minesweeper-game
```


## Roadmap

### Milestone 0.1
* Create Board
* Create Welcome Text
* Get basic game functions working
  * Flag
  * Reveal
  * Help
  * No fog (Hidden Command)

### Milestone 0.2
* Create game loop to be able to play many games on one run
* Add extra game functions
  * Quit game to menu
  * Quit game

### Milestone 0.3
* Add nicer looking board
* Add point system
* Print score at end of game

### Milestone 0.4
* Add game menu for custom sizes
* Add highscores to menu

### Milestone 0.5
* Add custom difficulty options

More TBD

<hr/>

![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey)

<small>
c-minesweeper by Cameron Bonesteel is licensed under CC BY 4.0. To view
a copy of this license, visit
https://creativecommons.org/licenses/by/4.0/
</small>