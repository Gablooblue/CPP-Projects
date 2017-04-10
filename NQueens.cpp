#include <iostream>
#include <unistd.h>

using namespace std;

/**
 * TODO Refactor this shit
 */
bool isValid(int row, int col, int board[8][8]);
void placeQueen(int row, int col, int board[8][8]);
bool backtrack(int row, int board[8][8], int queenNum);
void printBoard(int board[8][8]);

int main()
{

    int i, j, queenNum = 0, n = 0;
    int board[8][8];

    do
    {
	cout << "Enter a number from 1-8 > ";
	cin >> n;
    }while(n < 1 || n > 8);
    
    n--;

    for(i = 0; i < 8; i++)
    {
	for(j = 0; j < 8; j++)
	{
	    board[i][j] = 0;
	}
    }
    
    
    if(!backtrack(n, board, 0))
    {
	cout << "NO SOLUTION";
	return 0;
    }

    printBoard(board);
}

bool isValid(int row, int col, int board[8][8])
{
    int i, j;
    //checking horizontally
    for(i = 0; i < 8; i++)
    {
	if(board[row][i] == 1)
	{
	    return false;
	}
    }
    //checking vertically 
    for(j = 0; j < 8; j++)
    {
	if(board[j][col] == 1)
	{
	    return false;
	}
    }
   
    //checking up-left
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
	if(board[i][j] == 1)
	{
	    return false;
	}
    }

    //checking down-right
    for(i = row, j = col; i < 8 && j < 8; i++, j++)
    {
	if(board[i][j] == 1)
	{
	    return false;
	}
    }

    //checking down-left
    for(i = row, j = col; i >= 0 && j < 8; i--, j++)
    {
	if(board[i][j] == 1)
	{
	    return false;
	}
    }

    //checking up-right
    for(i = row, j = col; i < 8 && j >= 0; i++, j--)
    {
	if(board[i][j] == 1)
	{
	    return false;
	}
    }

    return true;
}

bool backtrack(int row, int board[8][8], int queenNum)
{
    int j;

    if( queenNum == 8)
    {
	return true;
    }
    else if( row >= 8 && queenNum < 8 )
    {
	row = 0;
    }
    

    for(int i = 0; i < 8; i++)
    {
	if(isValid(row , i, board))
	{
	    queenNum++;
	    board[row][i] = 1;
	    printBoard(board);
	    cout << queenNum << " queens placed" << endl;
	    if(backtrack(row+1,board, queenNum))
	    { 
		return true;
	    }
	    else
	    {
		board[row][i] = 0;
		queenNum--;
	    }
	}
    }

    return false;
}

void printBoard(int board[8][8])
{
    for(int i = 0; i < 8; i++)
    {
	for(int j = 0; j < 8; j++)
	{
	    if(board[i][j])
	    {
		cout << "Q";
	    }
	    else
	    {
		cout << " ";
	    }
	    cout << "|";
	}
	cout << endl;
    }
    // WARNING USLEEP DOES NOT WORK ON WINDOWS COMPUTERS
    // REMOVE OR REPLACE THIS LINE IF YOU'RE USING WINDOWS
    usleep(50000);
    cout << endl;
}
