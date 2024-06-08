#ifndef GAME_BOARD
#define GAME_BOARD

#include <vector>
#include <iostream>

class Board
{
private:
    int m_board_size_N;
    std::vector<std::pair<int, int>> m_cells_width;
    std::vector<std::pair<int, int>> m_cells_height;
    std::vector<std::vector<char>> m_board;

    // cell width (cell_width.Y - cell_width.X + 1)
    const int m_cell_width_x { 1 };
    const int m_cell_width_y { 5 };

    // cell height (cell_height.Y - cell_height.X + 1)
    const int m_cell_height_x { 1 };
    const int m_cell_height_y { 3 };
public:

    Board() 
    {
        std::pair<int, int> cell_width, cell_height;

        cell_width.first = m_cell_width_x;
        cell_width.second = m_cell_width_y;
        
        cell_height.first = m_cell_height_x;
        cell_height.second = m_cell_height_y;

        std::cout << "\n\n\tEnter map size NxN (N cannot be less then 3): ";
        std::cout << "\n\tN: ";
        std::cin >> m_board_size_N;
        if(m_board_size_N < 3)
        {
            // default size
            m_board_size_N = 3;
        }
        
        for (size_t i = 0; i < m_board_size_N; i++)
        {
            std::vector<char> tmp;

            m_cells_width.push_back({cell_width.first, cell_width.second});
            cell_width.first += m_cells_width[0].first + m_cells_width[0].second;
            cell_width.second += m_cells_width[0].first + m_cells_width[0].second;

            m_cells_height.push_back({cell_height.first, cell_height.second});
            cell_height.first += m_cells_height[0].first + m_cells_height[0].second;
            cell_height.second += m_cells_height[0].first + m_cells_height[0].second;

            for ( int j = 0; j < m_board_size_N; j++)
            {
                tmp.push_back(' ');
            }
            m_board.push_back(tmp);
        }

    }


    void drawBoard();


    auto getSize() const { return m_board_size_N; }

    auto getCellHeight() const { return m_cells_height; }

    auto getCellWidth() const { return m_cells_width; }

    auto getCellState(int x, int y) const { return m_board[x][y]; }

    void setCellState(const int x, const int y, const char state);

    bool isCoordValid(const int x, const int y, const char state);

    bool isCellFree(int row, int col) const;

    
    int countLeftDiagStates(const char state);
    int countRightDiagStates(const char state);
    int countRowStates(const int row, const char state);
    int countColumnStates(const int column, const char state);
    
    bool checkTie();
    bool checkWinner(const char& side);


};



#endif


