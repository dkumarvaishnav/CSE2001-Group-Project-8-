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

    // Provide the necessary function to use the statement like days=dt;
    operator int() const {
        int daysElapsed = 0;
        for (int m = 1; m < month; ++m) {
            daysElapsed += Date(1, m, year).daysInMonth();
        }
        daysElapsed += day;
        return daysElapsed;
    }

    // Friend function to overload << operator for output
    friend ostream& operator<<(ostream& os, const Date& dt) {
        os << dt.day << "/" << dt.month << "/" << dt.year;
        return os;
    }
};

int main() {
    Date dt1(15, 8, 2023);
    Date dt2(20, 12, 2023);

    if (dt1 < dt2) {
        cout << dt1 << " is earlier than " << dt2 << endl;
    }

    ++dt1; 
    cout << "Incremented date: " << dt1 << endl;

    Date dt3 = dt1 + 5; 
    cout << "Date after adding 5 days: " << dt3 << endl;

    int daysElapsed = dt1; 
    cout << "Days elapsed in the current year: " << daysElapsed << endl;

    return 0;
}
