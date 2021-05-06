#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created, int credits)
	: User(username, password, created, credits)
{
}

Player::~Player()
{

}