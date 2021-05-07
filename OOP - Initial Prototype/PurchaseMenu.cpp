#include "PurchaseMenu.h"

PurchaseMenu::PurchaseMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void PurchaseMenu::OutputOptions()
{
	for (int i = 0; app->GetStore().games.length(); i++)
	{
		//if (i == Utils::userGameChoice) --need to load only 1 game
		{
			std::cout << Utils::getGame(i, app->GetStore().games)->GetDescription() << std::endl;
			std::cout << Utils::getGame(i, app->GetStore().games)->getAgeRating() << std::endl;
			std::cout << Utils::getGame(i, app->GetStore().games)->GetCost() << std::endl;
			std::cout << Utils::getGame(i, app->GetStore().games)->GetDescription() << std::endl;
			//Utils::getGame(i, app->GetStore().games)->getRating();
		}
		
	}


}

bool PurchaseMenu::HandleChoice(std::string choice)
{
	
	return false;
}
