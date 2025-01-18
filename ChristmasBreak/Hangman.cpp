#include <iostream>
#include "Games.h"
#include <cstdlib>
#include <string>
#include "RandomCategorizedWords.h"
#include <Windows.h>


void Hangman(int Category, int Difficulty)
{
	system("cls");

	string Word = Randomization(Category, Difficulty);
	int WordSize = Word.length();

	string GuessingWord = Word;

	GuessingWord.replace(0, WordSize, WordSize, '_');

	int AttemptsLeft = 5;
	string GuessedLetter = "A";
	int Attempts = 0;

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
				printf("The answer was:\n%s\nYou win!", Word.c_str());
				Sleep(5000);
				return;
			}
		}

		printf("You lose. The actual answer was %s.", Word.c_str());
		Sleep(5000);
		return;
}
	//I have to make it look through every character and switch it to a _, if it is a space then leave it be.
	//for now this will be implemented later