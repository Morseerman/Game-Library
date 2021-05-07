#include "LoginMenu.h"

LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginMenu::OutputOptions()
{
	//for (int i = 0; i < userNames.size(); i++)
	//{
	//	// adding 1 so the display is nicer for the user
	//	Option(i + 1, userNames[i]);
	//}

	std::cout << "Enter email: " << std::endl;
	
}

bool LoginMenu::HandleChoice(std::string choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	//int index = choice - '1';

	system("CLS");
	std::cout << "  -= LOGIN =-       \n";
	std::cout << std::endl;
	std::cout << "Enter Password\n";
	std::string inputAccountPassword = Utils::GetLineFromUser();

	app->accounts.First()->users.First()->Promote();

	//logging into account
	if (app->LoginAccount(choice, inputAccountPassword) == true)
	{
		system("CLS");
		std::cout << "  -= LOGIN =-       \n";
		std::cout << std::endl;
		std::cout << "Select a user: " << std::endl;
		for (int i = 0; i < userNames.size(); i++)
		{
			// adding 1 so the display is nicer for the user
			app->accounts.First()->users.First()->GetUsername();
		}
		app->LoginUser(choice, "password");

		std::string inputOption = Utils::GetLineFromUser();
		
		//logging into user
		User* selectedUser = Utils::GetUserFromList(Utils::StringToInt(inputOption), app->accounts);
		system("CLS");
		std::cout << "  -= LOGIN =-       \n";
		std::cout << std::endl;
		std::cout << "Welcome: " << selectedUser->GetUsername() << ". Please enter your password.\n";

		std::string inputUserPassword = Utils::GetLineFromUser(); 
		if (inputUserPassword == selectedUser->GetPassword())
		{
			//Correct User Password
			app->setCurrentUser(selectedUser);
		}
		else
		{
			std::string holdPage = Utils::GetLineFromUser();
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


