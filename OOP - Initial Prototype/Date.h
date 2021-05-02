#pragma once
#include <time.h>
#include <iostream>
#include <string>
class Date
{
public:
    Date(int d = 0, int m = 0, int y = 0);

    void setCurrentDay(int d);
    void setCurrentMonth(int m);
    void setCurrentYear(int y);

    int const getCurrentDay() const;
    int const getCurrentMonth() const;
    int const getCurrentYear() const;

    std::string displayCurrentDate();



private:
    int mday;
    int mon;
    int year;
};

