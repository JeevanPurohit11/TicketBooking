#include <iostream>
using namespace std;

const size_t ROWS{ 16 };
const size_t COLS{ 10 };
const char symBooked{ 'X' };
const char symAvail{ '.' };
const char initRowName{ 'A' };

bool seats[ROWS][COLS];
char rowNames[ROWS];
char inRow;
int inCol;

void Init()
{
    for (auto i{ 0 }; i < ROWS; i++)
    {
        for (auto j{ 0 }; j < COLS; j++)
            seats[i][j] = false;

        rowNames[i] = initRowName + i;
    }
}

void Display()
{
    //system("cls");
    cout << "Current status:" << endl;
    for (auto i{ 0 }; i < ROWS; i++)
    {
        for (auto j{ 0 }; j < COLS; j++)
            cout << (seats[i][j] ? symBooked : symAvail) << ' ';
        cout << "--> " << rowNames[i];
        cout << endl;
    }
    cout << endl;
    cout << "vvvvvvvvvvvvvvvvvv ---- Screen this way" << endl;
}

void TakeInput()
{
    std::cin >> inRow >> inCol;
}

void ProcessInput(bool n)
{
    int rowIndex{ static_cast<int>(inRow - initRowName) };
    int colIndex{ inCol - 1 };
    if (rowIndex >= 0 && rowIndex < ROWS && colIndex >= 0 && colIndex < COLS) {
        seats[rowIndex][colIndex] = n;
    } else {
        cout << "Invalid seat selection. Please try again." << endl;
    }
}

int main()
{
    bool isExist = true;
    Init();
    Display();
    
    while (isExist) {
        int ch;
        cout << "\nSelect option :- \n";
        cout << "1. Buy a ticket\n";
        cout << "2. Cancel ticket\n";
        cout << "3. Exit the app\n";
        cout << "Enter Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            TakeInput();
            if (inRow == 'Q' || inRow == 'q')
                break;
            ProcessInput(true);
            Display();
            break;
        case 2:
            TakeInput();
            if (inRow == 'Q' || inRow == 'q')
                break;
            ProcessInput(false);
            Display();
            break;
        case 3:
            isExist = false;
            cout << "Thank You For Visit...";
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}
