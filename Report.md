# Project Report: Memory Card Game
# Team Members:
 ### Arwa Feroze (23K-0022)
 ### Hafsa Rashid (23K-0064)
 ### Amna Asim Khan (23K-0859)
 
 # 1. Introduction:
The Memory Card Game project aims to implement a simple memory card game in C++. The game requires players to match pairs of cards within a grid of face-down cards. It's designed to enhance memory skills and provide entertainment.

# 2. Project Overview:
The project utilizes object-oriented programming principles to create a modular and extensible design. It consists of the following components:

## - MemoryGameFinal Class:
This class represents the core functionality of the game. It includes methods for displaying the game board, starting the game, managing player interactions, and checking for matches between cards.

## - MemoryGameFinalException Class: 
An exception class for handling errors specific to the memory game.

## - MemoryGameTemplate Class: 
A template class derived from MemoryGameFinal, used for displaying the game board with template specialization.

# 3. Code Overview:
The code implements the memory card game using C++ and Windows Console APIs. It utilizes features such as classes, inheritance, exception handling, and template specialization. Key functionalities include:

## - Displaying the Game Board:
The game board is displayed using a grid format where face-down cards are represented by asterisks (*) and face-up cards display their values.

## - Starting the Game:
Players are prompted to enter their name and choose to start a new game or exit. Upon starting a new game, random numbers are generated to assign values to the cards.

## - Matching Cards:
Players input the row and column values of two cards they want to flip. The game checks if the selected cards match based on their values.

# 4. Implementation Details:
## - Graphics:
The game utilizes basic console graphics for displaying the game board and messages.

## - Randomization:
Random numbers are generated to assign values to the cards, ensuring a different game experience each time.

## - Error Handling:
Exception handling is implemented to catch and handle errors that may occur during the game.

# 5. Future Enhancements:
## - Graphical User Interface (GUI): 
Implementing a graphical user interface can enhance the game's visual appeal and user experience.

## - Multiple Difficulty Levels:
Adding options for different difficulty levels can cater to players with varying skill levels.

## - Score Tracking:
Implementing a scoring system and leaderboard can add competitiveness to the game.

# 6. Conclusion:
The Memory Card Game project provides a fun and interactive way to exercise memory skills while enjoying a classic game. With its modular design and extensibility, it serves as a foundation for further enhancements and customization.

