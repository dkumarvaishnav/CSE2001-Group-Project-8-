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

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    bool operator<(const Date& other) const {
        if (year != other.year) {
            return year < other.year;
        } else if (month != other.month) {
            return month < other.month;
        } else {
            return day < other.day;
        }
    }

    bool operator<=(const Date& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>(const Date& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Date& other) const {
        return !(*this < other);
    }

    bool operator==(const Date& other) const {
        return (year == other.year) && (month == other.month) && (day == other.day);
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

