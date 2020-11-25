# c-minesweeper

![Project Status: In Development](https://img.shields.io/badge/Project%20Status-In%20Development-brightgreen)
![Version: 0.2.0](https://img.shields.io/badge/Version-0.2.0-brightgreen)
![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-brightgreen)

## Table of Contents
[Project Description](https://github.com/cbonesteel/c-minesweeper#project-description)

[Installing this Repository](https://github.com/cbonesteel/c-minesweeper#installing-this-repository)
* [Dependencies](https://github.com/cbonesteel/c-minesweeper#dependencies)
* [Installing and Running](https://github.com/cbonesteel/c-minesweeper#installation-and-running)

[How to Play (In Release 0.1.0)](https://github.com/cbonesteel/c-minesweeper#how-to-play-in-release-010)
* [Starting a game](https://github.com/cbonesteel/c-minesweeper#starting-a-game)
* [Help Command](https://github.com/cbonesteel/c-minesweeper#help-command)
* [Reveal](https://github.com/cbonesteel/c-minesweeper#reveal)
* [Flag](https://github.com/cbonesteel/c-minesweeper#flag)
* [Guess](https://github.com/cbonesteel/c-minesweeper#guess)
* [No Fog](https://github.com/cbonesteel/c-minesweeper#no-fog)

[Roadmap](https://github.com/cbonesteel/c-minesweeper#roadmap)
* [Milestone 0.1](https://github.com/cbonesteel/c-minesweeper#milestone-01)
* [Milestone 0.2](https://github.com/cbonesteel/c-minesweeper#milestone-02)
* [Milestone 0.3](https://github.com/cbonesteel/c-minesweeper#milestone-03)
* [Milestone 0.4](https://github.com/cbonesteel/c-minesweeper#milestone-04)
* [Milestone 0.5](https://github.com/cbonesteel/c-minesweeper#milestone-05)
* [Milestone 0.6](https://github.com/cbonesteel/c-minesweeper#milestone-06)


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
> **NOTE:**
> This repository has only been run on macOS. The Makefile relies on Unix based commands
> such as mv, mkdir, etc. This repository may not work on Windows using these instructions. Windows
> instructions will be written after the project is finished.
1. In ~/your/path clone this repository
2. To compile, run the following command. The output should look similar to below.
``` console
system:c-minesweeper user$ make
mkdir build
mkdir build/board
mkdir build/game
mkdir build/menu
mkdir build/program
gcc -c src/game/game.c
mv game.o build/game/game.o
gcc -c src/board/board.c
mv board.o build/board/board.o
gcc -c src/game/command_processor.c
mv command_processor.o build/game/command_processor.o
gcc -c src/menu/menu.c
mv menu.o build/menu/menu.o
gcc -c src/program/program.c
mv program.o build/program/program.o
gcc -o minesweeper-game src/main.c build/board/board.o build/game/game.o build/game/command_processor.o build/menu/menu.o build/program/program.o
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

## How to Play (In Release 0.1.0)

### Starting a game
When you run the game you will be met with a simple welcome screen. To start the game
simply enter Y/Yes to start a 10x10 game with 20 mines. The game will then print the board
as shown below.
``` console
    __  ____           _____                                  
   /  |/  (_)___  ___ / ___/      _____  ___  ____  ___  _____
  / /|_/ / / __ \/ _ \\__ \ | /| / / _ \/ _ \/ __ \/ _ \/ ___/
 / /  / / / / / /  __/__/ / |/ |/ /  __/  __/ /_/ /  __/ /    
/_/  /_/_/_/ /_/\___/____/|__/|__/\___/\___/ .___/\___/_/     
                              coded in C  /_/ v. 0.1.0

Start New Game? Y/N: Y

* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 

Enter a command: 
```

### Help Command
If you forget the command structures during a game, you can type h/help to print
all of the available commands. The output will show like below.
``` console
Enter a command: help
Commands:
	r/reveal [row] [col]	Reveal a square
	m/mark [row] [col]		Flag a square
	g/guess [row] [col]		Guess a square
	h/help        		Print help
	q/quit        		Quit to menu
	c/close       		Quit the program
```

### Reveal
The reveal command is the first command that you will need in order to start finding mines.
Typing r/reveal and then the corresponding row and column will reveal a tile and print how many
mines are in adjacent tiles (This should be r/reveal [row] [col]. Any documentation that says [x] [y]
will be updated in the next release). A basic example of a reveal is shown below.
``` console
Enter a command: r 0 0

* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
1 * * * * * * * * *
```
As shown above, the tile in row 0, column 0 was revealed and revealed that there is one mine in
an adjacent tile, including diagnols. The reveal function is currently not recursive, meaning
revealing a tile with no adjacent mines will not reveal all tiles around it until there are no
more tiles with no adjacent mines. An example is shown below.
``` console
Enter a command: r 2 1

* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* 0 * * * * * * * * 
* * * * * * * * * * 
1 * * * * * * * * *
```

### Flag
Flagging is the essential tool to win the game once you find where the mines are. In order to win
all mines must be flagged but no additional flags must be present. This means, in this release, you
will need 20 flags to win. All tiles needing to be revealed is NOT a requirement to win. This means
the board below IS a valid win condition.
``` console
F * * * * * * * * F 
* * F F * * * * * * 
F * * * * F * * * F 
* * * F F * * * * * 
* * * * F * * * * F 
F * * * * * * * * * 
* * * * * * F * * * 
* * F * * * * * * * 
* F F * * * * * * F 
* * * F F * * * F * 
```
However, this is NOT a valid win condition as there are 21 flags. Tile (0,0) is flagged here unlike
the last output.
``` console
F * * * * * * * * F 
* * F F * * * * * * 
F * * * * F * * * F 
* * * F F * * * * * 
* * * * F * * * * F 
F * * * * * * * * * 
* * * * * * F * * * 
* * F * * * * * * * 
* F F * * * * * * F 
F * * F F * * * F * 
```
The flag command works exactly like the reveal function, being used as followed. Both f and flag is valid
command syntax.
``` console
Enter a command: f 1 1

* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* F * * * * * * * * 
* * * * * * * * * *
```

### Guess
You can guess where a mine might be without acutally flagging it by using both g and guess. A row
and column number are also required to run the command. The output will look like the output below.
``` console
Enter a command: g 1 1

* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * 
* F * * * * * * * * 
* * * * * * * * * *
```

### No Fog
No Fog is a hidden command used for debugging. This command removes the fog of war and shows all mines
on the board for one board print. The command and output is shown below.
``` console
Enter a command: noFog

@ * * * * * * * * @ 
* * @ @ * * * * * * 
@ * * * * @ * * * @ 
* * * @ @ * * * * * 
* * * * @ * * * * @ 
@ * * * * * * * * * 
* * * * * * @ * * * 
* * @ * * * * * * * 
* @ @ * * * * * * @ 
* * * @ @ * * * @ * 
```

## Roadmap

### Milestone 0.1
***RELEASED ON 22 NOV 2020***
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
  * Guess
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

### Milestone 0.6
* Recursive Reveal

<hr/>

![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey)

<small>
c-minesweeper by Cameron Bonesteel is licensed under CC BY 4.0. To view
a copy of this license, visit
https://creativecommons.org/licenses/by/4.0/
</small>