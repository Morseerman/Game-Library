#include "Date.h"

Date::Date(int mday, int mon, int year) {
    setCurrentDay(mday);
    setCurrentMonth(mon);
    setCurrentYear(year);
}

void Date::setCurrentDay(int d) {
    if (d >= 1 && d <= 31) {
        mday = d; // else days default value = 0
    }
}

int const Date::getCurrentDay() const{
    return mday;
}

void Date::setCurrentMonth(int m) {
    if (m >= 1 && m <= 12) {
        mon = m;
    }
}

int const Date::getCurrentMonth() const {
    return mon;
}

void Date::setCurrentYear(int y) {
    year = y;
}

int const Date::getCurrentYear() const {
    return year;
}

std::string Date::displayCurrentDate() {
    std::string d = std::to_string(getCurrentDay());
    std::string m = std::to_string(getCurrentMonth());
    std::string y = std::to_string(getCurrentYear());
    std::string returnString = "Current day: " + d + "  Current Month: " + m +
        "  Current Year: " + y;

    return returnString;
}