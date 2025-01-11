#pragma once
#include <iostream>
#include "RandomCategorizedWords.h"

class Card
{
public:
	int cat = 1;
	int diff = 1;
	int CardHeight;
	bool Shown = false;

private:

	string Name[5] = { Randomization(cat, diff) };

	void GiveWord();

	void Regenerate();

	void PrintCard();
};