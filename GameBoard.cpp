//
//  GameBoard.cpp
//

#include "GameBoard.hpp"

// Build the gameboard
// If the landing square is a chute, set the position to the corresponding lower square
// I.e., player slides down to the lower square
// If the landing square is a ladder, set the position to the corresponding higher square
// Player climbs up to the higher square
// Otherwise, player stays put at the landing square
// TO DO: implement this method
void GameBoard::buildBoard() {
   // TODO: implement this function properly
   for (int i = 1; i < BOARD_SIZE; i++){
      squares.insert(i-1, i);
   }
}
