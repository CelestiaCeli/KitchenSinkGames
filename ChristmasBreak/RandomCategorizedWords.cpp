#include "RandomCategorizedWords.h"
#include <iostream>
//This is where I grab all the randomized words for games such as 'hangman' or 'memory matching'

using namespace std;

//TOPICS + CONTENT
//It's difficult to put anything in here due to the absolute legal warfare that ensues.
//This will be fixed in a potential GUI update, where you can add your own without harsh restrictions!
//For now, this is unoperational
string TopicSelection[12][100] = {
	{ "PeopleHard", "People"},
	{ "PeopleMedium", "People"},
	{ "PeopleEasy", "People"},
	{ "CountriesHard", "Countries"},
	{ "CountriesMedium", "Countries"},
	{ "CountriesEasy", "Countries"},
	{ "MediaMedium", "Media"},
	{ "MediaEasy", "Media"},
	{ "ImmatureHard", "Immature"},
	{ "ImmatureMedium", "Immature"},
	{ "ImmatureEasy", "Immature"}
};

string Randomization(int Topic, int DifficultyOffset)
{
	string FinalizedWord;
	const int AnySubject = 4;

	do {
		srand(time(0));
		if (Topic == ANY)
		{
			switch (Topic + DifficultyOffset)
			{
			case(HARD):
				FinalizedWord = TopicSelection[rand() % 4 * 3][rand() % 35 + 1];
				break;
			case(MEDIUM):
				FinalizedWord = TopicSelection[(rand() % 4) * 3 + (MEDIUM)][rand() % 35 + 1];
				break;
			case(EASY):
				FinalizedWord = TopicSelection[(rand() % 4) * 3 + (EASY)][rand() % 35 + 1];
				break;
			}
		}
		else if (Topic + DifficultyOffset < 12)
		{
			FinalizedWord = TopicSelection[(Topic * 3) + DifficultyOffset - 3][rand() % 35 + 1];
		}
		else
		{
			cout << endl << "Error! Could not find a matching subject!" << endl << "Defaulting to Any(medium)";
			FinalizedWord = TopicSelection[(rand() % 4) * 3 + (MEDIUM)][rand() % 35 + 1];
		}
	} while (FinalizedWord == "");

	return(FinalizedWord);
}