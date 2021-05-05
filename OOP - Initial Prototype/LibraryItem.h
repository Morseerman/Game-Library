#pragma once

#include "Game.h"
#include "Date.h";

class LibraryItem
{
	public:
		LibraryItem(int, const Date&, Game*);
		~LibraryItem();
	private:
		int id;
		const Game *game;
		//const std::string purchased;  // TODO: replace with custom Date class, currently YYYY-MM-DD DONE
		const Date purchased;
};