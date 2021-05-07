#include "Date.h"

Date::Date(int mday, int mon, int year) {
    SetCurrentDay(mday);
    SetCurrentMonth(mon);
    SetCurrentYear(year);
}

void Date::SetCurrentDay(int d) {
    if (d >= 1 && d <= 31) {
        mday = d; // else days default value = 0
    }
}

int const Date::GetCurrentDay() const{
    return mday;
}

void Date::SetCurrentMonth(int m) {
    if (m >= 1 && m <= 12) {
        mon = m;
    }
}

int const Date::GetCurrentMonth() const {
    return mon;
}

void Date::SetCurrentYear(int y) {
    year = y;
}

int const Date::GetCurrentYear() const {
    return year;
}

std::string Date::DisplayCurrentDate() {
    std::string d = std::to_string(GetCurrentDay());
    std::string m = std::to_string(GetCurrentMonth());
    std::string y = std::to_string(GetCurrentYear());
    std::string returnString = "Current day: " + d + "  Current Month: " + m +
        "  Current Year: " + y;

    return returnString;
}