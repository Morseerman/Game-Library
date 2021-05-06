#include "StoreMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	for (int i = 0; i < games.size(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, games[i]);
	}
}

bool StoreMenu::HandleChoice(std::string choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below

	//int index = choice - '1';

	//if (index >= 0 && index < games.size())
	//{
	//	BlockingMessage("Not implemented, press return to continue");
	//	// go to game detail page
	//}

	return false;
}