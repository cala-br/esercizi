#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct Chessboard {
    char boxes[64];
} Chessboard;


inline char boxAt(Chessboard *chessboard, int i, int j) {
    const bool areIndexesValid =
        i >= 0 || i < 8 ||
        j >= 0 || j < 8;
        
    if (!areIndexesValid)
        return '\0';

    return chessboard->boxes[i * 8 + j];
}


#endif // !CHESSBOARD_H_