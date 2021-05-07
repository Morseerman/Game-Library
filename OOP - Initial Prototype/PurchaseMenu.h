#pragma warning(disable:4996)

#include "Menu.h"
#include <sstream>
#include <string>
#include <vector>
#include <ctime>


class PurchaseMenu : public Menu
{
public:
	PurchaseMenu(const std::string& title, Application* app, int userGameChoice);
	void OutputOptions() final;
	bool HandleChoice(std::string choice) final;
private:
	std::vector<std::string> userNames = { "Alice", "Bob", "Charlie" };
	int userGameChoice;
};
