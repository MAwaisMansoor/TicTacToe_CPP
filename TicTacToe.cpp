

//#include"pch.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace std;
char** ptr = new char* [3];			//assigning a array of three pointers to a double pointer dynamically
char a, P1, P2;						//'a' is for the input of lovation num. ,P1&P2 are for player's char.
int  i, j, i1 = 0, ac[9];			//i&j for global scope, i1 for index of ac[]
string Player1, Player2;			//two string type variable to hold the names of players
void DynamicallyArray(char**);		//a prototype of function to creat dynamic array
void StartOfGame();					//a prototype of funncton for the info. of both players
void DisplayTtt(char**);			//a prototype of function to display TIC TAC TOE. . .
void Game();						//a prototype of function to execute the game
void evaluateSymbol();				//a prototype of function to evaluate the symbol for number location
int main() {
	DynamicallyArray(ptr);
	StartOfGame();
	DisplayTtt(ptr);
	Game();
	if (i > 9)	cout << "\t\tITS A TIE!\n\n\t\tNOBODY WINS. . .\n\n\n\n";
	for (int k = 0; k < 3; k++)		//Deleting Dynamically creations
		delete[]  ptr[k];
	delete[] ptr;
}
void DynamicallyArray(char** ptr) {
	char s = '1';						//'s' is for storing the data into the array
	for (int i = 0; i < 3; i++) {
		ptr[i] = new char[3];			//creating three array dynamically at every index of array of pointers
	}
	for (int i = 0; i < 3; i++) {		//filling 2D array by char.s from(1-9)
		for (int j = 0; j < 3; j++) {
			ptr[i][j] = s;
			s++;
		}
	}
}
void StartOfGame() {
	cout << "\n\t\t\t\t\tLet's Play TIC TAC TOE. . .\n\n";
	cout << "Enter your name Player1: ";	getline(cin, Player1);
	cout << "Enter your name player2: ";	getline(cin, Player2);
	do {
		cout << Player1 << "! Choose either symbol 'X' or 'O'" << ": ";
		cin >> P1;	   //user can enter either upper case or lower case letter
	} while ((P1 != 'x' && P1 != 'X') && (P1 != 'o' && P1 != 'O'));
	if (P1 == 'x') {   //display uses upper case letters for better illustration
		P1 = 'X';
		P2 = 'O';
	}
	else if (P1 == 'o') {
		P1 = 'O';
		P2 = 'X';
	}
	else if (P1 == 'X')
		P2 = 'O';
	else
		P2 = 'X';
	cout << endl << "The symbol of " << Player2 << " is: " << P2;
	Sleep(700);		cout << "\n\n\n\n\n";
}
void DisplayTtt(char** ptr) {
	system("cls");              //a function to clear the previously displayed console screen
	evaluateSymbol();			//call of player's symbol evaluation's function
	cout << "\n\t\t\t\t\t-------------------\n";
	cout << "\t\t\t\t\t|   TIC TAC TOE   |\n";
	cout << "\t\t\t\t\t-------------------\n";
	for (int i = 0; i < 3; i++) {		//Display TIC TAC TOE
		cout << "\t\t\t\t\t\|  ";
		for (int j = 0; j < 3; j++)
			cout << ptr[i][j] << "  \|  ";
		cout << endl;
		cout << "\t\t\t\t\t-------------------\n";
	}
	cout << "\n\n\n";
}
void Game() {
	for (i = 1; i <= 9; i++) {
	line56: if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9) {  //player1 always comes at odd iterations
		cout << "\t\t" << Player1 << "!\n\nEnter the num. for location of your move " << P1 << ": ";
		a = _getche();					//inputting a character location by get character echo function
		while (a < 49 || a > 57) {		//using ASCII codes of characters from (1-9) for input validation
			cout << "\nInvalid Input!\n Enter again: ";
			a = _getche();
		}
	}
			else {				                //player2 always comes at even iterations
		cout << "\t\t" << Player2 << "!\n\nEnter the num. for location of your move " << P2 << ": ";
		a = _getche();					//inputting a character location by get character echo function
		while (a < 49 || a > 57) {		//using ASCII codes of characters from (1-10) for input validation
			cout << "\nInvalid Input!\n Enter again: ";
			a = _getche();
		}
	}
			for (int i = 0; i < 9; i++) {		//traversing the ac[]
				if (ac[i] == a) {
					cout << "\nOOPS! Already Choosen!\n";
					goto line56;    //to guide the players to enter different locations every time
				}
			}
			ac[i1] = a;   i1++;	   //ac[] is to keep a check on already entered location numbers
			DisplayTtt(ptr);	   //Display Game TIC TAC TOE. . .	
			if ((ptr[0][1] == ptr[1][1] && ptr[1][1] == ptr[2][1]) ||
				(ptr[0][2] == ptr[1][2] && ptr[1][2] == ptr[2][2]) ||
				(ptr[0][0] == ptr[1][1] && ptr[1][1] == ptr[2][2]) ||
				(ptr[0][2] == ptr[1][1] && ptr[1][1] == ptr[2][0]) ||
				(ptr[0][0] == ptr[0][1] && ptr[0][1] == ptr[0][2]) ||
				(ptr[1][0] == ptr[1][1] && ptr[1][1] == ptr[1][2]) ||
				(ptr[2][0] == ptr[2][1] && ptr[2][1] == ptr[2][2]) ||
				(ptr[0][0] == ptr[1][0] && ptr[1][0] == ptr[2][0])) {
				if ((ptr[0][1] == ptr[1][1] && ptr[1][1] == ptr[2][1] && ptr[2][1] == P1) ||
					(ptr[0][2] == ptr[1][2] && ptr[1][2] == ptr[2][2] && ptr[2][2] == P1) ||
					(ptr[0][0] == ptr[1][1] && ptr[1][1] == ptr[2][2] && ptr[2][2] == P1) ||
					(ptr[0][2] == ptr[1][1] && ptr[1][1] == ptr[2][0] && ptr[2][0] == P1) ||
					(ptr[0][0] == ptr[0][1] && ptr[0][1] == ptr[0][2] && ptr[0][2] == P1) ||
					(ptr[1][0] == ptr[1][1] && ptr[1][1] == ptr[1][2] && ptr[1][2] == P1) ||
					(ptr[2][0] == ptr[2][1] && ptr[2][1] == ptr[2][2] && ptr[2][2] == P1) ||
					(ptr[0][0] == ptr[1][0] && ptr[1][0] == ptr[2][0] && ptr[2][0] == P1))
					cout << "\t\tCONGRATULATIONS!\n\n\t\t" << Player1 << " WINS!\n\n\n\n";
				else
					cout << "\t\tCONGRATULATIONS!\n\n\t\t" << Player2 << " WINS!\n\n\n\n";
				break;       //to break the program when some combination is found
			}
	}
}
void evaluateSymbol() {  //a funtion to auto evaluate the symbols of the players 
	if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9) {
		switch (a) {
		case '1': ptr[0][0] = P1; break;
		case '2': ptr[0][1] = P1; break;
		case '3': ptr[0][2] = P1; break;
		case '4': ptr[1][0] = P1; break;
		case '5': ptr[1][1] = P1; break;
		case '6': ptr[1][2] = P1; break;
		case '7': ptr[2][0] = P1; break;
		case '8': ptr[2][1] = P1; break;
		case '9': ptr[2][2] = P1; break;
		}
	}
	else {
		switch (a) {
		case '1': ptr[0][0] = P2; break;
		case '2': ptr[0][1] = P2; break;
		case '3': ptr[0][2] = P2; break;
		case '4': ptr[1][0] = P2; break;
		case '5': ptr[1][1] = P2; break;
		case '6': ptr[1][2] = P2; break;
		case '7': ptr[2][0] = P2; break;
		case '8': ptr[2][1] = P2; break;
		case '9': ptr[2][2] = P2; break;
		}
	}
}