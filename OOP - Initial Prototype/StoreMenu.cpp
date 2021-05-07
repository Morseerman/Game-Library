#include "StoreMenu.h"


StoreMenu::StoreMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	for (int i = 1; i < app->GetStore().games.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		std::cout << i << ") " << Utils::getGame(i, app->GetStore().games)->GetName() << std::endl;
	}
}

bool StoreMenu::HandleChoice(std::string choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below

	//int index = choice - '1';

	for (int i = 1; i < app->GetStore().games.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		//std::cout << i << ") " << Utils::getGame(i, app->GetStore().games)->GetName() << std::endl;
		if (Utils::stringToInt(choice) == i)
		{
			//Utils::userGameChoice = Utils::stringToInt(choice);
			PurchaseMenu(Utils::getGame(i, app->GetStore().games)->GetName(), app, Utils::stringToInt(choice));
		}
	}

	return false;
}