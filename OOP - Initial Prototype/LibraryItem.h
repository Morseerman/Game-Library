#pragma once

#include "Game.h"
#include "Date.h";

class LibraryItem
{
	public:
		LibraryItem(int, const Date&, Game*, int);
		~LibraryItem();
		const Game* getGame();
		int getPlayTime();
		void addPlayTime(int add);
	private:
		int id;
		const Game *game;
		//const std::string purchased;  // TODO: replace with custom Date class, currently YYYY-MM-DD DONE
		const Date purchased;
		int playTime;
};