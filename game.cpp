#include "func.h"

void gameMode1()
{
  TTT game;
  int firstTurn;
  int currentTurn;
  bool playAgain = true;

  while (playAgain) 
  {
    firstTurn = game.turn();

    cout << "\n==================================" << endl;

    if (firstTurn == 1)
    {
      cout << "\n~ You get first turn this round ~" << endl << endl;
    }
    else 
    {
      cout << "\n~ Computer gets first turn this round ~" << endl << endl;
    }

    for (int i = 1; i < 10; i++)
    {
      if (firstTurn == 1)
      {
        if (i % 2 == 0)
        {
          currentTurn = 2;
          game.computerMove();
        }
        else
        {
          game.displayBoard();
          currentTurn = 1;
          game.playerMove("");
        }
      }
      else
      {
        if (i % 2 == 0)
        {
          game.displayBoard();
          currentTurn = 1;
          game.playerMove("");
        }
        else
        {
          currentTurn = 2;
          game.computerMove();
        }
      }

      if (game.checkWinning())
      {
        game.displayBoard();

        if (currentTurn == 1)
        {
          cout << "\n*** YOU won this round! ***" << endl;
        }
        else 
        {
          cout << "\n*** COMPUTER won this round. ***" << endl;
        }

        game.updateScore(currentTurn);
        game.displayScore(1);
        game.clearBoard();

        break;
      }

      if (game.checkTie())
      {
        game.displayBoard();
        cout << "\n*** It's a tie this round. ***" << endl;
        game.displayScore(1);
        game.clearBoard();

        break;
      }
    }

    if (!game.anotherRound())
    {
      if (game.changeMode())
      {
        switch (game.mode())
        {
          case 1:
            game.resetGame();
            gameMode1();
            break;
          case 2:
            game.resetGame();
            gameMode2();
            break;
        }
      }
      else 
      {
        game.goodbyeMsg();
      }
      
      break;
    }
  }
}

void gameMode2()
{
  TTT game;
  int firstTurn;
  int currentTurn;
  bool playAgain = true;

  while (playAgain) 
  {
    firstTurn = game.turn();

    cout << "\n=======================================" << endl;
    cout << "\n~ Player" << firstTurn << " gets first turn this round ~" << endl << endl;

    for (int i = 1; i < 10; i++)
    {
      game.displayBoard();

      if (firstTurn == 1)
      {
        if (i % 2 == 0)
        {
          currentTurn = 2;
          game.playerMove("2");
        }
        else
        {
          currentTurn = 1;
          game.playerMove("1");
        }
      }
      else
      {
        if (i % 2 == 0)
        {
          currentTurn = 1;
          game.playerMove("1");
        }
        else
        {
          currentTurn = 2;
          game.playerMove("2");
        }
      }

      if (game.checkWinning())
      {
        game.displayBoard();

        cout << "\n*** PLAYER" << currentTurn 
             << " won this round! ***" << endl;

        game.updateScore(currentTurn);
        game.displayScore(2);
        game.clearBoard();

        break;
      }

      if (game.checkTie())
      {
        game.displayBoard();
        cout << "\n*** It's a tie this round. ***" << endl;
        game.displayScore(2);
        game.clearBoard();

        break;
      }
    }

    if (!game.anotherRound())
    {
      if (game.changeMode())
      {
        switch (game.mode())
        {
          case 1:
            game.resetGame();
            gameMode1();
            break;
          case 2:
            game.resetGame();
            gameMode2();
            break;
        }
      }
      else
      {
        game.goodbyeMsg(); 
      }
      
      break;
    }
  }
}