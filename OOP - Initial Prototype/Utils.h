#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "User.h"
#include "ListT.h"
#include "Account.h"

class Utils
{
public:
    static std::string getLineFromUser();
    static char getCharFromUser();
    static User* getUserFromList(int index, List<Account*> accounts);

    // TODO: 2 versions of ToUpper
    static std::string loopToUpper(std::string str);

    static std::string recursiveToUpper(std::string str, int i);

    static std::string getUpperLineFromUser();

    static int stringToInt(std::string numString);

};