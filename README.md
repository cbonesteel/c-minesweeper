# c-minesweeper

![Project Status: Indefinitely Delayed](https://img.shields.io/badge/Project%20Status-Indefinitely%20Delayed-red)
![Version: 0.5.0](https://img.shields.io/badge/Version-0.5.0-brightgreen)
![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-brightgreen)

## Table of Contents
[Project Description](https://github.com/cbonesteel/c-minesweeper#project-description)

[Installing this Repository](https://github.com/cbonesteel/c-minesweeper#installing-this-repository)
* [Dependencies](https://github.com/cbonesteel/c-minesweeper#dependencies)
* [Installing and Running](https://github.com/cbonesteel/c-minesweeper#installation-and-running)

[How to Play (In Release 0.5.0)](https://github.com/cbonesteel/c-minesweeper#how-to-play-in-release-050)
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
* [Milestone 0.7](https://github.com/cbonesteel/c-minesweeper#milestone-07)
* [Milestone 0.8](https://github.com/cbonesteel/c-minesweeper#milestone-08)
* [Milestone 0.9](https://github.com/cbonesteel/c-minesweeper#milestone-09)
* [Milestone 1.0](https://github.com/cbonesteel/c-minesweeper#milestone-10)

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

## How To Play (In Release 0.5.0)

### Starting a game
When you start the game, you will be met with a welcome screen asking if you
would like to start a game. Entering Y will take you to the game options, entering
N closes the game. After entering Y, you can enter your gameboards height and width
as well as the number of mines. You may have up to 26% of the boards area covered
in mines, but remember, more mines equals a harder game.
``` console
    __  ____           _____                                  
   /  |/  (_)___  ___ / ___/      _____  ___  ____  ___  _____
  / /|_/ / / __ \/ _ \\__ \ | /| / / _ \/ _ \/ __ \/ _ \/ ___/
 / /  / / / / / /  __/__/ / |/ |/ /  __/  __/ /_/ /  __/ /    
/_/  /_/_/_/ /_/\___/____/|__/|__/\___/\___/ .___/\___/_/     
                              coded in C  /_/ v. 0.5.0

Start New Game? Y/N: Y

Enter Height (Max 24): 10

Enter Width (Max 32): 10

Enter Mines (Up to 26 percent of board area, max 200): 20

Turn: 0
 9 [*][*][*][*][*][*][*][*][*][*]
 8 [*][*][*][*][*][*][*][*][*][*]
 7 [*][*][*][*][*][*][*][*][*][*]
 6 [*][*][*][*][*][*][*][*][*][*]
 5 [*][*][*][*][*][*][*][*][*][*]
 4 [*][*][*][*][*][*][*][*][*][*]
 3 [*][*][*][*][*][*][*][*][*][*]
 2 [*][*][*][*][*][*][*][*][*][*]
 1 [*][*][*][*][*][*][*][*][*][*]
 0 [*][*][*][*][*][*][*][*][*][*]
    0  1  2  3  4  5  6  7  8  9  
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

Turn: 1
 9 [*][*][*][*][*][*][*][*][*][*]
 8 [*][*][*][*][*][*][*][*][*][*]
 7 [*][*][*][*][*][*][*][*][*][*]
 6 [*][*][*][*][*][*][*][*][*][*]
 5 [*][*][*][*][*][*][*][*][*][*]
 4 [*][*][*][*][*][*][*][*][*][*]
 3 [*][*][*][*][*][*][*][*][*][*]
 2 [*][*][*][*][*][*][*][*][*][*]
 1 [*][*][*][*][*][*][*][*][*][*]
 0 [1][*][*][*][*][*][*][*][*][*]
    0  1  2  3  4  5  6  7  8  9 
```
As shown above, the tile in row 0, column 0 was revealed and revealed that there is one mine in
an adjacent tile, including diagnols. The reveal function is recursive, meaning if you reveal a tile
with 0 mines adjacent, it will reveal all tiles around it until there are no more tiles with no adjacent
mines. An example is shown below, where 2 1 is revealed and 0 0 is already revealed.
``` console
Enter a command: r 2 1

Turn: 2
 9 [*][*][*][*][*][*][*][*][*][*]
 8 [*][*][*][*][*][*][*][*][*][*]
 7 [*][*][*][*][*][*][*][*][*][*]
 6 [*][*][*][*][*][*][*][*][*][*]
 5 [1][3][*][*][*][*][*][*][*][*]
 4 [0][1][*][*][*][*][*][*][*][*]
 3 [0][2][1][*][*][*][*][*][*][*]
 2 [0][0][1][*][*][*][*][*][*][*]
 1 [1][1][1][*][*][*][*][*][*][*]
 0 [1][*][*][*][*][*][*][*][*][*]
    0  1  2  3  4  5  6  7  8  9  
```

### Flag
Flagging is the essential tool to win the game once you find where the mines are. In order to win
all mines must be flagged but no additional flags must be present. This means, in this release, you
will need 20 flags to win. All tiles needing to be revealed is NOT a requirement to win. This means
the board below IS a valid win condition.
``` console
 9 [F][*][*][*][*][*][*][*][*][F]
 8 [*][*][F][F][*][*][*][*][*][*]
 7 [F][*][*][*][*][F][*][*][*][F]
 6 [*][*][*][F][F][*][*][*][*][*]
 5 [*][*][*][*][F][*][*][*][*][F]
 4 [F][*][*][*][*][*][*][*][*][*]
 3 [*][*][*][*][*][*][F][*][*][*]
 2 [*][*][F][*][*][*][*][*][*][*]
 1 [*][F][F][*][*][*][*][*][*][F]
 0 [*][*][*][F][F][*][*][*][F][*]
    0  1  2  3  4  5  6  7  8  9
```
However, this is NOT a valid win condition as there are 21 flags. Tile (0,0) is flagged here unlike
the last output.
``` console
 9 [F][*][*][*][*][*][*][*][*][F]
 8 [*][*][F][F][*][*][*][*][*][*]
 7 [F][*][*][*][*][F][*][*][*][F]
 6 [*][*][*][F][F][*][*][*][*][*]
 5 [*][*][*][*][F][*][*][*][*][F]
 4 [F][*][*][*][*][*][*][*][*][*]
 3 [*][*][*][*][*][*][F][*][*][*]
 2 [*][*][F][*][*][*][*][*][*][*]
 1 [*][F][F][*][*][*][*][*][*][F]
 0 [F][*][*][F][F][*][*][*][F][*]
    0  1  2  3  4  5  6  7  8  9
```
The flag command works exactly like the reveal function, being used as followed. Both f and flag is valid
command syntax.
``` console
Enter a command: f 1 1

Turn: 1
 9 [*][*][*][*][*][*][*][*][*][*]
 8 [*][*][*][*][*][*][*][*][*][*]
 7 [*][*][*][*][*][*][*][*][*][*]
 6 [*][*][*][*][*][*][*][*][*][*]
 5 [*][*][*][*][*][*][*][*][*][*]
 4 [*][*][*][*][*][*][*][*][*][*]
 3 [*][*][*][*][*][*][*][*][*][*]
 2 [*][*][*][*][*][*][*][*][*][*]
 1 [*][F][*][*][*][*][*][*][*][*]
 0 [*][*][*][*][*][*][*][*][*][*]
    0  1  2  3  4  5  6  7  8  9
```

### Guess
You can guess where a mine might be without acutally flagging it by using both g and guess. A row
and column number are also required to run the command. The output will look like the output below.
``` console
Enter a command: g 1 1

Turn: 1
 9 [*][*][*][*][*][*][*][*][*][*]
 8 [*][*][*][*][*][*][*][*][*][*]
 7 [*][*][*][*][*][*][*][*][*][*]
 6 [*][*][*][*][*][*][*][*][*][*]
 5 [*][*][*][*][*][*][*][*][*][*]
 4 [*][*][*][*][*][*][*][*][*][*]
 3 [*][*][*][*][*][*][*][*][*][*]
 2 [*][*][*][*][*][*][*][*][*][*]
 1 [*][?][*][*][*][*][*][*][*][*]
 0 [*][*][*][*][*][*][*][*][*][*]
    0  1  2  3  4  5  6  7  8  9
```

### No Fog
No Fog is a hidden command used for debugging. This command removes the fog of war and shows all mines
on the board for one board print. The command and output is shown below.
``` console
Enter a command: noFog

Turn: 1
 9 [*][*][*][*][*][*][*][*][*][*]
 8 [*][*][*][@][*][*][@][*][*][@]
 7 [*][@][@][*][*][*][*][*][*][*]
 6 [*][*][*][*][*][*][@][*][*][@]
 5 [*][*][*][*][*][*][*][*][*][*]
 4 [@][*][*][*][*][*][*][@][*][@]
 3 [*][@][@][*][*][*][*][*][*][*]
 2 [@][@][*][*][*][*][*][*][*][@]
 1 [*][*][*][*][*][*][*][*][*][@]
 0 [*][@][*][*][@][*][@][*][@][*]
    0  1  2  3  4  5  6  7  8  9   
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
***RELEASED ON 24 NOV 2020***
* Create game loop to be able to play many games on one run
* Add extra game functions
  * Guess
  * Quit game to menu
  * Quit game

### Milestone 0.3
***RELEASED ON 28 NOV 2020***
* Add nicer looking board
* Add point system
* Print score at end of game

### Milestone 0.4
***RELEASED ON 20 DEC 2020***
* Add game menu for custom sizes
* Add custom difficulty options

###  Milestone 0.5
***RELEASED ON 05 FEB 2021***
* Recursive Reveal

### Minestone 0.6
* Add new scoring system (Maybe based on time)
* Add highscores to menu

### Milestone 0.7
* Cleanup Formatting
* Make final style choices

### Milestone 0.8
* Add GUI Prototype

### Milestone 0.9
* Make final GUI style choices

### Milestone 1.0
* Check program for bugs
* Add any last minute features
* RELEASE FIRST FULL VERSION

###

<hr/>

![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey)

<small>
c-minesweeper by Cameron Bonesteel is licensed under CC BY 4.0. To view
a copy of this license, visit
https://creativecommons.org/licenses/by/4.0/
</small>