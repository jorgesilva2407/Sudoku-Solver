#include "../include/sudoku.hpp"

matrix ldfs(matrix &board, int &numStates, int lim, int depth) {
    if (depth > lim)
        return matrix();

    std::pair< int, int > next = getNextEmpty(board);
    int x = next.first, y = next.second;
    if (x == -1 && y == -1)
        return board;
    numStates++;

    for (int i = 1; i <= 9; i++) {
        if (allowedToInsert(board, x, y, i)) {
            board[x][y] = i;
            matrix result = ldfs(board, numStates, lim, depth + 1);
            if (!result.empty())
                return result;
        }
    }
    board[x][y] = 0;

    return matrix();
}

matrix ids(matrix &board, int &numStates) {
    matrix result;
    int lim = 0;
    while ((result = ldfs(board, numStates, lim++, 0)).empty() && lim <= 81)
        ;
    return result;
}
