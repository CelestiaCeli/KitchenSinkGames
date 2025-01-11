#include <iostream>
#include <windows.h>
#include "Menu.h"
#include "RandomCategorizedWords.h"
using namespace std;

enum
{
	HANGMAN,
	MEMORY_MATCHING_GAME,
	WORD_SCRAMBLE,
	WORDLE,
	TIC_TAC_TOE,
	MINESWEEPER,
	BLACKJACK,
	CHECKERS,
	SNAKE_GAME,
};

enum 
{
	START = 1,
	OPTIONS,
	QUIT
};

int Game(string GameName, int GAMEID);
int Options(string GameName, int GAMEID);

int main() 
{
	srand(time(0));

	string Games[13] = { "Hangman", "Memory Matching Game", "Word Scramble", "Wordle", "Tic Tac Toe", "Minesweeper", "Blackjack", "Checkers", "Snake Game", "UI Example", "Scott The Woz", "Music fiddling", "Vulkun Learning"};
	const int GamesSize = (sizeof(Games) / sizeof(Games[0]) - 1);
	string MenuSubheader = "Welcome to my winter project collection! Pick a game from the list!";

	cout << "Welcome to my winter project!" << endl;
	cout << "Start Date: January 3rd 2025" << endl;
	cout << "End Date: N/A" << endl;
	cout << "Was too addicted to mabinogi :(" << endl << endl;

	Sleep(5000);
	system("cls");

	int GameSelection = GameMenu(Games, GamesSize, MenuSubheader, 3);
	GameSelection--;

	switch (GameSelection)
	{
		case(HANGMAN):
			
			cout << endl << "HANGMAN" << endl;
			system("cls");
			
			Game("Hangman", GameSelection);
			break;
		case(MEMORY_MATCHING_GAME):
			break;
		case(WORD_SCRAMBLE):
			break;
		case(WORDLE):
			break;
		case(TIC_TAC_TOE):
			break;
		case(MINESWEEPER):
			break;
		case(BLACKJACK):
			break;
		case(CHECKERS):
			cout << "Now Selecting Checkers...";
				break;
		case(SNAKE_GAME):
			break;

	};
	

	return 0;
}

int Game(string GameName, int GAMEID)
{
	string GameMenu2[3] = { "Start", "Options", "Back to main menu" };
	int GameSelection = GameMenu(GameMenu2, sizeof(GameMenu2) / sizeof(GameMenu2[0]), "Welcome to " + GameName, 3);
	switch (GameSelection)
	{
	case(START):
		cout << "Bonjour" << endl;
		break;
	case(OPTIONS):
		system("cls");
		Options("Hangman", 1);
		break;
	case(QUIT):
		system("cls");
		return 0;
		break;
	};

}

int Options(string GameName, int GAMEID)
{

	string OptionsArray[1] = { "Blue" };
	cout << endl << "Options" << endl;

	//switch (GAMEID)
	//{
	//case(HANGMAN):
	//	string OptionsArray[3] = { "Category", "Difficulty", "Language"};
	//	break;
	//case(MEMORY_MATCHING_GAME):
	//	break;
	//	cout << "No settings"
	//case(WORD_SCRAMBLE):
	//	break;
	//case(WORDLE):
	//	break;
	//case(TIC_TAC_TOE):
	//	break;
	//case(MINESWEEPER):
	//	break;
	//case(BLACKJACK):
	//	break;
	//case(CHECKERS):
	//	cout << "Now Selecting Checkers...";
	//	break;
	//case(SNAKE_GAME):
	//	break;
	//}
	OptionsArray->erase(OptionsArray->begin());
	cout << OptionsArray;
	return(1);
}