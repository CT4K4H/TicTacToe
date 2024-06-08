#ifndef GANE_AI
#define GAME_AI

#include "Board.hpp"
#include "Menu.hpp"

class AI
{
private:
    char m_state;
    int m_difficulty;
    int m_first_move = 0;
public:

    AI()
    {
        std::cout << "\n\n\tChoose AI difficulty: \n\n";

        std::vector<std::string> options;
        options.push_back("\n\t1. Easy");
        options.push_back("\n\t2. Medium");
        options.push_back("\n\t3. Hard");

        switch (chooseMenuItem(options, "\n\n\tChoose mode\n"))
        {
            case 1:
                m_difficulty = 1;
                break;
            case 2:
                m_difficulty = 2;
                break;
            case 3:
                m_difficulty = 3;
                break;
            default:
                break;
        }
    }

    void setState(char state) { m_state = state; }
    char getState() const { return m_state; }

    void calculateTurn(Board& board);

    void setPoint(Board& board);
    void setRandomPoint(Board& board);
};


#endif