#include <chrono>
#include <iostream>

#include "../include/sudoku.hpp"

int main(int argc, char **argv) {
    if (argc != 11) {
        std::cout << "Numero insuficiente de parametros" << std::endl;
        exit(1);
    }

    matrix board(9, std::vector< int >(9));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = argv[i + 2][j] - '0';
        }
    }

    matrix result;
    int numStates = 0;
    std::chrono::time_point< std::chrono::high_resolution_clock > start =
        std::chrono::high_resolution_clock().now();
    switch (argv[1][0]) {
    case 'B':
        result = bfs(board, numStates);
        break;
    case 'I':
        result = ids(board, numStates);
        break;
    case 'U':
        result = ucs(board, numStates);
        break;
    case 'A':
        result = ast(board, numStates);
        break;
    case 'G':
        result = gre(board, numStates);
        break;
    }
    std::chrono::time_point< std::chrono::high_resolution_clock > end =
        std::chrono::high_resolution_clock().now();
    std::chrono::duration< long long, std::ratio< 1, 1000 > > time =
        std::chrono::duration_cast< std::chrono::milliseconds >(end - start);

    if (result.empty()) {
        std::cout << "Impssivel preencher este jogo" << std::endl;
        exit(1);
    }

    std::cout << numStates << " " << time.count() << std::endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << result[i][j];
        }
        std::cout << " ";
    }
    std::cout << std::endl;

    exit(0);
}
