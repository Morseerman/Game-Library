#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const Date& created)
	: Player(username, password, created)
{
}

Admin::~Admin()
{
}