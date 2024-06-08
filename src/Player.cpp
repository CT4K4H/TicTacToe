#include <windows.h>
#include "Player.hpp"
#include "Board.hpp"

void Player::makeTurn(Board& board)
{
    // show current board
    board.drawBoard();

    std::cout << "Player "<< getState() << " making his move...\n";
    std::cout << "Click on empty cell to set " << getState() << "\n";
    
    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); // получаем дескриптор
    INPUT_RECORD InputRecord; // используется для возвращения информации о входных сообщениях в консольном входном буфере
    DWORD Events; // unsigned long
    COORD coord; // для координат X, Y
    
    /*Запретить выделение консоли*/
    DWORD prev_mode;
    GetConsoleMode(hin, &prev_mode);
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));
    SetConsoleMode(hin, ENABLE_MOUSE_INPUT); // разрешаем обработку мыши
    
    while(true)
    {
        ReadConsoleInput(hin, &InputRecord, 1, &Events); // считывание 
        //
        if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) // левая кнопка
        {
            coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
            coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            std::cout << "left - X" << coord.X << ", Y = " << coord.Y << std::endl;

            if (board.isCoordValid(coord.X, coord.Y, m_State)) {
                break;
            }
        }
    }

    // show updated board
    board.drawBoard();
}