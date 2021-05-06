#pragma once

#include <string>
#include <vector>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&, int);
		~Player();
		//LibraryItem* library[2] = { }; // TODO: replace with custom List<T> class DONE
		//List<LibraryItem*> library;

	private:
};