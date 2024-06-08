#include "Board.hpp"

void Board::drawBoard() {
    const int cell_x_length = m_cell_width_y - m_cell_width_x + 1;
    const int cell_y_length = m_cell_height_y - m_cell_height_x + 1;
    
    system("CLS");
    
    for(int i=0; i < m_board.size(); ++i) {
        if(!i) { std::cout << '+'; }
        for(int j=0; j < cell_x_length; ++j) {
            std::cout << '-';
        }
        std::cout << '+';
    }

    for (int i = 0; i < m_board.size(); ++i) {
        for(int z = 0; z < cell_y_length; ++z) {
            std::cout << '\n';
            for(int k = 0; k < m_board.size(); ++k) {
                if(!k) { std::cout << "|"; }
                for (int j = 0; j < cell_x_length ; ++j) {
                    if(z == cell_y_length/2 && j == cell_x_length/2) { // set center 
                        std::cout << m_board[i][k];
                    }
                    else { std::cout << ' '; } 
                }
                std::cout << "|";
            }
        }

        std::cout << '\n';
        for(int i=0; i < m_board.size(); ++i) {
            if(!i) { std::cout << '+'; }
            for(int j=0; j < cell_x_length; ++j) {
                std::cout << '-';
            }
            std::cout << '+';
        }
    }

    std::cout << '\n';
}


void Board::setCellState(const int x, const int y, const char state) {
    if(!isCellFree(x, y)) {
        std::cout << "Error set!\n";
    }
    else {
        m_board[x][y] = state;
    }
}


bool Board::isCellFree(int row, int col) const {
    if (m_board[row][col] == ' ')
        return true;
    return false;
}


bool Board::isCoordValid(const int x, const int y, const char state) {
    bool check_coord = false;

    if ((x > getCellWidth()[getSize()-1].second) || (y > getCellHeight()[getSize()-1].second)) {
        std::cout << "Current coordinates are out of game map range, try another\n";
        return false;
    }
    else {
        for (int i=0; i < getSize(); ++i) {
            for (int j=0; j < getSize(); ++j) {
                if (y >= getCellHeight()[j].first && y <= getCellHeight()[j].second
                    && x >= getCellWidth()[i].first && x <= getCellWidth()[i].second) 
                {
                    check_coord = true;
                    if (getCellState(j, i) == ' ') {
                        setCellState(j, i, state);
                        return true;
                    }
                    else { return false; }
                }
            }
        }
        // if coordinates do not belong to current board
        if (check_coord == false) { return false; }
    }
    
    return false;
}


int Board::countLeftDiagStates(const char state) {
    int size = getSize();
    int count_states = 0;

    for (int i = 0; i < size; ++i) {
        char curr_cell_state = getCellState(i, i); 

        if (curr_cell_state != ' ') {
            if (curr_cell_state != state) { return -1; }
            else { ++count_states; }
        }
    }

    return count_states;
}

int Board::countRightDiagStates(const char state) {
    int size = getSize();
    int count_states = 0;
    
    for (int i = size - 1; i >= 0; --i) {
        char curr_cell_state = getCellState(size-1-i, i);
        
        if(curr_cell_state != ' ') {
            if(curr_cell_state != state) { return -1; }
            else { ++count_states; }
        }
    }

    return count_states;
}

int Board::countRowStates(const int row, const char state) {
    int size = getSize();
    int count_states = 0;

    for (int i = 0; i < size; ++i) {
        char curr_cell_state = getCellState(row, i); 

        if (curr_cell_state != ' ') {
            if (curr_cell_state != state) { return -1; }
            else { ++count_states; }
        }
    }

    return count_states;
}

int Board::countColumnStates(const int column, const char state) {
    int size = getSize();
    int count_states = 0;

    for (int i = 0; i < size; ++i) {
        char curr_cell_state = getCellState(i, column); 

        if (curr_cell_state != ' ') {
            if (curr_cell_state != state) { return -1; }
            else { ++count_states; }
        }
    }

    return count_states;
}

bool Board::checkTie() {

    for (int i = 0; i < m_board_size_N; i++) {
        for (int j = 0; j < m_board_size_N; j++) {
            if(getCellState(i, j) == ' ') {
                return false;
            }
        }
    }
    std::cout << "TIE!\n";
    return true;
}

bool Board::checkWinner(const char& state)
{

    if      (countLeftDiagStates(state) == m_board_size_N)  { return true; }
    else if (countRightDiagStates(state) == m_board_size_N) { return true; }

    for (int i = 0; i < m_board_size_N; ++i) {
        if (countRowStates(i, state) == m_board_size_N) {
            return true;
        }
    }

    for (int i = 0; i < m_board_size_N; ++i) {
        if (countColumnStates(i, state) == m_board_size_N) {
            return true;
        }
    }

    if (checkTie()) {
        std::cout << "TIE!\n";
        return false;
    }

    return false;
}