#include "Application.h"
#include "Utils.h"

Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	
}

bool Application::IsUserLoggedIn() const
{
	return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
	return currentAccount;
}
void Application::setCurrentUser(User* aUser)
{
	currentUser = aUser;
}

User* Application::GetCurrentUser() const
{
	return currentUser; 
}

Store& Application::GetStore()
{
	return store;
}

bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	//currentAccount = accounts->first();
	//currentAccount = accounts.contains();

	
	List<Account*> copyList = accounts;

	while (copyList.Length() != 0)
	{
		if (email == Utils::LoopToUpper(copyList.First()->GetEmail()) && password == copyList.First()->GetPassword())
		{
			currentAccount = accounts.First();
			return true;
		}

		copyList.DeleteFirst();

	}

	return false;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	// TODO: This currently always logs you in as the first user
	// currentUser = currentAccount->users[0];
	//currentUser = currentAccount->users.last();
	
	List<User*> copyList = accounts.First()->GetUsers();
	int counter = 1;

	while (copyList.Length() != 0)
	{
		std::cout << counter << ") " << copyList.First()->GetUsername() << std::endl;
		copyList.DeleteFirst();
		counter++;
	}


	while (copyList.Length() != 0)
	{
		if (username == Utils::LoopToUpper(copyList.First()->GetUsername()) && password == copyList.First()->GetPassword())
		{
			currentAccount = accounts.First();
			return true;
		}

		copyList.DeleteFirst();

	}
			
	return true;
}

void Application::LogoutUser()
{
	currentUser = nullptr;

}