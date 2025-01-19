#include "RandomCategorizedWords.h"
#include <iostream>
//This is where I grab all the randomized words for games such as 'hangman' or 'memory matching'

//TOPICS + CONTENT
//It's difficult to put anything in here due to the absolute legal warfare that ensues.
//This will be fixed in a potential GUI update, where you can add your own without harsh restrictions!
//For now, this is unoperational
string TopicSelection[12][10] = {
	{ "PeopleHard", "Canada", "", "", "", "", "", "", "", ""},
	{ "PeopleMedium", "Canada", "", "", "", "", "", "", "", ""},
	{ "PeopleEasy", "Canada", "", "", "", "", "", "", "", ""},
	{ "CountriesHard", "Canada", "", "", "", "", "", "", "", ""},
	{ "CountriesMedium", "Canada", "", "", "", "", "", "", "", ""},
	{ "CountriesEasy", "Canada", "", "", "", "", "", "", "", ""},
	{ "MediaMedium", "Canada", "", "", "", "", "", "", "", ""},
	{ "MediaEasy", "Canada", "", "", "", "", "", "", "", ""},
	{ "ImmatureHard", "Canada", "", "", "", "", "", "", "", ""},
	{ "ImmatureMedium", "Canada", "", "", "", "", "", "", "", ""},
	{ "ImmatureEasy", "Canada", "", "", "", "", "", "", "", ""}
};

string Randomization(int Topic, int DifficultyOffset)
{
	string FinalizedWord;

	do {
		srand(time(0));
		if (Topic == ANY)
		{
			int Hard = rand() % 4 * 3 + (HARD);
			int Medium = rand() % 4 * 3 + (MEDIUM);
			int Easy = rand() % 4 * 3 + (EASY);
			switch (Topic + DifficultyOffset)
			{
			case(HARD):
				FinalizedWord = TopicSelection[Hard][rand() % TopicSelection[Hard]->length() + 1];
				break;
			case(MEDIUM):
				FinalizedWord = TopicSelection[Medium][rand() % TopicSelection[Medium]->length() + 1];
				break;
			case(EASY):
				FinalizedWord = TopicSelection[Easy][rand() % TopicSelection[Easy]->length() + 1];
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
			int Medium = rand() % 4 * 3 + (MEDIUM);
			FinalizedWord = TopicSelection[Medium][rand() % TopicSelection[Medium]->length()];
			break;
		}
	} while (FinalizedWord == "");

	return(FinalizedWord);
}