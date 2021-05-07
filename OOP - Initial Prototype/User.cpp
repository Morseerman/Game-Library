#include "User.h"

User::User(const std::string& username, const std::string& password, const Date& created, int credits)
	: username(username), password(password), created(created), credits(credits)
{
}

User::~User()
{
}

const std::string& User::GetUsername() const
{
	return username;
}
const std::string& User::GetPassword() const
{
	return password;
}
const int User::getCredits() const
{
	return credits;
}
int User::incrementCredits(std::string choice) {
	if (choice == "I") {
		credits += 1;
		return credits;
	}
	if (choice == "O") {
		credits += 10;
		return credits;
	}
	if (choice == "P") {
		credits += 100;
		return credits;
	}
	else {
		return credits;
	}
}

int User::subtractCredits(int amount) {
	credits -= amount;
	return credits;
}

bool User::isAdmin()
{
	return admin;
}
void User::promote()
{
	admin = true;
}
void User::demote()
{
	admin = false;
}