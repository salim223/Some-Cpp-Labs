#include <iostream>
#include <string>
using namespace std;

string IntToReverseBinary(int num)
{
    string temp = "";
    while (num > 0)
    {
        temp += to_string(num % 2);
        num = num / 2;
    }
    return  temp;
}
string StringReverse(string num)
{
    string temp = "";
    for (int i = (num.size() - 1); i >= 0; i--)
    {
        temp += num[i];
    }
    return temp;
}

int main() {
    int num;
    cin >> num;

    cout << StringReverse(IntToReverseBinary(num)) << endl;


    return 0;
}
