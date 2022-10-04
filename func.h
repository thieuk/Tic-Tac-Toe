#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>
#include <stdlib.h>   
#include <ctime> 
#include <algorithm>
using namespace std;

class TTT
{
  public:
    // get user input for their choice of game mode
    // pre: none
    // post: return 1 for 1 player mode or 2 for 2 player mode
    int mode();

    // user to random generator to determine who gets first turn
    // pre: none
    // post: return 1 if player1 gets first turn else return 2
    int turn();

    // display the board
    // pre: none
    // post: the board is displayed
    void displayBoard();

    // fill the a user chosen square with either X or O 
    // pre: string turn must be "1", "2", or "" 
    // post: a square on the board will be filled
    void playerMove(const string turn);

    // fill the a square with either X or O 
    // post: a square on the board will be filled
    void computerMove();

    // clear the board and set the scores to 0
    // pre: none
    // post: all elements of board[9] are set to " "
    //       the score are set to 0
    void resetGame();

    // check if any player's won
    // pre: none
    // post: return true if someone won else return false
    bool checkWinning();

    // check if no more move is available
    // pre: none
    // post: return true if the board is filled else return false
    bool checkTie();

    // display the scores
    // pre: int mode must be 1 or 2
    // post: the scores are displayed
    void displayScore(const int mode);

    // update the scores
    // pre: int winner must be 1 or 2
    // post: increment the winner score 
    void updateScore(const int winner);

    // get user input for whether they want to play another round
    // pre: none
    // post: return true if they want to play another round
    //       else return false
    bool anotherRound();

    // clear the board
    // pre: none
    // post: replace all the elements in board[9] with " "
    void clearBoard();

    // get user input for whether they want to change game mode
    // pre: none
    // post: return true if they want to change more else return false
    bool changeMode();

    // display goodbye message
    // pre: none
    // post: thank you message is displayed 
    void goodbyeMsg();

    // Accessors 
    inline int getPlayer1Score() { return p1Score; }
    inline int getPlayer2Score() { return p2Score; }
  private:
    string board[9] = 
      { " ", " ", " ", 
        " ", " ", " ", 
        " ", " ", " " }; 
    int p1Score = 0;
    int p2Score = 0;
};

// run the 1 player game
// pre: none
// post: the game mode of 1 vs Ai is run
void gameMode1();

// run the 2 players game
// pre: none
// post: the game mode of 1 vs 1 is run
void gameMode2();

#endif