//
//  Player.cpp
//

#include "Player.hpp"

// TO DO: implement Player's assignment operator
Player& Player::operator=(const Player& p) {
   // TODO: implement this function properly
   if (&p != this){
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
   if (position > 100 || position < 0)
   throw std::length_error("Position out of board!");
   GameBoard check;
   die.roll();
   int temp = position + die.getFaceValue();
   if (temp > 100){
      return position;
   };
   temp = check.checkChutesLadders(temp);
   position = temp;
      return position;
}
