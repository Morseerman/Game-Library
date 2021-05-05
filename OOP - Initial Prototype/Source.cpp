#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"
#include "ListT.h"
#include "MainMenu.h"
#include "Date.h"

// TODO: Remove from global scope once menu system is integrated
Application app;

void createHardcodedTestData()
{
	

	// Setup store with some games
	app.GetStore().games.addAtEnd(new Game(1,"The Witness", "Explore a nice island and solve puzzles.", 2999, 5));
	app.GetStore().games.addAtEnd(new Game(2,"Braid", "A time twisting puzzle game.", 499, 15));
	app.GetStore().games.addAtEnd(new Game(3,"Factorio", "Build a complicated factory in space.", 1599, 12));
	app.GetStore().games.addAtEnd(new Game(4,"LIMBO", "Watch out for that spider.", 299, 12));
	app.GetStore().games.addAtEnd(new Game(5,"INSIDE", "What are those scientists even doing?!", 1299, 15));
	app.GetStore().games.addAtEnd(new Game(6,"Portal 2", "Play around with physics. Shoot the moon.", 1999, 15));
	app.GetStore().games.addAtEnd(new Game(7,"Half Life 3", "It's never coming out.", 5999, 18));
	app.GetStore().games.addAtEnd(new Game(8,"NUVAVULT", "A game where 2D and 3D collide.", 299, 18));
	app.GetStore().games.addAtEnd(new Game(9,"Path", "Draw nice shapes between 2 big dots.", 299, 15));

	std::string test = "this is a test";
	std::cout << Utils::recursiveToUpper(test, 0);

	//std::cout << str << std::endl;

	std::cout << "Size of games list: " << app.GetStore().games.length() << std::endl;


	// Create some users
	Player* u1 = new Admin("Alice", "password", (16, 6, 2018), 2222);
	Player* u2 = new Player("Bob", "password", (19, 9, 2018), 2222);
	Player* u3 = new Player("Charlie", "password", (24, 9, 2018), 2222);



	// With some games in their library
	//u1->library.addAtEnd(new LibraryItem(1,(17, 6, 2018), app.GetStore().games.last()));
	//u1->library.addAtEnd(new LibraryItem(2,(17, 6, 2018), app.GetStore().games.first()));
	//u2->library.addAtEnd(new LibraryItem(3,(19, 6, 2018), app.GetStore().games.first()));
	//u2->library.addAtEnd(new LibraryItem(4,(19, 9, 2018), app.GetStore().games.last()));
	//u3->library.addAtEnd(new LibraryItem(5,(24, 9, 2018), app.GetStore().games.first()));
	//u3->library.addAtEnd(new LibraryItem(6,(30, 9, 2018), app.GetStore().games.last()));

	//std::cout << "Size of user 1s game list: " << u1->library.length() << std::endl;


	//// Make an account and attach the users
	////"2018-06-16"
	app.accounts.addAtEnd(new Account("alice@shu.com", "password", (16, 6, 2018)));
	app.accounts.first()->users.addAtEnd(u1);
	//app.accounts.first()->users.addAtEnd(u2);
	//app.accounts.first()->users.addAtEnd(u3);

	std::cout << "List of users associated with account: " << app.accounts.length() << std::endl;
	//std::cout << "List of users: " << app.accounts.first

	//// TODO: We need a login menu for accounts, for now we log in the only account
	//app.LoginAccount("alice@shu.ac.uk", "password");
}

void parseFileData() {
	std::ifstream dataFile("data.txt");
	std::string line;

	if (dataFile) { //setup store with games from file
		while (std::getline(dataFile, line)) {
			if (line == "GAME") {
				std::string name1, desc1, cost1, rating1, id1;
				int costInt1, ratingInt1, idInt1;
				//dataFile >> id >> name >> desc >> cost >> rating;
				std::getline(dataFile, id1);
				std::getline(dataFile, name1);
				std::getline(dataFile, desc1);
				std::getline(dataFile, cost1);
				std::getline(dataFile, rating1);
				std::stringstream ssCost1;
				ssCost1 << cost1;
				ssCost1 >> costInt1;
				std::stringstream ssRating1;
				ssRating1 << rating1;
				ssRating1 >> ratingInt1;
				std::stringstream ssId1;
				ssId1 << id1;
				ssId1 >> idInt1;
				app.GetStore().games.addAtEnd(new Game(idInt1, name1, desc1, costInt1, ratingInt1));
				std::cout << app.GetStore().games.last()->GetName() << std::endl;
			}
			else if (line == "ACCOUNT") { //setup account from file
				std::string email2, password2, date2;
				std::string delimiter2 = "-";
				int intYear2, intMonth2, intDay2;
				//email password dateCreated
				std::getline(dataFile, date2);
				std::getline(dataFile, email2);
				std::getline(dataFile, password2);
				std::string year2 = date2.substr(0, date2.find(delimiter2));
				std::string month2 = date2.substr(1, date2.find(delimiter2));
				std::string day2 = date2.substr(2, date2.find(delimiter2));
				std::stringstream ssYear2, ssMonth2, ssDay2;
				ssYear2 << year2;
				ssYear2 >> intYear2;
				ssMonth2 << month2;
				ssMonth2 >> intMonth2;
				ssDay2 << day2;
				ssDay2 >> intDay2;
				Date actualDate2(intDay2, intMonth2, intYear2);
				//app.accounts.addAtEnd(new Account("alice@shu.com", "password", (16, 6, 2018)));
				app.accounts.addAtEnd(new Account(email2, password2, actualDate2));
			}
			else if (line == "ACCOUNT-PLAYER") { //setup account type player
				std::string username3, password3, created3, credits3;
				std::string delimiter3 = "-";
				int intYear3, intMonth3, intDay3, intCredits3;
				std::getline(dataFile, created3);
				std::getline(dataFile, username3);
				std::getline(dataFile, password3);
				std::getline(dataFile, credits3);
				std::string year3 = created3.substr(0, created3.find(delimiter3));
				std::string month3 = created3.substr(1, created3.find(delimiter3));
				std::string day3 = created3.substr(2, created3.find(delimiter3));
				std::stringstream ssYear3, ssMonth3, ssDay3, ssCredits3;
				ssYear3 << year3;
				ssYear3 >> intYear3;
				ssMonth3 << month3;
				ssMonth3 >> intMonth3;
				ssDay3 << day3;
				ssDay3 >> intDay3;
				ssCredits3 << credits3;
				ssCredits3 >> intCredits3;
				Date actualDate3(intDay3, intMonth3, intYear3);
				//Player* u2 = new Player("Bob", "password", (19, 9, 2018));
				Player* user = new Player(username3, password3, actualDate3, intCredits3);
				//app.accounts.first()->users.addAtEnd(u1);
				app.accounts.last()->users.addAtEnd(user);

			}
			else if (line == "ACCOUNT-ADMIN") { //setup account type admin
				std::string username4, password4, created4, credits4;
				std::string delimiter4 = "-";
				int intYear4, intMonth4, intDay4, intCredits4;
				std::getline(dataFile, created4);
				std::getline(dataFile, username4);
				std::getline(dataFile, password4);
				std::getline(dataFile, credits4);
				std::string year4 = created4.substr(0, created4.find(delimiter4));
				std::string month4 = created4.substr(1, created4.find(delimiter4));
				std::string day4 = created4.substr(2, created4.find(delimiter4));
				std::stringstream ssYear4, ssMonth4, ssDay4, ssCredits4;
				ssYear4 << year4;
				ssYear4 >> intYear4;
				ssMonth4 << month4;
				ssMonth4 >> intMonth4;
				ssDay4 << day4;
				ssDay4 >> intDay4;
				ssCredits4 << credits4;
				ssCredits4 >> intCredits4;
				Date actualDate4(intDay4, intMonth4, intYear4);
				//Player* u2 = new Player("Bob", "password", (19, 9, 2018));
				Player* user = new Admin(username4, password4, actualDate4, intCredits4);
				//app.accounts.first()->users.addAtEnd(u1);
				app.accounts.last()->users.addAtEnd(user);

			}
			else if (line == "LIBRARY-ITEM") { //setup library item
				std::string id5, created5, unknown5;
				std::string delimiter5 = "-";
				int intYear5, intMonth5, intDay5, intId5;
				std::getline(dataFile, id5);
				std::getline(dataFile, created5);
				std::getline(dataFile, unknown5);
				std::string year5 = created5.substr(0, created5.find(delimiter5));
				std::string month5 = created5.substr(1, created5.find(delimiter5));
				std::string day5 = created5.substr(2, created5.find(delimiter5));
				std::stringstream ssYear5, ssMonth5, ssDay5, ssId5;
				ssYear5 << year5;
				ssYear5 >> intYear5;
				ssMonth5 << month5;
				ssMonth5 >> intMonth5;
				ssDay5 << day5;
				ssDay5 >> intDay5;
				ssId5 << id5;
				ssId5 >> intId5;
				Date actualDate5(intDay5, intMonth5, intYear5);
				//u1->library.addAtEnd(new LibraryItem(1,(17, 6, 2018), app.GetStore().games.last()));
				//u1->library.addAtEnd(new LibraryItem(2,(17, 6, 2018), app.GetStore().games.first());
				app.accounts.last()->users.last()->library.push_back(new LibraryItem(intId5, actualDate5, app.GetStore().games.last()));
			}
		}
		std::cout << "The total amount of games is: " << app.GetStore().games.length() << std::endl;
		std::cout << "The total amount of accounts is: " << app.accounts.length() << std::endl;
		std::cout << "The total amount of player users is: " << app.accounts.last()->users.length() << std::endl;
		std::cout << "The total amount of games in user library is: " << app.accounts.last()->users.last()->library.size() << std::endl;
	}
};

char showMainMenuAndGetUserChoice()
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= GAME LIBRARY =-\n";
	std::cout << "                    \n";
	std::cout << "  S) Browse Store   \n";

	if (app.IsUserLoggedIn())
	{
		std::cout << "  L) Logout of " << app.GetCurrentUser()->GetUsername() << "\n";
		// TODO: User profile option
	}
	else
	{
		std::cout << "  L) Login      \n";
	}

	std::cout << "                    \n";
	std::cout << "  B) Exit           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return Utils::getCharFromUser();
}

char showStoreMenuAndGetUserChoice()
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= STORE =-       \n";
	std::cout << "                    \n";

	// Output game list
	app.GetStore().games.display();

	// TODO: Implement search store option

	// Output rest of menu
	std::cout << "                    \n";
	std::cout << "  B) Back           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return Utils::getCharFromUser();
}

char showLoginUserMenuAndGetUserChoice(Account *account)
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= LOGIN =-       \n";
	std::cout << "                    \n";

	// Output user list
	account->users.display();

	// Output rest of menu
	std::cout << "                    \n";
	std::cout << "  B) Back           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return Utils::getCharFromUser();
}

char showGameMenuAndGetUserChoice(Game* game)
{
	system("CLS");
	std::cout << "                                  \n";
	std::cout << "  -= " << game->GetName() << " =- \n";
	std::cout << "                                  \n";
	std::cout << "  " << game->GetDescription() << "\n";
	std::cout << "                                  \n";

	if (app.IsUserLoggedIn())
	{
		std::cout << "  P) Purchase for " << (game->GetCost() / 100.0f) << "\n";
		std::cout << "                                                      \n";
	}

	std::cout << "  B) Back                   \n";
	std::cout << "                            \n";
	std::cout << "                            \n";
	std::cout << "  >>> ";

	return Utils::getCharFromUser();
}

void gameMenu(Game* game)
{
	bool readyToGoBack = false;

	while (readyToGoBack == false)
	{
		int choice = showGameMenuAndGetUserChoice(game);

		switch (choice)
		{
			case 'P': {
				if (app.IsUserLoggedIn())
				{
					// TODO: Implement buying from the store
				}
			} break;
			case 'B': {
				readyToGoBack = true;
			} break;
		}
	}
}

void storeMenu()
{
	bool readyToGoBack = false;

	while (readyToGoBack == false)
	{
		int choice = showStoreMenuAndGetUserChoice();

		switch (choice)
		{
			case 'B': {
				readyToGoBack = true;
			} break;
			default: {
				int index = choice - '1';

				if (index >= 0 && index < 9) // TODO: Hardcoded numbers, change when using List<T>
				{
					//gameMenu(app.GetStore().games[index]);
				}
			} break;
		}
	}
}

void loginUserMenu()
{
	bool readyToGoBack = false;

	while (readyToGoBack == false)
	{
		int choice = showLoginUserMenuAndGetUserChoice(app.GetCurrentAccount());

		//switch (choice)
		//{
		//	case 'B': {
		//		readyToGoBack = true;
		//	} break;
		//	default: {
		//		int index = choice - '1';

		//		if (index >= 0 && index < 3) // TODO: Hardcoded numbers, change when using List<T>
		//		{
		//			std::string username = app.GetCurrentAccount()->users[index]->GetUsername();

		//			std::cout << "  Enter password for " << username << ": ";
		//			if (app.LoginUser(username, Utils::getLineFromUser()))
		//			{
		//				readyToGoBack = true;
		//			}
		//		}



		//	} break;
		//}
	}
}

void mainMenu()
{
	bool wantsToExit = false;

	while (wantsToExit == false)
	{
		int choice = showMainMenuAndGetUserChoice();

		switch (choice)
		{
			case 'S': {
				storeMenu();
			} break;
			case 'L': {
				if (app.IsUserLoggedIn())
				{
					app.LogoutUser();
				}
				else
				{
					loginUserMenu();
				}
			} break;
			case 'B': {
				wantsToExit = true;
			} break;
		}
	}
}

void main()
{
	
	// TODO: Remove call to dummy data, instead use Load and Save
	//createHardcodedTestData();
	parseFileData();

	// TODO: app.Load();

	//mainMenu(); // TODO: replace with proper menu system

	// TODO: app.Save();

	//MainMenu("Main Menu", &app);

	/*List<int> testList;
	bool isEqual = false;

	testList.addInFront(1);
	testList.addInFront(2);
	testList.addInFront(3);
	testList.addInFront(4);
	testList.addInFront(5);

	testList.deleteOne(3);

	testList.display();

	List<int> anotherList(testList);

	anotherList.display();*/


}