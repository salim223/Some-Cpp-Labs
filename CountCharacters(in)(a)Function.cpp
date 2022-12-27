#include <iostream>
using namespace std;

int CalcNumCharacters(string userString, char userChar)
{
	int count = 0;
	for (int i = 0; i < userString.size(); i++)
	{
		if (userString[i] == userChar)
		{
			count++;
		}
	}
	return count;
}

int main() {
	char userChar;
	string userString;

	cin >> userChar >> userString;

	if (CalcNumCharacters(userString, userChar) != 1)
	{
		cout << CalcNumCharacters(userString, userChar) << " " << userChar << "'s";
	}
	else
	{
		cout << CalcNumCharacters(userString, userChar) << " " << userChar << endl;
	}
	return 0;
}
