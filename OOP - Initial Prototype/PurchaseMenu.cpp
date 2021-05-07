#include "PurchaseMenu.h"

PurchaseMenu::PurchaseMenu(const std::string& title, Application* app, int aUserChoice) : Menu(title, app) 
{
	userGameChoice = aUserChoice;
	Paint(); // required in constructor
}

void PurchaseMenu::OutputOptions()
{
	for (int i = 1; i < app->GetStore().games.length(); i++)
	{
		if (i == userGameChoice) 
		{
			std::cout << "Description: " << Utils::getGame(i, app->GetStore().games)->GetDescription() << std::endl;
			std::cout << "Age Rating: " << Utils::getGame(i, app->GetStore().games)->getAgeRating() << std::endl;
			std::cout << "Price: " << Utils::getGame(i, app->GetStore().games)->GetCost() << std::endl;			
			std::cout << "Rating: " << Utils::getGame(i, app->GetStore().games)->getRating(Utils::getGame(i, app->GetStore().games)->getLikes(), Utils::getGame(i, app->GetStore().games)->getDislikes()) << "%" << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "P) Purchase game                  B) Back";
			std::cout << std::endl;
			
		}

		
	}



}

bool PurchaseMenu::HandleChoice(std::string choice)
{
	if (choice == "P") {
		for (int i = 1; i < app->GetStore().games.length(); i++) {
			if (Utils::getGame(i, app->GetStore().games)->getId() ==  userGameChoice - 1) {
				//conditions for buying the game
				if (Utils::getGame(i, app->GetStore().games)->GetCost() > app->GetCurrentUser()->getCredits()) {
					std::cout << "You have insufficient funds to purchase this game" << std::endl;
					Utils::getLineFromUser();
					return false;
				}
				else {
					for (int i = 0; i < app->GetCurrentUser()->library.size(); i++) {
						if (app->GetCurrentUser()->library[i]->getGame()->GetName() == Utils::getGame(userGameChoice, app->GetStore().games)->GetName()) {
							std::cout << "You already own this game" << std::endl;
							Utils::getLineFromUser();
							return false;
						}
					}
					time_t t = time(NULL);
					tm* timePtr = localtime(&t);
					app->GetCurrentUser()->library.push_back(new LibraryItem(10, (timePtr->tm_mday, timePtr->tm_mon, timePtr->tm_year), Utils::getGame(i, app->GetStore().games), 0));
					app->GetCurrentUser()->subtractCredits(Utils::getGame(i, app->GetStore().games)->GetCost());
					std::cout << "Your purchase is successful" << std::endl;
					Utils::getLineFromUser();
					return true;
				}
				

			}

		}
	} 
	if (choice == "B")
	{
		return true;
	}
	return false;
}
