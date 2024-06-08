#ifndef PLAYER
#define PLAYER

#include <iostream>

class Board;

class Player
{
private:
    char m_State;

public:

    void setState(char State) { m_State = State; }
    char getState() const { return m_State; }
    

    void makeTurn(Board& board);
};



#endif