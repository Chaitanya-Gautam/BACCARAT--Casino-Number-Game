# BACCARAT---Casino-Number-Game
BACCARAT - Casino Number Game
Overview
This C++ program simulates a virtual Baccarat game where a player can bet on either the 'BANKER' or 'PLAYER' side. The game involves drawing two cards for each side, and the winner is determined by the side with the nearest sum to 9. If the sum exceeds 9, an additional card is drawn. However, if the initial sum is 8 or 9, no more cards are drawn. The player's goal is to make successful bets and increase their virtual money.

Author
Chaitanya Gautam
Email: chaitanya.gautam@pisquaretech.com
How to Run
Compile the C++ code using a C++ compiler (e.g., g++).

bash
Copy code
g++ baccarat.cpp -o baccarat
Run the compiled executable.

bash
Copy code
./baccarat
Follow the on-screen prompts to enter your name, place bets, and choose sides.

Rules of the Game
The player chooses between 'BANKER' and 'PLAYER' sides.
Two cards are drawn for each side, and the sum of the cards determines the winner.
If the initial sum is 8 or 9, no additional cards are drawn.
If the sum exceeds 9, an extra card is drawn.
The player can place bets and aims to increase their virtual money.
Gameplay
Enter your name.
Choose between 'BANKER' and 'PLAYER'.
Place a bet within your available balance.
Two cards are drawn for both 'BANKER' and 'PLAYER'.
The winner is determined based on the sum of the cards.
The player's balance is updated based on the bet and outcome.
The player can choose to play again or exit.
Code Structure
The code is structured using functions and a main loop for gameplay.
The game logic is implemented in functions such as winnerFunction and declareWinner.
User inputs are validated to ensure correct choices and bet amounts.
The game continues in a loop until the player decides to exit or runs out of funds.
Additional Notes
The game provides a simple command-line interface (CLI) with basic color formatting.
Random card generation adds an element of chance to the game.
The program checks for valid inputs and ensures the player has sufficient funds for betting.
License
This project is open-source and available under the MIT License. Feel free to modify and use the code according to your needs. If you have any suggestions or find issues, please create an issue.

Enjoy the virtual Baccarat experience!
