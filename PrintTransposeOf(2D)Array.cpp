#include <iostream>
using namespace std;

int main()
{
	int i, j;
	int myArray[3][4];
	int secArray[4][3];

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cin >> myArray[j][i];
		}

	}

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			secArray[i][j] = myArray[j][i];
		}

	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cout << secArray[j][i] << " ";
		}
		cout << endl;
	}
	return 0;
}
