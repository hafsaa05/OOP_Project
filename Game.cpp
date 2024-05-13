#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <ctime>
#include <bitset>
#include <stdexcept> // For exception handling

using namespace std;

class MemoryGameFinal {
protected:
    int points = 0, point = 0;
    string firstName;
    char difficulty;
    int column, row, row1Value, column1Value, row2Value, column2Value, matrix[4][4];
    int menu;
    bool again = true;
    bool matrix2[4][4];
    static HANDLE color;

public:
    virtual void display() const {
        // Function to display the game board
        cout << "    1 2 3 4" << endl;
        cout << "  ";

        for (int i = 0; i <= 8; i++) {
            cout << "-";
        }
        cout << endl;

        for (int row = 0; row < 4; row++) {
            cout << row + 1 << " | ";

            for (int column = 0; column < 4; column++) {
                if (matrix2[row][column]) {
                    cout << matrix[row][column];
                } else {
                    cout << '*';
                }
                cout << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    virtual void start() {
        SetConsoleTextAttribute(color, 9);
        cout << "\t\t\tWELCOME TO CardCraft - A MEMORY CARD GAME" << endl
             << endl;

        SetConsoleTextAttribute(color, 7);
        cout << "Please enter your first name: ";
        cin >> firstName;

        while (again) {
            cout << "--------------------------------------" << endl;
            cout << "\t\tWelcome, " << firstName << "!" << endl;
            cout << endl;
            cout << "Game Menu" << endl;
            cout << " ********" << endl;
            cout << "Select 1 for a New Game and 2 to Exit Game" << endl;
            cout << "1. New Game" << endl;
            cout << "2. Exit Game" << endl;
            cout << " ********" << endl;
            cin >> menu;

            if (menu == 2) {
                cout << endl;
                cout << "Would you like to play Memory - The Card Game again?" << endl;
                cout << "Type '1' to play again and '0' to leave" << endl;
                cin >> again;
                cout << endl;
            } else if (menu == 1) {
                cout<<"\t\t\tYou need 16 points to win the game!"<<endl;
                cout << "\t\t\t\tLET THE GAME BEGIN!" << endl<<endl;
                cout << "Enter (y) to proceed with the game!" << endl;

                cin >> difficulty;

                switch (difficulty) {
                    case 'y':
                        srand((unsigned int) time(NULL));

                        for (int row = 0; row < 4; row++) {
                            for (int column = 0; column < 4; column++) {
                                matrix[row][column] = rand() % 8 + 1;
                                matrix2[row][column] = false;
                            }
                            cout << endl;
                        }
                        cout << "Points: " << points << endl;

                        display();
                        Loop();
                        break;
                }
            }
        }
    }

    void Loop() {
        while (points != 16) {
            cout << firstName << ", please enter a row value for first card: " << endl;
            cin >> row1Value;

            cout << firstName << ", please enter a column value for first card: " << endl;
            cin >> column1Value;

            cout << firstName << ", please enter a row value for second card: " << endl;
            cin >> row2Value;

            cout << firstName << ", please enter a column value for second card: " << endl;
            cin >> column2Value;
            cout << endl;

            row1Value--;
            column1Value--;
            row2Value--;
            column2Value--;

            matrix2[row1Value][column1Value] = true;
            matrix2[row2Value][column2Value] = true;

            display();
            Match();
        }
        system("cls");
        cout << "Thank you for completing my game " << firstName << "!" << endl << endl;
    }

    void Match() {
        if (matrix[row1Value][column1Value] == matrix[row2Value][column2Value]) {
            points = points + 2;
            SetConsoleTextAttribute(color, 4);
            cout << "Congratulations!" << endl;
            cout << "Your Two Cards Match!" << endl << endl;
            SetConsoleTextAttribute(color, 7);
            cout << "Points: " << points << endl << endl;
        } else {
            SetConsoleTextAttribute(color, 4);
            cout << "Oh No!" << endl;
            cout << "Your Two Cards Do Not Match!" << endl << endl;
            SetConsoleTextAttribute(color, 7);
            cout << "Points: " << points << endl << endl;

            matrix2[row1Value][column1Value] = false;
            matrix2[row2Value][column2Value] = false;
        }
    }

    static void setColor(WORD attributes) {
        SetConsoleTextAttribute(color, attributes);
    }

    friend ostream& operator<<(ostream& os, const MemoryGameFinal& game) {
        game.display();
        return os;
    }

    virtual ~MemoryGameFinal() {} // Virtual destructor for polymorphic behavior
};

HANDLE MemoryGameFinal::color = GetStdHandle(STD_OUTPUT_HANDLE);

class MemoryGameFinalException : public exception {
public:
    const char* what() const noexcept override {
        return "MemoryGameFinal Exception";
    }
};

template <typename T>
class MemoryGameTemplate : public MemoryGameFinal {
public:
    void display() const override {
        // Display the game board using template specialization
        cout << "    1 2 3 4" << endl;
        cout << "  ";

        for (int i = 0; i <= 8; i++) {
            cout << "-";
        }
        cout << endl;

        for (int row = 0; row < 4; row++) {
            cout << row + 1 << " | ";

            for (int column = 0; column < 4; column++) {
                if (this->matrix2[row][column]) {
                    cout << this->matrix[row][column];
                } else {
                    cout << '*';
                }
                cout << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    try {
        MemoryGameTemplate<int> Game;
        Game.start();
    } catch (const MemoryGameFinalException& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
