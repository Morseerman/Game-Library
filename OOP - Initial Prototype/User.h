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
		std::vector<LibraryItem*> GetLibrary();
		std::vector<LibraryItem*> library;
		const std::string& GetPassword() const;
		const int GetCredits() const;
		int IncrementCredits(std::string choice);
		int SubtractCredits(int amount);
		bool IsAdmin();
		void Promote();
		void Demote();
		
	private:
		std::string username;
		std::string password;
		//std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD DONE
		Date created;
		bool admin;

		int credits;
};