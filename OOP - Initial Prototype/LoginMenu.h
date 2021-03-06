#pragma once

#include "Menu.h"
#include <sstream>
#include <string>
#include <vector>

class LoginMenu : public Menu
{
public:
	LoginMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(std::string choice) final;
private:
	std::vector<std::string> userNames = { "Alice", "Bob", "Charlie"};
}; 