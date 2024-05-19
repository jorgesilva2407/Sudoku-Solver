#include "../include/sudoku.hpp"
#include <queue>

matrix gre(matrix &board, int &numStates) {
    std::queue< matrix > q;
    q.push(board);

    while (!q.empty()) {
        matrix curr = q.front();
        q.pop();

        std::pair< int, int > next = getNextMin(curr);
        int x = next.first, y = next.second;
        if (x == -2 && y == -2)
            continue;
        if (x == -1 && y == -1)
            return curr;
        numStates++;

        for (int i = 1; i <= 9; i++) {
            if (allowedToInsert(curr, x, y, i)) {
                matrix new_board(curr);
                new_board[x][y] = i;
                q.push(new_board);
            }
        }
    }

    return matrix();
}
