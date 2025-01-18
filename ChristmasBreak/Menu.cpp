#include <iostream>
#include <windows.h>
#include "Menu.h"

enum
{
	BACK = 1,
	FRONT,
	QUIT
};

int GameMenu(std::string Games[], int ArraySize, std::string Comment, int LengthSize)
{
	bool Back = false;
	bool Front = false;
	bool Quit = false;
	int GamePage = 0;

	do
	{
		printf("%s\n", Comment.c_str());
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
			printf("%d )  %s\n", GameIndexPosition % LengthSize + 1, Games[GameIndexPosition + GamePage].c_str());

			if ((GameIndexPosition + 1) % LengthSize == 0 || Games[GameIndexPosition + GamePage + 1] == "")
			{
				break;
			}
		}

		if (GameIndexPosition + GamePage < ArraySize - 2)
			Front = true;

		printf("\n");

		//Put any extra options here!
		std::string OtherOptions[3] = { "Back", "Front", "Quit" };

		//Made it like this in the case anyone wants to add their own options
		for (int i = 0; i < sizeof(OtherOptions) / sizeof(OtherOptions[0]);i++) 
		{
			GameIndexPosition++;
			printf("%d )%3s\n", GameIndexPosition + 1, OtherOptions[i].c_str());
		}

		GameIndexPosition++;

		do
		{
			std::cin >> GameSelection;

			if (GameSelection > GameIndexPosition || GameSelection <= 0)
			{
				printf("\nWrong Number, please try again.\n");
			}
		} while (GameSelection > GameIndexPosition || GameSelection <= 0);

		if (GameSelection > LengthSize)
		{
			GameSelection -= LengthSize;

			switch (GameSelection)
			{
				case(BACK):
				{
					printf("Back!\n");
					GamePage -= LengthSize;
					break;
				}
				case(FRONT):
				{
					printf("Front!\n");
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