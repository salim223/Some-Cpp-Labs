#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
    length = 0;
    size = 1;
    arr = new int[size];
}

DynamicArray::DynamicArray(int s)
{
    size = s;
    length = 0;
    arr = new int[s];
}

void DynamicArray::addElement(int val)
{

    if (length == size)
    {
        int* temp;;

        temp = new int[size * 2];
        {
            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
        }


        delete[] arr;


        size = size * 2;


        arr = new int[size * 2];
        {
            for (int i = 0; i < size; i++)
            {
                arr[i] = temp[i];
            }
        }

        delete[] temp;
    }

    arr[length++] = val;

}

int DynamicArray::getLength()
{
    return length;
}

int DynamicArray::getElement(int pos)
{
    return arr[pos];
}

int DynamicArray::getSize()
{
    return size;
}

DynamicArray::~DynamicArray() { delete[] arr; }

/*

    DynamicArray(): Default constructor: set length=0; size =1; allocate memory for arr
    DynamicArray(int s): set size =s, length=0; allocate memory for arr
    getLength(): return length of array
    getElement(int pos): return element at position pos
    getSize(): return size of the array
    addElement(int val): add new element to array. If array is full, you need to double the size of the array before adding the new element. Always remember to update the length of the array.

*/


