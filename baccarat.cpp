#include <iostream>
#include <ctime>
#include <string>

// Structure to represent a set of cards
struct Number
{
    int num1, num2, sum, extraCard;
};

// Function prototypes
void printCard1(int num1, int num2, int num3, int sum);
void printCard2(int num1, int num2, int sum);
bool playAgain(char x, int money);
int winnerFunction(int bankerCard, int playerCard);
int declareWinner(int winner, int decision, int bet);

int main()
{
    system("Color 2F"); // CLI color changer => This will change the color of Terminal
    srand(time(NULL));  // Random number initialization

    // Variable declaration
    std::string name;
    int bet, decision, winner, prize;
    char play;
    bool logic = true;
    int money = 10000;

    std::cout << "\n=================================" << std::endl;

    // Name input
    std::cout << "Enter your name: ";
    getline(std::cin, name);

    std::cout << "\nGood evening, " << name << std::endl;
    std::cout << "=================================\n\n";
    std::cout << "WELCOME TO VIRTUAL BACCARAT TABLE" << std::endl;
    std::cout << "=================================" << std::endl;

    do
    { // Main do-while loop

        std::cout << "Current balance, INR " << money << std::endl;
        std::cout << "\nChoose your side: ";
        std::cout << "\n1-BANKER \n2-PLAYER \n";

        // Checks if input is 1 or 2
        while (!(std::cin >> decision) || (decision < 1 || decision > 2))
        {
            std::cin.clear();
            std::cout << "=================================" << std::endl;
            std::cout << "\nWrong choice!!!!!! ";
            std::cout << "\n\nChoose between: ";
            std::cout << "\n1-BANKER & \n2-PLAYER \n";
        }

        do
        {
            // Checks if bet is below balance money
            std::cout << "\nPlace your bet, INR: (between 1 - " << money << "): ";
            std::cin >> bet;
        } while (bet > money);

        // BANKER CARDS
        std::cout << "\n=================================\n";
        std::cout << "      ="
                  << " BANKER'S CARD  "
                  << "=\n";
        std::cout << "=================================\n";

        // Random card generator
        struct Number banker;
        banker.num1 = rand() % 10 + 1;
        banker.num2 = rand() % 10 + 1;
        banker.sum = banker.num1 + banker.num2;
        banker.sum = banker.sum % 10;

        // Checks if card is a natural win (8 or 9)
        if (banker.sum != 9 && banker.sum != 8)
        {
            banker.extraCard = rand() % 10 + 1; // Third and extra card
            banker.sum += banker.extraCard;
            banker.sum = banker.sum % 10; // Gets remainder of 3 cards as the final card

            // Prints banker's card
            printCard1(banker.num1, banker.num2, banker.extraCard, banker.sum);
        }
        else
        {
            // Natural win (8 or 9) and prints cards
            printCard2(banker.num1, banker.num2, banker.sum);
        }

        // PLAYER CARDS
        std::cout << "\n=================================\n";
        std::cout << "      ="
                  << " PLAYER'S CARD"
                  << "  =\n";
        std::cout << "=================================\n";

        // Random number generator for 2 cards
        struct Number player;
        player.num1 = rand() % 10 + 1;
        player.num2 = rand() % 10 + 1;
        player.sum = player.num1 + player.num2;
        player.sum = player.sum % 10;

        // Checks if 2 cards are a natural win (8 or 9)
        if (player.sum != 9 && player.sum != 8)
        {
            player.extraCard = rand() % 10 + 1; // Third and extra card
            player.sum += player.extraCard;
            player.sum = player.sum % 10; // Gets remainder of 3 cards as the final card

            // Function to print card of players
            printCard1(player.num1, player.num2, player.extraCard, player.sum);
        }
        else
        {
            // Natural win (8 or 9), print card of player
            printCard2(player.num1, player.num2, player.sum);
        }

        // Declaration of winner
        winner = winnerFunction(banker.sum, player.sum);

        // Awards prize for the winner, 1:1 for the winner;
        prize = declareWinner(winner, decision, bet);
        std::cout << "INR " << prize << std::endl;
        money += prize;
        std::cout << "Current Money, INR " << money << "\n\n";

        // Asks the user if he wants to play again
        std::cout << "PLAY AGAIN? Y/N ";
        std::cin >> play;
        logic = playAgain(play, money);

    } while (logic);

    return 0;
}

// Function to print card with three numbers
void printCard1(int num1, int num2, int num3, int sum)
{
    std::cout << "=======\n";
    std::cout << "|     |\n";
    std::cout << "|  " << sum << "  |\n";
    std::cout << "|     |\n";
    std::cout << "=======\n";

    std::cout << "First Card " << num1 << "\n";
    std::cout << "Second Card " << num2 << "\n";
    std::cout << "Extra Card " << num3 << "\n";
}

// Function to print card with two numbers for natural win
void printCard2(int num1, int num2, int sum)
{
    std::cout << "=======\n";
    std::cout << "|     |\n";
    std::cout << "|  " << sum << "  |\n";
    std::cout << "|     |\n";
    std::cout << "=======\n";

    std::cout << "This is a natural win 8/9 \n";
    std::cout << "First Card " << num1 << "\n";
    std::cout << "Second Card " << num2 << "\n";
}

// Function to check if the player wants to play again
bool playAgain(char x, int money)
{
    if (money > 0)
    {
        if (x == 'Y' || x == 'y')
        {
            return true;
        }
        else if (x == 'N' || x == 'n')
        {
            std::cout << "THANK YOU FOR PLAYING!\n";
            return false;
        }
    }
    else
    {
        std::cout << "Insufficient funds!\n";
        return false;
    }

    return false;
}

// Function to determine the winner
int winnerFunction(int bankerCard, int playerCard)
{
    std::cout << "\n=================================\n";
    if (bankerCard > playerCard)
    {
        std::cout << "\nBANKER WIN, ";
        return 1;
    }
    else if (bankerCard < playerCard)
    {
        std::cout << "\nPLAYER WIN, ";
        return 2;
    }
    else
    { // bankerCard == playerCard
        std::cout << "\nDRAW, ";
        return 3;
    }

    return 0;
}

// Function to declare the winner and calculate the prize
int declareWinner(int winner, int decision, int bet)
{
    if (winner == decision)
    {
        // Win pays the bet
        std::cout << "YOU WIN!\n";
        return bet;
    }
    if (winner == 3)
    {
        // Draw
        std::cout << "Tie Game!\n";
        return 0;
    }
    else
    {
        std::cout << "YOU LOSE!\n";
        bet *= -1;
        return bet;
    }
}
