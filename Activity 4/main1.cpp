#include <iostream>

using namespace std;
template <typename T>
T findLargest(T a, T b, T c) {
    T largest = a;

    if (b > largest) {
        largest = b;
    }
    if (c > largest) {
        largest = c;
    }

    return largest;
};

int main() {
    int x = 10, y = 25, z = 5;
    double a = 3.14, b = 2.71, c = 1.62;
    string str1 = "apple", str2 = "banana", str3 = "cherry";

    cout << "Largest integer: " << findLargest(x, y, z) << endl;
    cout << "Largest double: " << findLargest(a, b, c) << endl;
    cout << "Largest string: " << findLargest(str1, str2, str3) << endl;

    return 0;
}
