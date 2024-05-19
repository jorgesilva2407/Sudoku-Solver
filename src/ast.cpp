#include "../include/sudoku.hpp"
#include <queue>
#include <utility>

matrix ast(matrix &board, int &numStates) {
    std::priority_queue< std::pair< int, matrix > > pq;
    pq.push(std::make_pair(0, board));

    while (!pq.empty()) {
        std::pair< int, matrix > curr_pair = pq.top();
        int filled = curr_pair.first;
        matrix curr = curr_pair.second;
        pq.pop();

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
                pq.push(std::make_pair(filled + 1, new_board));
            }
        }
    }

    return matrix();
}
