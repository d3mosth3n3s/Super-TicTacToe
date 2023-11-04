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
    char symbol;

    while (true)
    {
        cout << endl;
        cout << "Enter row: ";
        cin >> userRow;
        cout << "Enter column: ";
        cin >> userColumn;
        cout << "Enter symbol ('X' or 'O'): ";
        cin >> symbol;

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
