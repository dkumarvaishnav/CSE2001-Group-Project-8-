#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>

using namespace std;

template <typename T>
class Vector {
private:
    vector<T> elements;

public:
    // Constructor to initialize the Vector with a list of elements
    Vector(const vector<T>& init_elements) : elements(init_elements) {}

    // Method to find the smallest element
    T findSmallest() const {
        if (elements.empty()) {
            throw runtime_error("Vector is empty.");
        }
        T min_element = *min_element(elements.begin(), elements.end());
        return min_element;
    }

    // Method to search for an element
    bool searchElement(const T& value) const {
        return find(elements.begin(), elements.end(), value) != elements.end();
    }

    // Method to calculate the average of the elements
    double calculateAverage() const {
        if (elements.empty()) {
            throw runtime_error("Vector is empty.");
        }
        T sum = accumulate(elements.begin(), elements.end(), T{0});
        return static_cast<double>(sum) / elements.size();
    }

    // Method to display all elements (for testing purposes)
    void display() const {
        for (const T& elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
};
int main(){
    Vector<int>intVec({10,20,5,40,30});
    cout<<"Vector elements: ";
    intVec.display();
    try{
        cout<<"Smallest element: "<<intVec.findSmallest()<<endl;
        cout<<"Search for 20: "<< (intVec.searchElement(20) ? "Found" : "Not Found") << endl;
        cout<<"Search for 100: "<< (intVec.searchElement(100) ? "Found" : "Not Found") << endl;
        cout << "Average of elements: " << intVec.calculateAverage() << endl;
        } catch (const runtime_error& e) {
            cerr << "Error: " << e.what() << endl;
        }
        return 0;


}
