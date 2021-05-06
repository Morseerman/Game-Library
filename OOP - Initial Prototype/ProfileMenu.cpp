#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void ProfileMenu::OutputOptions()
{
	//for (int i = 0; i < userNames.size(); i++)
	//{
	//	// adding 1 so the display is nicer for the user
	//	Option(i + 1, userNames[i]);
	//}
	std::cout << "Credits: " << app->GetCurrentUser()->getCredits() << std::endl;
	std::cout << std::endl;
	std::cout << "I) Purhcase 1 Credit" << std::endl;
	std::cout << "O) Purhcase 10 Credit" << std::endl;
	std::cout << "P) Purhcase 100 Credit" << std::endl;

	for (int i = 0; i < app->GetCurrentUser()->library.size(); i++) {
		std::cout << i << ") " << app->GetCurrentUser()->library[i]->getGame()->GetName() << "  (" << app->GetCurrentUser()->library[i]->getPlayTime() << " hours played)" << std::endl;
		
	}
	
}

bool ProfileMenu::HandleChoice(std::string choice)
{
	//if(choice == app->GetCurrentUser()->library)
	int intChoice = Utils::stringToInt(choice);

	for (int i = 0; i < app->GetCurrentUser()->library.size(); i++) {
		if (i == intChoice) {
			app->GetCurrentUser()->library[i]->addPlayTime(Utils::returnRandomNumber());
			return false;
		}
	}

	

	//if (choice == "s") {
	//	app->GetCurrentUser
	//}


	app->GetCurrentUser()->incrementCredits(choice);
	if (choice == "B") {
		return true;
	}
	else {
		return false;
	}
}


