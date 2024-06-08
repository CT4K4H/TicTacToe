#include "AI.hpp"
#include "Board.hpp"
#include "RandomGen.hpp"
#include <algorithm>


void AI::setPoint(Board& board) {
    int row;
    int col;
    int max_weight_in_point = 0;
    
    //  std::cout << "\nTrying to calculate next move...\n";

    for (int i = 0; i < board.getSize(); ++i) {
        int temp_max = 0;

        for (int j = 0; j < board.getSize(); ++j) {
            if (board.isCellFree(i, j) && i == j) {
                temp_max = std::max({board.countLeftDiagStates(m_state), board.countColumnStates(j, m_state), board.countRowStates(i, m_state)});
                //  std::cout << "weight on left diag: " << temp_max << '\n';
                if (max_weight_in_point < temp_max) {
                    max_weight_in_point = temp_max;
                    row = i;
                    col = j;
                }
            }
            else if (board.isCellFree(i, j) && i == board.getSize()-j-1) {
                temp_max = std::max({board.countRightDiagStates(m_state), board.countColumnStates(j, m_state), board.countRowStates(i, m_state)});
                //  std::cout << "weight on right diag: " << temp_max << '\n';
                if (max_weight_in_point < temp_max) {
                    max_weight_in_point = temp_max;
                    row = i;
                    col = j;
                }
            }
            else if (board.isCellFree(i, j)) {
                temp_max = std::max({board.countColumnStates(j, m_state), board.countRowStates(i, m_state)});
                //  std::cout << "weight on raw/column: " << temp_max << '\n';
                if (max_weight_in_point < temp_max) {
                    max_weight_in_point = temp_max;
                    row = i;
                    col = j;
                }
            }
        }
    }

    //  std::cout << "Row: " << row << "\t Column: " << col << '\n';
    //  system("pause");
    
    board.setCellState(row, col, m_state);
    
    //  show updated board
    board.drawBoard();
}

std::pair<int, int> lastCellToWin(const char state, Board& board) {
    // std::cout << "\nChecking if the player is 1 move from win...\n";
    
    int row = -1;
    int col = -1;
    int count_player_cells = 0;
    
    for (int i = 0; i < board.getSize(); ++i) {
        for (int j = 0; j < board.getSize(); ++j) {
            if (board.isCellFree(i, j) && i == j) {
                count_player_cells = std::max({board.countLeftDiagStates(state), board.countColumnStates(j, state), board.countRowStates(i, state)});
                //  std::cout << "weight on left diag: " << count_player_cells << '\n';
                row = i;
                col = j;
                //  std::cout << "Row: " << row << "\t Column: " << col << '\n';
            }
            else if (board.isCellFree(i, j) && i == board.getSize()-j-1) {
                count_player_cells = std::max({board.countRightDiagStates(state), board.countColumnStates(j, state), board.countRowStates(i, state)});
                //  std::cout << "weight on right diag: " << count_player_cells << '\n';
                row = i;
                col = j;
                //  std::cout << "Row: " << row << "\t Column: " << col << '\n';
            }
            else if (board.isCellFree(i, j)) {
                count_player_cells = std::max({board.countColumnStates(j, state), board.countRowStates(i, state)});
                //  std::cout << "weight on raw/column: " << count_player_cells << '\n';
                row = i;
                col = j;
                //  std::cout << "Row: " << row << "\t Column: " << col << '\n';
            }

            if (count_player_cells == board.getSize()-1) {
                // std::cout << "Row: " << row << "\t Column: " << col << '\n';
                // std::cout << "THIS IS THE LAST CELL!!! \n";
                // system("pause");
                return {row, col};
            }
        }
    }
    //  system("pause");
    return {-1, -1};
}


void AI::setRandomPoint(Board& board) {
    int row;
    int col;

    while (true) {
        row = randomInt(0, board.getSize()-1);
        col = randomInt(0, board.getSize()-1);

        if (board.isCellFree(row, col)) { break; }
    }

    board.setCellState(row, col, getState());
    //  show updated board
    board.drawBoard();
}



void AI::calculateTurn(Board& board) {
    //  show current board
    board.drawBoard();

    char player_state;

    if (m_state == 'X') { player_state = 'O'; }
    else { player_state = 'X'; }

    int error_chance = randomInt(0, 100);


    if (m_first_move == 0) {
        setRandomPoint(board);
        ++m_first_move;
        return;
    }


    std::pair<int, int> last_cell = lastCellToWin(player_state, board); 

    if (last_cell.first != -1 && last_cell.second != -1) {
        error_chance = randomInt(0, 100);
            //  std::cout << error_chance << '\n';
        //  system("pause");
        if (error_chance <= 20) {
            setRandomPoint(board);
        }
        else {
            board.setCellState(last_cell.first, last_cell.second, m_state);
        }

        //  show updated board
        board.drawBoard();
        return;
    }


    switch (m_difficulty)
    {
        case 1:
            if (error_chance <= 70) { setRandomPoint(board); }
            else { setPoint(board); }
            break;
        case 2:
            if (error_chance <= 45) { setRandomPoint(board); }
            else { setPoint(board); }
            break;
        case 3:
            if (error_chance <= 5) { setRandomPoint(board); }
            else { setPoint(board); }
            break;
        default:
            break;
    }

}
