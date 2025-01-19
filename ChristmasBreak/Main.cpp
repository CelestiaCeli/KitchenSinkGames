#include <stdio.h>
#include <windows.h>
#include "Menu.h"
#include "Games.h"
#include <iostream>

//Hello and welcome to my winter break project. This is a project I've been working on during winter and somewhat into spring aswell.
//I'm rather new to programming and only finished down the basics of c++ during around christmas, so this is a little area to test and enhance my skills.

//I'd prefer to group these things together because I'm not making them for proudly presenting them; this is to learn and help get a feel for a video game.

enum 
{
	START = 1,
	OPTIONS,
	QUIT
};

int Game(string GameName, int GAMEID);
int Game(string GameName, int GAMEID);
int Options(string GameName, int GAMEID);
void MainMenu();
void StartUpMessage();

int main() 
{
    srand(time(0));
	bool Quit = false;
	StartUpMessage();
	while (!Quit) 
	{
		MainMenu();
	}
	return 0;
}


void StartUpMessage()
{
	system("cls");

	printf("Welcome to my winter project! \n Start Date: January 3rd 2025 \n End Date: N/A \n Was too addicted to mabinogi :(\n");

	Sleep(1);
}

void MainMenu()
{
	string PlayerInfo[1][2];
	system("cls");
	string Games[13] = { "Hangman", "Memory Matching Game", "Word Scramble", "Wordle", "Tic Tac Toe", "Minesweeper", "Blackjack", "Checkers", "Snake Game", "UI Example", "Scott The Woz", "Music fiddling", "Vulkun Learning" };
	const int GamesSize = (sizeof(Games) / sizeof(Games[0]) - 1);
	string MenuSubheader = "Welcome to my winter project collection! Pick a game from the list!";

	int GameSelection = GameMenu(Games, GamesSize, MenuSubheader, 3);
	GameSelection--;

	printf("%s", Games[GameSelection].c_str());

	Game(Games[GameSelection], GameSelection);
}


int Game(string GameName, int GAMEID)
{
	bool Quit = false;
	while (!Quit)
	{

		int Category = 1;
		int Difficulty = 1;

		system("cls");

		string GameMenu2[3] = { "Start", "Options", "Back to main menu" };
		int GameSelection = GameMenu(GameMenu2, sizeof(GameMenu2) / sizeof(GameMenu2[0]), "Welcome to " + GameName, 3);

		system("cls");

		switch (GameSelection)
		{
		case(START):
			printf("Now loading %d...\n\nThis code is like really awful btw...", GameSelection);
			GameStarter(GameSelection, Category, Difficulty);

			system("cls");
			break;
		case(OPTIONS):
			printf("Settings NOT implemented yet.");
			Sleep(500);

			system("cls");
			break;

		case(QUIT):
			system("cls");
			Quit = true;
			break;
		};
	}
	return 0;
}

//January 18th 2025 marks the day I RUN OUT OF ESTROGEN

//HECK!!!!!!!!!!!!!!!!!!!!!!!!!


//A list of getting to do
// Finished:
// Main Menu(Functionally Complete)
// Hangman(Functionally Complete)
// 
// Working on:
// Memory Matching Game(WIP)
// Dynamic Word Randomizer Update
// 
// To do:
// Checkers(not started)
// Chess(not started)
// Memory Matching Game(WIP)
// Minesweeper(not started)
// RPG(not started)
// Snake Game(not started)
// TicTacToe(not started)
// Godot Project(not started)
// Vulkan test(not started)
// Music Fiddling
// Video Testing
//
// Overhauls:
// Multiplayer Update
// Full UI Update

//Get rid of iostream btw