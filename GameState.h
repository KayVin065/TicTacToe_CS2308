//The game state specification file.
//  It stores the move stack and the current state of the tic tac toe board

#include <iostream>
#include "MoveStack.h"

class GameState {
    char boardState[3][3];
    MoveStack moveStack;
public:
    GameState();
    int getCurrentPlayer();
    int addMove(Move move);
    bool undoLast();
    void displayBoardState(std::ostream& out);
    bool checkLastPlayerWin();
};

