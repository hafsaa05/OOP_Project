#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <bitset>

using namespace std;

//Class
class MemoryGameFinal
{
protected:
    //Declare global variables
    static const int SIZE = 4;
    int points = 0, point = 0;
    string firstName;
    char difficulty;
    int column, row, row1Value, column1Value, row2Value, column2Value, matrix[SIZE][SIZE];
    int menu;
    bool again = true;
    bool matrix2[SIZE][SIZE];

public:
    // Display the cards
    void display() const
    {
        // Easy grid setup
        cout << "    1 2 3 4" << endl;
        cout << "  ";

        for (int i = 0; i <= 8; i++)
        {
            cout << "-";
        }
        cout << endl;

        //More setup
        for (int row = 0; row < SIZE; row++)
        {
            cout << row + 1 << " | ";

            for (int column = 0; column < SIZE; column++)
            {
                // Print the value or '*' depending on whether the card
                // is exposed.
                if (matrix2[row][column])
                {
                    cout << matrix[row][column];
                }
                else
                {
                    cout << '*';
                }
                cout << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    void start()
    {
        // The first few lines are only printed once.
        cout << "\t\t\tWELCOME TO CardCraft - A MEMORY CARD GAME" << endl
             << endl;


        // Select game
        cout << "Please enter your first name: ";
        cin >> firstName;

        // Main Menu
        while (again)
        {
            cout << "--------------------------------------" << endl;
            cout << "\t\tWelcome, " << firstName << "!" << endl;
            cout << endl;
            cout << "Game Menu" << endl;
            cout << " ********************" << endl;
            cout << "Select 1 for a New Game and 2 to Exit Game" << endl;
            cout << "1. New Game" << endl;
            cout << "2. Exit Game" << endl;
            cout << " ********************" << endl;
            cin >> menu;

            // Option to exit game and re-ask the user to play again
            if (menu == 2)
            {
                cout << endl;
                cout << "Would you like to play Memory - The Card Game again?" << endl;
                cout << "Type '1' to play again and '0' to leave" << endl;
                cin >> again;
                cout << endl;
            }
            else if (menu == 1)
            {
                cout<<"\t\t\tYou need 16 points to win the game!"<<endl;
                cout << "\t\t\t\t\tLET THE GAME BEGIN!" << endl<<endl;
                cout << "Enter (y) to proceed with the game!" << endl;
               
                cin >> difficulty;

                // Switch statement which determines the grid setup for
                // the chosen game
                switch (difficulty)
                {
                // Case easy
                case 'y':
                    srand((unsigned int)time(NULL));
                    // Dictates number of columns and rows
                    for (int row = 0; row < SIZE; row++)
                    {
                        for (int column = 0; column < SIZE; column++)
                        {
                            // Initialize a random matrix
                            matrix[row][column] = rand() % 8 + 1;
                            matrix2[row][column] = false;
                        }
                        cout << endl;
                    }
                    cout << "Points: " << points << endl;

                    // display the board
                    display();

                    // Initialize the game function after setup
                    Loop();

                    // End of case easy
                    break;
                }
            }
        }
    }

    // game function
    void Loop()
    {
        while (points != SIZE * SIZE)
        {
            // Prompt
            cout << firstName << ", please enter a row value for the first card: "
                 << endl;
            cin >> row1Value;

            cout << firstName
                 << ", please enter a column value for the first card: " << endl;
            cin >> column1Value;

            cout << firstName
                 << ", please enter a row value for the second card: " << endl;
            cin >> row2Value;

            cout << firstName
                 << ", please enter a column value for the second card: " << endl;
            cin >> column2Value;
            cout << endl;

            // Decrease the number value as the rows and columns go down
            row1Value--;
            column1Value--;
            row2Value--;
            column2Value--;

            // Temporarily expose the cards
            matrix2[row1Value][column1Value] = true;
            matrix2[row2Value][column2Value] = true;

            // display the board
            display();

            // Initializes the function for matching results
            Match();
        }

        // When you get here, points == SIZE * SIZE
        cout << "Thank you for completing my game " << firstName
             << "!" << endl
             << endl;
    }

    // Match in-game function
    void Match()
    {
        // Check condition
        if (matrix[row1Value][column1Value] == matrix[row2Value][column2Value])
        { // If there is a match
            // Leave them exposed
            points = points + 2;
            cout << "Congratulations!" << endl;
            cout << "Your Two Cards Match!" << endl
                 << endl;
            cout << "Points: " << points << endl
                 << endl; // update points
        }
        else
        {
            cout << "Oh No!" << endl;
            cout << "Your Two Cards Do Not Match!" << endl
                 << endl;
            cout << "Points: " << points << endl
                 << endl; // update points

            // Cover them up again
            matrix2[row1Value][column1Value] = false;
            matrix2[row2Value][column2Value] = false;
        }
    }
};

// Executable code for the whole program
int main()
{
    MemoryGameFinal Game;
    Game.start();
}
