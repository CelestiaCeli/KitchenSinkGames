#pragma once
#include <iostream>

using namespace std;

enum Topics {
	ANY,
	PEOPLE,
	COUNTRIES,
	MEDIA,
	IMMATURE,
};

enum Difficulties {
	HARD,
	MEDIUM,
	EASY
};

string Randomization(int Topic, int DifficultyOffset);

