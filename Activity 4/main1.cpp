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
}