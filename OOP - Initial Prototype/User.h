#pragma once

#include <string>
#include "Date.h"
#include "LibraryItem.h"
#include <vector>

class User
{
	public:
		User(const std::string&, const std::string&, const Date&, int);
		virtual ~User();
		const std::string& GetUsername() const;
		std::vector<LibraryItem*> getLibrary();
		std::vector<LibraryItem*> library;
		const std::string& GetPassword() const;
		const int getCredits() const;
		int incrementCredits(std::string choice);
		int subtractCredits(int amount);
	private:
		std::string username;
		std::string password;
		//std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD DONE
		Date created;

		int credits;
};