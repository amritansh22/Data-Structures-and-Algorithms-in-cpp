#include <iostream>

// minimize the memory usage by using the smallest possible data type
using square_t = unsigned char;

/* draws the board in a more readable manner */
void print_board(square_t board[9][9])
{
    for (size_t i = 0; i < 9; ++i)
    {
        if (i % 3 == 0)
            std::cout << std::endl;
        for (size_t j = 0; j < 9; ++j)
        {
            if (j % 3 == 0)
                std::cout << "  ";
            std::cout << (int) board[i][j] << ' ';

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/* checks if the board is after the data of the given location has been changed */
bool is_valid_move(square_t board[9][9], size_t row, size_t col)
{
    for (size_t i = 0; i < 9; ++i)
    {
        // validate the row
        if (i != col // check we aren't comparing the same column
            && board[row][i] == board[row][col])
            return false;
        
        // validate the column
        if (i != row // check we aren't comparing the same row
            && board[i][col] == board[row][col])
            return false;
        
        // validate the box
        // the calculation utilizes the fact that i / 3 will give sets of three equal numbers numbers
        // and i % 3 repeats the same three digits over and over
        if (row - i / 3 + row % 3 != row // check that the tested row in the box is not the original one
            && col - col % 3 + i % 3 != col // do the same for the column
            && board[row - row % 3 + i / 3][col - col % 3 + i % 3] == board[row][col])
            return false;
    }
    return true;
}

/* solve the sudoku using backtracking */
void solve_sudoku(square_t board[9][9])
{
    for (size_t i = 0; i < 9; ++i)
        for (size_t j = 0; j < 9; ++j)
            // if the current block is empty, backtrack on it
            if (board[i][j] == 0)
            {
                // test every ooption
                for (square_t option = 1; option < 10; option++)
                {
                    board[i][j] = option;
                    if (is_valid_move(board, i, j))
                        solve_sudoku(board);
                }
                // backtrack
                board[i][j] = 0;
                // since we found an empty block, we don't want to risk printing a half-filled board
                return;
            }
    // if we've reached this, that means that we have finished filling in a valid sudoku board and there are no more empty spots
    std::cout << "~~~ Found a Solution! ~~~" << std::endl;
    print_board(board);
}

int main()
{
    square_t board[9][9] = { 
        {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
        {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
        {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    // a simple test
    solve_sudoku(board);
}