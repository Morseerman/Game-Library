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
	std::cout << "Credits: " << app->GetCurrentUser()->GetCredits() << std::endl;
	std::cout << std::endl;
	std::cout << "I) Purhcase 1 Credit" << std::endl;
	std::cout << "O) Purhcase 10 Credit" << std::endl;
	std::cout << "P) Purhcase 100 Credit" << std::endl;

	//Admin UserOptions
	if (app->GetCurrentUser()->IsAdmin())
	{
		std::cout << "\nC) Create user" << std::endl;		
	}


	for (int i = 0; i < app->GetCurrentUser()->library.size(); i++) {
		std::cout << i << ") " << app->GetCurrentUser()->library[i]->getGame()->GetName() << "  (" << app->GetCurrentUser()->library[i]->getPlayTime() << " hours played)" << std::endl;
		
	}
	
}

bool ProfileMenu::HandleChoice(std::string choice)
{
    //if(choice == app->GetCurrentUser()->library)
    int intChoice = Utils::StringToInt(choice);

    //Admin Choices

    if (choice == "C" && app->GetCurrentUser()->IsAdmin())
    {
        std::cout << "Enter Username\n";
        std::string newUserName = Utils::GetLineFromUser();

        std::cout << "Enter Password\n";
        std::string newPassword = Utils::GetLineFromUser();
        
        app->accounts.first()->users.addAtEnd(new Player(newUserName, newPassword, (2019, 07, 19), 500));
        std::cout << "Account Created";
        std::string nextChoice = Utils::GetLineFromUser();
    }
    

    //All User Choices

    if (choice == "I" || "O" || "P") {
        app->GetCurrentUser()->IncrementCredits(choice);
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
                std::string nextChoice = Utils::GetLineFromUser();

                if (nextChoice == "1")
                {
                    app->GetCurrentUser()->library[i]->addPlayTime(Utils::ReturnRandomNumber());
                }
                else if (nextChoice == "2")
                {
                    for (int j = 0; j < app->GetStore().games.length(); j++)
                    {
                        if (app->GetCurrentUser()->library[i]->getGame()->GetName() == Utils::GetGame(j, app->GetStore().games)->GetName())
                        {
                            Utils::GetGame(j, app->GetStore().games)->addLike();
                        }
                    }

                }
                else if (nextChoice == "3")
                {
                    for (int j = 0; j < app->GetStore().games.length(); j++)
                    {
                        if (app->GetCurrentUser()->library[i]->getGame()->GetName() == Utils::GetGame(j, app->GetStore().games)->GetName())
                        {
                            Utils::GetGame(j, app->GetStore().games)->addDislike();
                        }
                    }
                }

                return false;
            }
        }

    }

    return false;

}


