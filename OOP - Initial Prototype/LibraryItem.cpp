#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& date, Game* game)
	: purchased(purchased), game(game)
{
}

LibraryItem::~LibraryItem()
{
}