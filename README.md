# c-minesweeper

![Project Status: In Development](https://img.shields.io/badge/Project%20Status-In%20Development-brightgreen)

## Project Description
This project is a personal programming project with a focus on learning how to use C. The
program is a basic command line game of minesweeper with user input being text inputs.

The minesweeper game will allow for custom board sizes and difficulty, difficulty being
defined by mine density. All user inputs will be used in the form [letter] [x] [y]. The letter
will define the specific game command, flag, reveil, help, etc., with x and y being the
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
1. In ~/your/path clone this repository
2. To compile, run the following command. The output should look similar to below.
``` console
system:c-minesweeper user$ make
cc  -I/usr/local/opt/icu4c/include:-I/usr/local/opt/ruby/include:  -c -o minesweeper/board/board.o minesweeper/board/board.c
gcc -o minesweeper-game minesweeper/main.c minesweeper/board/board.o
```
3. To run, simply execute the generated executable minesweeper-game as follows.
``` console
system:c-minesweeper user$ ./minesweeper-game
```
4. To clean the directory, run the following command. The output should look simialr to below.
``` console
system:c-minesweeper user$ make clean
rm minesweeper/board/*.o minesweeper-game
```


## Roadmap

TO BE COMPLETED


<hr/>

![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey)

<small>
c-minesweeper by Cameron Bonesteel is licensed under CC BY 4.0. To view
a copy of this license, visit
https://creativecommons.org/licenses/by/4.0/
</small>