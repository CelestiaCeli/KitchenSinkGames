
#include "Games.h"

using namespace std;

void MemoryMatchingGame(int Category)
{
	cout << "This Game";
}

#include <iostream>
#include "Games.h"
#include "RandomCategorizedWords.h"
#include "MemoryMatching.h"
using namespace std;

//ASCII CARD GIVEN BY ASCIIART.EU
//   _____
//  |2    |
//  |  o  |
//  |     |
//  |  o  |
//  |____Z|

class Card
{
	string CardTop = "_____";

	string CardBottom = "|____|";

	void Reroll()
	{
		Name = Randomization(1, 1);

		int StartOffset = 1;
		if (Name.length() > MaximumLength)
		{
			reroll();
			return;
		}
		for (EndOffset = Name.find(' ', EndOffset);Name.find(' ', EndOffset) != -1;EndOffset = Name.find(' ', i + 1))
		{
			if (EndOffset > 5)
				break;
			else
				RepresentedName.append(Name, StartOffset, StartOffset - EndOffset);
			StartOffset = EndOffset;
		}
		if (Name.find(' ', 0) <= 5)
		{
			while (RepresentedName.length() < Name.length())
			{
				RepresentedName.append(Name, StartOffset, StartOffset - EndOffset);
				StartOffset = EndOffset;
				EndOffset += 5;
			}
		}
		return;
	}

	void PrintCard()
	{
		printf("%s", CardTop);
		for (int c = 0; c < CardHeight; c++)
		{
			printf("|%s|", RepresentedName[c]);
		}
		printf("|%s|", CardBottom);
	}

public:
	int MaximumLength = 15;
	int CardHeight = 4;
	int CardID;
	string RepresentedName;
	bool IsCollected = false;
	bool IsSelected = true;

	void Reroll();
	void Compare();
	void PrintCard();
	string Name = Randomization(1, 1);
};

// Cards will spawn 
void MemoryMatchingGame(string Cards[1][1], int ArraySize, int Category)
{
	int Turns = 5;
	bool Valid = false;
	const int RandomDifficulty = rand() % 3;

	CardIntiation();


	if (MemoryMatchingGame() == true)
	{
		Win();
	}
	else
	{
		Lose();
	}
	return;

}  

bool MemoryMatchingGame()
{
	while (Turns > 0)
	{
		CardPresenting();

		int CardSelection = CardPlayerSelection();

		if (Compare(CardSelection, CardSelection) == false)
		{
			Turns--;
		}
		if (CardAmount == 0)
		{
			return(true);
		}
	}
	return(false);
}
void CardPresenting()
{

}

void CardIntiation()
{
	for (int a = 0; a <= ArraySize; a++)
	{
		for (int b = 0; b <= ArraySize; b++)
		{
			printf("%d", Card1.CardID);
			Card1.PrintCard();
		}
		"\n"
	}
}

int CardPlayerSelection()
{
	int CardSelection;
	int CardSelection2;
	printf("Pick two cards!");
	std::cin >> CardSelection;
	printf("\n");
	std::cin >> CardSelection2;
	return(CardSelection, CardSelection2);
}

bool Compare(Card Card1, Card Card2)
{
	if (Card1.Name == Card2.Name)
	{
		Card1.IsCollected = true;
		Card2.IsCollected = true;
		return(true);
	}
	else
	{
		return(false);
	}
	return;
}