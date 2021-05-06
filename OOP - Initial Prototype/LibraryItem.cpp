#include "LibraryItem.h"

LibraryItem::LibraryItem(int id, const Date& date, Game* game, int playTime)
	: id(id),purchased(purchased), game(game), playTime(playTime)
{
}

LibraryItem::~LibraryItem()
{
}

const Game* LibraryItem::getGame(){
	return game;
}

int LibraryItem::getPlayTime() {
	return playTime;
}

void LibraryItem::addPlayTime(int add) {
	playTime += add;
}

