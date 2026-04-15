#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, m;
class room
{
public:
	int level;
	set<pair<string, int>> users;
	bool isFull;

	room() {
		level = 0;
		isFull = false;
	}

	void Insert(int l, string name)
	{
		users.insert({ name, l});
		if (users.size() == m)
			isFull = true;
	}

	bool isBelong(int l)
	{
		return isFull == false && l <= level + 10 && l >= level - 10;
	}

	void Print()
	{
		if (isFull == true)
			cout << "Started!\n";
		else
			cout << "Waiting!\n";

		for (auto iter = users.begin(); iter != users.end(); ++iter)
		{
			cout << iter->second << " " << iter->first << "\n";
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	vector<room> v;
	while (n-- > 0)
	{
		int level; string name;
		cin >> level >> name;

		if (v.empty() == true)
		{
			room r; r.level = level; r.Insert(level, name);
			v.push_back(r);
			continue;
		}

		bool isInserted = false;
		for (auto iter = v.begin(); iter != v.end(); ++iter)
		{
			if (iter->isBelong(level))
			{
				iter->Insert(level, name);
				isInserted = true;
				break;
			}
		}

		if (isInserted == false)
		{
			room r; r.level = level; r.Insert(level, name);
			v.push_back(r);
		}
	}

	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		iter->Print();
	}

	return 0;
}