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
	std::cout << "Credits: " << app->GetCurrentUser()->getCredits();
	
}

bool ProfileMenu::HandleChoice(std::string choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	//int index = choice - '1';


	std::cout << "Enter Password\n";
	std::string inputAccountPassword = Utils::getLineFromUser();

	//logging into account
	if (app->LoginAccount(choice, inputAccountPassword) == true)
	{
		for (int i = 0; i < userNames.size(); i++)
		{
			// adding 1 so the display is nicer for the user
			app->accounts.first()->users.first()->GetUsername();
		}
		app->LoginUser(choice, "password");

		std::string inputOption = Utils::getLineFromUser();

		//logging into user
		User* selectedUser = Utils::getUserFromList(Utils::stringToInt(inputOption), app->accounts);
		std::cout << "Welcome: " << selectedUser->GetUsername() << ". Please enter your password.\n";

		std::string inputUserPassword = Utils::getLineFromUser();
		if (inputUserPassword == selectedUser->GetPassword())
		{
			//Correct User Password
			app->setCurrentUser(selectedUser);
		}
		else
		{
			std::string ballsack = Utils::getLineFromUser();
		}

		return true;
	}



	//if (app->accounts.first()->users.contains())
	//{
	//	//app->LoginUser("Bob", "password");
	//	//BlockingMessage("women be shopping");
	//	// go to game detail page
	//}


	return false;
}


