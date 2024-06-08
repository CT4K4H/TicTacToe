#include <conio.h>
#include <windows.h>

#include "Game.hpp"
#include "RandomGen.hpp"
#include "Menu.hpp"


int chooseMode() {
    std::vector<std::string> options;
    options.push_back("\n\t1. Play with AI");
    options.push_back("\n\t2. Play on one screen");
    options.push_back("\n\t3. Play multiplayer");

    switch (chooseMenuItem(options, "\n\n\tChoose mode\n"))
    {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        default:
            break;
    }

    return -1;
}


void runGame(Player& player1, Player& player2) {
    Board game_board{};

    if (randomInt(0,100) >= 50) { 
        player1.setState('X'); 
        player2.setState('O');
    }
    else { 
        player2.setState('X');
        player1.setState('O');
    }


    while (true)
    {
        // player with State 'X' always has first turn
        if (player1.getState() == 'X')
        {
            player1.makeTurn(game_board);
            if (game_board.checkWinner(player1.getState())) {
                std::cout << "Player " << player1.getState() << " won the game!\n";
                break;
            }

            player2.makeTurn(game_board);
            if (game_board.checkWinner(player2.getState())) {
                std::cout << "Player " << player2.getState() << " won the game!\n";
                break;
            }
        }
        else if (player2.getState() == 'X')
        {
            player2.makeTurn(game_board);
            if (game_board.checkWinner(player2.getState())) {
                std::cout << "Player " << player2.getState() << " won the game!\n";
                break;
            }

            player1.makeTurn(game_board);
            if (game_board.checkWinner(player1.getState())) {
                std::cout << "Player " << player1.getState() << " won the game!\n";
                break;
            }
        }
    }
}


void runGame(Player& player) {

    Board game_board{};

    if (randomInt(0,100) >= 50) { player.setState('X'); }
    else { player.setState('O'); }

    while(true)
    {
        game_board.drawBoard();
        player.makeTurn(game_board);
        if (game_board.checkWinner(player.getState())) {
            std::cout << "Player " << player.getState() << " won the game!\n";
            break;
        }

        if (player.getState() == 'X') { player.setState('O'); }
        else{ player.setState('X'); }
    }
}


void runGame(Player& player, AI& ai) {
    Board game_board {};

    if (randomInt(0,100) >= 50) {
        player.setState('X');
        ai.setState('O');
    }
    else {
        player.setState('O');
        ai.setState('X');
    }

    while (true)
    {
        player.makeTurn(game_board);
        if (game_board.checkWinner(player.getState())) {
            std::cout << "Player " << player.getState() << " won the game!\n";
            break;
        }

        ai.calculateTurn(game_board);
        if (game_board.checkWinner(ai.getState())) {
            std::cout << "AI won the game!\n";
            break;
        }
    }
}


int main() {

    while (true)
    {
        const int choosen_mode = chooseMode();

        if(choosen_mode == 1)
        {
            AI ai;
            Player player;
            runGame(player, ai);
        }
        else if(choosen_mode == 2)
        {
            Player one_screen_player;
            runGame(one_screen_player);
        }
        else if(choosen_mode == 3)
        {
            Player player1;
            Player player2;
            runGame(player1, player2);
        }
        
        char choose = '-';

        while(choose != 'y' && choose != 'n')
        {
            std::cout << "Do you want to play again? [y/n] : ";
            std::cin >> choose;
        }

        if(choose == 'n') { break; }
    }
    
    return 0;
}