//DO NOT DELETE!!! SEVERELY IMPORTANT!
#include "Objects/HangmanObject.h"


//I name this execution because it sounds COOL :D
class Executioner {
    int *minigameAmount;
    int *contextAmount;

    int *collection;

    Executioner() {
        minigameAmount = new int;
        minigameAmount = 10;

        contextAmount = new int;
        contextAmount = 2;

        collection = new int[minigameAmount][contextAmount];

        //This is the list of minigames that can be executed. adding a minigame should be as simple as drag and drop the values.
        collection =
        {
            "Hangman", std::addressof(HangmanObject->)
            "MemoryMatchingGame"
        };

    }
};
int *executionList