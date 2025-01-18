
#include "Games.h"

using namespace std;

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