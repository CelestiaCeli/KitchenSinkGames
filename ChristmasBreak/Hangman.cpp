#include <iostream>
#include "Games.h"
#include <cstdlib>
#include <string>
#include "RandomCategorizedWords.h"
#include <Windows.h>

string WordIntialization(string Word);
bool HangmanGame(string Word, string GuessingWord);

void Hangman(int Category, int Difficulty)
{
	system("cls");

	string Word = Randomization(Category, Difficulty);

	string GuessingWord = WordIntialization(Word);

	int AttemptsLeft = 5;
	string GuessedLetter = "A";
	int Attempts = 0;

	if (HangmanGame(Word, GuessingWord) == true)
	{
		system("cls");
		printf("The answer was:\n%s\nYou win!", Word.c_str());
		Sleep(5000);
		return;
	}
	else
	{
		system("cls");
		printf("You lose. The actual answer was %s.", Word.c_str());
		Sleep(5000);
		return;
	}
}

bool HangmanGame(string Word, string GuessingWord)
{
	int AttemptsLeft = 5;
	string GuessedLetter = "A";
	int Attempts = 0;
	int WordSize = Word.length();

	while (Attempts < AttemptsLeft)
	{
		printf("Playing: Hangman. \nGuess the word! \n%s\n You have %d attempts left \n\n", GuessingWord.c_str(), AttemptsLeft - Attempts);

		std::cin >> GuessedLetter;

		bool Wrong = true;

		if (GuessedLetter.length() == 1)
		{
			for (int i = 0; i <= WordSize; i++)
			{
				if (Word[i] != ' ' && tolower(Word[i]) == tolower(GuessedLetter[0]))
				{
					GuessingWord[i] = Word[i];
					Wrong = false;
				}
			}
		}
		else
		{
			if (GuessedLetter == Word)
			{
				GuessingWord = Word;
				Wrong = false;
			}
		}


		if (Wrong)
			Attempts++;

		system("cls");
		if (GuessingWord == Word)
		{
			return(true);
		}
	}
	return(false);
}

string WordIntialization(string Word)
{
	string GuessingWord = Word;

	GuessingWord.replace(0, Word.length(), Word.length(), '_');
	int i = 0;

	for (i = Word.find(' ', i);Word.find(' ', i) != -1;i = Word.find(' ', i + 1))
	{
		GuessingWord[i] = ' ';
	}
	return(GuessingWord);

}