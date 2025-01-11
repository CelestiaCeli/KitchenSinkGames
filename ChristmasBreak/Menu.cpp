#include <iostream>
#include <windows.h>
#include "Menu.h"

using namespace std;

enum
{
	BACK = 1,
	FRONT,
	QUIT
};

int GameMenu(string Games[], int ArraySize, string Comment, int LengthSize)
{
	bool Back = false;
	bool Front = false;
	bool Quit = false;
	int GamePage = 0;

	do
	{
		cout << Comment << endl;
		int GameSelection = 0;
		int GameIndexPosition = 0;

		if (GameIndexPosition + GamePage != 0)
		{
			Back = true;
		}

		if (GamePage < 0 || GamePage >= ArraySize)
		{
			GamePage = 0;
		}

		for (GameIndexPosition;GameIndexPosition + GamePage >= 0 && GameIndexPosition + GamePage < ArraySize;GameIndexPosition++)
		{
			cout << (GameIndexPosition % LengthSize + 1) << ") " << Games[GameIndexPosition + GamePage] << endl;

			if ((GameIndexPosition + 1) % LengthSize == 0 || Games[GameIndexPosition + GamePage + 1] == "")
			{
				break;
			}
		}

		if (GameIndexPosition + GamePage < ArraySize - 2)
			Front = true;

		cout << endl;

		//Put any extra options here!
		string OtherOptions[3] = { "Back", "Front", "Quit" };

		//Made it like this in the case anyone wants to add their own options
		for (int i = 0; i < sizeof(OtherOptions) / sizeof(OtherOptions[0]);i++) 
		{
			GameIndexPosition++;
			cout << GameIndexPosition + 1 << ") " << OtherOptions[i] << endl;
		}

		GameIndexPosition++;

		do
		{
			cin >> GameSelection;

			if (GameSelection > GameIndexPosition || GameSelection <= 0)
			{
				cout << endl << "Wrong Number, please try again" << endl;
			}
		} while (GameSelection > GameIndexPosition || GameSelection <= 0);

		if (GameSelection > LengthSize)
		{
			GameSelection -= LengthSize;

			switch (GameSelection)
			{
				case(BACK):
				{
					cout << "Back!";
					GamePage -= LengthSize;
					break;
				}
				case(FRONT):
				{
					cout << "Front!";
					GamePage += LengthSize;
					break;
				}
				case(QUIT):
				{
					Quit = true;
					return(-1);
				}
			}
		}
		else
		{
			return(GameSelection + GamePage);
		}
		system("cls");

	} while (!Quit);

	return(1);
}