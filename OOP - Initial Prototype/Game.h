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

		float getLikes();
		float getDislikes();
		float getRating(float, float);

		void addLike();
		void addDislike();

	private:
		int id;
		std::string name;
		std::string description;
		float cost;
		int ageRating;

		float likes = 0;
		float dislikes = 0;
		float rating = 0;

};