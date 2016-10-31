//
//  ChutesAndLaddersGame.cpp
//

#include <iostream>
#include <string>

#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

// TODO: implement the constructor with all your team members
// constructor with the default value of a minimum players
ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : winner("no winner") {
   // TODO: implement this function properly
   players = new Player[nPlayers];
   ArrayQueue<string> playerOrder(nPlayers);
   addMembers(nPlayers);
}

// TODO: implement the destructor
// destructor - dequeue players from the queue
ChutesAndLaddersGame::~ChutesAndLaddersGame() {
   // TODO: implement this function properly
   while (!playerOrder.empty()){
      playerOrder.dequeue();
   }
   delete []players;
}

// TO DO: implement this function properly
// reset the game - rebuild the list of players
//        (i.e., the list should be the same as in the constructor).
//        Place all players at the figurative square zero
void ChutesAndLaddersGame::resetGame() {
   // TODO: implement this function properly
   throw std::logic_error("not implemented yet");
}

// TO DO: implement this function properly
// Play the chutes and ladders until a player reaches the winning square 100
//    - Each player takes turn to roll the die and moves to the new square by invoking rollDieAndMove.
//         If the new square is outside of the board, the player stays put
//    - Player's new position is checked against the game board's checkChutesLadders
//    - checkChutesLadders returns a different square if player lands on a chute or a ladder
//    - Player's position is then set to the new position as indicated by checkChutesLadders
//          If player lands on a chute or a ladder, player slides down or climbs up
//    - If player lands on the winning square 100, game is over
//    - playGame returns after congratulating and printing the winner's name
void ChutesAndLaddersGame::playGame() {
   // TODO: implement this function properly
   if (playerOrder.empty())
   throw std::logic_error("Not enough players.");
   int *tmp = new int[getNumberOfPlayers()];
   while (!haveWinner()) {
     for (int m = 0; m < getNumberOfPlayers(); m++){
      playerOrder.dequeue();
      tmp[m] = players[m].rollDieAndMove();
      tmp[m] = gameBoard.checkChutesLadders(tmp[m]);
      players[m].setPostion(tmp[m]);
      cout << players[m].getName() << "'s position is at " << players[m].getPostion() << endl;
      playerOrder.enqueue(players[m].getName());
     }
   }
   cout << "Congratulation!" << endl;
   cout << "The winner is " << winner << " !" << endl;
}
