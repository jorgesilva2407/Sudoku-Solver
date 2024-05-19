#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <vector>

typedef std::vector< std::vector< int > > matrix;

bool allowedToInsert(matrix &board, int line, int col, int val);
std::pair< int, int > getNextEmpty(matrix &board);
std::pair< int, int > getNextMin(matrix &board);

matrix bfs(matrix &board, int &numStates);
matrix ids(matrix &board, int &numStates);
matrix ucs(matrix &board, int &numStates);
matrix ast(matrix &board, int &numStates);
matrix gre(matrix &board, int &numStates);

#endif
