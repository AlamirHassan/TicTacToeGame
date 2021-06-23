// This program is an X-O game
#include <iostream>
#include <string>
using namespace std;
void printArray(char arr[], int n);
char checkWinner(char arr[], int n);

int main() {

	cout << "        X-O Game\n";
	cout << "Player 1 <x> - Player 2 <y>\n";

	char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

	printArray(arr, 9);

	int temp;
	int flag = 0;
	char winner;
	do {
		cout << "Player 1, enter a number: ";
		do {
			cin >> temp;
			if (arr[temp - 1] == 'X' || arr[temp - 1] == 'O')
				cout << "this was choosed before\n";
			if (temp > 9 || temp < 1)
				cout << "Invalid location\n";
		} while ((arr[temp - 1] == 'X' || arr[temp - 1] == 'O') || (temp > 9 || temp < 1));
		
		arr[temp - 1] = 'X';

		printArray(arr, 9);

		winner = checkWinner(arr, 9);

		if (winner == 'X') {
			cout << "\tX wins\n";
			break;
		}
		
		
		cout << "Player 2, enter a number: ";
		do {
			cin >> temp;
			if (arr[temp - 1] == 'X' || arr[temp - 1] == 'O')
				cout << "this was choosed before\n";
			if (temp > 9 || temp < 1)
				cout << "Invalid location\n";
		} while ((arr[temp - 1] == 'X' || arr[temp - 1] == 'O') || (temp > 9 || temp < 1));
		
		arr[temp - 1] = 'O';

		printArray(arr, 9);

		winner = checkWinner(arr, 9);

		if (winner == 'O') {
			cout << "\tO wins\n";
			break;
		}


	} while (flag == 0);


	return 0;
}

void printArray(char arr[], int n) {
	cout << '\n';
	for (int i = 0; i < n; i++) {

		if (i == 0 || i == 3 || i == 6)
			cout << "      ";
		cout << arr[i] << "    ";
		if ((i + 1) % 3 == 0)
			cout << '\n';
	}
	cout << '\n';
}

char checkWinner(char arr[], int n) {

	char flag = 'A';
	if (arr[0] == arr[1] && arr[1] == arr[2]) {
		flag = arr[0];
	}
	else if (arr[3] == arr[4] && arr[4] == arr[5]) {
		flag = arr[3];
	}
	else if (arr[6] == arr[7] && arr[7] == arr[8]) {
		flag = arr[6];
	}
	else if (arr[0] == arr[3] && arr[3] == arr[6]) {
		flag = arr[0];
	}
	else if (arr[1] == arr[4] && arr[4] == arr[7]) {
		flag = arr[1];
	}
	else if (arr[2] == arr[5] && arr[5] == arr[8]) {
		flag = arr[2];
	}
	else if (arr[0] == arr[4] && arr[4] == arr[8]) {
		flag = arr[0];
	}
	else if (arr[2] == arr[4] && arr[4] == arr[6]) {
		flag = arr[2];
	}
	return flag;
}