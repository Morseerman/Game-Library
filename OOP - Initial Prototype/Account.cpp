#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const Date& created)
	: email(email), password(password), created(created)
{
}

Account::~Account()
{
}

//Getters
List<User*> Account:: getUsers()
{
	return users;
}
std::string Account::getEmail()
{
	return email;
}
std::string Account::getPassword()
{
	return password;
}