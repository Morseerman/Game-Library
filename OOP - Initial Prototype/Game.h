#pragma once

#include <string>

class Game
{
	public:
		Game(int ,const std::string&, const std::string&, float, int);
		~Game();

		const std::string& GetName() const;
		const std::string& GetDescription() const;
		float GetCost() const;
		int getId();
		int getAgeRating();

	private:
		int id;
		std::string name;
		std::string description;
		float cost;
		int ageRating;

};