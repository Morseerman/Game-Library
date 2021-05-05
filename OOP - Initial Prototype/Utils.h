#pragma once

#include <string>
#include <iostream>

class Utils
{
public:
    static std::string getLineFromUser();
    static char getCharFromUser();

    // TODO: 2 versions of ToUpper
    static std::string loopToUpper(std::string str) {
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

    static std::string recursiveToUpper(std::string str, int i) {
        if (i >= str.size()) {
            return str;
        }
        str[i] = toupper(str[i]);
        str = recursiveToUpper(str, i + 1);

        return str;
    }
};
