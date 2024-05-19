#include "../include/sudoku.hpp"
#include <climits>
#include <limits.h>

bool allowedToInsert(matrix &board, int line, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (board[line][i] == val || board[i][col] == val)
            return false;
    }

    int x = line - (line % 3);
    int y = col - (col % 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[x + i][y + j] == val)
                return false;
        }
    }

    return true;
}

std::pair< int, int > getNextEmpty(matrix &board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0)
                return std::make_pair(i, j);
        }
    }
    return std::make_pair(-1, -1);
}

std::pair< int, int > getNextMin(matrix &board) {
    std::pair< int, int > min(-1, -1);
    int num = INT_MAX;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != 0)
                continue;

            int tmp = 0;
            for (int k = 1; k <= 9; k++) {
                if (allowedToInsert(board, i, j, k))
                    tmp++;
            }

            if (tmp == 0)
                return std::make_pair(-2, -2);

            if (tmp < num) {
                num = tmp;
                min = std::make_pair(i, j);
            }
        }
    }

    return min;
}
