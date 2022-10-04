#include "func.h"

int TTT::mode()
{
  int gameMode;
  bool valid = false;

  cout << "\n============= Game Mode =============" << endl;
  cout << "\t[1] 1 vs Computer (1 Player)" << endl;
  cout << "\t[2] 1 vs 1 (2 Players)" << endl;
  cout << "=====================================" << endl;

  cout << "\nChoose a game mode (Enter 1 or 2): ";

  do
  {
    cin >> gameMode;

    switch(gameMode)
    {
      case 1:
      case 2:
        valid = true;
        break;
      default:
        cout << "\nINVALID INPUT. Input must be 1 or 2." << endl;
        cout << "Enter a different input (1 or 2): ";
    }
  } while (!valid);

  return gameMode;
}

int TTT::turn()
{
  int num = rand() % 10 + 1;
  int turn;

  if (num <= 5)
  {
    turn = 1;
  }
  else 
  {
    turn = 2;
  }

  return turn;
}

void TTT::displayBoard()
{
  string line = "\t- - - - - - -";

  cout << "\tBoard" << endl;
  cout << line << endl;
  for (int i = 1; i <= 9; i++)
  {
    if (i == 1 || i == 4 || i == 7)
    {
      cout << "\t| ";
    }

    cout << board[i - 1] << " | ";

    if (i % 3 == 0)
    {
      cout << endl;
      cout << line << endl;
    }
  }

  return;
}

void TTT::playerMove(const string turn)
{
  int location;
  bool valid = false;

  cout << "Player" << turn << "'s turn (1-9): ";

  do
  {
    cin >> location;

    if (location >= 1 && location <= 9)
    {
      if (board[location - 1] == " ")
      {
        valid = true;

        if (turn == "1" || turn == "")
        {
          board[location - 1] = "X";
        }
        else 
        {
          board[location - 1] = "O";
        }
      }
    }

    if (!valid) 
    {
      cout << endl;
      cout << "INVALID MOVE" << endl;
      cout << "Enter a different move (1-9): ";
    }
  } while (!valid);

  cout << endl;

  return;
}

void TTT::computerMove()
{
  int num = rand() % 10;
  char symbol = 'O';
  int move;
  int choice;
  bool valid;
  bool moved = false;

  string row1 = board[0] + board[1] + board[2];
  string row2 = board[3] + board[4] + board[5];
  string row3 = board[6] + board[7] + board[8];
  string col1 = board[0] + board[3] + board[6];
  string col2 = board[1] + board[4] + board[7];
  string col3 = board[2] + board[5] + board[8];
  string diag1 = board[0] + board[4] + board[8];
  string diag2 = board[2] + board[4] + board[6];

  if (num < 4)
  {
    valid = false;
    
    do
    {
      move = rand() % 9;

      if (board[move] == " ")
      {
        board[move] = symbol;
        choice = move + 1;
        valid = true;
      }
    } while (!valid);
  }
  else 
  {
    for (int i = 0; i < 2; i++)
    {
      if (count(row1.begin(), row1.end(), symbol) == 2)
      {
        if (count(row1.begin(), row1.end(), ' ') == 1 && !moved)
        {
          moved = true;

          if (board[0] == " ")
          {
            board[0] = "O";
            choice = 1;
          }
          else if (board[1] == " ")
          {
            board[1] = "O";
            choice = 2;
          }
          else
          {
            board[2] = "O";
            choice = 3;
          }
        }
      }

      if (count(row2.begin(), row2.end(), symbol) == 2)
      {
        if (count(row2.begin(), row2.end(), ' ') == 1 && !moved)
        {
          moved = true;
          
          if (board[3] == " ")
          {
            board[3] = "O";
            choice = 4;
          }
          else if (board[4] == " ")
          {
            board[4] = "O";
            choice = 5;
          }
          else
          {
            board[5] = "O";
            choice = 6;
          }
        }
      }
      
      if (count(row3.begin(), row3.end(), symbol) == 2)
      {
        if (count(row3.begin(), row3.end(), ' ') == 1 && !moved)
        {
          moved = true;
          
          if (board[6] == " ")
          {
            board[6] = "O";
            choice = 7;
          }
          else if (board[7] == " ")
          {
            board[7] = "O";
            choice = 8;
          }
          else
          {
            board[8] = "O";
            choice = 9;
          }
        }
      }
      
      if (count(col1.begin(), col1.end(), symbol) == 2)
      {
        if (count(col1.begin(), col1.end(), ' ') == 1 && !moved)
        {
          moved = true;
          
          if (board[0] == " ")
          {
            board[0] = "O";
            choice = 1;
          }
          else if (board[3] == " ")
          {
            board[3] = "O";
            choice = 4;
          }
          else 
          {
            board[6] = "O";
            choice = 7;
          }
        }
      }
      
      if (count(col2.begin(), col2.end(), symbol) == 2)
      {
        if (count(col2.begin(), col2.end(), ' ') == 1 && !moved)
        {
          moved = true;
          
          if (board[1] == " ")
          {
            board[1] = "O";
            choice = 2;
          }
          else if (board[4] == " ")
          {
            board[4] = "O";
            choice = 5;
          }
          else 
          {
            board[7] = "O";
            choice = 8;
          }
        }
      }
      
      if (count(col3.begin(), col3.end(), symbol) == 2)
      {
        if (count(col3.begin(), col3.end(), ' ') == 1 && !moved)
        {
          moved = true;
          
          if (board[2] == " ")
          {
            board[2] = "O";
            choice = 3;
          }
          else if (board[5] == " ")
          {
            board[5] = "O";
            choice = 6;
          }
          else
          {
            board[8] = "O";
            choice = 9;
          }
        }
      }

      if (count(diag1.begin(), diag1.end(), symbol) == 2)
      {
        if (count(diag1.begin(), diag1.end(), ' ') == 1 && !moved)
        {
          moved = true;
          
          if (board[0] == " ")
          {
            board[0] = "O";
            choice = 1;
          }
          else if (board[4] == " ")
          {
            board[4] = "O";
            choice = 5;
          }
          else 
          {
            board[8] = "O";
            choice = 9;
          }
        }
      }
      
      if (count(diag2.begin(), diag2.end(), symbol) == 2)
      {
        if (count(row1.begin(), row1.end(), ' ') == 1 && !moved)
        {
          moved = true;
          
          if (board[2] == " ")
          {
            board[2] = "O";
            choice = 3;
          }
          else if (board[4] == " ")
          {
            board[4] = "O";
            choice = 5;
          }
          else 
          {
            board[6] = "O";
            choice = 7;
          }
        }
      }

      symbol = 'X';
    }

    if (!moved)
    {
      valid = false;

      do
      {
        move = rand() % 9;
        if (board[move] == " ")
        {
          board[move] = "O";
          choice = move + 1;
          valid = true;
        }
      } while (!valid);
    }
  }

  cout << "Computer's Move: " << choice << endl << endl;

  return;
}

bool TTT::checkWinning()
{
  bool win = false;

  if (board[0] == board[1] && board[1] == board[2] )
  {
    if (board[0] != " " && board[1] != " " && board[2] != " ")
    {
      win = true;
    }
  }
  else if (board[3] == board[4] && board[4] == board[5])
  {
    if (board[3] != " " && board[4] != " " && board[5] != " ")
    {
      win = true;
    }
  }
  else if (board[6] == board[7] && board[7] == board[8])
  {
    if (board[6] != " " && board[7] != " " && board[8] != " ")
    {
      win = true;
    }
  }
  else if (board[0] == board[3] && board[3] == board[6])
  {
    if (board[0] != " " && board[3] != " " && board[6] != " ")
    {
      win = true;
    }
  }
  else if (board[1] == board[4] && board[4] == board[7])
  {
    if (board[1] != " " && board[4] != " " && board[7] != " ")
    {
      win = true;
    }
  }
  else if (board[2] == board[5] && board[5] == board[8])
  {
    if (board[2] != " " && board[5] != " " && board[8] != " ")
    {
      win = true;
    }
  }
  else if (board[0] == board[4] && board[4] == board[8])
  {
    if (board[0] != " " && board[4] != " " && board[8] != " ")
    {
      win = true;
    }
  }
  else if (board[2] == board[4] && board[4] == board[6])
  {
    if (board[2] != " " && board[4] != " " && board[6] != " ")
    {
      win = true;
    }
  }

  return win;
}

bool TTT::checkTie()
{
  bool tie = true;

  for (int i = 0; i < 9; i++)
  {
    if (board[i] == " ")
    {
      tie = false;
    }
  }

  return tie;
}

void TTT::updateScore(const int winner)
{
  switch(winner)
  {
    case 1:
      p1Score += 1;
      break;
    case 2:
      p2Score += 1;
      break;
  }
}

void TTT::displayScore(const int mode)
{
  cout << "\n===== Current Score =====" << endl;

  switch (mode)
  {
    case 1:
      cout << "\tYou: " << getPlayer1Score() << endl;
      cout << "\tComputer: " << getPlayer2Score() << endl;
      break;
    case 2:
      cout << "\tPlayer1: " << getPlayer1Score() << endl;
      cout << "\tPlayer2: " << getPlayer2Score() << endl;
      break;
  }
  
  cout << "==========================" << endl;

  return;
}

bool TTT::anotherRound()
{
  bool playAgain;
  string userInput;
  bool valid;

  cout << "\nPlay Another Round? (Y/N): ";

  do
  {
    cin >> userInput;

    if (userInput == "y" || userInput == "Y")
    {
      valid = true;
      playAgain = true;
    }
    else if (userInput == "n" || userInput == "N")
    {
      valid = true;
      playAgain = false;
    }
    else 
    {
      cout << "\nINVALID INPUT. Input must be Y/y or N/n." << endl;
      cout << "Enter a different input (Y/N): ";
    }

  } while (!valid);
  
  return playAgain;
}

void TTT::clearBoard()
{
  for (int i = 0; i < 9; i++)
  {
    board[i] = " ";
  }

  return;
}

void TTT::resetGame()
{
  for (int i = 0; i < 9; i++)
  {
    board[i] = " ";
  }

  p1Score = 0;
  p2Score = 0;

  return;
}

bool TTT::changeMode()
{
  bool change;
  int userInput;
  bool valid = false;

  cout << "\nWould you like to change game mode or quit?" << endl;
  cout << "* Warning: changing mode will reset the scores *" << endl;
  cout << "Enter 1 to change mode or 2 to quit: ";

  do
  {
    cin >> userInput;

    switch (userInput)
    {
      case 1:
        valid = true;
        change = true;
        break;
      case 2:
        valid = true;
        change = false;
        break;
      default:
        cout << "\nINVALID INPUT. Inpput must be 1 or 2." << endl;
        cout << "Enter another input (1 or 2): ";
    }

  } while (!valid);
  
  return change;
}

void TTT::goodbyeMsg()
{
  cout << "\n=====================================" << endl;
  cout << "-------------------------------------" << endl;
  cout << ">> Thank You for playing the game! <<" << endl;
  cout << "-------------------------------------" << endl; 
  cout << "=====================================" << endl;

  return;
}