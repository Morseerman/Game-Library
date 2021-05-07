#pragma once

#include <string>
#include "Player.h"
#include "ListT.h"
#include "Date.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const Date&);
		~Account();
		//User* users[3] = { }; // TODO: replace with custom List<T> class DONE
		List<User*> GetUsers();		
		std::string GetEmail();
		std::string GetPassword();

		List<User*> users;
	private:
		std::string email;
		std::string password;
		//std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD DONE
		Date created;
};