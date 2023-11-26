#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
#include <limits>
using namespace std;

void printGrid(const vector<string> &grid)
{
    for (const string &row : grid)
    {
        for (char c : row)
        {
            if (c == 'X') 
            {
                cout << "\x1b[31m" << c << "\x1b[0m"; 
            }

            else if (c == 'O') 
            {    
                cout << "\x1b[34m" << c << "\x1b[0m"; 
            } 
            
            else 
            {
                cout << c;
            }
        }
        
        cout << endl;
    }
}

int getY (int n)
{
    if (n >= 1 && n <= 3)
    {
        return 0;
    }

    if (n >= 4 && n <= 6)
    {
        return 1;
    }

    if (n >= 7 && n <= 9)
    {
        return 2;
    }

    return -1;
}

int getX (int n)
{
    // 1 4 7 >>> 0 ;mod 3 = 1
    // 2 5 8 >>> 1 ;mod 3 = 2
    // 3 6 9 >>> 2 ;mod 3 = 0

    int rem = n % 3;

    switch (rem) {
        case 0:
            return 2;
        case 1:
            return 0;
        case 2:
            return 1;
    }

    return -1;
}

int getActualX(int outer, int inner)
{
    // 2 -> 6
    // 0 -> 0
    // 1 -> 3

    int ref, x = 0;
    
    switch (getX(outer)) {
        case 0:
            ref = 0;
            break;
        case 1:
            ref = 3;
            break;
        case 2:
            ref = 6;
            break;
    }

    x = ref + inner;

    if (inner > 6)
    {
        x -= 6;
    } 
    
    else if (inner > 3)
    {
        x -= 3;
    }

    return x;
}

int getActualY(int outer, int inner)
{
    int ref, y = 0;
    
    switch (getY(outer)) {
        case 0:
            ref = 1;
            break;
        case 1:
            ref = 4;
            break;
        case 2:
            ref = 7;
            break;
    }

    y = ref;

    if (inner > 6)
    {
        y += 2;
    } 
    
    else if (inner > 3)
    {
        y += 1;
    }

    return y;
}

bool checkWin(const vector<string> &grid, char symbol, int subgrid)
{
    int horizontal[9] = {1, 5, 9, 15, 19, 23, 29, 33, 37};
    int vertical[9] = {1, 3, 5, 10, 12, 15, 19, 21, 24};

    int vertical_start = getY(subgrid) * 3; //0,1,2
    int horizontal_start =  getX(subgrid) * 3; // 0,1,2

    bool won = true;

    // vertical
    for (int i = vertical_start; i <= vertical_start + 2; i++) // y axis
    {
        if (grid[vertical[i]][horizontal[horizontal_start]] == symbol && grid[vertical[i]][horizontal[horizontal_start+1]] == symbol && grid[vertical[i]][horizontal[horizontal_start+2]] == symbol)
        {
            return true;
        }
    }

    //horizontal
    for (int i = horizontal_start; i <= horizontal_start + 2; i++) // x axis
    {
        if (grid[vertical[vertical_start]][horizontal[i]] == symbol && grid[vertical[vertical_start+1]][horizontal[i]] == symbol && grid[vertical[vertical_start+2]][horizontal[i]] == symbol)
        {
            return true;
        }
    }

    // diagonal
    if ((grid[vertical[vertical_start]][horizontal[horizontal_start]] == symbol && grid[vertical[vertical_start+1]][horizontal[horizontal_start+1]] == symbol && grid[vertical[vertical_start+2]][horizontal[horizontal_start+2]] == symbol) ||
        (grid[vertical[vertical_start+2]][horizontal[horizontal_start]] == symbol && grid[vertical[vertical_start+1]][horizontal[horizontal_start+1]] == symbol && grid[vertical[vertical_start]][horizontal[horizontal_start+2]] == symbol))   
    {
        return true;
    }

    return false;
}

bool checkWinFinal(char grid[3][3], char symbol)
{
    // vertical win
    for (int i = 0; i <= 2; i += 1)
    {
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol)
        {
            return true;
        }
    }

    // horizontal
    for (int i = 0; i <= 2; i += 1)
    {
        if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)
        {
            return true;
        }
    }

    // diagonal
    if ((grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) ||
        (grid[2][0] == symbol && grid[1][1] == symbol && grid[0][2] == symbol))   
    {
        return true;
    }

    return false;
}

void clearConsole() 
{
    for (int i = 0; i < 100; ++i) 
    {
        cout << endl;
    }
}

int getUserInput() 
{
    string userInput;
    while (true) 
    {
        cout << "\nEnter your move (eg. 41): ";
        cin >> userInput;

        bool validInput = true;
        
        for (char c : userInput) 
        {
            if (!isdigit(c)) 
            {
                validInput = false;
                break;
            }
        }

        if (validInput) 
        {
            stringstream ss(userInput);
            int move;
            if (ss >> move) 
            {
                return move;
            }
        }

        cout << "\nInvalid input. Please enter a valid coordinate." << endl;
        cout << "______________________________________________________" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {

    vector<string> vectorGrid = {
        "            |             |            ",
        "   |   |    |    |   |    |    |   |   ",
        "___|___|___ | ___|___|___ | ___|___|___",
        "   |   |    |    |   |    |    |   |   ",
        "___|___|___ | ___|___|___ | ___|___|___",
        "   |   |    |    |   |    |    |   |   ",
        "   |   |    |    |   |    |    |   |   ",
        "            |             |            ",
        "_______________________________________",
        "            |             |            ",
        "   |   |    |    |   |    |    |   |   ",
        "___|___|___ | ___|___|___ | ___|___|___",
        "   |   |    |    |   |    |    |   |   ",
        "___|___|___ | ___|___|___ | ___|___|___",
        "   |   |    |    |   |    |    |   |   ",
        "   |   |    |    |   |    |    |   |   ",
        "            |             |            ",
        "_______________________________________",
        "            |             |            ",
        "   |   |    |    |   |    |    |   |   ",
        "___|___|___ | ___|___|___ | ___|___|___",
        "   |   |    |    |   |    |    |   |   ",
        "___|___|___ | ___|___|___ | ___|___|___",
        "   |   |    |    |   |    |    |   |   ",
        "   |   |    |    |   |    |    |   |   ",
        "            |             |            "
    };

    printGrid(vectorGrid);

    int userRow, userColumn;
    int inner, outer, userInput;
    char symbol;

    int moveCounter = 0;
    int prevSecondDigit = -1;

    bool skipSecondCondition = false;

    vector<vector<bool>> boxPlayed(9, vector<bool>(9, false));

    char winnerArray[3][3] = {{'D', 'D', 'D'}, {'D', 'D', 'D'}, {'D', 'D', 'D'}};
    int nextGrid = -1;

    while (true)
    {
        char currentPlayer = (moveCounter % 2 == 0) ? 'X' : 'O';
        
        cout << "______________________________________________________" << endl;
        cout << "\nPlayer " << currentPlayer << "'s turn.";
        cout << endl;

        if (nextGrid != -1)
        {
            cout << "\nYour move has to be in grid " << nextGrid << endl;
        } 
        
        else
        {
            cout << "\nYou can play in any grid." << endl;
        }

        int userInput = getUserInput();
        
        int userCoordinate = userInput;
        int firstDigit = userCoordinate / 10;
        int secondDigit = userCoordinate % 10;

        inner = secondDigit;
        outer = firstDigit;

        if (firstDigit == 0 || secondDigit == 0 || userInput > 99 || userInput < 11) 
        {
            cout << "\nThe coordinate you entered is out of range. Please enter the right coordinate. " << endl;
            cout << "______________________________________________________" << endl;
            continue;
        }

        int selectedGrid = firstDigit;

        if (winnerArray[getY(selectedGrid)][getX(selectedGrid)] != 'D')
        {
            cout << "\nThis grid has already been drawn or won. Choose another grid." << endl;
            cout << "______________________________________________________" << endl;
            skipSecondCondition = true;
            continue;
        }

        if (nextGrid != -1 && firstDigit != nextGrid)
        {
            cout << "\nInvalid move. Your move must be in grid " << prevSecondDigit << endl;
            cout << "______________________________________________________" << endl;
            continue;
        }

        skipSecondCondition = false;

        if (moveCounter % 2 == 0) 
        {
            symbol = 'X'; 
        } 

        else 
        {
            symbol = 'O'; 
        }

        userRow = getActualY(outer,inner);
        userColumn = getActualX(outer,inner);

        if (boxPlayed[userRow - 1][userColumn - 1]) 
        {
            cout << "\nThis box has already been played in. Play in another box." << endl;
            cout << "______________________________________________________" << endl;
            continue;
        }

        boxPlayed[userRow - 1][userColumn - 1] = true;

        double adjustedRow = 1.0;
        int adjustedRowMultiplier = 3;

        switch (userRow) {
            case 2:
            case 3:
                adjustedRowMultiplier = 2;
                break;
            case 5:
            case 8:
                adjustedRow -= 0.1;
                break;
            case 6:
            case 9:
                adjustedRow -= 0.2;
                break;
            default:
                break;
        }

        double adjustedColumn = 1.0;
        int adjustedColumnMultiplier = 4;

        switch (userColumn) {
            case 4:
            case 5:
            case 6:
                adjustedColumn = 3;
                break;
            case 7:
            case 8:
            case 9:
                adjustedColumn = 5;
                break;
            default:
                break;
        }  

        userRow--;
        userColumn--;

        // play accepted
        vectorGrid[static_cast<int>(userRow * adjustedRowMultiplier + adjustedRow)][userColumn * adjustedColumnMultiplier + adjustedColumn] = symbol;
        
        cout << endl;
        clearConsole();
        printGrid(vectorGrid);

        if (checkWin(vectorGrid, symbol, outer))
        {
            winnerArray[getY(selectedGrid)][getX(selectedGrid)] = symbol;
            cout << "\nPlayer " << symbol << " wins grid " << outer << endl;
            cout << "______________________________________________________" << endl;
        }

        bool currentGridFullyPlayed = true;
        
        for (int i = 0; i < 9; ++i) 
        {
            int y = getY(outer) * 3 + i / 3;
            int x = getX(outer) * 3 + i % 3;
            
            if (!boxPlayed[y][x]) 
            {
                currentGridFullyPlayed = false;
                break;
            }
        }

        // check for a draw in the current grid
        if (currentGridFullyPlayed) 
        {
            if (!checkWin(vectorGrid, 'X', outer) && !checkWin(vectorGrid, 'O', outer)) 
            {
                cout << "\nGrid " << outer << " is a draw!" << endl;
                cout << "______________________________________________________" << endl;

                winnerArray[getY(outer)][getX(outer)] = 'A';
            }
        }

        bool allGridsFilled = true;

        for (int i = 0; i < 9; ++i) 
        {
            if (winnerArray[i / 3][i % 3] == 'D') 
            {
                allGridsFilled = false;
                break;
            }
        }

        if (allGridsFilled && !checkWinFinal(winnerArray, 'X') && !checkWinFinal(winnerArray, 'O')) 
        {
            cout << "\nThe game is a draw!" << endl;
            cout << "______________________________________________________" << endl;
            break; // End the game
        }

        // check if player won the whole game:
        if (checkWinFinal(winnerArray, symbol))
        {
            cout << "\nPlayer " << symbol << " has won the game!!!! GGWP!!.\n";
            cout << "______________________________________________________" << endl;
            break;
        }

        if (winnerArray[getY(outer)][getX(outer)] == 'A')
        {
            nextGrid = -1;
        }

        if (winnerArray[getY(secondDigit)][getX(secondDigit)] == 'D')
        {
            nextGrid = secondDigit;
        }

        else
        {
            // the next grid has already been won
            nextGrid = -1;
        }

        prevSecondDigit = inner;

        moveCounter++;
    }
    
    cout << "\nThanks for playing." << endl;
    cout << endl;

    return 0;
}
