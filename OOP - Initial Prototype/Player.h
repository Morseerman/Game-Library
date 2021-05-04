#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&);
		~Player();
		//LibraryItem* library[2] = { }; // TODO: replace with custom List<T> class
		List<LibraryItem*>* library;
	private:
};