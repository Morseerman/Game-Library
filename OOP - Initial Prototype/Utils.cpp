#include "Utils.h"
#include "ListT.h"
#include "Account.h"


std::string Utils::GetLineFromUser()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}


char Utils::GetCharFromUser()
{
    return toupper(GetLineFromUser()[0]);
}

std::string Utils::LoopToUpper(std::string str) {
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

std::string Utils::RecursiveToUpper(std::string str, int i) {
    if (i >= str.size()) {
        return str;
    }
    str[i] = toupper(str[i]);
    str = RecursiveToUpper(str, i + 1);

    return str;
}
std::string Utils::GetUpperLineFromUser()
{
    return LoopToUpper(GetLineFromUser());
}
User* Utils::GetUserFromList(int index, List<Account*> accounts)
{
    
    List<User*> copyList = accounts.First()->GetUsers();

    for (int i = 0; i < index - 1; i++)
    {
        copyList.DeleteFirst();
    }
    return copyList.First();
}
User* Utils::DeleteUserFromList(int index, List<Account*> accounts)
{
    

    List<User*> copyList = accounts.First()->GetUsers();


    for (int i = 0; i < index - 1; i++)
    {
        copyList.DeleteFirst();
    }
    return copyList.First();
}

Game* Utils::GetGame(int index, List<Game*> games)
{

    List<Game*> copyList = games;

    for (int i = 0; i < index - 1; i++)
    {
        copyList.DeleteFirst();
    }
    return copyList.First();
}

int Utils::StringToInt(std::string numString)
{
    int temp;
    std::stringstream ssInputOption;
    ssInputOption << numString;
    ssInputOption >> temp;
    return temp;
}

int Utils::ReturnRandomNumber()
{
    srand((unsigned)time(0));
    int randomNumber;
    randomNumber = 10 + (rand() % 60) + 1;
    std::cout << randomNumber << std::endl;
    return randomNumber;
}

float Utils::CalculatePercentage(float num1, float num2)
{
    float total = num1 + num2;

    if (num1 != 0)
    {
        float percentage = (num1 / total) * 100;
        return percentage;
    }
    else
    {
        return 0;
    }

}