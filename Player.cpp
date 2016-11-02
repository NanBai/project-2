//
//  Player.cpp
//

#include "Player.hpp"

// TO DO: implement Player's assignment operator
Player& Player::operator=(const Player& p) {
   // TODO: implement this function properly
   if (&p != this){                                    //check self-assignment
      playerName = p.playerName;
      position = p.position;
      die = p.die;
   }
   return *this;
}

// return player's new position after player rolls die
// If the new position is outside of the board, player stays put
// If not, player moves to the new square = player's postion + die's face value
// TO DO: implement this function to move player to the new postion
//        after player rolls die. Position must be inside the board
int Player::rollDieAndMove() {
   // TODO: implement this function properly
   if (position > 100 || position < 0)                         //check if player's position is outside the board or not
   throw std::length_error("Position out of board!");
   GameBoard check;                                            //declare a GameBoard type variable
   die.roll();                                                 //roll die
   int temp = position + die.getFaceValue();                   //store the position in a temporary integer variable 
   if (temp > 100){                                            //check if the position after rolling die is outside the board
      return position;                                         //if it is outside the board, player stay put
   };
   temp = check.checkChutesLadders(temp);                      //if not, check if player's new position is at a chute or
   position = temp;                                            //ladder or not
      return position;                                         
}
