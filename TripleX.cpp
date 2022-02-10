#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty)
{
    cout << "Time to crack the code! - Level " << Difficulty << std::endl;
    std::cout << "Figure out the code to the safe to get the gold" << std::endl;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA{rand() % Difficulty + Difficulty};
    const int CodeC{rand() % Difficulty + Difficulty};
    const int CodeB{rand() % Difficulty + Difficulty};

    int CodeSum{CodeA + CodeB + CodeC};
    int CodeProduct{CodeA * CodeB * CodeC};
    

    std::cout << "\n- There are 3 numbers in the code" << std::endl;
    std::cout << "- The codes add-up to:" << CodeSum << std::endl;
    std::cout << "- The codes multiply to give:" << CodeProduct << std::endl;

    int GuessA , GuessB , GuessC;
    std::cout << "What is your guess?";
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "Your guess was: " << GuessA << GuessB << GuessC << std::endl;

    int GuessSum{GuessA + GuessB + GuessC};
    int GuessProduct{GuessA * GuessB * GuessC};

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou cracked the code and got 20 gold bars!!! onto the next level.\n";
        return true;
    } 
    else 
    {
        std::cout << "\nYou have lost un-lucky" << std::endl;;
        return false;
    }

    
}


int main()
{
    srand(time(NULL));

    int LevelDifficulty{1};
    const int MaxDifficulty{6};

    while(LevelDifficulty <= MaxDifficulty)//Loop until all levels complete
    {

        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if(bLevelComplete)
        {
            ++LevelDifficulty;
        }
        else 
        {
            return 0;
        }
    }
    
    std::cout << "Congrats You got All the gold .... I'll see you next time soldier ;)";
    return 0;
}