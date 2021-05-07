#include "PurchaseMenu.h"

PurchaseMenu::PurchaseMenu(const std::string& title, Application* app, int aUserChoice) : Menu(title, app) 
{
	userGameChoice = aUserChoice;
	Paint(); // required in constructor
}

void PurchaseMenu::OutputOptions()
{
	for (int i = 0; app->GetStore().games.length(); i++)
	{
		if (i == userGameChoice) 
		{
			std::cout << "Description: " << Utils::getGame(i, app->GetStore().games)->GetDescription() << std::endl;
			std::cout << "Age Rating: " << Utils::getGame(i, app->GetStore().games)->getAgeRating() << std::endl;
			std::cout << "Price: \x9C" << Utils::getGame(i, app->GetStore().games)->GetCost() << std::endl;
			//std::cout << Utils::getGame(i, app->GetStore().games)->GetDescription() << std::endl;
			//Utils::getGame(i, app->GetStore().games)->getRating();
		}
		
	}


}

bool PurchaseMenu::HandleChoice(std::string choice)
{
	
	return false;
}
