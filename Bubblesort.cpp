#include <iostream>

using namespace std;

int main()
{

    int myArray[10];


    int i, j, temp;

    for (i = 0; i < 10; i++)
    {
        cin >> myArray[i];
    }

    //Bubblesort
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (myArray[i] > myArray[j])
            {
                temp = myArray[i];
                myArray[i] = myArray[j];
                myArray[j] = temp;
            }
        }
    }
    cout << "Sorted array:\n";

    for (i = 0; i < 10; i++)
        cout << myArray[i] << " ";

    return 0;
}


