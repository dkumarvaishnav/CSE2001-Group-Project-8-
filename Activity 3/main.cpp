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
    
    Vector(const vector<T>& init_elements) : elements(init_elements) {}

    
    T findSmallest() const {
        if (elements.empty()) {
            throw runtime_error("Vector is empty.");
        }
        T min_element = *min_element(elements.begin(), elements.end());
        return min_element;
    }

    
    bool searchElement(const T& value) const {
        return find(elements.begin(), elements.end(), value) != elements.end();
    }

    
    double calculateAverage() const {
        if (elements.empty()) {
            throw runtime_error("Vector is empty.");
        }
        T sum = accumulate(elements.begin(), elements.end(), T{0});
        return static_cast<double>(sum) / elements.size();
    }

    
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
