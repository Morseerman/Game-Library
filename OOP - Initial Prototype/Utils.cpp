#include "Utils.h"
#include "ListT.h"
#include "Account.h"


std::string Utils::getLineFromUser()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}


char Utils::getCharFromUser()
{
    return toupper(getLineFromUser()[0]);
}

std::string Utils::loopToUpper(std::string str) {
    std::string upperCase;
    for (int it : str) {
        if (it > 96 && it < 123) {
            upperCase += char(it - 32);

        }
        else {
            upperCase += char(it);
        }
    }
    return upperCase;
}

std::string Utils::recursiveToUpper(std::string str, int i) {
    if (i >= str.size()) {
        return str;
    }
    str[i] = toupper(str[i]);
    str = recursiveToUpper(str, i + 1);

    return str;
}
std::string Utils::getUpperLineFromUser()
{
    return loopToUpper(getLineFromUser());
}
User* Utils::getUserFromList(int index, List<Account*> accounts)
{
    
    List<User*> copyList = accounts.first()->getUsers();

    for (int i = 0; i < index - 1; i++)
    {
        copyList.deleteFirst();
    }
    return copyList.first();
}

int Utils::stringToInt(std::string numString)
{
    int temp;
    std::stringstream ssInputOption;
    ssInputOption << numString;
    ssInputOption >> temp;
    return temp;
}