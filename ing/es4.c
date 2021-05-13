#include <stdio.h>
#include "es4.h"


extern void printChessboard(Chessboard *chessboard) {
    const char *delimiter = "+---+---+---+---+---+---+---+---+";
    
    for (int i = 0; i < 8; i++) {
        puts(delimiter);
        for (int j = 0; j < 8; j++)
            printf("| %c ", boxAt(chessboard, i, j));
            
        puts("|");
    }    
    puts(delimiter);
}


int main()
{
    Chessboard c = {
        'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
        'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
        'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R',
    };
    printChessboard(&c);
}