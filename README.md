# Maze Game In C
This project is a 2D console maze game written in C programming language. The user can type the command to move the player ( W, A, S, D ). The players goal is to reach the  `x` to win the game.

W - UP
A - LEFT
S - DOWN
D - RIGHT

## Visibility Mode
The command line arguments determines the visibility range of the player of the map. Value of zero means that the whole map is always visible at all time. Any value greater than 0 defines the visibility range of the player in the square shape around it. For example, the value of 2 means that you can only see 5x5 square area around the player (2 blocks to the left, right, up, and down). 

This visibility feature will only be included if you activate the conditional compilation through makefile. If `DARK` is not defined, then the default behavior is to always print the whole map regardless the value of the integer.

![Game Interface](https://i.imgur.com/gAxeRMh.png)

### Indexed in Turn-It In Global Referencing Scheme

***This project should not be used for any coursework related activity and all codes have been submitted to `Turn-It In global referencing platform`, where usage of this code may be caught for Plagiarism.***
