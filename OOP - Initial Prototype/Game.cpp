#include "Game.h"


Game::Game(int id, const std::string& name, const std::string& desc, float cost, int rating)
	: id(id),name(name), description(desc), cost(cost), ageRating(rating)
{
}

Game::~Game()
{
}

const std::string& Game::GetName() const
{
	return name;
}

const std::string& Game::GetDescription() const
{
	return description;
}

float Game::GetCost() const
{
	return cost;
}
int Game::getId() {
	return id;
}
int Game::getAgeRating()
{
	return ageRating;
}
float Game::getLikes()
{
	return likes;
}
float Game::getDislikes()
{
	return dislikes;
}
float Game::getRating(float likes, float dislikes)
{
	float total = likes + dislikes;

	if (likes != 0)
	{
		float percentage = (likes / total) * 100;
		return percentage;
	}
	else
	{
		return 0;
	}
}
void Game::addLike()
{
	likes++;
}
void Game::addDislike()
{
	dislikes++;
}