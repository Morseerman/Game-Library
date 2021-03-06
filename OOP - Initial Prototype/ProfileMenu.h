#pragma once

#include "Menu.h"
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

class ProfileMenu : public Menu
{
public:
	ProfileMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(std::string choice) final;
private:
	std::vector<std::string> userNames = { "Alice", "Bob", "Charlie" };
};