#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
    games.~List();
}