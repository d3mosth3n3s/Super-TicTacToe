Purpose: 
The purpose of the program is to make a game called Super/Ultimate Tic-Tac-Toe, something different to the traditional Tic-Tac-Toe game

Command Prompt Version
On how to build/run the command prompt version of this game, you first download the TicTacToeStartingCode.cpp file in the Super-TicTacToe repository and run it in an IDE of your
choosing; just as you would run any prior program you’ve constructed in the past. 

Rules:
Super TicTacToe has essentially two parts, an inner and outer TicTacToe grid. The game is played on a 9x9 grid which consists of 9 boxes of 3x3 grids. The first player, ‘X’, 
is allowed to make their first move in any of the 81 boxes. The second player's move, ‘O’,  is determined by the previous move made by ‘X’. An example of this is if the player 
for ‘X’ placed their marker on the 4th box of the 3x3 grid, the player using ‘O’ would have to play their next move in the outer TicTacToe 4th grid. This is done over and over, 
each move being determined by the previous, until one player wins a 3x3 grid; either horizontally, vertically, or diagonally. A draw is also possible. If the previous move directs 
the current player to play in a box that has already been won or drawn, they can place a mark on the grid of their choosing. The game has a chosen winner if the outer grid is 
overtaken by 3 markers horizontally, vertically, or diagonally. Again, a tie is also possible. 

Note: If the user's input is "41," this would translate as the 4th outer grid and the 1st box in that grid. 
The first digit always represents one of the smaller 3x3 grids and the second digit represents where on that 3x3 grid the marker is placed. 
