#include "Player.h"


Pole::Pole() {
	this->n = 9;
	this->m = 9;
	this->matrix = nullptr;
	this->matrix = new char* [n];
	this->step = 0;

	for (int i = 0; i < n; i++)
	{
		this->matrix[i] = new char[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			this->matrix[i][j] = '-';
		}
	}

}




void Pole::printPole(Player& player) {
	++step;
	char arr[9]{ '-','A', 'B', 'C','D','E', 'F','G', 'H' };
	ship--;
	int x = player.getX();
	int y = player.getY();
	char ch = player.getCh();
	int ship = 11;
	matrix[x][y] = ch;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			this->matrix[i][0] = arr[i];
			this->matrix[0][j] = arr[j];
			cout << this->matrix[i][j] << "\t";
		}
		cout << endl;
	}


}



void Pole::printPole(int x, int y, char ch)
{
	if (getWinner() == true) {
		cout << "Game over" << endl;
	}
	else {

		char arr[9]{ '-','A', 'B', 'C','D', 'E', 'F','G', 'H' };
		if (matrix[x][y] == 'X') {
			matrix[x][y] = 'X';
		}
		else if (matrix[x][y] == '*') {

			matrix[x][y] = '-';
		}
		else {
			matrix[x][y] = ch;
		}


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{

				this->matrix[i][0] = arr[i];
				this->matrix[0][j] = arr[j];
				cout << this->matrix[i][j] << "\t";
			}
			cout << endl;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (this->matrix[i][j] == '*') {
					this->matrix[i][j] = '-';
				}
			}
		}
		cout << "Ship = " << ship << endl;
		cout << "Please do not put more than 10 " <<  endl;
	}

}


bool Pole::getWinner()
{
	int sum = 0; //кількість співпадінь
	int sum1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (this->matrix[i][j] == 'X')
				sum++;
			
			if (sum == 1000) {
				cout << "Winner X " << endl;
				return true;
			}
			if (sum1 == 1000) {
				cout << "Winner 0 " << endl;
				return true;
			}
		}
		sum = 0;
		sum1 = 0;
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (this->matrix[j][i] == 'X')
				sum++;

			if (sum == 1000) {
				cout << "Winner X " << endl;
				return true;
			}
			if (sum1 == 1000) {
				cout << "Winner 0 " << endl;
				return true;
			}
		}
		sum = 0;
		sum1 = 0;
	}

	if (this->step >= 9) {
		cout << "Draw " << endl;

	}

	return false;
}