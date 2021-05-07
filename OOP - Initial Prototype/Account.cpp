#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const Date& created)
	: email(email), password(password), created(created)
{
}

Account::~Account()
{
}

//Getters
List<User*> Account:: GetUsers()
{
	return users;
}
std::string Account::GetEmail()
{
	return email;
}
std::string Account::GetPassword()
{
	return password;
}