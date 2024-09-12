// File Name: main.cpp
//
// Author: Kayla Vincent
// Collaborators: Makenna Wilson
// Date: 4/17/2023
// Assignment Number: 6
// CS 2308 Spring 2023
//
// Contains the main game loop for a game of Tic-Tac-Toe.
// Players enter their move as "move x y", where x and y 
// are int values between 0 and 2. Players may also undo 
// the last move of their opponent by entering "undo". If 
// the win condition is reached or there is a draw, the 
// program is terminated and the game ends.

#include <iostream>
#include <sstream>
using namespace std;
#include "GameState.h"

int main(){
  MoveStack m;
  GameState newGame;
  string command;
  int player, x, y; 
  bool draw = false;

  newGame.displayBoardState(cout); //outputs blank game board

  //loops until there is a winner or a draw
  while((!newGame.checkLastPlayerWin()) && (draw == false)){
    player = newGame.getCurrentPlayer();
    
    cout << "Player " << player << " make a turn." << endl;
    cin >> command;
    
    if(command == "move") { //make a move
      cin >> x >> y;
      int num = newGame.addMove(Move(x,y));

      if(num == -1) { //if the target is full
        cout << "Incorrect move. Please try again." << endl;
      }
      else if(num == 0) { //if the board is full
        newGame.displayBoardState(cout);
        draw = true;
        cout << "It's a draw!" << endl;
      }
      else { //if the move was successful
        newGame.displayBoardState(cout);
      }
    }  
    else if(command == "undo") { //undo a move
      if(newGame.undoLast()) {
        newGame.displayBoardState(cout);
      }
      else {
        cout << "No moves to undo." << endl;
      }
    }
    else {
      cout << "Invalid command" << endl;
    }
  }

  if(!draw) {
    cout << "Player " << player << " won!" << endl;
  }
  
  return 0;
} 