#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>    
#include "User.h"
#include "ListT.h"
#include "Account.h"

class Utils
{
public:
    static std::string GetLineFromUser();
    static char GetCharFromUser();
    static User* GetUserFromList(int index, List<Account*> accounts);

    // TODO: 2 versions of ToUpper
    static std::string LoopToUpper(std::string str);

    static std::string RecursiveToUpper(std::string str, int i);

    static std::string GetUpperLineFromUser();

    static int StringToInt(std::string numString);
    static Game* GetGame(int index, List<Game*> games);

    static int ReturnRandomNumber();
    static float CalculatePercentage(float num1, float num2);
    User* DeleteUserFromList(int index, List<Account*> accounts);
    //static int userGameChoice;
private:
    


};