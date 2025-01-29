#pragma once
#include <iostream>

using namespace std;

enum GAMES
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
	UIEXAMPLE,
	VIDEOPLAYER,
	MUSICFIDDLING,
	VULKANLEARNING,
	FIVEHUNDREDCIGARETTES
};

enum PLAYERINFO
{
	PLAYER,
	PLAYERSCORE
};

void Hangman(int Category, int Difficulty);
void MemoryMatchingGame(int Length, int Height, int Category);
void WordScramble();
void Wordle();
void TicTacToe(int Difficulty);
void Minesweeper(int Difficulty);
void BlackJack();
void Chess(int Diffiuclty);
void Checkers(int Difficulty);
void SnakeGame(int Difficulty);

void UIExample();
void VideoPlayer();
void MusicFiddling();
void VulkanExample();
void GodotGame();
void FiveHundredCigarettes();

void GameStarter(int GameSelection, int Category, int Difficulty);

void Results();
void Win();
void Lose();