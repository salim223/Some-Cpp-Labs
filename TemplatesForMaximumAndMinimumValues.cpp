#include <string>
#include <iostream>

using namespace std;

// TODO: Define a generic method called getMinValue() that
//       takes in three variables of generic type as arguments.
//       The return type of the method is the minimum value of the three
//       Define a generic method called getMaxValue() that
//       takes in three variables of generic type as arguments.
//       The return type of the method is the maximum value of the three

template<typename TheType>
TheType getMinValue(TheType item1, TheType item2, TheType item3) {
    TheType minVal = item1; // Holds min item value, init to first item

    if (item2 < minVal) {
        minVal = item2;
    }
    if (item3 < minVal) {
        minVal = item3;
    }

    return minVal;
}
template<typename TheType>

TheType getMaxValue(TheType item1, TheType item2, TheType item3) {
    TheType minVal = item1; // Holds min item value, init to first item

    if (item2 > minVal) {
        minVal = item2;
    }
    if (item3 > minVal) {
        minVal = item3;
    }

    return minVal;
}




int main() {
    // Uncomment the lines below for testing and the final submission
    // Using three strings
    cout << "Min: " << getMinValue('a', 'b', 'z') << endl;
    cout << "Max: " << getMaxValue('a', 'b', 'z') << endl;

    // Using three doubles
    cout << "Min: " << getMinValue(1.23, 0.45, 100.1) << endl;
    cout << "Max: " << getMaxValue(1.23, 0.45, 100.1) << endl;

    // Using three integers
    cout << "Min: " << getMinValue(11, 8, 9) << endl;
    cout << "Max: " << getMaxValue(11, 8, 9) << endl;

    return 0;
}