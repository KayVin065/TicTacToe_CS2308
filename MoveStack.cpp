// File Name: MoveStack.cpp
//
// Author: Kayla Vincent
// Collaborators: none
// Date: 4/13/2023
// Assignment Number: 6
// CS 2308 Spring 2023
//
// Implementation of the MoveStack member functions. Includes 
// a default constructor and destructor. The MoveStack class 
// keeps track of all past moves made by the players. A linked 
// list is used to store the Moves.

#include <iostream>
#include <cassert>
#include "MoveStack.h"
using namespace std;

//***********************************************************
// MoveStack(): default constructor for the MoveStack class.
//     Takes no arguments, but assigns the private MoveNode
//     head to nullptr
//***********************************************************
MoveStack :: MoveStack() {
  head = nullptr;
}

//***********************************************************
// ~MovStack(): destructor for the MoveStack class. 
//     Deallocates memory assigned to MoveNodes.
//***********************************************************
MoveStack :: ~MoveStack() {
  delete head;
}

//***********************************************************
// getSize: a function that counts the number of Moves 
//     currently on the stack
// returns: size of the stack (int)
//***********************************************************
int MoveStack :: getSize() {
  Move *p = head;
  int count = 0;

  while(p != nullptr) {
    count++;
    p = p->next;
  }

  return count;
}

//***********************************************************
// top: a function that finds the Move on the top of the 
//     stack. First checks if the stack is empty.
// returns: the Move instance on the top (Move)
//***********************************************************
Move MoveStack :: top() {
  assert(!isEmpty());
  return *head;
}

//***********************************************************
// push: a function that adds a new Move to the top of the  
//     stack. First checks if the stack is full. 
// move: the Move instance to be added to the top
// returns: void
//***********************************************************
void MoveStack :: push(Move move) {
  assert(!isFull());
  
  Move *newNode = new Move;
  newNode->x = move.x;
  newNode->y = move.y;
  //newNode->next = nullptr;

  if(head == nullptr) { //checks if head is empty
    head = newNode;
  }
  else {
    newNode->next = head;
    head = newNode;
  }
}

//***********************************************************
// pop: a function that removes the Move at the top of the 
//     stack. First checks if the stack is empty. 
// returns: void
//***********************************************************
void MoveStack :: pop() {
  assert(!isEmpty());
  
  Move *p = head;
  head = head->next;
  delete p;
}

//***********************************************************
// isEmpty: a function that determines if the stack is empty 
// returns: true if head is a nullptr, false if head is not
//     a nullptr
//***********************************************************
bool MoveStack :: isEmpty() {
  if(head != nullptr)
    return false;
  else 
    return true;
}