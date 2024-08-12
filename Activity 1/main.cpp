#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    // Helper function to check if a year is a leap year
    bool isLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Helper function to get the number of days in a month
    int daysInMonth() const {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && isLeapYear()) {
            return 29;
        } else {
            return days[month - 1];
        }
    }
  // Overload ++ operator to increment a date by one day
    Date& operator++() {
        day++;
        if (day > daysInMonth()) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    // Overload + to add given number of days to find the next date
    Date operator+(int daysToAdd) const {
        Date result = *this;
        for (int i = 0; i < daysToAdd; ++i) {
            ++result;
        }
        return result;
    }
