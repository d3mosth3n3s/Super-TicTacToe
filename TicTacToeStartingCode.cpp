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
    int inner, outer;
    char symbol;

    while (true)
    {
        cout << endl;
        cout << "Enter outer: ";
        cin >> outer;
        cout << "Enter inner: ";
        cin >> inner;
        cout << "Enter symbol ('X' or 'O'): ";
        cin >> symbol;

        userRow = getActualY(outer,inner);
        userColumn = getActualX(outer,inner);

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
    }
    
    return 0;
}
