#include "Games.h"
#include <Windows.h>
#include <string>

void GameStarter(int GameSelection, int Category, int Difficulty)
{
	switch (GameSelection)
	{
	case(HANGMAN):
		Hangman(Category, Difficulty);
		break;
	case(MEMORY_MATCHING_GAME):
		MemoryMatchingGame(Category);
		break;
	case(WORD_SCRAMBLE):
		WordScramble();
		break;
	case(WORDLE):
		Wordle();
		break;
	case(TIC_TAC_TOE):
		TicTacToe(Difficulty);
		break;
	case(MINESWEEPER):
		Minesweeper();
		break;
	case(BLACKJACK):
		BlackJack();
		break;
	case(CHECKERS):
		Checkers(Difficulty);
		break;
	case(SNAKE_GAME):
		SnakeGame(Difficulty);
		break;
	case(UIEXAMPLE):
		UIExample();
		break;
	case(VIDEOPLAYER):
		VideoPlayer();
		break;
	case(MUSICFIDDLING):
		MusicFiddling();
		break;
	case(VULKANLEARNING):
		VulkanExample();
		break;
	}
	printf("\nGame Finished.\n");

	return;
}

void PrintResults(int PlayersPlaying, string Player[1][1])
{
	printf("Here are your results!\n");
	for (int i; i <= PlayersPlaying; i++)
	{
		printf("Player %d results:\n Name: %s\n Score: %d \n", i, Player[i][PLAYER].c_str(), Player[i][PLAYERSCORE].c_str());
	}
}

void EndOfGame(string FirstString, string SecondString, string Condition, string Players[1][1])
{
	system("cls");
	printf("%s\n%s\n%s", FirstString, SecondString, Condition);
	PrintResults(sizeof(Players) / Players, Players);
	Sleep(5000);
	return;
}