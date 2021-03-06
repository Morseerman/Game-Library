#include "MainMenu.h"
#include "LoginMenu.h"
#include "ProfileMenu.h"

MainMenu::MainMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	Option('S', "Browse Store");

	if (app->IsUserLoggedIn())
	{
		Option('P', "View Profile");
		Option('L', "Logout");
	}
	else
	{
		Option('L', "Login");
	}
}

bool MainMenu::HandleChoice(std::string choice)
{
	//switch (choice)
	//{
	//case 'S':
	//{
	//	StoreMenu("STORE", app);
	//} break;
	//case 'L':
	//{
	//	if (app->IsUserLoggedIn())
	//	{
	//		std::string answer = Question("Are you sure?");
	//		if (answer == "y" || answer == "Y")
	//		{
	//			app->LogoutUser();  //-------------WILL NEEED TO CHANGE
	//		}
	//	}
	//	else
	//	{
	//		// this would need to go to a LoginMenu - similar to StoreMenu
	//		// instead we just set logged in to true on the main app object

	//		//app->LoginUser("Bob", "password"); //----------------WILL NEEED TO CHANGE
	//		LoginMenu("Login", app);
	//	}
	//} break;
	//case 'P':
	//{
	//	if (app->IsUserLoggedIn())
	//	{
	//		BlockingMessage("Not implemented, press return to continue");
	//		// this needs to go to a profile page - similar to StoreMenu
	//		// notice the if - this only works if somebody is logged in
	//	}
	//} break;
	//}

	if (choice == "S")
	{
		StoreMenu("STORE", app);
	}
	else if (choice == "L")
	{
		if (app->IsUserLoggedIn())
		{
			std::string answer = Question("Are you sure?");
			if (answer == "y" || answer == "Y")
			{
				app->LogoutUser();  //-------------WILL NEEED TO CHANGE
			}
		}
		else
		{
			// this would need to go to a LoginMenu - similar to StoreMenu
			// instead we just set logged in to true on the main app object

			//app->LoginUser("Bob", "password"); //----------------WILL NEEED TO CHANGE
			LoginMenu("Login", app);
		}
	}
	else if (choice == "P")
	{
		if (app->IsUserLoggedIn())
		{
			ProfileMenu(app->GetCurrentUser()->GetUsername() + "'s Profile", app);
			// this needs to go to a profile page - similar to StoreMenu
			// notice the if - this only works if somebody is logged in
		}
	}
	

	return false;
}