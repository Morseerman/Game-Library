#pragma once
#include <time.h>
#include <iostream>
#include <string>
class Date
{
public:
    Date(int d = 0, int m = 0, int y = 0);

    void SetCurrentDay(int d);
    void SetCurrentMonth(int m);
    void SetCurrentYear(int y);

    int const GetCurrentDay() const;
    int const GetCurrentMonth() const;
    int const GetCurrentYear() const;

    std::string DisplayCurrentDate();



private:
    int mday;
    int mon;
    int year;
};

