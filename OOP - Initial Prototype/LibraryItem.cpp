#include "LibraryItem.h"

LibraryItem::LibraryItem(int id, const Date& date, Game* game)
	: id(id),purchased(purchased), game(game)
{
}

LibraryItem::~LibraryItem()
{
}