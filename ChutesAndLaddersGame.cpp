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
   ArrayQueue<Player> playerOrder(nPlayers);      //initialize the player order array queue
   addMembers();                                  //call add player members function
}

// TODO: implement the destructor
// destructor - dequeue players from the queue
ChutesAndLaddersGame::~ChutesAndLaddersGame() {
   // TODO: implement this function properly
   while (!playerOrder.empty()){                  //judge the statement if the queue is empty or not
      playerOrder.dequeue();                      //if not empty, dequeue from the queue
   }
}

// TO DO: implement this function properly
// reset the game - rebuild the list of players
//        (i.e., the list should be the same as in the constructor).
//        Place all players at the figurative square zero
void ChutesAndLaddersGame::resetGame() {
   // TODO: implement this function properly
   if (playerOrder.size() < 2)                        //check if there is enough players
   throw std::logic_error("Not enough players!");   // if empty, throw a exception error
   Player tmp;                                     //declare a temporary Player type variable
   while (playerOrder.front().getPostion() != 0) { //judge statement: if player's position is at 0 square or not
   tmp = playerOrder.front();                       //use the temporary variable to store the front element in the queue
   playerOrder.dequeue();                           //dequeue the front element in the queue
   tmp.setPostion(0);                              //set the player's position to 0 square
   playerOrder.enqueue(tmp);                        //enqueue the player's info from the temporary variable
   }
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
   if (playerOrder.size() < 2)                          //check if there is enough players
   throw std::logic_error("Not enough players.");       //if not, throw an exception error
   Player tmp;                                          //declare a temporary Player type variable to store the front player
   while (playerOrder.front().getPostion() != WINNING_POSITION) {    //judge statement: check if there is a player at
                                                                     // the winning position
      tmp = playerOrder.front();                        //use the temporary to store the front element in the queue
      playerOrder.dequeue();                            //dequeue the front element in the queue
      tmp.rollDieAndMove();                             //player's turn to roll die and move
      playerOrder.enqueue(tmp);                         //enqueue the player to wait his/her turn 
   }
   winner = playerOrder.front().getName();              //assign the winner player's name to the winner variable
   cout << ">> Congratulation! <<" << endl;
   cout << "The winner is > " << winner << " < !" << endl;
}
