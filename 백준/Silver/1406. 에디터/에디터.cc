#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	std::string str;
	cin >> str;

	std::list<char> cursor;
	for (int i = 0; i < str.size(); ++i)
	{
		cursor.push_front(str[i]);
	}
	std::list<char>::iterator iter = cursor.begin();

	int num;
	cin >> num;
	cin.clear();
	for (int i = 0; i < num; ++i)
	{
		std::string temp;
		std::getline(std::cin, temp);

		if (temp == "")
		{
			--i;
			continue;
		}

		switch (temp[0])
		{
		case 'L':
			if (iter != cursor.end())
			{
				++iter;
			}
			break;
		case 'D':
			if (iter != cursor.begin())
			{
				--iter;
			}
			break;
		case 'B':
			if (iter != cursor.end())
			{
				iter = cursor.erase(iter);
			}
			break;
		case 'P':
			iter = cursor.insert(iter, temp[2]); 
			break;
		}
	}

	while (!cursor.empty())
	{
		std::cout << cursor.back();
		cursor.pop_back();
	}

	return 0;
}