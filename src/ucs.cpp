#include "../include/sudoku.hpp"
#include <queue>

matrix ucs(matrix &board, int &numStates) {
    std::priority_queue< std::pair< int, matrix > > pq;
    pq.push(make_pair(0, board));

    while (!pq.empty()) {
        std::pair< int, matrix > curr = pq.top();
        int score = curr.first;
        matrix m = curr.second;
        std::pair< int, int > next = getNextEmpty(m);
        int x = next.first, y = next.second;
        if (x == -1 && y == -1)
            return m;
        pq.pop();
        numStates++;

        for (int i = 1; i <= 9; i++) {
            if (allowedToInsert(m, x, y, i)) {
                matrix new_board(m);
                new_board[x][y] = i;
                pq.push(make_pair(score + i, new_board));
            }
        }
    }

    return matrix();
}
