#pragma once

#include <string>

class Game
{
	public:
		Game(int ,const std::string&, const std::string&, int, int);
		~Game();

		const std::string& GetName() const;
		const std::string& GetDescription() const;
		int GetCost() const;
		int getId();
		int getAgeRating();

	private:
		int id;
		std::string name;
		std::string description;
		int cost;
		int ageRating;

};