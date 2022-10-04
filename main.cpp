#include <iostream>
#include "func.h"
using namespace std;

int main() 
{
  srand(time(NULL));

  TTT game;

  switch (game.mode())
  {
    case 1:
      gameMode1();
      break;
    case 2:
      gameMode2();
      break;
  }

  return 0;
}