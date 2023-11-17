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

int getY(int n)
{
    if(n >= 1 && n <= 3)
    {
        return 0;
    }

    if(n >= 4 && n <= 6)
    {
        return 1;
    }

    if(n >= 7 && n <= 9)
    {
        return 2;
    }

}

int getX(int n)
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

    if(inner > 6)
    {
        // cout << inner << " is more than 6 \n";
        x -= 6;
    } 
    
    else if(inner > 3)
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

    if(inner > 6)
    {
        y += 2;
    } 
    
    else if(inner > 3)
    {
        y += 1;
    }

    return y;
}

bool checkWinG1(const vector<string> &grid, char symbol)
{
    for (int i = 1; i <= 5; i += 2)
    {
        if (grid[i][1] == symbol && grid[i][5] == symbol && grid[i][9] == symbol)
        {
            return true;
        }
    }

    for (int i = 1; i <= 9; i += 4)
    {
        if (grid[1][i] == symbol && grid[3][i] == symbol && grid[5][i] == symbol)
        {
            return true;
        }
    }
    
    if ((grid[1][1] == symbol && grid[3][5] == symbol && grid[5][9] == symbol) ||
        (grid[5][1] == symbol && grid[3][5] == symbol && grid[1][9] == symbol))   
    {
        return true;
    }

    return false;
}

bool checkWinG2(const vector<string> &grid, char symbol)
{
    for (int i = 1; i <= 5; i += 2)
    {
        if (grid[i][15] == symbol && grid[i][19] == symbol && grid[i][23] == symbol)
        {
            return true;
        }
    }

    for (int i = 15; i <= 23; i += 4)
    {
        if (grid[1][i] == symbol && grid[3][i] == symbol && grid[5][i] == symbol)
        {
            return true;
        }
    }
    
    if ((grid[1][15] == symbol && grid[3][19] == symbol && grid[5][23] == symbol) ||
        (grid[5][15] == symbol && grid[3][19] == symbol && grid[1][23] == symbol))   
    {
        return true;
    }

    return false;
}

bool checkWinG3(const vector<string> &grid, char symbol)
{
    for (int i = 1; i <= 5; i += 2)
    {
        if (grid[i][29] == symbol && grid[i][33] == symbol && grid[i][37] == symbol)
        {
            return true;
        }
    }

    for (int i = 29; i <= 37; i += 4)
    {
        if (grid[1][i] == symbol && grid[3][i] == symbol && grid[5][i] == symbol)
        {
            return true;
        }
    }
    
    if ((grid[1][29] == symbol && grid[3][33] == symbol && grid[5][37] == symbol) ||
        (grid[5][37] == symbol && grid[3][33] == symbol && grid[1][29] == symbol))   
    {
        return true;
    }

    return false;
}

bool checkWinG4(const vector<string> &grid, char symbol)
{
    for (int i = 10; i <= 15; i += (i == 12 ? 3 : 2))
    {
        if (grid[i][1] == symbol && grid[i][5] == symbol && grid[i][9] == symbol)
        {
            return true;
        }
    }

    for (int i = 1; i <= 9; i += 4)
    {
        if (grid[10][i] == symbol && grid[12][i] == symbol && grid[15][i] == symbol)
        {
            return true;
        }
    }
    
    if ((grid[10][1] == symbol && grid[12][5] == symbol && grid[15][9] == symbol) ||
        (grid[15][1] == symbol && grid[12][5] == symbol && grid[10][9] == symbol))   
    {
        return true;
    }

    return false;
}

bool checkWinG5(const vector<string> &grid, char symbol)
{
    for (int i = 10; i <= 15; i += (i == 12 ? 3 : 2))
    {
        if (grid[i][15] == symbol && grid[i][19] == symbol && grid[i][23] == symbol)
        {
            return true;
        }
    }

    for (int i = 15; i <= 23; i += 4)
    {
        if (grid[10][i] == symbol && grid[12][i] == symbol && grid[15][i] == symbol)
        {
            return true;
        }
    }
    
    if ((grid[10][15] == symbol && grid[12][19] == symbol && grid[15][23] == symbol) ||
        (grid[15][15] == symbol && grid[12][19] == symbol && grid[10][23] == symbol))   
    {
        return true;
    }

    return false;
}

bool checkWinG6(const vector<string> &grid, char symbol)
{
    for (int i = 10; i <= 15; i += (i == 12 ? 3 : 2))
    {
        if (grid[i][29] == symbol && grid[i][33] == symbol && grid[i][37] == symbol)
        {
            return true;
        }
    }

    for (int i = 29; i <= 37; i += 4)
    {
        if (grid[10][i] == symbol && grid[12][i] == symbol && grid[15][i] == symbol)
        {
            return true;
        }
    }
    
    if ((grid[10][29] == symbol && grid[12][33] == symbol && grid[15][37] == symbol) ||
        (grid[15][37] == symbol && grid[12][33] == symbol && grid[10][29] == symbol))   
    {
        return true;
    }

    return false;
}

bool checkWinG7(const vector<string> &grid, char symbol)
{
    for (int i = 19; i <= 24; i += (i == 21 ? 3 : 2))
    {
        if (grid[i][1] == symbol && grid[i][5] == symbol && grid[i][9] == symbol)
        {
            return true;
        }
    }

    for (int i = 1; i <= 9; i += 4)
    {
        if (grid[19][i] == symbol && grid[21][i] == symbol && grid[24][i] == symbol)
        {
            return true;
        }
    }
    
    if ((grid[19][1] == symbol && grid[21][5] == symbol && grid[24][9] == symbol) ||
        (grid[24][1] == symbol && grid[21][5] == symbol && grid[19][9] == symbol))   
    {
        return true;
    }

    return false;
}

bool checkWinG8(const vector<string> &grid, char symbol)
{
    for (int i = 19; i <= 24; i += (i == 21 ? 3 : 2))
    {
        if (grid[i][15] == symbol && grid[i][19] == symbol && grid[i][23] == symbol)
        {
            return true;
        }
    }

    for (int i = 15; i <= 23; i += 4)
    {
        if (grid[19][i] == symbol && grid[21][i] == symbol && grid[24][i] == symbol)
        {
            return true;
        }
    }
    
    if ((grid[19][15] == symbol && grid[21][19] == symbol && grid[24][23] == symbol) ||
        (grid[24][15] == symbol && grid[21][19] == symbol && grid[19][23] == symbol))   
    {
        return true;
    }

    return false;
}

bool checkWinG9(const vector<string> &grid, char symbol)
{
    for (int i = 19; i <= 24; i += (i == 21 ? 3 : 2))
    {
        if (grid[i][29] == symbol && grid[i][33] == symbol && grid[i][37] == symbol)
        {
            return true;
        }
    }

    for (int i = 29; i <= 37; i += 4)
    {
        if (grid[19][i] == symbol && grid[21][i] == symbol && grid[24][i] == symbol)
        {
            return true;
        }
    }
    
    if ((grid[19][29] == symbol && grid[21][33] == symbol && grid[24][37] == symbol) ||
        (grid[24][37] == symbol && grid[21][33] == symbol && grid[19][29] == symbol))   
    {
        return true;
    }

    return false;
}

bool isGridWon(const vector<string> &grid, int gridNumber) {
    switch (gridNumber) {
        case 1:
            return checkWinG1(grid, 'X') || checkWinG1(grid, 'O');
        case 2:
            return checkWinG2(grid, 'X') || checkWinG2(grid, 'O');
        case 3:
            return checkWinG3(grid, 'X') || checkWinG3(grid, 'O');
        case 4:
            return checkWinG4(grid, 'X') || checkWinG4(grid, 'O');
        case 5:
            return checkWinG5(grid, 'X') || checkWinG5(grid, 'O');
        case 6:
            return checkWinG6(grid, 'X') || checkWinG6(grid, 'O');
        case 7:
            return checkWinG7(grid, 'X') || checkWinG7(grid, 'O');
        case 8:
            return checkWinG8(grid, 'X') || checkWinG8(grid, 'O');
        case 9:
            return checkWinG9(grid, 'X') || checkWinG9(grid, 'O');
        default:
            return false;
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

    while (true)
    {
        char currentPlayer = (moveCounter % 2 == 0) ? 'X' : 'O';
        
        cout << "Player " << currentPlayer << "'s turn." << endl;

        cout << endl;
        cout << "Enter your move (eg. 41): ";
        cin >> userInput;

        int userCoordinate = userInput;
        int firstDigit = userCoordinate / 10;
        int secondDigit = userCoordinate % 10;

        inner = secondDigit;
        outer = firstDigit;

        int selectedGrid = firstDigit;

        if (isGridWon(vectorGrid, selectedGrid))
        {
            cout << "This grid has already been won. Choose another grid." << endl;
            skipSecondCondition = true;
            continue;
        }

        if (!skipSecondCondition && prevSecondDigit != -1 && prevSecondDigit != outer)
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

        vectorGrid[static_cast<int>(userRow * adjustedRowMultiplier + adjustedRow)][userColumn * adjustedColumnMultiplier + adjustedColumn] = symbol;

        cout << endl;
        printGrid(vectorGrid);

        if (checkWinG1(vectorGrid, symbol))
        {
            cout << "Player " << symbol << " wins the first grid!" << endl;
        }

        if (checkWinG2(vectorGrid, symbol))
        {
            cout << "Player " << symbol << " wins the first grid!" << endl;
        }

        if (checkWinG3(vectorGrid, symbol))
        {
            cout << "Player " << symbol << " wins the first grid!" << endl;
        }

        if (checkWinG4(vectorGrid, symbol))
        {
            cout << "Player " << symbol << " wins the first grid!" << endl;
        }

        if (checkWinG5(vectorGrid, symbol))
        {
            cout << "Player " << symbol << " wins the first grid!" << endl;
        }

        if (checkWinG6(vectorGrid, symbol))
        {
            cout << "Player " << symbol << " wins the first grid!" << endl;
        }

        if (checkWinG7(vectorGrid, symbol))
        {
            cout << "Player " << symbol << " wins the first grid!" << endl;
        }

        if (checkWinG8(vectorGrid, symbol))
        {
            cout << "Player " << symbol << " wins the first grid!" << endl;
        }

        if (checkWinG9(vectorGrid, symbol))
        {
            cout << "Player " << symbol << " wins the first grid!" << endl;
        }

        prevSecondDigit = inner;

        moveCounter++;
    }
    
    return 0;
}
