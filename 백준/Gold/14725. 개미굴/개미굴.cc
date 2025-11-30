#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXCOUNT = 1000;

struct FoodInfo
{
public:
	string food;
	vector<FoodInfo> c;

	FoodInfo()
	{
		food = '\0';
		c.reserve(MAXCOUNT);
	}

	FoodInfo(string f) : food(f) {
		c.reserve(MAXCOUNT);
	}

	bool operator<(const FoodInfo& other) const {
		return food < other.food;
	}

	void Add(vector<string> foods)
	{
		if (foods.size() == 1)
		{
			if (Find(foods[0]) == -1)
			{
				c.push_back(foods[0]);
				sort(c.begin(), c.end());
			}
			return;
		}

		vector<string> newVec(foods.begin() + 1, foods.end());

		int index = Find(foods[0]);
		
		if (index == -1)
		{
			c.push_back(foods[0]);
			index = c.size() - 1;
		}

		c[index].Add(newVec);
		sort(c.begin(), c.end());
	}

	int Find(string f)
	{
		for (int i = 0, size = c.size(); i < size; ++i)
		{
			if (c[i].food == f)
				return i;
		}
		return -1;
	}

	void Print()
	{
		for (int i = 0, size = c.size(); i < size; ++i)
		{
			c[i].Print(0);
		}
	}

	void Print(int n)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << "--";
		}

		cout << food << "\n";
		for (int i = 0, size = c.size(); i < size; ++i)
		{
			c[i].Print(n + 1);
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	FoodInfo head;

	while (--n >= 0)
	{
		int k;
		cin >> k;

		vector<string> vec;
		for (int i = 0; i < k; ++i)
		{
			string f;
			cin >> f;
			vec.push_back(f);
		}

		head.Add(vec);
	}

	head.Print();

	return 0;
}