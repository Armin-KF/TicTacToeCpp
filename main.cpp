#include <iostream>
using namespace std;

void displayBoard(string board[3][3])
{
  cout << "+---+---+---+" << endl;
  for (int i = 0; i < 3; i++)
  {
    cout << "|";
    for (int j = 0; j < 3; j++)
    {
      cout << " " << board[i][j] << " |";
    }
    cout << endl;
    cout << "+---+---+---+" << endl;
  }
}

bool setPlayer(string board[3][3], char player)
{
  int row, col;
  while (true)
  {
    cout << "Player " << player << " Turn: " << endl;
    cout << "Enter the row and column number - for example : 0-2 " << endl;
    cin >> row >> col;
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == " ")
    {
      board[row][col] = player;
      return true;
    }
    else
    {
      cout << "Invalid Move" << endl;
    }
  }
}

bool checkWinner(string board[3][3], char &winner)
{
  // Check rows and columns
  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != " ")
    {
      winner = board[i][0][0];
      return true;
    }
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != " ")
    {
      winner = board[0][i][0];
      return true;
    }
  }
  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != " ")
  {
    winner = board[0][0][0];
    return true;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != " ")
  {
    winner = board[0][2][0];
    return true;
  }
  // Check draw
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] == " ")
      {
        return false; // Game continues
      }
    }
  }
  winner = 'D'; // Draw
  return true;
}

int main()
{
  string board[3][3] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};
  displayBoard(board);
  char winner = ' ';
  for (int i = 0; i < 9 && winner == ' '; i++)
  {
    if (!setPlayer(board, i % 2 == 0 ? 'X' : 'O'))
    {
      cout << "Error setting player move." << endl;
      return -1;
    }
    displayBoard(board);
    if (checkWinner(board, winner))
    {
      if (winner != 'D')
      {
        cout << "Player " << winner << " Wins!" << endl;
      }
      else
      {
        cout << "Game Draw" << endl;
      }
      return 0;
    }
  }
  return 0;
}