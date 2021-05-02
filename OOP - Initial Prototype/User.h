#pragma once

#include <string>

class User
{
	public:
		User(const std::string&, const std::string&, const std::string&);
		virtual ~User();
		const std::string& GetUsername() const;
	private:
		std::string username;
		std::string password;
		std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD
};