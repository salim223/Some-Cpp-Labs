#include <iostream>
#include <string>
using namespace std;

int main()
{
	int count = 0;
	string sentence;
	getline(cin, sentence);
	char character = sentence.back();
	string temp_word = "";

	bool checker = false;
	int i = 0;

	for (int y = 0; y < sentence.size(); y++)
	{
		if (isspace(sentence.at(y)))
			count++;
	}

	if (count < 11)
	{

		while (i < (sentence.size() - 1))
		{
			if (isalpha(sentence.at(i)))
			{
				if (sentence.at(i) == character)
				{
					checker = true;
				}
				temp_word += sentence[i];
			}
			else
			{
				if (checker)
				{
					cout << temp_word << ",";
				}
				temp_word = "";
				checker = false;
			}

			i++;
		}
	}
	else
	{
		cout << "Too many words" << endl;
	}

	return 0;
}












