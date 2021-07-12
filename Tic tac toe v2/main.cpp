#include <iostream>
using namespace std;
#include <random>
#include <ctime>
#include <string>
char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

void show_board();
void player_vs_player();
void player_vs_computer();
void player_x_choice();
void player_o_choice();
int count_board(char symbol);
char check_winner();
void computer_choice();

int main()
{
	int mode;
	cout << "1.Player_vs_Player" << endl;
	cout << "2.Player_vs_Computer" << endl;
	cout << "---Select your mode---" << endl;
	cin >> mode;
	switch (mode)
	{
	case 1:
		player_vs_player();
		break;
	case 2:
		player_vs_computer();
		break;
	default:
		cout << "Please select mode" << endl;
		break;
	}

	return 0;
}

void player_vs_computer()
{
	string player;
	cout << "Player name: ";
	cin >> player;
	while (true)
	{
		system("cls");
		show_board();
		if (count_board('X') == count_board('O'))
		{
			cout << "Please select 1-9" << endl;
			player_x_choice();
		}
		else
		{
			computer_choice();
		}
		char winner = check_winner();
		if (winner == 'X')
		{
			system("cls");
			show_board();
			cout << player << "'s is winner!" << endl;
			break;
		}
		else if (winner == 'O')
		{
			system("cls");
			show_board();
			cout << "Computer's is winner!" << endl;
			break;
		}
		else if (winner == 'D')
		{
			cout << "Game is draw!" << endl;
			break;
		}
	}
}

void player_vs_player()
{
	string player_x, player_o;
	cout << "Player x name: ";
	cin >> player_x;
	cout << "Player o name: ";
	cin >> player_o;

	while (true)
	{
		system("cls");
		show_board();
		if (count_board('X') == count_board('O'))
		{
			cout << "Please select 1-9" << endl;
			player_x_choice();
		}
		else
		{
			cout << "Please select 1-9" << endl;
			player_o_choice();
		}
		char winner = check_winner();
		if (winner == 'X')
		{
			system("cls");
			show_board();
			cout << player_x << "'s is winner!" << endl;
			break;
		}
		else if (winner == 'O')
		{
			system("cls");
			show_board();
			cout << player_o << "'s is winner!" << endl;
			break;
		}
		else if(winner == 'D')
		{ 
			cout << "Game is draw!" << endl;
			break;
		}
	}
}

void computer_choice()
{
	int choice;
	srand(time(0));
	do
	{
		choice = rand() % 10;
	} while (board[choice] != ' ');
	board[choice] = 'O';
}

void player_x_choice()
{
	while (true)
	{
		int choice;
		cin >> choice;
		choice--;
		if (choice < 0 || choice > 8)
		{
			cout << "Please choose the potion 1-9" << endl;
		}
		else if(board[choice] != ' ')
		{
			cout << "Please choose an empty potition" << endl;
		}
		else
		{
			board[choice] = 'X';
			break;
		}
	}
}

void player_o_choice()
{
	while (true)
	{
		int choice;
		cin >> choice;
		choice--;
		if (choice < 0 || choice > 8)
		{
			cout << "Please choose the potion 1-9" << endl;
		}
		else if (board[choice] != ' ')
		{
			cout << "Please choose an empty potition" << endl;
		}
		else
		{
			board[choice] = 'O';
			break;
		}
	}
}
	
int count_board(char symbol)
{
	int total = 0;
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == symbol)
		{
			total += 1;
		}
		
	}
	return total;
}


char check_winner()
{
	if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
	{
		return board[0];
	}
	if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
	{
		return board[3];
	}
	if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
	{
		return board[6];
	}

	if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
	{
		return board[0];
	}
	if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
	{
		return board[1];
	}
	if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
	{
		return board[2];
	}

	if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
	{
		return board[0];
	}
	if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
	{
		return board[2];
	}

	if (count_board('X') + count_board('O') < 9)
	{
		return 'C';
	}
	else
	{
		return 'D';
	}
}

void show_board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player (X)  -  Player  (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;

	cout << "     |     |     " << endl << endl;
	
}