#include <iostream>
#include <vector>

using namespace std;


class Solution
{
private:

  bool isValid(int row, int col, vector<vector<char>> &board, char val)
  { // Checking the presence of the element
    for (int i = 0; i < 9; i++)
    {
      if (board[row][i] == val) // row check
        return false;
      if (board[i][col] == val) // column check
        return false;

      if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == val) // 3x3 matrix check
        return false;
    }
    return true;
  }



  

public:

  bool Solve(vector<vector<char>> &board)
  {
    int n = board[0].size();

    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < n; col++)
      {
        if (board[row][col] == '_')
        {
          for (char i = '1'; i <= '9'; i++)
          {
            if (isValid(row, col, board, i))
            {
              board[row][col] = i;

              if (Solve(board))
                return true;
              else
                board[row][col] = '_';
            }
          }
          return false;
        }
      }
    }
    return true;
  }


  void print(vector<vector<char>> &board)    //Print Sudoku Matrix
  {
    cout << " ___________________________________" << endl;
    cout << "|   |   |   |   |   |   |   |   |   |" << endl;
    for (int i = 0; i < 9; i++)
    {
      cout << "| ";
      for (int j = 0; j < 9; j++)
      {
        cout << board[i][j];

        if (j == 8)
          cout << " |";
        else
          cout << " | ";
      }
      cout << endl;

      if (i == 8)
        cout << "|___|___|___|___|___|___|___|___|___|" << endl;
      else
      {
        cout << "|___|___|___|___|___|___|___|___|___|" << endl;
        cout << "|   |   |   |   |   |   |   |   |   |" << endl;
      }
    }
  }
};

int main()
{
  Solution sudoku;
  vector<vector<char>> board;


  // Default input

  board.push_back({'_', '_', '2', '_', '8', '_', '_', '6', '_'});
  board.push_back({'_', '5', '6', '9', '1', '7', '_', '3', '_'});
  board.push_back({'_', '4', '_', '_', '5', '_', '8', '7', '1'});
  board.push_back({'_', '9', '_', '_', '_', '_', '6', '_', '_'});
  board.push_back({'6', '7', '1', '_', '9', '5', '2', '_', '_'});
  board.push_back({'_', '_', '_', '_', '2', '_', '1', '_', '_'});
  board.push_back({'1', '6', '7', '_', '3', '_', '5', '9', '_'});
  board.push_back({'4', '8', '_', '_', '7', '_', '3', '_', '_'});
  board.push_back({'_', '2', '5', '4', '6', '_', '_', '_', '_'});

  // User Input

  // Use '_' for empty val

  // for(int row=0;row<9;row++)
  // {
  //     vector<char>temp;
  //     for(int col=0;col<9;col++)
  //     {
  //         char val;
  //         cin>>val;
  //         temp.push_back(val);
  //     }
  //     board.push_back(temp);
  //     temp.clear();
  //}


  cout<<"Solve the following Sudoku :"<<endl;
  sudoku.print(board); 
  cout<<endl<<endl;
  ;

  if(sudoku.Solve(board))
  {
    cout<<"Congratulations!! , Your Sudoku is Successfully Solved."<<endl<<endl;
    sudoku.print(board);
    cout<<endl<<endl;
    
  }
   else
   {
    cout<<"Sorry!! Can't be Solved , Please put Valid Sudoku input."<<endl;
   }
  
  
}