#include <iostream>
#include "Games.h"
#include "RandomCategorizedWords.h"
#include "MemoryMatching.h"
#include <Windows.h>

//ASCII CARD GIVEN BY ASCIIART.EU
//   _____
//  |2    |
//  |  o  |
//  |     |
//  |  o  |
//  |____Z|

class Card
{
private:
	string CardTopBottom;
	int CardHeight = 8;
	int CardWidth = 10;
	int CardID;
	string Name = "Placeholder";

public:

	bool IsCollected = false;
	bool IsSelected = false;

	void PrintCard()
	{
		if (IsCollected == true)
		{
			return;
		}
		for (int i = 0; i <= CardWidth; i++)
		{
			CardTopBottom.append("_");

		}
		int HeightPrinted = 1;
		int LengthPrinted = 0;
		printf("%d\t%s\n\t|", CardID, CardTopBottom.c_str());
		for (int c = 0; c <= Name.length(); c++)
		{
			if (Name[c] != ' ' && LengthPrinted < CardWidth)
			{
				if (IsSelected)
					printf("%c", Name[c]);
				if (!IsSelected)
					printf(" ");
				LengthPrinted++;
			}
			else if (LengthPrinted > CardWidth)
			{
				printf("-|\n\t|-");
				LengthPrinted = 1;
				HeightPrinted++;
				c--;
			}
			else if (LengthPrinted > 2 && Name[c] == ' ')
			{
				while (LengthPrinted <= CardWidth)
				{
					printf(" ");
					LengthPrinted++;
				}
				printf("|\n\t|");
				HeightPrinted++;
				LengthPrinted = 0;
			}
			else
			{
				LengthPrinted++;
			}
		}
		LengthPrinted--;
		while (HeightPrinted++ <= CardHeight)
		{
			while (LengthPrinted <= CardWidth)
			{
				printf(" ");
				LengthPrinted++;
			}
			LengthPrinted = 0;
			HeightPrinted++;
			printf("|\n\t|");
		}

		printf("|\n\t|%s|\n", CardTopBottom.c_str());
	}

	void Intialize(int height, int width, int ID)
	{
		CardWidth = width;
		CardHeight = height;
		CardID = ID;
		do
		{
			Name = Randomization(1, 1);
		} while (Name.length() > CardHeight * CardWidth);
	}

	string RetrieveName()
	{
		return(Name);
	}
};

void PrintALLCards(Card ListOfCards[], int n);

void MemoryMatchingGame(int Length, int Height, int Category)
{

	int CollectedCards = 0;
	Card ListOfCards[8];
	int CardListSize = sizeof(ListOfCards) / sizeof(ListOfCards[0]);
	int FullRounds = 0;
	int TotalAttempts = 5;

	for (int i = 0; i < CardListSize; i++)
	{
		ListOfCards[i].Intialize(5, 5, i + 1);
	}


	for (int FailedRounds = 0; FailedRounds < TotalAttempts; FailedRounds++)
	{
		printf("\nYou have %d tries left!\n", TotalAttempts - FailedRounds);

		PrintALLCards(ListOfCards, CardListSize);

		int PickedCards[2];
		string Count[2][2] = {"First", "Second"};

		for (int i = 0; i < 2; i++)
		{
			printf("\nChoose your %s card!\n", Count[i]->c_str());
			std::cin >> PickedCards[i];

			system("cls");
			ListOfCards[PickedCards[i] - 1].IsSelected = true;

			PrintALLCards(ListOfCards, CardListSize);
		}
		Sleep(500);
		ListOfCards[PickedCards[0] - 1].IsSelected = false;
		ListOfCards[PickedCards[1] - 1].IsSelected = false;

		if (ListOfCards[PickedCards[0] - 1].RetrieveName() == ListOfCards[PickedCards[1] - 1].RetrieveName())
		{
			ListOfCards[PickedCards[0] - 1].IsCollected = true;
			ListOfCards[PickedCards[1] - 1].IsCollected = true;
			CollectedCards += 2;
		}

		if (CollectedCards == CardListSize)
		{
			printf("Congrats! You won!\nIt took you %d tries!\nYou successfully collected %d of them!", FullRounds, CollectedCards);
			Sleep(500);
			return;
		}

		system("cls");
	}

	printf("Congratulations! You're a failure!\n\nOH I FAILED?? DIDN'T I?....");
	Sleep(500);
	return;
}

void PrintALLCards(Card ListOfCards[], int n)
{
	for (int i = 0; i < n; i++)
	{
		ListOfCards[i].PrintCard();
	}
}
