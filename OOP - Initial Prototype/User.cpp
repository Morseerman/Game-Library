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
const int User::GetCredits() const
{
	return credits;
}
int User::IncrementCredits(std::string choice) {
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

int User::SubtractCredits(int amount) {
	credits -= amount;
	return credits;
}

bool User::IsAdmin()
{
	return admin;
}
void User::Promote()
{
	admin = true;
}
void User::Demote()
{
	admin = false;
}