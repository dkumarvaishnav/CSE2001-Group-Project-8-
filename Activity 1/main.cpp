#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInMonth() const {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && isLeapYear()) {
            return 29;
        } else {
            return days[month - 1];
        }
    }
