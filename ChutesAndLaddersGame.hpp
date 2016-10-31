//
//  ChutesAndLaddersGame.hpp
//

#pragma once

#include <stdio.h>
#include <string>

#include "ArrayQueue.h"
#include "Player.hpp"
#include "GameBoard.hpp"

using namespace std;

// TO DO - change the default value to the number of your team members
static const int MIN_NUMBER_OF_PLAYERS = 2;

class ChutesAndLaddersGame {
public:
   // TODO: implement the constructor with all your team members
   // constructor with the default value of 2 minimim players
   ChutesAndLaddersGame(int nPlayers = MIN_NUMBER_OF_PLAYERS);

   // TODO: implement the destructor
   // destructor
   ~ChutesAndLaddersGame();

   // accessors
   // TO DO: implement the accessor to get the number Of Players
   long getNumberOfPlayers() {
      // TODO: implement this function properly
      if (playerOrder.size() < 2)
      {throw std::logic_error("Not enough players!");}
      return playerOrder.size();
   }
   string getWinner() { return winner; }

   // TODO: implement this function properly
   // reset the game - (1) this will reset the position of each player to zero
   void resetGame();

   // TODO: implement this function properly
   // play the Chutes and Ladders game
   void playGame();
   const void addMembers(int _nPlayers){
     players[0].setName("Nan");
     players[1].setName("Ellie");
     for (int i = 0; i < _nPlayers; i++){
     playerOrder.enqueue(players[i].getName());}
   }

   bool haveWinner() {
     for (int i = 0; i < getNumberOfPlayers(); i++){
       if (players[i].getPostion() == WINNING_POSITION){
         winner = players[i].getName();
         return true;
       }
     }
     return false;
   }

private:
   static const int WINNING_POSITION = 100;

   string winner;       // the winner
   GameBoard gameBoard; // the game board
   ArrayQueue<string> playerOrder;
   // TO DO: use ArrayQueue to store the players
   Player *players;
};
