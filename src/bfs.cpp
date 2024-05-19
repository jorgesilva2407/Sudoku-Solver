#include "../include/sudoku.hpp"
#include <queue>

matrix bfs(matrix &board, int &numStates) {
    std::queue< matrix > q;
    q.push(board);

    while (!q.empty()) {
        matrix curr = q.front();
        std::pair< int, int > next = getNextEmpty(curr);
        int x = next.first, y = next.second;
        if (x == -1 && y == -1)
            return curr;
        q.pop();
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
