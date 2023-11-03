#include <iostream>
#include <string>
using namespace std;

void placeSymbol(char grid[26][39], int row, int column, char symbol) 
{
    if (row >= 0 && row < 26 && column >= 0 && column < 39) 
    {
        grid[row][column] = symbol;
    } 
    
    else 
    {
        cout << "Invalid coordinates. Please try again." << endl;
    }
}

void printGrid(char grid[26][39])
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 39; j++)
        {
            cout << grid[i][j];
        }
        
        cout << endl;
    }
}

bool occupiedGrid[26][39] = {false};

void playMove(char grid[26][39], int row, int column, char symbol)
{
    if (occupiedGrid[row][column])
    {
        cout << "\nA move has already been played there. Play your move in another box." << endl;
        cout << endl;
    }

    else
    {
        placeSymbol(grid, row, column, symbol);
        occupiedGrid[row][column] = true;
    }
    printGrid(grid);
}

int main() {

    const int rows = 26;
    const int columns = 39;

    char grid[rows][columns] = {
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' },
        { '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', ' ', '|', ' ', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', ' ', '|', ' ', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_' },
        { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' },
        { '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', ' ', '|', ' ', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', ' ', '|', ' ', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_' },
        { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' },
        { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' },
        { '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', ' ', '|', ' ', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', ' ', '|', ' ', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_' },
        { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' },
        { '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', ' ', '|', ' ', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', ' ', '|', ' ', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_' },
        { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' },
        { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' },
        { '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', ' ', '|', ' ', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', ' ', '|', ' ', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_' },
        { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' },
        { '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', ' ', '|', ' ', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', ' ', '|', ' ', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_' },
        { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' },
        { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }
    };

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    char symbol;
    int row, column;
    string userInput;

    while (true)
    {
        cout << "\nEnter where you want to play your move: ";

        cin >> userInput;
        cout << endl;

        if (userInput == "q")
        {
            break;
        }

        //inputs for the top left mini tic tac toe.
        if (userInput == "11X")
        {
            playMove(grid, 1, 1, 'X');
        }
        
        if (userInput == "11O")
        {
            playMove(grid, 1, 1, 'O');
        }

        if (userInput == "12X")
        {
            playMove(grid, 1, 5, 'X');
        }

        if (userInput == "12O")
        {
            playMove(grid, 1, 5, 'O');
        }

        if (userInput == "13X")
        {
            playMove(grid, 1, 9, 'X');
        }

        if (userInput == "13O")
        {
            playMove(grid, 1, 9, 'O');
        }

        if (userInput == "14X")
        {
            playMove(grid, 3, 1, 'X');
        }

        if (userInput == "14O")
        {
            playMove(grid, 3, 1, 'O');
        }

        if (userInput == "15X")
        {
            playMove(grid, 3, 5, 'X');
        }

        if (userInput == "15O")
        {
            playMove(grid, 3, 5, 'O');
        }
        
        if (userInput == "16X")
        {
            playMove(grid, 3, 9, 'X');
        }

        if (userInput == "16O")
        {
            playMove(grid, 3, 9, 'O');
        }
        
        if (userInput == "17X")
        {
            playMove(grid, 5, 1, 'X');
        }
        
        if (userInput == "17O")
        {
            playMove(grid, 5, 1, 'O');
        }
        
        if (userInput == "18X")
        {
            playMove(grid, 5, 5, 'X');
        }

        if (userInput == "18O")
        {
            playMove(grid, 5, 5, 'O');
        }

        if (userInput == "19X")
        {
            playMove(grid, 5, 9, 'X');
        }
        
        if (userInput == "19O")
        {
            playMove(grid, 5, 9, 'O');
        }
        
        //inputs for the top middle mini tic tac toe.
        if (userInput == "21X")
        {
            playMove(grid, 1, 15, 'X');
        }

        if (userInput == "21O")
        {
            playMove(grid, 1, 15, 'O');
        }
        
        if (userInput == "22X")
        {
            playMove(grid, 1, 19, 'X');
        }

        if (userInput == "22O")
        {
            playMove(grid, 1, 19, 'O');
        }
        
        if (userInput == "23X")
        {
            playMove(grid, 1, 23, 'X');
        }
        
        if (userInput == "23O")
        {
            playMove(grid, 1, 23, 'O');
        }

        if (userInput == "24X")
        {
            playMove(grid, 3, 15, 'X');
        }
        
        if (userInput == "24O")
        {
            playMove(grid, 3, 15, 'O');
        }
        
        if (userInput == "25X")
        {
            playMove(grid, 3, 19, 'X');
        }

        if (userInput == "25O")
        {
            playMove(grid, 3, 19, 'O');
        }

        if (userInput == "26X")
        {
            playMove(grid, 3, 23, 'X');
        }

        if (userInput == "26O")
        {
            playMove(grid, 3, 23, 'O');
        }
        
        if (userInput == "27X")
        {
            playMove(grid, 5, 15, 'X');
        }
        
        if (userInput == "27O")
        {
            playMove(grid, 5, 15, 'O');
        }

        if (userInput == "28X")
        {
            playMove(grid, 5, 19, 'X');
        }

        if (userInput == "28O")
        {
            playMove(grid, 5, 19, 'O');
        }
        
        if (userInput == "29X")
        {
            playMove(grid, 5, 23, 'X');
        }
        
        if (userInput == "29O")
        {
            playMove(grid, 5, 23, 'O');
        }
        
        //inputs for the top right mini tic tac toe.
        if (userInput == "31X")
        {
            playMove(grid, 1, 29, 'X');
        }

        if (userInput == "31O")
        {
            playMove(grid, 1, 29, 'O');
        }
        
        if (userInput == "32X")
        {
            playMove(grid, 1, 33, 'X');
        }
        
        if (userInput == "32O")
        {
            playMove(grid, 1, 33, 'O');
        }
        
        if (userInput == "33X")
        {
            playMove(grid, 1, 37, 'X');
        }

        if (userInput == "33O")
        {
            playMove(grid, 1, 37, 'O');
        }
        
        if (userInput == "34X")
        {
            playMove(grid, 3, 29, 'X');
        }
        
        if (userInput == "34O")
        {
            playMove(grid, 3, 29, 'O');
        }

        if (userInput == "35X")
        {
            playMove(grid, 3, 33, 'X');
        }
        
        if (userInput == "35O")
        {
            playMove(grid, 3, 33, 'O');
        }
        
        if (userInput == "36X")
        {
            playMove(grid, 3, 37, 'X');
        }
        
        if (userInput == "36O")
        {
            playMove(grid, 3, 37, 'O');
        }

        if (userInput == "37X")
        {
            playMove(grid, 5, 29, 'X');
        }

        if (userInput == "37O")
        {
            playMove(grid, 5, 29, 'O');
        }
        
        if (userInput == "38X")
        {
            playMove(grid, 5, 33, 'X');
        }
        
        if (userInput == "38O")
        {
            playMove(grid, 5, 33, 'O');
        }
        
        if (userInput == "39X")
        {
            playMove(grid, 5, 37, 'X');
        }

        if (userInput == "39O")
        {
            playMove(grid, 5, 37, 'O');
        }
        
        //inputs for the middle left mini tic tac toe.
        if (userInput == "41X")
        {
            playMove(grid, 10, 1, 'X');
        }
        
        if (userInput == "41O")
        {
            playMove(grid, 10, 1, 'O');
        }
        
        if (userInput == "42X")
        {
            playMove(grid, 10, 5, 'X');
        }
        
        if (userInput == "42O")
        {
            playMove(grid, 10, 5, 'O');
        }
        
        if (userInput == "43X")
        {
            playMove(grid, 10, 9, 'X');
        }
        
        if (userInput == "43O")
        {
            playMove(grid, 10, 9, 'O');
        }

        if (userInput == "44X")
        {
            playMove(grid, 12, 1, 'X');
        }

        if (userInput == "44O")
        {
            playMove(grid, 12, 1, 'O');
        }

        if (userInput == "45X")
        {
            playMove(grid, 12, 5, 'X');
        }
        
        if (userInput == "45O")
        {
            playMove(grid, 12, 5, 'O');
        }
        
        if (userInput == "46X")
        {
            playMove(grid, 12, 9, 'X');
        }

        if (userInput == "46O")
        {
            playMove(grid, 12, 9, 'O');
        }
        
        if (userInput == "47X")
        {
            playMove(grid, 14, 1, 'X');
        }
        
        if (userInput == "47O")
        {
            playMove(grid, 14, 1, 'O');
        }
        
        if (userInput == "48X")
        {
            playMove(grid, 14, 5, 'X');
        }
        
        if (userInput == "48O")
        {
            playMove(grid, 14, 5, 'O');
        }
        
        if (userInput == "49X")
        {
            playMove(grid, 14, 9, 'X');
        }
        
        if (userInput == "49O")
        {
            playMove(grid, 14, 9, 'O');
        }
        
        //inputs for the middle mini tic tac toe.
        if (userInput == "51X")
        {
            playMove(grid, 10, 15, 'X');
        }

        if (userInput == "51O")
        {
            playMove(grid, 10, 15, 'O');
        }
        
        if (userInput == "52X")
        {
            playMove(grid, 10, 19, 'X');
        }
        
        if (userInput == "52O")
        {
            playMove(grid, 10, 19, 'O');
        }
        
        if (userInput == "53X")
        {
            playMove(grid, 10, 23, 'X');
        }

        if (userInput == "53O")
        {
            playMove(grid, 10, 23, 'O');
        }
        
        if (userInput == "54X")
        {
            playMove(grid, 12, 15, 'X');
        }

        if (userInput == "54O")
        {
            playMove(grid, 12, 15, 'O');
        }

        if (userInput == "55X")
        {
            playMove(grid, 12, 19, 'X');
        }

        if (userInput == "55O")
        {
            playMove(grid, 12, 19, 'O');
        }
        
        if (userInput == "56X")
        {
            playMove(grid, 12, 23, 'X');
        }
        
        if (userInput == "56O")
        {
            playMove(grid, 12, 23, 'O');
        }

        if (userInput == "57X")
        {
            playMove(grid, 14, 15, 'X');
        }

        if (userInput == "57O")
        {
            playMove(grid, 14, 15, 'O');
        }
        
        if (userInput == "58X")
        {
            playMove(grid, 14, 19, 'X');
        }
        
        if (userInput == "58O")
        {
            playMove(grid, 14, 19, 'O');
        }
        
        if (userInput == "59X")
        {
            playMove(grid, 14, 23, 'X');
        }
        
        if (userInput == "59O")
        {
            playMove(grid, 14, 23, 'O');
        }
        
        //inputs for the middle left mini tic tac toe.
        if (userInput == "61X")
        {
            playMove(grid, 10, 29, 'X');
        }
        
        if (userInput == "61O")
        {
            playMove(grid, 10, 29, 'O');
        }
        
        if (userInput == "62X")
        {
            playMove(grid, 10, 33, 'X');
        }
        
        if (userInput == "62O")
        {
            playMove(grid, 10, 33, 'O');
        }
        
        if (userInput == "63X")
        {
            playMove(grid, 10, 37, 'X');
        }
        
        if (userInput == "63O")
        {
            playMove(grid, 10, 37, 'O');
        }
        
        if (userInput == "64X")
        {
            playMove(grid, 12, 29, 'X');
        }
        
        if (userInput == "64O")
        {
            playMove(grid, 12, 29, 'O');
        }
        
        if (userInput == "65X")
        {
            playMove(grid, 12, 33, 'X');
        }
        
        if (userInput == "65O")
        {
            playMove(grid, 12, 33, 'O');
        }
        
        if (userInput == "66X")
        {
            playMove(grid, 12, 37, 'X');
        }

        if (userInput == "66O")
        {
            playMove(grid, 12, 37, 'O');
        }
        
        if (userInput == "67X")
        {
            playMove(grid, 14, 29, 'X');
        }
        
        if (userInput == "67O")
        {
            playMove(grid, 14, 29, 'O');
        }
        
        if (userInput == "68X")
        {
            playMove(grid, 14, 33, 'X');
        }
        
        if (userInput == "68O")
        {
            playMove(grid, 14, 33, 'O');
        }
        
        if (userInput == "69X")
        {
            playMove(grid, 14, 37, 'X');
        }
        
        if (userInput == "69O")
        {
            playMove(grid, 14, 37, 'O');
        }
        
        //inputs for the bottom left mini tic tac toe.
        if (userInput == "71X")
        {
            playMove(grid, 19, 1, 'X');
        }
        
        if (userInput == "71O")
        {
            playMove(grid, 19, 1, 'O');
        }
        
        if (userInput == "72X")
        {
            playMove(grid, 19, 5, 'X');
        }
        
        if (userInput == "72O")
        {
            playMove(grid, 19, 5, 'O');
        }
        
        if (userInput == "73X")
        {
            playMove(grid, 19, 9, 'X');
        }
        
        if (userInput == "73O")
        {
            playMove(grid, 19, 9, 'O');
        }
        
        if (userInput == "74X")
        {
            playMove(grid, 21, 1, 'X');
        }
        
        if (userInput == "74O" )
        {
            playMove(grid, 21, 1, 'O');
        }

        if (userInput == "75X")
        {
            playMove(grid, 21, 5, 'X');
        }
        
        if (userInput == "75O")
        {
            playMove(grid, 21, 5, 'O');
        }
        
        if (userInput == "76X")
        {
            playMove(grid, 21, 9, 'X');
        }
        
        if (userInput == "76O")
        {
            playMove(grid, 21, 9, 'O');
        }
        
        if (userInput == "77X")
        {
            playMove(grid, 23, 1, 'X');
        }
        
        if (userInput == "77O")
        {
            playMove(grid, 23, 1, 'O');
        }
        
        if (userInput == "78X")
        {
            playMove(grid, 23, 5, 'X');
        }
        
        if (userInput == "78O")
        {
            playMove(grid, 23, 5, 'O');
        }
        
        if (userInput == "79X")
        {
            playMove(grid, 23, 9, 'X');
        }
        
        if (userInput == "79O")
        {
            playMove(grid, 23, 9, 'O');
        }
        
        //inputs for the bottom middle mini tic tac toe.
        if (userInput == "81X")
        {
            playMove(grid, 19, 15, 'X');
        }
        
        if (userInput == "81O")
        {
            playMove(grid, 19, 15, 'O');
        }
        
        if (userInput == "82X")
        {
            playMove(grid, 19, 19, 'X');
        }
        
        if (userInput == "82O")
        {
            playMove(grid, 19, 19, 'O');
        }

        if (userInput == "83X")
        {
            playMove(grid, 19, 23, 'X');
        }

        if (userInput == "83O")
        {
            playMove(grid, 19, 23, 'O');
        }
        
        if (userInput == "84X")
        {
            playMove(grid, 21, 15, 'X');
        }
        
        if (userInput == "84O")
        {
            playMove(grid, 21, 15, 'O');
        }
        
        if (userInput == "85X")
        {
            playMove(grid, 21, 19, 'X');
        }
        
        if (userInput == "85O")
        {
            playMove(grid, 21, 19, 'O');
        }

        if (userInput == "86X")
        {
            playMove(grid, 21, 23, 'X');
        }
        
        if (userInput == "86O")
        {
            playMove(grid, 21, 23, 'O');
        }
        
        if (userInput == "87X")
        {
            playMove(grid, 23, 15, 'X');
        }

        if (userInput == "87O")
        {
            playMove(grid, 23, 15, 'O');
        }
        
        if (userInput == "88X")
        {
            playMove(grid, 23, 19, 'X');
        }

        if (userInput == "88O")
        {
            playMove(grid, 23, 19, 'O');
        }
        
        if (userInput == "89X")
        {
            playMove(grid, 23, 23, 'X');
        }

        if (userInput == "89O")
        {
            playMove(grid, 23, 23, 'O');
        }
        
        //inputs for the bottom right mini tic tac toe.
        if (userInput == "91X")
        {
            playMove(grid, 19, 29, 'X');
        }

        if (userInput == "91O")
        {
            playMove(grid, 19, 29, 'O');
        }

        if (userInput == "92X")
        {
            playMove(grid, 19, 33, 'X');
        }
        
        if (userInput == "92O")
        {
            playMove(grid, 19, 33, 'O');
        }
        
        if (userInput == "93X")
        {
            playMove(grid, 19, 37, 'X');
        }
        
        if (userInput == "93O")
        {
            playMove(grid, 19, 37, 'O');
        }
        
        if (userInput == "94X")
        {
            playMove(grid, 21, 29, 'X');
        }
        
        if (userInput == "94O")
        {
            playMove(grid, 21, 29, 'O');
        }
        
        if (userInput == "95X")
        {
            playMove(grid, 21, 33, 'X');
        }
        
        if (userInput == "95O")
        {
            playMove(grid, 21, 33, 'O');
        }
        
        if (userInput == "96X")
        {
            playMove(grid, 21, 37, 'X');
        }
        
        if (userInput == "96O")
        {
            playMove(grid, 21, 37, 'O');
        }
        
        if (userInput == "97X")
        {
            playMove(grid, 23, 29, 'X');
        }
        
        if (userInput == "97O")
        {
            playMove(grid, 23, 29, 'O');
        }
        
        if (userInput == "98X")
        {
            playMove(grid, 23, 33, 'X');
        }

        if (userInput == "98O")
        {
            playMove(grid, 23, 33, 'O');
        }
        
        if (userInput == "99X")
        {
            playMove(grid, 23, 37, 'X');
        }

        if (userInput == "99O")
        {
            playMove(grid, 23, 37, 'O');
        }
        
    }

   return 0;
}
