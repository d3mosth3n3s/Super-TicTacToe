// Last Updated : 11/14/23
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printGrid(const vector<string> &grid) 
{
    for (const string &row : grid) 
    {
        cout << row << endl;
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
}

int getActualX(int outer, int inner)
{
    //partially solved (for first row only)
    //REMEMBER
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
        // cout << inner << " is more than 6 \n";
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
    // cout << getY(outer);
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

    //horizontal
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
        
        cout << "Player " << currentPlayer << "'s turn." << endl;
        cout << endl;

        if (nextGrid != -1)
        {
            cout << "Your move has to be in grid " << nextGrid << endl;
        } 
        
        else
        {
            cout << "You can play in any grid." << endl;
        }

        cout << "Enter your move (eg. 41): ";
        cin >> userInput;
        
        int userCoordinate = userInput;
        int firstDigit = userCoordinate / 10;
        int secondDigit = userCoordinate % 10;

        inner = secondDigit;
        outer = firstDigit;

        int selectedGrid = firstDigit;

        if (winnerArray[getY(selectedGrid)][getX(selectedGrid)] != 'D')
        {
            cout << "This grid has already been won. Choose another grid." << endl;
            skipSecondCondition = true;
            continue;
        }

        if (nextGrid != -1 && firstDigit != nextGrid)
        {
            cout << "Invalid move. Your move must be in grid " << prevSecondDigit << endl;
            continue;
        }

        skipSecondCondition = false;

        if (firstDigit == 0 || secondDigit == 0 || userInput > 99 || userInput < 11) 
        {
            cout << "The coordinate you entered is out of range. Please enter the right coordinate. " << endl;
            continue;
        }

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
            cout << "This box has already been played in. Play in another box." << endl;
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
        printGrid(vectorGrid);

        if (checkWin(vectorGrid, symbol, outer))
        {
            winnerArray[getY(selectedGrid)][getX(selectedGrid)] = symbol;
            cout << "Player " << symbol << " wins grid " << outer << endl;
        }

        // check if player won the whole game:
        if(checkWinFinal(winnerArray,symbol))
        {
            cout << "Player " << symbol << " has won the game!!!! GGWP!!.\n";
            break;
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
    
    cout << "Thanks for playing." << endl;

    return 0;
}
