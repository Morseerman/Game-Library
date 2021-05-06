#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const Date& created, int credits)
	: Player(username, password, created, credits)
{
}

Admin::~Admin()
{
}