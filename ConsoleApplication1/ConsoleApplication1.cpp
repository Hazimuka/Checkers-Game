// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


class CheckerBoard
{
public:
	CheckerBoard(void);
	void initBoard();
	void printBoard();

	int getXCoord();
	int getYCoord();
	int getXCoordOfPiece();
	int getYCoordOfPiece();


	int xCoord = getXCoord();
	int yCoord = getYCoord();
	int yInput = getYCoordOfPiece();
	int xInput = getXCoordOfPiece();

	void movePieces(char turn, int  yInput, int xInput, int yCoord, int xCoord);
	void placePieces();

	void playGame();

private:
	char turn = '1';

	char player1 = 'R';
	char player2 = 'B';

	char board[8][8];
};
CheckerBoard::CheckerBoard(void)
{
}

void CheckerBoard::initBoard()
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			board[y][x] = ' ';
		}
	}
}

void CheckerBoard::printBoard()
{
	cout << "  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |\n";
	cout << "-----------------------------------\n";

	for (int y = 0; y < 8; y++)
	{
		int x = 0;
		cout << y + 1 << " | ";
		for (int x = 0; x < 8; x++)
		{
			cout << board[y][x] << " | ";
		}
		cout << endl << "-----------------------------------" << endl;
	}
}

int CheckerBoard::getXCoordOfPiece()
{
	int xInput;
	cout << "Enter X Coordinate of piece you'd like to move: ";
	cin >> xInput;
	return xInput - 1;
}

int CheckerBoard::getYCoordOfPiece()
{
	int yInput;
	cout << "Enter Y Coordinate of piece you'd like to move: ";
	cin >> yInput;
	return yInput - 1;

}

int CheckerBoard::getYCoord()
{
	int yCoord;
	cout << "Enter Y Coordinate of where you want to move.";
	cin >> yCoord;
	return yCoord - 1;
}

int CheckerBoard::getXCoord()
{
	int xCoord;
	cout << "Enter X Coordinate of where you want to move.";
	cin >> xCoord;
	return xCoord - 1;
}

void CheckerBoard::movePieces(char turn, int  yInput, int xInput, int yCoord, int xCoord)
{
	if (turn == '1')
	{
		xInput = getXCoordOfPiece();
		yInput = getYCoordOfPiece();
		if (board[yInput][xInput] == player1)
		{
			xCoord = getXCoord();
			yCoord = getYCoord();
			if (board[yCoord][xCoord] == player1)
			{
				cout << "That move is invalid!";
				cout << yCoord << xCoord;
				system("PAUSE");
				return;
			}
			else if (board[yCoord][xCoord] == player2)
			{
				cout << "That move is invalid!";
				cout << yCoord << xCoord;
				system("PAUSE");
				return;
			}
			else
			{
				board[yInput][xInput] = ' ';
				board[yCoord][xCoord] = player1;
			}
		}
	}

	if (turn == '2')
	{
		xInput = getXCoordOfPiece();
		yInput = getYCoordOfPiece();
		if (board[yInput][xInput] == player1)
		{
			xCoord = getXCoord();
			yCoord = getYCoord();
			if (board[yCoord][xCoord] == player1)
			{
				cout << "That move is invalid!";
				cout << yCoord << xCoord;
				system("PAUSE");
				return;
			}
			else if (board[yCoord][xCoord] == player2)
			{
				cout << "That move is invalid!";
				cout << yCoord << xCoord;
				system("PAUSE");
				return;
			}
			else
			{
				board[yInput][xInput] = ' ';
				board[yCoord][xCoord] = player2;
			}
		}
	}
}

void CheckerBoard::placePieces()
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (((x + y) % 2) == 0)
			{
				board[y][x] = player1;
			}
		}
	}

	for (int y = 5; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (((x + y) % 2) == 1)
			{
				board[y][x] = player2;
			}
		}
	}
}

void CheckerBoard::playGame()
{
	bool isDone = false;

	while (isDone == false)
	{

		initBoard();
		placePieces();
		printBoard();


		movePieces(turn, yInput, xInput, yCoord, xCoord);

		if (turn == '1')
		{
			turn = '2';
		}
		else if (turn == '2')
		{
			turn = '1';
		}
		system("PAUSE");
	}
}

int main()
{



	CheckerBoard checkerBoard;

	checkerBoard.playGame();

	return 0;

}