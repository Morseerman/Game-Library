#include "PurchaseMenu.h"

PurchaseMenu::PurchaseMenu(const std::string& title, Application* app, int aUserChoice) : Menu(title, app) 
{
	userGameChoice = aUserChoice;
	Paint(); // required in constructor
}

void PurchaseMenu::OutputOptions()
{
	for (int i = 1; i < app->GetStore().games.Length(); i++)
	{
		if (i == userGameChoice) 
		{
			std::cout << "Description: " << Utils::GetGame(i, app->GetStore().games)->GetDescription() << std::endl;
			std::cout << "Age Rating: " << Utils::GetGame(i, app->GetStore().games)->getAgeRating() << std::endl;
			std::cout << "Price: " << Utils::GetGame(i, app->GetStore().games)->GetCost() << std::endl;			
			std::cout << "Rating: " << Utils::GetGame(i, app->GetStore().games)->getRating(Utils::GetGame(i, app->GetStore().games)->getLikes(), Utils::GetGame(i, app->GetStore().games)->getDislikes()) << "%" << std::endl;
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
		for (int i = 1; i < app->GetStore().games.Length(); i++) {
			if (Utils::GetGame(i, app->GetStore().games)->getId() == userGameChoice - 1) {
				//conditions for buying the game
				if (Utils::GetGame(i, app->GetStore().games)->GetCost() > app->GetCurrentUser()->GetCredits()) {
					std::cout << "You have insufficient funds to purchase this game" << std::endl;
					Utils::GetLineFromUser();
					return false;
				}
				else {
					for (int i = 0; i < app->GetCurrentUser()->library.size(); i++) {
						if (app->GetCurrentUser()->library[i]->getGame()->GetName() == Utils::GetGame(userGameChoice, app->GetStore().games)->GetName()) {
							std::cout << "You already own this game" << std::endl;
							Utils::GetLineFromUser();
							return false;
						}
					}
					time_t t = time(NULL);
					tm* timePtr = localtime(&t);
					app->GetCurrentUser()->library.push_back(new LibraryItem(10, (timePtr->tm_mday, timePtr->tm_mon, timePtr->tm_year), Utils::GetGame(userGameChoice, app->GetStore().games), 0));
					app->GetCurrentUser()->SubtractCredits(Utils::GetGame(i, app->GetStore().games)->GetCost());
					std::cout << "Your purchase is successful" << std::endl;
					Utils::GetLineFromUser();
					std::fstream dataFile;
					std::string line;
					std::string strGameId, strDay, strMon, strYear;
					std::stringstream ssgameId, ssday, ssmon, ssyear;
					int gameId = Utils::GetGame(i, app->GetStore().games)->getId();
					int day = timePtr->tm_mday;
					int mon = timePtr->tm_mon;
					int year = timePtr->tm_year;
					ssgameId << gameId;
					ssgameId >> strGameId;
					ssday << day;
					ssday >> strDay;
					ssmon << mon;
					ssmon >> strMon;
					ssyear << year;
					ssyear >> strYear;


					dataFile.open("data.txt", std::ios::app);
					dataFile << "\nLIBRARY-ITEM\n";
					dataFile << strGameId + "\n";
					dataFile << strYear + "-" + strMon + "-" + strYear + "\n";
					dataFile << "0";
					dataFile.close();
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
