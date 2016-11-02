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
      if (playerOrder.size() < 2)                           //check if there is enough players
      {throw std::logic_error("Not enough players!");}      //if not, throw an error exception
      return playerOrder.size();                            
   }
   string getWinner() { return winner; }

   // TODO: implement this function properly
   // reset the game - (1) this will reset the position of each player to zero
   void resetGame();

   // TODO: implement this function properly
   // play the Chutes and Ladders game
   void playGame();
   
   void addMembers(){                                       //a function to add team members into the player array queue
      Player player1("Nan");                                 
      Player player2("Ellie");
      playerOrder.enqueue(player1);
      playerOrder.enqueue(player2);
   }
   
private:
   static const int WINNING_POSITION = 100;

   string winner;       // the winner
   GameBoard gameBoard; // the game board
   ArrayQueue<Player> playerOrder;
   // TO DO: use ArrayQueue to store the players
};
