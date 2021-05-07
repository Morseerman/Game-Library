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

	//All User Options
	std::cout << "Credits: " << app->GetCurrentUser()->getCredits() << std::endl;
	std::cout << std::endl;
	std::cout << "I) Purhcase 1 Credit" << std::endl;
	std::cout << "O) Purhcase 10 Credit" << std::endl;
	std::cout << "P) Purhcase 100 Credit" << std::endl;

	//Admin UserOptions
	if (app->GetCurrentUser()->isAdmin())
	{
		std::cout << "\nC) Create user" << std::endl;
		std::cout << "D) Delete user\n" << std::endl;
	}


	for (int i = 0; i < app->GetCurrentUser()->library.size(); i++) {
		std::cout << i << ") " << app->GetCurrentUser()->library[i]->getGame()->GetName() << "  (" << app->GetCurrentUser()->library[i]->getPlayTime() << " hours played)" << std::endl;
		
	}
	
}

bool ProfileMenu::HandleChoice(std::string choice)
{
    //if(choice == app->GetCurrentUser()->library)
    int intChoice = Utils::stringToInt(choice);

    //Admin Choices

    if (choice == "C" && app->GetCurrentUser()->isAdmin())
    {
        std::cout << "Enter Username\n";
        std::string newUserName = Utils::getLineFromUser();

        std::cout << "Enter Password\n";
        std::string newPassword = Utils::getLineFromUser();
        
        app->accounts.first()->users.addAtEnd(new Player(newUserName, newPassword, (2019, 07, 19), 500));
        std::cout << "Account Created";
        std::string nextChoice = Utils::getLineFromUser();
    }
    else if (choice == "D" && app->GetCurrentUser()->isAdmin())
    {
        std::cout << "Account deleated";
        std::string nextChoice = Utils::getLineFromUser();
    }

    //All User Choices

    if (choice == "I" || "O" || "P") {
        app->GetCurrentUser()->incrementCredits(choice);
        if (choice == "B") {
            return true;
        }

    }     

    for (int i = 0; i < app->GetCurrentUser()->library.size(); i++) {
        if ((choice != "P") && (choice != "O") && (choice != "I") && (choice != "C") && (choice != "D")) {
            if (i == intChoice)
            {
                std::cout << "1) Play\n";
                std::cout << "2) Like\n";
                std::cout << "3) Dislike\n";
                std::string nextChoice = Utils::getLineFromUser();

                if (nextChoice == "1")
                {
                    app->GetCurrentUser()->library[i]->addPlayTime(Utils::returnRandomNumber());
                }
                else if (nextChoice == "2")
                {
                    for (int j = 0; j < app->GetStore().games.length(); j++)
                    {
                        if (app->GetCurrentUser()->library[i]->getGame()->GetName() == Utils::getGame(j, app->GetStore().games)->GetName())
                        {
                            Utils::getGame(j, app->GetStore().games)->addLike();
                        }
                    }

                }
                else if (nextChoice == "3")
                {
                    for (int j = 0; j < app->GetStore().games.length(); j++)
                    {
                        if (app->GetCurrentUser()->library[i]->getGame()->GetName() == Utils::getGame(j, app->GetStore().games)->GetName())
                        {
                            Utils::getGame(j, app->GetStore().games)->addDislike();
                        }
                    }
                }

                return false;
            }
        }

    }

    return false;

}


