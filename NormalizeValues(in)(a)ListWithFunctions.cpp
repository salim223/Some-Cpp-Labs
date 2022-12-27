#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double GetMinimumValue(double myArray[], int size)
{
    double min;
    int max = 99999999;
    for (int i = 0; i < size; i++)
    {
        if (myArray[i] < max)
        {
            min = myArray[i];
            max = myArray[i];
        }
    }
    return min;
}

int main()
{
    double min;

    double myArray[20];

    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> myArray[i];
    }


    for (int i = 0; i < size; i++)
    {
        cout << fixed << setprecision(2) << myArray[i] / (GetMinimumValue(myArray, size)) << " ";
    }
    cout << endl;

    return 0;
}
