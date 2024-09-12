// File Name: GameState.cpp
//
// Author: Kayla Vincent
// Collaborators: none
// Date: 4/17/2023
// Assignment Number: 6
// CS 2308 Spring 2023
//
// Implementation of the GameState member functions

#include "GameState.h"
#include <cassert>

//***********************************************************
// GameState(): default constructor for the GameState class.
//     Takes no arguments, but initializes the boardState 
//     variable to hold '_' in every element.
//***********************************************************
GameState :: GameState() {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      boardState[i][j] = '_';
    }
  }
}

//***********************************************************
// getCurrentPlayer(): determines whose turn it is based on 
//     the size of the stack of Moves.
// returns: 0 if the size of the stack is even, 1 if size of
//     the stack is odd.
//***********************************************************
int GameState :: getCurrentPlayer() {
  if((moveStack.getSize() % 2) == 0) {
    return 0;
  }
  else {
    return 1;
  }
}

//***********************************************************
// addMove(): updates the state of the board given the move
//     that the player played.
// move: an instance of Move used to determine if the player's
//     move is valid or not.
// returns: -1 if the target position is already full.
//     0 if all positions on board are full.
//     1 if move was successfully done and there are
//     more moves available
//***********************************************************
int GameState :: addMove(Move move) {
  int player = getCurrentPlayer();
  
  if(boardState[move.x][move.y] != '_') { //if target is full
    return -1;
  }
  else { 
    moveStack.push(move); //adds move to the stack
    
    if(player == 0) { //determines 'x' or 'o'
      boardState[move.x][move.y] = 'x'; 
    }
    else {
      boardState[move.x][move.y] = 'o';
    }

    if(moveStack.getSize() == 9) {
      return 0;
    } //if board is full
    else if(moveStack.getSize() < 9) { 
      return 1;
    } //if move done successfully and there are moves left
    else {
      assert(false);
    }    
  }
}

//***********************************************************
//undoLast(): undoes the previous player's turn by emptying 
//     position of previous move and removing the last move 
//     from the stack.
// returns: true if the move was undone, false if there are 
//     no moves to undo (the board is empty)
//***********************************************************
bool GameState :: undoLast() {
  if(moveStack.getSize() == 0) {
    return false;
  }
  else {
    boardState[moveStack.top().x][moveStack.top().y] = '_';
    moveStack.pop();
    return true;
  }
}

//***********************************************************
// displayBoardState(): outputs the current layout of the 
//     board.
// out: the ostream variable that outputs the board state
// returns: void
//***********************************************************
void GameState :: displayBoardState(std::ostream& out) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      out << boardState[i][j];
    }
    out << std :: endl;
  }
}

//***********************************************************
// checkLastPlayerWin(): determines if the last player won 
//     the game.
// returns: true if the last player won, false if not.
//***********************************************************
bool GameState::checkLastPlayerWin() {
    char targetSymbol = getCurrentPlayer() ? 'x' : 'o';
    int sumHorizontal, sumVertical;
    for (int i = 0; i < 3; ++i){
        sumHorizontal = 0;
        sumVertical = 0;
        for (int j = 0; j < 3; ++j){
            sumHorizontal += boardState[i][j] == targetSymbol;
            sumVertical += boardState[j][i] == targetSymbol;
        }
        if (sumHorizontal == 3 || sumVertical == 3)
            return true;
    }
    int sumDiagonal1 = 0, sumDiagonal2 = 0;
    for (int i = 0; i < 3; ++i){
        sumDiagonal1 += boardState[i][i] == targetSymbol;
        sumDiagonal2 += boardState[i][2 - i] == targetSymbol;
    }
    if (sumDiagonal1 == 3 || sumDiagonal2 == 3)
        return true;

    return false;
}
